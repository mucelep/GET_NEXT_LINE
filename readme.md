İşte bonus kısmı eklenmiş hali:
markdown

*This project has been created as part of the 42 curriculum by mucelep.*

# GET_NEXT_LINE

---

## 📋 ENGLISH VERSION

## Description

**get_next_line** is a function that reads a line from a file descriptor. The goal of this project is to add a highly useful function to your collection while learning an important concept in C programming: **static variables**.

The prototype of the implemented function is:
```c
char *get_next_line(int fd);
```

- Returns the line that was read (including `\n` if present)
- Returns `NULL` if there is nothing left to read or an error occurred
- Works both when reading a file and from standard input

---

## 📖 Instructions

### Compilation
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

This will generate the executable with a buffer size of 42. The `BUFFER_SIZE` can be changed to any value:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c
```

The project can also be compiled without the `-D BUFFER_SIZE` flag:
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```

### Files

| File | Description |
|------|-------------|
| `get_next_line.c` | Main function |
| `get_next_line_utils.c` | Helper functions |
| `get_next_line.h` | Header file |

### Bonus Files

| File | Description |
|------|-------------|
| `get_next_line_bonus.c` | Main function (multiple fd support) |
| `get_next_line_utils_bonus.c` | Helper functions (bonus) |
| `get_next_line_bonus.h` | Header file (bonus) |

### Usage Example
```c
#include "get_next_line.h"
#include 
#include 

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

**Compile with your program:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
./a.out
```

### Bonus Usage Example
```c
#include "get_next_line_bonus.h"
#include 
#include 

int main(void)
{
    int     fd1;
    int     fd2;
    int     fd3;
    char    *line;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);

    line = get_next_line(fd1); printf("fd1: %s", line); free(line);
    line = get_next_line(fd2); printf("fd2: %s", line); free(line);
    line = get_next_line(fd3); printf("fd3: %s", line); free(line);
    line = get_next_line(fd1); printf("fd1: %s", line); free(line);

    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}
```

**Compile bonus with your program:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c
./a.out
```

---

## ⚙️ Algorithm & Data Structure

### Static Variable

The key concept of this project is the use of a **static variable** to retain unread data between function calls.

**Why static?**
- Persists between function calls without using global variables
- Stores the leftover buffer content after each `read()`
- Allows the function to continue reading from where it left off

### Parsing Strategy

> 🔎 **Core workflow:**
> 1. Read from the file descriptor using `read()` with `BUFFER_SIZE` chunks
> 2. Append the read content to the static variable (leftover from previous call)
> 3. Search for a `\n` character in the accumulated buffer
> 4. If found, return everything up to and including `\n`, keep the rest in the static variable
> 5. If not found, keep reading until `\n` or end of file
> 6. On end of file, return whatever remains in the buffer
> 7. Return `NULL` when nothing is left to read

### Bonus: Multiple File Descriptors

The bonus part manages multiple file descriptors simultaneously using a **single static variable** implemented as an array.

> 🔎 **Bonus approach:**
> - Static variable becomes an array indexed by file descriptor: `char *stash[OPEN_MAX]`
> - Each fd has its own independent reading state
> - Calling `get_next_line(3)`, then `get_next_line(4)`, then `get_next_line(3)` works correctly without losing track
```c
// Conceptual example of bonus static variable
static char *stash[OPEN_MAX];

// stash[fd] stores the leftover for each file descriptor independently
```

**Why an array?**
- Each file descriptor index maps directly to its own buffer
- Simple and efficient lookup
- No data structure overhead
- Only one static variable used (as required by bonus)

### Design Choices

**Why This Approach?**
- Read as little as possible each call (efficient)
- Never reads the whole file at once
- Handles any `BUFFER_SIZE` value (1, 42, 9999, 10000000)
- Clean memory management (no leaks)
- No forbidden functions (`lseek`, global variables, `libft`)

### Forbidden

- ❌ `libft` is not allowed
- ❌ `lseek()` is forbidden
- ❌ Global variables are forbidden

---

## 📚 Resources

- `man 2 read`
- `man 3 malloc`
- `man 3 free`
- `man 2 open`
- [Static variables in C](https://en.wikipedia.org/wiki/Static_variable)
- 42 get_next_line subject PDF

### AI Usage

AI was used only for:
- Understanding static variable behavior across function calls
- Clarifying edge cases (empty files, no newline at EOF, large buffer sizes)
- README documentation assistance

**All code implementation, debugging, and testing were done manually.**

---

## 👤 Author

**mucelep** - 42 Network

---

*Made with ☕ at 42*

---
---

## 📋 TÜRKÇE VERSİYON

## Açıklama

**get_next_line**, bir dosya tanımlayıcısından satır okuyan bir fonksiyondur. Bu projenin amacı, koleksiyonunuza çok kullanışlı bir fonksiyon eklerken C programlamada önemli bir kavramı öğrenmektir: **static değişkenler**.

Implement edilen fonksiyonun prototipi:
```c
char *get_next_line(int fd);
```

- Okunan satırı döner (`\n` varsa dahil)
- Okunacak bir şey kalmadığında veya hata oluştuğunda `NULL` döner
- Hem dosya okurken hem de standart girdiden okurken çalışır

---

## 📖 Talimatlar

### Derleme
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Bu komut buffer boyutu 42 olacak şekilde derler. `BUFFER_SIZE` herhangi bir değere ayarlanabilir:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c
```

