import numpy as np
import pyspark
from pyspark.ml.evaluation import RegressionEvaluator
from pyspark.ml.recommendation import ALS
from pyspark import SparkConf,SparkContext
from pyspark.sql import SparkSession
from pyspark.sql.functions import col,explode
from pyspark.sql.types import  DateType, DoubleType,IntegerType,StringType 

#copy valoracionesep to ratingcomplete 
#with open("valoraciones_EP.csv","r") as file1, open("rating_complete.csv","a+") as file2:  
#    file2.write(file1.read())
#    print(file1,file2)

#init spark session with utf8
spark = SparkSession.builder.appName("Recomendador").getOrCreate()
#open csvs
animes_dataset = spark.read.option("header","true").option("encoding","utf-8").csv('anime.csv')
ratings_dataset = spark.read.option("header","true").option("encoding","utf-8").csv('rating_complete.csv')

#castear data a int para poder operar
casted_anime = animes_dataset.withColumn("ID",animes_dataset["ID"].cast(IntegerType()))

ratings_dataset = ratings_dataset.withColumn("user_id",ratings_dataset["user_id"].cast(IntegerType()))
ratings_dataset = ratings_dataset.withColumn("anime_id",ratings_dataset["anime_id"].cast(IntegerType()))
ratings_dataset = ratings_dataset.withColumn("rating",ratings_dataset["rating"].cast(IntegerType()))

#pasar de dataframe a pandas
(training,recom) = ratings_dataset.randomSplit([0.8,0.2])
als = ALS(maxIter=5,regParam=0.09,rank=25,userCol="user_id",itemCol = "anime_id",ratingCol ="rating",coldStartStrategy="drop",nonnegative= True )
model = als.fit(training)
evaluator = RegressionEvaluator(metricName = "rmse",labelCol = "rating", predictionCol = "prediction")
predictions = model.transform(recom)
rmse = evaluator.evaluate(predictions)
print("RMSE="+str(rmse))
# predictions.show()
model_rec_usrs = model.recommendForAllUsers(20)

model_rec_usr = model_rec_usrs.withColumn("rec_exp",explode("recommendations")).select("user_id",col("rec_exp.anime_id"),col("rec_exp.rating"))
model_rec_usr = model_rec_usr.filter(col("user_id") == 666666)
 
animes = casted_anime.select(casted_anime["ID"], casted_anime["Name"],casted_anime["English name"], casted_anime["Type"])
model_rec_usr = model_rec_usr.join(anime,model_rec_usr.anime_id == anime.ID)

movies = model_rec_usr.filter((col("Type") == "Movie")& (col("rating") <= 10))
movies = movies.orderBy(col("rating").desc()).limit(5)

movies.show(5,truncate = False)