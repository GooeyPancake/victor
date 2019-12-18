typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
    byte eh_frame_hdr_version; // Exception Handler Frame Header Version
    dwfenc eh_frame_pointer_encoding; // Exception Handler Frame Pointer Encoding
    dwfenc eh_frame_desc_entry_count_encoding; // Encoding of # of Exception Handler FDEs
    dwfenc eh_frame_table_encoding; // Exception Handler Table Encoding
};

typedef struct termios termios, *Ptermios;

typedef uint tcflag_t;

typedef uchar cc_t;

typedef uint speed_t;

struct termios {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[32];
    speed_t c_ispeed;
    speed_t c_ospeed;
};

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef longlong __quad_t;

typedef __quad_t __off64_t;

typedef ulong size_t;

struct _IO_FILE {
    int _flags;
    char * _IO_read_ptr;
    char * _IO_read_end;
    char * _IO_read_base;
    char * _IO_write_base;
    char * _IO_write_ptr;
    char * _IO_write_end;
    char * _IO_buf_base;
    char * _IO_buf_end;
    char * _IO_save_base;
    char * _IO_backup_base;
    char * _IO_save_end;
    struct _IO_marker * _markers;
    struct _IO_FILE * _chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t * _lock;
    __off64_t _offset;
    void * __pad1;
    void * __pad2;
    void * __pad3;
    void * __pad4;
    size_t __pad5;
    int _mode;
    char _unused2[15];
};

struct _IO_marker {
    struct _IO_marker * _next;
    struct _IO_FILE * _sbuf;
    int _pos;
};

typedef struct _IO_FILE FILE;

typedef long __fd_mask;

typedef struct fd_set fd_set, *Pfd_set;

struct fd_set {
    __fd_mask fds_bits[128];
};

typedef int __ssize_t;

typedef __ssize_t ssize_t;

typedef int __clockid_t;

typedef long __time_t;

typedef uint __useconds_t;

typedef long __suseconds_t;

typedef __clockid_t clockid_t;

typedef struct timeval timeval, *Ptimeval;

struct timeval {
    __time_t tv_sec;
    __suseconds_t tv_usec;
};

typedef struct timespec timespec, *Ptimespec;

struct timespec {
    __time_t tv_sec;
    long tv_nsec;
};

typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

typedef enum Elf_SectionHeaderType_ARM {
    SHT_ARM_ATTRIBUTES=1879048195,
    SHT_ARM_DEBUGOVERLAY=1879048196,
    SHT_ARM_EXIDX=1879048193,
    SHT_ARM_OVERLAYSECTION=1879048197,
    SHT_ARM_PREEMPTMAP=1879048194,
    SHT_CHECKSUM=1879048184,
    SHT_DYNAMIC=6,
    SHT_DYNSYM=11,
    SHT_FINI_ARRAY=15,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_GROUP=17,
    SHT_HASH=5,
    SHT_INIT_ARRAY=14,
    SHT_NOBITS=8,
    SHT_NOTE=7,
    SHT_NULL=0,
    SHT_PREINIT_ARRAY=16,
    SHT_PROGBITS=1,
    SHT_REL=9,
    SHT_RELA=4,
    SHT_SHLIB=10,
    SHT_STRTAB=3,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_syminfo=1879048188,
    SHT_SYMTAB=2,
    SHT_SYMTAB_SHNDX=18
} Elf_SectionHeaderType_ARM;

struct Elf32_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType_ARM sh_type;
    dword sh_flags;
    dword sh_addr;
    dword sh_offset;
    dword sh_size;
    dword sh_link;
    dword sh_info;
    dword sh_addralign;
    dword sh_entsize;
};

typedef struct Elf32_Phdr Elf32_Phdr, *PElf32_Phdr;

typedef enum Elf_ProgramHeaderType_ARM {
    PT_ARM_EXIDX=1879048192,
    PT_DYNAMIC=2,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_RELRO=1685382482,
    PT_GNU_STACK=1685382481,
    PT_INTERP=3,
    PT_LOAD=1,
    PT_NOTE=4,
    PT_NULL=0,
    PT_PHDR=6,
    PT_SHLIB=5,
    PT_TLS=7
} Elf_ProgramHeaderType_ARM;

struct Elf32_Phdr {
    enum Elf_ProgramHeaderType_ARM p_type;
    dword p_offset;
    dword p_vaddr;
    dword p_paddr;
    dword p_filesz;
    dword p_memsz;
    dword p_flags;
    dword p_align;
};

typedef enum Elf32_DynTag_ARM {
    DT_AUDIT=1879047932,
    DT_AUXILIARY=2147483645,
    DT_BIND_NOW=24,
    DT_CHECKSUM=1879047672,
    DT_CONFIG=1879047930,
    DT_DEBUG=21,
    DT_DEPAUDIT=1879047931,
    DT_ENCODING=32,
    DT_FEATURE_1=1879047676,
    DT_FILTER=2147483647,
    DT_FINI=13,
    DT_FINI_ARRAY=26,
    DT_FINI_ARRAYSZ=28,
    DT_FLAGS=30,
    DT_FLAGS_1=1879048187,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_HASH=1879047925,
    DT_GNU_LIBLIST=1879047929,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_GNU_PRELINKED=1879047669,
    DT_HASH=4,
    DT_INIT=12,
    DT_INIT_ARRAY=25,
    DT_INIT_ARRAYSZ=27,
    DT_JMPREL=23,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_MOVETAB=1879047934,
    DT_NEEDED=1,
    DT_NULL=0,
    DT_PLTGOT=3,
    DT_PLTPAD=1879047933,
    DT_PLTPADSZ=1879047673,
    DT_PLTREL=20,
    DT_PLTRELSZ=2,
    DT_POSFLAG_1=1879047677,
    DT_PREINIT_ARRAYSZ=33,
    DT_REL=17,
    DT_RELA=7,
    DT_RELACOUNT=1879048185,
    DT_RELAENT=9,
    DT_RELASZ=8,
    DT_RELCOUNT=1879048186,
    DT_RELENT=19,
    DT_RELSZ=18,
    DT_RPATH=15,
    DT_RUNPATH=29,
    DT_SONAME=14,
    DT_STRSZ=10,
    DT_STRTAB=5,
    DT_SYMBOLIC=16,
    DT_SYMENT=11,
    DT_SYMINENT=1879047679,
    DT_SYMINFO=1879047935,
    DT_SYMINSZ=1879047678,
    DT_SYMTAB=6,
    DT_TEXTREL=22,
    DT_TLSDESC_GOT=1879047927,
    DT_TLSDESC_PLT=1879047926,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_VERSYM=1879048176
} Elf32_DynTag_ARM;

typedef struct Elf32_Dyn_ARM Elf32_Dyn_ARM, *PElf32_Dyn_ARM;

struct Elf32_Dyn_ARM {
    enum Elf32_DynTag_ARM d_tag;
    dword d_val;
};

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    byte st_info;
    byte st_other;
    word st_shndx;
};

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    dword r_offset; // location to apply the relocation action
    dword r_info; // the symbol table index and the type of relocation
};

typedef struct Elf32_Ehdr Elf32_Ehdr, *PElf32_Ehdr;

struct Elf32_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_pad[9];
    word e_type;
    word e_machine;
    dword e_version;
    dword e_entry;
    dword e_phoff;
    dword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};




void _DT_INIT(void)

{
  FUN_00009110();
  return;
}



void __libc_start_main(void)

