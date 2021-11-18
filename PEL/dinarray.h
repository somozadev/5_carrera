   namespace detail {
      template<typename T>
      struct Dynarray_base {
         T* first;          // dirección de inicio del array
         std::size_t count; // número de elementos

         explicit Dynarray_base(std::size_t n)
            : first{n? alloc(n) : nullptr}, count{n} { }

         static auto alloc(std::size_t n) -> T*
         {
            if (n >= std::numeric_limits<std::size_t>::max()/sizeof(T))
               throw std::bad_array_new_length{};
            // nota: omitir la búsqueda de funciones de alojamiento específicas
            // en el ámbito de la clase T
            return static_cast<T*>(::operator new(n*sizeof(T)));
         }

         void dealloc() noexcept
         {
            // desalojo de la memoria apuntada por first
            ::operator delete(static_cast<void*>(first));
         }

         ~Dynarray_base() { dealloc(); }
      };
   }
  
   template<typename T>
   class Dynarray : protected detail::Dynarray_base<T> {
      using Base = detail::Dynarray_base<T>;
      using Base::first;
      using Base::count;
   public:
      // typedefs:
      using value_type             = T;
      using const_reference        = T const&;
      using reference              = T&;
      using const_iterator         = T const*;
      using iterator               = T*;
      using const_reverse_iterator = std::reverse_iterator<const_iterator>;
      using reverse_iterator       = std::reverse_iterator<iterator>;
      using size_type              = std::size_t;
  
      // construct/copy/move/destroy:
      explicit Dynarray(size_type n = 0)
         : Base{n}
      {
         auto current = first;
         try {
            for (; n > 0; ++current, --n)
               ::new(static_cast<void*>(current)) value_type;
         }
         catch (...) {
            for (auto p = first; p != current; ++p)
               p->~value_type();
            throw;
         }
      }
      Dynarray(size_type n, value_type const& val)
         : Base{n}
      {
         std::uninitialized_fill_n(first,n,val);
      }
      Dynarray(std::initializer_list<value_type> const& init)
         : Base{init.size()}
      {
         std::uninitialized_copy(init.begin(),init.end(),first);
      }
      Dynarray(Dynarray const& d)
         : Base{d.size()}
      {
         std::uninitialized_copy(d.begin(),d.end(),first);
      }
      auto& operator=(Dynarray const& d)
      {
         Dynarray<value_type> tmp{d};
         swap(tmp);
         return *this;
      }
      Dynarray(Dynarray&& d) noexcept
         : Base{0}
      {
         swap(d);
      }
      auto& operator=(Dynarray&& d) noexcept
      {
         Dynarray<value_type> tmp;
         swap(tmp);
         swap(d);
         return *this;
      }
      ~Dynarray()
      {
         for (auto p = begin(); p != end(); ++p)
            p->~value_type();
      }
  
      // iterators:
      auto begin() const noexcept { return const_iterator{first}; }
      auto begin() noexcept { return first; }
      auto end() const noexcept { return const_iterator{first + count}; }
      auto end() noexcept { return first + count; }
      auto cbegin() const noexcept { return const_iterator{first}; }
      auto cend() const noexcept { return const_iterator{first + count}; }
      auto rbegin() const noexcept { return const_reverse_iterator{cend()}; }
      auto rbegin() noexcept { return reverse_iterator{end()}; }
      auto rend() const noexcept { return const_reverse_iterator{first}; }
      auto rend() noexcept { return reverse_iterator{first}; }
      auto crbegin() const noexcept { return const_reverse_iterator{cend()}; }
      auto crend() const noexcept { return const_reverse_iterator{first}; }
  
      // capacity:
      auto size()  const noexcept -> size_type { return count; }
      [[nodiscard]] auto empty() const noexcept -> bool { return count == 0; }
  
      // element access:
      auto operator[](size_type i) const -> const_reference { return first[i]; }
      auto operator[](size_type i) -> reference { return first[i]; }
      auto at(size_type i) const -> const_reference { rangeCheck(i); return first[i]; }
      auto at(size_type i) -> reference { rangeCheck(i); return first[i]; }
  
      // data access:
      auto data() const noexcept -> T const* { return first; }
      auto data() noexcept -> T* { return first; }
  
      // modifiers:
      void swap(Dynarray& d) noexcept
      {
         std::swap(first,d.first);
         std::swap(count,d.count);
      }
   private:
      void rangeCheck(size_type i) const
      {
         if (i >= size)
            throw std::out_of_range{"Out of range index"};
      }
   };
