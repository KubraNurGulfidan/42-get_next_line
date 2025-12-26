# get_next_line

## Proje Hakkında (TR)
Bu projenin amacı, bir dosya tanımlayıcıdan (file descriptor) okunan metni satır satır döndüren bir fonksiyon yazmaktır. Proje, C dilinde dosya okuma, statik değişken kullanımı ve dinamik bellek yönetimi konularında derinlik kazandırır.

### Teknik Detaylar
- **Static Variables**: Fonksiyon her çağrıldığında dosyanın neresinde kalındığını takip etmek için statik değişkenler kullanılmıştır.
- **Buffer Management**: `BUFFER_SIZE` değerine bakılmaksızın verimli okuma ve bellek kullanımı sağlanmıştır.
- **Memory Safety**: Bellek sızıntılarını (memory leaks) önlemek için tüm geçici tamponlar ve kalıntı veriler titizlikle yönetilmiştir.
- **Bonus**: Aynı anda birden fazla dosya tanımlayıcıdan (Multiple File Descriptors) veri okuma desteği.

---

## About the Project (EN)
The aim of this project is to write a function that returns a line read from a file descriptor. It provides deep insights into file I/O operations, the use of static variables, and dynamic memory management in C.

### Technical Details
- **Static Variables**: Used to keep track of the reading position across multiple function calls.
- **Buffer Management**: Efficient reading and memory usage regardless of the defined `BUFFER_SIZE`.
- **Memory Safety**: Careful management of temporary buffers and leftover data to prevent memory leaks.
- **Bonus**: Capability to manage multiple file descriptors simultaneously without losing the reading thread.

---

## Kullanım / Usage

- Bir main.c dosyası oluşturup derleme sırasında BUFFER_SIZE belirleyebilirsiniz (You can define BUFFER_SIZE during compilation):
  ```bash
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=34 main.c get_next_line.c get_next_line_utils.c

- Aşağıda örnek bir main.c dosyası içeriği verilmiştir. (Below is an example of the contents of a main.c file.)
  ```c
  #include "get_next_line.h"
  #include <fcntl.h>
  #include <stdio.h>

  int main(void)
  {
      int     fd;
      char    *line;

      // Dosyayı salt okunur modda açın
      fd = open("test.txt", O_RDONLY);
      if (fd < 0)
          return (1);

      // Satır satır okuma döngüsü
      while ((line = get_next_line(fd)) != NULL)
      {
          printf("%s", line); // Satırı ekrana yazdır
          free(line);         // Bellek sızıntısını önlemek için serbest bırak!
      }

      close(fd);
      return (0);
  }