{
  __libc_start_main();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void abort(void)

{
                    // WARNING: Subroutine does not return
  abort();
}



// WARNING: Unknown calling convention yet parameter storage is locked

int clock_gettime(clockid_t __clock_id,timespec *__tp)

{
  int iVar1;
  
  iVar1 = clock_gettime(__clock_id,__tp);
  return iVar1;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention yet parameter storage is locked

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = open(__file,__oflag);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = write(__fd,__buf,__n);
  return sVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int close(int __fd)

{
  int iVar1;
  
  iVar1 = close(__fd);
  return iVar1;
}



void __printf_chk(void)

{
  __printf_chk();
  return;
}



void __snprintf_chk(void)

{
  __snprintf_chk();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int nanosleep(timespec *__requested_time,timespec *__remaining)

{
  int iVar1;
  
  iVar1 = nanosleep(__requested_time,__remaining);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memset(__s,__c,__n);
  return pvVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = read(__fd,__buf,__nbytes);
  return sVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
  pcVar1 = strstr(__haystack,__needle);
  return pcVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void exit(int __status)

{
                    // WARNING: Subroutine does not return
  exit(__status);
}



// WARNING: Unknown calling convention yet parameter storage is locked

ushort ** __ctype_b_loc(void)

{
  ushort **ppuVar1;
  
  ppuVar1 = __ctype_b_loc();
  return ppuVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int atoi(char *__nptr)

{
  int iVar1;
  
  iVar1 = atoi(__nptr);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void __assert_fail(char *__assertion,char *__file,uint __line,char *__function)

{
                    // WARNING: Subroutine does not return
  __assert_fail(__assertion,__file,__line,__function);
}



// WARNING: Unknown calling convention yet parameter storage is locked

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = malloc(__size);
  return pvVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void free(void *__ptr)

{
  free(__ptr);
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int usleep(__useconds_t __useconds)

{
  int iVar1;
  
  iVar1 = usleep(__useconds);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
  iVar1 = ioctl(__fd,__request);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int * __errno_location(void)

{
  int *piVar1;
  
  piVar1 = __errno_location();
  return piVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

char * strerror(int __errnum)

{
  char *pcVar1;
  
  pcVar1 = strerror(__errnum);
  return pcVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int tcgetattr(int __fd,termios *__termios_p)

{
  int iVar1;
  
  iVar1 = tcgetattr(__fd,__termios_p);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void cfmakeraw(termios *__termios_p)

{
  cfmakeraw(__termios_p);
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int cfsetispeed(termios *__termios_p,speed_t __speed)

{
  int iVar1;
  
  iVar1 = cfsetispeed(__termios_p,__speed);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int cfsetospeed(termios *__termios_p,speed_t __speed)

{
  int iVar1;
  
  iVar1 = cfsetospeed(__termios_p,__speed);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int tcsetattr(int __fd,int __optional_actions,termios *__termios_p)

{
  int iVar1;
  
  iVar1 = tcsetattr(__fd,__optional_actions,__termios_p);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int tcflush(int __fd,int __queue_selector)

{
  int iVar1;
  
  iVar1 = tcflush(__fd,__queue_selector);
  return iVar1;
}



void __fdelt_chk(void)

{
  __fdelt_chk();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int select(int __nfds,fd_set *__readfds,fd_set *__writefds,fd_set *__exceptfds,timeval *__timeout)

{
  int iVar1;
  
  iVar1 = select(__nfds,__readfds,__writefds,__exceptfds,__timeout);
  return iVar1;
}



void __memmove_chk(void)

{
  __memmove_chk();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = memcpy(__dest,__src,__n);
  return pvVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int tcdrain(int __fd)

{
  int iVar1;
  
  iVar1 = tcdrain(__fd);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int putchar(int __c)

{
  int iVar1;
  
  iVar1 = putchar(__c);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = fopen(__filename,__modes);
  return pFVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream)

{
  size_t sVar1;
  
  sVar1 = fread(__ptr,__size,__n,__stream);
  return sVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int feof(FILE *__stream)

{
  int iVar1;
  
  iVar1 = feof(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int ferror(FILE *__stream)

{
  int iVar1;
  
  iVar1 = ferror(__stream);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int raise(int __sig)

{
  int iVar1;
  
  iVar1 = raise(__sig);
  return iVar1;
}



uint FUN_00008b30(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  undefined8 uVar15;
  
  pcVar5 = (char *)0x0;
  iVar11 = 1;
  uVar10 = 0;
  uVar7 = 0;
  while (iVar11 < param_1) {
    pcVar8 = *(char **)(param_2 + iVar11 * 4);
    pcVar1 = pcVar8;
    if (*pcVar8 == '-') {
      pcVar1 = pcVar5;
      if (pcVar8[1] == 'd') {
        uVar7 = 1;
      }
      else {
        if (pcVar8[1] == 'f') {
          uVar10 = 1;
        }
      }
    }
    pcVar5 = pcVar1;
    iVar11 = iVar11 + 1;
  }
  FUN_0000a3c4();
  FUN_00009ec4();
  FUN_0000a40c();
  iVar11 = FUN_0000a114();
  uVar15 = FUN_000091f8();
  __printf_chk(1,&DAT_0000c4df,"lcd_check");
  if (iVar11 != 0) {
    iVar11 = 1;
  }
  __printf_chk(1,&DAT_0000c5a9,iVar11);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
  iVar2 = FUN_00009604();
  iVar3 = FUN_0000ac38("/dev/ttyHS0",0x100d);
  if (iVar3 != 0) {
LAB_00009018:
    uVar9 = 0x322;
LAB_0000901c:
    uVar13 = 0;
    uVar12 = uVar13;
    goto LAB_00008edc;
  }
  FUN_0000988c();
  uVar15 = FUN_00009470();
  uVar12 = (uint)((ulonglong)uVar15 >> 0x20);
  uVar9 = (int)uVar15 + (uint)(0xc46535ff < uVar12);
  do {
    iVar3 = FUN_0000b0ec(1);
    if (iVar3 == 0) {
      iVar3 = FUN_0000b0ec(10);
      if (iVar3 == 0) goto LAB_00008ca4;
      break;
    }
    uVar15 = FUN_00009470();
    bVar14 = uVar9 <= (uint)uVar15;
    if ((uint)uVar15 == uVar9) {
      bVar14 = uVar12 + 1000000000 <= (uint)((ulonglong)uVar15 >> 0x20);
    }
  } while (!bVar14);
  uVar15 = FUN_000091f8();
  __printf_chk(1,&DAT_0000c4df,"before_dfu.got_frame");
  __printf_chk(1,&DAT_0000c5ea,(uint)*(ushort *)(iVar3 + 4) & 0xff,
               (uint)(*(ushort *)(iVar3 + 4) >> 8));
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
LAB_00008ca4:
  if ((pcVar5 != (char *)0x0) && (iVar4 = FUN_0000bf10(pcVar5,uVar10), 0 < iVar4)) {
    uVar15 = FUN_000091f8();
    __printf_chk(1,&DAT_0000c4df,"dfu_error");
    __printf_chk(1,"DFU Error %d",iVar4);
    iVar3 = __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    if (iVar4 < 0x11) goto LAB_00009018;
    uVar9 = 0x321;
    goto LAB_0000901c;
  }
  uVar10 = FUN_000096e4();
  switch(uVar10) {
  case 1:
    uVar15 = FUN_000091f8();
    __printf_chk(1,&DAT_0000c4df,"battery_level_low");
    __printf_chk(1,&DAT_0000c5a9,1);
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    uVar13 = 1;
    goto LAB_00008ec4;
  case 2:
    uVar15 = FUN_000091f8();
    __printf_chk(1,&DAT_0000c4df,"battery_too_hot");
    __printf_chk(1,&DAT_0000c5a9,2);
    uVar13 = 0;
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    uVar12 = 1;
    uVar9 = 0;
    break;
  case 3:
    uVar15 = FUN_000091f8();
    uVar12 = 0;
    uVar13 = 0;
    __printf_chk(1,&DAT_0000c4df,"battery_check_fail");
    __printf_chk(1,"Battery check saw bootloader!");
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
    uVar9 = 0x321;
    break;
  case 4:
    uVar15 = FUN_000091f8();
    __printf_chk(1,&DAT_0000c4df,"battery_check_fail");
    __printf_chk(1,"Battery check timed out!");
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
  default:
    uVar13 = 0;
LAB_00008ec4:
    uVar9 = 0;
    uVar12 = uVar9;
  }
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  iVar3 = FUN_00009560(iVar11,iVar2);
LAB_00008edc:
  uVar6 = uVar9;
  if (uVar9 != 0) {
    uVar6 = 1;
  }
  if (((uVar6 | uVar7) == 0) && ((uVar13 | uVar12) == 0)) {
    uVar10 = 1;
    goto LAB_00008fb4;
  }
  FUN_0000a490(iVar3);
  FUN_0000a1f0(5);
  if (uVar6 == 0) {
    if (uVar13 == 0) {
      if (uVar12 == 0) {
        if (uVar7 != 0) {
          FUN_0000a2b4(&DAT_00030e18,DAT_00030e10);
        }
        goto LAB_00008fb0;
      }
      FUN_0000a2b4(&DAT_0001fa08,DAT_0001fa00);
      pcVar5 = "too hot";
    }
    else {
      FUN_0000a2b4(&DAT_00028410,DAT_00028408);
      pcVar5 = "low bat";
    }
    FUN_00009278(pcVar5,7);
  }
  else {
    FUN_00009334(uVar9);
  }
LAB_00008fb0:
  uVar10 = 0;
LAB_00008fb4:
  FUN_000096a4(uVar10);
  FUN_0000b3f0();
  uVar15 = FUN_000091f8();
  __printf_chk(1,&DAT_0000c4df,"rampost.exit");
  __printf_chk(1,&DAT_0000c5a9,uVar9);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
  return uVar9;
}



void entry(undefined4 param_1)

{
  undefined4 param_5;
  
  __libc_start_main(FUN_00008b30,param_5,&stack0x00000004,FUN_0000c458,&DAT_0000c4b8,param_1);
                    // WARNING: Subroutine does not return
  abort();
}



// WARNING: Removing unreachable block (ram,0x00009124)

void FUN_00009110(void)

{
  __gmon_start__();
  return;
}



// WARNING: Removing unreachable block (ram,0x00009148)
// WARNING: Removing unreachable block (ram,0x00009150)
// WARNING: Removing unreachable block (ram,0x00009154)

void FUN_00009134(void)

{
  return;
}



void _FINI_0(void)

{
  if (DAT_00039930 != '\0') {
    return;
  }
  FUN_00009134();
  DAT_00039930 = 1;
  return;
}



// WARNING: Removing unreachable block (ram,0x00009180)
// WARNING: Removing unreachable block (ram,0x00009188)
// WARNING: Removing unreachable block (ram,0x000091e4)
// WARNING: Removing unreachable block (ram,0x0000918c)

void _INIT_0(void)

{
  return;
}



int FUN_000091f8(void)

{
  int iVar1;
  timespec local_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = clock_gettime(7,&local_1c);
  if (iVar1 == 0) {
    iVar1 = FUN_0000c014(local_1c.tv_nsec,1000000);
    iVar1 = local_1c.tv_sec * 1000 + iVar1;
  }
  else {
    iVar1 = 0;
  }
  if (local_14 == __stack_chk_guard) {
    return iVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void FUN_00009278(void *param_1,size_t param_2,undefined4 param_3,undefined4 param_4)

{
  int __fd;
  undefined8 uVar1;
  
  __fd = open("/dev/rampost_error",0x41,0x1a0,param_4,param_1,param_2,param_3);
  if (-1 < __fd) {
    write(__fd,param_1,param_2);
    close(__fd);
    return;
  }
  uVar1 = FUN_000091f8();
  __printf_chk(1,&DAT_0000c4df,"semaphore");
  __printf_chk(1,"Couldn\'t write semaphore file \"%s\": %d for error \"%s\"","/dev/rampost_error",
               __fd,param_1);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar1 >> 0x20),(int)uVar1);
  return;
}



void FUN_00009334(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *local_3c;
  undefined auStack52 [16];
  int local_24;
  
  local_24 = __stack_chk_guard;
  uVar1 = __snprintf_chk(auStack52,0x10,1,0x10,"ERROR %d\n",param_1);
  FUN_00009278(auStack52,uVar1);
  if (param_1 == 0x321) {
    iVar2 = -0x24;
    local_3c = &DAT_00017000;
  }
  else {
    if (param_1 != 0x322) {
      uVar3 = FUN_000091f8();
      __printf_chk(1,&DAT_0000c4df,"show_error");
      __printf_chk(1,"No image for error %d",param_1);
      __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
      goto LAB_00009428;
    }
    iVar2 = -0x2c;
    local_3c = &DAT_0000e5f8;
  }
  FUN_0000a2b4(local_3c,**(undefined4 **)((int)&__DT_PLTGOT + iVar2));
LAB_00009428:
  if (local_24 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



undefined8 FUN_00009470(undefined4 param_1,int param_2,int param_3)

{
  longlong lVar1;
  timespec local_14;
  int local_c;
  
  local_c = __stack_chk_guard;
  local_14.tv_sec = param_2;
  local_14.tv_nsec = param_3;
  clock_gettime(1,&local_14);
  lVar1 = (longlong)local_14.tv_sec * 1000000000 + (longlong)local_14.tv_nsec;
  if (local_c != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return CONCAT44((int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
}



void FUN_000094d4(int param_1,__time_t param_2,long param_3)

{
  int iVar1;
  long lVar2;
  timespec local_1c;
  int local_14;
  
  iVar1 = param_1 * 1000;
  local_14 = __stack_chk_guard;
  local_1c.tv_sec = param_2;
  local_1c.tv_nsec = param_3;
  local_1c.tv_sec = FUN_0000c110(iVar1,iVar1 >> 0x1f,1000000000,0,param_1);
  lVar2 = 1000000000;
  FUN_0000c110(iVar1,iVar1 >> 0x1f,1000000000,0);
  local_1c.tv_nsec = lVar2;
  nanosleep(&local_1c,(timespec *)0x0);
  if (local_14 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



void FUN_00009560(int param_1,int param_2)

{
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined local_29;
  undefined local_28;
  undefined local_27;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  memset(&local_2c,0,0x10);
  if (param_1 == 0) {
    local_2c = 0xff;
  }
  else {
    local_2a = 0xff;
    local_27 = 0xff;
    if (param_2 == 0) {
      local_2c = 0xff;
      local_2b = 0xff;
      local_29 = 0xff;
      local_28 = 0xff;
    }
  }
  FUN_0000b214(0x736c,&local_2c,0x10);
  FUN_0000b0ec(500);
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



char * FUN_00009604(void)

{
  int __fd;
  ssize_t sVar1;
  char *pcVar2;
  char acStack532 [512];
  int local_14;
  
  local_14 = __stack_chk_guard;
  __fd = open("/proc/cmdline",0);
  sVar1 = read(__fd,acStack532,0x1ff);
  if (sVar1 < 1) {
    pcVar2 = (char *)0x0;
  }
  else {
    acStack532[sVar1] = '\0';
    pcVar2 = strstr(acStack532,"anki.unbrick");
    if (pcVar2 != (char *)0x0) {
      pcVar2 = (char *)0x1;
    }
  }
  if (local_14 == __stack_chk_guard) {
    return pcVar2;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void FUN_000096a4(int param_1)

{
  if (param_1 != 0) {
    FUN_0000a1f0(0);
    FUN_0000a4b8();
  }
  if (DAT_00039934 != 0) {
    FUN_00009d38();
  }
  if (DAT_0003993c != 0) {
    FUN_00009d38();
  }
  if (DAT_00039940 == 0) {
    return;
  }
  FUN_00009d38();
  return;
}



void FUN_000096c4(int param_1)

{
  FUN_00009334(0x322);
  FUN_000096a4(0);
                    // WARNING: Subroutine does not return
  exit(param_1);
}



uint FUN_000096e4(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr8;
  undefined8 unaff_d8;
  double dVar4;
  undefined8 uVar5;
  
  iVar3 = 5;
  do {
    iVar2 = FUN_0000b0ec(500);
    if (iVar2 != 0) {
      if (*(short *)(iVar2 + 4) == 0x6662) {
        return 3;
      }
      if (*(short *)(iVar2 + 4) == 0x6466) {
        coprocessor_function(10,6,1,in_cr8,in_cr0,in_cr7);
        uVar5 = FUN_000091f8((float)(longlong)(int)*(short *)(iVar2 + 0x48),
                             (int)*(short *)(iVar2 + 0x48));
        __printf_chk(1,&DAT_0000c4df,"battery_level");
        dVar4 = (double)(float)((ulonglong)unaff_d8 >> 0x20);
        __printf_chk(1,"%0.3f",SUB84(dVar4,0),(int)((ulonglong)dVar4 >> 0x20));
        __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
        uVar5 = FUN_000091f8();
        __printf_chk(1,&DAT_0000c4df,"battery_temperature");
        __printf_chk(1,&DAT_0000c5a9,(int)*(short *)(iVar2 + 0x4c));
        __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
        uVar5 = FUN_000091f8();
        __printf_chk(1,&DAT_0000c4df,"battery_flags");
        __printf_chk(1,&DAT_0000c5ba,(uint)*(ushort *)(iVar2 + 0x4e));
        __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
        uVar1 = *(ushort *)(iVar2 + 0x4e);
        if ((uVar1 & 8) != 0) {
          return 2;
        }
        if ((uVar1 & 1) != 0) {
          return (uint)uVar1 & 8;
        }
        return (uint)((uVar1 & 0x60) != 0);
      }
    }
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 4;
    }
  } while( true );
}



void FUN_0000988c(void)

{
  int iVar1;
  undefined auStack276 [256];
  int local_14;
  
  iVar1 = 8;
  local_14 = __stack_chk_guard;
  memset(auStack276,0xff,0x100);
  do {
    FUN_0000ab7c(auStack276,0x100);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (local_14 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



int FUN_000098fc(undefined4 param_1,uint param_2,uint param_3)

{
  int __fd;
  ssize_t sVar1;
  ushort **ppuVar2;
  uint local_1c;
  uint local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_1c = param_2;
  local_18 = param_3;
  if (DAT_00039818 < 0) {
    __fd = open("/sys/devices/soc/1000000.pinctrl/gpio/gpiochip0/base",0,0xffffffcc,&__DT_PLTGOT,
                param_1);
    if ((__fd < 0) &&
       (__fd = open("/sys/devices/soc.0/1000000.pinctrl/gpio/gpiochip911/base",0), __fd < 0)) {
      FUN_000096c4(1);
    }
    local_1c = 0;
    local_18 = local_18 & 0xffffff00;
    sVar1 = read(__fd,&local_1c,5);
    if (sVar1 < 0) {
      FUN_000096c4(1);
    }
    ppuVar2 = __ctype_b_loc();
    if (((*ppuVar2)[local_1c & 0xff] & 0x800) == 0) {
      FUN_000096c4(1);
    }
    DAT_00039818 = atoi((char *)&local_1c);
  }
  if (local_14 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return DAT_00039818;
}



void FUN_00009a10(int param_1,int param_2)

{
  int __fd;
  undefined *__buf;
  size_t __n;
  char acStack60 [40];
  int local_14;
  
  local_14 = __stack_chk_guard;
  if (param_1 == 0) {
                    // WARNING: Subroutine does not return
    __assert_fail("gp != ((void *)0)","gpio.c",0x4d,"gpio_set_direction");
  }
  FUN_000098fc();
  __snprintf_chk(acStack60);
  __fd = open(acStack60,1);
  if (__fd < 0) {
    FUN_000096c4(2);
  }
  if (param_2 == 1) {
    __n = 3;
    __buf = &UNK_0000c737;
  }
  else {
    __n = 2;
    __buf = &UNK_0000c73b;
  }
  write(__fd,__buf,__n);
  close(__fd);
  if (local_14 == __stack_chk_guard) {
    return;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void FUN_00009b18(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  if (param_1 == 0) {
                    // WARNING: Subroutine does not return
    __assert_fail("gp != ((void *)0)","gpio.c",0x5f,"gpio_set_value");
  }
  if (*(byte *)(param_1 + 8) != 0) {
    uVar1 = count_leading_zeroes(param_2);
    FUN_00009a10(param_1,uVar1 >> 5,(uint)*(byte *)(param_1 + 8),param_4);
    return;
  }
  if (param_2 != 0) {
    param_2 = 1;
  }
  write(*(int *)(param_1 + 4),*(void **)(&DAT_00039828 + param_2 * 4),1);
  return;
}



int * FUN_00009b98(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *__ptr;
  int __fd;
  int iVar1;
  size_t __n;
  char acStack68 [32];
  int local_24;
  
  local_24 = __stack_chk_guard;
  __ptr = (int *)malloc(0xc);
  if (__ptr == (int *)0x0) {
    FUN_000096c4(3);
  }
  __fd = open("/sys/class/gpio/export",1);
  if (__fd < 0) {
    free(__ptr);
    FUN_000096c4(4);
  }
  iVar1 = FUN_000098fc();
  __snprintf_chk(acStack68,0x20,1,0x20,&DAT_0000c755,param_1 + iVar1);
  __n = strlen(acStack68);
  write(__fd,acStack68,__n);
  close(__fd);
  *__ptr = param_1;
  *(undefined *)(__ptr + 2) = 0;
  FUN_00009a10(__ptr,param_2);
  __fd = FUN_000098fc();
  __snprintf_chk(acStack68,0x20,1,0x20,"/sys/class/gpio/gpio%d/value",param_1 + __fd);
  __fd = open(acStack68,0x41,0x80);
  if (__fd < 0) {
    free(__ptr);
    FUN_000096c4(4);
  }
  __ptr[1] = __fd;
  if (0 < __fd) {
    FUN_00009b18(__ptr,param_3);
  }
  *(undefined *)(__ptr + 2) = 0;
  if (local_24 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return __ptr;
}



void FUN_00009d18(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = count_leading_zeroes(param_2);
  iVar1 = FUN_00009b98(param_1,uVar2 >> 5,0,param_4,param_4);
  *(undefined *)(iVar1 + 8) = 1;
  return;
}



void FUN_00009d38(void *param_1)

{
  if (param_1 == (void *)0x0) {
                    // WARNING: Subroutine does not return
    __assert_fail("gp != ((void *)0)","gpio.c",0x98,"gpio_close");
  }
  if (0 < *(int *)((int)param_1 + 4)) {
    close(*(int *)((int)param_1 + 4));
  }
  free(param_1);
  return;
}



int FUN_00009d90(void)

{
  int iVar1;
  timespec local_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = clock_gettime(7,&local_1c);
  if (iVar1 == 0) {
    iVar1 = FUN_0000c014(local_1c.tv_nsec,1000000);
    iVar1 = local_1c.tv_sec * 1000 + iVar1;
  }
  else {
    iVar1 = 0;
  }
  if (local_14 == __stack_chk_guard) {
    return iVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void FUN_00009e10(undefined4 param_1,size_t param_2,void *param_3,undefined4 param_4)

{
  uint uVar1;
  size_t __n;
  
  uVar1 = count_leading_zeroes(param_1);
  FUN_00009b18(DAT_00039934,uVar1 >> 5,param_3,&DAT_0002fb00,param_4);
  while (0 < (int)param_2) {
    __n = param_2;
    if (0xfff < (int)param_2) {
      __n = 0x1000;
    }
    param_2 = param_2 - __n;
    write(DAT_00039938,param_3,__n);
    param_3 = (void *)((int)param_3 + __n);
  }
  return;
}



void FUN_00009e74(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  param_1 = param_1 + 2;
  while (*(byte *)(param_1 + -2) != 0) {
    FUN_00009e10(1,1,param_1 + -2,(uint)*(byte *)(param_1 + -2),param_4);
    FUN_00009e10(0,(uint)*(byte *)(param_1 + -1),param_1);
    piVar1 = (int *)(param_1 + 0xe);
    param_1 = param_1 + 0x14;
    usleep(*piVar1 * 1000);
  }
  return;
}



int FUN_00009ec4(void)

{
  int iVar1;
  
  DAT_00039938 = open("/dev/spidev1.0",2);
  if (DAT_00039938 == 0) {
    FUN_000096c4(5);
  }
  iVar1 = DAT_00039938;
  if (0 < DAT_00039938) {
    ioctl(DAT_00039938,0x80016b01,&DAT_0000ceb0);
  }
  return iVar1;
}



undefined4 FUN_00009f38(int param_1,int param_2,undefined4 param_3)

{
  int __errnum;
  int *piVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_38;
  undefined4 local_34;
  undefined local_2e;
  int local_24;
  
  local_24 = __stack_chk_guard;
  memset(&local_48,0,0x20);
  local_2e = 8;
  local_34 = 17500000;
  local_38 = 1;
  local_48 = param_2;
  local_40 = param_3;
  FUN_00009b18(DAT_00039934,0);
  __errnum = ioctl(DAT_00039938,0x40206b00,&local_48);
  if (__errnum < 1) {
    uVar4 = FUN_00009d90();
    __printf_chk(1,&DAT_0000c4df,"lcd.spi.cmd_error");
    piVar1 = __errno_location();
    __errnum = *piVar1;
    pcVar2 = strerror(__errnum);
    __printf_chk(1,"%d %s",__errnum,pcVar2);
  }
  else {
    local_48 = param_2 + 1;
    local_44 = 0;
    local_38 = param_1 + -1;
    FUN_00009b18(DAT_00039934,1);
    __errnum = ioctl(DAT_00039938,0x40206b00,&local_48);
    if (0 < __errnum) {
      uVar3 = 0;
      goto LAB_0000a0c4;
    }
    uVar4 = FUN_00009d90();
    __printf_chk(1,&DAT_0000c4df,"lcd.spi.dat_error");
    piVar1 = __errno_location();
    __errnum = *piVar1;
    pcVar2 = strerror(__errnum);
    __printf_chk(1,"%d %s",__errnum,pcVar2);
  }
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
  uVar3 = 0xffffffff;
LAB_0000a0c4:
  if (local_24 == __stack_chk_guard) {
    return uVar3;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



uint FUN_0000a114(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  uint local_1c;
  uint local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_18 = (param_3 >> 0x10 & 0xff00) << 0x10;
  local_1c = param_2 & 0xff000000 | 0xf;
  iVar1 = FUN_00009f38(3,&local_1c,&local_18,&__DT_PLTGOT,param_1);
  if (iVar1 != 0) {
    uVar3 = FUN_00009d90();
    __printf_chk(1,&DAT_0000c4df,"lcd.read_status");
    __printf_chk(1,"readback error");
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
  }
  uVar2 = count_leading_zeroes(local_18 >> 0x10 & 0xff);
  if (local_14 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return uVar2 >> 5;
}



void FUN_0000a1f0(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int __fd;
  int iVar1;
  undefined4 uStack40;
  int local_24;
  
  iVar1 = 0;
  if (9 < (int)param_1) {
    param_1 = 10;
  }
  local_24 = __stack_chk_guard;
  uStack40 = param_3;
  do {
    __fd = open((&PTR_s__sys_class_leds_face_backlight_b_00039830)[iVar1],1);
    if (__fd != 0) {
      __snprintf_chk(&uStack40,3,1,3,"%02d\n",param_1 & ~((int)param_1 >> 0x1f));
      write(__fd,&uStack40,3);
      close(__fd);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 3);
  if (local_24 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



void FUN_0000a2b4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00009e10(1,1,&DAT_0000ceb1);
  FUN_00009e10(0,param_2,param_1,param_4);
  return;
}



void FUN_0000a2f0(void)

{
  undefined auStack35348 [35328];
  int local_14;
  
  local_14 = __stack_chk_guard;
  memset(auStack35348,0,0x8a00);
  FUN_0000a2b4(auStack35348,0x8a00);
  if (local_14 != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



void FUN_0000a3c4(void)

{
  DAT_00039934 = FUN_00009b98(0x6e,1,1);
  DAT_0003993c = FUN_00009d18(0x60,1);
  DAT_00039940 = FUN_00009d18(0x37,1);
  return;
}



undefined4 FUN_0000a40c(void)

{
  FUN_000094d4(0x32);
  FUN_00009b18(DAT_0003993c,0);
  FUN_00009b18(DAT_00039940,0);
  FUN_000094d4(0x32);
  FUN_00009b18(DAT_0003993c,1);
  FUN_00009b18(DAT_00039940,1);
  FUN_000094d4(0x32);
  FUN_00009e10(1,1,&DAT_0000ceb2);
  FUN_000094d4(0x32);
  return 0;
}



void FUN_0000a490(void)

{
  FUN_00009e74(&DAT_0000ceb4);
  FUN_0000a2f0();
  FUN_00009e74(&DAT_0000d044);
  return;
}



void FUN_0000a4b8(void)

{
  if (DAT_00039938 == 0) {
    return;
  }
  FUN_00009e10(1,1,&DAT_0000d080);
  close(DAT_00039938);
  return;
}



undefined4 FUN_0000a4fc(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0x6b61) {
    return 4;
  }
  if (param_1 < 0x6b62) {
    if (param_1 == 0x6473) {
      return 0;
    }
    if (param_1 < 0x6474) {
      if (param_1 == 0x6466) {
        if (param_2 == 0) {
          uVar1 = 0x40;
        }
        else {
          uVar1 = 0x300;
        }
        return uVar1;
      }
    }
    else {
      if (param_1 == 0x6662) {
        return 4;
      }
      if (param_1 == 0x6675) {
        return 0x404;
      }
    }
  }
  else {
    if (param_1 == 0x736c) {
      return 0x10;
    }
    if (param_1 < 0x736d) {
      if (param_1 == 0x6d64) {
        return 0;
      }
      if (param_1 == 0x7276) {
        if (param_2 == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = 0x28;
        }
        return uVar1;
      }
    }
    else {
      if (param_1 == 0x7374) {
        return 0;
      }
      if (param_1 == 0x7878) {
        return 0;
      }
    }
  }
  return 0xffffffff;
}



int FUN_0000a5cc(void)

{
  int iVar1;
  timespec local_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = clock_gettime(7,&local_1c);
  if (iVar1 == 0) {
    iVar1 = FUN_0000c014(local_1c.tv_nsec,1000000);
    iVar1 = local_1c.tv_sec * 1000 + iVar1;
  }
  else {
    iVar1 = 0;
  }
  if (local_14 == __stack_chk_guard) {
    return iVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void FUN_0000a64c(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_0000a5cc();
  __printf_chk(1,&DAT_0000c4df,"spine.close");
  __printf_chk(1,"fd=%d",DAT_00039e50);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar1 >> 0x20),(int)uVar1);
  close(DAT_00039e50);
  DAT_00039e50 = 0xffffffff;
  return;
}



uint FUN_0000a6d0(byte *param_1,int param_2)

{
  byte *pbVar1;
  uint uVar2;
  
  uVar2 = 0xffffffff;
  pbVar1 = param_1;
  while (pbVar1 != param_1 + param_2) {
    uVar2 = *(uint *)(&DAT_0000d088 + ((*pbVar1 ^ uVar2) & 0xff) * 4) ^ uVar2 >> 8;
    pbVar1 = pbVar1 + 1;
  }
  return uVar2;
}



int FUN_0000aa58(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *local_28;
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  iVar1 = 0;
  do {
    (&DAT_0003be60)[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x20);
  iVar1 = __fdelt_chk(DAT_00039e50);
  uVar2 = DAT_00039e50 & 0x8000001f;
  if ((int)uVar2 < 0) {
    uVar2 = ~(~((uVar2 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  (&DAT_0003be60)[iVar1] = (&DAT_0003be60)[iVar1] | 1 << (uVar2 & 0xff);
  local_28 = &DAT_0003bee0;
  DAT_0003bee0 = 1;
  DAT_0003bee4 = 0;
  iVar1 = select(0x400,(fd_set *)&DAT_0003be60,(fd_set *)0x0,(fd_set *)0x0,(timeval *)&DAT_0003bee0)
  ;
  if (iVar1 == 0) {
    DAT_0003bee8 = DAT_0003bee8 + 1;
    uVar3 = FUN_0000a5cc();
    __printf_chk(1,&DAT_0000c4df,"spine.select_timeout",0x19b3,local_28,param_2,param_3);
    __printf_chk(1,"No serial data for %d sec",(uint)DAT_0003bee8);
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
  }
  else {
    DAT_0003bee8 = 0;
  }
  return iVar1;
}



ssize_t FUN_0000ab7c(void *param_1,size_t param_2)

{
  ssize_t sVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = 0;
  while( true ) {
    if ((int)param_2 < 1) {
      return iVar2;
    }
    sVar1 = write(DAT_00039e50,param_1,param_2);
    if (sVar1 < 1) break;
    param_1 = (void *)((int)param_1 + sVar1);
    iVar2 = iVar2 + sVar1;
    param_2 = param_2 - sVar1;
  }
  uVar3 = FUN_0000a5cc();
  __printf_chk(1,&DAT_0000c4df,"spine.write_error");
  __printf_chk(1,"Serial write error=%d",sVar1);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
  return sVar1;
}



// WARNING: Removing unreachable block (ram,0x0000a740)

int FUN_0000ac38(char *param_1,speed_t param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined8 uVar4;
  termios tStack104;
  int local_2c;
  
  DAT_00039e50 = 0xffffffff;
  DAT_0003be5c = 0;
  local_2c = __stack_chk_guard;
  uVar4 = FUN_0000a5cc();
  __printf_chk(1,&DAT_0000c4df,"spine.open_serial");
  __printf_chk(1,"opening serial port %s",param_1);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
  DAT_00039e50 = open(param_1,2);
  if (DAT_00039e50 < 0) {
    uVar4 = FUN_0000a5cc();
    iVar3 = 7;
    __printf_chk(1,&DAT_0000c4df,"spine.cannot_open");
    __printf_chk(1,"Cannot open %s",param_1);
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
  }
  else {
    uVar4 = FUN_0000a5cc();
    __printf_chk(1,&DAT_0000c4df,"spine.configure_serial_port");
    __printf_chk(1,"configuring port %s (fd=%d)",param_1,DAT_00039e50);
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
    usleep(10000);
    iVar3 = tcgetattr(DAT_00039e50,&tStack104);
    if (iVar3 == 0) {
      cfmakeraw(&tStack104);
      cfsetispeed(&tStack104,param_2);
      cfsetospeed(&tStack104,param_2);
      tStack104.c_cflag = tStack104.c_cflag | 0x70;
      iVar3 = tcsetattr(DAT_00039e50,0,&tStack104);
      if (iVar3 == 0) {
        iVar1 = tcflush(DAT_00039e50,2);
        if (iVar1 != 0) {
          uVar4 = FUN_0000a5cc();
          __printf_chk(1,&DAT_0000c4df,"spine.tcflush_fail");
          __printf_chk(1,"Failed to flush with TCIOFLUSH");
          __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
        }
        goto LAB_0000a9e4;
      }
      FUN_0000a64c();
      uVar4 = FUN_0000a5cc();
      __printf_chk(1,&DAT_0000c4df,"spine.termios_fail");
      pcVar2 = "tcsetattr() failed";
    }
    else {
      FUN_0000a64c();
      uVar4 = FUN_0000a5cc();
      __printf_chk(1,&DAT_0000c4df,"spine.termios_fail");
      pcVar2 = "tcgetattr() failed";
    }
    __printf_chk(1,pcVar2);
    iVar3 = 8;
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
  }
LAB_0000a9e4:
  if (local_2c == __stack_chk_guard) {
    return iVar3;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void FUN_0000ac5c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *__assertion;
  uint __line;
  
  if ((int)param_1 < 1) {
    if (param_1 == 0) {
      return;
    }
    DAT_0003be54 = 0;
    memset(&DAT_00039e54,0x55,0x2000);
    return;
  }
  if ((int)(0x2000 - param_1) < 0) {
    __line = 0x19b;
    __assertion = "remaining >= 0";
  }
  else {
    if (param_1 <= DAT_0003be54) {
      __memmove_chk(&DAT_00039e54,&DAT_00039e54 + param_1,0x2000 - param_1,0x200c,param_4);
      DAT_0003be54 = DAT_0003be54 - param_1;
      return;
    }
    __line = 0x19c;
    __assertion = "gHal.rx_cursor >= bytes_to_drop";
  }
                    // WARNING: Subroutine does not return
  __assert_fail(__assertion,"spine_hal.c",__line,"hal_discard_rx_bytes");
}



uint FUN_0000ad4c(void *param_1,uint param_2)

{
  uint __n;
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *__src;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  
  if (0xb < DAT_0003be54) {
    iVar4 = 0;
    pcVar3 = (char *)((int)&DAT_00039e50 + 3);
    while (iVar4 < (int)(DAT_0003be54 - 3)) {
      __src = pcVar3 + 1;
      if ((((*__src == -0x56) && (pcVar3[2] == 'B')) && (pcVar3[3] == '2')) && (pcVar3[4] == 'H')) {
        uVar5 = DAT_0003be54 - iVar4;
        if (uVar5 < 8) break;
        __n = FUN_0000a4fc((uint)*(ushort *)(pcVar3 + 5),1);
        if ((__n == 0xffffffff) || (uVar2 = (uint)*(ushort *)(pcVar3 + 7), uVar2 != __n)) {
          uVar7 = FUN_0000a5cc();
          __printf_chk(1,&DAT_0000c4df,"spine.invalid_payload_len");
          __printf_chk(1,"expected=%d | observed=%u",__n,(uint)*(ushort *)(pcVar3 + 7));
        }
        else {
          __n = uVar2 + 0xc;
          if (uVar5 < __n) break;
          iVar6 = *(int *)(pcVar3 + uVar2 + 9);
          iVar1 = FUN_0000a6d0();
          if (iVar6 == iVar1) {
            if (param_1 != (void *)0x0 && __n <= param_2) {
              memcpy(param_1,__src,__n);
              FUN_0000ac5c(iVar4 + __n);
              return __n;
            }
                    // WARNING: Subroutine does not return
            __assert_fail("outbuf && outbuf_len >= frame_len","spine_hal.c",0x201,"hal_parse_frame")
            ;
          }
          uVar7 = FUN_0000a5cc();
          __printf_chk(1,&DAT_0000c4df,"spine.crc_error");
          __printf_chk(1,"calc %08x vs data %08x",iVar1,iVar6);
        }
        __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
        FUN_0000ac5c(iVar4 + 4);
        return 0xffffffff;
      }
      iVar4 = iVar4 + 1;
      pcVar3 = __src;
    }
    FUN_0000ac5c(iVar4);
  }
  return 0;
}



undefined4 FUN_0000af88(undefined4 param_1,uint param_2)

{
  int __fd;
  int iVar1;
  uint __n;
  uint uVar2;
  undefined8 uVar3;
  
  if (param_2 < 0x30c) {
                    // WARNING: Subroutine does not return
    __assert_fail(
                  "buffer_len >= ((sizeof(struct SpineMessageHeader)) + sizeof(struct BodyToHead) + (sizeof(crc_t)))"
                  ,"spine_hal.c",0x210,"hal_get_a_frame");
  }
  do {
    iVar1 = FUN_0000ad4c(param_1,param_2);
    __fd = DAT_00039e50;
  } while (iVar1 < 0);
  if (iVar1 == 0) {
    iVar1 = FUN_0000aa58();
    if ((iVar1 != 0) && (__n = read(__fd,&DAT_0003bef0,0x1000), __fd = DAT_0003be54, 0 < (int)__n))
    {
      uVar2 = 0x2000 - DAT_0003be54;
      if (uVar2 < __n) {
        uVar3 = FUN_0000a5cc();
        __printf_chk(1,&DAT_0000c4df,"spine.receive_data_overflow");
        __printf_chk(1,&DAT_0000cb2a,__n - uVar2);
        __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
        DAT_0003be54 = 0;
      }
      memcpy(&DAT_00039e54 + __fd,&DAT_0003bef0,__n);
      DAT_0003be54 = __n + __fd;
    }
    return 0;
  }
  return param_1;
}



int FUN_0000b0ec(int param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined8 uVar5;
  
  lVar1 = FUN_00009470();
  lVar1 = (longlong)param_1 * 1000000 + lVar1;
  uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
  do {
    iVar2 = FUN_0000af88(&DAT_00039948,0x500);
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar5 = FUN_00009470();
    bVar4 = uVar3 <= (uint)uVar5;
    if ((uint)uVar5 == uVar3) {
      bVar4 = (uint)lVar1 <= (uint)((ulonglong)uVar5 >> 0x20);
    }
  } while (!bVar4);
  return 0;
}



int FUN_0000b144(uint param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined8 uVar5;
  
  lVar1 = FUN_00009470();
  lVar1 = (longlong)param_2 * 1000000 + lVar1;
  uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
  while( true ) {
    uVar5 = FUN_00009470();
    bVar4 = uVar3 <= (uint)uVar5;
    if ((uint)uVar5 == uVar3) {
      bVar4 = (uint)lVar1 <= (uint)((ulonglong)uVar5 >> 0x20);
    }
    if (bVar4) break;
    iVar2 = FUN_0000b0ec(param_2);
    if ((iVar2 != 0) && ((uint)*(ushort *)(iVar2 + 4) == param_1)) {
      return iVar2;
    }
  }
  return 0;
}



int FUN_0000b1a0(uint param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined8 uVar5;
  
  lVar1 = FUN_00009470();
  lVar1 = (longlong)param_2 * 1000000 + lVar1;
  uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
  do {
    do {
      uVar5 = FUN_00009470();
      bVar4 = uVar3 <= (uint)uVar5;
      if ((uint)uVar5 == uVar3) {
        bVar4 = (uint)lVar1 <= (uint)((ulonglong)uVar5 >> 0x20);
      }
      if (bVar4) {
        return 0;
      }
      iVar2 = FUN_0000b0ec(param_2);
    } while (iVar2 == 0);
    if ((uint)*(ushort *)(iVar2 + 4) == param_1) {
      return iVar2;
    }
  } while ((*(ushort *)(iVar2 + 4) != 0x6b61) || (-1 < *(int *)(iVar2 + 8)));
  return iVar2;
}



void FUN_0000b214(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint __line;
  char *__assertion;
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_20 = param_1;
  __line = FUN_0000a4fc(param_1,0);
  if ((int)__line < 0) {
    __assertion = "expected_len >= 0";
    __line = 0x17c;
  }
  else {
    if (__line == (param_3 & 0xffff)) {
      if (__line < 0x4f5) {
        DAT_00039e4c = (undefined2)param_1;
        DAT_00039e48 = 0x423248aa;
        DAT_00039e4e = (undefined2)__line;
        local_20 = FUN_0000a6d0(param_2,param_3);
        FUN_0000ab7c(&DAT_00039e48,8);
        FUN_0000ab7c(param_2,param_3);
        FUN_0000ab7c(&local_20,4);
        tcdrain(DAT_00039e50);
        if (local_1c != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
          __stack_chk_fail();
        }
        return;
      }
      __line = 0x17e;
      __assertion = "payload_len <= (1280 - (sizeof(struct SpineMessageHeader)) - (sizeof(crc_t)))";
    }
    else {
      __line = 0x17d;
      __assertion = "expected_len == payload_len";
    }
  }
                    // WARNING: Subroutine does not return
  __assert_fail(__assertion,"spine_hal.c",__line,"spine_construct_header");
}



void FUN_0000b378(void)

{
  undefined4 in_r3;
  undefined8 uVar1;
  
  uVar1 = FUN_0000a5cc();
  __printf_chk(1,&DAT_0000c4df,"spine.set_mode");
  __printf_chk(1,"Sending Mode Change %x",0x6d64);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar1 >> 0x20),(int)uVar1);
  FUN_0000b214(0x6d64,0,0,in_r3);
  return;
}



void FUN_0000b3f0(void)

{
  return;
}



int FUN_0000b3f4(void)

{
  int iVar1;
  timespec local_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = clock_gettime(7,&local_1c);
  if (iVar1 == 0) {
    iVar1 = FUN_0000c014(local_1c.tv_nsec,1000000);
    iVar1 = local_1c.tv_sec * 1000 + iVar1;
  }
  else {
    iVar1 = 0;
  }
  if (local_14 == __stack_chk_guard) {
    return iVar1;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void FUN_0000b474(undefined4 param_1,int param_2)

{
  ushort **ppuVar1;
  uint __c;
  byte *pbVar2;
  byte *pbVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_0000b3f4();
  pbVar3 = (byte *)(param_2 + -1);
  __printf_chk(1,&DAT_0000c4df,param_1);
  pbVar2 = pbVar3;
  do {
    pbVar2 = pbVar2 + 1;
    __printf_chk(1,&DAT_0000cbcf,(uint)*pbVar2);
  } while (pbVar2 != (byte *)(param_2 + 0xf));
  putchar(0x1f);
  ppuVar1 = __ctype_b_loc();
  do {
    pbVar3 = pbVar3 + 1;
    __c = (uint)*pbVar3;
    if (((*ppuVar1)[__c] & 0x4000) == 0) {
      __c = 0x2a;
    }
    putchar(__c);
  } while (pbVar3 != (byte *)(param_2 + 0xf));
  __printf_chk(1,&DAT_0000cbd4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
  return;
}



void FUN_0000b560(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_0000b3f4();
  __printf_chk(1,&DAT_0000c4df,"dfu.error");
  __printf_chk(1,&DAT_0000c5a9,param_1);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar1 >> 0x20),(int)uVar1);
  return;
}



undefined4 FUN_0000b5cc(int param_1,int param_2)

{
  int iVar1;
  
  FUN_0000b474("dfu.installed_version");
  FUN_0000b474("dfu.desired_version  ",param_1);
  iVar1 = 0;
  while (*(byte *)(param_1 + iVar1) == *(byte *)(param_2 + iVar1)) {
    iVar1 = iVar1 + 1;
    if (iVar1 == 0x10) {
      return 2;
    }
  }
  if (*(byte *)(param_2 + iVar1) <= *(byte *)(param_1 + iVar1)) {
    return 1;
  }
  return 3;
}



uint FUN_0000b638(int *param_1)

{
  return (uint)(0 < *param_1);
}



int FUN_0000b64c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = FUN_0000b144(0x6662,500,param_3,param_4,param_4);
  if (iVar1 == 0) {
    uVar3 = FUN_0000b3f4();
    __printf_chk(1,&DAT_0000c4df,"dfu.send_data_noframe");
    __printf_chk(1,"Not seeing boot frames");
  }
  else {
    FUN_0000b214(0x6675,param_1,0x404);
    iVar2 = FUN_0000b144(0x6b61,1000);
    if (iVar2 == 0) {
      uVar3 = FUN_0000b3f4();
      __printf_chk(1,&DAT_0000c4df,"dfu.send_data_timeout");
      __printf_chk(1,"No response to DFU_PACKET");
      __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
      return 0;
    }
    iVar1 = FUN_0000b638(iVar2 + 8);
    if (iVar1 != 0) {
      return 1;
    }
    uVar3 = FUN_0000b3f4();
    __printf_chk(1,&DAT_0000c4df,"dfu.send_data_nak");
    __printf_chk(1,"Got NACK %d in response",*(undefined4 *)(iVar2 + 8));
  }
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
  return iVar1;
}



undefined4 * FUN_0000b7c4(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  
  uVar6 = FUN_0000b3f4();
  __printf_chk(1,&DAT_0000c4df,"dfu.request_version");
  __printf_chk(1,&DAT_0000ccb2);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
  FUN_0000b214(0x7276,0,0);
  iVar1 = FUN_0000b1a0(0x7276,1000);
  if (iVar1 == 0) {
    uVar6 = FUN_0000b3f4();
    __printf_chk(1,&DAT_0000c4df,"dfu.request_version.no_response");
    __printf_chk(1,"Assuming erased");
  }
  else {
    if (*(short *)(iVar1 + 4) == 0x7276) {
      puVar2 = &DAT_0003cef0;
      puVar4 = (undefined4 *)(iVar1 + 0x20);
      do {
        puVar5 = puVar4 + 2;
        uVar3 = puVar4[1];
        *puVar2 = *puVar4;
        puVar2[1] = uVar3;
        puVar2 = puVar2 + 2;
        puVar4 = puVar5;
      } while (puVar5 != (undefined4 *)(iVar1 + 0x30));
      goto LAB_0000b934;
    }
    uVar6 = FUN_0000b3f4();
    __printf_chk(1,&DAT_0000c4df,"dfu.request_version.nack");
    __printf_chk(1,&DAT_0000c5a9,*(undefined4 *)(iVar1 + 8));
  }
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
  puVar2 = &DAT_0003cef0;
  puVar4 = (undefined4 *)"-----Erased-----";
  do {
    uVar3 = puVar4[1];
    puVar5 = puVar4 + 2;
    *puVar2 = *puVar4;
    puVar2[1] = uVar3;
    puVar2 = puVar2 + 2;
    puVar4 = puVar5;
  } while (puVar5 != (undefined4 *)0xcd0f);
LAB_0000b934:
  return &DAT_0003cef0;
}



undefined * FUN_0000b970(char *param_1,FILE **param_2)

{
  FILE *__stream;
  undefined4 uVar1;
  size_t sVar2;
  undefined *puVar3;
  undefined8 uVar4;
  char *pcVar5;
  FILE **local_1c;
  
  pcVar5 = param_1;
  local_1c = param_2;
  uVar4 = FUN_0000b3f4();
  __printf_chk(1,&DAT_0000c4df,"dfu.open_file");
  __printf_chk(1,"opening \"%s\"",param_1,0x1362,pcVar5,local_1c);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
  __stream = fopen(param_1,"rb");
  *param_2 = __stream;
  if (__stream == (FILE *)0x0) {
    uVar1 = 9;
  }
  else {
    puVar3 = &DAT_0003cf08;
    sVar2 = fread(&DAT_0003cf08,1,0x10,__stream);
    if (sVar2 == 0x10) {
      return puVar3;
    }
    uVar1 = 10;
  }
  FUN_0000b560(uVar1);
  return (undefined *)0;
}



undefined4 FUN_0000ba54(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  undefined8 uVar3;
  
  uVar3 = FUN_0000b3f4();
  __printf_chk(1,&DAT_0000c4df,"dfu.erase_image");
  __printf_chk(1,"erasing installed image");
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3,in_r3);
  FUN_0000b214(0x7878,0,0);
  iVar1 = FUN_0000b144(0x6b61,5000);
  if (iVar1 == 0) {
    uVar3 = FUN_0000b3f4();
    __printf_chk(1,&DAT_0000c4df,"dfu.erase_timeout");
    __printf_chk(1,"Erase timeout");
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
    return 0;
  }
  iVar2 = FUN_0000b638(iVar1 + 8);
  if (iVar2 == 0) {
    uVar3 = FUN_0000b3f4();
    __printf_chk(1,&DAT_0000c4df,"dfu.erase_nak");
    __printf_chk(1,"Got NACK %d in response",*(undefined4 *)(iVar1 + 8));
    __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
    return 0;
  }
  return 1;
}



size_t FUN_0000bba4(FILE *param_1)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined2 local_430;
  undefined2 local_42e;
  undefined auStack1068 [1024];
  int local_2c;
  
  iVar4 = 0;
  local_2c = __stack_chk_guard;
  memset(&local_430,0,0x404);
  do {
    sVar1 = feof(param_1);
    if (sVar1 != 0) {
      sVar2 = 1;
LAB_0000bcc8:
      if (local_2c != __stack_chk_guard) {
                    // WARNING: Subroutine does not return
        __stack_chk_fail();
      }
      return sVar2;
    }
    sVar2 = fread(auStack1068,4,0x100,param_1);
    if (sVar2 < 0x100) {
      iVar3 = ferror(param_1);
      if (iVar3 != 0) {
        FUN_0000b560(10);
        sVar2 = sVar1;
        goto LAB_0000bcc8;
      }
      if (sVar2 == 0) {
        uVar5 = FUN_0000b3f4();
        __printf_chk(1,&DAT_0000c4df,"dfu.send_image_error");
        __printf_chk(1,"unexpected itemcount of %zd",0);
        __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
        goto LAB_0000bcc8;
      }
    }
    local_430 = (undefined2)iVar4;
    local_42e = (undefined2)sVar2;
    sVar1 = FUN_0000b64c();
    if (sVar1 == 0) {
      FUN_0000b560(0xb);
      sVar2 = sVar1;
      goto LAB_0000bcc8;
    }
    iVar4 = sVar2 * 4 + iVar4;
  } while( true );
}



int FUN_0000bd04(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  undefined8 uVar3;
  
  uVar3 = FUN_0000b3f4();
  __printf_chk(1,&DAT_0000c4df,"dfu.validate");
  __printf_chk(1,&DAT_0000ccb2);
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3,in_r3);
  iVar1 = FUN_0000b144(0x6662,500);
  if (iVar1 == 0) {
    uVar3 = FUN_0000b3f4();
    __printf_chk(1,&DAT_0000c4df,"dfu.validate_noframes");
    __printf_chk(1,"not seeing boot frames");
  }
  else {
    FUN_0000b214(0x7374,0,0);
    iVar2 = FUN_0000b144(0x6b61,5000);
    if (iVar2 == 0) {
      uVar3 = FUN_0000b3f4();
      __printf_chk(1,&DAT_0000c4df,"dfu.validate_no_ack");
      __printf_chk(1,"Did not get ACK response");
      __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
    }
    else {
      iVar1 = FUN_0000b638(iVar2 + 8);
      if (iVar1 == 0) {
        uVar3 = FUN_0000b3f4();
        __printf_chk(1,&DAT_0000c4df,"dfu.validate_nak");
        __printf_chk(1,"Got NACK %d in response",*(undefined4 *)(iVar2 + 8));
        goto LAB_0000bec4;
      }
    }
    iVar1 = FUN_0000b144(0x6466,500);
    if (iVar1 != 0) {
      return 1;
    }
    uVar3 = FUN_0000b3f4();
    __printf_chk(1,&DAT_0000c4df,"dfu.validate_timeout");
    __printf_chk(1,"Did not get app DATA_FRAME");
  }
LAB_0000bec4:
  __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
  return iVar1;
}



undefined4 FUN_0000bf10(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  iVar1 = FUN_0000b7c4();
  if (iVar1 == 0) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = FUN_0000b970(param_1);
    if ((param_2 == 0) && (uVar3 = FUN_0000b5cc(uVar2,iVar1), 1 < uVar3)) {
      uVar2 = 0xffffffff;
    }
    else {
      iVar1 = FUN_0000ba54();
      if (iVar1 == 0) {
        uVar2 = 0x11;
      }
      else {
        iVar1 = FUN_0000bba4(DAT_0003cf00);
        if (iVar1 == 0) {
          uVar2 = 0x12;
        }
        else {
          iVar1 = FUN_0000bd04();
          if (iVar1 == 0) {
            uVar2 = 0x13;
          }
          else {
            uVar4 = FUN_0000b3f4();
            __printf_chk(1,&DAT_0000c4df,"dfu.success");
            __printf_chk(1,"Success");
            __printf_chk(1,&DAT_0000c52d,(int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
            uVar2 = 0;
          }
        }
      }
    }
  }
  return uVar2;
}



longlong FUN_0000c014(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  if (param_2 == 0) {
    uVar6 = raise(8);
    return (ulonglong)uVar6 << 0x20;
  }
  uVar6 = param_1 ^ param_2;
  if ((int)param_2 < 0) {
    param_2 = -param_2;
  }
  if (param_2 - 1 == 0) {
    if ((int)(uVar6 ^ param_1) < 0) {
      param_1 = -param_1;
    }
    return CONCAT44(param_1,param_2);
  }
  uVar5 = param_1;
  if ((int)param_1 < 0) {
    uVar5 = -param_1;
  }
  if (uVar5 <= param_2) {
    if (uVar5 < param_2) {
      param_1 = 0;
    }
    if (uVar5 == param_2) {
      param_1 = (int)uVar6 >> 0x1f | 1;
    }
    return CONCAT44(param_1,param_2);
  }
  if ((param_2 & param_2 - 1) == 0) {
    iVar1 = count_leading_zeroes(param_2);
    uVar5 = uVar5 >> (0x1fU - iVar1 & 0xff);
    if ((int)uVar6 < 0) {
      uVar5 = -uVar5;
    }
    return CONCAT44(uVar5,param_2);
  }
  iVar3 = count_leading_zeroes(param_2);
  iVar1 = count_leading_zeroes(uVar5);
  param_2 = param_2 << (iVar3 - iVar1 & 0xffU);
  uVar4 = 1 << (iVar3 - iVar1 & 0xffU);
  uVar2 = 0;
  while( true ) {
    if (param_2 <= uVar5) {
      uVar5 = uVar5 - param_2;
      uVar2 = uVar2 | uVar4;
    }
    if (param_2 >> 1 <= uVar5) {
      uVar5 = uVar5 - (param_2 >> 1);
      uVar2 = uVar2 | uVar4 >> 1;
    }
    if (param_2 >> 2 <= uVar5) {
      uVar5 = uVar5 - (param_2 >> 2);
      uVar2 = uVar2 | uVar4 >> 2;
    }
    if (param_2 >> 3 <= uVar5) {
      uVar5 = uVar5 - (param_2 >> 3);
      uVar2 = uVar2 | uVar4 >> 3;
    }
    bVar7 = uVar5 == 0;
    if (!bVar7) {
      uVar4 = uVar4 >> 4;
      bVar7 = uVar4 == 0;
    }
    if (bVar7) break;
    param_2 = param_2 >> 4;
  }
  if ((int)uVar6 < 0) {
    uVar2 = -uVar2;
  }
  return CONCAT44(uVar2,param_2);
}



void FUN_0000c110(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  if (param_4 != 0 || param_3 != 0) {
    FUN_0000c198();
    return;
  }
  raise(8);
  return;
}



void FUN_0000c15c(uint param_1,int param_2,uint param_3,int param_4,int *param_5)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_0000c1d8();
  uVar2 = (uint)((ulonglong)uVar4 >> 0x20);
  lVar1 = (ulonglong)uVar2 * (ulonglong)param_3;
  uVar3 = (uint)lVar1;
  *param_5 = param_1 - uVar3;
  param_5[1] = param_2 - (uVar2 * param_4 + param_3 * (int)uVar4 + (int)((ulonglong)lVar1 >> 0x20) +
                         (uint)(param_1 < uVar3));
  return;
}



void FUN_0000c198(uint param_1,int param_2,uint param_3,int param_4,int *param_5)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_0000c350();
  uVar2 = (uint)((ulonglong)uVar4 >> 0x20);
  lVar1 = (ulonglong)param_3 * (ulonglong)uVar2;
  uVar3 = (uint)lVar1;
  *param_5 = param_1 - uVar3;
  param_5[1] = param_2 - (param_3 * (int)uVar4 + uVar2 * param_4 + (int)((ulonglong)lVar1 >> 0x20) +
                         (uint)(param_1 < uVar3));
  return;
}



undefined8 FUN_0000c1d8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  undefined8 in_d0;
  uint uVar6;
  ulonglong uVar7;
  undefined8 in_d3;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 in_d20;
  undefined8 in_d22;
  
  if ((int)param_2 < 0) {
    bVar5 = param_1 != 0;
    param_1 = -param_1;
    uVar4 = 0xffffffff;
    param_2 = -(param_2 + bVar5);
  }
  else {
    uVar4 = 0;
  }
  if ((int)param_4 < 0) {
    bVar5 = param_3 != 0;
    param_3 = -param_3;
    uVar4 = ~uVar4;
    param_4 = -(param_4 + bVar5);
  }
  bVar5 = param_2 <= param_4;
  if (param_4 == param_2) {
    bVar5 = param_1 <= param_3;
  }
  if (bVar5 && (param_4 != param_2 || param_3 != param_1)) {
    uVar10 = 0;
  }
  else {
    if (param_4 == 0) {
      iVar2 = count_leading_zeroes(param_3);
      iVar2 = iVar2 + 0x20;
    }
    else {
      iVar2 = count_leading_zeroes(param_4);
    }
    if (param_2 == 0) {
      iVar3 = count_leading_zeroes(param_1);
      iVar3 = iVar3 + 0x20;
    }
    else {
      iVar3 = count_leading_zeroes(param_2);
    }
    iVar2 = iVar2 - iVar3;
    VectorSetElement(iVar2,in_d0,0,4);
    uVar7 = VectorShiftLeft(CONCAT44(param_4,param_3),in_d0,8,1);
    uVar1 = (uint)(uVar7 >> 0x20);
    uVar6 = (uint)uVar7;
    bVar5 = uVar1 <= param_2;
    if (param_2 == uVar1) {
      bVar5 = uVar6 <= param_1;
    }
    if (bVar5) {
      bVar5 = param_1 < uVar6;
      param_1 = param_1 - uVar6;
      param_2 = param_2 - (uVar1 + bVar5);
      VectorSetElement(iVar2,in_d3,0,4);
      uVar10 = VectorShiftLeft(1,in_d3,8,1);
    }
    else {
      uVar10 = 0;
    }
    if (iVar2 != 0) {
      uVar8 = VectorShiftRight(((ulonglong)uVar1 << 0x20) + (uVar7 & 0xffffffff),0x3f);
      iVar3 = iVar2;
      do {
        uVar9 = VectorSub(CONCAT44(param_2,param_1),uVar8,8);
        uVar1 = (uint)((ulonglong)uVar8 >> 0x20);
        uVar9 = VectorAdd(uVar9,uVar9,8);
        bVar5 = uVar1 <= param_2;
        if (param_2 == uVar1) {
          bVar5 = (uint)uVar8 <= param_1;
        }
        if (bVar5) {
          uVar9 = CONCAT44((int)((ulonglong)uVar9 >> 0x20) + (uint)(0xfffffffe < (uint)uVar9),
                           (uint)uVar9 + 1);
        }
        else {
          uVar9 = CONCAT44(param_2 * 2 + (uint)CARRY4(param_1,param_1),param_1 * 2);
        }
        iVar3 = iVar3 + -1;
        param_2 = (uint)((ulonglong)uVar9 >> 0x20);
        param_1 = (uint)uVar9;
      } while (iVar3 != 0);
      VectorSetElement(iVar2,in_d22,0,4);
      uVar10 = VectorAdd(uVar9,uVar10,8);
      VectorSetElement(-iVar2,in_d20,0,4);
      uVar8 = VectorShiftLeft(uVar9,in_d20,8,1);
      uVar8 = VectorShiftLeft(uVar8,in_d22,8,1);
      uVar10 = VectorSub(uVar10,uVar8,8);
    }
  }
  if (uVar4 != 0) {
    uVar4 = 1;
  }
  uVar1 = (uint)uVar10 ^ -uVar4;
  return CONCAT44(uVar4 + uVar1,
                  ((uint)((ulonglong)uVar10 >> 0x20) ^ -(uint)(uVar4 != 0)) +
                  (uint)CARRY4(uVar4,uVar1));
}



undefined8 FUN_0000c350(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 in_d2;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 in_d17;
  undefined8 uVar9;
  undefined8 in_d20;
  undefined8 in_d22;
  
  bVar4 = param_2 <= param_4;
  if (param_4 == param_2) {
    bVar4 = param_1 <= param_3;
  }
  if (bVar4 && (param_4 != param_2 || param_3 != param_1)) {
    uVar9 = 0;
  }
  else {
    if (param_4 == 0) {
      iVar1 = count_leading_zeroes(param_3);
      iVar1 = iVar1 + 0x20;
    }
    else {
      iVar1 = count_leading_zeroes(param_4);
    }
    if (param_2 == 0) {
      iVar2 = count_leading_zeroes(param_1);
      iVar2 = iVar2 + 0x20;
    }
    else {
      iVar2 = count_leading_zeroes(param_2);
    }
    iVar1 = iVar1 - iVar2;
    VectorSetElement(iVar1,in_d17,0,4);
    uVar6 = VectorShiftLeft(CONCAT44(param_4,param_3),in_d17,8,1);
    uVar3 = (uint)(uVar6 >> 0x20);
    uVar5 = (uint)uVar6;
    bVar4 = uVar3 <= param_2;
    if (param_2 == uVar3) {
      bVar4 = uVar5 <= param_1;
    }
    if (bVar4) {
      bVar4 = param_1 < uVar5;
      param_1 = param_1 - uVar5;
      param_2 = param_2 - (uVar3 + bVar4);
      VectorSetElement(iVar1,in_d2,0,4);
      uVar9 = VectorShiftLeft(1,in_d2,8,1);
    }
    else {
      uVar9 = 0;
    }
    if (iVar1 != 0) {
      uVar7 = VectorShiftRight(((ulonglong)uVar3 << 0x20) + (uVar6 & 0xffffffff),0x3f);
      iVar2 = iVar1;
      do {
        uVar8 = VectorSub(CONCAT44(param_2,param_1),uVar7,8);
        uVar3 = (uint)((ulonglong)uVar7 >> 0x20);
        uVar8 = VectorAdd(uVar8,uVar8,8);
        bVar4 = uVar3 <= param_2;
        if (param_2 == uVar3) {
          bVar4 = (uint)uVar7 <= param_1;
        }
        if (bVar4) {
          uVar8 = CONCAT44((int)((ulonglong)uVar8 >> 0x20) + (uint)(0xfffffffe < (uint)uVar8),
                           (uint)uVar8 + 1);
        }
        else {
          uVar8 = CONCAT44(param_2 * 2 + (uint)CARRY4(param_1,param_1),param_1 * 2);
        }
        iVar2 = iVar2 + -1;
        param_2 = (uint)((ulonglong)uVar8 >> 0x20);
        param_1 = (uint)uVar8;
      } while (iVar2 != 0);
      VectorSetElement(iVar1,in_d22,0,4);
      uVar9 = VectorAdd(uVar8,uVar9,8);
      VectorSetElement(-iVar1,in_d20,0,4);
      uVar7 = VectorShiftLeft(uVar8,in_d20,8,1);
      uVar7 = VectorShiftLeft(uVar7,in_d22,8,1);
      uVar9 = VectorSub(uVar9,uVar7,8);
    }
  }
  return CONCAT44((int)uVar9,(int)((ulonglong)uVar9 >> 0x20));
}



// WARNING: Removing unreachable block (ram,0x0000c484)

void FUN_0000c458(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  int iVar2;
  
  _DT_INIT();
  iVar2 = 0;
  do {
    ppcVar1 = (code **)(&__DT_INIT_ARRAY + iVar2);
    iVar2 = iVar2 + 1;
    (**ppcVar1)(param_1,param_2,param_3,*ppcVar1,param_4);
  } while (iVar2 != 1);
  return;
}



void _DT_FINI(void)

{
  return;
}