Proje `-D BUFFER_SIZE` bayrağı olmadan da derlenebilir:
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```

### Dosyalar

| Dosya | Açıklama |
|-------|----------|
| `get_next_line.c` | Ana fonksiyon |
| `get_next_line_utils.c` | Yardımcı fonksiyonlar |
| `get_next_line.h` | Header dosyası |

### Bonus Dosyalar

| Dosya | Açıklama |
|-------|----------|
| `get_next_line_bonus.c` | Ana fonksiyon (çoklu fd desteği) |
| `get_next_line_utils_bonus.c` | Yardımcı fonksiyonlar (bonus) |
| `get_next_line_bonus.h` | Header dosyası (bonus) |

### Kullanım Örneği
```c
#include "get_next_line.h"
#include 
#include 

int main(void)
{
    int     fd;
    char    *line;

    fd = open("dosya.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

**Programınızla derleyin:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
./a.out
```

### Bonus Kullanım Örneği
```c
#include "get_next_line_bonus.h"
#include 
#include 

int main(void)
{
    int     fd1;
    int     fd2;
    int     fd3;
    char    *line;

    fd1 = open("dosya1.txt", O_RDONLY);
    fd2 = open("dosya2.txt", O_RDONLY);
    fd3 = open("dosya3.txt", O_RDONLY);

    line = get_next_line(fd1); printf("fd1: %s", line); free(line);
    line = get_next_line(fd2); printf("fd2: %s", line); free(line);
    line = get_next_line(fd3); printf("fd3: %s", line); free(line);
    line = get_next_line(fd1); printf("fd1: %s", line); free(line);

    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}
```

**Bonus programınızla derleyin:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c
./a.out
```

---

## ⚙️ Algoritma & Veri Yapısı

### Static Değişken

Bu projenin temel kavramı, fonksiyon çağrıları arasında okunmamış veriyi saklamak için **static değişken** kullanmaktır.

**Neden static?**
- Global değişken kullanmadan fonksiyon çağrıları arasında varlığını sürdürür
- Her `read()` sonrasında buffer'da kalan içeriği saklar
- Fonksiyonun kaldığı yerden okumaya devam etmesini sağlar

### Parse Stratejisi

> 🔎 **Temel iş akışı:**
> 1. `read()` ile dosya tanımlayıcısından `BUFFER_SIZE` boyutunda parçalar oku
> 2. Okunan içeriği static değişkene (önceki çağrıdan kalan) ekle
> 3. Biriktirilen buffer'da `\n` karakterini ara
> 4. Bulunursa, `\n` dahil her şeyi döndür, geri kalanı static değişkende tut
> 5. Bulunmazsa, `\n` veya dosya sonu gelene kadar okumaya devam et
> 6. Dosya sonunda, buffer'da ne varsa döndür
> 7. Okunacak bir şey kalmadığında `NULL` döndür

### Bonus: Çoklu Dosya Tanımlayıcıları

Bonus kısım, **tek bir static değişken** kullanarak birden fazla dosya tanımlayıcısını aynı anda yönetir.

> 🔎 **Bonus yaklaşımı:**
> - Static değişken, dosya tanımlayıcısına göre indekslenen bir diziye dönüşür: `char *stash[OPEN_MAX]`
> - Her fd'nin bağımsız okuma durumu vardır
> - `get_next_line(3)`, ardından `get_next_line(4)`, ardından `get_next_line(3)` çağırmak takibi kaybetmeden doğru çalışır
```c
// Bonus static değişkenin kavramsal örneği
static char *stash[OPEN_MAX];

// stash[fd] her dosya tanımlayıcısı için kalan buffer'ı bağımsız olarak saklar
```

**Neden dizi?**
- Her dosya tanımlayıcısı indeksi doğrudan kendi buffer'ına karşılık gelir
- Basit ve verimli erişim
- Veri yapısı yükü yok
- Yalnızca bir static değişken kullanılır (bonus gereksinimlerine uygun)

### Tasarım Seçimleri

**Neden Bu Yaklaşım?**
- Her çağrıda mümkün olduğunca az okur (verimli)
- Dosyanın tamamını bir anda okumaz
- Her `BUFFER_SIZE` değerini işler (1, 42, 9999, 10000000)
- Temiz bellek yönetimi (sızıntı yok)
- Yasak fonksiyon yok (`lseek`, global değişkenler, `libft`)

### Yasaklar

- ❌ `libft` kullanılamaz
- ❌ `lseek()` yasak
- ❌ Global değişkenler yasak

---

## 📚 Kaynaklar

- `man 2 read`
- `man 3 malloc`
- `man 3 free`
- `man 2 open`
- [C'de Static Değişkenler](https://en.wikipedia.org/wiki/Static_variable)
- 42 get_next_line konu PDF'i

### Yapay Zeka Kullanımı

Yapay zeka sadece şunlar için kullanıldı:
- Fonksiyon çağrıları arasında static değişken davranışını anlama
- Edge case'leri netleştirme (boş dosyalar, EOF'ta newline olmaması, büyük buffer boyutları)
- README dokümantasyonu yardımı

**Tüm kod implementasyonu, hata ayıklama ve testler manuel olarak yapıldı.**

---

## 👤 Yazar

**mucelep** - 42 Network

---

*42'de ☕ ile yapıldı*