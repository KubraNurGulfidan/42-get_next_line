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

Derleme sırasında BUFFER_SIZE belirleyebilirsiniz (You can define BUFFER_SIZE during compilation):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
