typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned int    uint;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
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




undefined8 entry(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined8 uVar1;
  
  uVar1 = FUN_0000002a(param_1,param_2,param_3,param_4);
  FUN_00000728((int)((ulonglong)uVar1 >> 0x20),(uint)uVar1,param_3,param_4);
  return uVar1;
}



undefined8 FUN_00000010(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  FUN_00000728(param_1,param_2,param_3,param_4);
  return CONCAT44(param_1,param_2);
}



void FUN_0000001c(void)

{
  FUN_0000a8ec((int *)0x0);
  FUN_00000846();
  return;
}



void FUN_0000002a(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00000048();
  FUN_00000010(iVar1,param_3,param_3,param_4);
  uVar2 = FUN_0000d834();
  uVar2 = FUN_00000856((int)((ulonglong)uVar2 >> 0x20),(int)uVar2);
  FUN_0000001c();
                    // WARNING: Subroutine does not return
  thunk_FUN_00000060((int)((ulonglong)uVar2 >> 0x20),(int)uVar2);
}



void FUN_0000003c(undefined4 param_1,undefined4 param_2)

{
  FUN_0000001c();
                    // WARNING: Subroutine does not return
  thunk_FUN_00000060(param_1,param_2);
}



undefined4 FUN_00000048(void)

{
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00000060(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int extraout_r1;
  undefined4 *puVar5;
  undefined *in_lr;
  byte in_Q;
  undefined4 uStack16;
  undefined4 uStack12;
  undefined *puStack8;
  undefined4 uStack4;
  
  disableFIQinterrupts();
  uStack4 = param_4;
  puStack8 = (undefined *)param_3;
  uStack12 = param_2;
  uStack16 = param_1;
  puStack8 = &DAT_000900c8;
  puVar5 = &uStack16;
  if ((DAT_000900cc == 0) && (DAT_000900cc = DAT_000900d0, DAT_000900d0 == 0)) {
    DAT_000900cc = _DAT_00083000;
    DAT_000900d0 = _DAT_00083004;
    DAT_00090108 = getMainStackPointer();
    DAT_0009010c = getProcessStackPointer();
    DAT_00090118 = (uint)(byte)(SBORROW4(_DAT_00083004,_DAT_00083004) << 1 | 0xcU | in_Q) << 0x1b;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getCurrentExceptionNumber();
      DAT_00090118 = DAT_00090118 | uVar4 & 0x1f;
    }
    DAT_0009011c = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      DAT_0009011c = isIRQinterruptsEnabled();
    }
    DAT_00090120 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      DAT_00090120 = isFIQinterruptsEnabled();
    }
    DAT_00090124 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      DAT_00090124 = getBasePriority();
    }
    cVar2 = isThreadModePrivileged();
    cVar3 = isUsingMainStack();
    DAT_00090128 = (uint)(byte)((cVar3 != '\x01') << 1 | cVar2 != '\x01');
    DAT_00090114 = 0x61;
    DAT_0009012c = _DAT_e000ed24;
    DAT_00090130 = _DAT_e000ed28;
    DAT_00090134 = _DAT_e000ed2c;
    DAT_00090138 = _DAT_e000ed30;
    DAT_0009013c = _DAT_e000ed34;
    DAT_00090140 = _DAT_e000ed38;
    DAT_00090144 = _DAT_e000ed3c;
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getCurrentExceptionNumber();
      uVar4 = uVar4 & 0x1f;
    }
    DAT_000900d4 = param_1;
    DAT_000900d8 = param_2;
    DAT_000900dc = param_3;
    DAT_000900e0 = param_4;
    puStack8 = in_lr;
    FUN_0000c1f4(in_lr,uVar4);
    FUN_0000c0a4(0);
    FUN_0000e174();
    DAT_000900cc = extraout_r1;
    puVar5 = (undefined4 *)register0x00000054;
  }
  do {
    puVar5[-1] = DAT_000900cc;
    *(undefined **)(puVar5 + -2) = puStack8;
    puStack8 = (undefined *)puVar5[-2];
    DAT_000900cc = puVar5[-1];
  } while( true );
}



longlong FUN_00000108(void)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getBasePriority();
  }
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  WaitForInterrupt();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar2);
  }
  enableIRQinterrupts();
  return (longlong)((ulonglong)uVar2 << 0x20);
}



longlong FUN_00000128(void)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getBasePriority();
  }
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  WaitForInterrupt();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar2);
  }
  enableIRQinterrupts();
  return (longlong)((ulonglong)uVar2 << 0x20);
}



int FUN_00000154(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_000006e0();
  FUN_0000d758();
  iVar1 = DAT_000900bc;
  uVar2 = param_1 + 7U & 0xfffffff8;
  uVar3 = DAT_000900bc + uVar2;
  if (uVar3 < DAT_000900c0) {
    DAT_000900bc = uVar3;
    FUN_00016a76(-uVar2);
    FUN_0001a7ec();
    return iVar1;
  }
  FUN_000065ec(0xe1,0,0,0,0);
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00000168(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  FUN_000006e0();
  if (DAT_000900b4 != '\0') {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  DAT_000900b8 = DAT_000900b8 + 1;
  return;
}



int FUN_00000182(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    FUN_00000168(param_1);
    return 0;
  }
  if (param_1 != 0) {
    FUN_000006e0();
    FUN_0000d758();
    iVar1 = DAT_000900bc;
    uVar3 = param_2 + 7U & 0xfffffff8;
    uVar2 = DAT_000900bc + uVar3;
    if (uVar2 < DAT_000900c0) {
      DAT_000900bc = uVar2;
      FUN_00016a76(-uVar3);
      FUN_0001a7ec();
      FUN_0000044c(iVar1,param_1,param_2);
      return iVar1;
    }
    FUN_000065ec(0xe1,0,0,0,0);
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  iVar1 = FUN_00000154(param_2);
  return iVar1;
}



undefined8 FUN_000001b0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  
  if ((param_4 | param_3) == 0) {
    return 0;
  }
  uVar5 = 0;
  if (param_4 != 0) {
    iVar3 = count_leading_zeroes(param_4);
    uVar1 = param_4 << iVar3;
    uVar5 = uVar1 >> iVar3 ^ param_4 | param_3;
  }
  else {
    iVar3 = count_leading_zeroes(param_3);
    uVar1 = param_3 << iVar3;
  }
  iVar4 = -iVar3 + 0x20;
  if (param_4 != 0) {
    uVar1 = uVar1 | param_3 >> iVar4;
    iVar4 = -iVar3 + 0x40;
  }
  uVar2 = uVar1 >> 0x10;
  if ((uVar5 | uVar1 << 0x10) != 0) {
    uVar2 = uVar2 + 1;
  }
  iVar3 = 0;
  uVar5 = 0;
  while (param_4 + (param_1 < param_3) <= param_2) {
    if (param_2 != 0) {
      iVar8 = count_leading_zeroes(param_2);
      uVar1 = param_2 << iVar8;
    }
    else {
      iVar8 = count_leading_zeroes(param_1);
      uVar1 = param_1 << iVar8;
    }
    iVar9 = -iVar8 + 0x20;
    if (param_2 != 0) {
      uVar1 = uVar1 | param_1 >> iVar9;
      iVar9 = -iVar8 + 0x40;
    }
    uVar10 = (iVar9 - iVar4) - 0x10;
    uVar6 = uVar1 / uVar2 >> 0x20 - (uVar10 & 0x1f);
    uVar7 = uVar6;
    uVar1 = uVar1 / uVar2 << (uVar10 & 0x1f);
    if ((int)uVar10 < 0) {
      uVar7 = 0;
      uVar1 = uVar6;
    }
    if (0x1f < (int)uVar10) {
      uVar7 = uVar1;
    }
    if ((iVar9 - iVar4) + -0x30 < 0 == SBORROW4(uVar10,0x20)) {
      uVar1 = 0;
    }
    if ((uVar1 | uVar7) == 0) {
      uVar1 = 1;
    }
    bVar11 = CARRY4(uVar5,uVar1);
    uVar5 = uVar5 + uVar1;
    uVar6 = (uint)((ulonglong)uVar1 * (ulonglong)param_3);
    iVar3 = iVar3 + uVar7 + bVar11;
    bVar11 = param_1 < uVar6;
    param_1 = param_1 - uVar6;
    param_2 = param_2 - (uVar1 * param_4 +
                         uVar7 * param_3 + (int)((ulonglong)uVar1 * (ulonglong)param_3 >> 0x20) +
                        (uint)bVar11);
  }
  return CONCAT44(uVar5,iVar3);
}



ulonglong FUN_0000029e(uint param_1,int param_2,int param_3)

{
  if (param_3 + -0x20 < 0) {
    return CONCAT44(param_1 << param_3,param_2 << param_3 | param_1 >> 0x20 - param_3);
  }
  return (ulonglong)(param_1 << param_3 + -0x20);
}



undefined8 FUN_000002c4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  undefined8 uVar7;
  
  uVar5 = (int)param_2 >> 1;
  uVar1 = param_4 >> 1;
  if ((int)uVar5 < 0) {
    bVar6 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -param_2;
    if (bVar6) {
      param_2 = param_2 - 1;
    }
  }
  if ((int)param_4 < 0) {
    bVar6 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -param_4;
    if (bVar6) {
      param_4 = param_4 - 1;
    }
  }
  uVar7 = FUN_000001b0(param_1,param_2,param_3,param_4);
  iVar3 = (int)((ulonglong)uVar7 >> 0x20);
  iVar4 = (int)uVar7;
  if (((uVar5 ^ uVar1) & 0x40000000) != 0) {
    iVar2 = -iVar3;
    uVar7 = CONCAT44(iVar2,-iVar4);
    if (iVar3 != 0) {
      uVar7 = CONCAT44(iVar2,-iVar4 + -1);
    }
  }
  return uVar7;
}



char * FUN_0000030c(int param_1,char param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_1 + -1);
  do {
    pcVar1 = pcVar1 + 1;
    if (param_2 == *pcVar1) {
      return pcVar1;
    }
  } while (*pcVar1 != '\0');
  return (char *)0x0;
}



int FUN_00000320(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while (3 < param_3) {
      uVar4 = *param_1;
      param_1 = param_1 + 1;
      uVar3 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 - 4;
      if (uVar4 != uVar3) {
        if ((uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
            uVar4 >> 0x18) <=
            (uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18)) {
          return -1;
        }
        return 1;
      }
    }
  }
  if (param_3 != 0) {
    if ((param_3 & 1) == 0) goto LAB_00000358;
    param_3 = param_3 + 1;
    puVar1 = param_1;
    puVar2 = param_2;
    while( true ) {
      param_1 = (uint *)((int)puVar1 + 1);
      param_2 = (uint *)((int)puVar2 + 1);
      if ((uint)*(byte *)puVar1 - (uint)*(byte *)puVar2 != 0) {
        return (uint)*(byte *)puVar1 - (uint)*(byte *)puVar2;
      }
      param_3 = param_3 - 2;
      if (param_3 == 0) break;
LAB_00000358:
      puVar1 = (uint *)((int)param_1 + 1);
      puVar2 = (uint *)((int)param_2 + 1);
      if ((uint)*(byte *)param_1 - (uint)*(byte *)param_2 != 0) {
        return (uint)*(byte *)param_1 - (uint)*(byte *)param_2;
      }
    }
    return 0;
  }
  return 0;
}



uint * FUN_00000378(uint *param_1)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = param_1;
  while (((uint)puVar3 & 3) != 0) {
    puVar2 = (uint *)((int)puVar3 + 1);
    cVar1 = *(char *)puVar3;
    puVar3 = puVar2;
    if (cVar1 == '\0') {
      return (uint *)((int)puVar2 - ((int)param_1 + 1));
    }
  }
  do {
    uVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    uVar4 = uVar4 + 0xfefefeff & ~uVar4;
  } while ((uVar4 & 0x80808080) == 0);
  puVar3 = (uint *)((int)puVar3 - ((int)param_1 + 1));
  if ((uVar4 & 0x80) == 0) {
    if ((uVar4 & 0x8080) == 0) {
      if ((uVar4 & 0x808080) != 0) {
        return (uint *)((int)puVar3 + -1);
      }
    }
    else {
      puVar3 = (uint *)((int)puVar3 + -2);
    }
    return puVar3;
  }
  return (uint *)((int)puVar3 + -3);
}



uint FUN_000003b6(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while (3 < param_3) {
      uVar4 = *param_1;
      param_1 = param_1 + 1;
      uVar5 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 - 4;
      uVar6 = uVar4 + 0xfefefeff & ~uVar4 & 0x80808080;
      if (uVar6 != 0) {
        uVar1 = (uVar4 & 0xff) - (uVar5 & 0xff);
        if ((((uVar1 | uVar6 << 0x18) == 0) &&
            (uVar1 = (uVar4 & 0xffff) - (uVar5 & 0xffff), (uVar1 | uVar6 << 0x10) == 0)) &&
           (uVar1 = (uVar4 & 0xffffff) - (uVar5 & 0xffffff), (uVar1 | uVar6 << 8) == 0)) {
          uVar1 = (uVar4 >> 0x18) - (uVar5 >> 0x18);
        }
        return uVar1;
      }
      if (uVar4 != uVar5) {
        if ((uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
            uVar4 >> 0x18) <=
            (uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
            uVar5 >> 0x18)) {
          return 0xffffffff;
        }
        return 1;
      }
    }
  }
  if (param_3 == 0) {
    return 0;
  }
  while( true ) {
    pbVar2 = (byte *)((int)param_1 + 1);
    uVar4 = (uint)*(byte *)param_1;
    pbVar3 = (byte *)((int)param_2 + 1);
    uVar5 = (uint)*(byte *)param_2;
    if (((*(byte *)param_1 == 0) || (uVar4 != uVar5)) || (param_3 == 1)) break;
    param_1 = (uint *)((int)param_1 + 2);
    uVar4 = (uint)*pbVar2;
    param_2 = (uint *)((int)param_2 + 2);
    uVar5 = (uint)*pbVar3;
    if (((*pbVar2 == 0) || (uVar4 != uVar5)) || (param_3 = param_3 - 2, param_3 == 0)) break;
  }
  return uVar4 - uVar5;
}



undefined8 FUN_0000044c(uint *param_1,uint *param_2,uint param_3,byte param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  byte *pbVar4;
  byte bVar5;
  undefined2 uVar6;
  byte in_r12;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  char in_shift_carry;
  
  if (3 < param_3) {
    uVar7 = (uint)param_1 & 3;
    puVar2 = param_1;
    puVar3 = param_2;
    uVar8 = uVar7;
    if (uVar7 != 0) {
      bVar5 = *(byte *)param_2;
      puVar2 = (uint *)((int)param_2 + 1);
      if (uVar7 < 3) {
        puVar2 = (uint *)((int)param_2 + 2);
        uVar8 = (uint)*(byte *)(uint *)((int)param_2 + 1);
      }
      *(byte *)param_1 = bVar5;
      puVar3 = puVar2;
      if (uVar7 < 2) {
        puVar3 = (uint *)((int)puVar2 + 1);
        bVar5 = *(byte *)puVar2;
      }
      param_3 = (param_3 + uVar7) - 4;
      puVar1 = (uint *)((int)param_1 + 1);
      if (uVar7 < 3) {
        puVar1 = (uint *)((int)param_1 + 2);
        *(byte *)(uint *)((int)param_1 + 1) = (byte)uVar8;
      }
      puVar2 = puVar1;
      if (uVar7 < 2) {
        puVar2 = (uint *)((int)puVar1 + 1);
        *(byte *)puVar1 = bVar5;
      }
    }
    uVar7 = (uint)puVar3 & 3;
    if (uVar7 == 0) {
      while (uVar8 = param_3 - 0x20, 0x1f < param_3) {
        uVar7 = puVar3[1];
        uVar9 = puVar3[2];
        uVar10 = puVar3[3];
        *puVar2 = *puVar3;
        puVar2[1] = uVar7;
        puVar2[2] = uVar9;
        puVar2[3] = uVar10;
        uVar7 = puVar3[4];
        uVar9 = puVar3[5];
        uVar10 = puVar3[6];
        uVar11 = puVar3[7];
        puVar3 = puVar3 + 8;
        puVar2[4] = uVar7;
        puVar2[5] = uVar9;
        puVar2[6] = uVar10;
        puVar2[7] = uVar11;
        puVar2 = puVar2 + 8;
        param_3 = uVar8;
      }
      if (in_shift_carry != '\0') {
        uVar7 = *puVar3;
        uVar9 = puVar3[1];
        uVar10 = puVar3[2];
        uVar11 = puVar3[3];
        puVar3 = puVar3 + 4;
        *puVar2 = uVar7;
        puVar2[1] = uVar9;
        puVar2[2] = uVar10;
        puVar2[3] = uVar11;
        puVar2 = puVar2 + 4;
      }
      if ((int)(param_3 << 0x1c) < 0) {
        uVar7 = *puVar3;
        uVar9 = puVar3[1];
        puVar3 = puVar3 + 2;
        *puVar2 = uVar7;
        puVar2[1] = uVar9;
        puVar2 = puVar2 + 2;
      }
      puVar1 = puVar3;
      if (in_shift_carry != '\0') {
        puVar1 = puVar3 + 1;
        uVar7 = *puVar3;
      }
      uVar6 = (undefined2)uVar7;
      puVar3 = puVar2;
      if (in_shift_carry != '\0') {
        puVar3 = puVar2 + 1;
        *puVar2 = uVar7;
      }
      if ((uVar8 & 3) != 0) {
        bVar13 = (uVar8 >> 1 & 1) != 0;
        bVar5 = 0;
        bVar12 = (int)(param_3 << 0x1f) < 0;
        puVar2 = puVar1;
        if (bVar13) {
          puVar2 = (uint *)((int)puVar1 + 2);
          uVar6 = *(undefined2 *)puVar1;
        }
        puVar1 = puVar2;
        if (bVar12) {
          puVar1 = (uint *)((int)puVar2 + 1);
          bVar5 = *(byte *)puVar2;
        }
        puVar2 = puVar3;
        if (bVar13) {
          puVar2 = (uint *)((int)puVar3 + 2);
          *(undefined2 *)puVar3 = uVar6;
        }
        puVar3 = puVar2;
        if (bVar12) {
          puVar3 = (uint *)((int)puVar2 + 1);
          *(byte *)puVar2 = bVar5;
        }
        return CONCAT44(puVar3,puVar1);
      }
      return CONCAT44(puVar3,puVar1);
    }
    while( true ) {
      in_r12 = (byte)uVar8;
      if (param_3 < 8) break;
      puVar1 = puVar3 + 1;
      uVar7 = *puVar3;
      puVar3 = puVar3 + 2;
      uVar8 = *puVar1;
      *puVar2 = uVar7;
      puVar2[1] = uVar8;
      puVar2 = puVar2 + 2;
      param_3 = param_3 - 8;
    }
    param_3 = param_3 - 4;
    param_2 = puVar3;
    if (-1 < (int)param_3) {
      param_2 = puVar3 + 1;
      uVar7 = *puVar3;
    }
    param_4 = (byte)uVar7;
    param_1 = puVar2;
    if (-1 < (int)param_3) {
      param_1 = puVar2 + 1;
      *puVar2 = uVar7;
    }
  }
  bVar13 = (param_3 >> 1 & 1) != 0;
  bVar5 = 0;
  bVar12 = (int)(param_3 << 0x1f) < 0;
  if (bVar13) {
    pbVar4 = (byte *)((int)param_2 + 1);
    param_4 = *(byte *)param_2;
    param_2 = (uint *)((int)param_2 + 2);
    in_r12 = *pbVar4;
  }
  puVar3 = param_2;
  if (bVar12) {
    puVar3 = (uint *)((int)param_2 + 1);
    bVar5 = *(byte *)param_2;
  }
  if (bVar13) {
    pbVar4 = (byte *)((int)param_1 + 1);
    *(byte *)param_1 = param_4;
    param_1 = (uint *)((int)param_1 + 2);
    *pbVar4 = in_r12;
  }
  puVar2 = param_1;
  if (bVar12) {
    puVar2 = (uint *)((int)param_1 + 1);
    *(byte *)param_1 = bVar5;
  }
  return CONCAT44(puVar2,puVar3);
}



undefined8 FUN_000004de(undefined4 *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined uVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  bool bVar10;
  bool bVar11;
  char in_shift_carry;
  
  uVar5 = param_3 - 0x20;
  if (0x1f < param_3) {
    do {
      uVar7 = param_2[1];
      uVar8 = param_2[2];
      uVar9 = param_2[3];
      bVar10 = 0x1f < uVar5;
      uVar5 = uVar5 - 0x20;
      *param_1 = *param_2;
      param_1[1] = uVar7;
      param_1[2] = uVar8;
      param_1[3] = uVar9;
      param_4 = param_2[4];
      uVar7 = param_2[5];
      uVar8 = param_2[6];
      uVar9 = param_2[7];
      param_2 = param_2 + 8;
      param_1[4] = param_4;
      param_1[5] = uVar7;
      param_1[6] = uVar8;
      param_1[7] = uVar9;
      param_1 = param_1 + 8;
    } while (bVar10);
  }
  if (in_shift_carry != '\0') {
    param_4 = *param_2;
    uVar7 = param_2[1];
    uVar8 = param_2[2];
    uVar9 = param_2[3];
    param_2 = param_2 + 4;
    *param_1 = param_4;
    param_1[1] = uVar7;
    param_1[2] = uVar8;
    param_1[3] = uVar9;
    param_1 = param_1 + 4;
  }
  if ((int)(uVar5 << 0x1c) < 0) {
    param_4 = *param_2;
    uVar7 = param_2[1];
    param_2 = param_2 + 2;
    *param_1 = param_4;
    param_1[1] = uVar7;
    param_1 = param_1 + 2;
  }
  puVar3 = param_2;
  if (in_shift_carry != '\0') {
    puVar3 = param_2 + 1;
    param_4 = *param_2;
  }
  uVar6 = (undefined2)param_4;
  puVar2 = param_1;
  if (in_shift_carry != '\0') {
    puVar2 = param_1 + 1;
    *param_1 = param_4;
  }
  if ((uVar5 & 3) != 0) {
    bVar11 = (uVar5 >> 1 & 1) != 0;
    uVar4 = 0;
    bVar10 = (int)(uVar5 << 0x1f) < 0;
    puVar1 = puVar3;
    if (bVar11) {
      puVar1 = (undefined4 *)((int)puVar3 + 2);
      uVar6 = *(undefined2 *)puVar3;
    }
    puVar3 = puVar1;
    if (bVar10) {
      puVar3 = (undefined4 *)((int)puVar1 + 1);
      uVar4 = *(undefined *)puVar1;
    }
    puVar1 = puVar2;
    if (bVar11) {
      puVar1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar6;
    }
    puVar2 = puVar1;
    if (bVar10) {
      puVar2 = (undefined4 *)((int)puVar1 + 1);
      *(undefined *)puVar1 = uVar4;
    }
    return CONCAT44(puVar2,puVar3);
  }
  return CONCAT44(puVar2,puVar3);
}



undefined8 FUN_00000542(code **param_1,code **param_2,code **param_3)

{
  code **ppcVar1;
  code **ppcVar2;
  code **ppcVar3;
  int *piVar4;
  code **ppcVar5;
  int *piVar6;
  undefined uVar7;
  undefined2 uVar8;
  int iVar9;
  code *pcVar10;
  int iVar11;
  code *pcVar12;
  int iVar13;
  code *pcVar14;
  bool bVar15;
  bool bVar16;
  char in_shift_carry;
  int *piVar17;
  
  ppcVar2 = (code **)((int)param_1 - (int)param_2);
  bVar15 = ppcVar2 == (code **)0x0;
  if (param_2 <= param_1) {
    bVar15 = param_3 == ppcVar2;
  }
  if ((param_2 > param_1 || param_3 < ppcVar2) || bVar15) {
    ppcVar5 = param_3 + -8;
    if (FUN_0000001c + 3 < param_3) {
      do {
        pcVar10 = param_2[1];
        pcVar12 = param_2[2];
        pcVar14 = param_2[3];
        bVar15 = FUN_0000001c + 3 < ppcVar5;
        ppcVar5 = ppcVar5 + -8;
        *param_1 = *param_2;
        param_1[1] = pcVar10;
        param_1[2] = pcVar12;
        param_1[3] = pcVar14;
        ppcVar2 = (code **)param_2[4];
        pcVar10 = param_2[5];
        pcVar12 = param_2[6];
        pcVar14 = param_2[7];
        param_2 = param_2 + 8;
        *(code ***)(param_1 + 4) = ppcVar2;
        param_1[5] = pcVar10;
        param_1[6] = pcVar12;
        param_1[7] = pcVar14;
        param_1 = param_1 + 8;
      } while (bVar15);
    }
    if (in_shift_carry != '\0') {
      ppcVar2 = (code **)*param_2;
      pcVar10 = param_2[1];
      pcVar12 = param_2[2];
      pcVar14 = param_2[3];
      param_2 = param_2 + 4;
      *(code ***)param_1 = ppcVar2;
      param_1[1] = pcVar10;
      param_1[2] = pcVar12;
      param_1[3] = pcVar14;
      param_1 = param_1 + 4;
    }
    if ((int)ppcVar5 << 0x1c < 0) {
      ppcVar2 = (code **)*param_2;
      pcVar10 = param_2[1];
      param_2 = param_2 + 2;
      *(code ***)param_1 = ppcVar2;
      param_1[1] = pcVar10;
      param_1 = param_1 + 2;
    }
    ppcVar3 = param_2;
    if (in_shift_carry != '\0') {
      ppcVar3 = param_2 + 1;
      ppcVar2 = (code **)*param_2;
    }
    uVar8 = SUB42(ppcVar2,0);
    ppcVar1 = param_1;
    if (in_shift_carry != '\0') {
      ppcVar1 = param_1 + 1;
      *(code ***)param_1 = ppcVar2;
    }
    if (((uint)ppcVar5 & 3) == 0) {
      return CONCAT44(ppcVar1,ppcVar3);
    }
    bVar16 = ((uint)ppcVar5 >> 1 & 1) != 0;
    uVar7 = 0;
    bVar15 = (int)ppcVar5 << 0x1f < 0;
    ppcVar2 = ppcVar3;
    if (bVar16) {
      ppcVar2 = (code **)((int)ppcVar3 + 2);
      uVar8 = *(undefined2 *)ppcVar3;
    }
    ppcVar5 = ppcVar2;
    if (bVar15) {
      ppcVar5 = (code **)((int)ppcVar2 + 1);
      uVar7 = *(undefined *)ppcVar2;
    }
    ppcVar2 = ppcVar1;
    if (bVar16) {
      ppcVar2 = (code **)((int)ppcVar1 + 2);
      *(undefined2 *)ppcVar1 = uVar8;
    }
    ppcVar3 = ppcVar2;
    if (bVar15) {
      ppcVar3 = (code **)((int)ppcVar2 + 1);
      *(undefined *)ppcVar2 = uVar7;
    }
    return CONCAT44(ppcVar3,ppcVar5);
  }
  piVar4 = (int *)((int)param_1 + (int)param_3);
  bVar15 = ((uint)piVar4 & 3) == 0;
  piVar6 = (int *)((int)param_2 + (int)param_3);
  do {
    if (!bVar15) {
      piVar6 = (int *)((int)piVar6 + -1);
      param_3 = (code **)((int)param_3 + -1);
      piVar4 = (int *)((int)piVar4 + -1);
      *(undefined *)piVar4 = *(undefined *)piVar6;
    }
    bVar15 = ((uint)piVar4 & 3) == 0;
  } while (!bVar15);
  ppcVar2 = param_3 + -4;
  if (entry + 7 < param_3) {
    do {
      piVar17 = piVar6 + -1;
      iVar13 = piVar6[-2];
      iVar11 = piVar6[-3];
      piVar6 = piVar6 + -4;
      iVar9 = *piVar6;
      bVar15 = entry + 7 < ppcVar2;
      ppcVar2 = ppcVar2 + -4;
      piVar4[-1] = *piVar17;
      piVar4[-2] = iVar13;
      piVar4[-3] = iVar11;
      piVar4 = piVar4 + -4;
      *piVar4 = iVar9;
    } while (bVar15);
  }
  iVar9 = (int)ppcVar2 << 0x1d;
  bVar15 = iVar9 < 0;
  if (((uint)ppcVar2 >> 3 & 1) != 0) {
    piVar17 = piVar6 + -1;
    piVar6 = piVar6 + -2;
    iVar9 = *piVar6;
    piVar4[-1] = *piVar17;
    piVar4 = piVar4 + -2;
    *piVar4 = iVar9;
  }
  if (bVar15) {
    piVar6 = piVar6 + -1;
    iVar9 = *piVar6;
  }
  uVar8 = (undefined2)iVar9;
  if (bVar15) {
    piVar4 = piVar4 + -1;
    *piVar4 = iVar9;
  }
  if (((uint)ppcVar2 & 3) == 0) {
    return CONCAT44(piVar4,piVar6);
  }
  bVar16 = ((uint)ppcVar2 >> 1 & 1) != 0;
  uVar7 = 0;
  bVar15 = (int)ppcVar2 << 0x1f < 0;
  if (bVar16) {
    piVar6 = (int *)((int)piVar6 + -2);
    uVar8 = *(undefined2 *)piVar6;
  }
  if (bVar15) {
    uVar7 = *(undefined *)((int)piVar6 + -1);
  }
  if (bVar16) {
    piVar4 = (int *)((int)piVar4 + -2);
    *(undefined2 *)piVar4 = uVar8;
  }
  if (bVar15) {
    *(undefined *)((int)piVar4 + -1) = uVar7;
  }
  return CONCAT44(piVar4,piVar6);
}



// WARNING: Removing unreachable block (ram,0x00000600)
// WARNING: Removing unreachable block (ram,0x00000604)

uint * FUN_000005bc(uint *param_1,uint param_2,uint param_3)

{
  undefined uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  
  param_3 = param_3 & 0xff;
  uVar5 = param_3 | param_3 << 8;
  uVar6 = uVar5 | uVar5 << 0x10;
  uVar1 = (undefined)param_3;
  if (param_2 < 4) {
    puVar3 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar3 = (uint *)((int)param_1 + 1);
      *(undefined *)param_1 = uVar1;
    }
    return puVar3;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar7 = 4 - ((uint)param_1 & 3);
    puVar3 = param_1;
    if (iVar7 != 2) {
      puVar3 = (uint *)((int)param_1 + 1);
      *(undefined *)param_1 = uVar1;
    }
    param_1 = puVar3;
    if (1 < iVar7) {
      param_1 = (uint *)((int)puVar3 + 2);
      *(short *)puVar3 = (short)uVar5;
    }
    param_2 = param_2 - iVar7;
  }
  bVar8 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar8) {
      *param_1 = uVar6;
      param_1[1] = uVar6;
      param_1[2] = uVar6;
      param_1[3] = uVar6;
      param_1[4] = uVar6;
      param_1[5] = uVar6;
      param_1[6] = uVar6;
      param_1[7] = uVar6;
      param_1 = param_1 + 8;
      bVar8 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar8);
  if ((param_2 >> 4 & 1) != 0) {
    *param_1 = uVar6;
    param_1[1] = uVar6;
    param_1[2] = uVar6;
    param_1[3] = uVar6;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = uVar6;
    param_1[1] = uVar6;
    param_1 = param_1 + 2;
  }
  uVar4 = param_2 << 0x1e;
  puVar3 = param_1;
  if (((param_2 << 0x1c) >> 0x1e & 1) != 0) {
    puVar3 = param_1 + 1;
    *param_1 = uVar6;
  }
  if (uVar4 != 0) {
    puVar2 = puVar3;
    if ((int)uVar4 < 0) {
      puVar2 = (uint *)((int)puVar3 + 2);
      *(short *)puVar3 = (short)uVar5;
    }
    puVar3 = puVar2;
    if ((uVar4 & 0x40000000) != 0) {
      puVar3 = (uint *)((int)puVar2 + 1);
      *(undefined *)puVar2 = uVar1;
    }
    return puVar3;
  }
  return puVar3;
}



undefined4 * FUN_000005cc(undefined4 *param_1,uint param_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  char in_shift_carry;
  
  if (param_2 < 4) {
    if (in_shift_carry != '\0') {
      puVar1 = (undefined *)((int)param_1 + 1);
      *(undefined *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar1 = 0;
    }
    puVar3 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar3 = (undefined4 *)((int)param_1 + 1);
      *(undefined *)param_1 = 0;
    }
    return puVar3;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar5 = 4 - ((uint)param_1 & 3);
    puVar3 = param_1;
    if (iVar5 != 2) {
      puVar3 = (undefined4 *)((int)param_1 + 1);
      *(undefined *)param_1 = 0;
    }
    param_1 = puVar3;
    if (1 < iVar5) {
      param_1 = (undefined4 *)((int)puVar3 + 2);
      *(undefined2 *)puVar3 = 0;
    }
    param_2 = param_2 - iVar5;
  }
  bVar6 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar6) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar6 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar6);
  if ((param_2 >> 4 & 1) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar4 = param_2 << 0x1e;
  puVar3 = param_1;
  if (((param_2 << 0x1c) >> 0x1e & 1) != 0) {
    puVar3 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar4 != 0) {
    puVar2 = puVar3;
    if ((int)uVar4 < 0) {
      puVar2 = (undefined4 *)((int)puVar3 + 2);
      *(undefined2 *)puVar3 = 0;
    }
    puVar3 = puVar2;
    if ((uVar4 & 0x40000000) != 0) {
      puVar3 = (undefined4 *)((int)puVar2 + 1);
      *(undefined *)puVar2 = 0;
    }
    return puVar3;
  }
  return puVar3;
}



undefined4 * FUN_00000610(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  bool bVar4;
  
  bVar4 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar4) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar4 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar4);
  if ((param_2 >> 4 & 1) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar3 = param_2 << 0x1e;
  puVar2 = param_1;
  if (((param_2 << 0x1c) >> 0x1e & 1) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar3 != 0) {
    puVar1 = puVar2;
    if ((int)uVar3 < 0) {
      puVar1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = 0;
    }
    puVar2 = puVar1;
    if ((uVar3 & 0x40000000) != 0) {
      puVar2 = (undefined4 *)((int)puVar1 + 1);
      *(undefined *)puVar1 = 0;
    }
    return puVar2;
  }
  return puVar2;
}



int FUN_00000660(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  while( true ) {
    uVar4 = *param_1;
    uVar5 = *param_2;
    if (uVar4 != uVar5) break;
    if ((uVar4 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) {
      return 0;
    }
    puVar1 = param_1 + 2;
    uVar4 = param_1[1];
    puVar3 = param_2 + 2;
    uVar5 = param_2[1];
    if (uVar4 != uVar5) break;
    if ((uVar4 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) {
      return 0;
    }
    param_1 = param_1 + 3;
    uVar4 = *puVar1;
    param_2 = param_2 + 3;
    uVar5 = *puVar3;
    if (uVar4 != uVar5) break;
    if ((uVar4 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) {
      return 0;
    }
  }
  uVar2 = uVar4 - uVar5;
  uVar2 = count_leading_zeroes
                    (uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                     uVar2 >> 0x18);
  uVar2 = uVar2 & 0x18;
  uVar6 = 0x1010101 >> 0x20 - uVar2;
  if ((uVar4 - uVar6 & ~uVar4 & uVar6 << 7) != 0) {
    return 0;
  }
  return (uVar4 >> uVar2 & 0xff) - (uVar5 >> uVar2 & 0xff);
}



undefined * FUN_000006e0(void)

{
  return &DAT_00096028;
}



undefined * FUN_000006e8(void)

{
  return &DAT_0009602c;
}



undefined * FUN_000006f0(void)

{
  return &DAT_00096030;
}



undefined4 FUN_00000700(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint local_10;
  
  local_10 = param_4;
  iVar1 = FUN_000007f4(0,&local_10,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_0000a850();
  return 1;
}



void FUN_00000728(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined8 uVar5;
  uint local_18;
  
  local_18 = param_4;
  uVar5 = FUN_000007e0(param_1,param_2);
  uVar4 = (uint)((ulonglong)uVar5 >> 0x20);
  iVar1 = FUN_0000a804();
  if ((uint)uVar5 < uVar4 + iVar1) {
    iVar2 = FUN_000007f4(0,&local_18,iVar1);
    if (iVar2 == 0) {
      FUN_000007a2(0);
    }
    if (local_18 != (uint)uVar5) {
      uVar4 = local_18;
    }
    uVar5 = CONCAT44(uVar4,local_18 + iVar2);
  }
  iVar2 = (int)((ulonglong)uVar5 >> 0x20);
  piVar3 = (int *)FUN_000006e0();
  *piVar3 = iVar2;
  FUN_0000a824();
  if ((int)uVar5 == (iVar1 + 7U & 0xfffffff8) + iVar2) {
    return;
  }
  FUN_0000a850();
  return;
}



void thunk_FUN_0000082c(void)

{
  undefined4 *puVar1;
  code *pcVar2;
  
  puVar1 = FUN_00000904();
  pcVar2 = (code *)puVar1[4];
  if (pcVar2 == (code *)0x0) {
    (*(code *)puVar1[2])();
  }
  else {
    puVar1[4] = 0;
    (*pcVar2)();
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_000007a2(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00000894(param_1);
  if (iVar1 != 0) {
                    // WARNING: Subroutine does not return
    thunk_FUN_00000060();
  }
  return;
}



undefined4 FUN_000007b0(void)

{
  FUN_00000862("SIGPVFN: Pure virtual fn called",(char *)0x0);
  return 1;
}



void FUN_000007e0(int param_1,uint param_2)

{
  if (param_1 + 0x1000U <= param_2) {
    DAT_000934d4 = param_1 + 0x1000U;
    return;
  }
  DAT_000934d4 = param_2;
  return;
}



int FUN_000007f4(int param_1,uint *param_2,int param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined auStack4108 [4096];
  
  puVar2 = (undefined *)(param_3 + DAT_000934d4);
  if (puVar2 <= auStack4108) {
    puVar1 = puVar2 + 0x1000;
    if (puVar2 + (int)(auStack4108 + -(int)puVar2) / 2 < puVar2 + 0x1000) {
      puVar1 = puVar2 + (int)(auStack4108 + -(int)puVar2) / 2;
    }
    *param_2 = DAT_000934d4;
    param_1 = ((uint)(puVar1 + 7) & 0xfffffff8) - DAT_000934d4;
    DAT_000934d4 = (uint)(puVar1 + 7) & 0xfffffff8;
  }
  return param_1;
}



void FUN_0000082c(void)

{
  undefined4 *puVar1;
  code *pcVar2;
  
  puVar1 = FUN_00000904();
  pcVar2 = (code *)puVar1[4];
  if (pcVar2 == (code *)0x0) {
    (*(code *)puVar1[2])();
  }
  else {
    puVar1[4] = 0;
    (*pcVar2)();
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 FUN_00000846(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000006e0();
  return *puVar1;
}



void FUN_00000856(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0000003c(param_1,param_2);
  pcVar2 = (char *)((ulonglong)uVar3 >> 0x20);
  pcVar1 = (char *)uVar3;
  while ((FUN_0000a988(), pcVar2 != (char *)0x0 && (*pcVar2 != '\0'))) {
    pcVar2 = pcVar2 + 1;
  }
  while ((pcVar1 != (char *)0x0 && (*pcVar1 != '\0'))) {
    pcVar1 = pcVar1 + 1;
    FUN_0000a988();
  }
  FUN_0000a988();
  return;
}



void FUN_00000862(char *param_1,char *param_2)

{
  while ((FUN_0000a988(), param_1 != (char *)0x0 && (*param_1 != '\0'))) {
    param_1 = param_1 + 1;
  }
  while ((param_2 != (char *)0x0 && (*param_2 != '\0'))) {
    param_2 = param_2 + 1;
    FUN_0000a988();
  }
  FUN_0000a988();
  return;
}



undefined4 FUN_00000894(int param_1)

{
  char *pcVar1;
  
  if (param_1 == 1) {
    pcVar1 = ": Heap memory corrupted";
  }
  else {
    pcVar1 = (char *)0x0;
  }
  FUN_00000862("SIGRTMEM: Out of heap memory",pcVar1);
  return 1;
}



void FUN_000008e4(int param_1,int param_2,int param_3,undefined *param_4)

{
  bool bVar1;
  
  param_1 = param_1 - param_3;
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    (*(code *)param_4)(param_1);
    param_1 = param_1 - param_3;
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x00000934)

undefined4 * FUN_00000904(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)FUN_00000954();
  puVar2 = (undefined4 *)*puVar1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)FUN_00000154(0x20);
    if (puVar2 == (undefined4 *)0x0) {
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    *(undefined4 **)puVar1 = puVar2;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0x901;
    *(undefined *)(puVar2 + 3) = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
  }
  return puVar2;
}



undefined * FUN_00000954(void)

{
  return &DAT_00096034;
}



void FUN_0000095c(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)FUN_00000154(0x88);
  if (puVar1 != (undefined *)0x0) {
    *puVar1 = 0;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_00000998(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = _DAT_6194d000 >> 0x1c;
  uVar3 = (_DAT_6194d000 << 4) >> 0x14;
  if (uVar4 == 0) {
    if (6 < uVar3) {
      return 0;
    }
    puVar1 = &DAT_0009135c;
  }
  else {
    if (uVar4 == 1) {
      uVar2 = 0;
      if (uVar3 == 0) {
        uVar2 = _DAT_00091358;
      }
      return uVar2;
    }
    if (uVar4 != 2) {
      return 0;
    }
    if (7 < uVar3) {
      return 0;
    }
    puVar1 = &DAT_00091378;
  }
  return *(undefined4 *)(puVar1 + uVar3 * 4);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_000009e8(void)

{
  return _DAT_6194d000 & 0xff | (_DAT_6194d000 & 0xff00) << 8;
}



uint FUN_000009fc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined *extraout_r1;
  undefined *puVar2;
  uint uVar3;
  bool bVar4;
  undefined8 uVar5;
  
  uVar3 = *(uint *)(**(int **)(DAT_0009157c + 0x10) + DAT_0009158c * 0x28) / 1000;
  if (DAT_00091532 == '\0') {
    return uVar3;
  }
  if (DAT_00091532 == '\x03') {
    uVar1 = FUN_0000dc54();
    bVar4 = uVar1 != 1;
    if (!bVar4) {
      uVar1 = (uint)DAT_00091530;
    }
    if ((bVar4 || uVar1 != 1) || (uVar1 = FUN_000044a4(), puVar2 = extraout_r1, uVar1 == 0)) {
      thunk_FUN_0000b46c();
    }
    else {
      do {
        uVar5 = FUN_0000223c(DAT_00091538,puVar2);
        puVar2 = (undefined *)uVar5;
      } while ((int)((ulonglong)uVar5 >> 0x20) == 0);
      do {
        uVar1 = FUN_000041f8();
      } while ((uVar1 & 0x10000) == 0);
      DAT_00095614 = DAT_00095614 + 1;
      FUN_0000b3cc();
      FUN_00000f94(DAT_00091534);
      param_4 = 0;
      param_3 = 0;
      FUN_000065ec(0x188,3,0,0,0);
    }
    DAT_00091532 = 0;
    FUN_00000d44((int)&PTR_s__clk_bimc_0009153c,uVar3,param_3,param_4);
    return uVar3;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



uint FUN_00000aa8(uint param_1,undefined *param_2,undefined **param_3,uint param_4)

{
  undefined *extraout_r1;
  undefined *puVar1;
  undefined *extraout_r1_00;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = 0;
  if (DAT_00091532 == 1) {
    if ((DAT_00091530 == '\x01') &&
       (uVar2 = FUN_000044a4(), param_2 = extraout_r1, puVar1 = extraout_r1, uVar2 != 0)) {
      do {
        uVar3 = FUN_0000223c(DAT_00091538,puVar1);
        puVar1 = (undefined *)uVar3;
      } while ((int)((ulonglong)uVar3 >> 0x20) == 1);
      do {
        uVar2 = FUN_000041f8();
      } while ((uVar2 & 1) == 0);
      FUN_00000f94(DAT_00091534);
      FUN_00000f94(DAT_0009157c);
      if (DAT_0009152c == 0) {
        FUN_00002ba0(DAT_0009151c,(undefined **)**(undefined ***)(DAT_0009151c + 0x10),param_3,
                     param_4);
      }
      param_4 = 0;
      param_3 = (undefined **)0x0;
      FUN_000065ec(0x187,10,0,0,0);
      param_2 = extraout_r1_00;
    }
    DAT_00091532 = 2;
    uVar3 = FUN_00000b44(param_1,param_2,param_3,param_4);
    uVar2 = FUN_000009fc((int)((ulonglong)uVar3 >> 0x20),(int)uVar3,param_3,param_4);
  }
  else {
    if (DAT_00091532 == 2) {
      FUN_00000b44(param_1,param_2,param_3,param_4);
    }
    else {
      if (DAT_00091532 == 3) {
        uVar2 = FUN_000009fc((uint)DAT_00091532,param_2,param_3,param_4);
      }
    }
  }
  return uVar2;
}



void FUN_00000b44(uint param_1,undefined4 param_2,undefined **param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  if (DAT_00091532 != '\x02') {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  DAT_0009158c = DAT_00091580;
  iVar3 = *(int *)DAT_0009157c[4];
  uVar2 = DAT_00091580;
  if (DAT_00091580 <= DAT_00091584) {
    do {
      uVar1 = FUN_00002188(iVar3 + uVar2 * 0x28);
      param_2 = extraout_r1;
      if ((uVar1 != 0) && (DAT_0009158c = uVar2, param_1 <= *(uint *)(iVar3 + uVar2 * 0x28) / 1000))
      break;
      uVar2 = uVar2 + 1;
    } while (uVar2 <= DAT_00091584);
  }
  FUN_000012a0(DAT_00091534,param_2,param_3,param_4);
  uVar2 = FUN_0000dc54();
  bVar4 = uVar2 == 1;
  if (bVar4) {
    uVar2 = (uint)DAT_00091530;
  }
  if ((bVar4 && uVar2 == 1) && (uVar2 = FUN_000044a4(), uVar2 != 0)) {
    FUN_000012a0(DAT_0009157c,extraout_r1_00,param_3,param_4);
    FUN_000013b0(DAT_00091538,1,param_3);
    DAT_00091532 = 3;
    FUN_000065ec(0x188,9,0,0,0);
    return;
  }
  FUN_00000f94(DAT_00091534);
  FUN_000012a0(DAT_0009157c,extraout_r1_01,param_3,param_4);
  thunk_FUN_0000b46c();
  DAT_00091532 = 0;
  return;
}



void FUN_00000c1c(void)

{
  uint uVar1;
  uint extraout_r1;
  undefined4 uVar2;
  uint in_r3;
  bool bVar3;
  
  if (DAT_00091532 == '\0') {
    uVar2 = 0xfa0a1f00;
    uVar1 = *(int *)(*(int *)DAT_0009157c[4] + DAT_00091588 * 0x28) + 0xfa0a1f00;
    if (999 < uVar1) {
      FUN_00000d44((int)&PTR_s__clk_bimc_0009153c,100000,0xfa0a1f00,in_r3);
      uVar1 = extraout_r1;
    }
    FUN_000012a0(DAT_00091534,uVar1,uVar2,in_r3);
    uVar1 = FUN_0000dc54();
    bVar3 = uVar1 != 1;
    if (!bVar3) {
      uVar1 = (uint)DAT_00091530;
    }
    if ((bVar3 || uVar1 != 1) || (uVar1 = FUN_000044a4(), uVar1 == 0)) {
      FUN_00000f94(DAT_00091534);
      thunk_FUN_0000b33c();
      FUN_00000f94(DAT_0009157c);
      DAT_00091532 = 2;
    }
    else {
      if (DAT_00091528 == 0) {
        DAT_0009152c = DAT_00091528;
        FUN_00002ba0(DAT_0009151c,(undefined **)(**(int **)(DAT_0009151c + 0x10) + 0x28),uVar2,in_r3
                    );
      }
      FUN_0000b31c();
      DAT_00095610 = DAT_00095610 + 1;
      FUN_00001088(DAT_00091538);
      FUN_000065ec(0x187,8,0,0,0);
      DAT_00091532 = 1;
    }
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



uint FUN_00000ce0(int param_1,uint param_2,undefined **param_3)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 extraout_r1;
  undefined *extraout_r1_00;
  undefined **ppuVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  
  puVar2 = (undefined *)(uint)DAT_00091532;
  if (((DAT_00091532 == 0) && (ppuVar3 = param_3, param_2 != 0)) ||
     (ppuVar3 = (undefined **)(uint)DAT_00091738, DAT_00091738 == 0)) {
    uVar1 = FUN_00000d44(param_1,param_2,ppuVar3,param_1);
    return uVar1;
  }
  puVar4 = &DAT_00095610;
  if (param_2 == 0) {
    if (DAT_00091532 == 0) {
      DAT_00095618 = DAT_00095618 + 1;
    }
    if (DAT_00091532 == 0) {
      FUN_00000c1c();
    }
    else {
      if (DAT_00091532 == 1) {
        if ((DAT_00091530 == '\x01') &&
           (uVar1 = FUN_000044a4(), puVar2 = extraout_r1_00, uVar1 != 0)) {
          do {
            uVar5 = FUN_0000223c(DAT_00091538,puVar2);
            puVar2 = (undefined *)uVar5;
          } while ((int)((ulonglong)uVar5 >> 0x20) == 1);
          do {
            uVar1 = FUN_000041f8();
          } while ((uVar1 & 1) == 0);
          FUN_00000f94(DAT_00091534);
          FUN_00000f94(DAT_0009157c);
          if (DAT_0009152c == 0) {
            FUN_00002ba0(DAT_0009151c,(undefined **)**(undefined ***)(DAT_0009151c + 0x10),ppuVar3,
                         (uint)puVar4);
          }
          FUN_000065ec(0x187,10,0,0,0);
        }
        DAT_00091532 = 2;
      }
      else {
        if (DAT_00091532 == 3) {
          FUN_000009fc((uint)DAT_00091532,puVar2,ppuVar3,(uint)&DAT_00095610);
          FUN_00000c1c();
        }
      }
    }
    return 0;
  }
  if (DAT_00091532 == 2) {
    puVar2 = DAT_0009561c + 1;
    DAT_0009561c = puVar2;
  }
  uVar1 = FUN_00000aa8(param_2,puVar2,ppuVar3,(uint)&DAT_00095610);
  if ((uVar1 | (uint)param_3) != 0) {
    return 0;
  }
  uVar1 = FUN_000009fc(0,extraout_r1,ppuVar3,(uint)puVar4);
  return uVar1;
}



uint FUN_00000d44(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  puVar1 = FUN_00001620();
  iVar7 = **(int **)(*(int *)(param_1 + 0x40) + 0x10);
  uVar2 = *(uint *)(iVar7 + *(int *)(param_1 + 0x4c) * 0x28) / 1000;
  uVar5 = *(uint *)(param_1 + 0x44);
  uVar6 = uVar5;
  if (uVar5 <= *(uint *)(param_1 + 0x48)) {
    do {
      uVar3 = FUN_00002188(iVar7 + uVar5 * 0x28);
      if ((uVar3 != 0) && (uVar6 = uVar5, param_2 <= *(uint *)(iVar7 + uVar5 * 0x28) / 1000)) break;
      uVar5 = uVar5 + 1;
    } while (uVar5 <= *(uint *)(param_1 + 0x48));
  }
  uVar5 = *(uint *)(iVar7 + uVar6 * 0x28) / 1000;
  if (uVar5 != uVar2) {
    if (DAT_00091740 == 0) {
      DAT_0009173c = uVar5 >> 1;
      FUN_0000ec02(puVar1[0xdd],DAT_0009173c);
    }
    uVar4 = 0;
    FUN_0000b7a8(uVar2,uVar5,0);
    uVar5 = FUN_00002bcc(param_1,uVar5 * 1000,uVar4,param_4);
    uVar5 = uVar5 / 1000;
    uVar4 = 0;
    FUN_0000b5c0(uVar2,uVar5,0);
    FUN_00002bcc((int)(puVar1 + 0xa6),*(uint *)(**(int **)(puVar1[0xb6] + 0x10) + uVar6 * 0x28),
                 uVar4,param_4);
    FUN_00002bcc((int)(puVar1 + 0x79),*(uint *)(**(int **)(puVar1[0x89] + 0x10) + uVar6 * 0x28),
                 uVar4,param_4);
  }
  return uVar5;
}



undefined4 FUN_00000eb4(uint param_1,uint *param_2,uint param_3)

{
  if (param_2 != (uint *)0x0 && param_3 != 0) {
    param_1 = param_2[1];
  }
  if (((param_2 != (uint *)0x0 && param_3 != 0) && param_1 != 0) && (param_2[3] == 0)) {
    FUN_00003a6c(*param_2);
    param_2[1] = param_3;
    return 0;
  }
  return 0xffffffff;
}



undefined4 FUN_00000edc(int param_1,undefined4 param_2,undefined *param_3)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint local_38;
  uint local_34;
  
  iVar7 = *(int *)(param_1 + 0x40);
  FUN_00003a90(*(int *)(*(int *)(iVar7 + 0x10) + 4),&local_38,param_3);
  if (local_34 < 3) {
    local_34 = 2;
  }
  uVar5 = 0;
  piVar6 = **(int ***)(iVar7 + 0x10);
  *(undefined4 *)(param_1 + 0x4c) = 0x7fffffff;
  uVar4 = 0;
  if (*piVar6 != 0) {
    do {
      piVar2 = piVar6 + uVar5 * 10;
      uVar3 = FUN_00002188((int)piVar2);
      if (uVar3 != 0) {
        uVar3 = piVar2[2];
        if (uVar3 < 2) {
          uVar3 = 2;
        }
        uVar4 = uVar5;
        if (*(int *)(param_1 + 0x4c) == 0x7fffffff) {
          uVar1 = local_38;
          if (local_38 == piVar2[1]) {
            uVar1 = local_34;
          }
          if (local_38 == piVar2[1] && uVar1 == uVar3) {
            *(uint *)(param_1 + 0x4c) = uVar5;
          }
        }
      }
      uVar5 = uVar5 + 1;
    } while (piVar6[uVar5 * 10] != 0);
    if (uVar5 != 0) {
      uVar5 = *(uint *)(param_1 + 0x44);
      if (uVar4 < *(uint *)(param_1 + 0x44)) {
        uVar5 = uVar4;
      }
      *(uint *)(param_1 + 0x44) = uVar5;
      if (*(uint *)(param_1 + 0x48) <= uVar4) {
        uVar4 = *(uint *)(param_1 + 0x48);
      }
      *(uint *)(param_1 + 0x48) = uVar4;
      if ((*(int *)(param_1 + 0x4c) != 0x7fffffff) && (uVar5 <= uVar4)) {
        (*(int **)(iVar7 + 0x10))[2] = **(int **)(iVar7 + 0x10) + *(int *)(param_1 + 0x4c) * 0x28;
        return 0;
      }
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int FUN_00000f94(undefined4 *param_1)

{
  int iVar1;
  int extraout_r1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    return -1;
  }
  FUN_0000d758();
  if (param_1[2] == 1) {
    if (((param_1[3] & 0x100) == 0) && ((*(uint *)(PTR_DAT_00091398 + 0x30) & 0x100) == 0)) {
      FUN_00003ad8(param_1[1],extraout_r1);
      if (((param_1[3] & 1) != 0) || ((*(uint *)(PTR_DAT_00091398 + 0x30) & 1) != 0)) {
        FUN_00006a54(*(undefined4 *)(PTR_DAT_00091398 + 0x2c),1,"%s (Enabled: 0)",*param_1);
      }
      iVar2 = param_1[4];
      if (iVar2 == 0) {
        iVar1 = -1;
LAB_00000ffe:
        FUN_0001a7ec();
        return iVar1;
      }
      iVar3 = -((*(int *)(iVar2 + 0x14) << 0x13) >> 0x1f);
      if (*(int *)(iVar2 + 0xc) == 1) {
        if ((*(uint **)(iVar2 + 0x18) != (uint *)0x0) &&
           (iVar1 = FUN_00001108((int)PTR_DAT_00091398,*(uint **)(iVar2 + 0x18),
                                 (uint)(*(int *)(iVar2 + 0x14) << 0x16) >> 0x1f), iVar1 != 0))
        goto LAB_00000ffe;
        if ((*(uint *)(iVar2 + 0x14) & 0x400) == 0) {
          if (iVar3 == 0) {
            FUN_00002e84((int)PTR_DAT_00091398,(uint *)(iVar2 + 0x10),3,0);
          }
          else {
            FUN_00002e84((int)PTR_DAT_00091398,(uint *)(iVar2 + 0x10),0,iVar3);
          }
        }
      }
      iVar1 = *(int *)(iVar2 + 0xc);
      bVar4 = iVar1 != 0;
      if (bVar4) {
        iVar1 = iVar1 + -1;
      }
      if (bVar4) {
        *(int *)(iVar2 + 0xc) = iVar1;
      }
      goto LAB_0000104a;
    }
  }
  else {
LAB_0000104a:
    if (param_1[2] == 0) goto LAB_00001054;
  }
  param_1[2] = param_1[2] + -1;
LAB_00001054:
  iVar2 = FUN_0000428a(param_1[1]);
  FUN_000065ec(0x182,3,iVar2,0,param_1[2]);
  FUN_0001a7ec();
  return 0;
}



undefined4 FUN_00001088(undefined4 *param_1)

{
  int iVar1;
  int extraout_r1;
  bool bVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_0000d758();
    if (((((uint)param_1[2] < 2) && ((param_1[4] & 0x100) == 0)) &&
        ((*(uint *)(PTR_DAT_00091398 + 0x30) & 0x400) == 0)) && (*(char *)(param_1 + 3) != '\0')) {
      FUN_00003aec(param_1[1],extraout_r1);
      *(undefined *)(param_1 + 3) = 0;
      if (((param_1[4] & 1) != 0) || ((*(uint *)(PTR_DAT_00091398 + 0x30) & 0x20) != 0)) {
        FUN_00006a54(*(undefined4 *)(PTR_DAT_00091398 + 0x2c),1,"%s (Enabled: 0)",*param_1);
      }
    }
    iVar1 = param_1[2];
    bVar2 = iVar1 != 0;
    if (bVar2) {
      iVar1 = iVar1 + -1;
    }
    if (bVar2) {
      param_1[2] = iVar1;
    }
    FUN_0001a7ec();
    return 0;
  }
  return 0xffffffff;
}



undefined4 FUN_00001108(int param_1,uint *param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_3 == 0) {
    if ((((param_2[3] == 0) || (uVar1 = param_2[3] - 1, param_2[3] = uVar1, uVar1 == 0)) &&
        ((param_2[6] & 0x100) == 0)) && ((*(uint *)(param_1 + 0x30) & 0x200) == 0)) {
      uVar1 = param_2[2];
      if (param_2[4] == 0) {
        if (uVar1 == 0) {
          if ((*(uint *)(param_2[1] + 0x2c) & 1) == 0) {
            FUN_00003b00(*param_2);
          }
          else {
            FUN_00003b24(*param_2);
          }
        }
        else {
          FUN_0000ec02(uVar1,0);
        }
        if (((param_2[6] & 1) != 0) || ((*(uint *)(param_1 + 0x30) & 0x10) != 0)) {
          FUN_00006a54(*(undefined4 *)(param_1 + 0x2c),1,"source_%d (Enabled: 0)",*param_2);
        }
        FUN_000065ec(0x184,*param_2,0,0,0);
        FUN_00002e84(param_1,param_2 + 5,3,0);
      }
      else {
        if (uVar1 != 0) {
          FUN_0000ec02(uVar1,1);
        }
      }
      if ((uint *)param_2[7] != (uint *)0x0) {
        FUN_00001108(param_1,(uint *)param_2[7],0);
      }
    }
  }
  else {
    if (((param_2[4] == 0) || (uVar1 = param_2[4] - 1, param_2[4] = uVar1, uVar1 == 0)) &&
       (((param_2[6] & 0x100) == 0 && ((*(uint *)(param_1 + 0x30) & 0x200) == 0)))) {
      if (param_2[3] == 0) {
        if (param_2[2] == 0) {
          if ((*(uint *)(param_2[1] + 0x2c) & 1) == 0) {
            FUN_00003b00(*param_2);
          }
          else {
            FUN_00003b24(*param_2);
          }
        }
        else {
          FUN_0000ec02(param_2[2],0);
        }
        if (((param_2[6] & 1) != 0) || ((*(uint *)(param_1 + 0x30) & 0x10) != 0)) {
          FUN_00006a54(*(undefined4 *)(param_1 + 0x2c),1,"source_%d (Enabled: 0)",*param_2);
        }
        FUN_000065ec(0x184,*param_2,0,0,0);
        FUN_00002e84(param_1,param_2 + 5,3,0);
      }
      if ((uint *)param_2[7] != (uint *)0x0) {
        FUN_00001108(param_1,(uint *)param_2[7],1);
      }
    }
  }
  return 0;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0000124c(void)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  iVar1 = FUN_0000346c(0x2000145,&DAT_0009139c);
  if (iVar1 != 0) {
    return;
  }
  FUN_000009e8();
  FUN_00000998();
  FUN_00004294(&local_10);
  iVar1 = FUN_000016b4();
  if (iVar1 == 0) {
    FUN_00001a10();
    return;
  }
  return;
}



int FUN_000012a0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined **ppuVar2;
  undefined **extraout_r1;
  undefined **extraout_r1_00;
  undefined *extraout_r1_01;
  undefined *UNRECOVERED_JUMPTABLE;
  undefined *extraout_r1_02;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (param_1 == (undefined4 *)0x0) {
    return -1;
  }
  FUN_0000d758();
  if (param_1[2] != 0) goto LAB_00001376;
  iVar3 = param_1[4];
  if (iVar3 == 0) {
    iVar4 = -1;
    goto LAB_00001312;
  }
  iVar1 = *(int *)(iVar3 + 0x14);
  ppuVar2 = *(undefined ***)(iVar3 + 0xc);
  if (ppuVar2 == (undefined **)0x0) {
    ppuVar2 = *(undefined ***)(iVar3 + 0x18);
    if ((ppuVar2 == (undefined **)0x0) ||
       (iVar4 = FUN_00001420((int)PTR_DAT_00091398,(uint *)ppuVar2,(uint)(iVar1 << 0x16) >> 0x1f,
                             param_4), ppuVar2 = extraout_r1, iVar4 == 0)) {
      if (((*(uint *)(iVar3 + 0x14) & 0x400) == 0) && (*(int *)(iVar3 + 8) != 0)) {
        FUN_00002e84((int)PTR_DAT_00091398,(uint *)(iVar3 + 0x10),
                     *(uint *)(*(int *)(iVar3 + 8) + 0x18),(uint)(iVar1 << 0x13) >> 0x1f);
        ppuVar2 = extraout_r1_00;
      }
      goto LAB_00001306;
    }
  }
  else {
LAB_00001306:
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;
    iVar4 = 0;
  }
  if (iVar4 != 0) {
LAB_00001312:
    FUN_0001a7ec();
    return iVar4;
  }
  FUN_00003b48(param_1[1],ppuVar2);
  if (((param_1[3] & 1) != 0) || ((*(uint *)(PTR_DAT_00091398 + 0x30) & 1) != 0)) {
    FUN_00006a54(*(undefined4 *)(PTR_DAT_00091398 + 0x2c),1,"%s (Enabled: 1)",*param_1);
  }
  uVar5 = 0;
  iVar3 = FUN_00004420(param_1[1],4);
  UNRECOVERED_JUMPTABLE = extraout_r1_01;
  if (iVar3 != 0) {
    while (iVar3 = FUN_0000440c(param_1[1],UNRECOVERED_JUMPTABLE), iVar3 == 0) {
      if (0x95 < uVar5) {
        FUN_000036b8();
        break;
      }
      uVar5 = uVar5 + 1;
      thunk_FUN_0000b1ac(1);
      UNRECOVERED_JUMPTABLE = extraout_r1_02;
    }
  }
LAB_00001376:
  param_1[2] = param_1[2] + 1;
  iVar3 = FUN_0000428a(param_1[1]);
  FUN_000065ec(0x182,3,iVar3,1,param_1[2]);
  FUN_0001a7ec();
  return 0;
}



undefined4 FUN_000013b0(undefined4 *param_1,undefined4 param_2,undefined **param_3)

{
  uint uVar1;
  bool bVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    FUN_0000d758();
    uVar1 = param_1[2];
    bVar2 = uVar1 == 0;
    if (bVar2) {
      uVar1 = (uint)*(byte *)(param_1 + 3);
    }
    if (bVar2 && uVar1 == 0) {
      FUN_00003b5c(param_1[1],param_2,param_3);
      *(undefined *)(param_1 + 3) = 1;
      if (((param_1[4] & 1) != 0) || ((*(uint *)(PTR_DAT_00091398 + 0x30) & 0x20) != 0)) {
        FUN_00006a54(*(undefined4 *)(PTR_DAT_00091398 + 0x2c),1,"%s (Enabled: 1)",*param_1);
      }
    }
    param_1[2] = param_1[2] + 1;
    FUN_0001a7ec();
    return 0;
  }
  return 0xffffffff;
}



undefined4 FUN_00001420(int param_1,uint *param_2,int param_3,undefined4 param_4)

{
  if (param_2 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_3 == 0) {
    if (param_2[3] == 0) {
      if ((uint *)param_2[7] != (uint *)0x0) {
        FUN_00001420(param_1,(uint *)param_2[7],0,param_4);
      }
      if (param_2[4] == 0) {
        FUN_00002e84(param_1,param_2 + 5,*(uint *)(param_2[1] + 0x34),0);
        if (param_2[2] == 0) {
          if ((*(uint *)(param_2[1] + 0x2c) & 1) == 0) {
            FUN_00003b70(*param_2);
          }
          else {
            FUN_00003b94(*param_2);
          }
        }
        else {
          FUN_0000ec02(param_2[2],2);
        }
        if (((param_2[6] & 1) != 0) || ((*(uint *)(param_1 + 0x30) & 0x10) != 0)) {
          FUN_00006a54(*(undefined4 *)(param_1 + 0x2c),1,"source_%d (Enabled: 1)",*param_2);
        }
        FUN_000065ec(0x184,*param_2,1,0,0);
      }
      else {
        if (param_2[2] != 0) {
          FUN_0000ec02(param_2[2],2);
        }
      }
    }
    param_2[3] = param_2[3] + 1;
  }
  else {
    if (param_2[4] == 0) {
      if ((uint *)param_2[7] != (uint *)0x0) {
        FUN_00001420(param_1,(uint *)param_2[7],1,param_4);
      }
      if (param_2[3] == 0) {
        FUN_00002e84(param_1,param_2 + 5,*(uint *)(param_2[1] + 0x34),0);
        if (param_2[2] == 0) {
          if ((*(uint *)(param_2[1] + 0x2c) & 1) == 0) {
            FUN_00003b70(*param_2);
          }
          else {
            FUN_00003b94(*param_2);
          }
        }
        else {
          FUN_0000ec02(param_2[2],1);
        }
        if (((param_2[6] & 1) != 0) || ((*(uint *)(param_1 + 0x30) & 0x10) != 0)) {
          FUN_00006a54(*(undefined4 *)(param_1 + 0x2c),1,"source_%d (Enabled: 1)",*param_2);
        }
        FUN_000065ec(0x184,*param_2,1,0,0);
      }
    }
    param_2[4] = param_2[4] + 1;
  }
  return 0;
}



undefined4 FUN_00001544(int param_1,uint *param_2,undefined *param_3)

{
  uint *puVar1;
  uint uVar2;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  uVar2 = 0;
  if (param_1 == 0) {
    *param_2 = 0;
    return 0xffffffff;
  }
  FUN_0000d758();
  puVar1 = *(uint **)(*(int *)(param_1 + 0x10) + 8);
  if (puVar1 == (uint *)0x0) {
    FUN_00003a90(*(int *)(*(int *)(param_1 + 0x10) + 4),&local_28,param_3);
    if (PTR_DAT_00091398[local_28 + 0x48] != 0xff) {
      uVar2 = *(uint *)(*(int *)(*(int *)(PTR_DAT_00091398 + 100) +
                                (uint)(byte)PTR_DAT_00091398[local_28 + 0x48] * 0x20 + 4) + 0x30);
      if (2 < local_24) {
        uVar2 = uVar2 / local_24 << 1;
      }
      if (1 < local_20) {
        uVar2 = local_20 * uVar2;
      }
      if (1 < local_1c) {
        uVar2 = uVar2 / local_1c;
      }
    }
  }
  else {
    uVar2 = *puVar1;
  }
  FUN_0001a7ec();
  *param_2 = uVar2;
  return 0;
}



undefined4 FUN_000015c0(uint *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(PTR_DAT_00091398 + 0x70) != 0) {
    do {
      iVar1 = FUN_00000660(param_1,*(uint **)(*(int *)(PTR_DAT_00091398 + 0x74) + uVar2 * 0x14));
      if (iVar1 == 0) {
        *param_2 = *(int *)(PTR_DAT_00091398 + 0x74) + uVar2 * 0x14;
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(PTR_DAT_00091398 + 0x70));
  }
  *param_2 = 0;
  return 0xffffffff;
}



undefined * FUN_00001614(void)

{
  return PTR_DAT_00091398;
}



undefined4 * FUN_00001620(void)

{
  return &DAT_000913ac;
}



undefined4 FUN_00001628(uint *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(PTR_DAT_00091398 + 0x78) != 0) {
    do {
      iVar1 = FUN_00000660(param_1,*(uint **)(*(int *)(PTR_DAT_00091398 + 0x7c) + uVar2 * 0x14));
      if (iVar1 == 0) {
        *param_2 = *(int *)(PTR_DAT_00091398 + 0x7c) + uVar2 * 0x14;
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(PTR_DAT_00091398 + 0x78));
  }
  *param_2 = 0;
  return 0xffffffff;
}



int FUN_0000167c(uint *param_1,undefined4 *param_2)

{
  int iVar1;
  uint auStack24 [2];
  undefined4 uStack16;
  
  iVar1 = FUN_000034e4((int *)&DAT_0009139c,param_1,0,auStack24);
  if (iVar1 == 0) {
    *param_2 = uStack16;
    return 0;
  }
  return iVar1;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_000016b4(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined *UNRECOVERED_JUMPTABLE;
  undefined *UNRECOVERED_JUMPTABLE_00;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int local_4c;
  undefined4 *local_48;
  int aiStack68 [5];
  uint auStack48 [2];
  undefined4 uStack40;
  
  local_4c = 0;
  local_48 = (undefined4 *)0x0;
  iVar2 = FUN_0000425c();
  UNRECOVERED_JUMPTABLE_00 = PTR_DAT_00091398;
  *(int *)(PTR_DAT_00091398 + 0x68) = iVar2;
  if (iVar2 == 0) {
LAB_00001798:
    *(undefined4 *)(PTR_DAT_00091398 + 0x70) = 0;
  }
  else {
    if ((int *)(UNRECOVERED_JUMPTABLE_00 + 0x6c) == (int *)0x0) {
LAB_0000177c:
      FUN_000036b8();
      return -1;
    }
    iVar3 = FUN_00000154(iVar2 << 5);
    *(int *)(UNRECOVERED_JUMPTABLE_00 + 0x6c) = iVar3;
    if (*(undefined4 **)(PTR_DAT_00091398 + 0x6c) == (undefined4 *)0x0) goto LAB_0000177c;
    FUN_00000610(*(undefined4 **)(PTR_DAT_00091398 + 0x6c),iVar2 << 5);
    if (*(int *)(PTR_DAT_00091398 + 0x68) == 0) goto LAB_00001798;
    iVar2 = FUN_00004268();
    UNRECOVERED_JUMPTABLE_00 = PTR_DAT_00091398;
    *(int *)(PTR_DAT_00091398 + 0x70) = iVar2;
    if (iVar2 == 0) {
      return -1;
    }
    if ((int *)(UNRECOVERED_JUMPTABLE_00 + 0x74) == (int *)0x0) {
LAB_0000179e:
      FUN_000036b8();
      return -1;
    }
    iVar3 = FUN_00000154(iVar2 * 0x14);
    *(int *)(UNRECOVERED_JUMPTABLE_00 + 0x74) = iVar3;
    if (*(undefined4 **)(PTR_DAT_00091398 + 0x74) == (undefined4 *)0x0) goto LAB_0000179e;
    FUN_00000610(*(undefined4 **)(PTR_DAT_00091398 + 0x74),iVar2 * 0x14);
  }
  iVar2 = FUN_00004274();
  UNRECOVERED_JUMPTABLE_00 = PTR_DAT_00091398;
  *(int *)(PTR_DAT_00091398 + 0x78) = iVar2;
  if (iVar2 == 0) {
LAB_00001754:
    iVar2 = FUN_00002034((int)PTR_DAT_00091398);
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_00004218(0,&local_4c);
    uVar6 = 0;
    uVar7 = 0;
    while (local_4c != 0) {
      if (*(uint *)(PTR_DAT_00091398 + 0x68) <= uVar6) {
        return -1;
      }
      iVar2 = uVar6 * 0x20 + 0x14;
      iVar3 = uVar6 * 0x20 + 4;
      *(uint *)(*(int *)(PTR_DAT_00091398 + 0x6c) + iVar2) =
           *(uint *)(*(int *)(PTR_DAT_00091398 + 0x6c) + iVar2) | 0x200;
      *(int *)(*(int *)(PTR_DAT_00091398 + 0x6c) + iVar3) = local_4c;
      UNRECOVERED_JUMPTABLE_00 = *(undefined **)(PTR_DAT_00091398 + 0x6c);
      *(undefined4 *)(UNRECOVERED_JUMPTABLE_00 + uVar6 * 0x20 + 0x1c) = 0;
      FUN_00003a90(*(int *)(*(int *)(PTR_DAT_00091398 + 0x6c) + iVar3),aiStack68,
                   UNRECOVERED_JUMPTABLE_00);
      if (aiStack68[0] == 0) {
        bVar1 = PTR_DAT_00091398[0x49];
      }
      else {
        UNRECOVERED_JUMPTABLE_00 = PTR_DAT_00091398 + 0x48;
        bVar1 = UNRECOVERED_JUMPTABLE_00[aiStack68[0]];
      }
      if (bVar1 != 0xff) {
        UNRECOVERED_JUMPTABLE_00 = *(undefined **)(PTR_DAT_00091398 + 0x6c);
        *(uint *)(UNRECOVERED_JUMPTABLE_00 + uVar6 * 0x20 + 0x18) =
             *(int *)(PTR_DAT_00091398 + 100) + (uint)bVar1 * 0x20;
      }
      uVar8 = 0;
      puVar4 = (undefined4 *)
               FUN_0000422c(*(int *)(*(int *)(PTR_DAT_00091398 + 0x6c) + iVar3),0,
                            (uint)UNRECOVERED_JUMPTABLE_00);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_000036b8();
      }
      else {
        do {
          if (*(uint *)(PTR_DAT_00091398 + 0x70) <= uVar7) {
            return -1;
          }
          *(undefined4 **)(*(int *)(PTR_DAT_00091398 + 0x74) + uVar7 * 0x14 + 4) = puVar4;
          FUN_000041ec(puVar4,(undefined4 *)(*(int *)(PTR_DAT_00091398 + 0x74) + uVar7 * 0x14));
          if ((*(int *)(*(int *)(PTR_DAT_00091398 + 0x6c) + uVar6 * 0x20) == 0) &&
             (iVar2 = FUN_000034e4((int *)&DAT_0009139c,
                                   *(uint **)(*(int *)(PTR_DAT_00091398 + 0x74) + uVar7 * 0x14),0,
                                   auStack48), iVar2 == 0)) {
            *(undefined4 *)(*(int *)(PTR_DAT_00091398 + 0x6c) + uVar6 * 0x20) = uStack40;
          }
          uVar5 = uVar7 * 0x14 + 0x10;
          uVar8 = uVar8 + 1;
          uVar7 = uVar7 + 1;
          *(int *)(*(int *)(PTR_DAT_00091398 + 0x74) + uVar5) =
               *(int *)(PTR_DAT_00091398 + 0x6c) + uVar6 * 0x20;
          puVar4 = (undefined4 *)
                   FUN_0000422c(*(int *)(*(int *)(PTR_DAT_00091398 + 0x6c) + iVar3),uVar8,uVar5);
        } while (puVar4 != (undefined4 *)0x0);
      }
      FUN_00004218(local_4c,&local_4c);
      uVar6 = uVar6 + 1;
    }
    if (*(uint *)(PTR_DAT_00091398 + 0x68) == uVar6) {
      FUN_00004248(0,&local_48);
      uVar6 = 0;
      while (local_48 != (undefined4 *)0x0) {
        if (*(uint *)(PTR_DAT_00091398 + 0x78) <= uVar6) {
          return -1;
        }
        iVar2 = uVar6 * 0x14 + 4;
        *(undefined4 **)(*(int *)(PTR_DAT_00091398 + 0x7c) + iVar2) = local_48;
        FUN_00004280(local_48,(undefined4 *)(*(int *)(PTR_DAT_00091398 + 0x7c) + uVar6 * 0x14));
        iVar2 = FUN_000044b4(*(int *)(*(int *)(PTR_DAT_00091398 + 0x7c) + iVar2),
                             UNRECOVERED_JUMPTABLE);
        *(undefined *)(*(int *)(PTR_DAT_00091398 + 0x7c) + uVar6 * 0x14 + 0xc) = (char)iVar2;
        FUN_00004248((int)local_48,&local_48);
        uVar6 = uVar6 + 1;
      }
      if (*(uint *)(PTR_DAT_00091398 + 0x78) == uVar6) {
        iVar2 = FUN_00002150((int)PTR_DAT_00091398);
        return iVar2;
      }
    }
    return -1;
  }
  if ((int *)(UNRECOVERED_JUMPTABLE_00 + 0x7c) != (int *)0x0) {
    iVar3 = FUN_00000154(iVar2 * 0x14);
    *(int *)(UNRECOVERED_JUMPTABLE_00 + 0x7c) = iVar3;
    if (*(undefined4 **)(PTR_DAT_00091398 + 0x7c) != (undefined4 *)0x0) {
      FUN_00000610(*(undefined4 **)(PTR_DAT_00091398 + 0x7c),iVar2 * 0x14);
      goto LAB_00001754;
    }
  }
  FUN_000036b8();
  return -1;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_00001a10(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined **extraout_r1_05;
  undefined **ppuVar6;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  undefined4 extraout_r1_10;
  undefined4 extraout_r1_11;
  undefined4 extraout_r1_12;
  undefined4 extraout_r1_13;
  undefined4 extraout_r1_14;
  undefined4 extraout_r1_15;
  undefined4 extraout_r1_16;
  undefined4 extraout_r1_17;
  undefined4 extraout_r1_18;
  undefined4 uVar7;
  undefined4 extraout_r1_19;
  undefined **ppuVar8;
  char *pcVar9;
  bool bVar10;
  uint *apuStack232 [32];
  char *pcStack104;
  char *apcStack100 [7];
  undefined4 auStack72 [4];
  int iStack56;
  
  puVar1 = FUN_00001620();
  puVar2 = FUN_00001614();
  puVar2[0x40] = 0;
  pcVar9 = (char *)0x0;
  ppuVar8 = (undefined **)0x0;
  FUN_000065ec(0x181,0,0,0,0);
  iVar3 = FUN_000015c0((uint *)"gcc_spmi_ser_clk",(int *)&DAT_0009398c);
  if (iVar3 != 0) {
LAB_00001b8a:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  FUN_000012a0(DAT_0009398c,extraout_r1,ppuVar8,pcVar9);
  iVar3 = FUN_000015c0((uint *)"gcc_imem_axi_clk",(int *)&DAT_00093990);
  if (iVar3 != 0) goto LAB_00001b8a;
  FUN_000012a0(DAT_00093990,extraout_r1_00,ppuVar8,pcVar9);
  iVar3 = FUN_000015c0((uint *)"gcc_msg_ram_ahb_clk",(int *)&DAT_00093994);
  if (iVar3 != 0) goto LAB_00001b8a;
  FUN_000012a0(DAT_00093994,extraout_r1_01,ppuVar8,pcVar9);
  puVar1[0x33] = 0;
  puVar1[0x34] = 0x7fffffff;
  puVar1[0x48] = 0;
  puVar1[0x49] = 0x7fffffff;
  puVar1[0x5d] = 0;
  puVar1[0x5e] = 0x7fffffff;
  puVar1[0x75] = 0;
  uVar4 = FUN_00004208();
  bVar10 = uVar4 != DAT_00090518;
  DAT_0009051c = uVar4;
  if (bVar10) {
    puVar1[0x76] = 0x7fffffff;
  }
  else {
    uVar4 = 4;
  }
  if (!bVar10) {
    puVar1[0x76] = uVar4;
  }
  puVar1[0x8a] = 0;
  puVar1[0x8b] = 0x7fffffff;
  puVar1[0x9f] = 0;
  puVar1[0xa0] = 0x7fffffff;
  puVar1[0xb7] = 0;
  puVar1[0xb8] = 0x7fffffff;
  FUN_00002f88((int)puVar2,1);
  iVar3 = FUN_000015c0((uint *)"gcc_rpm_proc_fclk",puVar1 + 0x32);
  if (iVar3 != 0) {
    return iVar3;
  }
  *(uint *)(*(int *)(puVar1[0x32] + 0x10) + 0x14) =
       *(uint *)(*(int *)(puVar1[0x32] + 0x10) + 0x14) | 0x400;
  iVar3 = FUN_000015c0((uint *)"gcc_sys_noc_axi_clk",puVar1 + 0x47);
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar3 = FUN_000015c0((uint *)"gcc_pcnoc_ahb_clk",puVar1 + 0x5c);
  if (iVar3 != 0) {
    return iVar3;
  }
  puVar5 = FUN_00001620();
  *(undefined *)((int)puVar5 + 0x186) = 0;
  *(undefined *)(puVar5 + 0x61) = 1;
  iVar3 = FUN_000015c0((uint *)"gcc_bimc_clk",puVar5 + 0x74);
  if (((iVar3 != 0) || (iVar3 = FUN_000015c0((uint *)"gcc_dehr_clk",puVar5 + 0x62), iVar3 != 0)) ||
     (iVar3 = FUN_00001628((uint *)"VDD_BIMC",puVar5 + 99), iVar3 != 0)) {
    return -1;
  }
  FUN_000013b0((undefined4 *)puVar5[99],1,ppuVar8);
  iVar3 = FUN_000015c0((uint *)"gcc_bimc_gpu_clk",puVar1 + 0x89);
  if (iVar3 != 0) {
    return iVar3;
  }
  puVar5 = FUN_00001620();
  iVar3 = FUN_000015c0((uint *)"gcc_qpic_clk",puVar5 + 0x9e);
  if (((iVar3 != 0) ||
      (iVar3 = FUN_000015c0((uint *)"gcc_qpic_system_clk",puVar5 + 0xa4), iVar3 != 0)) ||
     (iVar3 = FUN_000015c0((uint *)"gcc_qpic_ahb_clk",puVar5 + 0xa5), iVar3 != 0))
  goto LAB_00001b8a;
  *(uint *)(*(int *)(puVar5[0x9e] + 0x10) + 0x14) =
       *(uint *)(*(int *)(puVar5[0x9e] + 0x10) + 0x14) & 0xfffffdff;
  FUN_00002218(puVar5[0x9e],(undefined *)(puVar5 + 0xa3));
  if (*(char *)(puVar5 + 0xa3) != '\0') {
    FUN_000012a0((undefined4 *)puVar5[0x9e],extraout_r1_02,ppuVar8,pcVar9);
    FUN_000012a0((undefined4 *)puVar5[0xa4],extraout_r1_03,ppuVar8,pcVar9);
    FUN_000012a0((undefined4 *)puVar5[0xa5],extraout_r1_04,ppuVar8,pcVar9);
  }
  iVar3 = FUN_000015c0((uint *)"gcc_apss_tcu_async_clk",puVar1 + 0xb6);
  if (iVar3 != 0) {
    return iVar3;
  }
  FUN_00003ab0(8,auStack72);
  ppuVar6 = extraout_r1_05;
  if (iStack56 == 0x36) {
    iVar3 = 0;
    ppuVar6 = (undefined **)**(undefined ***)(puVar1[0x74] + 0x10);
    ppuVar8 = (undefined **)*ppuVar6;
    if (ppuVar8 != (undefined **)0x0) {
      ppuVar8 = (undefined **)0x1fc4ef40;
      do {
        pcVar9 = ppuVar6[iVar3 * 10];
        if (pcVar9 == (char *)0x1fc4ef40) {
          ppuVar8 = (undefined **)0x1ee62800;
          ppuVar6[iVar3 * 10] = (undefined *)0x1ee62800;
          break;
        }
        iVar3 = iVar3 + 1;
        pcVar9 = ppuVar6[iVar3 * 10];
      } while (pcVar9 != (char *)0x0);
    }
  }
  iVar3 = FUN_00000edc((int)(puVar1 + 0x22),ppuVar6,(undefined *)ppuVar8);
  if (iVar3 == 0) {
    FUN_000012a0((undefined4 *)puVar1[0x32],extraout_r1_06,ppuVar8,pcVar9);
    iVar3 = FUN_00000edc((int)(puVar1 + 0x37),extraout_r1_07,(undefined *)ppuVar8);
    if (iVar3 == 0) {
      FUN_000012a0((undefined4 *)puVar1[0x47],extraout_r1_08,ppuVar8,pcVar9);
      iVar3 = FUN_00000edc((int)(puVar1 + 0x4c),extraout_r1_09,(undefined *)ppuVar8);
      if (iVar3 == 0) {
        FUN_000012a0((undefined4 *)puVar1[0x5c],extraout_r1_10,ppuVar8,pcVar9);
        iVar3 = FUN_00000edc((int)(puVar1 + 100),extraout_r1_11,(undefined *)ppuVar8);
        if (iVar3 == 0) {
          FUN_000012a0((undefined4 *)puVar1[0x74],extraout_r1_12,ppuVar8,pcVar9);
          iVar3 = FUN_00000edc((int)(puVar1 + 0x79),extraout_r1_13,(undefined *)ppuVar8);
          if ((iVar3 == 0) &&
             ((FUN_000012a0((undefined4 *)puVar1[0x89],extraout_r1_14,ppuVar8,pcVar9),
              *(char *)(puVar1 + 0xa3) == '\0' ||
              (iVar3 = FUN_00000edc((int)(puVar1 + 0x8e),extraout_r1_15,(undefined *)ppuVar8),
              iVar3 == 0)))) {
            puVar5 = puVar1;
            FUN_0000f038((uint *)"/clk/snoc",&LAB_00002cc4_1,(int)puVar1);
            iVar3 = FUN_00000edc((int)(puVar1 + 0xa6),extraout_r1_16,(undefined *)puVar5);
            if (iVar3 == 0) {
              FUN_000012a0((undefined4 *)puVar1[0xb6],extraout_r1_17,puVar5,pcVar9);
              FUN_000004de(apuStack232,&PTR_s_gcc_qdss_cfg_ahb_clk_0001b240,0x78);
              apuStack232[1] = puVar1 + 0xce;
              apuStack232[3] = puVar1 + 0xcf;
              apuStack232[5] = puVar1 + 0xd0;
              apcStack100[0] = puVar1 + 0xd1;
              apcStack100[2] = puVar1 + 0xd2;
              puVar5 = puVar1 + 0xd3;
              apuStack232[13] = puVar1 + 0xd4;
              apuStack232[15] = puVar1 + 0xd5;
              apuStack232[7] = apcStack100[0];
              apuStack232[17] = puVar1 + 0xd6;
              apuStack232[9] = apcStack100[2];
              apuStack232[19] = puVar1 + 0xd7;
              apuStack232[11] = puVar5;
              apuStack232[21] = puVar1 + 0xd8;
              apuStack232[23] = puVar1 + 0xd9;
              apuStack232[25] = puVar1 + 0xda;
              apuStack232[27] = puVar1 + 0xdb;
              apuStack232[29] = puVar1 + 0xdc;
              apcStack100[1] = "gcc_sys_noc_at_clk";
              pcStack104 = "gcc_qdss_at_clk";
              pcVar9 = "gcc_pcnoc_at_clk";
              apcStack100[3] = "gcc_pcnoc_at_clk";
              *(undefined *)(puVar1 + 0xcd) = 0;
              uVar4 = 0;
              apcStack100[4] = puVar5;
              do {
                iVar3 = FUN_000015c0(apuStack232[uVar4 * 2],(int *)apuStack232[uVar4 * 2 + 1]);
                if (iVar3 != 0) {
                  iVar3 = -1;
                  goto LAB_00001d3e;
                }
                uVar4 = uVar4 + 1;
              } while (uVar4 < 0xf);
              uVar4 = 0;
              uVar7 = extraout_r1_18;
              do {
                FUN_000012a0(*(undefined4 **)apcStack100[uVar4 * 2],uVar7,puVar5,pcVar9);
                uVar4 = uVar4 + 1;
                uVar7 = extraout_r1_19;
              } while (uVar4 < 3);
              *(uint *)(*(int *)(puVar1[0xd4] + 0x10) + 0x14) =
                   *(uint *)(*(int *)(puVar1[0xd4] + 0x10) + 0x14) | 0x400;
              *(uint *)(*(int *)(puVar1[0xd1] + 0x10) + 0x14) =
                   *(uint *)(*(int *)(puVar1[0xd1] + 0x10) + 0x14) | 0x400;
              *(uint *)(*(int *)(puVar1[0xd8] + 0x10) + 0x14) =
                   *(uint *)(*(int *)(puVar1[0xd8] + 0x10) + 0x14) | 0x400;
              *(uint *)(*(int *)(puVar1[0xd5] + 0x10) + 0x14) =
                   *(uint *)(*(int *)(puVar1[0xd5] + 0x10) + 0x14) | 0x400;
              goto LAB_00001d48;
            }
          }
        }
      }
    }
  }
LAB_00001d3e:
  if (iVar3 != 0) {
    return iVar3;
  }
LAB_00001d48:
  FUN_00001f44();
  DAT_00090528 = FUN_00016ac0(0x306b6c63,3);
  FUN_00016a82(DAT_00090528,0,puVar1[2],(uint)pcVar9);
  FUN_00016a82(DAT_00090528,1,puVar1[0xbb],(uint)pcVar9);
  FUN_00016a82(DAT_00090528,2,puVar1[0x12],(uint)pcVar9);
  DAT_0009052c = FUN_00016ac0(0x316b6c63,2);
  FUN_00016a82(DAT_0009052c,0,puVar1[0x4c],(uint)pcVar9);
  FUN_00016a82(DAT_0009052c,1,puVar1[0x37],(uint)pcVar9);
  DAT_00090530 = FUN_00016b08(0x326b6c63,1);
  FUN_00016a82(DAT_00090530,0,puVar1[100],(uint)pcVar9);
  DAT_00090534 = FUN_00016ac0(0x63697071,1);
  FUN_00016a82(DAT_00090534,0,puVar1[0x8e],(uint)pcVar9);
  FUN_00002f48((int)puVar2,1);
  return 0;
}



undefined4 FUN_00001f44(void)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint local_28;
  char local_24 [8];
  
  local_24[0] = '\0';
  puVar1 = FUN_00001614();
  local_28 = 1;
  FUN_0000e51c((undefined *)&PTR_s__node_xo_cxo_000913d4,(int)&local_28,(undefined *)0x0,
               (undefined *)0x0);
  local_28 = (uint)(byte)puVar1[0x40];
  if (puVar1[0x40] != 0) {
    local_28 = 1;
  }
  FUN_0000e51c((undefined *)&PTR_s__node_clk_dcvs_ena_00091414,(int)&local_28,(undefined *)0x0,
               (undefined *)0x0);
  uVar3 = 0;
  do {
    local_24[0] = '\0';
    puVar1 = (&PTR_PTR_s__clk_cpu_00091724)[uVar3];
    FUN_000021f4(*(int *)(puVar1 + 0x40),local_24);
    *(uint *)(puVar1 + 8) =
         *(uint *)(**(int **)(*(int *)(puVar1 + 0x40) + 0x10) + *(int *)(puVar1 + 0x48) * 0x28) /
         1000;
    if (local_24[0] != '\0') {
      local_28 = *(uint *)(**(int **)(*(int *)(puVar1 + 0x40) + 0x10) +
                          *(int *)(puVar1 + 0x4c) * 0x28) / 1000;
    }
    FUN_0000e51c(puVar1 + 0x20,(int)&local_28,(undefined *)0x0,(undefined *)0x0);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 5);
  local_28 = 0;
  FUN_0000e51c((undefined *)&PTR_s__node_clk_qdss_000916b8,(int)&local_28,(undefined *)0x0,
               (undefined *)0x0);
  iVar2 = FUN_00014250((uint *)"vddcx");
  FUN_00014d30(iVar2,0,(int)&LAB_00002920_1,0);
  FUN_00014d30(iVar2,1,(int)&LAB_000028e8_1,0);
  return 0;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_00002034(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  bool bVar8;
  int *local_1c [2];
  
  iVar2 = FUN_0000167c((uint *)"ClockSources",local_1c);
  piVar7 = local_1c[0];
  if (iVar2 != 0) {
    return iVar2;
  }
  while( true ) {
    iVar2 = *piVar7;
    bVar8 = iVar2 != 0;
    if (bVar8) {
      iVar2 = piVar7[0xc];
    }
    iVar3 = *(int *)(param_1 + 0x60);
    if (!bVar8 || iVar2 == 0) break;
    *(int *)(param_1 + 0x60) = iVar3 + 1;
    piVar7 = piVar7 + 0xe;
  }
  if (iVar3 == 0) {
    return -1;
  }
  if ((undefined4 *)(param_1 + 100) != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)FUN_00000154(iVar3 << 5);
    *(undefined4 **)(undefined4 *)(param_1 + 100) = puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      FUN_00000610(puVar4,iVar3 << 5);
      FUN_000005bc((uint *)(param_1 + 0x48),0x15,0xff);
      uVar6 = *(uint *)(param_1 + 0x60);
      uVar5 = 0;
      if (uVar6 != 0) {
        do {
          *(undefined *)(*local_1c[0] + param_1 + 0x48) = (char)uVar5;
          *(int **)(*(int *)(param_1 + 100) + uVar5 * 0x20 + 4) = local_1c[0];
          iVar2 = uVar5 * 0x20;
          uVar5 = uVar5 + 1;
          *(int *)(*(int *)(param_1 + 100) + iVar2) = *local_1c[0];
          uVar6 = *(uint *)(param_1 + 0x60);
          local_1c[0] = local_1c[0] + 0xe;
        } while (uVar5 < uVar6);
      }
      uVar5 = 0;
      if (uVar6 != 0) {
        do {
          iVar2 = *(int *)(param_1 + 100);
          bVar1 = *(byte *)(*(int *)(*(int *)(iVar2 + uVar5 * 0x20 + 4) + 4) + param_1 + 0x48);
          if (bVar1 != 0xff) {
            *(int *)(iVar2 + uVar5 * 0x20 + 0x1c) = iVar2 + (uint)bVar1 * 0x20;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(param_1 + 0x60));
      }
      return 0;
    }
  }
  FUN_000036b8();
  return -1;
}



undefined4 FUN_00002150(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00014250((uint *)"vddcx");
  *(int *)(param_1 + 0xa8) = iVar1;
  if (iVar1 != -1) {
    uVar2 = FUN_00014504(iVar1,1,0x6a);
    *(undefined4 *)(param_1 + 0xac) = uVar2;
    *(undefined4 *)(param_1 + 0xd8) = 0xffffffff;
    return 0;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



uint FUN_00002188(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    if (*(int *)(param_1 + 0x20) == 0) {
      return 1;
    }
LAB_000021a4:
    iVar1 = FUN_000041d4();
    if (iVar1 != *(int *)(param_1 + 0x20)) goto LAB_000021e0;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x1c) == -0x10000) {
      return 0;
    }
    if (*(int *)(param_1 + 0x20) != 0) goto LAB_000021a4;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 1;
  }
  uVar2 = FUN_000041e0();
  uVar3 = *(uint *)(param_1 + 0x1c);
  uVar4 = uVar3 & 0xff | (uVar3 & 0xff00) << 8;
  if (((uVar3 << 8) >> 0x18 | (uVar3 & 0xff000000) >> 8) <= uVar2) {
    bVar5 = uVar2 < uVar4;
    if (bVar5) {
      uVar4 = 1;
    }
    if (bVar5) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
      return uVar4;
    }
  }
LAB_000021e0:
  *(undefined4 *)(param_1 + 0x1c) = 0xffff0000;
  return 0;
}



undefined4 FUN_000021f4(int param_1,undefined *param_2)

{
  int iVar1;
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_1 != 0) {
    FUN_0000d758();
    iVar1 = FUN_000043f8(*(int *)(param_1 + 4),UNRECOVERED_JUMPTABLE);
    *param_2 = (char)iVar1;
    FUN_0001a7ec();
    return 0;
  }
  *param_2 = 0;
  return 0xffffffff;
}



undefined4 FUN_00002218(int param_1,undefined *param_2)

{
  int iVar1;
  undefined *UNRECOVERED_JUMPTABLE;
  
  if (param_1 != 0) {
    FUN_0000d758();
    iVar1 = FUN_0000440c(*(int *)(param_1 + 4),UNRECOVERED_JUMPTABLE);
    *param_2 = (char)iVar1;
    FUN_0001a7ec();
    return 0;
  }
  *param_2 = 0;
  return 0xffffffff;
}



void FUN_0000223c(int param_1,undefined *param_2)

{
  if (param_1 == 0) {
    return;
  }
  FUN_000044b4(*(int *)(param_1 + 4),param_2);
  return;
}



uint FUN_00002248(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = FUN_00001620();
  uVar2 = (uint)*(byte *)(puVar1 + 0xcd);
  if (*(byte *)(puVar1 + 0xcd) != 0) {
    uVar2 = 1;
  }
  return uVar2;
}



void FUN_0000225c(void)

{
  uint uVar1;
  int iVar2;
  undefined *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar3;
  uint uVar4;
  uint unaff_r6;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  uVar4 = 0;
  if (*(int *)(PTR_DAT_00091398 + 0x70) == 0) {
    return;
  }
  do {
    uVar7 = 0xffffffff;
    uVar5 = 0;
    puVar3 = (undefined4 *)(*(int *)(PTR_DAT_00091398 + 0x74) + uVar4 * 0x14);
    uVar6 = puVar3[2];
    iVar2 = FUN_00004420(puVar3[1],4);
    if (iVar2 != 0) {
      unaff_r6 = 0;
      if (puVar3 != (undefined4 *)0x0) {
        FUN_0000d758();
        unaff_r6 = FUN_0000440c(puVar3[1],UNRECOVERED_JUMPTABLE);
        FUN_0001a7ec();
        if ((unaff_r6 & 0xff) != 0) {
          uVar7 = 1;
          goto LAB_000022bc;
        }
      }
      uVar7 = 0;
    }
LAB_000022bc:
    uVar1 = uVar6;
    if ((int)uVar6 < 1) {
      uVar1 = unaff_r6 & 0xff;
    }
    if ((uVar1 != 0) && (*(undefined4 **)(puVar3[4] + 8) != (undefined4 *)0x0)) {
      uVar5 = **(undefined4 **)(puVar3[4] + 8);
    }
    FUN_000065ec(0x2c2,*puVar3,uVar7,uVar6,uVar5);
    uVar4 = uVar4 + 1;
    if (*(uint *)(PTR_DAT_00091398 + 0x70) <= uVar4) {
      return;
    }
  } while( true );
}



uint FUN_000022f8(int param_1,int param_2,uint param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 0xc);
  if (*(int *)(param_2 + 0x14) == 1) {
    return param_3;
  }
  puVar1 = FUN_00001614();
  if (puVar1[0x40] == '\0') {
    return *(uint *)(**(int **)(*(int *)(iVar4 + 0x40) + 0x10) + *(int *)(iVar4 + 0x4c) * 0x28) /
           1000;
  }
  ppuVar2 = *(undefined ***)(param_2 + 0x10);
  if (ppuVar2 != (undefined **)0x0) {
    ppuVar2 = (undefined **)&UNK_00000001;
  }
  uVar3 = FUN_00000ce0(iVar4,param_3,ppuVar2);
  return uVar3;
}



uint FUN_00002344(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 0xc);
  if (*(int *)(param_2 + 0x14) == 1) {
    return param_3;
  }
  uVar1 = FUN_00002bcc(iVar2,param_3 * 1000,iVar2,param_1);
  return uVar1 / 1000;
}



undefined4 FUN_0000236c(int param_1,int *param_2,undefined4 param_3)

{
  FUN_00018590(*(int **)(param_1 + 0xc),param_2);
  return param_3;
}



uint FUN_0000237c(undefined4 param_1,int param_2,uint param_3,int *param_4)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = param_3;
  puVar1 = FUN_00001614();
  uVar3 = *(uint *)(param_2 + 0x14);
  bVar5 = uVar3 != 1;
  if (bVar5) {
    uVar3 = (uint)(byte)puVar1[0x40];
  }
  if (bVar5 && uVar3 != param_3) {
    puVar1[0x40] = (char)param_3;
    uVar3 = 0;
    if ((param_3 & 0xff) == 0) {
      do {
        puVar1 = (&PTR_PTR_s__clk_pcnoc_000913a4)[uVar3];
        uVar2 = FUN_00002bcc((int)puVar1,
                             *(uint *)(**(int **)(*(int *)(puVar1 + 0x40) + 0x10) +
                                      *(int *)(puVar1 + 0x48) * 0x28),uVar4,(uint)param_4);
        FUN_0000e180(*(int *)(puVar1 + 0x1c),uVar2 / 1000,uVar4,param_4);
        uVar3 = uVar3 + 1;
      } while (uVar3 < 2);
      uVar3 = *(uint *)(**(int **)(DAT_0009157c + 0x10) + DAT_00091584 * 0x28) / 1000;
    }
    else {
      do {
        puVar1 = (&PTR_PTR_s__clk_pcnoc_000913a4)[uVar3];
        if (*(int *)(*(int *)(puVar1 + 0x1c) + 0x18) != 0) {
          uVar2 = FUN_00002bcc((int)puVar1,*(int *)(*(int *)(puVar1 + 0x1c) + 0x18) * 1000,uVar4,
                               (uint)param_4);
          FUN_0000e180(*(int *)(puVar1 + 0x1c),uVar2 / 1000,uVar4,param_4);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 2);
      uVar3 = *(uint *)(DAT_00091558 + 0x18);
      if (uVar3 == 0) {
        return param_3;
      }
    }
    uVar3 = FUN_00000ce0((int)&PTR_s__clk_bimc_0009153c,uVar3,(undefined **)0x0);
    FUN_0000e180(DAT_00091558,uVar3,DAT_00091558,param_4);
  }
  return param_3;
}



uint FUN_00002450(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint in_r3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 0xc);
  if (*(int *)(param_2 + 0x14) != 1) {
    iVar3 = param_3;
    puVar1 = FUN_00001614();
    if (puVar1[0x40] == '\0') {
      uVar2 = *(uint *)(**(int **)(*(int *)(iVar4 + 0x40) + 0x10) + *(int *)(iVar4 + 0x4c) * 0x28);
    }
    else {
      uVar2 = FUN_00002bcc(iVar4,param_3 * 1000,iVar3,in_r3);
    }
    return uVar2 / 1000;
  }
  return param_3;
}



uint FUN_00002494(undefined4 param_1,int param_2,uint param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  uint uVar3;
  
  if (*(int *)(param_2 + 0x14) == 1) {
    uVar2 = FUN_00014094();
    DAT_000916d8 = (char)uVar2;
    return param_3;
  }
  if (DAT_000916d8 != '\x01') {
    return param_3;
  }
  uVar3 = param_3 & 0xff;
  uVar1 = (undefined)uVar3;
  if ((uint)DAT_000916e0 == uVar3) {
    DAT_000916e0 = uVar1;
    return param_3;
  }
  DAT_000916e0 = uVar1;
  if (uVar3 == 0) {
    uVar3 = param_3;
    FUN_00002c46((int)&PTR_s__clk_qdss_00091698,0);
    FUN_00002dd0((int)&PTR_s__clk_qdss_00091698,0,uVar3,in_r3);
    DAT_000916e0 = uVar1;
    return param_3;
  }
  if (uVar3 == 1) {
    FUN_00002dd0((int)&PTR_s__clk_qdss_00091698,1,param_3,in_r3);
    if (899999 < DAT_000913ac) goto LAB_00002504;
  }
  else {
    if (uVar3 == 2) {
      FUN_00002dd0((int)&PTR_s__clk_qdss_00091698,1,param_3,in_r3);
LAB_00002504:
      FUN_00002c46((int)&PTR_s__clk_qdss_00091698,2);
      DAT_000916e0 = uVar1;
      return param_3;
    }
    if (uVar3 != 3) {
      return param_3;
    }
    FUN_00002dd0((int)&PTR_s__clk_qdss_00091698,1,param_3,in_r3);
  }
  FUN_00002c46((int)&PTR_s__clk_qdss_00091698,1);
  DAT_000916e0 = uVar1;
  return param_3;
}



undefined4 FUN_000025d8(int param_1,int param_2,undefined *param_3)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  ppuVar3 = *(undefined ***)(*(int *)(param_1 + 8) + 0xc);
  iVar7 = **(int **)(ppuVar3[0x10] + 0x10);
  if (param_2 == 0x1020) {
    *param_3 = 1;
    puVar4 = ppuVar3[0x11];
    iVar6 = 0;
    if (puVar4 <= ppuVar3[0x12]) {
      do {
        uVar2 = FUN_00002188(iVar7 + (int)puVar4 * 0x28);
        if (uVar2 != 0) {
          iVar6 = iVar6 + 1;
        }
        puVar4 = puVar4 + 1;
      } while (puVar4 <= ppuVar3[0x12]);
    }
    *(int *)(param_3 + 4) = iVar6;
    return 0;
  }
  if (param_2 == 0x1021) {
    *param_3 = 1;
    *(uint *)(param_3 + 4) =
         *(uint *)(**(int **)(ppuVar3[0x10] + 0x10) + (int)ppuVar3[0x11] * 0x28) / 1000;
  }
  else {
    if (param_2 != 0x1022) {
      if (param_2 != 0x1023) {
        return 1;
      }
      *param_3 = 1;
      *(undefined4 *)(param_3 + 4) = 0;
      if (ppuVar3 != &PTR_s__clk_bimc_0009153c) {
        return 0;
      }
      uVar2 = (uint)DAT_00091532;
      if (DAT_00091532 == 0) {
        return 0;
      }
      if (DAT_00091532 != 2) {
        uVar2 = 0x780;
      }
      if (DAT_00091532 == 2) {
        return 0;
      }
      *(uint *)(param_3 + 4) = uVar2;
      return 0;
    }
  }
  *param_3 = 3;
  iVar6 = *(int *)(param_3 + 4);
  if (iVar6 != 0) {
    iVar5 = 0;
    puVar4 = ppuVar3[0x11];
    if (puVar4 <= ppuVar3[0x12]) {
      do {
        iVar8 = iVar7 + (int)puVar4 * 0x28;
        uVar2 = FUN_00002188(iVar8);
        if (uVar2 != 0) {
          iVar1 = iVar5 * 8;
          *(uint *)(iVar6 + iVar5 * 8) = *(uint *)(iVar7 + (int)puVar4 * 0x28) / 1000;
          iVar5 = iVar5 + 1;
          *(undefined4 *)(iVar6 + iVar1 + 4) = *(undefined4 *)(iVar8 + 0x18);
        }
        puVar4 = puVar4 + 1;
      } while (puVar4 <= ppuVar3[0x12]);
    }
    return 0;
  }
  return 2;
}



undefined4 FUN_000026cc(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 uVar3;
  undefined **ppuVar4;
  uint uVar5;
  undefined8 uVar6;
  
  puVar1 = FUN_00001614();
  if (puVar1 != (undefined *)0x0) {
    FUN_00002f88((int)puVar1,1);
    uVar5 = 0;
    ppuVar4 = (undefined **)0x0;
    FUN_000065ec(0x186,0,0,0,0);
    puVar2 = FUN_00001620();
    if (param_2 == 0) {
      FUN_00003bb8();
      FUN_000012a0(DAT_0009398c,extraout_r1_00,ppuVar4,uVar5);
      FUN_000012a0(DAT_00093990,extraout_r1_01,ppuVar4,uVar5);
      FUN_000012a0(DAT_00093994,extraout_r1_02,ppuVar4,uVar5);
      uVar3 = extraout_r1_03;
      if (puVar2[0x35] != 0) {
        ppuVar4 = (undefined **)(puVar2[0x36] * 5);
        FUN_00002ba0(puVar2[0x32],
                     (undefined **)(**(int **)(puVar2[0x32] + 0x10) + puVar2[0x36] * 0x28),ppuVar4,
                     uVar5);
        uVar3 = extraout_r1_04;
      }
      if (puVar2[0x5f] != 0) {
        ppuVar4 = (undefined **)(puVar2[0x60] * 5);
        FUN_00002ba0(puVar2[0x5c],
                     (undefined **)(**(int **)(puVar2[0x5c] + 0x10) + puVar2[0x60] * 0x28),ppuVar4,
                     uVar5);
        uVar3 = extraout_r1_05;
      }
      if (puVar2[0x4a] != 0) {
        ppuVar4 = (undefined **)(puVar2[0x4b] * 5);
        FUN_00002ba0(puVar2[0x47],
                     (undefined **)(**(int **)(puVar2[0x47] + 0x10) + puVar2[0x4b] * 0x28),ppuVar4,
                     uVar5);
        uVar3 = extraout_r1_06;
      }
      if (puVar2[0xb9] != 0) {
        ppuVar4 = (undefined **)(puVar2[0xba] * 5);
        FUN_00002ba0(puVar2[0xb6],
                     (undefined **)(**(int **)(puVar2[0xb6] + 0x10) + puVar2[0xba] * 0x28),ppuVar4,
                     uVar5);
        uVar3 = extraout_r1_07;
      }
      uVar6 = CONCAT44(puVar2[0x8c],uVar3);
      if (puVar2[0x8c] != 0) {
        ppuVar4 = (undefined **)(puVar2[0x8d] * 5);
        uVar6 = FUN_00002ba0(puVar2[0x89],
                             (undefined **)(**(int **)(puVar2[0x89] + 0x10) + puVar2[0x8d] * 0x28),
                             ppuVar4,uVar5);
      }
      FUN_000029e8((int)((ulonglong)uVar6 >> 0x20),(int)uVar6,ppuVar4,uVar5);
    }
    else {
      FUN_00003068(puVar2,extraout_r1,ppuVar4,uVar5);
      if (*(char *)(puVar2 + 0xcd) != '\0') {
        FUN_00002c46((int)(puVar2 + 0xbb),(uint)*(byte *)((int)puVar2 + 0x336));
      }
    }
    FUN_00002f48((int)puVar1,0);
    FUN_000065ec(0x186,1,0,0,0);
    return 0;
  }
  return 0xffffffff;
}



undefined4 FUN_000027ec(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  puVar1 = FUN_00001620();
  puVar2 = FUN_00001614();
  FUN_00002f88((int)puVar2,1);
  uVar5 = 0;
  uVar4 = 0;
  uVar6 = FUN_000065ec(0x185,0,0,0,0);
  uVar3 = (undefined4)uVar6;
  if (param_2 == 0) {
    FUN_00002fc4((int)((ulonglong)uVar6 >> 0x20),uVar3,uVar4,uVar5);
    if (puVar1[0x4a] != 0) {
      puVar1[0x4b] = puVar1[0x4a];
      FUN_00002ba0(puVar1[0x47],(undefined **)**(undefined ***)(puVar1[0x47] + 0x10),uVar4,uVar5);
    }
    if (puVar1[0xb9] != 0) {
      puVar1[0xba] = puVar1[0xb9];
      FUN_00002ba0(puVar1[0xb6],(undefined **)**(undefined ***)(puVar1[0xb6] + 0x10),uVar4,uVar5);
    }
    if (puVar1[0x8c] != 0) {
      puVar1[0x8d] = puVar1[0x8c];
      FUN_00002ba0(puVar1[0x89],(undefined **)**(undefined ***)(puVar1[0x89] + 0x10),uVar4,uVar5);
    }
    FUN_00000f94(DAT_0009398c);
    FUN_00000f94(DAT_00093990);
    FUN_00000f94(DAT_00093994);
    if (puVar1[0x5f] != 0) {
      puVar1[0x60] = puVar1[0x5f];
      FUN_00002ba0(puVar1[0x5c],(undefined **)**(undefined ***)(puVar1[0x5c] + 0x10),uVar4,uVar5);
    }
    if (puVar1[0x35] != 0) {
      puVar1[0x36] = puVar1[0x35];
      FUN_00002ba0(puVar1[0x32],(undefined **)**(undefined ***)(puVar1[0x32] + 0x10),uVar4,uVar5);
    }
    FUN_00003c30();
  }
  else {
    if (*(char *)(puVar1 + 0xcd) != '\0') {
      *(undefined *)((int)puVar1 + 0x336) = *(undefined *)((int)puVar1 + 0x335);
      FUN_00002c46((int)(puVar1 + 0xbb),0);
      uVar3 = extraout_r1;
    }
    FUN_000029c4((uint)(param_2 == 2),uVar3,uVar4);
  }
  FUN_000065ec(0x185,1,0,0,0);
  FUN_00002f48((int)puVar2,0);
  return 0;
}



undefined4 FUN_00002958(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int unaff_r4;
  
  if (param_1 != 0 && param_2 != (int *)0x0) {
    unaff_r4 = *(int *)(param_1 + 0x10);
  }
  if ((param_1 == 0 || param_2 == (int *)0x0) || unaff_r4 == 0) {
    return 0xffffffff;
  }
  piVar1 = *(int **)(unaff_r4 + 0x1c);
  if (piVar1 == (int *)0x0) {
    puVar2 = (undefined4 *)FUN_00000154(0x10);
    *(undefined4 **)(unaff_r4 + 0x1c) = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    piVar1 = *(int **)(unaff_r4 + 0x1c);
    if (piVar1 == (int *)0x0) {
      return 0xffffffff;
    }
  }
  if (*piVar1 == 0) {
    *piVar1 = param_3;
    *(undefined4 *)(*(int *)(unaff_r4 + 0x1c) + 4) = param_4;
    *param_2 = *(int *)(unaff_r4 + 0x1c);
    return 0;
  }
  if (piVar1[2] != 0) {
    return 0xffffffff;
  }
  piVar1[2] = param_3;
  *(undefined4 *)(*(int *)(unaff_r4 + 0x1c) + 0xc) = param_4;
  *param_2 = *(int *)(unaff_r4 + 0x1c) + 8;
  return 0;
}



undefined4 FUN_000029c4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined *extraout_r1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  
  DAT_00091531 = DAT_00091532;
  uVar3 = (uint)DAT_00091532;
  if (DAT_00091532 == 2) {
    return param_1;
  }
  DAT_00091530 = (char)param_1;
  DAT_0009158c = DAT_00091588;
  if (DAT_00091532 == 0) {
    FUN_00000c1c();
  }
  else {
    if (DAT_00091532 == 1) {
      if ((DAT_00091530 == '\x01') && (uVar1 = FUN_000044a4(), puVar2 = extraout_r1, uVar1 != 0)) {
        do {
          uVar4 = FUN_0000223c(DAT_00091538,puVar2);
          puVar2 = (undefined *)uVar4;
        } while ((int)((ulonglong)uVar4 >> 0x20) == 1);
        do {
          uVar1 = FUN_000041f8();
        } while ((uVar1 & 1) == 0);
        FUN_00000f94(DAT_00091534);
        FUN_00000f94(DAT_0009157c);
        if (DAT_0009152c == 0) {
          FUN_00002ba0(DAT_0009151c,(undefined **)**(undefined ***)(DAT_0009151c + 0x10),param_3,
                       uVar3);
        }
        FUN_000065ec(0x187,10,0,0,0);
      }
      DAT_00091532 = 2;
    }
    else {
      if (DAT_00091532 == 3) {
        FUN_000009fc((uint)DAT_00091532,&DAT_000913ac,param_3,uVar3);
        FUN_00000c1c();
      }
    }
  }
  return 0;
}



void FUN_000029e8(undefined4 param_1,undefined4 param_2,undefined **param_3,uint param_4)

{
  if (DAT_00091531 != '\0') {
    return;
  }
  FUN_00000aa8(*(uint *)(**(int **)(DAT_0009157c + 0x10) + DAT_0009158c * 0x28) / 1000,
               (undefined *)0x3e8,param_3,param_4);
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_00002a18(int param_1,undefined **param_2,undefined4 param_3,uint param_4)

{
  code cVar1;
  undefined **ppuVar2;
  uint uVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **extraout_r1;
  undefined **extraout_r1_00;
  undefined **extraout_r1_01;
  undefined **extraout_r1_02;
  undefined **ppuVar6;
  uint uVar7;
  undefined **ppuVar8;
  undefined **ppuVar9;
  uint uVar10;
  code *pcVar11;
  bool bVar12;
  bool bVar13;
  
  uVar10 = 0;
  if ((param_1 == 0 || param_2 == (undefined **)0x0) || (FUN_00000010 + 4 < param_2[1])) {
    return -1;
  }
  if (*(uint **)(param_1 + 8) != (uint *)0x0) {
    uVar10 = **(uint **)(param_1 + 8) / 1000;
  }
  ppuVar2 = (undefined **)((uint)*param_2 / 1000);
  uVar3 = *(uint *)(param_1 + 0x14);
  ppuVar6 = (undefined **)((uVar3 << 0x16) >> 0x1f);
  uVar7 = (uVar3 << 0x13) >> 0x1f;
  if ((*(int *)(param_1 + 0xc) == 0) || ((uVar3 & 0x400) != 0)) {
    bVar13 = false;
  }
  else {
    bVar13 = true;
  }
  ppuVar8 = (undefined **)(PTR_DAT_00091398 + 0x48);
  cVar1 = (code)param_2[1][(int)ppuVar8];
  if (cVar1 == (code)0xff) {
    ppuVar9 = (undefined **)0x0;
  }
  else {
    ppuVar8 = *(undefined ***)(PTR_DAT_00091398 + 100);
    ppuVar9 = ppuVar8 + (uint)(byte)cVar1 * 8;
    if (ppuVar9 != (undefined **)0x0) {
      ppuVar8 = (undefined **)param_2[9];
    }
    if ((ppuVar9 != (undefined **)0x0 && ppuVar8 != (undefined **)0x0) &&
       (iVar4 = FUN_00000eb4((uint)PTR_DAT_00091398,(uint *)ppuVar9,(uint)ppuVar8), iVar4 != 0)) {
      return iVar4;
    }
  }
  if ((bVar13) && (ppuVar8 = (undefined **)param_2[6], *(undefined ***)(param_1 + 0x10) < ppuVar8))
  {
    param_4 = uVar7;
    FUN_00002e84((int)PTR_DAT_00091398,(uint *)(param_1 + 0x10),(uint)ppuVar8,uVar7);
  }
  ppuVar5 = *(undefined ***)(param_1 + 0xc);
  bVar12 = ppuVar5 != (undefined **)0x0;
  if (bVar12) {
    ppuVar5 = *(undefined ***)(param_1 + 0x18);
  }
  if (((bVar12 && ppuVar5 != ppuVar9) && ppuVar9 != (undefined **)0x0) &&
     (ppuVar8 = ppuVar6,
     iVar4 = FUN_00001420((int)PTR_DAT_00091398,(uint *)ppuVar9,(int)ppuVar6,param_4), iVar4 != 0))
  {
    return iVar4;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar4 = 0;
    do {
      pcVar11 = *(code **)(*(int *)(param_1 + 0x1c) + iVar4 * 8);
      if (pcVar11 != (code *)0x0) {
        ppuVar8 = ppuVar2;
        (*pcVar11)(0,uVar10,ppuVar2,*(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar4 * 8 + 4));
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
  }
  FUN_00003a58(*(int *)(param_1 + 4),param_2 + 1,ppuVar8);
  ppuVar8 = extraout_r1;
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar4 = 0;
    do {
      pcVar11 = *(code **)(*(int *)(param_1 + 0x1c) + iVar4 * 8);
      if (pcVar11 != (code *)0x0) {
        (*pcVar11)(1,uVar10,ppuVar2,*(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar4 * 8 + 4));
        ppuVar8 = extraout_r1_00;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
  }
  bVar12 = *(int *)(param_1 + 0xc) != 0;
  if (bVar12) {
    ppuVar8 = *(undefined ***)(param_1 + 0x18);
  }
  if ((bVar12 && ppuVar8 != ppuVar9) && ppuVar8 != (undefined **)0x0) {
    FUN_00001108((int)PTR_DAT_00091398,(uint *)ppuVar8,(int)ppuVar6);
    ppuVar8 = extraout_r1_01;
  }
  if ((bVar13) && (param_2[6] < *(undefined **)(param_1 + 0x10))) {
    FUN_00002e84((int)PTR_DAT_00091398,(uint *)(param_1 + 0x10),(uint)param_2[6],uVar7);
    ppuVar8 = extraout_r1_02;
  }
  *(undefined ***)(param_1 + 0x18) = ppuVar9;
  uVar10 = *(uint *)(param_1 + 0x14);
  bVar13 = (uVar10 & 0x800) != 0;
  if (bVar13) {
    ppuVar8 = *(undefined ***)(param_1 + 8);
  }
  if (bVar13 && ppuVar8 != param_2) {
    uVar10 = uVar10 & 0xfffff7ff;
  }
  if (bVar13 && ppuVar8 != param_2) {
    *(uint *)(param_1 + 0x14) = uVar10;
  }
  *(undefined ***)(param_1 + 8) = param_2;
  return 0;
}



void FUN_00002ba0(int param_1,undefined **param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_00002a18(*(int *)(param_1 + 0x10),param_2,param_3,param_4);
  if (iVar1 != 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  iVar1 = FUN_0000428a(*(int *)(param_1 + 4));
  FUN_000065ec(0x183,iVar1,*param_2,0,0);
  return;
}



undefined4 FUN_00002bcc(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = **(int **)(*(int *)(param_1 + 0x40) + 0x10);
  uVar5 = *(uint *)(param_1 + 0x44);
  if (uVar5 < *(uint *)(param_1 + 0x48)) {
    do {
      uVar1 = FUN_00002188(iVar6 + uVar5 * 0x28);
      if ((uVar1 != 0) && (param_2 <= *(uint *)(iVar6 + uVar5 * 0x28))) break;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x48));
  }
  ppuVar3 = (undefined **)(iVar6 + uVar5 * 0x28);
  iVar2 = *(int *)(*(int *)(param_1 + 0x40) + 0x10);
  ppuVar4 = *(undefined ***)(iVar2 + 8);
  if (ppuVar3 != ppuVar4) {
    FUN_00002a18(iVar2,ppuVar3,ppuVar4,param_4);
    *(uint *)(param_1 + 0x4c) = uVar5;
    iVar2 = FUN_0000428a(*(int *)(*(int *)(param_1 + 0x40) + 4));
    FUN_000065ec(0x183,iVar2,*(undefined4 *)(iVar6 + uVar5 * 0x28),0,0);
    return *(undefined4 *)(iVar6 + uVar5 * 0x28);
  }
  return *(undefined4 *)(iVar6 + uVar5 * 0x28);
}



void FUN_00002c46(int param_1,int param_2)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  
  puVar1 = FUN_00001614();
  uVar4 = 0;
  if (*(char *)(param_1 + 0x48) == '\x02') {
    uVar3 = 5;
    FUN_00002e84((int)puVar1,(uint *)(param_1 + 0x44),5,0);
  }
  else {
    uVar3 = 3;
    FUN_00002e84((int)puVar1,(uint *)(param_1 + 0x44),3,0);
  }
  piVar2 = *(int **)(*(int *)(param_1 + 100) + 0x10);
  FUN_00002a18((int)piVar2,(undefined **)(*piVar2 + param_2 * 0x28),uVar3,uVar4);
  piVar2 = *(int **)(*(int *)(param_1 + 0x58) + 0x10);
  FUN_00002a18((int)piVar2,(undefined **)(*piVar2 + param_2 * 0x28),uVar3,uVar4);
  piVar2 = *(int **)(*(int *)(param_1 + 0x74) + 0x10);
  FUN_00002a18((int)piVar2,(undefined **)(*piVar2 + param_2 * 0x28),uVar3,uVar4);
  piVar2 = *(int **)(*(int *)(param_1 + 0x68) + 0x10);
  FUN_00002a18((int)piVar2,(undefined **)(*piVar2 + param_2 * 0x28),uVar3,uVar4);
  FUN_000063c8(*(int *)(**(int **)(*(int *)(param_1 + 0x74) + 0x10) + param_2 * 0x28));
  *(undefined *)(param_1 + 0x49) = (char)param_2;
  return;
}



void FUN_00002d30(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = FUN_00001620();
  if (param_1 != 0) {
    DAT_00090520 = DAT_00090520 + 1;
    return;
  }
  if (param_2 == 0) {
    if (DAT_00091740 != 0) {
      uVar2 = *(uint *)(**(int **)(puVar1[0x74] + 0x10) + puVar1[0x77] * 0x28) / 2000;
      DAT_00091740 = 0;
      DAT_00090538 = DAT_00090538 + 1;
      FUN_0000ec02(puVar1[0xdd],uVar2);
      DAT_0009173c = uVar2;
      return;
    }
  }
  else {
    if ((param_2 == 1) && (DAT_00091740 != 1)) {
      DAT_00091740 = 1;
      DAT_0009053c = DAT_0009053c + 1;
      FUN_0000ec02(puVar1[0xdd],0);
      DAT_0009173c = 0;
      return;
    }
  }
  DAT_00090524 = DAT_00090524 + 1;
  return;
}



void FUN_00002dd0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r1_09;
  
  if ((uint)*(byte *)(param_1 + 0x41) == param_2) {
    return;
  }
  *(undefined *)(param_1 + 0x41) = (char)param_2;
  if (param_2 != 0) {
    FUN_000012a0(*(undefined4 **)(param_1 + 0x4c),param_2,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 0x50),extraout_r1,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 0x54),extraout_r1_00,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 100),extraout_r1_01,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 0x68),extraout_r1_02,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 0x6c),extraout_r1_03,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 0x70),extraout_r1_04,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 0x74),extraout_r1_05,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 0x78),extraout_r1_06,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 0x7c),extraout_r1_07,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 0x80),extraout_r1_08,param_3,param_4);
    FUN_000012a0(*(undefined4 **)(param_1 + 0x84),extraout_r1_09,param_3,param_4);
    return;
  }
  FUN_00000f94(*(undefined4 **)(param_1 + 0x4c));
  FUN_00000f94(*(undefined4 **)(param_1 + 0x50));
  FUN_00000f94(*(undefined4 **)(param_1 + 0x54));
  FUN_00000f94(*(undefined4 **)(param_1 + 100));
  FUN_00000f94(*(undefined4 **)(param_1 + 0x68));
  FUN_00000f94(*(undefined4 **)(param_1 + 0x6c));
  FUN_00000f94(*(undefined4 **)(param_1 + 0x70));
  FUN_00000f94(*(undefined4 **)(param_1 + 0x74));
  FUN_00000f94(*(undefined4 **)(param_1 + 0x78));
  FUN_00000f94(*(undefined4 **)(param_1 + 0x7c));
  FUN_00000f94(*(undefined4 **)(param_1 + 0x80));
  FUN_00000f94(*(undefined4 **)(param_1 + 0x84));
  return;
}



undefined4 FUN_00002e84(int param_1,uint *param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_4 == 0) {
    if (*param_2 < 3) {
      *param_2 = 3;
    }
    if (param_3 < 3) {
      param_3 = 3;
    }
  }
  uVar3 = *param_2;
  if (uVar3 != param_3) {
    if (8 < uVar3 || 8 < param_3) {
      return 0xffffffff;
    }
    if (param_4 == 0) {
      iVar2 = param_1 + 0x80;
    }
    else {
      iVar2 = param_1 + 0xb0;
    }
    if (uVar3 != 3) {
      param_4 = *(int *)(iVar2 + uVar3 * 4);
    }
    if (uVar3 != 3 && param_4 != 0) {
      *(int *)(iVar2 + uVar3 * 4) = param_4 + -1;
    }
    if (param_3 != 3) {
      *(int *)(iVar2 + param_3 * 4) = *(int *)(iVar2 + param_3 * 4) + 1;
    }
    *param_2 = param_3;
    uVar3 = *(uint *)(iVar2 + 0x24);
    if (param_3 <= uVar3) {
      uVar1 = param_3 + 1;
      param_3 = uVar3;
      while ((uVar1 <= param_3 && (*(int *)(iVar2 + param_3 * 4) == 0))) {
        param_3 = param_3 - 1;
      }
    }
    if (uVar3 != param_3) {
      if (DAT_000901ff == '\0') {
        if (iVar2 == param_1 + 0x80) {
          uVar3 = 0x189;
        }
        else {
          uVar3 = 0x18a;
        }
        FUN_000065ec(uVar3,param_3 & 0xff,0,0,0);
        FUN_000144e4(*(undefined **)(iVar2 + 0x2c),param_3 & 0xff);
        FUN_00015020();
      }
      *(uint *)(iVar2 + 0x24) = param_3;
    }
  }
  return 0;
}



void FUN_00002f48(int param_1,int param_2)

{
  uint uVar1;
  
  DAT_000901ff = 0;
  if (param_2 == 0) {
    DAT_000901ff = 0;
    return;
  }
  uVar1 = *(uint *)(param_1 + 0xa4) & 0xff;
  FUN_000065ec(0x189,uVar1,0,0,0);
  FUN_000144e4(*(undefined **)(param_1 + 0xac),uVar1);
  FUN_00015020();
  return;
}



undefined4 FUN_00002f88(int param_1,int param_2)

{
  uint uVar1;
  
  DAT_000901ff = (undefined)param_2;
  if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 0xa4) & 0xff;
    FUN_000065ec(0x189,uVar1,0,0,0);
    FUN_000144e4(*(undefined **)(param_1 + 0xac),uVar1);
    FUN_00015020();
  }
  return 0;
}



void FUN_00002fc4(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined *extraout_r1;
  undefined *puVar2;
  undefined4 extraout_r1_00;
  undefined8 uVar3;
  
  if (DAT_00091532 != 2) {
    do {
      if (DAT_00091532 == 0) {
        FUN_00000c1c();
      }
      else {
        if (DAT_00091532 == 1) {
          if ((DAT_00091530 == '\x01') && (uVar1 = FUN_000044a4(), puVar2 = extraout_r1, uVar1 != 0)
             ) {
            do {
              uVar3 = FUN_0000223c(DAT_00091538,puVar2);
              puVar2 = (undefined *)uVar3;
            } while ((int)((ulonglong)uVar3 >> 0x20) == 1);
            do {
              uVar1 = FUN_000041f8();
            } while ((uVar1 & 1) == 0);
            FUN_00000f94(DAT_00091534);
            FUN_00000f94(DAT_0009157c);
            if (DAT_0009152c == 0) {
              FUN_00002ba0(DAT_0009151c,(undefined **)**(undefined ***)(DAT_0009151c + 0x10),param_3
                           ,param_4);
            }
            param_4 = 0;
            param_3 = 0;
            FUN_000065ec(0x187,10,0,0,0);
          }
          DAT_00091532 = 2;
        }
        else {
          if (DAT_00091532 == 3) {
            FUN_000009fc((uint)DAT_00091532,param_2,param_3,param_4);
            FUN_00000c1c();
          }
        }
      }
      thunk_FUN_0000b1ac(100);
      param_2 = extraout_r1_00;
    } while (DAT_00091532 != 2);
    return;
  }
  return;
}



void FUN_00003068(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  if (DAT_00091531 != 0) {
    return;
  }
  if (DAT_00091532 == 0) {
    return;
  }
  FUN_000009fc((uint)DAT_00091532,(uint)DAT_00091531,param_3,param_4);
  return;
}



int * FUN_0000308c(int *param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  uint unaff_r7;
  
  iVar1 = FUN_0000d758();
  piVar5 = (int *)param_1[3];
  if (piVar5 != (int *)0x0) {
    iVar1 = *piVar5;
  }
  if (piVar5 != (int *)0x0) {
    param_1[3] = iVar1;
  }
  FUN_0001a7ec();
  if (param_1 != (int *)0x0) {
    if (piVar5 == (int *)0x0) {
      pcVar3 = (code *)param_1[6];
      if (pcVar3 != (code *)0x0) {
        unaff_r7 = param_1[1];
      }
      if ((pcVar3 != (code *)0x0 && unaff_r7 != 0) &&
         (piVar4 = (int *)(*pcVar3)(unaff_r7), piVar4 != (int *)0x0)) {
        if (7 < unaff_r7) {
          piVar4[1] = unaff_r7;
          FUN_0000d758();
          *piVar4 = *param_1;
          *(int **)param_1 = piVar4;
          param_1[2] = param_1[2] + 1;
          FUN_0001a7ec();
          uVar6 = unaff_r7 - 8;
          piVar4 = piVar4 + 2;
          if (piVar4 != (int *)0x0) {
            if ((uint)param_1[4] <= uVar6) {
              do {
                if (piVar4 == (int *)0x0) goto LAB_00003128;
                FUN_0000d758();
                *piVar4 = param_1[3];
                *(int **)(param_1 + 3) = piVar4;
                FUN_0001a7ec();
                FUN_0000d758();
                param_1[5] = param_1[5] + 1;
                FUN_0001a7ec();
                uVar2 = param_1[4];
                uVar6 = uVar6 - uVar2;
                piVar4 = (int *)((int)piVar4 + uVar2);
              } while (uVar2 <= uVar6);
            }
            iVar1 = FUN_0000d758();
            piVar5 = (int *)param_1[3];
            if (piVar5 != (int *)0x0) {
              iVar1 = *piVar5;
            }
            if (piVar5 != (int *)0x0) {
              param_1[3] = iVar1;
            }
            FUN_0001a7ec();
            return piVar5;
          }
        }
        goto LAB_00003128;
      }
    }
    return piVar5;
  }
LAB_00003128:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000312c(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == (undefined4 *)0x0 || param_2 == (uint *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  uVar3 = *param_2;
  if (param_2[1] == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = uVar3;
    if (uVar3 < 5) {
      uVar2 = 4;
    }
    uVar2 = uVar2 * param_2[1] + 8;
  }
  puVar1 = (undefined4 *)FUN_00000154(uVar2);
  FUN_000031ee(param_1,uVar3,puVar1,uVar2);
  *(undefined **)(param_1 + 6) = &LAB_00003088_1;
  uVar3 = param_2[2];
  if (uVar3 != 0) {
    uVar2 = param_1[4];
    if (uVar2 < 5) {
      uVar2 = 4;
    }
    uVar3 = uVar2 * uVar3 + 8;
  }
  param_1[1] = uVar3;
  return;
}



void FUN_00003188(undefined4 *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = param_3;
    if (param_3 < 5) {
      uVar2 = 4;
    }
    uVar2 = param_2 * uVar2 + 8;
  }
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_00000154(uVar2);
    FUN_000031ee(param_1,param_3,puVar1,uVar2);
    *(undefined **)(param_1 + 6) = &LAB_00003088_1;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_000031cc(int param_1,undefined4 *param_2)

{
  if (param_1 == 0 || param_2 == (undefined4 *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  FUN_0000d758();
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 **)(param_1 + 0xc) = param_2;
  FUN_0001a7ec();
  return;
}



void FUN_000031ee(undefined4 *param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    if (param_2 < 5) {
      param_2 = 4;
    }
    param_1[4] = param_2;
    param_1[7] = 1;
    if (param_4 == 0) {
      return;
    }
    if ((param_3 != (undefined4 *)0x0) && (param_1[1] = param_4, 7 < param_4)) {
      param_3[1] = param_4;
      FUN_0000d758();
      *param_3 = *param_1;
      *(undefined4 **)param_1 = param_3;
      param_1[2] = param_1[2] + 1;
      FUN_0001a7ec();
      param_4 = param_4 - 8;
      param_3 = param_3 + 2;
      if (param_3 != (undefined4 *)0x0) {
        if (param_4 < (uint)param_1[4]) {
          return;
        }
        while (param_3 != (undefined4 *)0x0) {
          FUN_0000d758();
          *param_3 = param_1[3];
          *(undefined4 **)(param_1 + 3) = param_3;
          FUN_0001a7ec();
          FUN_0000d758();
          param_1[5] = param_1[5] + 1;
          FUN_0001a7ec();
          uVar1 = param_1[4];
          param_4 = param_4 - uVar1;
          param_3 = (undefined4 *)((int)param_3 + uVar1);
          if (param_4 < uVar1) {
            return;
          }
        }
      }
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00003276(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 != 0) {
    if (param_2 != 0) {
      uVar1 = *(uint *)(param_1 + 0x10);
      if (uVar1 < 5) {
        uVar1 = 4;
      }
      param_2 = uVar1 * param_2 + 8;
    }
    *(int *)(param_1 + 4) = param_2;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 FUN_000032d6(int param_1,int **param_2)

{
  int *piVar1;
  bool bVar2;
  
  *param_2 = (int *)0x0;
  bVar2 = param_1 != 0;
  if (bVar2) {
    param_1 = *(int *)(param_1 + 0x1c);
  }
  if ((bVar2 && param_1 != 0) && (piVar1 = FUN_0000308c((int *)(param_1 + 8)), piVar1 != (int *)0x0)
     ) {
    *param_2 = piVar1 + 1;
    return 0;
  }
  return 0xffffffff;
}



undefined4 FUN_00003300(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    puVar1 = (undefined4 *)FUN_00000154(0x20);
    uVar3 = 0;
    *(undefined4 **)param_1 = puVar1;
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[5] = 0;
      puVar1[6] = 0;
      *puVar1 = 0x342b;
      puVar1[7] = 0;
      *(code **)(puVar1 + 1) = FUN_000033c0 + 1;
      puVar1[2] = param_2;
      *(undefined **)(puVar1 + 3) = &LAB_000033a0_1;
      puVar1[4] = 1;
      if (puVar1 + 7 == (int *)0x0) {
        uVar3 = 0xffffffff;
        *param_1 = 0;
      }
      else {
        iVar2 = FUN_00000154(0x2c);
        puVar1[7] = iVar2;
        uVar3 = 0;
        if (iVar2 == 0) {
                    // WARNING: Subroutine does not return
          FUN_00000060();
        }
        FUN_000005cc(iVar2,0x2c);
        FUN_0000d758();
        FUN_00003188((undefined4 *)(iVar2 + 8),param_3,param_5 + 4);
        if (param_4 != 0) {
          FUN_00003276((int)(undefined4 *)(iVar2 + 8),param_4);
        }
        FUN_0001a7ec();
      }
    }
  }
  return uVar3;
}



undefined4 FUN_000033c0(int param_1,int **param_2)

{
  int *piVar1;
  int **unaff_r4;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 == (int **)0x0) {
    return 0xffffffff;
  }
  if (param_1 != 0) {
    unaff_r4 = *(int ***)(param_1 + 0x1c);
  }
  if (param_1 != 0 && unaff_r4 != (int **)0x0) {
    FUN_0000d758();
    piVar1 = *unaff_r4;
    if (piVar1 == (int *)0x0) {
      uVar2 = 0xffffffff;
      *param_2 = (int *)0x0;
    }
    else {
      unaff_r4[10] = (int *)((int)unaff_r4[10] + -1);
      *param_2 = piVar1 + 1;
      piVar1 = (int *)*piVar1;
      if (piVar1 != (int *)0x0) {
        *unaff_r4 = piVar1;
      }
      else {
        *unaff_r4 = (int *)0x0;
      }
      if (piVar1 == (int *)0x0) {
        unaff_r4[1] = (int *)0x0;
      }
    }
    FUN_0001a7ec();
    return uVar2;
  }
  *param_2 = (int *)0x0;
  return 0xffffffff;
}



int FUN_0000342a(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *unaff_r4;
  bool bVar3;
  
  bVar3 = param_1 != 0;
  if (bVar3) {
    unaff_r4 = *(undefined4 **)(param_1 + 0x1c);
  }
  if ((!bVar3 || unaff_r4 == (undefined4 *)0x0) || param_2 == 0) {
    param_1 = -1;
  }
  if ((bVar3 && unaff_r4 != (undefined4 *)0x0) && param_2 != 0) {
    FUN_0000d758();
    unaff_r4[10] = unaff_r4[10] + 1;
    puVar1 = (undefined4 *)(param_2 + -4);
    *puVar1 = 0;
    puVar2 = (undefined4 *)unaff_r4[1];
    if (puVar2 != (undefined4 *)0x0) {
      *(undefined4 **)puVar2 = puVar1;
    }
    *(undefined4 **)(unaff_r4 + 1) = puVar1;
    if (puVar2 == (undefined4 *)0x0) {
      *(undefined4 **)unaff_r4 = puVar1;
    }
    FUN_0001a7ec();
    return 0;
  }
  return param_1;
}



void thunk_FUN_0000b1ac(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  piVar1 = DAT_00090514;
  if (DAT_00090514 == (int *)0x0) {
    return;
  }
  iVar2 = *DAT_00090514;
  uVar3 = FUN_000001b0((uint)((ulonglong)param_1 * 0x4b00),
                       (uint)((ulonglong)param_1 * 0x4b00 >> 0x20),1000,0);
  do {
  } while ((int)uVar3 + (uint)((uint)(*piVar1 - iVar2) < (uint)((ulonglong)uVar3 >> 0x20)) != 0);
  return;
}



undefined4 FUN_0000346c(int param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if ((&DAT_0001b6ac)[uVar1 * 2] == param_1) {
      *(undefined **)param_2 = &DAT_0001b694;
      param_2[1] = (&DAT_0001b6b0)[uVar1 * 2];
      return 0;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 2);
  *param_2 = 0;
  param_2[1] = 0;
  return 0xffffffff;
}



undefined4 FUN_000034b4(uint *param_1,undefined4 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int local_10;
  
  local_10 = 0;
  iVar1 = FUN_000036bc(param_1,&local_10,(int)&PTR_DAT_0001bca4,param_4);
  if (iVar1 != 0) {
    *param_2 = 0;
    param_2[1] = 0;
    return 0xffffffff;
  }
  *(undefined **)param_2 = &DAT_0001b694;
  param_2[1] = *(undefined4 *)(local_10 + 8);
  return 0;
}



undefined4 FUN_000034e4(int *param_1,uint *param_2,int param_3,uint *param_4)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  int local_48 [5];
  int local_34 [4];
  
  local_34[0] = 0;
  iVar6 = *param_1;
  pbVar8 = (byte *)(iVar6 + param_1[1]);
  bVar1 = false;
  if (iVar6 == 0 || pbVar8 == (byte *)0x0) {
    return 0xffffffff;
  }
  uVar3 = 0;
  do {
    if ((&DAT_0001b6ac)[uVar3 * 2] == 0) goto LAB_0000352e;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 2);
  bVar1 = true;
LAB_0000352e:
  do {
    while( true ) {
      FUN_0000da64(param_4,4,pbVar8,4);
      if (*param_4 != 0xff00ff00) break;
      if (bVar1) {
        return 0xffffffff;
      }
      bVar1 = true;
      pbVar8 = (byte *)(*param_1 + *(int *)(iVar6 + 0x1c));
    }
    FUN_0000da64(local_34,4,pbVar8 + 4,4);
    pbVar7 = pbVar8 + 8;
    if (param_2 == (uint *)0x0) {
      if (local_34[0] == param_3) goto LAB_0000359a;
    }
    else {
      iVar4 = FUN_00000660((uint *)(local_34[0] + iVar6 + *(int *)(iVar6 + 4)),param_2);
      if (iVar4 == 0) {
LAB_0000359a:
        uVar3 = *param_4 & 0x3fffff;
        if (uVar3 == 0x12) {
          local_48[0] = 0;
          FUN_0000da64(local_48,4,pbVar7,4);
          *(undefined **)(param_4 + 2) = (&PTR_DAT_00091844)[local_48[0]];
          *param_4 = 0x12;
          param_4[1] = 4;
        }
        else {
          if (uVar3 < 0x12) {
            if (uVar3 == 2) {
              FUN_0000da64(param_4 + 2,4,pbVar7,4);
              param_4[1] = 4;
              uVar3 = 2;
            }
            else {
              if (uVar3 == 8) {
                bVar2 = *pbVar7;
                *param_4 = 0x11;
                param_4[1] = (uint)bVar2 + 1;
                *(byte **)(param_4 + 2) = pbVar8 + 9;
                return 0;
              }
              if (uVar3 != 0x11) {
                return 0xffffffff;
              }
              local_48[0] = 0;
              FUN_0000da64(local_48,4,pbVar7,4);
              puVar5 = (uint *)(*(int *)(iVar6 + 8) + local_48[0] + iVar6);
              *(uint **)(param_4 + 2) = puVar5;
              puVar5 = FUN_00000378(puVar5);
              *(uint **)(param_4 + 1) = puVar5;
              uVar3 = 0x10;
            }
            *param_4 = uVar3;
          }
          else {
            if (uVar3 == 0x14) {
              local_48[0] = 0;
              FUN_0000da64(local_48,4,pbVar7,4);
              uVar3 = *(int *)(iVar6 + 0x10) + iVar6 + local_48[0] + 4;
              param_4[2] = uVar3;
              iVar6 = *(int *)(uVar3 - 4);
              *param_4 = 0x12;
              param_4[1] = iVar6 + 1;
              return 0;
            }
            if (uVar3 != 0x18) {
              return 0xffffffff;
            }
            local_48[0] = 0;
            FUN_0000da64(local_48,4,pbVar7,4);
            uVar3 = *(int *)(iVar6 + 0xc) + iVar6 + local_48[0] + 1;
            param_4[2] = uVar3;
            bVar2 = *(byte *)(uVar3 - 1);
            *param_4 = 0x11;
            param_4[1] = (uint)bVar2 + 1;
          }
        }
        return 0;
      }
    }
    uVar3 = *param_4 & 0x3fffff;
    if (uVar3 == 0x12) {
LAB_000035c4:
      pbVar8 = pbVar8 + 0xc;
      goto LAB_0000352e;
    }
    if (0x12 < uVar3) {
      if (uVar3 != 0x14 && uVar3 != 0x18) {
        return 0xffffffff;
      }
      goto LAB_000035c4;
    }
    if (uVar3 == 2) goto LAB_000035c4;
    if (uVar3 != 8) {
      if (uVar3 != 0x11) {
        return 0xffffffff;
      }
      goto LAB_000035c4;
    }
    bVar2 = *pbVar7 + 2;
    pbVar8 = pbVar7 + (uint)bVar2;
    if ((bVar2 & 3) != 0) {
      pbVar8 = pbVar8 + (4 - ((uint)bVar2 & 3));
    }
  } while( true );
}



void FUN_000036b8(void)

{
  return;
}



undefined4 FUN_000036bc(uint *param_1,int *param_2,int param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar7 = param_3;
  if (param_3 != 0) {
    iVar7 = *(int *)(param_3 + 0xc);
  }
  if (param_3 != 0 && iVar7 != 0) {
    if (param_1 != (uint *)0x0) {
      param_4 = *(uint *)(param_3 + 8);
    }
    if ((param_1 != (uint *)0x0 && param_4 != 0) && param_2 != (int *)0x0) {
      bVar1 = *(byte *)param_1;
      iVar9 = 0x1505;
      puVar4 = param_1;
      while (bVar1 != 0) {
        iVar9 = (uint)*(byte *)puVar4 + iVar9 * 0x21;
        bVar1 = *(byte *)(uint *)((int)puVar4 + 1);
        puVar4 = (uint *)((int)puVar4 + 1);
      }
      uVar3 = 0;
      if (param_4 != 0) {
        uVar6 = param_4 & 1;
        uVar2 = uVar6;
      }
      else {
        uVar6 = param_4;
        uVar2 = 0;
      }
      if ((param_4 != 0 && uVar2 != 0) && -1 < (int)uVar6) {
        do {
          if (*(int *)(iVar7 + uVar3 * 0x18 + 4) == iVar9) goto LAB_00003750;
          uVar3 = uVar3 + 1;
        } while ((int)uVar3 < (int)uVar2);
      }
      while( true ) {
        uVar3 = uVar2;
        if ((param_4 <= uVar3) || (*(int *)(iVar7 + uVar3 * 0x18 + 4) == iVar9)) goto LAB_00003750;
        if (*(int *)(iVar7 + uVar3 * 0x18 + 0x1c) == iVar9) break;
        uVar2 = uVar3 + 2;
      }
      uVar3 = uVar3 + 1;
LAB_00003750:
      if (param_4 != uVar3) {
        iVar9 = *(int *)(iVar7 + uVar3 * 0x18 + 0x10);
        if (iVar9 == 0) {
          *param_2 = iVar7 + uVar3 * 0x18;
          return 0;
        }
        iVar8 = 0;
        iVar7 = *(int *)(iVar7 + uVar3 * 0x18 + 0x14);
        if (0 < iVar9) {
          do {
            puVar4 = FUN_00000378(param_1);
            puVar5 = FUN_00000378(*(uint **)(*(int *)(param_3 + 0xc) +
                                            *(int *)(iVar7 + iVar8 * 4) * 0x18));
            if (puVar4 == puVar5) {
              puVar4 = FUN_00000378(param_1);
              uVar3 = FUN_000003b6(param_1,*(uint **)(*(int *)(param_3 + 0xc) +
                                                     *(int *)(iVar7 + iVar8 * 4) * 0x18),
                                   (uint)puVar4);
              if (uVar3 == 0) {
                *param_2 = *(int *)(param_3 + 0xc) + *(int *)(iVar7 + iVar8 * 4) * 0x18;
                return 0;
              }
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar9);
        }
      }
    }
  }
  return 0xffffffff;
}



void FUN_000037e4(void)

{
  DAT_000939d8 = 1;
  return;
}



void thunk_FUN_0000d758(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar2 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x10);
  }
  if ((DAT_000900c4 != 0) && (iVar2 == 0)) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  DAT_000900c4 = DAT_000900c4 + 1;
  return;
}



int thunk_FUN_0001a7ec(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar2 = getBasePriority();
  }
  if (DAT_000900c4 == 0 || iVar2 == 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  DAT_000900c4 = DAT_000900c4 + -1;
  iVar2 = DAT_000900c4;
  if (DAT_000900c4 == 0) {
    iVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0);
    }
  }
  return iVar2;
}



undefined4 FUN_000037f8(undefined4 param_1,uint *param_2,undefined4 *param_3)

{
  uint uVar1;
  
  uVar1 = FUN_000003b6((uint *)"CORE_TOP_CSR",param_2,0xd);
  if (uVar1 == 0) {
    *param_3 = 0x61900000;
    return 0;
  }
  uVar1 = FUN_000003b6((uint *)"PMIC_ARB",param_2,8);
  if (uVar1 == 0) {
    *param_3 = 0x62000000;
    return 0;
  }
  return 0xffffffff;
}



undefined4 FUN_000038a2(void)

{
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_000038a8(void)

{
  do {
  } while ((_DAT_e0041010 & 2) == 0);
  _DAT_e0041020 = 0x77ef;
  _DAT_e0041000 = _DAT_e0041000 & 0xfffffbff;
  do {
  } while ((_DAT_e0041010 & 2) != 0);
  _DAT_e0041fb0 = 0;
  DataSynchronizationBarrier(0xf);
  DAT_000905c0 = 0;
  FUN_00005f2c();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_000038f8(void)

{
  FUN_00005fa4();
  do {
  } while ((_DAT_e0041010 & 2) == 0);
  do {
  } while ((_DAT_e0041010 & 2) != 0);
  DataSynchronizationBarrier(0xf);
  DAT_000905c0 = 1;
  _DAT_e0041000 = 0x840;
  _DAT_e0041018 = 0;
  _DAT_e004101c = 0;
  _DAT_e0041020 = 0x37ef;
  _DAT_e0041024 = 0x1000000;
  _DAT_e0041200 = 0x20;
  _DAT_e0041fb0 = 0;
  return;
}



void FUN_00003970(void)

{
                    // WARNING: Could not recover jumptable at 0x0000397a. Too many branches
                    // WARNING: Treating indirect jump as call
  (**DAT_00090578)();
  return;
}



void FUN_00003984(void)

{
                    // WARNING: Could not recover jumptable at 0x0000398e. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(DAT_00090578 + 4))();
  return;
}



int * FUN_00003998(int *param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = param_1 != (int *)0x0;
  if (bVar3) {
    param_4 = param_1[6];
  }
  if ((!bVar3 || param_2 <= param_4) && (bVar3 && param_4 != param_2)) {
    iVar2 = *param_1;
    if ((*(uint *)(iVar2 + param_2 * 0x8000 + 0x49020) & 0xff) == 1) {
      iVar1 = param_2 * 0x8000 + 0x49210;
      *(uint *)(iVar2 + iVar1) = *(uint *)(iVar2 + iVar1) & 0xf0000000 | param_3;
      return *(int **)(*param_1 + iVar1);
    }
    return param_1;
  }
  return param_1;
}



void FUN_000039a8(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  puVar2 = (undefined4 *)*param_1;
  uVar1 = puVar2[0x408];
  param_1[2] = (uVar1 << 8) >> 0x18;
  param_1[5] = uVar1 & 0xff;
  param_1[6] = (uVar1 << 0x10) >> 0x18;
  param_1[3] = uVar1 >> 0x18;
  param_1[4] = (uint)puVar2[0x40c] >> 0x10;
  param_1[7] = *puVar2;
  return;
}



void FUN_000039b2(int *param_1,uint param_2,int param_3,uint *param_4)

{
  uint in_r12;
  bool bVar1;
  
  bVar1 = param_1 != (int *)0x0;
  if (bVar1) {
    in_r12 = param_1[5];
  }
  if ((!bVar1 || param_2 <= in_r12) && (bVar1 && in_r12 != param_2)) {
    if (param_4 != (uint *)0x0) {
      FUN_0000ac70(param_1,param_2,param_3,param_4);
      return;
    }
    return;
  }
  return;
}



int * FUN_000039ca(int *param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint in_r12;
  int iVar2;
  bool bVar3;
  
  bVar3 = param_1 != (int *)0x0;
  if (bVar3) {
    in_r12 = param_1[5];
  }
  if (bVar3 && in_r12 < param_2 || (!bVar3 || in_r12 == param_2)) {
    return param_1;
  }
  if ((uint)param_1[7] < 0x20010001) {
    return param_1;
  }
  if (param_3 != 0) {
    if (param_3 < 4) {
      iVar2 = *param_1 + param_2 * 0x4000;
      iVar1 = (param_3 - 1) * 0x100 + 0x8800;
      *(uint *)(iVar2 + iVar1) = param_4 | *(uint *)(iVar2 + iVar1) & 0xff000000;
      return (int *)*(undefined4 *)(*param_1 + param_2 * 0x4000 + iVar1);
    }
    return param_1;
  }
  return param_1;
}



void FUN_000039dc(int *param_1,uint param_2,uint param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint in_r12;
  bool bVar4;
  
  bVar4 = param_1 != (int *)0x0;
  if (bVar4) {
    in_r12 = param_1[5];
  }
  if (bVar4 && in_r12 < param_2 || (!bVar4 || in_r12 == param_2)) {
    return;
  }
  if ((uint)param_1[7] < 0x20010001) {
    return;
  }
  if (param_3 != 0) {
    if (param_3 < 4) {
      iVar3 = *param_1 + param_2 * 0x4000;
      iVar1 = (param_3 - 1) * 0x100 + 0x8800;
      uVar2 = *(uint *)(iVar3 + iVar1) & 0xff000001 & ~(*param_4 << 0x18) | param_4[1] << 0x18;
      *(uint *)(iVar3 + iVar1) = uVar2;
      *(uint *)(*param_1 + param_2 * 0x4000 + iVar1) = uVar2;
      return;
    }
    return;
  }
  return;
}



int * FUN_000039ee(int *param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint in_r12;
  bool bVar2;
  
  bVar2 = param_1 != (int *)0x0;
  if (bVar2) {
    in_r12 = param_1[5];
  }
  if (bVar2 && in_r12 < param_2 || (!bVar2 || in_r12 == param_2)) {
    return param_1;
  }
  if (param_4 == 0) {
    return param_1;
  }
  if (0x20010000 < (uint)param_1[7]) {
    if (param_3 == 0) {
      return param_1;
    }
    if (param_3 < 4) {
      iVar1 = param_3 - 1;
      *(uint *)(*param_1 + param_2 * 0x4000 + iVar1 * 0x100 + 0x884c) =
           *(uint *)(param_4 + 0x14) & 3 |
           (*(uint *)(param_4 + 0x10) & 3) << 8 | (uint)*(byte *)(param_4 + 0xc) << 0x1f;
      *(uint *)(*param_1 + param_2 * 0x4000 + iVar1 * 0x100 + 0x8848) =
           (*(uint *)(param_4 + 0x1c) & 3) << 8 | (uint)*(byte *)(param_4 + 0x18) << 0x1f |
           *(uint *)(param_4 + 0x20) & 3;
      *(uint *)(*param_1 + param_2 * 0x4000 + iVar1 * 0x100 + 0x8844) =
           (*(uint *)(param_4 + 0x28) & 3) << 8 | (uint)*(byte *)(param_4 + 0x24) << 0x1f |
           *(uint *)(param_4 + 0x2c) & 3;
      iVar1 = iVar1 * 0x100 + 0x8840;
      *(uint *)(*param_1 + param_2 * 0x4000 + iVar1) =
           (*(uint *)(param_4 + 0x34) & 3) << 8 | (uint)*(byte *)(param_4 + 0x30) << 0x1f |
           *(uint *)(param_4 + 0x38) & 3;
      return (int *)*(undefined4 *)(*param_1 + param_2 * 0x4000 + iVar1);
    }
    return param_1;
  }
  return param_1;
}



void FUN_00003a06(int *param_1,uint param_2,uint *param_3,uint param_4)

{
  bool bVar1;
  
  bVar1 = param_1 != (int *)0x0;
  if (bVar1) {
    param_4 = param_1[5];
  }
  if ((!bVar1 || param_2 <= param_4) && (bVar1 && param_4 != param_2)) {
    if (param_3 != (uint *)0x0) {
      FUN_0000af5c(param_1,param_2,param_3);
      return;
    }
    return;
  }
  return;
}



int * FUN_00003a1c(int *param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = param_1 != (int *)0x0;
  if (bVar2) {
    param_4 = param_1[5];
  }
  if (bVar2 && param_4 < param_2 || (!bVar2 || param_4 == param_2)) {
    return param_1;
  }
  iVar1 = param_2 * 0x4000 + 0x8300;
  if (1 < param_3) {
    if (param_3 == 2) {
      *(uint *)(*param_1 + iVar1) = *(uint *)(*param_1 + iVar1) & 0xff000000;
      return *(int **)(*param_1 + iVar1);
    }
    if (param_3 != 3) {
      return param_1;
    }
  }
  *(uint *)(*param_1 + iVar1) = *(uint *)(*param_1 + iVar1) & 0xff000000 | 1;
  return *(int **)(*param_1 + iVar1);
}



void FUN_00003a2c(int *param_1,uint param_2,int param_3,uint *param_4)

{
  uint in_r12;
  bool bVar1;
  
  bVar1 = param_1 != (int *)0x0;
  if (bVar1) {
    in_r12 = param_1[5];
  }
  if ((!bVar1 || param_2 <= in_r12) && (bVar1 && in_r12 != param_2)) {
    if (param_4 != (uint *)0x0) {
      FUN_0000b084(param_1,param_2,param_3,param_4);
      return;
    }
    return;
  }
  return;
}



void FUN_00003a44(void)

{
  if (DAT_00095734 == (code *)0x0) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00003a50. Too many branches
                    // WARNING: Treating indirect jump as call
  (*DAT_00095734)();
  return;
}



void FUN_00003a58(int param_1,undefined4 param_2,undefined **param_3)

{
  if (param_1 != 0) {
    param_3 = *(undefined ***)(param_1 + 0xc);
  }
  if (param_1 != 0 && (code **)param_3 != (code **)0x0) {
    if ((code *)*param_3 != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003a6a. Too many branches
                    // WARNING: Treating indirect jump as call
      (*(code *)*param_3)();
      return;
    }
    return;
  }
  return;
}



void FUN_00003a6c(uint param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  bool bVar1;
  
  if (0x14 < param_1) {
    return;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(&DAT_00095624 + param_1 * 0xc);
  bVar1 = UNRECOVERED_JUMPTABLE != (code *)0x0;
  if (bVar1) {
    UNRECOVERED_JUMPTABLE = *(code **)(UNRECOVERED_JUMPTABLE + 0x10);
  }
  if (bVar1 && UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003a88. Too many branches
                    // WARNING: Treating indirect jump as call
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}



void FUN_00003a90(int param_1,undefined4 *param_2,undefined *UNRECOVERED_JUMPTABLE)

{
  bool bVar1;
  bool bVar2;
  
  bVar2 = param_1 != 0;
  if (bVar2) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0xc);
  }
  bVar1 = (code *)UNRECOVERED_JUMPTABLE != (code *)0x0;
  if (bVar2 && bVar1) {
    UNRECOVERED_JUMPTABLE = *(undefined **)((code *)UNRECOVERED_JUMPTABLE + 4);
  }
  if ((!bVar2 || !bVar1) || (code *)UNRECOVERED_JUMPTABLE == (code *)0x0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
    return;
  }
  if (param_2 != (undefined4 *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003aa4. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}



void FUN_00003ab0(uint param_1,undefined4 *param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  bool bVar1;
  
  *param_2 = 0;
  if (0x14 < param_1) {
    return;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(&DAT_00095624 + param_1 * 0xc);
  bVar1 = UNRECOVERED_JUMPTABLE != (code *)0x0;
  if (bVar1) {
    UNRECOVERED_JUMPTABLE = *(code **)(UNRECOVERED_JUMPTABLE + 0x14);
  }
  if (bVar1 && UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003ad0. Too many branches
                    // WARNING: Treating indirect jump as call
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}



void FUN_00003ad8(int param_1,int param_2)

{
  if (param_1 != 0) {
    param_2 = *(int *)(param_1 + 0x14);
  }
  if (param_1 != 0 && param_2 != 0) {
    if (*(code **)(param_2 + 4) != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003aea. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(param_2 + 4))();
      return;
    }
    return;
  }
  return;
}



void FUN_00003aec(int param_1,int param_2)

{
  if (param_1 != 0) {
    param_2 = *(int *)(param_1 + 8);
  }
  if (param_1 != 0 && param_2 != 0) {
    if (*(code **)(param_2 + 4) != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003afe. Too many branches
                    // WARNING: Treating indirect jump as call
      (**(code **)(param_2 + 4))();
      return;
    }
    return;
  }
  return;
}



void FUN_00003b00(uint param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  bool bVar1;
  
  if (0x14 < param_1) {
    return;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(&DAT_00095624 + param_1 * 0xc);
  bVar1 = UNRECOVERED_JUMPTABLE != (code *)0x0;
  if (bVar1) {
    UNRECOVERED_JUMPTABLE = *(code **)(UNRECOVERED_JUMPTABLE + 4);
  }
  if (bVar1 && UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003b1c. Too many branches
                    // WARNING: Treating indirect jump as call
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}



void FUN_00003b24(uint param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  bool bVar1;
  
  if (0x14 < param_1) {
    return;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(&DAT_00095624 + param_1 * 0xc);
  bVar1 = UNRECOVERED_JUMPTABLE != (code *)0x0;
  if (bVar1) {
    UNRECOVERED_JUMPTABLE = *(code **)(UNRECOVERED_JUMPTABLE + 0x1c);
  }
  if (bVar1 && UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003b40. Too many branches
                    // WARNING: Treating indirect jump as call
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}



void FUN_00003b48(int param_1,undefined **param_2)

{
  if (param_1 != 0) {
    param_2 = *(undefined ***)(param_1 + 0x14);
  }
  if (param_1 != 0 && (code **)param_2 != (code **)0x0) {
    if ((code *)*param_2 != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003b5a. Too many branches
                    // WARNING: Treating indirect jump as call
      (*(code *)*param_2)();
      return;
    }
    return;
  }
  return;
}



void FUN_00003b5c(int param_1,undefined4 param_2,undefined **param_3)

{
  if (param_1 != 0) {
    param_3 = *(undefined ***)(param_1 + 8);
  }
  if (param_1 != 0 && (code **)param_3 != (code **)0x0) {
    if ((code *)*param_3 != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003b6e. Too many branches
                    // WARNING: Treating indirect jump as call
      (*(code *)*param_3)();
      return;
    }
    return;
  }
  return;
}



void FUN_00003b70(uint param_1)

{
  code **UNRECOVERED_JUMPTABLE;
  bool bVar1;
  
  if (0x14 < param_1) {
    return;
  }
  UNRECOVERED_JUMPTABLE = *(code ***)(&DAT_00095624 + param_1 * 0xc);
  bVar1 = UNRECOVERED_JUMPTABLE != (code **)0x0;
  if (bVar1) {
    UNRECOVERED_JUMPTABLE = (code **)*UNRECOVERED_JUMPTABLE;
  }
  if (bVar1 && UNRECOVERED_JUMPTABLE != (code **)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003b8c. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}



void FUN_00003b94(uint param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  bool bVar1;
  
  if (0x14 < param_1) {
    return;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(&DAT_00095624 + param_1 * 0xc);
  bVar1 = UNRECOVERED_JUMPTABLE != (code *)0x0;
  if (bVar1) {
    UNRECOVERED_JUMPTABLE = *(code **)(UNRECOVERED_JUMPTABLE + 0x18);
  }
  if (bVar1 && UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x00003bb0. Too many branches
                    // WARNING: Treating indirect jump as call
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}



void FUN_00003bb8(void)

{
  uint *puVar1;
  
  puVar1 = (uint *)(DAT_00091750 + 0x21000);
  *puVar1 = *puVar1 & 0xe0ffff0f | 0x200000;
  *puVar1 = *puVar1 & 0xe0ffff0d;
  *puVar1 = *puVar1 & 0xe0ffff0b;
  *puVar1 = *puVar1 & 0xe0ffff0e;
  FUN_00003a44();
  *(uint *)(DAT_00091750 + 0x21000) = *(uint *)(DAT_00091750 + 0x21000) & 0xe0ffff0f | 0x100000;
  FUN_00003a44();
  *(uint *)(DAT_00091750 + 0x21000) = *(uint *)(DAT_00091750 + 0x21000) & 0xe0dfff0f;
  return;
}



void FUN_00003c30(void)

{
  uint *puVar1;
  
  puVar1 = (uint *)(DAT_00091750 + 0x21000);
  *puVar1 = *puVar1 & 0xe0efff0f;
  *puVar1 = *puVar1 & 0xe0ffff0d;
  *puVar1 = *puVar1 & 0xe0ffff0b;
  *puVar1 = *puVar1 & 0xe0ffff0e;
  return;
}



void FUN_000040b6(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint **ppuVar4;
  
  ppuVar4 = *(uint ***)(param_1 + 8);
  puVar3 = *ppuVar4;
  if ((~*puVar3 & 7) == 0) {
    return;
  }
  uVar1 = *puVar3 & 0xfffffff8;
  *puVar3 = uVar1;
  if (ppuVar4[3] == (uint *)0x0) {
    **ppuVar4 = uVar1 | 6;
  }
  else {
    **ppuVar4 = uVar1 | 2;
    FUN_00003a44();
    **ppuVar4 = uVar1 | 6;
  }
  FUN_00003a44();
  uVar2 = (*ppuVar4)[7];
  while ((uVar2 & 0x10000) == 0) {
    FUN_00003a44();
    uVar2 = (*ppuVar4)[7];
  }
  **ppuVar4 = uVar1 | 7;
  return;
}



void FUN_00004120(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  *(uint *)piVar1[1] = *(uint *)piVar1[1] | piVar1[2];
  if ((*(uint *)(*piVar1 + 0x1c) & 0x20000) != 0) {
    return;
  }
  do {
    FUN_00003a44();
  } while ((*(uint *)(*piVar1 + 0x1c) & 0x20000) == 0);
  return;
}



undefined4 FUN_000041d4(void)

{
  return DAT_0009573c;
}



undefined4 FUN_000041e0(void)

{
  return DAT_00095738;
}



void FUN_000041ec(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_000041f8(void)

{
  return _DAT_604b2200 & 0x110011;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_00004208(void)

{
  return (uint)(_DAT_61110010 << 4) >> 0x10;
}



void FUN_00004218(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0009571c;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  *param_2 = uVar1;
  return;
}



int FUN_0000422c(int param_1,uint param_2,uint param_3)

{
  bool bVar1;
  
  bVar1 = param_1 == 0;
  if (!bVar1) {
    param_3 = *(uint *)(param_1 + 8);
  }
  if (!bVar1 && param_3 < param_2 || (bVar1 || param_3 == param_2)) {
    param_1 = 0;
  }
  if ((bVar1 || param_3 >= param_2) && (!bVar1 && param_3 != param_2)) {
    return *(int *)(param_1 + 4) + param_2 * 0x1c;
  }
  return param_1;
}



void FUN_00004248(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00095720;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0xc);
  }
  *param_2 = uVar1;
  return;
}



undefined4 FUN_0000425c(void)

{
  return DAT_0009572c;
}



undefined4 FUN_00004268(void)

{
  return DAT_00095728;
}



undefined4 FUN_00004274(void)

{
  return DAT_00095730;
}



void FUN_00004280(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  return;
}



int FUN_0000428a(int param_1)

{
  if (param_1 != 0) {
    param_1 = *(int *)(param_1 + 0x18);
  }
  return param_1;
}



void FUN_00004294(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    DAT_00095734 = *param_1;
    DAT_00095738 = param_1[1];
    DAT_0009573c = param_1[2];
  }
  if (PTR_DAT_0009179c == (undefined *)0x0) {
    return;
  }
  pcVar1 = *(code **)PTR_DAT_0009179c;
  iVar2 = 1;
  if (pcVar1 == (code *)0x0) {
    return;
  }
  do {
    (*pcVar1)();
    pcVar1 = *(code **)(PTR_DAT_0009179c + iVar2 * 4);
    iVar2 = iVar2 + 1;
  } while (pcVar1 != (code *)0x0);
  return;
}



void FUN_000042d8(int **param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  piVar2 = *param_1;
  if (piVar2 == (int *)0x0) {
    return;
  }
  do {
    piVar1 = DAT_0009571c;
    uVar5 = 0;
    if (piVar2 != (int *)0x0) {
      DAT_0009571c = piVar2;
      if (*piVar2 != 0) {
        *piVar2 = *piVar2 + param_2;
      }
      *(int **)(DAT_0009571c + 4) = piVar1;
      if (piVar2[2] != 0) {
        do {
          iVar3 = DAT_0009571c[1] + uVar5 * 0x1c;
          iVar4 = *(int *)(iVar3 + 4);
          bVar6 = iVar4 != 0;
          if (bVar6) {
            iVar4 = iVar4 + param_2;
          }
          if (bVar6) {
            *(int *)(iVar3 + 4) = iVar4;
          }
          iVar4 = *(int *)(iVar3 + 8);
          bVar6 = iVar4 != 0;
          if (bVar6) {
            iVar4 = iVar4 + param_2;
          }
          if (bVar6) {
            *(int *)(iVar3 + 8) = iVar4;
          }
          iVar4 = *(int *)(iVar3 + 0xc);
          bVar6 = iVar4 != 0;
          if (bVar6) {
            iVar4 = iVar4 + param_2;
          }
          if (bVar6) {
            *(int *)(iVar3 + 0xc) = iVar4;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < (uint)piVar2[2]);
      }
      DAT_00095728 = DAT_00095728 + uVar5;
      DAT_0009572c = DAT_0009572c + 1;
    }
    param_1 = param_1 + 1;
    piVar2 = *param_1;
  } while (piVar2 != (int *)0x0);
  return;
}



void FUN_00004368(uint param_1,int *param_2,int param_3)

{
  undefined **ppuVar1;
  int iVar2;
  
  *param_2 = *param_2 + param_3;
  iVar2 = param_2[1];
  if (iVar2 != 0) {
    param_3 = param_3 + iVar2;
  }
  if (iVar2 != 0) {
    param_2[1] = param_3;
  }
  if (param_2[3] == 2) {
    ppuVar1 = &PTR_FUN_00004752_1_00092054;
  }
  else {
    ppuVar1 = &PTR_FUN_000040b6_1_00091bc8;
  }
  if (0x14 < param_1) {
    return;
  }
  *(uint *)(&DAT_00095620 + param_1 * 0xc) = param_1;
  *(undefined ***)(&DAT_00095624 + param_1 * 0xc) = ppuVar1;
  *(int **)(&DAT_00095628 + param_1 * 0xc) = param_2;
  return;
}



int FUN_000043f8(int param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = param_1 != 0;
  if (bVar3) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x14);
  }
  bVar1 = (code *)UNRECOVERED_JUMPTABLE != (code *)0x0;
  if (bVar3 && bVar1) {
    UNRECOVERED_JUMPTABLE = *(undefined **)((code *)UNRECOVERED_JUMPTABLE + 8);
  }
  if ((!bVar3 || !bVar1) || (code *)UNRECOVERED_JUMPTABLE == (code *)0x0) {
    param_1 = 0;
  }
  if ((bVar3 && bVar1) && (code *)UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x0000440a. Too many branches
                    // WARNING: Treating indirect jump as call
    iVar2 = (*(code *)UNRECOVERED_JUMPTABLE)();
    return iVar2;
  }
  return param_1;
}



int FUN_0000440c(int param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = param_1 != 0;
  if (bVar3) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x14);
  }
  bVar1 = (code *)UNRECOVERED_JUMPTABLE != (code *)0x0;
  if (bVar3 && bVar1) {
    UNRECOVERED_JUMPTABLE = *(undefined **)((code *)UNRECOVERED_JUMPTABLE + 0xc);
  }
  if ((!bVar3 || !bVar1) || (code *)UNRECOVERED_JUMPTABLE == (code *)0x0) {
    param_1 = 0;
  }
  if ((bVar3 && bVar1) && (code *)UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x0000441e. Too many branches
                    // WARNING: Treating indirect jump as call
    iVar2 = (*(code *)UNRECOVERED_JUMPTABLE)();
    return iVar2;
  }
  return param_1;
}



undefined4 FUN_00004420(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == 8) {
    if (*(int *)(param_1 + 0x18) == 0) {
      return 0;
    }
  }
  else {
    piVar1 = *(int **)(param_1 + 0x14);
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    switch(param_2) {
    case 0:
      if (*piVar1 == 0) {
        return 0;
      }
      break;
    case 1:
      if (piVar1[1] == 0) {
        return 0;
      }
      break;
    case 2:
      if (piVar1[4] == 0) {
        return 0;
      }
      break;
    case 3:
      if (piVar1[4] == 0) {
        return 0;
      }
      break;
    case 4:
      if (piVar1[3] == 0) {
        return 0;
      }
      break;
    case 5:
      if (piVar1[2] == 0) {
        return 0;
      }
      break;
    case 6:
      if (piVar1[5] == 0) {
        return 0;
      }
      break;
    case 7:
      if (piVar1[7] == 0) {
        return 0;
      }
      break;
    default:
      return 0;
    }
  }
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_000044a4(void)

{
  return (uint)(_DAT_604b3000 << 0x1b) >> 0x1f;
}



int FUN_000044b4(int param_1,undefined *UNRECOVERED_JUMPTABLE)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = param_1 != 0;
  if (bVar3) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 8);
  }
  bVar1 = (code *)UNRECOVERED_JUMPTABLE != (code *)0x0;
  if (bVar3 && bVar1) {
    UNRECOVERED_JUMPTABLE = *(undefined **)((code *)UNRECOVERED_JUMPTABLE + 8);
  }
  if ((!bVar3 || !bVar1) || (code *)UNRECOVERED_JUMPTABLE == (code *)0x0) {
    param_1 = 0;
  }
  if ((bVar3 && bVar1) && (code *)UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x000044c6. Too many branches
                    // WARNING: Treating indirect jump as call
    iVar2 = (*(code *)UNRECOVERED_JUMPTABLE)();
    return iVar2;
  }
  return param_1;
}



void FUN_000044c8(void)

{
  int iVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  
  FUN_000042d8((int **)&PTR_DAT_00091e14,DAT_00091750);
  iVar1 = DAT_00091750;
  ppuVar3 = &PTR_PTR_s_VDD_BIMC_00091e0c;
  if (PTR_PTR_s_VDD_BIMC_00091e0c != (undefined *)0x0) {
    do {
      puVar2 = DAT_00095720;
      puVar4 = *ppuVar3;
      if (puVar4 != (undefined *)0x0) {
        DAT_00095720 = puVar4;
        *(int *)(puVar4 + 4) = *(int *)(puVar4 + 4) + iVar1;
        *(undefined **)(DAT_00095720 + 0xc) = puVar2;
        DAT_00095730 = DAT_00095730 + 1;
      }
      ppuVar3 = ppuVar3 + 1;
    } while (*ppuVar3 != (undefined *)0x0);
    return;
  }
  return;
}



void FUN_000044ec(void)

{
  FUN_00004368(2,(int *)&DAT_00091754,DAT_00091750);
  FUN_00004368(3,(int *)&DAT_00091764,DAT_00091750);
  FUN_00004368(8,(int *)&DAT_00091774,DAT_00091750);
  return;
}



void FUN_00004588(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint **ppuVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  
  ppuVar3 = *(uint ***)(param_1 + 8);
  puVar1 = *ppuVar3;
  uVar5 = *puVar1 & 0x100000;
  bVar7 = (~*puVar1 & 7) == 0;
  if (bVar7) {
    *puVar1 = *puVar1 & 0xfffffff8;
  }
  uVar4 = **ppuVar3;
  if (uVar5 != 0) {
    uVar4 = uVar4 & 0xffefffff;
    **ppuVar3 = uVar4;
  }
  (*ppuVar3)[1] = *(uint *)(param_2 + 0x10);
  (*ppuVar3)[2] = *(uint *)(param_2 + 0x20);
  (*ppuVar3)[3] = *(uint *)(param_2 + 0x24);
  iVar6 = *(int *)(param_2 + 4);
  uVar2 = (*ppuVar3)[4] & 0xfecf8cff;
  if (iVar6 != 1) {
    if (iVar6 == 2) {
      uVar2 = uVar2 | 0x100000;
    }
    else {
      if (iVar6 == 3) {
        uVar2 = uVar2 | 0x200000;
      }
    }
  }
  if (*(int *)(param_2 + 8) - 1U < 8) {
    uVar2 = *(int *)(param_2 + 8) * 0x1000 - 0x1000U & 0x7000 | uVar2;
  }
  iVar6 = *(int *)(param_2 + 0xc);
  if ((iVar6 == 2 || iVar6 == 4) || (iVar6 == 8 || iVar6 == 0x10)) {
    uVar2 = iVar6 * 0x100 - 0x100U | uVar2;
  }
  bVar8 = *(int *)(param_2 + 0x20) == 0;
  if (bVar8) {
    param_2 = *(int *)(param_2 + 0x24);
  }
  if (!bVar8 || param_2 != 0) {
    uVar2 = uVar2 | 0x1000000;
  }
  (*ppuVar3)[4] = uVar2 | 1;
  if (uVar5 != 0) {
    **ppuVar3 = uVar4 | 0x200000;
    **ppuVar3 = uVar4 & 0xfff000ff | 0x304000;
    **ppuVar3 = uVar4 & 0xffd000ff | 0x104000;
  }
  if (!bVar7) {
    return;
  }
  if (uVar5 != 0) {
    return;
  }
  ppuVar3 = *(uint ***)(param_1 + 8);
  puVar1 = *ppuVar3;
  if ((~*puVar1 & 7) == 0) {
    return;
  }
  uVar4 = *puVar1;
  *puVar1 = uVar4 | 2;
  FUN_00003a44();
  **ppuVar3 = uVar4 | 6;
  FUN_00003a44();
  uVar5 = **ppuVar3;
  while (-1 < (int)uVar5) {
    FUN_00003a44();
    uVar5 = **ppuVar3;
  }
  **ppuVar3 = uVar4 | 7;
  return;
}



void FUN_00004752(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint **ppuVar4;
  
  ppuVar4 = *(uint ***)(param_1 + 8);
  puVar1 = *ppuVar4;
  if ((~*puVar1 & 7) != 0) {
    uVar3 = *puVar1;
    *puVar1 = uVar3 | 2;
    FUN_00003a44();
    **ppuVar4 = uVar3 | 6;
    FUN_00003a44();
    uVar2 = **ppuVar4;
    while (-1 < (int)uVar2) {
      FUN_00003a44();
      uVar2 = **ppuVar4;
    }
    **ppuVar4 = uVar3 | 7;
    return;
  }
  return;
}



void FUN_000047a4(int param_1)

{
  uint **ppuVar1;
  
  ppuVar1 = *(uint ***)(param_1 + 8);
  *ppuVar1[1] = *ppuVar1[1] | (uint)ppuVar1[2];
  if ((**ppuVar1 & 0x40000000) != 0) {
    return;
  }
  do {
    FUN_00003a44();
  } while ((**ppuVar1 & 0x40000000) == 0);
  return;
}



void FUN_000047f4(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = param_1[1];
  *(int *)(*(int *)(param_1 + 8) + 0x44) = (uint)*param_1 * 0x4b00;
  uVar2 = *(uint *)(*(int *)(param_1 + 8) + 0x90);
  if (bVar1 == 0) {
    uVar2 = uVar2 & 0xff7ffff7;
  }
  else {
    uVar2 = uVar2 & 0xff7fffff | 8;
  }
  *(uint *)(*(int *)(param_1 + 8) + 0x90) = uVar2;
  return;
}



void FUN_00004822(int param_1)

{
  *(uint *)(*(int *)(param_1 + 8) + 0x94) = (uint)*(byte *)(param_1 + 5);
  *(uint *)(*(int *)(param_1 + 8) + 0x48) =
       (uint)*(byte *)(param_1 + 4) | (uint)*(byte *)(param_1 + 3) << 6;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004838(void)

{
  DAT_00090624 = (_DAT_604a8000 << 6) >> 0x18;
  _DAT_604a8000 = (_DAT_604a8000 & 0xc003fff | 0x140002) & 0xffc3ffd | 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000488c(void)

{
  _DAT_604a8000 = _DAT_604a8000 & 0xc003ffd | (DAT_00090624 & 0xff) << 0x12 | 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_000048e0(void)

{
  _DAT_604a0070 = _DAT_604a0070 & (uint)&DAT_000901fe | 0x64e01;
  _DAT_604a00b4 = 0;
  _DAT_604a00b8 = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004908(int param_1)

{
  if (param_1 == 0) {
    if (*(int *)(DAT_000941fc + 0x10) == 0) {
      return;
    }
    _DAT_604a0070 = _DAT_604a0070 & 0xf5fbf | 0x80;
  }
  else {
    if (*(int *)(DAT_000941fc + 0x10) == 0) {
      return;
    }
    _DAT_604a0070 = _DAT_604a0070 & 0xf5fff | 0xc0;
  }
  return;
}



void FUN_00004958(undefined param_1)

{
  DAT_00090620 = param_1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004abc(int param_1,int param_2)

{
  _DAT_604a00c4 = (uint)(param_1 == 0);
  if (param_2 == 0) {
    _DAT_604a00c4 = _DAT_604a00c4 | 2;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004adc(void)

{
  _DAT_604a0070 = _DAT_604a0070 & 0xc0;
  _DAT_604a0080 = 1;
  _DAT_604a00b4 = 0;
  _DAT_604a00b8 = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004af8(int param_1)

{
  uint uVar1;
  
  uVar1 = 1;
  *(int *)(DAT_000941fc + 0x20) = param_1;
  if (param_1 != 0) {
    uVar1 = 3;
  }
  _DAT_604a00bc = _DAT_604a00bc & ~uVar1 & 0x1f | param_1 != 0 & uVar1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004b30(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 2;
  uVar2 = 0;
  *(int *)(DAT_000941fc + 0x24) = param_1;
  if (param_1 != 0) {
    uVar1 = 3;
    uVar2 = 2;
  }
  _DAT_604a00bc = _DAT_604a00bc & ~uVar1 & 0x1f | uVar2 & uVar1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004b68(uint param_1)

{
  _DAT_604a00c0 = _DAT_604a00c0 & 8 | param_1 & 7;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004b80(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = 0x1100;
  }
  _DAT_604a0070 = uVar1 | _DAT_604a0070 & 0xf4eff;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int FUN_00004bb4(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  uVar2 = 0;
  uVar6 = ((uint)(_DAT_604a0060 << 0x18) >> 0x1c) + 1;
  if (uVar6 != 0) {
    bVar7 = (uVar6 & 1) != 0;
    if (bVar7) {
      uVar2 = (uint)*(ushort *)(&DAT_00090640 + (_DAT_604a0030 >> 0x1c) * 2);
    }
    uVar4 = (uint)bVar7;
    iVar5 = 0;
    uVar3 = uVar6 >> 1;
    while (uVar3 != 0) {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 2;
      uVar2 = uVar2 + *(ushort *)(&DAT_00090640 + (*(uint *)(&DAT_604a0030 + iVar1) >> 0x1c) * 2);
      iVar5 = iVar5 + (uint)*(ushort *)
                             (&DAT_00090640 + (*(uint *)(&DAT_604a0034 + iVar1) >> 0x1c) * 2);
      uVar3 = uVar3 - 1;
    }
    uVar2 = uVar2 + iVar5;
  }
  return ((uVar2 + uVar6 * 3) * 0x4b00) / 1000 + 0x6de;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int FUN_00004c28(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  uVar2 = 0;
  uVar6 = (_DAT_604a0060 & 0xf) + 1;
  if (uVar6 != 0) {
    bVar7 = (uVar6 & 1) != 0;
    if (bVar7) {
      uVar2 = (uint)*(ushort *)(&DAT_00090640 + (_DAT_604a0000 >> 0x1c) * 2);
    }
    uVar4 = (uint)bVar7;
    iVar5 = 0;
    uVar3 = uVar6 >> 1;
    while (uVar3 != 0) {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 2;
      uVar2 = uVar2 + *(ushort *)(&DAT_00090640 + (*(uint *)(&DAT_604a0000 + iVar1) >> 0x1c) * 2);
      iVar5 = iVar5 + (uint)*(ushort *)
                             (&DAT_00090640 + (*(uint *)(&DAT_604a0004 + iVar1) >> 0x1c) * 2);
      uVar3 = uVar3 - 1;
    }
    uVar2 = uVar2 + iVar5;
  }
  iVar5 = FUN_00004ccc();
  return ((uVar2 + uVar6 * 3) * 0x4b00) / 1000 + (iVar5 + *DAT_000941fc) * 0x24a + 0x1006 +
         (_DAT_604a0078 & 0xffff) * 0x24a + DAT_000941fc[1];
}



undefined4 FUN_00004ccc(void)

{
  return DAT_00090618;
}



void FUN_00004cd8(uint param_1,undefined4 *param_2)

{
  if (1 < param_1) {
    return;
  }
  *param_2 = (&DAT_00090638)[param_1];
  return;
}



void FUN_00004cec(undefined4 *param_1)

{
  undefined *puVar1;
  int *piVar2;
  
  DAT_000941fc = &DAT_00091970;
  FUN_00004db4();
  puVar1 = DAT_000941fc;
  piVar2 = (int *)(DAT_000941fc + 0x28);
  FUN_00004abc(*(int *)(DAT_000941fc + 0x14),*(int *)(DAT_000941fc + 0x18));
  FUN_00004af8(*(int *)(puVar1 + 0x20));
  FUN_00004b30(*(int *)(puVar1 + 0x24));
  FUN_00004b80(*(int *)(puVar1 + 0x1c));
  FUN_00004d90(*piVar2);
  FUN_00004b68((uint)(byte)puVar1[0x2c]);
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0x4d3c;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004d48(void)

{
  int *piVar1;
  
  piVar1 = DAT_000941fc;
  if (DAT_000904cb == '\x01') {
    DAT_00090618 = 0x82;
    FUN_00005074();
    FUN_0000f54c(0,1,0x82);
  }
  else {
    DAT_00090618 = 0;
  }
  if (*piVar1 + DAT_00090618 == 0) {
    return;
  }
  _DAT_604a0078 = _DAT_604a0078 & 0xffff | (*piVar1 + DAT_00090618) * 0x10000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004d90(int param_1)

{
  _DAT_604a00c0 = _DAT_604a00c0 & 7 | (uint)(param_1 != 0) << 3;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00004db4(void)

{
  _DAT_00080004 = _DAT_00080004 & 7 | 1;
  DAT_00090638 = 0;
  DAT_0009063c = 0;
  _DAT_604a00f4 = 0x24a0000;
  _DAT_604a1000 = _DAT_604a1000 & 0x102 | 1;
  _DAT_604a4004 = 1;
  _DAT_604a4040 = 0x21;
  _DAT_61948004 = _DAT_61948004 & 1;
  _DAT_61948014 = 1;
  _DAT_61948018 = 0x10000;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00005074(void)

{
  _DAT_604a00f4 = 38400000;
  return;
}



void FUN_00005084(void)

{
  FUN_0000a7ae(DAT_000919b8,0xff);
  return;
}



void FUN_00005094(uint param_1)

{
  byte bVar1;
  uint *puVar2;
  
  bVar1 = (&DAT_000919ca)[param_1 * 3];
  if (bVar1 != 0xff) {
    puVar2 = (uint *)(DAT_000919b0 + (uint)(bVar1 >> 5) * 4);
    *puVar2 = *puVar2 & ~(1 << ((uint)bVar1 & 0x1f));
  }
  puVar2 = (uint *)(DAT_000919ac + (param_1 >> 5) * 4);
  *puVar2 = *puVar2 & ~(1 << (param_1 & 0x1f));
  return;
}



void FUN_000050ec(uint param_1)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  
  bVar1 = (&DAT_000919ca)[param_1 * 3];
  if (bVar1 != 0xff) {
    puVar3 = (uint *)(DAT_000919b0 + (uint)(bVar1 >> 5) * 4);
    *puVar3 = 1 << ((uint)bVar1 & 0x1f) | *puVar3;
  }
  uVar2 = 1 << (param_1 & 0x1f);
  *(uint *)(DAT_000919b8 + (param_1 >> 5) * 4) = uVar2;
  puVar3 = (uint *)(DAT_000919ac + (param_1 >> 5) * 4);
  *puVar3 = uVar2 | *puVar3;
  return;
}



uint FUN_00005148(uint param_1,uint *param_2)

{
  if (param_1 < 0x40) {
    *param_2 = param_1;
  }
  return (uint)(param_1 < 0x40);
}



void FUN_00005154(uint param_1,uint param_2,uint param_3,uint param_4,undefined *param_5)

{
  uint uVar1;
  
  uVar1 = (uint)((param_1 & param_4) != 0);
  if ((param_2 & param_4) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_3 & param_4) != 0) {
    uVar1 = uVar1 | 4;
  }
  *param_5 = (&DAT_0001b378)[uVar1];
  return;
}



void FUN_00005184(undefined4 *param_1)

{
  *param_1 = 2;
  return;
}



void FUN_0000518c(undefined4 *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  
  uVar5 = 0;
  do {
    iVar3 = uVar5 * 3;
    bVar1 = (&DAT_000919c8)[iVar3];
    uVar9 = uVar5 >> 5;
    puVar7 = (uint *)(DAT_000919bc + uVar9 * 4);
    bVar2 = (&DAT_0001b378)[bVar1];
    uVar8 = *puVar7;
    uVar6 = 1 << (uVar5 & 0x1f);
    if ((bVar2 & 1) == 0) {
      uVar8 = uVar8 & ~uVar6;
    }
    else {
      uVar8 = uVar8 | uVar6;
    }
    *puVar7 = uVar8;
    puVar7 = (uint *)(DAT_000919c0 + uVar9 * 4);
    uVar8 = *puVar7;
    if ((bVar2 & 2) == 0) {
      uVar8 = uVar8 & ~uVar6;
    }
    else {
      uVar8 = uVar8 | uVar6;
    }
    *puVar7 = uVar8;
    puVar7 = (uint *)(DAT_000919c4 + uVar9 * 4);
    uVar8 = *puVar7;
    if ((bVar2 & 4) == 0) {
      uVar6 = uVar8 & ~uVar6;
    }
    else {
      uVar6 = uVar6 | uVar8;
    }
    *puVar7 = uVar6;
    uVar5 = uVar5 + 1;
    (&DAT_000919c8)[iVar3] = bVar1;
    uVar4 = DAT_000919ac;
  } while (uVar5 < 0x40);
  FUN_000005cc(DAT_000919b0,8);
  FUN_000005cc(uVar4,8);
  FUN_0000a7ae(DAT_000919b8,0xff);
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0x523c;
  }
  return;
}



uint FUN_0000524c(int param_1,uint *param_2)

{
  byte bVar1;
  
  bVar1 = (&DAT_000919c9)[param_1 * 3];
  if (bVar1 != 0xff) {
    *param_2 = (uint)bVar1;
  }
  return (uint)(bVar1 != 0xff);
}



void FUN_00005268(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  bVar1 = (&DAT_0001b378)[param_2];
  uVar2 = 1 << (param_1 & 0x1f);
  uVar3 = param_1 >> 5;
  puVar4 = (uint *)(DAT_000919bc + uVar3 * 4);
  uVar5 = *puVar4;
  if ((bVar1 & 1) == 0) {
    uVar5 = uVar5 & ~uVar2;
  }
  else {
    uVar5 = uVar5 | uVar2;
  }
  *puVar4 = uVar5;
  puVar4 = (uint *)(DAT_000919c0 + uVar3 * 4);
  uVar5 = *puVar4;
  if ((bVar1 & 2) == 0) {
    uVar5 = uVar5 & ~uVar2;
  }
  else {
    uVar5 = uVar5 | uVar2;
  }
  *puVar4 = uVar5;
  puVar4 = (uint *)(DAT_000919c4 + uVar3 * 4);
  uVar3 = *puVar4;
  if ((bVar1 & 4) == 0) {
    uVar2 = uVar3 & ~uVar2;
  }
  else {
    uVar2 = uVar2 | uVar3;
  }
  *puVar4 = uVar2;
  (&DAT_000919c8)[param_1 * 3] = (char)param_2;
  return;
}



void FUN_000052e0(int param_1)

{
  byte bVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return;
  }
  bVar1 = *(byte *)(param_1 + 0x28);
  uVar2 = (uint)bVar1;
  if (3 < bVar1) {
    uVar2 = 0;
  }
  if (3 < bVar1) {
    *(undefined *)(param_1 + 0x28) = (char)uVar2;
  }
  else {
    if (uVar2 == 3) {
      if (*(int *)(param_1 + 0x30) == 0) {
        *(undefined4 *)(param_1 + 0x2c) = DAT_00091808;
        *(undefined4 *)(param_1 + 0x30) = DAT_0009180c;
        return;
      }
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x2c) = (&DAT_00091808)[uVar2 * 2];
  *(undefined4 *)(param_1 + 0x30) = (&DAT_0009180c)[uVar2 * 2];
  return;
}



int * FUN_000052ea(int *param_1,uint param_2,uint *param_3,uint param_4)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  bVar10 = param_1 != (int *)0x0;
  if (bVar10) {
    param_4 = param_1[2];
  }
  if (bVar10 && param_4 < param_2 || (!bVar10 || param_4 == param_2)) {
    return param_1;
  }
  if (param_3 == (uint *)0x0) {
    return param_1;
  }
  uVar8 = param_1[4];
  if (uVar8 != 0) {
    piVar2 = *(int **)(param_1[5] + param_2 * 4);
    if (((uint)piVar2 & 10) != 0) {
      uVar6 = *param_3;
      uVar7 = param_3[1];
      uVar3 = 0;
      if ((uVar6 | uVar7) != 0) {
        lVar1 = (ulonglong)(uVar8 * 2) * 0xffff;
        uVar3 = (uint)lVar1;
        uVar11 = FUN_000001b0(uVar3 + 0x3e7ff,
                              (uint)CARRY4(uVar8,uVar8) * 0xffff + (int)((ulonglong)lVar1 >> 0x20) +
                              (uint)(0xfffc1800 < uVar3),0x3e800,0);
        lVar1 = (uVar11 >> 0x20) * 1000000;
        uVar3 = uVar6;
        uVar4 = uVar7;
        if ((int)uVar11 * 1000000 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(uVar6 < (uint)lVar1) <=
            uVar7) {
          lVar1 = (ulonglong)(uVar8 * 2) * 0xffff;
          uVar3 = (uint)lVar1;
          uVar11 = FUN_000001b0(uVar3 + 0x3e7ff,
                                (uint)CARRY4(uVar8,uVar8) * 0xffff + (int)((ulonglong)lVar1 >> 0x20)
                                + (uint)(0xfffc1800 < uVar3),0x3e800,0);
          lVar1 = (uVar11 >> 0x20) * 1000000;
          uVar3 = (uint)lVar1;
          uVar4 = (int)uVar11 * 1000000 + (int)((ulonglong)lVar1 >> 0x20);
        }
        uVar9 = uVar4 << 8 | uVar3 >> 0x18;
        uVar4 = uVar8 * 2000;
        uVar3 = uVar3 * 0x100;
        uVar12 = FUN_000001b0((uVar3 + uVar4) - 1,
                              uVar9 + CARRY4(uVar3,uVar4) + ((uint)(uVar3 + uVar4 != 0) - 1),uVar4,0
                             );
        if ((uint)uVar12 < (uint)((uint)((ulonglong)uVar12 >> 0x20) < 0xffff)) {
          uVar12 = FUN_000001b0((uVar3 + uVar4) - 1,
                                uVar9 + CARRY4(uVar3,uVar4) + ((uint)(uVar3 + uVar4 != 0) - 1),uVar4
                                ,0);
          uVar3 = (uint)((ulonglong)uVar12 >> 0x20);
        }
        else {
          uVar3 = 0xffff;
        }
      }
      uVar4 = 0;
      uVar9 = param_3[2];
      if ((uVar6 | uVar7) != 0) {
        lVar1 = (ulonglong)(uVar8 * 2) * 0xffff;
        uVar4 = (uint)lVar1;
        uVar11 = FUN_000001b0(uVar4 + 0x3e7ff,
                              (uint)CARRY4(uVar8,uVar8) * 0xffff + (int)((ulonglong)lVar1 >> 0x20) +
                              (uint)(0xfffc1800 < uVar4),0x3e800,0);
        lVar1 = (uVar11 >> 0x20) * 1000000;
        if ((int)uVar11 * 1000000 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(uVar6 < (uint)lVar1) <=
            uVar7) {
          lVar1 = (ulonglong)(uVar8 * 2) * 0xffff;
          uVar7 = (uint)lVar1;
          uVar11 = FUN_000001b0(uVar7 + 0x3e7ff,
                                (uint)CARRY4(uVar8,uVar8) * 0xffff + (int)((ulonglong)lVar1 >> 0x20)
                                + (uint)(0xfffc1800 < uVar7),0x3e800,0);
          lVar1 = (uVar11 >> 0x20) * 1000000;
          uVar6 = (uint)lVar1;
          uVar7 = (int)uVar11 * 1000000 + (int)((ulonglong)lVar1 >> 0x20);
        }
        uVar12 = FUN_000001b0(uVar6 + 99999,uVar7 + (0xfffe7960 < uVar6),100000,0);
        uVar7 = (uint)((ulonglong)uVar12 >> 0x20);
        uVar11 = (ulonglong)uVar7 * (ulonglong)uVar9;
        lVar1 = (uVar11 & 0xffffffff) * (ulonglong)uVar8;
        uVar6 = (uint)lVar1;
        uVar13 = FUN_000001b0(uVar6 + 0x8967ffff,
                              ((int)uVar12 * uVar9 + (int)(uVar11 >> 0x20)) * uVar8 +
                              (int)((ulonglong)lVar1 >> 0x20) + (uint)(0x76980000 < uVar6) + 9,
                              0x89680000,9);
        if ((uint)uVar13 < (uint)((uint)((ulonglong)uVar13 >> 0x20) < 0x3ff)) {
          uVar11 = (ulonglong)uVar7 * (ulonglong)uVar9;
          lVar1 = (uVar11 & 0xffffffff) * (ulonglong)uVar8;
          uVar7 = (uint)lVar1;
          uVar12 = FUN_000001b0(uVar7 + 0x8967ffff,
                                ((int)uVar12 * uVar9 + (int)(uVar11 >> 0x20)) * uVar8 +
                                (int)((ulonglong)lVar1 >> 0x20) + (uint)(0x76980000 < uVar7) + 9,
                                0x89680000,9);
          uVar4 = (uint)((ulonglong)uVar12 >> 0x20);
        }
        else {
          uVar4 = 0x3ff;
        }
      }
      iVar5 = param_1[0xc] * param_2 + 0xc;
      uVar8 = *(uint *)(param_1[0xb] + *param_1 + iVar5) & 3;
      if (uVar8 == 3 || uVar8 == 1) {
        *(undefined4 *)(param_1[0xb] + *param_1 + iVar5) = 0;
      }
      *(uint *)(*param_1 + param_1[0xb] + param_1[0xc] * param_2 + 0x10) = uVar3 & 0xffff;
      *(uint *)(*param_1 + param_1[0xb] + param_1[0xc] * param_2 + 0x14) = uVar4 & 0x3ff;
      *(uint *)(*param_1 + param_1[0xb] + param_1[0xc] * param_2 + 0xc) = uVar8;
      return *(int **)(*param_1 + param_1[0xb] + param_1[0xc] * param_2 + 0xc);
    }
    return piVar2;
  }
  return param_1;
}



int * FUN_00005300(int *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = param_1 != (int *)0x0;
  if (bVar2) {
    param_4 = param_1[2];
  }
  if (bVar2 && param_4 < param_2 || (!bVar2 || param_4 == param_2)) {
    return param_1;
  }
  uVar1 = *(uint *)(param_1[5] + param_2 * 4);
  if (uVar1 == 1) {
    return param_1;
  }
  if (param_3 < 4) {
    if ((uVar1 & 1 << param_3) != 0) {
      *(uint *)(*param_1 + param_1[0xb] + param_1[0xc] * param_2 + 0xc) = param_3 & 3;
      return *(int **)(*param_1 + param_1[0xb] + param_2 * param_1[0xc] + 0xc);
    }
    return param_1;
  }
  return param_1;
}



int * FUN_00005310(int *param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  uint in_r12;
  int iVar1;
  bool bVar2;
  
  bVar2 = param_1 != (int *)0x0;
  if (bVar2) {
    in_r12 = param_1[2];
  }
  if ((!bVar2 || param_2 <= in_r12) && (bVar2 && in_r12 != param_2)) {
    if (param_4 != (uint *)0x0) {
      iVar1 = param_1[0xc] * param_2 + 8;
      *(uint *)(*param_1 + param_1[0xb] + iVar1) =
           *(uint *)(*param_1 + param_1[0xb] + iVar1) & 3 | (*param_4 & 3) << 2;
      iVar1 = param_2 * param_1[0xc] + 8;
      *(uint *)(param_1[0xb] + *param_1 + iVar1) =
           param_4[1] & 3 | *(uint *)(param_1[0xb] + *param_1 + iVar1) & 0xc;
      return (int *)*(undefined4 *)(*param_1 + param_1[0xb] + param_2 * param_1[0xc] + 8);
    }
    return param_1;
  }
  return param_1;
}



void FUN_00005328(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 < *(byte *)(param_1 + 2)) {
    uVar2 = 1 << (param_2 & 0x1f);
    puVar1 = (uint *)(*(int *)(param_1 + 8) + (param_2 >> 5) * 4 + 0x30);
    uVar3 = *puVar1;
    if (param_3 == 0) {
      uVar2 = uVar3 & ~uVar2;
    }
    else {
      uVar2 = uVar2 | uVar3;
    }
    *puVar1 = uVar2;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000535c(int param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x30) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x34) = 0xffffffff;
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x30) = 0;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x34) = 0;
  return;
}



void FUN_00005376(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x110) = 0x7f;
  return;
}



void FUN_00005380(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  bVar1 = *(byte *)(param_2 + 0x84);
  iVar4 = param_2 + (uint)bVar1 * 0x30;
  *(uint *)(iVar4 + 0x24) = *(uint *)(*(int *)(param_1 + 8) + 0x48) & 0xfff;
  *(uint *)(iVar4 + 0x28) = *(uint *)(*(int *)(param_1 + 8) + 0x80) & 0x1fff;
  uVar2 = 0;
  do {
    uVar3 = uVar2 + 1 & 0xff;
    ((uint *)(iVar4 + 0x24))[uVar2 + 2] = *(uint *)(*(int *)(param_1 + 8) + uVar2 * 4 + 0x60);
    uVar2 = uVar3;
  } while (uVar3 < 8);
  *(uint *)(iVar4 + 0x4c) = *(uint *)(*(int *)(param_1 + 8) + 0x100) & 0x7f;
  *(uint *)(iVar4 + 0x50) = *(uint *)(*(int *)(param_1 + 8) + 0x114) & 0x7f;
  *(byte *)(param_2 + 0x84) = bVar1 ^ 1;
  return;
}



void FUN_000053e6(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (param_2 != 0) {
    *(uint *)(iVar1 + 0x90) = *(uint *)(iVar1 + 0x90) & 0xff7fffef;
    *(uint *)(*(int *)(param_1 + 8) + 0x90) =
         *(uint *)(*(int *)(param_1 + 8) + 0x90) & 0xff7fffff | 1;
    return;
  }
  *(uint *)(iVar1 + 0x90) = *(uint *)(iVar1 + 0x90) & 0xff7ffffe;
  return;
}



void FUN_00005420(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)(*(int *)(param_1 + 8) + 0x100);
  uVar2 = *puVar1;
  if (param_3 == 0) {
    param_2 = uVar2 & ~param_2;
  }
  else {
    param_2 = param_2 | uVar2;
  }
  *puVar1 = param_2;
  return;
}



undefined * FUN_00005438(uint *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_00000660(param_1,(uint *)(&PTR_s_vddcx_0001bd34)[iVar2 * 0x16]);
    if (iVar1 == 0) {
      return &DAT_0001bd28 + iVar2 * 0x58;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



uint FUN_00005478(int param_1)

{
  return *(uint *)(*(int *)(param_1 + 8) + 0x114) & 0x7f;
}



void FUN_00005484(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 < *(byte *)(param_1 + 2)) {
    uVar2 = 1 << (param_2 & 0x1f);
    puVar1 = (uint *)(*(int *)(param_1 + 8) + (param_2 >> 5) * 4 + 0x20);
    uVar3 = *puVar1;
    if (param_3 == 0) {
      uVar2 = uVar3 & ~uVar2;
    }
    else {
      uVar2 = uVar2 | uVar3;
    }
    *puVar1 = uVar2;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_000054b8(int param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x20) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x24) = 0xffffffff;
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x20) = 0;
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x24) = 0;
  return;
}



void FUN_000054d2(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (param_2 != 0) {
    *(undefined4 *)(iVar1 + 0x98) = 1;
  }
  if (param_2 == 0) {
    *(undefined4 *)(iVar1 + 0x9c) = 1;
  }
  return;
}



void FUN_000054e4(int param_1,byte *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    if (iVar2 < 100) {
      param_3 = *(uint *)(param_1 + 8);
    }
    if (iVar1 + -99 < 0 == SBORROW4(iVar2,100)) goto LAB_0000552c;
    do {
    } while ((*(uint *)(param_3 + 0xa0) & 0x80000) != 0);
    iVar1 = iVar2;
  } while ((((*(uint *)(param_3 + 0xa0) & 0x80000) != 0) ||
           ((*(uint *)(param_3 + 0xa0) & 0x80000) != 0)) ||
          (param_3 = *(uint *)(param_3 + 0xa0), (param_3 & 0x80000) != 0));
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xa0) << 0xc;
  *param_2 = (byte)((uint)iVar1 >> 0x1f);
  if (-1 < iVar1) {
    *(ushort *)(param_2 + 2) =
         (ushort)((uint)(*(int *)(*(int *)(param_1 + 8) + 0xa0) << 0xe) >> 0x14);
    param_2[4] = (byte)((uint)(*(int *)(*(int *)(param_1 + 8) + 0xa0) << 0x1a) >> 0x1c);
    param_2[5] = (byte)((uint)(*(int *)(*(int *)(param_1 + 8) + 0xa0) << 0x1e) >> 0x1f);
    param_2[6] = (byte)*(undefined4 *)(*(int *)(param_1 + 8) + 0xa0) & 1;
    param_2[7] = 1;
    return;
  }
LAB_0000552c:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00005566(int param_1,int param_2,int param_3,uint param_4)

{
  *(uint *)(*(int *)(param_1 + 8) + param_2 * 4 + 0x60) = param_4 | param_3 << 0xc;
  return;
}



void FUN_00005576(int param_1,int param_2,undefined param_3)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(param_2 + (uint)*(byte *)(param_2 + 0x20) * 0x10);
  *(undefined *)(puVar2 + 3) = param_3;
  uVar1 = FUN_0001a764();
  puVar2[1] = uVar1;
  puVar2[2] = *(uint *)(*(int *)(param_1 + 8) + 0x140) & 0xfffff7ff;
  *puVar2 = *(uint *)(*(int *)(param_1 + 8) + 0xa0) & 0xfffff;
  *(byte *)(param_2 + 0x20) = ~*(byte *)(param_2 + 0x20) & 1;
  return;
}



void FUN_000055d0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 8);
    uVar2 = *(uint *)(iVar1 + 0x90) & 0xff7ffbff;
  }
  else {
    if (param_2 != 1) {
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    iVar1 = *(int *)(param_1 + 8);
    uVar2 = *(uint *)(iVar1 + 0x90) & 0xff7fffff | 0x400;
  }
  *(uint *)(iVar1 + 0x90) = uVar2;
  return;
}



void FUN_000055fe(int param_1,int param_2)

{
  *(uint *)(*(int *)(param_1 + 8) + 0x90) =
       *(uint *)(*(int *)(param_1 + 8) + 0x90) & 0xff7fffdf | param_2 << 5;
  return;
}



void FUN_00005616(int param_1,int param_2)

{
  *(uint *)(*(int *)(param_1 + 8) + 0x90) =
       *(uint *)(*(int *)(param_1 + 8) + 0x90) & 0xff7fffbf | param_2 << 6;
  return;
}



void FUN_00005630(int param_1,uint param_2)

{
  *(uint *)(*(int *)(param_1 + 8) + 0x4c) =
       (param_2 & 0xf) << 4 | *(uint *)(*(int *)(param_1 + 8) + 0x4c) & 0x1ff0f;
  return;
}



void FUN_00005648(int param_1,uint param_2)

{
  *(uint *)(*(int *)(param_1 + 8) + 0x4c) =
       param_2 & 0xf | *(uint *)(*(int *)(param_1 + 8) + 0x4c) & 0x1fff0;
  return;
}



void FUN_00005660(int param_1,int param_2)

{
  *(uint *)(*(int *)(param_1 + 8) + 0x90) =
       *(uint *)(*(int *)(param_1 + 8) + 0x90) & 0xf7fffff | param_2 << 0x1c;
  return;
}



void FUN_00005678(int param_1,byte param_2,uint param_3)

{
  *(uint *)(*(int *)(param_1 + 8) + 0x80) =
       *(uint *)(*(int *)(param_1 + 8) + 0x80) & 0x1f00 | (uint)param_2;
  *(uint *)(*(int *)(param_1 + 8) + 0x80) =
       *(uint *)(*(int *)(param_1 + 8) + 0x80) & 0xff | (param_3 & 0x1f) << 8;
  return;
}



void FUN_000056a4(int param_1,uint param_2)

{
  *(uint *)(*(int *)(param_1 + 8) + 0x90) =
       (param_2 & 0xf) << 0x18 | *(uint *)(*(int *)(param_1 + 8) + 0x90) & 0xf07fffff;
  return;
}



undefined4 FUN_000056c0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_000939a4;
  uVar2 = DAT_000939a0;
  uVar1 = DAT_0009399c;
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  *param_1 = DAT_00093998;
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  param_1[3] = uVar3;
  return 1;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

undefined4
FUN_00005730(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,int param_5,
            uint param_6,int *param_7)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  bool bVar14;
  byte abStack72 [8];
  undefined4 local_40;
  byte abStack60 [8];
  undefined4 uStack52;
  undefined4 uStack48;
  uint uStack44;
  undefined4 uStack40;
  
  uStack40 = param_4;
  uStack44 = param_3;
  uStack48 = param_2;
  uStack52 = param_1;
  bVar14 = false;
  local_40 = 0;
  if (0xf < param_3) {
    return 0x12;
  }
  if (param_5 == 0 || param_6 == 0) {
    return 0xf;
  }
  if (param_7 == (int *)0x0) {
    param_7 = (int *)(abStack72 + 0x10);
  }
  *param_7 = 0;
  sVar4 = (&DAT_000957d0)[*(uint *)(abStack72 + 0x20) >> 8];
  while( true ) {
    if ((int)sVar4 == -1) {
      return 0x18;
    }
    iVar5 = (int)sVar4 * 3;
    if ((int)(char)(&DAT_000959d0)[iVar5] == param_3) break;
    sVar4 = *(short *)(&DAT_000959d1 + iVar5);
  }
  abStack72[0] = (char)sVar4;
  iVar5 = *(int *)(abStack72 + 0x14);
  bVar13 = iVar5 == 0;
  if (bVar13) {
    iVar5 = 1;
  }
  if (bVar13) {
    *(int *)(abStack72 + 8) = iVar5;
  }
  else {
    bVar14 = iVar5 == 1;
    if (!bVar14) {
      return 3;
    }
  }
  if (param_6 != 0) {
    do {
      iVar5 = DAT_00092018;
      if (bVar14) {
        uVar10 = (uint)abStack72[0];
        uVar6 = *(uint *)(DAT_00092018 + (uint)DAT_000957c8 * 0x1000 + uVar10 * 0x8000 + 0xc00008);
      }
      else {
        uVar10 = (uint)abStack72[0];
        uVar6 = *(uint *)(DAT_00092018 + (uint)DAT_000957c8 * 0x1000 + uVar10 * 0x8000 + 0x400008);
      }
      if ((uVar6 & 1) == 0) {
        return 1;
      }
      uVar6 = param_6;
      if (8 < param_6) {
        uVar6 = 8;
      }
      if (*(int *)(abStack72 + 8) != 0) {
        pbVar1 = abStack72 + 4;
        iVar12 = *param_7 + *(int *)(abStack72 + 0x48);
        uVar7 = 0;
        *(undefined4 *)(abStack72 + 4) = 0;
        uVar11 = uVar6;
        do {
          if (uVar11 == 0) break;
          pbVar1[uVar7] = *(byte *)(iVar12 + uVar7);
          uVar7 = uVar7 + 1;
          uVar11 = uVar11 - 1;
        } while (uVar7 < 4);
        *(undefined4 *)(DAT_00092018 + (uint)DAT_000957c8 * 0x1000 + uVar10 * 0x8000 + 0x400010) =
             *(undefined4 *)(abStack72 + 4);
        if (uVar11 != 0) {
          uVar7 = 0;
          *(undefined4 *)(abStack72 + 4) = 0;
          do {
            uVar11 = uVar11 - 1;
            pbVar1[uVar7] = *(byte *)(iVar12 + uVar7 + 4);
            uVar7 = uVar7 + 1;
            if (3 < uVar7) break;
          } while (uVar11 != 0);
          *(undefined4 *)(iVar5 + (uint)DAT_000957c8 * 0x1000 + uVar10 * 0x8000 + 0x400014) =
               *(undefined4 *)(abStack72 + 4);
        }
      }
      iVar5 = *(int *)(abStack72 + 0x14);
      uVar10 = *(int *)(abStack72 + 0x20) + *param_7 & 0xff;
      if (bVar14) {
        uVar10 = iVar5 << 0x1b | uVar10 << 4;
        puVar8 = (uint *)(DAT_00092018 + (uint)DAT_000957c8 * 0x1000 + (uint)abStack72[0] * 0x8000 +
                         0xc00000);
      }
      else {
        uVar10 = iVar5 << 0x1b | *(int *)(abStack72 + 0x18) << 0x1a | uVar10 << 4;
        puVar8 = (uint *)(DAT_00092018 + (uint)DAT_000957c8 * 0x1000 + (uint)abStack72[0] * 0x8000 +
                         0x400000);
      }
      *puVar8 = uVar6 - 1 | uVar10;
      bVar3 = abStack72[0];
      uVar10 = 0;
      iVar5 = 400;
      do {
        bVar13 = iVar5 == 0;
        iVar5 = iVar5 + -1;
        if (bVar13) break;
        thunk_FUN_0000b1ac(1,abStack72[0]);
        iVar12 = DAT_00092018 + (uint)DAT_000957c8 * 0x1000 + (uint)bVar3 * 0x8000;
        if (bVar14) {
          iVar12 = iVar12 + 0xc00000;
        }
        else {
          iVar12 = iVar12 + 0x400000;
        }
        uVar10 = *(uint *)(iVar12 + 8);
      } while (uVar10 == 0);
      if ((uVar10 & 8) != 0) {
        return 7;
      }
      if ((uVar10 & 1) == 0) {
        if ((*(uint *)((int)&PTR_PTR_LAB_00014184_1_0000a028 + DAT_00092018) & 1) == 0) {
          uVar9 = 8;
        }
        else {
          uVar9 = 2;
        }
        return uVar9;
      }
      if ((uVar10 & 2) != 0) {
        return 5;
      }
      if ((uVar10 & 4) != 0) {
        return 6;
      }
      if (bVar14) {
        iVar5 = *param_7 + *(int *)(abStack72 + 0x48);
        uVar7 = (uint)abStack72[0];
        *(undefined4 *)(abStack72 + 0xc) =
             *(undefined4 *)(DAT_00092018 + (uint)DAT_000957c8 * 0x1000 + uVar7 * 0x8000 + 0xc00018)
        ;
        uVar11 = 0;
        pbVar1 = abStack72 + 0xc;
        uVar10 = uVar6;
        do {
          if (uVar10 == 0) goto LAB_000059d0;
          *(byte *)(iVar5 + uVar11) = pbVar1[uVar11];
          uVar11 = uVar11 + 1;
          uVar10 = uVar10 - 1;
        } while (uVar11 < 4);
        if (uVar10 != 0) {
          *(undefined4 *)(abStack72 + 0xc) =
               *(undefined4 *)
                (DAT_00092018 + (uint)DAT_000957c8 * 0x1000 + uVar7 * 0x8000 + 0xc0001c);
          uVar11 = 0;
          do {
            iVar12 = iVar5 + uVar11;
            pbVar2 = pbVar1 + uVar11;
            uVar11 = uVar11 + 1;
            uVar10 = uVar10 - 1;
            *(byte *)(iVar12 + 4) = *pbVar2;
            if (3 < uVar11) break;
          } while (uVar10 != 0);
        }
      }
LAB_000059d0:
      param_6 = param_6 - uVar6;
      *param_7 = *param_7 + uVar6;
    } while (param_6 != 0);
  }
  return 0;
}



undefined4 FUN_000059f4(int param_1,int param_2,undefined *param_3)

{
  short sVar1;
  int iVar2;
  
  sVar1 = (&DAT_000957d0)[param_2];
  while( true ) {
    if ((int)sVar1 == -1) {
      return 0x18;
    }
    iVar2 = (int)sVar1 * 3;
    if ((int)(char)(&DAT_000959d0)[iVar2] == param_1) break;
    sVar1 = *(short *)(&DAT_000959d1 + iVar2);
  }
  *param_3 = (char)sVar1;
  return 0;
}



void FUN_00005a38(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  *param_1 = *(undefined4 *)(DAT_00092018 + 0xb000);
  iVar1 = DAT_00092018;
  param_1[1] = *(undefined4 *)((int)&PTR_LAB_00007020_1_0000a02c + DAT_00092018);
  param_1[2] = *(undefined4 *)((int)&PTR_PTR_LAB_00014184_1_0000a028 + iVar1);
  return;
}



uint FUN_00005a60(void)

{
  return (uint)DAT_000957c9;
}



int FUN_00005a6c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 extraout_r1;
  undefined2 *puVar5;
  int *piVar6;
  uint uVar7;
  byte *pbVar8;
  
  DAT_000957cc = param_1;
  iVar3 = FUN_00006820();
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar3 = FUN_000068d0(&DAT_000957c8,extraout_r1,param_3,param_4);
  if (iVar3 != 0) {
    return iVar3;
  }
  iVar3 = FUN_000069d4((int)&FUN_00013f8c_1,0);
  DAT_000957c9 = iVar3 == 0;
  puVar5 = (undefined2 *)((int)&DAT_000957cc + 2);
  uVar4 = 0x80;
  do {
    puVar5[1] = 0xffff;
    puVar5 = puVar5 + 2;
    *puVar5 = 0xffff;
    uVar4 = uVar4 - 1;
  } while (uVar4 != 0);
  do {
    piVar6 = (int *)(DAT_00092018 + uVar4 * 4 + 0xf800);
    iVar3 = *piVar6;
    uVar7 = (uint)(*piVar6 << 0x10) >> 0x18;
    if ((&DAT_000957d0)[uVar7] == -1) {
      (&DAT_000957d0)[uVar7] = (short)uVar4;
      (&DAT_000959d0)[uVar4 * 3] = 0xff;
      *(undefined2 *)(&DAT_000959d1 + uVar4 * 3) = 0xffff;
    }
    iVar2 = (int)(short)(&DAT_000957d0)[uVar7] * 3;
    sVar1 = *(short *)(&DAT_000959d1 + iVar2);
    while (pbVar8 = &DAT_000959d0 + iVar2, sVar1 != -1) {
      iVar2 = (int)*(short *)(&DAT_000959d1 + iVar2) * 3;
      sVar1 = *(short *)(&DAT_000959d1 + iVar2);
    }
    if (*pbVar8 != 0xff) {
      *(short *)(&DAT_000959d1 + iVar2) = (short)uVar4;
      pbVar8 = &DAT_000959d0 + uVar4 * 3;
      *(undefined2 *)(&DAT_000959d1 + uVar4 * 3) = 0xffff;
    }
    uVar4 = uVar4 + 1;
    *pbVar8 = (byte)((uint)(iVar3 << 0xc) >> 0x1c);
  } while (uVar4 < 0x80);
  return 0;
}



undefined4 FUN_00005b44(uint param_1,uint param_2)

{
  uint *puVar1;
  
  if (DAT_000957c9 == '\0') {
    return 0xb;
  }
  if ((uint)DAT_000957c8 == (*(uint *)(DAT_00092018 + param_1 * 4 + 0xa700) & 7)) {
    if (param_1 < 0x80) {
      puVar1 = (uint *)(DAT_00092018 + param_1 * 0x1000 + 0x1800000);
      *puVar1 = *puVar1 & 0xfffffffe | param_2 & 1;
      return 0;
    }
    return 0x17;
  }
  return 4;
}



undefined4 FUN_00005b94(void)

{
  int iVar1;
  
  if (((DAT_00091bc0 == 0) || (DAT_00091bc0 = DAT_00091bc0 + -1, DAT_00091bc0 == 0)) &&
     (iVar1 = FUN_00000f94(DAT_00091bc4), iVar1 != 0)) {
    return 2;
  }
  return 0;
}



undefined4 FUN_00005bbc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_r1;
  
  if ((DAT_00091bc0 == 0) &&
     ((iVar1 = FUN_000015c0((uint *)"gcc_prng_ahb_clk",&DAT_00091bc4), iVar1 != 0 ||
      (iVar1 = FUN_000012a0(DAT_00091bc4,extraout_r1,param_3,param_4), iVar1 != 0)))) {
    return 2;
  }
  DAT_00091bc0 = DAT_00091bc0 + 1;
  return 0;
}



undefined4 thunk_FUN_00005b94(void)

{
  undefined4 uVar1;
  
  uVar1 = thunk_FUN_00005b94();
  return uVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_00005c04(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int local_28;
  
  if (param_1 != (int *)0x0 && param_2 != 0) {
    uVar1 = param_2;
    if ((param_2 & 3) != 0) {
      uVar1 = (4 - (param_2 & 3)) + param_2;
    }
    uVar2 = 0;
    if (uVar1 >> 2 != 0) {
      do {
        do {
        } while ((_DAT_60022004 & 1) == 0);
        do {
          local_28 = _DAT_60022000;
        } while (_DAT_60022000 == 0);
        if (uVar2 < (uVar1 >> 2) - 1) {
          *param_1 = _DAT_60022000;
          param_1 = param_1 + 1;
        }
        else {
          if ((param_2 & 3) == 0) {
            *param_1 = _DAT_60022000;
          }
          else {
            FUN_0000044c(param_1,&local_28,param_2 & 3);
          }
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar1 >> 2);
    }
    return 0;
  }
  return 3;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00005c84(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  thunk_FUN_00005bbc(param_1,param_2,param_3,param_4);
  if (DAT_00091354 == 0) {
    return;
  }
  _DAT_60022100 = 0xdddd;
  _DAT_60022104 = 2;
  return;
}



void FUN_00005cac(void)

{
  return;
}



void FUN_00005cae(void)

{
  return;
}



undefined4 thunk_FUN_00005b94(void)

{
  int iVar1;
  
  if (((DAT_00091bc0 == 0) || (DAT_00091bc0 = DAT_00091bc0 + -1, DAT_00091bc0 == 0)) &&
     (iVar1 = FUN_00000f94(DAT_00091bc4), iVar1 != 0)) {
    return 2;
  }
  return 0;
}



undefined4
thunk_FUN_00005bbc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_r1;
  
  if ((DAT_00091bc0 == 0) &&
     ((iVar1 = FUN_000015c0((uint *)"gcc_prng_ahb_clk",&DAT_00091bc4), iVar1 != 0 ||
      (iVar1 = FUN_000012a0(DAT_00091bc4,extraout_r1,param_3,param_4), iVar1 != 0)))) {
    return 2;
  }
  DAT_00091bc0 = DAT_00091bc0 + 1;
  return 0;
}



int FUN_00005cb8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  if (param_1 == 0 || param_2 == 0) {
    return 3;
  }
  FUN_00005cac();
  if (DAT_00090510 != 1) {
    iVar1 = FUN_00005c84(DAT_00090510,extraout_r1,in_r2,in_r3);
    if (iVar1 != 0) {
      return iVar1;
    }
    DAT_00090510 = 1;
  }
  iVar2 = FUN_00005c04((int *)param_1,param_2);
  iVar1 = DAT_00090510;
  if ((DAT_00090510 == 1) && (iVar2 = thunk_FUN_00005b94(), iVar1 = iVar2, iVar2 != 0)) {
    return iVar2;
  }
  DAT_00090510 = iVar1;
  FUN_00005cae();
  return iVar2;
}



int FUN_00005cc2(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  
  FUN_00005cac();
  if (DAT_00090510 != 1) {
    iVar1 = FUN_00005c84(DAT_00090510,extraout_r1,param_3,param_4);
    if (iVar1 != 0) {
      return iVar1;
    }
    DAT_00090510 = 1;
  }
  iVar2 = FUN_00005c04(param_1,param_2);
  iVar1 = DAT_00090510;
  if ((DAT_00090510 == 1) && (iVar2 = thunk_FUN_00005b94(), iVar1 = iVar2, iVar2 != 0)) {
    return iVar2;
  }
  DAT_00090510 = iVar1;
  FUN_00005cae();
  return iVar2;
}



undefined4 FUN_00005d10(int *param_1)

{
  uint uVar1;
  
  if (DAT_00093568 != '\0') {
    uVar1 = 0;
    do {
      if ((&DAT_00093558)[uVar1] == '\0') break;
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 0x10);
    if (uVar1 != 0x10) {
      (&DAT_00093558)[uVar1] = 1;
      *param_1 = uVar1 * 0x100 + 0x69040000;
      DAT_00093570 = DAT_00093570 + '\x01';
      return 0;
    }
  }
  return 0xffffffff;
}



void FUN_00005d60(void)

{
  uint uVar1;
  
  if (DAT_0009359c != '\0') {
    return;
  }
  if ((*(uint *)(DAT_000901a0 + 0x20) & 1) == 0) {
    return;
  }
  *(undefined4 *)(DAT_0009019c + 0xfb0) = 0xc5acce55;
  if ((*(uint *)(DAT_0009019c + 0x20) & 1) != 0) {
    DAT_0009359c = '\x01';
    uVar1 = *(uint *)(DAT_0009019c + 0x304);
    *(uint *)(DAT_0009019c + 0x304) = *(uint *)(DAT_0009019c + 0x304) & 0x6773 | 0x1000;
    *(uint *)(DAT_0009019c + 0x304) = *(uint *)(DAT_0009019c + 0x304) & 0x7773 | 0x40;
    do {
    } while ((*(uint *)(DAT_0009019c + 0x304) & 0x40) != 0);
    do {
    } while (-1 < *(int *)(DAT_0009019c + 0xc) << 0x1d);
    *(undefined4 *)(DAT_0009019c + 0x20) = 0;
    *(uint *)(DAT_0009019c + 0x304) = uVar1 & 0x7773;
    *(undefined4 *)(DAT_0009019c + 0x28) = 0;
    *(undefined4 *)(DAT_0009019c + 0x20) = 1;
    do {
    } while (*(int *)(DAT_0009019c + 0xc) << 0x1d < 0);
  }
  *(undefined4 *)(DAT_0009019c + 0xfb0) = 0x3a5331aa;
  return;
}



undefined4 FUN_00005f2c(void)

{
  uint uVar1;
  
  if (DAT_00093568 != '\0') {
    FUN_0000ec02(DAT_0009356c,0);
    uVar1 = FUN_00002248();
    if (uVar1 == 0) {
      DAT_00093568 = '\x01';
    }
    return 0;
  }
  return 0xffffffff;
}



undefined4 FUN_00005fa4(void)

{
  if (DAT_00093568 != '\0') {
    FUN_0000ec02(DAT_0009356c,1);
    DAT_00093568 = 2;
    return 0;
  }
  return 0xffffffff;
}



// WARNING: Heritage AFTER dead removal. Example location: r0x60801018 : 0x00006068
// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: ram

void FUN_00005fc8(void)

{
  int iVar1;
  uint uVar2;
  
  DAT_00093568 = 0;
  DAT_0009359c = 0;
  iVar1 = FUN_00014094();
  if (iVar1 == 0) {
    return;
  }
  DAT_000935a0 = (uint *)FUN_000140e4();
  if (((DAT_000935a0 != (uint *)0x0) &&
      (uVar2 = *DAT_000935a0, (undefined **)(uVar2 >> 0x10) == &PTR_DAT_00005144)) && (uVar2 != 0))
  {
    if ((uVar2 & 1) == 0) {
      uVar2 = uVar2 & 0xfffffffd;
    }
    else {
      uVar2 = uVar2 & 0xfffffffe | 2;
      DAT_00090190 = 1;
    }
    *DAT_000935a0 = uVar2;
  }
  DAT_00093590 = 1;
  DAT_0009356c = FUN_0000e418((uint *)"/clk/qdss",(uint *)"qdssrpm",0x40,0,0);
  if (DAT_0009356c == (int *)0x0) {
    return;
  }
  FUN_0000ec02((int)DAT_0009356c,1);
  DAT_000901b0 = 0x60801000;
  _DAT_60801060 = _DAT_60801060 | 2;
  _DAT_60801014 = 0x3020100;
  _DAT_60801018 = _DAT_60801018 & 0xf803ffff | 0x40000;
  _DAT_60801010 = 0;
  _DAT_60801fb0 = 0x3a5331aa;
  DAT_00090198 = 0x60802000;
  _DAT_60802e8c = DAT_00093594;
  _DAT_60802fb0 = 0x3a5331aa;
  FUN_00006330();
  DAT_000901a0 = 0x60826000;
  DAT_0009019c = 0x60825000;
  DAT_000901a4 = 1;
  DAT_000901a8 = &DAT_00090194;
  DAT_00093568 = 1;
  if (DAT_00090190 == 0) {
    FUN_0000ec02((int)DAT_0009356c,0);
  }
  else {
    _DAT_60825028 = 0;
    _DAT_60825304 = 0x433;
    _DAT_60825020 = 1;
    _DAT_60825fb0 = 0x3a5331aa;
    DAT_00090194[0x3ec] = 0xc5acce55;
    *DAT_00090194 = *DAT_00090194 & 0xfff | 0x80;
    DAT_000901ac = DAT_00090194;
    DAT_00090194[0x3ec] = 0x3a5331aa;
    DAT_00090198 = 0x60802000;
    if ((_DAT_60802e80 & 1) == 0) {
      _DAT_60802e64 = _DAT_60802e64 & 0x7f8000;
      _DAT_60802e00 = 0xffffffff;
      _DAT_60802e60 = _DAT_60802e60 & 0xfff00000;
      _DAT_60802e90 = 0x1600;
      _DAT_60802e80 = _DAT_60802e80 & 0xff0026 | 5;
    }
    _DAT_60802fb0 = 0x3a5331aa;
    DAT_00093568 = 2;
  }
  if (DAT_00093568 == 0) {
    return;
  }
  uVar2 = 0;
  do {
    if ((&DAT_00093558)[uVar2] == '\0') break;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 0x10);
  if (uVar2 == 0x10) {
    return;
  }
  (&DAT_00093558)[uVar2] = 1;
  DAT_00093598 = uVar2 * 0x100 + 0x69040000;
  DAT_00093570 = DAT_00093570 + '\x01';
  if (DAT_000935a0 == (uint *)0x0) {
    return;
  }
  if ((undefined **)(*DAT_000935a0 >> 0x10) != &PTR_DAT_00005144) {
    return;
  }
  if ((*DAT_000935a0 & 2) != 0) {
    if (1 < DAT_00093568) {
      *(undefined4 *)(DAT_00093598 | 0x80) = 0x2b380;
      return;
    }
    return;
  }
  return;
}



void FUN_00006280(void)

{
  if (DAT_00093568 == '\0') {
    return;
  }
  FUN_00006330();
  if (DAT_0009018c == 0) {
    return;
  }
  FUN_0000b1ac((uint)DAT_0009018c);
  return;
}



void FUN_000062ac(void)

{
  if (DAT_00093568 == '\0') {
    return;
  }
  *(undefined4 *)(DAT_000901b0 + 0xfb0) = 0xc5acce55;
  *(uint *)(DAT_000901b0 + 0x38) = *(uint *)(DAT_000901b0 + 0x38) | 2;
  *(uint *)(DAT_000901b0 + 0x38) = *(uint *)(DAT_000901b0 + 0x38) & 0xfffffffe;
  *(uint *)(DAT_000901b0 + 0x38) = *(uint *)(DAT_000901b0 + 0x38) | 1;
  DAT_0009358c = *(undefined4 *)(DAT_000901b0 + 0x48);
  DAT_00093588 = *(undefined4 *)(DAT_000901b0 + 0x44);
  DAT_0009357c = *(uint *)(DAT_000901b0 + 0x40) & 0xffffff;
  DAT_00093578 = *(undefined4 *)(DAT_000901b0 + 0x3c);
  *(uint *)(DAT_000901b0 + 0x38) = *(uint *)(DAT_000901b0 + 0x38) & 0xfffffffd;
  *(undefined4 *)(DAT_000901b0 + 0xfb0) = 0x3a5331aa;
  if (DAT_0009018c == 0) {
    return;
  }
  FUN_0000b1ac((uint)DAT_0009018c);
  return;
}



void FUN_00006330(void)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined4 *)(DAT_000901b0 + 0xfb0) = 0xc5acce55;
  *(uint *)(DAT_000901b0 + 0x38) = *(uint *)(DAT_000901b0 + 0x38) | 2;
  *(uint *)(DAT_000901b0 + 0x38) = *(uint *)(DAT_000901b0 + 0x38) & 0xfffffffe;
  *(uint *)(DAT_000901b0 + 0x38) = *(uint *)(DAT_000901b0 + 0x38) | 1;
  DAT_00093584 = *(uint *)(DAT_000901b0 + 0x40) & 0xffffff;
  DAT_00093580 = *(uint *)(DAT_000901b0 + 0x3c);
  lVar1 = (ulonglong)DAT_00093590 * (ulonglong)(DAT_00093580 - DAT_00093578);
  uVar3 = (uint)lVar1;
  iVar2 = DAT_00093588 + uVar3;
  *(int *)(DAT_000901b0 + 0x50) =
       DAT_0009358c +
       DAT_00093590 * (DAT_00093584 - (DAT_0009357c + (uint)(DAT_00093580 < DAT_00093578))) +
       (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(DAT_00093588,uVar3);
  *(int *)(DAT_000901b0 + 0x4c) = iVar2;
  *(uint *)(DAT_000901b0 + 0x38) = *(uint *)(DAT_000901b0 + 0x38) & 0xfffffffd;
  *(undefined4 *)(DAT_000901b0 + 0xfb0) = 0x3a5331aa;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_000063c8(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  undefined4 uStack40;
  int iStack36;
  undefined4 uStack32;
  uint uStack28;
  
  if (param_1 == 150000000) {
    DAT_00093590 = 7;
  }
  else {
    if (param_1 == 300000000) {
      DAT_00093590 = 0xf;
    }
    else {
      if (param_1 == 600000000) {
        DAT_00093590 = 0x1f;
      }
      else {
        DAT_00093590 = 1;
      }
    }
  }
  if (DAT_00093568 == '\0') {
    DAT_00093594 = param_1;
    return;
  }
  DAT_00093594 = param_1;
  if (DAT_00093598 != 0) {
    FUN_0000d758();
    uStack32 = _DAT_00083000;
    uStack28 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    uVar1 = DAT_00093598;
    uStack40 = 0x2b2;
    iStack36 = param_1;
    iVar2 = 0x10;
    *(undefined4 *)(DAT_00093598 | 0x88) = 0x1021010;
    puVar4 = (undefined4 *)(uVar1 | 0x98);
    puVar3 = &uStack40;
    while (bVar5 = ((uint)puVar3 & 3) == 0, (!bVar5 && iVar2 != 0) && (bVar5 || -1 < iVar2)) {
      *(undefined *)puVar4 = *(undefined *)puVar3;
      iVar2 = iVar2 + -1;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    while (3 < iVar2) {
      *puVar4 = *puVar3;
      iVar2 = iVar2 + -4;
      puVar3 = puVar3 + 1;
    }
    while (1 < iVar2) {
      *(undefined2 *)puVar4 = *(undefined2 *)puVar3;
      iVar2 = iVar2 + -2;
      puVar3 = (undefined4 *)((int)puVar3 + 2);
    }
    while (0 < iVar2) {
      *(undefined *)puVar4 = *(undefined *)puVar3;
      iVar2 = iVar2 + -1;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    *(undefined4 *)(uVar1 | 0xe0) = 0;
  }
  *(undefined4 *)(DAT_00090198 + 0xfb0) = 0xc5acce55;
  *(int *)(DAT_00090198 + 0xe8c) = param_1;
  *(undefined4 *)(DAT_00090198 + 0xfb0) = 0x3a5331aa;
  return;
}



undefined4 FUN_000064cc(uint param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((1 < DAT_00093568) && (0 < (int)param_4)) {
    *(uint *)(param_1 | 0x88) =
         param_2 << 0x18 | (param_2 >> 8 & 0xff) << 0x10 | (param_2 >> 0x10 & 0xff) << 8 |
         param_2 >> 0x18;
    puVar2 = (undefined4 *)(param_1 | 0x98);
    while( true ) {
      uVar3 = (uint)param_3 & 3;
      uVar1 = uVar3;
      if (uVar3 != 0) {
        uVar1 = param_4;
      }
      if ((uVar3 == 0 || param_4 == 0) || (int)uVar1 < 0) break;
      *(undefined *)puVar2 = *(undefined *)param_3;
      param_4 = param_4 - 1;
      param_3 = (undefined4 *)((int)param_3 + 1);
    }
    while (3 < (int)param_4) {
      *puVar2 = *param_3;
      param_4 = param_4 - 4;
      param_3 = param_3 + 1;
    }
    while (1 < (int)param_4) {
      *(undefined2 *)puVar2 = *(undefined2 *)param_3;
      param_4 = param_4 - 2;
      param_3 = (undefined4 *)((int)param_3 + 2);
    }
    while (0 < (int)param_4) {
      *(undefined *)puVar2 = *(undefined *)param_3;
      param_4 = param_4 - 1;
      param_3 = (undefined4 *)((int)param_3 + 1);
    }
    *(undefined4 *)(param_1 | 0xe0) = 0;
    return 0;
  }
  return 0xffffffff;
}



void FUN_00006558(int param_1)

{
  if (param_1 == 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (*(char *)(param_1 + 0x2e) != '\x01') {
    return;
  }
  *(undefined *)(param_1 + 0x2e) = 2;
  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
  return;
}



void FUN_000065c0(undefined4 param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0000a6f4(0x40);
  puVar1 = (undefined4 *)FUN_00009338(puVar1,1,0);
  *(undefined **)puVar1 = &DAT_0001daa4;
  *(undefined *)((int)puVar1 + 0x2e) = 0;
  *(undefined2 *)(puVar1 + 0xc) = param_2;
  puVar1[0xd] = 0;
  puVar1[0xe] = param_1;
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_000065ec(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 param_2_00;
  uint uVar3;
  ulonglong uVar4;
  uint uStack52;
  undefined4 uStack48;
  undefined4 uStack44;
  undefined4 uStack40;
  undefined4 uStack36;
  
  uVar4 = FUN_0000029e(1,0,param_1 & 0x3f);
  uVar1 = (uint)(uVar4 >> 0x20);
  if (0x3ff < param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  uVar3 = param_1 >> 6;
  if ((DAT_00090448 == '\0') ||
     (((&DAT_00093898)[uVar3 * 2] & uVar1 | (&DAT_0009389c)[uVar3 * 2] & (uint)uVar4) == 0)) {
    if ((uVar1 & (&DAT_00093818)[uVar3 * 2] | (uint)uVar4 & (&DAT_0009381c)[uVar3 * 2]) != 0) {
      FUN_00016e88(param_1,param_2,param_3,param_4,param_5);
      return;
    }
    return;
  }
  if (DAT_00090449 != '\0') {
    return;
  }
  uStack36 = param_5;
  DAT_00090450 = DAT_00090450 + 1;
  uStack52 = param_1;
  uStack48 = param_2;
  uStack44 = param_3;
  uStack40 = param_4;
  iVar2 = FUN_000064cc(DAT_00090458,0x10100201,&uStack52,0x14);
  if (iVar2 != 0) {
    FUN_00016e88(param_1,param_2,param_3,param_4,param_5);
  }
  if ((DAT_00090450 & 0x3ff) == 0) {
    param_2_00 = FUN_0000c3a4();
    FUN_000065ec(0xe3,param_2_00,0,0,0);
    return;
  }
  return;
}



int FUN_000066cc(void)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 uVar2;
  uint uVar3;
  
  if (DAT_000939e0 != '\0') {
    return 0;
  }
  uVar3 = 0x10301;
  uVar2 = 0x80;
  FUN_00006a4c(&DAT_00091840);
  iVar1 = FUN_00005a6c(0xdced,extraout_r1,uVar2,uVar3);
  if (iVar1 == 0) {
    uVar3 = FUN_00005a60();
    if ((uVar3 != 0) && (iVar1 = FUN_000069b8(0x200,&DAT_000939e8), iVar1 != 0)) {
      return iVar1;
    }
    DAT_000939e0 = 1;
    return iVar1;
  }
  return iVar1;
}



void FUN_00006730(byte param_1,undefined4 param_2,ushort param_3,undefined *param_4,uint param_5,
                 int *param_6)

{
  FUN_0000ba4c(1,param_2,(uint)param_1,(uint)param_3,param_4,param_5,param_6);
  return;
}



// WARNING: Could not reconcile some variable overlaps

void FUN_00006750(int param_1,int param_2,int param_3,uint param_4,uint param_5,undefined *param_6)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint **ppuVar4;
  uint local_20;
  
  if (DAT_000939e0 == '\0') {
    return;
  }
  if (DAT_000939e8 == 0) {
    return;
  }
  if ((param_3 == 0 || param_4 == 0) || param_6 == (undefined *)0x0) {
    param_1 = 0xc;
  }
  if ((param_3 == 0 || param_4 == 0) || param_6 == (undefined *)0x0) {
    return;
  }
  local_20 = param_4;
  iVar1 = FUN_000059f4(param_1,param_2,(undefined *)&local_20);
  if (iVar1 != 0) {
    return;
  }
  if (0x80 < (byte)local_20) {
    return;
  }
  ppuVar4 = (uint **)(DAT_000939e8 + (local_20 & 0xff) * 4);
  while (puVar2 = *ppuVar4, puVar2 != (uint *)0x0) {
    if (*puVar2 == 0) goto LAB_000067ca;
    ppuVar4 = (uint **)(puVar2 + 4);
  }
  iVar1 = FUN_000069b8(0x14,(int *)ppuVar4);
  if (iVar1 != 0) {
    return;
  }
LAB_000067ca:
  **ppuVar4 = param_4;
  (*ppuVar4)[1] = param_5;
  *(char *)(*ppuVar4 + 2) = (char)param_3;
  uVar3 = DAT_000939e4 + 1;
  DAT_000939e4 = uVar3;
  (*ppuVar4)[3] = uVar3;
  *(uint *)(param_6 + 4) = uVar3;
  *param_6 = (byte)local_20;
  FUN_00005b44(local_20 & 0xff,1);
  return;
}



void FUN_00006800(byte param_1,undefined4 param_2,ushort param_3,undefined *param_4,uint param_5)

{
  FUN_0000ba4c(0,param_2,(uint)param_1,(uint)param_3,param_4,param_5,(int *)0x0);
  return;
}



int FUN_00006820(void)

{
  int iVar1;
  
  if (DAT_00092018 == 0) {
    iVar1 = FUN_00006928(&DAT_00092018);
    return iVar1;
  }
  return 0;
}



int FUN_00006838(uint *param_1,uint *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  if (DAT_0009200c == '\0') {
    iVar1 = FUN_000034b4((uint *)"DALDEVICEID_SPMI_DEVICE",(undefined4 *)&DAT_00092010,param_3,
                         param_4);
    if (iVar1 != 0) {
      return 0xd;
    }
    DAT_0009200c = '\x01';
  }
  iVar1 = FUN_000034e4((int *)&DAT_00092010,param_1,0,param_2);
  if (iVar1 != 0) {
    iVar1 = 0xb;
  }
  return iVar1;
}



// WARNING: Could not reconcile some variable overlaps

uint FUN_0000687c(void)

{
  int iVar1;
  uint in_r3;
  uint local_10;
  
  local_10 = in_r3;
  if (DAT_0009182a == '\0') {
    iVar1 = FUN_000015c0((uint *)"gcc_spmi_ahb_clk",&DAT_00091838);
    if (iVar1 == 0) {
      DAT_0009182a = '\x01';
    }
    else {
      if (DAT_0009182a == '\0') {
        return 2;
      }
    }
  }
  iVar1 = FUN_00002218(DAT_00091838,(undefined *)&local_10);
  if (iVar1 != 0) {
    return 2;
  }
  local_10 = local_10 & 0xff;
  if ((char)local_10 != '\0') {
    local_10 = 1;
  }
  return local_10;
}



int FUN_000068d0(undefined *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint auStack32 [2];
  undefined local_18;
  
  if (DAT_0009200c == '\0') {
    iVar1 = FUN_000034b4((uint *)"DALDEVICEID_SPMI_DEVICE",(undefined4 *)&DAT_00092010,param_3,
                         param_4);
    if (iVar1 != 0) {
      return 0xd;
    }
    DAT_0009200c = '\x01';
  }
  iVar1 = FUN_000034e4((int *)&DAT_00092010,(uint *)"owner",0,auStack32);
  if (iVar1 == 0) {
    *param_1 = local_18;
  }
  else {
    iVar1 = 0xb;
  }
  return iVar1;
}



int FUN_00006928(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_000037f8(1,(uint *)"PMIC_ARB",param_1);
  if (iVar1 != 0) {
    iVar1 = 0xd;
  }
  return iVar1;
}



// WARNING: Could not reconcile some variable overlaps

uint FUN_00006948(void)

{
  int iVar1;
  uint in_r3;
  uint local_10;
  
  local_10 = in_r3;
  if (DAT_00091829 == '\0') {
    iVar1 = FUN_000015c0((uint *)"gcc_spmi_ser_clk",&DAT_00091834);
    if (iVar1 == 0) {
      DAT_00091829 = '\x01';
    }
    else {
      if (DAT_00091829 == '\0') {
        return 2;
      }
    }
  }
  iVar1 = FUN_00002218(DAT_00091834,(undefined *)&local_10);
  if (iVar1 != 0) {
    return 2;
  }
  local_10 = local_10 & 0xff;
  if ((char)local_10 != '\0') {
    local_10 = 1;
  }
  return local_10;
}



void FUN_0000699c(void)

{
  if (DAT_00091828 == '\0') {
    FUN_0001a770();
    DAT_00091828 = '\x01';
  }
  FUN_0001a750();
  return;
}



undefined4 FUN_000069b8(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    iVar1 = FUN_00000154(param_1);
    *param_2 = iVar1;
    FUN_000005cc(iVar1,param_1);
    return 0;
  }
  return 0xb;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

undefined4 FUN_000069d4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 in_r2;
  uint in_r3;
  uint auStack32 [2];
  uint uStack24;
  
  if (param_1 == 0) {
    return 0xc;
  }
  iVar1 = FUN_00006838((uint *)"interrupt",auStack32,in_r2,in_r3);
  if (iVar1 == 0) {
    DAT_0009183c = uStack24;
    DAT_0009182c = param_1;
    DAT_00091830 = param_2;
    FUN_0000d57c(uStack24,FUN_0001a0a0 + 1);
    FUN_0000d4f0(DAT_0009183c,2);
    iVar2 = 1 << (DAT_0009183c & 0x1f);
    iVar1 = (DAT_0009183c >> 5) * 4;
    *(int *)(&DAT_e000e280 + iVar1) = iVar2;
    *(int *)(&DAT_e000e100 + iVar1) = iVar2;
    return 0;
  }
  return 0xb;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

undefined4 FUN_000069dc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint auStack32 [2];
  uint uStack24;
  
  iVar1 = FUN_00006838((uint *)"interrupt",auStack32,param_3,param_4);
  if (iVar1 == 0) {
    DAT_0009183c = uStack24;
    DAT_0009182c = param_1;
    DAT_00091830 = param_2;
    FUN_0000d57c(uStack24,FUN_0001a0a0 + 1);
    FUN_0000d4f0(DAT_0009183c,2);
    iVar2 = 1 << (DAT_0009183c & 0x1f);
    iVar1 = (DAT_0009183c >> 5) * 4;
    *(int *)(&DAT_e000e280 + iVar1) = iVar2;
    *(int *)(&DAT_e000e100 + iVar1) = iVar2;
    return 0;
  }
  return 0xb;
}



void thunk_FUN_0000b1ac(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  piVar1 = DAT_00090514;
  if (DAT_00090514 == (int *)0x0) {
    return;
  }
  iVar2 = *DAT_00090514;
  uVar3 = FUN_000001b0((uint)((ulonglong)param_1 * 0x4b00),
                       (uint)((ulonglong)param_1 * 0x4b00 >> 0x20),1000,0);
  do {
  } while ((int)uVar3 + (uint)((uint)(*piVar1 - iVar2) < (uint)((ulonglong)uVar3 >> 0x20)) != 0);
  return;
}



undefined4 FUN_00006a4c(undefined4 *param_1)

{
  *param_1 = 0;
  return 0;
}



// WARNING (jumptable): Heritage AFTER dead removal. Example location: s0xffffffec : 0x00006a68
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00006a54(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE_00;
  undefined4 uStack88;
  undefined4 uStack84;
  undefined4 uStack80;
  undefined4 uStack76;
  undefined4 auStack72 [11];
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uStack16;
  uint uStack12;
  undefined4 uStack8;
  undefined4 uStack4;
  
  uStack4 = param_4;
  uStack16 = param_1;
  uStack12 = param_2;
  uStack8 = param_3;
  if (param_2 < 0xb) {
    UNRECOVERED_JUMPTABLE = UNRECOVERED_JUMPTABLE_00;
    if (DAT_00091350 != 0) {
      uStack88 = 1;
      uStack84 = 0;
      uStack80 = 0;
      puVar2 = &uStack76;
      uVar3 = 0;
      puVar1 = &uStack4;
      if (param_2 != 0) {
        do {
          puVar2 = puVar2 + 1;
          uVar3 = uVar3 + 1;
          *puVar2 = *puVar1;
          puVar1 = puVar1 + 1;
        } while (uVar3 < param_2);
      }
      uStack76 = param_3;
      FUN_000064cc(DAT_00091350,0x10100b02,&uStack88,param_2 * 4 + 0x10);
    }
                    // WARNING: Could not recover jumptable at 0x00006ac2. Too many branches
                    // WARNING: Treating indirect jump as call
    (*UNRECOVERED_JUMPTABLE)(0);
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00006a68. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE_00)(0xffffffff);
  return;
}



undefined4 * FUN_00006ad0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (((DAT_00090498 & 1) == 0) && (iVar1 = FUN_0000a92e(&DAT_00090498), iVar1 != 0)) {
    DAT_00093940 = 0;
    puVar2 = FUN_0000a3fa((undefined4 *)&DAT_00093948,10);
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    FUN_0000a8a4((int)(puVar2 + -2),0x9831,0);
  }
  return &DAT_00093940;
}



undefined4 * FUN_00006b20(void)

{
  int iVar1;
  
  if (((DAT_00091314 & 1) == 0) && (iVar1 = FUN_0000a92e(&DAT_00091314), iVar1 != 0)) {
    DAT_000954f8 = 0;
    DAT_000954f0 = 0;
    DAT_000954f4 = 0;
  }
  return &DAT_000954f0;
}



void FUN_00006b50(undefined4 *param_1,int param_2,int param_3)

{
  undefined uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  bool bVar5;
  
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[1] = param_3;
  *(char *)param_1 = (char)param_2;
  uVar4 = (uint)(byte)PTR_DAT_000912d4[param_2 * 0x1c + 4];
  iVar2 = FUN_00000154(uVar4);
  param_1[2] = iVar2;
  FUN_000005cc(iVar2,uVar4);
  iVar2 = 0;
  DAT_000912e4 = FUN_00017184(DAT_000912e4,(int)param_1,uVar4,(int *)0x0,(int *)param_1[2]);
  param_1[3] = 0;
  *(undefined *)((int)param_1 + 1) = 0x7f;
  if (DAT_00090470 != (int *)0x0) {
    iVar2 = *DAT_00090470;
  }
  piVar3 = DAT_00090470;
  if (DAT_00090470 != (int *)0x0 && iVar2 != 0) {
    while( true ) {
      bVar5 = iVar2 == *(int *)(PTR_DAT_000912d4 + (uint)*(byte *)param_1 * 0x1c);
      if (bVar5) {
        iVar2 = piVar3[1];
      }
      if (bVar5 && iVar2 == param_3) break;
      piVar3 = piVar3 + 3;
      iVar2 = *piVar3;
      if (iVar2 == 0) {
        return;
      }
    }
    uVar1 = (undefined)piVar3[2];
    bVar5 = (piVar3[2] & 1U) == 0;
    if (bVar5) {
      uVar1 = 0xff;
    }
    if (bVar5) {
      *(undefined *)((int)param_1 + 1) = uVar1;
    }
    return;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00006c08(uint **param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  uint **ppuVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  bool bVar13;
  uint uStack52;
  byte abStack48 [4];
  uint uStack44;
  
  ppuVar6 = (uint **)*param_1;
  puVar10 = param_1[4];
  puVar8 = param_1[5];
  if ((ppuVar6 != (uint **)0x0) && (param_1[1] < *ppuVar6)) {
    puVar12 = (uint *)ppuVar6[1][(int)param_1[1] * 3];
    puVar11 = (uint *)(ppuVar6[1] + (int)param_1[1] * 3)[1];
    puVar9 = param_1[2];
    if ((puVar12 != (uint *)0x0) && (puVar9 < DAT_000912c4)) {
      piVar1 = (int *)puVar11[(int)puVar9];
      if (piVar1 == (int *)0x0) {
        if (puVar9 < &DAT_00000004) {
          pcVar4 = (&PTR_DAT_000912f4)[(int)puVar9 * 2];
        }
        else {
          pcVar4 = "unknown client via rpm-npa adapter";
        }
        piVar1 = FUN_0000e418(puVar12,(uint *)pcVar4,0x40,0,0);
        *(int **)(puVar11 + (int)puVar9) = piVar1;
        if (piVar1 == (int *)0x0) goto LAB_00006dd2;
      }
      if (puVar8 == (uint *)0x0) {
        iVar5 = *(int *)(ppuVar6[1][(int)param_1[1] * 3 + 1] + (int)param_1[2] * 4);
        if (iVar5 != 0) {
          FUN_0000e3a8(iVar5);
        }
        iVar5 = *(int *)(ppuVar6[1][(int)param_1[1] * 3 + 2] + (int)param_1[2] * 4);
        if (iVar5 != 0) {
          FUN_0000e3a8(iVar5);
        }
      }
      else {
        if (puVar10 == (uint *)0x0) {
          FUN_0000ec02((int)piVar1,*puVar8);
          if (puVar8[1] != 0) {
            puVar10 = param_1[2];
            puVar11 = (uint *)ppuVar6[1][(int)param_1[1] * 3];
            puVar9 = (uint *)(ppuVar6[1] + (int)param_1[1] * 3)[2];
            if ((puVar11 == (uint *)0x0) || (DAT_000912c4 <= puVar10)) goto LAB_00006dd2;
            piVar3 = (int *)puVar9[(int)puVar10];
            if (piVar3 == (int *)0x0) {
              if (puVar10 < &DAT_00000004) {
                pcVar4 = (&PTR_DAT_000912f4)[(int)puVar10 * 2];
              }
              else {
                pcVar4 = "unknown client via rpm-npa adapter";
              }
              piVar3 = FUN_0000e418(puVar11,(uint *)pcVar4,0x200,0,0);
              *(int **)(puVar9 + (int)puVar10) = piVar3;
              if (piVar3 == (int *)0x0) goto LAB_00006dd2;
            }
            FUN_0000eb68((int)piVar3,puVar8[1]);
          }
        }
        else {
          bVar13 = *(char *)(ppuVar6 + 2) == '\0';
          if (!bVar13) {
            bVar13 = ((uint)param_1[8] | (uint)param_1[9]) == 0;
          }
          if (bVar13) {
            if (puVar10[1] != puVar8[1]) {
              puVar10 = param_1[2];
              puVar11 = (uint *)ppuVar6[1][(int)param_1[1] * 3];
              puVar9 = (uint *)(ppuVar6[1] + (int)param_1[1] * 3)[2];
              if ((puVar11 == (uint *)0x0) || (DAT_000912c4 <= puVar10)) goto LAB_00006dd2;
              piVar3 = (int *)puVar9[(int)puVar10];
              if (piVar3 == (int *)0x0) {
                if (puVar10 < &DAT_00000004) {
                  pcVar4 = (&PTR_DAT_000912f4)[(int)puVar10 * 2];
                }
                else {
                  pcVar4 = "unknown client via rpm-npa adapter";
                }
                piVar3 = FUN_0000e418(puVar11,(uint *)pcVar4,0x200,0,0);
                *(int **)(puVar9 + (int)puVar10) = piVar3;
                if (piVar3 == (int *)0x0) goto LAB_00006dd2;
              }
              FUN_0000eb68((int)piVar3,puVar8[1]);
            }
            FUN_0000ec02((int)piVar1,*puVar8);
          }
          else {
            if (puVar10 == puVar8) {
              uVar2 = piVar1[10];
              iVar5 = (piVar1 + uVar2 * 2)[7];
              (piVar1 + (uVar2 ^ 1) * 2)[6] = (piVar1 + uVar2 * 2)[6];
              (piVar1 + (uVar2 ^ 1) * 2)[7] = iVar5;
            }
            FUN_0000eb5c((int)piVar1);
          }
        }
      }
      uVar2 = FUN_0000f02c((int)piVar1,0,abStack48);
      bVar13 = uVar2 == 0;
      if (bVar13) {
        uVar2 = (uint)abStack48[0];
      }
      if (bVar13 && uVar2 == 0) {
        *param_1[6] = uStack44;
        if (*(char *)(ppuVar6 + 2) != '\0') {
          iVar5 = FUN_0000f02c((int)piVar1,0x1023,&stack0xffffffc8);
          if ((iVar5 == 0) && (uStack52 != 0)) {
            FUN_0000d758();
            uVar2 = _DAT_00083000;
            uVar7 = _DAT_00083004 & 0xffffff;
            FUN_0001a7ec();
            puVar10 = (uint *)(uVar2 + uStack52);
            puVar8 = (uint *)(uVar7 + CARRY4(uVar2,uStack52));
          }
          else {
            puVar10 = (uint *)0x0;
            puVar8 = puVar10;
          }
          param_1[8] = puVar10;
          param_1[9] = puVar8;
          return;
        }
        return;
      }
    }
  }
LAB_00006dd2:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00006e3c(uint **param_1)

{
  uint **ppuVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint uStack36;
  int iStack32;
  uint *puStack28;
  
  ppuVar1 = (uint **)*param_1;
  puVar8 = param_1[4];
  if ((ppuVar1 != (uint **)0x0) && (param_1[1] < *ppuVar1)) {
    puVar10 = (uint *)ppuVar1[1][(int)param_1[1] * 3];
    puVar9 = (uint *)(ppuVar1[1] + (int)param_1[1] * 3)[1];
    puVar6 = param_1[2];
    if ((puVar10 != (uint *)0x0) && (puVar6 < DAT_000912c4)) {
      piVar2 = (int *)puVar9[(int)puVar6];
      if (piVar2 == (int *)0x0) {
        if (puVar6 < &DAT_00000004) {
          pcVar5 = (&PTR_DAT_000912f4)[(int)puVar6 * 2];
        }
        else {
          pcVar5 = "unknown client via rpm-npa adapter";
        }
        piVar2 = FUN_0000e418(puVar10,(uint *)pcVar5,0x40,0,0);
        *(int **)(puVar9 + (int)puVar6) = piVar2;
        if (piVar2 == (int *)0x0) goto LAB_00006eea;
      }
      puVar6 = *(uint **)(*(int *)piVar2[3] + 4);
LAB_00006ea4:
      iVar3 = FUN_0000d658((int *)param_1[5],&uStack36,&iStack32,&puStack28);
      if (iVar3 == 0) {
        return;
      }
      if (iStack32 != 4) goto code_r0x00006ec6;
      uVar7 = *puStack28;
      goto LAB_00006ece;
    }
  }
LAB_00006eea:
                    // WARNING: Subroutine does not return
  FUN_00000060();
code_r0x00006ec6:
  if (iStack32 == 0) {
    uVar7 = 0;
LAB_00006ece:
    if (uStack36 == 0x78616d) {
      puVar8[1] = uVar7;
    }
    else {
      uVar4 = FUN_000003b6(&uStack36,puVar6,4);
      if (uVar4 == 0) {
        *puVar8 = uVar7;
      }
    }
  }
  goto LAB_00006ea4;
}



uint FUN_00006f04(undefined1 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  bool bVar11;
  
  uVar2 = DAT_000912e8;
  puVar9 = &DAT_000912e0;
  if (7 < DAT_000912e8) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  iVar1 = DAT_000912e8 * 0x1c;
  puVar8 = (undefined4 *)(&DAT_00095410 + iVar1);
  DAT_000912e8 = DAT_000912e8 + 1;
  *puVar8 = 0;
  *(undefined4 *)(&DAT_00095418 + iVar1) = 0;
  *(undefined4 *)(&DAT_0009541c + iVar1) = 0;
  *(undefined4 *)(&DAT_00095420 + iVar1) = 0;
  *(undefined4 *)(&DAT_00095424 + iVar1) = 0;
  *(undefined4 *)(&DAT_00095428 + iVar1) = 0;
  *(undefined1 **)(&DAT_00095414 + iVar1) = param_1;
  *(char *)puVar8 = (char)param_2;
  uVar10 = (uint)(byte)PTR_DAT_000912d4[param_2 * 0x1c + 4];
  iVar3 = FUN_00000154(uVar10);
  *(int *)(&DAT_00095418 + iVar1) = iVar3;
  FUN_000005cc(iVar3,uVar10);
  iVar3 = 0;
  DAT_000912e4 = FUN_00017184(DAT_000912e4,(int)puVar8,uVar10,(int *)0x0,
                              *(int **)(&DAT_00095418 + iVar1));
  puVar7 = (undefined1 *)0x7f;
  *(undefined4 *)(&DAT_0009541c + iVar1) = 0;
  (&DAT_00095411)[iVar1] = 0x7f;
  iVar6 = *(int *)(PTR_DAT_000912d4 + (uint)*(byte *)puVar8 * 0x1c);
  uVar5 = (undefined)iVar6;
  if (DAT_00090470 != (int *)0x0) {
    iVar3 = *DAT_00090470;
  }
  piVar4 = DAT_00090470;
  if (DAT_00090470 != (int *)0x0 && iVar3 != 0) {
    do {
      if (iVar3 == iVar6) {
        puVar9 = (undefined1 *)piVar4[1];
      }
      if (iVar3 == iVar6 && puVar9 == param_1) {
        bVar11 = (piVar4[2] & 1U) == 0;
        if (bVar11) {
          uVar5 = 0xff;
        }
        if (bVar11) {
          (&DAT_00095411)[iVar1] = uVar5;
        }
        break;
      }
      piVar4 = piVar4 + 3;
      iVar3 = *piVar4;
    } while (iVar3 != 0);
  }
  if (DAT_00090470 != (int *)0x0) {
    puVar7 = (undefined1 *)*DAT_00090470;
  }
  piVar4 = DAT_00090470;
  if (DAT_00090470 != (int *)0x0 && puVar7 != (undefined1 *)0x0) {
    do {
      bVar11 = puVar7 == *(undefined1 **)(PTR_DAT_000912d4 + (uint)*(byte *)puVar8 * 0x1c);
      if (bVar11) {
        puVar7 = (undefined1 *)piVar4[1];
      }
      if (bVar11 && puVar7 == param_1) {
        if ((piVar4[2] & 1U) != 0) {
          return uVar2;
        }
        return uVar2 | 0x80;
      }
      piVar4 = piVar4 + 3;
      puVar7 = (undefined1 *)*piVar4;
    } while (puVar7 != (undefined1 *)0x0);
  }
  return uVar2;
}



void FUN_00007028(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *local_10;
  
  if (*(char *)((int)param_3 + 0x39) == '\0') {
    return;
  }
  do {
    if (*(char *)(param_3 + 0xe) != '\0') {
LAB_0000705c:
      local_10 = (int *)0x0;
      uVar2 = *(undefined4 *)(param_3[0x12] + 8);
      FUN_000065ec(0xd0,param_3[0xd],uVar2,0,0);
      if ((*(int *)(param_3[0x12] + 0xc) == 2) && (iVar3 = FUN_000197c2(param_3[0xc],3), iVar3 == 0)
         ) {
        return;
      }
      *(undefined *)((int)param_3 + 0x39) = 0;
      *(undefined *)((int)param_3 + 0x62) = 1;
      *(undefined *)(param_3 + 0x18) = 1;
      FUN_00009246(param_3,0,uVar2,local_10);
      return;
    }
    puVar1 = FUN_00019790(param_3[0xc]);
    if (puVar1 == (undefined *)0x0) {
      if (*(char *)(param_3 + 0xe) == '\0') {
        return;
      }
      goto LAB_0000705c;
    }
    uVar2 = FUN_00009954((int)param_3);
    *(char *)(param_3 + 0xe) = (char)uVar2;
  } while( true );
}



undefined4 * FUN_000071d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (((DAT_0009131c & 1) == 0) && (iVar1 = FUN_0000a92e(&DAT_0009131c), iVar1 != 0)) {
    puVar2 = (undefined4 *)FUN_0000a6f4(0xc);
    puVar2[1] = 0x20;
    puVar2[2] = 0;
    puVar3 = (undefined4 *)FUN_00000154(0x280);
    *(undefined4 **)puVar2 = puVar3;
    FUN_00000610(puVar3,0x280);
    DAT_00095508 = *puVar2;
    DAT_0009550c = puVar2[1];
    DAT_00095510 = puVar2[2];
  }
  return &DAT_00095508;
}



undefined8
FUN_00007230(byte *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  code *pcVar5;
  int *apiStack96 [2];
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 uStack44;
  byte *local_28;
  
  puVar4 = (undefined4 *)(PTR_DAT_000912d4 + (uint)*param_1 * 0x1c);
  local_50 = puVar4[4];
  local_4c = *(undefined4 *)(param_1 + 4);
  local_48 = param_2;
  local_44 = 0;
  local_40 = param_3;
  local_3c = param_4;
  local_28 = param_1;
  local_38 = *(undefined4 *)(param_1 + 8);
  local_30 = param_5;
  uStack44 = param_6;
  iVar2 = -((uint)*(byte *)(puVar4 + 1) + 7 & 0xfffffff8);
  FUN_0000044c((int *)((int)&local_58 + iVar2),*(undefined4 *)(param_1 + 8));
  *(int **)((int)apiStack96 + iVar2) = 0;
  FUN_000065ec(0xd5,*puVar4,local_4c,0,*(int **)((int)apiStack96 + iVar2));
  bVar1 = *(byte *)(puVar4 + 1);
  pcVar5 = (code *)puVar4[3];
  FUN_00016b82(local_28,local_48,&local_58 + 1,&local_58,*(undefined *)((int)&local_58 + iVar2));
  if (local_44 == local_54) {
    iVar3 = local_3c;
    if (local_58 != 0) {
      if (local_3c == 0) goto LAB_000072c2;
      iVar3 = FUN_00000320(local_58,local_3c,(uint)bVar1,*(undefined *)((int)&local_58 + iVar2));
    }
    if (iVar3 == 0) {
      (*pcVar5)(&local_58 + 2);
      *(int **)((int)apiStack96 + iVar2) = *(undefined4 *)(param_1 + 8);
      DAT_000912e4 = FUN_00017184(DAT_000912e4,(int)param_1,(uint)*(byte *)(puVar4 + 1),
                                  (int *)((int)&local_58 + iVar2),*(int **)((int)apiStack96 + iVar2)
                                 );
      return CONCAT44(local_30,uStack44);
    }
  }
LAB_000072c2:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_000072f8(void)

{
  uint **ppuVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  FUN_0000d758();
  puVar5 = DAT_000904a4;
  FUN_0000d758();
  while( true ) {
    uVar2 = _DAT_00083000;
    uVar4 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    if ((puVar5 == (uint *)0x0) || (uVar4 + (*puVar5 < uVar2) <= puVar5[1])) break;
    (*(code *)puVar5[3])(puVar5[2]);
    puVar3 = DAT_000904a4;
    puVar5 = (uint *)puVar5[4];
    if (DAT_000904a4 != (uint *)0x0) {
      ppuVar1 = (uint **)(DAT_000904a4 + 4);
      DAT_000904a4 = (uint *)DAT_000904a4[4];
      *ppuVar1 = DAT_000904a8;
      *puVar3 = 0xffffffff;
      puVar3[1] = 0xffffffff;
      DAT_000904a8 = puVar3;
    }
    FUN_0000d758();
  }
  if (DAT_000904a4 != (uint *)0x0) {
    _DAT_00084020 = *DAT_000904a4;
    _DAT_00084024 = DAT_000904a4[1];
  }
  _DAT_0008402c = (uint)(DAT_000904a4 != (uint *)0x0);
  FUN_0001a7ec();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_000073a0(byte *param_1,char **param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  longlong lVar15;
  
  puVar3 = FUN_00006b20();
  iVar6 = puVar3[2];
  uVar11 = *(uint *)(param_1 + iVar6 * 4 + 0x14);
  if (uVar11 == 0) {
    uVar11 = iVar6 + 1;
    if (1 < uVar11) {
      uVar11 = 0;
    }
    iVar10 = *(int *)(param_1 + uVar11 * 4 + 0x14);
    if (iVar10 == 0) {
      uVar11 = 0x4b00;
    }
    else {
      puVar4 = FUN_00006b20();
      uVar7 = puVar4[iVar6];
      puVar4 = FUN_00006b20();
      uVar11 = (uint)((ulonglong)(((uint)puVar4[uVar11] / 1000) * iVar10) /
                     ((ulonglong)uVar7 / 1000));
    }
  }
  uVar7 = 0;
  *param_3 = 0;
  param_3[1] = 0;
  if (**param_2 == '\0') {
    FUN_0000d758();
    uVar1 = _DAT_00083000;
    uVar8 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    if (uVar8 + CARRY4(uVar1,uVar11) + (uint)(*(uint *)param_2[1] < uVar1 + uVar11) <=
        *(uint *)(param_2[1] + 1)) {
      FUN_0000d758();
      uVar1 = _DAT_00083000;
      uVar9 = _DAT_00083004 & 0xffffff;
      FUN_0001a7ec();
      FUN_00006b20();
      uVar14 = FUN_00007d88(param_1,(uint)param_2[2],(uint)*(byte *)(param_2 + 3));
      *param_3 = (uint)((ulonglong)uVar14 >> 0x20);
      param_3[1] = (uint)uVar14;
      uVar8 = *(uint *)param_2[4];
      if (uVar11 < uVar8) {
        uVar8 = uVar8 - uVar11;
      }
      else {
        uVar8 = 0;
      }
      *(uint *)param_2[4] = uVar8;
      FUN_0000d758();
      uVar11 = _DAT_00083000;
      uVar8 = _DAT_00083004 & 0xffffff;
      FUN_0001a7ec();
      uVar13 = uVar11 - uVar1;
      if ((param_3[1] | *param_3) != 0) {
        FUN_0000d758();
        uVar2 = _DAT_00083000;
        uVar12 = _DAT_00083004 & 0xffffff;
        FUN_0001a7ec();
        if (DAT_0009049c == '\0') {
          uVar5 = *param_3;
          if (uVar12 < param_3[1] + (uint)(uVar2 < uVar5)) {
            uVar7 = uVar5 - uVar2;
          }
          else {
            uVar14 = FUN_000082c8(param_1,(uint)param_2[2],uVar5,param_3[1]);
            *param_3 = (uint)((ulonglong)uVar14 >> 0x20);
            param_3[1] = (uint)uVar14;
          }
        }
        else {
          if ((param_3[1] | *param_3) != 0) {
            do {
              lVar15 = FUN_000082c8(param_1,(uint)param_2[2],*param_3,param_3[1]);
              *param_3 = (uint)((ulonglong)lVar15 >> 0x20);
              param_3[1] = (uint)lVar15;
            } while (lVar15 != 0);
          }
        }
      }
      if ((uVar8 - (uVar9 + (uVar11 < uVar1))) +
          (uint)(*(uint *)(param_1 + puVar3[2] * 4 + 0x14) < uVar13) != 0) {
        *(uint *)(param_1 + puVar3[2] * 4 + 0x14) = uVar13;
      }
      iVar6 = (uint)*param_1 * 0x1c + 0x18;
      if (uVar7 <= *(uint *)(PTR_DAT_000912d4 + iVar6)) {
        uVar7 = *(uint *)(PTR_DAT_000912d4 + iVar6);
      }
      *(uint *)(PTR_DAT_000912d4 + iVar6) = uVar7;
      return 1;
    }
  }
  return 0;
}



undefined4 FUN_00007568(byte *param_1,uint param_2,int param_3,int *param_4,uint *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  char **ppcVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  uint local_30;
  uint uStack44;
  
  if (DAT_000912e0 == '\0') {
    DAT_000912e0 = '\x01';
    if ((~param_1[1] & 0x7f) == 0) {
      uVar1 = FUN_00007a90(param_1,param_2,param_3,(byte *)param_4,param_5);
      DAT_000912e0 = 0;
      return uVar1;
    }
    ppcVar4 = (char **)0x0;
    if (param_4 != (int *)0x0) {
      if (DAT_000912ec == (char **)0x0) {
        uVar1 = FUN_0000d6de(param_4);
        uVar2 = FUN_0000d6e6(param_4);
        ppcVar4 = (char **)FUN_0000d630(uVar2,uVar1);
        DAT_000912ec = ppcVar4;
      }
      else {
        uVar1 = FUN_0000d6e6(param_4);
        uVar2 = FUN_0000d6de(param_4);
        FUN_0000d748(DAT_000912ec,uVar2,uVar1);
        ppcVar4 = DAT_000912ec;
      }
    }
    local_30 = 0;
    uStack44 = 0;
    if ((((uint)param_1[1] & 7) < 8) &&
       (FUN_00007a90(&DAT_00095410 + ((uint)param_1[1] & 7) * 0x1c,param_2,param_3,(byte *)ppcVar4,
                     &local_30), (local_30 | uStack44) == 0)) {
      *param_5 = 0;
      param_5[1] = 0;
      uVar1 = FUN_00007a90(param_1,param_2,param_3,(byte *)param_4,param_5);
      if ((param_5[1] | *param_5) != 0) {
        do {
          uVar5 = *param_5;
          uVar6 = param_5[1];
          pbVar3 = (byte *)FUN_000083e4((int)param_1,param_2);
          lVar7 = FUN_00007230(param_1,param_2,*(undefined4 *)(pbVar3 + (uint)*pbVar3 * 4 + 4),
                               *(undefined4 *)(pbVar3 + (uint)*pbVar3 * 4 + 4),uVar5,uVar6);
          *param_5 = (uint)((ulonglong)lVar7 >> 0x20);
          param_5[1] = (uint)lVar7;
        } while (lVar7 != 0);
      }
      DAT_000912e0 = 0;
      return uVar1;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00007680(void)

{
  byte bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  
  FUN_0000d758();
  uVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar4 = getCurrentExceptionNumber();
    uVar4 = uVar4 & 0x1f;
  }
  bVar1 = *(byte *)(DAT_000912f0 + (uVar4 - 0x10) * 2);
  uVar8 = (uint)bVar1;
  uVar4 = (uint)*(byte *)(DAT_000912f0 + (uVar4 - 0x10) * 2 + 1);
  puVar6 = PTR_DAT_000912d0 + uVar8 * 0x40;
  if (bVar1 != 0xff) {
    FUN_000065ec(0xc2,uVar8,uVar4,(uint)(byte)puVar6[0x31],0);
    *(int *)(puVar6 + 0x34) = *(int *)(puVar6 + 0x34) + 1;
    **(uint **)(puVar6 + 0x3c) = **(uint **)(puVar6 + 0x3c) | 1 << uVar4;
    FUN_0000d758();
    uVar3 = _DAT_00083000;
    uVar7 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    iVar5 = *(int *)(puVar6 + 0x3c);
    *(undefined4 *)(iVar5 + 0x18) = uVar3;
    *(uint *)(iVar5 + 0x1c) = uVar7;
    *(uint *)(puVar6 + 0x38) = *(uint *)(puVar6 + 0x38) | 1 << uVar4;
    uVar4 = *(uint *)(*(int *)(puVar6 + 0x14) + uVar4 * 4);
    *(int *)(&DAT_e000e180 + (uVar4 >> 5) * 4) = 1 << (uVar4 & 0x1f);
    FUN_00017654(uVar8,1);
    FUN_0001a7ec();
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int FUN_000077a4(int param_1)

{
  return (uint)*(byte *)(param_1 + 2) + **_FUN_000077b4;
}



void FUN_000077b4(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int *local_24;
  
  if (*(char *)((int)param_1 + 0x39) == '\0') {
    return;
  }
  uVar1 = 0;
  do {
    if (param_1[uVar1 * 4 + 0x1b] != 0) {
      local_24 = (int *)0x0;
      uVar2 = 0;
      FUN_000065ec(0xdd,param_1[0xd],0,0,0);
      *(undefined *)(param_1 + 0x18) = 2;
      *(undefined *)((int)param_1 + 0x39) = 0;
      FUN_00009246(param_1,0,uVar2,local_24);
      return;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 3);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00007800(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  undefined in_stack_ffffff98;
  undefined3 in_stack_ffffff99;
  uint uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  uint uStack88;
  undefined4 uStack84;
  uint local_40;
  undefined4 *puStack48;
  
  uVar11 = *(uint *)(param_1 + 4);
  uVar7 = *(uint *)(param_1 + 8);
  uVar4 = (uVar11 << 0x11) >> 0x1c;
  if (uVar4 == 4) {
    uVar7 = uVar7 & 0xff;
    uVar4 = *(int *)(param_1 + 0xc) + uVar7 & 0xff;
    if (uVar4 <= uVar7) {
      return;
    }
    do {
      if (((*(uint *)(param_1 + 4) & 0x8000) == 0) &&
         (uVar11 = *(uint *)(uVar7 * 0x1000 + 0x61000000), uVar7 * 0x1000 - 1 < 0x300fff)) {
        uStack88 = uVar11 & 0xffff | uVar11 << 0x10;
        FUN_000065ec(0x2c1,*(undefined4 *)(param_1 + 4),uVar7,uStack88,0);
      }
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < uVar4);
    return;
  }
  if (uVar4 == 2) {
    uVar12 = uVar7 + *(int *)(param_1 + 0xc);
    uVar4 = uVar7;
    if (uVar12 <= uVar7) {
      return;
    }
    do {
      uStack88 = 0;
      if ((uVar4 & 3) == 0) {
        FUN_0000c120();
      }
      if (uVar4 + 4 < uVar12) {
        uVar5 = 4;
      }
      else {
        uVar5 = uVar12 - uVar4;
      }
                    // WARNING: Ignoring partial resolution of indirect
      uVar14 = uVar5 & 0xff;
      iVar6 = FUN_00006730((byte)(uVar7 >> 0x10),0,(ushort)uVar4,(undefined *)&uStack88,
                           CONCAT31(in_stack_ffffff99,in_stack_ffffff98),(int *)0x0);
      if ((iVar6 == 0) && ((*(uint *)(param_1 + 4) & 0x8000) == 0)) {
        uVar11 = uVar11 & 0xffff | (uVar5 & 0xff) << 0x10;
                    // WARNING: Ignoring partial resolution of indirect
        uVar15 = 0;
        FUN_000065ec(0x2c1,uVar11,uVar4,uStack88,CONCAT31(in_stack_ffffff99,in_stack_ffffff98));
      }
      uVar4 = uVar4 + 4;
    } while (uVar4 < uVar12);
    return;
  }
  if (uVar4 == 3) {
    FUN_0000225c();
    return;
  }
  if (uVar4 != 5) {
    if (uVar4 != 6) {
      if (uVar4 == 8) {
        _DAT_000904e0 = uVar7;
      }
      return;
    }
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  local_40 = 0;
  if (DAT_000912cc == 0) {
    return;
  }
  do {
    uVar4 = 0;
    pbVar8 = PTR_DAT_000912d8 + local_40 * 0x1c;
    uVar11 = uVar11 & 0xffff | 0x10000;
    pbVar13 = *(byte **)(pbVar8 + 0xc);
    uStack84 = *(undefined4 *)(PTR_DAT_000912d4 + (uint)*pbVar8 * 0x1c);
    bVar3 = (byte)(PTR_DAT_000912d4 + (uint)*pbVar8 * 0x1c)[1] >> 2;
    puVar9 = *(undefined4 **)(pbVar8 + 8);
    if (bVar3 != 0) {
      do {
        puVar10 = puVar9;
        if (puVar9 != (undefined4 *)0x0) {
          puVar10 = puVar9 + 1;
                    // WARNING: Ignoring partial resolution of indirect
          uVar15 = *puVar9;
          FUN_000065ec(0x2c0,uVar11,uStack84,*(int *)(pbVar8 + 4) << 0x10 | uVar4,
                       CONCAT31(in_stack_ffffff99,in_stack_ffffff98));
        }
        uVar4 = uVar4 + 1 & 0xff;
        puVar9 = puVar10;
      } while (uVar4 < bVar3);
    }
    bVar3 = 0;
    if (pbVar8[3] != 0) {
      do {
        if (pbVar13 != (byte *)0x0) {
          puStack48 = *(undefined4 **)(pbVar13 + (~(uint)*pbVar13 & 1) * 4 + 4);
          bVar1 = pbVar13[1];
          uVar4 = 0;
          uStack84 = *(undefined4 *)(PTR_DAT_000912d4 + (uint)*pbVar8 * 0x1c);
          bVar2 = (byte)(PTR_DAT_000912d4 + (uint)*pbVar8 * 0x1c)[1] >> 2;
          puVar9 = *(undefined4 **)(pbVar13 + ((uint)*pbVar13 & 1) * 4 + 4);
          if (bVar2 != 0) {
            do {
              puVar10 = puVar9;
              if (puVar9 != (undefined4 *)0x0) {
                puVar10 = puVar9 + 1;
                    // WARNING: Ignoring partial resolution of indirect
                uVar15 = *puVar9;
                FUN_000065ec(0x2c0,uVar11 & 0xffff | 0x20000,uStack84,
                             *(int *)(pbVar8 + 4) << 0x10 | (uint)bVar1 << 8 | uVar4,
                             CONCAT31(in_stack_ffffff99,in_stack_ffffff98));
              }
              uVar4 = uVar4 + 1 & 0xff;
              puVar9 = puVar10;
            } while (uVar4 < bVar2);
          }
          uVar11 = uVar11 & 0xffff | 0x30000;
          uVar4 = 0;
          uVar15 = *(undefined4 *)(PTR_DAT_000912d4 + (uint)*pbVar8 * 0x1c);
          bVar2 = (byte)(PTR_DAT_000912d4 + (uint)*pbVar8 * 0x1c)[1] >> 2;
          puVar9 = puStack48;
          if (bVar2 != 0) {
            do {
              puVar10 = puVar9;
              if (puVar9 != (undefined4 *)0x0) {
                puVar10 = puVar9 + 1;
                    // WARNING: Ignoring partial resolution of indirect
                uVar16 = *puVar9;
                FUN_000065ec(0x2c0,uVar11,uVar15,
                             *(int *)(pbVar8 + 4) << 0x10 | (uint)bVar1 << 8 | uVar4,
                             CONCAT31(in_stack_ffffff99,in_stack_ffffff98));
              }
              uVar4 = uVar4 + 1 & 0xff;
              puVar9 = puVar10;
            } while (uVar4 < bVar2);
          }
          pbVar13 = *(byte **)(pbVar13 + 0xc);
        }
        bVar3 = bVar3 + 1;
      } while (bVar3 < pbVar8[3]);
    }
    local_40 = local_40 + 1 & 0xff;
  } while (local_40 < DAT_000912cc);
  return;
}



undefined4 FUN_00007a90(byte *param_1,uint param_2,int param_3,byte *param_4,undefined4 *param_5)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  byte **ppbVar13;
  byte **ppbVar14;
  bool bVar15;
  bool bVar16;
  undefined8 uVar17;
  byte *local_60;
  uint local_5c;
  byte *local_58;
  undefined *local_54;
  undefined *local_50;
  uint local_4c;
  uint local_48;
  undefined4 local_44;
  int iStack64;
  byte *local_3c;
  uint local_38;
  byte *local_34;
  uint local_30;
  int iStack44;
  byte *local_28;
  
  ppbVar13 = &local_60;
  ppbVar14 = &local_60;
  local_34 = param_1;
  local_30 = param_2;
  iStack44 = param_3;
  local_28 = param_4;
  pbVar3 = (byte *)FUN_000083e4((int)param_1,param_2);
  local_50 = PTR_DAT_000912d4 + (uint)*local_34 * 0x1c;
  bVar15 = local_28 != (byte *)0x0;
  uVar4 = (uint)*pbVar3;
  local_5c = ~uVar4 & 1;
  bVar1 = pbVar3[(uVar4 & 1) + 2];
  pbVar7 = (byte *)(param_3 + 1U & 0xff);
  bVar2 = pbVar3[local_5c + 2];
  if ((byte *)(uint)bVar1 == pbVar7) {
LAB_00007afe:
    uVar9 = uVar4 & 1;
  }
  else {
    uVar9 = local_5c;
    if ((byte *)(uint)bVar2 != pbVar7) {
      if (!bVar15) {
        return 0;
      }
      if ((bVar1 == 0) || (((bVar2 != 0 && (bVar1 == 1)) && (pbVar7 == &DAT_00000003))))
      goto LAB_00007afe;
    }
  }
  local_60 = (byte *)(uint)bVar1;
  local_58 = (byte *)(uint)bVar2;
  pbVar7 = pbVar3 + uVar9;
  uVar11 = param_3 + 1U & 0xff;
  uVar5 = (uint)pbVar7[2];
  iVar10 = 0;
  uVar4 = uVar4 & 1;
  local_4c = uVar5;
  if (!bVar15) {
    uVar5 = 0;
  }
  if (bVar15) {
    uVar8 = uVar9;
    if (uVar5 == uVar11) {
LAB_00007b58:
      iVar10 = *(int *)(pbVar3 + uVar8 * 4 + 4);
    }
    else {
      if (uVar11 == 3) {
        uVar8 = uVar9 ^ 1;
        if (pbVar3[uVar8 + 2] == 1) goto LAB_00007b58;
        if (uVar5 == 1) {
          iVar10 = *(int *)(pbVar3 + uVar9 * 4 + 4);
        }
      }
    }
    bVar16 = uVar9 == uVar4 && uVar11 == 3;
    if (uVar9 == uVar4 && uVar11 == 3) {
      bVar16 = pbVar7[2] == 1;
    }
    if (!bVar16) {
      pbVar7[2] = (byte)uVar11;
    }
    if (*(int *)(pbVar3 + uVar9 * 4 + 4) == 0) {
      iVar6 = FUN_00000154((uint)(byte)local_50[4]);
      *(int *)(pbVar3 + uVar9 * 4 + 4) = iVar6;
    }
  }
  else {
    pbVar7[2] = (byte)uVar5;
  }
  bVar16 = true;
  if (local_60 == (byte *)0x0 && uVar11 == 3) {
    if (uVar4 != uVar9) goto LAB_00007bb4;
    *pbVar3 = (byte)local_5c;
    bVar16 = false;
  }
  else {
    if ((uVar9 != uVar4) && (local_4c != 0 || uVar11 != 1)) {
LAB_00007bb4:
      bVar16 = false;
    }
  }
  local_54 = (undefined *)0x0;
  if (local_60 == (byte *)0x0) {
LAB_00007bfe:
    if (bVar15) goto LAB_00007c04;
  }
  else {
    if (((local_4c == 0) && (uVar11 == 1)) || (!bVar15)) {
      local_54 = *(undefined **)(pbVar3 + uVar4 * 4 + 4);
      goto LAB_00007bfe;
    }
    ppbVar13 = &local_60;
    if (bVar16) {
      iVar6 = -((uint)(byte)local_50[4] + 7 & 0xfffffff8);
      ppbVar13 = (byte **)((int)&local_60 + iVar6);
      local_54 = (undefined *)((int)&local_60 + iVar6);
      FUN_0000044c((byte **)((int)&local_60 + iVar6),*(undefined4 *)(pbVar3 + uVar4 * 4 + 4));
    }
LAB_00007c04:
    pbVar7 = pbVar3 + uVar9 * 4;
    if (*(int *)(pbVar7 + 4) == 0) {
      iVar6 = FUN_00000154((uint)(byte)local_50[4],*(undefined *)ppbVar13);
      *(int *)(pbVar7 + 4) = iVar6;
    }
    local_38 = local_30;
    local_60 = local_28;
    iStack64 = *(int *)(pbVar7 + 4);
    puVar12 = (undefined4 *)(PTR_DAT_000912d4 + (uint)*local_34 * 0x1c);
    if (iVar10 == 0) {
      FUN_000005cc(iStack64,(uint)*(byte *)(puVar12 + 1));
    }
    else {
      if (iVar10 != iStack64) {
        FUN_0000044c(iStack64,iVar10,(uint)*(byte *)(puVar12 + 1));
      }
    }
    local_50 = (undefined *)puVar12[4];
    local_4c = *(uint *)(local_34 + 4);
    local_48 = local_38;
    local_44 = 0;
    local_3c = local_60;
    *(undefined4 *)((undefined *)ppbVar13 + -8) = 0;
    FUN_000065ec(0xd4,*puVar12,local_4c,0,*(undefined4 *)((undefined *)ppbVar13 + -8));
    (*(code *)puVar12[2])(&local_50);
    ppbVar14 = ppbVar13;
  }
  if (!bVar16) {
    return 0;
  }
  uVar4 = uVar9;
  if ((bVar15) || (uVar4 = local_5c, local_58 == &UNK_00000002 || local_58 == &UNK_00000001)) {
    iVar10 = *(int *)(pbVar3 + uVar4 * 4 + 4);
  }
  else {
    iVar10 = 0;
  }
  bVar1 = *pbVar3;
  if (1 < bVar1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (pbVar3[(uint)bVar1 + 2] == 0) {
    uVar4 = (uint)bVar1 ^ 1;
    if ((pbVar3[uVar4 + 2] != 0) && (pbVar3[uVar4 + 2] != 3)) {
      *pbVar3 = (byte)uVar4;
      goto LAB_00007ce4;
    }
  }
  *pbVar3 = (byte)uVar9;
LAB_00007ce4:
  *(undefined4 *)((undefined *)ppbVar14 + -8) = 0;
  *(undefined4 *)((undefined *)ppbVar14 + -4) = 0;
  uVar17 = FUN_00007230(local_34,local_30,local_54,iVar10,
                        *(undefined4 *)((undefined *)ppbVar14 + -8),
                        *(undefined4 *)((undefined *)ppbVar14 + -4));
  *param_5 = (int)((ulonglong)uVar17 >> 0x20);
  param_5[1] = (int)uVar17;
  return 1;
}



undefined8 FUN_00007d88(byte *param_1,uint param_2,int param_3)

{
  uint uVar1;
  byte *pbVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if ((~(uint)param_1[1] & 0x7f) == 0) {
    uVar4 = FUN_000080c8(param_1,param_2,param_3);
    return uVar4;
  }
  uVar1 = (uint)param_1[1] & 7;
  if ((uVar1 < 8) &&
     (lVar3 = FUN_000080c8(&DAT_00095410 + uVar1 * 0x1c,param_2,param_3), lVar3 == 0)) {
    lVar3 = FUN_000080c8(param_1,param_2,param_3);
    while (lVar3 != 0) {
      pbVar2 = (byte *)FUN_000083e4((int)param_1,param_2);
      lVar3 = FUN_00007230(param_1,param_2,*(undefined4 *)(pbVar2 + (uint)*pbVar2 * 4 + 4),
                           *(undefined4 *)(pbVar2 + (uint)*pbVar2 * 4 + 4),
                           (int)((ulonglong)lVar3 >> 0x20),(int)lVar3);
    }
    return 0;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00007e0c(uint **param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  char *pcVar5;
  uint *puVar6;
  uint uVar7;
  uint **ppuVar8;
  uint *puVar9;
  uint uStack28;
  
  ppuVar8 = (uint **)*param_1;
  if ((ppuVar8 != (uint **)0x0) && (param_1[1] < *ppuVar8)) {
    puVar9 = (uint *)ppuVar8[1][(int)param_1[1] * 3];
    puVar4 = (uint *)(ppuVar8[1] + (int)param_1[1] * 3)[1];
    puVar6 = param_1[2];
    if ((puVar9 != (uint *)0x0) && (puVar6 < DAT_000912c4)) {
      piVar2 = (int *)puVar4[(int)puVar6];
      if (piVar2 == (int *)0x0) {
        if (puVar6 < &DAT_00000004) {
          pcVar5 = (&PTR_DAT_000912f4)[(int)puVar6 * 2];
        }
        else {
          pcVar5 = "unknown client via rpm-npa adapter";
        }
        piVar2 = FUN_0000e418(puVar9,(uint *)pcVar5,0x40,0,0);
        *(int **)(puVar4 + (int)puVar6) = piVar2;
        if (piVar2 == (int *)0x0) goto LAB_00007e7e;
      }
      if (*(char *)(ppuVar8 + 2) == '\0') {
        return;
      }
      iVar3 = FUN_0000f02c((int)piVar2,0x1023,&stack0xffffffe0);
      if ((iVar3 == 0) && (uStack28 != 0)) {
        FUN_0000d758();
        uVar1 = _DAT_00083000;
        uVar7 = _DAT_00083004 & 0xffffff;
        FUN_0001a7ec();
        puVar4 = (uint *)(uVar1 + uStack28);
        puVar6 = (uint *)(uVar7 + CARRY4(uVar1,uStack28));
      }
      else {
        puVar4 = (uint *)0x0;
        puVar6 = puVar4;
      }
      param_1[8] = puVar4;
      param_1[9] = puVar6;
      return;
    }
  }
LAB_00007e7e:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00007ec8(void)

{
  FUN_00017124(0x74736574,1,4,&LAB_00006f02_1,&LAB_00006f00_1,0);
  return;
}



undefined8
FUN_00007ef0(byte *param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined *puVar6;
  int *piVar7;
  code *pcVar8;
  int *apiStack120 [2];
  undefined *local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  int local_5c;
  undefined *local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_48;
  undefined4 local_44;
  byte *local_40;
  byte *pbStack52;
  uint uStack48;
  uint uStack44;
  undefined4 local_28;
  
  local_28 = param_4;
  uStack44 = param_3;
  uStack48 = param_2;
  pbStack52 = param_1;
  puVar6 = PTR_DAT_000912d4 + (uint)*param_1 * 0x1c;
  if (((DAT_000912c4 <= param_2) && (param_2 < DAT_000912c4 + param_1[2])) && (param_3 != 0)) {
    piVar7 = (int *)(*(int *)(param_1 + 0x10) + (param_2 - DAT_000912c4) * 8);
    if (*piVar7 == 0) {
      uVar3 = (uint)(byte)puVar6[4];
LAB_00007f4a:
      if (uVar3 == param_3) {
        iVar1 = -(param_3 + 7 & 0xfffffff8);
        local_70 = (undefined *)((int)&local_70 + iVar1);
        FUN_0000044c((undefined **)((int)&local_70 + iVar1),piVar7[1],param_3);
        FUN_0000044c(piVar7[1],local_28,param_3);
        local_68 = *(undefined4 *)(puVar6 + 0x10);
        local_64 = *(undefined4 *)(param_1 + 4);
        local_60 = param_2;
        local_5c = *piVar7;
        local_58 = local_70;
        local_54 = piVar7[1];
        local_48 = param_5;
        local_50 = *(undefined4 *)(param_1 + 8);
        local_44 = param_6;
        local_40 = param_1;
        iVar2 = -((uint)(byte)puVar6[4] + 7 & 0xfffffff8);
        FUN_0000044c((int)&local_70 + iVar2 + iVar1,*(undefined4 *)(param_1 + 8));
        pcVar8 = *(code **)(puVar6 + 0xc);
        FUN_00016b82(local_40,local_60,&local_6c,&local_70,
                     *(undefined *)((int)&local_70 + iVar2 + iVar1));
        if (local_5c == local_6c) {
          iVar5 = local_54;
          if (local_70 != (undefined *)0x0) {
            if (local_54 == 0) goto LAB_00007fde;
            iVar5 = FUN_00000320(local_70,local_54,param_3,
                                 *(undefined *)((int)&local_70 + iVar2 + iVar1));
          }
          if (iVar5 == 0) {
            (*pcVar8)(&local_68);
            if ((param_1[1] & 0x80) == 0) {
              *(undefined4 *)((int)apiStack120 + iVar2 + iVar1) = *(undefined4 *)(param_1 + 8);
              DAT_000912e4 = FUN_00017184(DAT_000912e4,(int)param_1,(uint)(byte)puVar6[4],
                                          (int *)((int)&local_70 + iVar2 + iVar1),
                                          *(int **)((int)apiStack120 + iVar2 + iVar1));
            }
            return CONCAT44(local_48,local_44);
          }
        }
      }
    }
    else {
      piVar4 = *(int **)(puVar6 + 0x14);
      while (piVar4 != (int *)0x0) {
        if (*piVar4 == *piVar7) {
          uVar3 = piVar4[1];
          goto LAB_00007f4a;
        }
        piVar4 = (int *)piVar4[2];
      }
    }
  }
LAB_00007fde:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined8 FUN_000080c8(byte *param_1,uint param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  undefined8 uVar6;
  
  pbVar2 = (byte *)FUN_000083e4((int)param_1,param_2);
  uVar5 = (uint)*pbVar2 & 1;
  uVar3 = ~(uint)*pbVar2 & 1;
  if (param_1 == (byte *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  pbVar4 = *(byte **)(param_1 + 0xc);
  while( true ) {
    if (pbVar4 == (byte *)0x0) {
      return 0;
    }
    if ((uint)pbVar4[1] == param_2) break;
    pbVar4 = *(byte **)(pbVar4 + 0xc);
  }
  bVar1 = pbVar4[(~(uint)*pbVar4 & 1) + 2];
  if (param_3 == 0) {
    if (bVar1 != 2) {
      return 0;
    }
  }
  else {
    if (bVar1 == 0 || bVar1 == 2) {
      return 0;
    }
  }
  if ((pbVar2[uVar3 + 2] == 3) && (pbVar2[uVar3 + 2] = 1, pbVar2[uVar5 + 2] == 1)) {
    pbVar2[uVar5 + 2] = 0;
  }
  *pbVar2 = (byte)uVar3;
  uVar6 = FUN_00007230(param_1,param_2,*(undefined4 *)(pbVar2 + uVar5 * 4 + 4),
                       *(int *)(pbVar2 + uVar3 * 4 + 4),0,0);
  return uVar6;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000816c(void)

{
  byte bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  
  FUN_0000d758();
  uVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar4 = getCurrentExceptionNumber();
    uVar4 = uVar4 & 0x1f;
  }
  bVar1 = *(byte *)(DAT_000912f0 + (uVar4 - 0x10) * 2);
  uVar8 = (uint)bVar1;
  uVar4 = (uint)*(byte *)(DAT_000912f0 + (uVar4 - 0x10) * 2 + 1);
  puVar6 = PTR_DAT_000912d0 + uVar8 * 0x40;
  if (bVar1 != 0xff) {
    *(int *)(puVar6 + 0x34) = *(int *)(puVar6 + 0x34) + -1;
    **(uint **)(puVar6 + 0x3c) = **(uint **)(puVar6 + 0x3c) & ~(1 << uVar4);
    if (*(int *)(puVar6 + 0x34) == 0) {
      *(int *)(*(int *)(puVar6 + 0x3c) + 4) = *(int *)(*(int *)(puVar6 + 0x3c) + 4) + 1;
      FUN_0000d758();
      uVar3 = _DAT_00083000;
      uVar7 = _DAT_00083004 & 0xffffff;
      FUN_0001a7ec();
      iVar5 = *(int *)(puVar6 + 0x3c);
      *(undefined4 *)(iVar5 + 8) = uVar3;
      *(uint *)(iVar5 + 0xc) = uVar7;
    }
    FUN_000065ec(0xc4,uVar8,uVar4,(uint)(byte)puVar6[0x31],0);
    if (puVar6[0x31] == '\0') {
      _DAT_00080018 = 1 << *(int *)(*(int *)(puVar6 + 0x18) + uVar4 * 4);
      _DAT_00080014 = 1 << *(int *)(*(int *)(puVar6 + 0x20) + uVar4 * 4);
    }
    else {
      FUN_00009da8(*(int *)(PTR_DAT_000912d0 + uVar8 * 0x40 + 0x28),3,(uint *)0x0,0x646d63);
    }
    FUN_0000d57c(*(int *)(*(int *)(puVar6 + 0x1c) + uVar4 * 4),&LAB_0000801c_1);
    FUN_0000d4f0(*(uint *)(*(int *)(puVar6 + 0x1c) + uVar4 * 4),3);
    FUN_0001a7ec();
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 * FUN_0000826c(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (((DAT_00091318 & 1) == 0) && (iVar1 = FUN_0000a92e(&DAT_00091318), iVar1 != 0)) {
    puVar2 = (undefined4 *)FUN_0000a6f4(0xc);
    puVar2[1] = 8;
    puVar2[2] = 0;
    puVar3 = (undefined4 *)FUN_00000154(0xa0);
    *(undefined4 **)puVar2 = puVar3;
    FUN_00000610(puVar3,0xa0);
    DAT_000954fc = *puVar2;
    DAT_00095500 = puVar2[1];
    DAT_00095504 = puVar2[2];
  }
  return &DAT_000954fc;
}



undefined8 FUN_000082c8(byte *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  undefined8 uVar2;
  
  pbVar1 = (byte *)FUN_000083e4((int)param_1,param_2);
  uVar2 = FUN_00007230(param_1,param_2,*(undefined4 *)(pbVar1 + (uint)*pbVar1 * 4 + 4),
                       *(undefined4 *)(pbVar1 + (uint)*pbVar1 * 4 + 4),param_3,param_4);
  return uVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_000082f4(byte *param_1,undefined4 param_2)

{
  uint *local_38;
  undefined4 local_34;
  undefined4 uStack48;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  byte *pbStack16;
  
  local_38 = *(uint **)(*(int *)(*_FUN_00008330 + 0x10) + (uint)*param_1 * 0x1c + 0x10);
  local_34 = *(undefined4 *)(param_1 + 4);
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_18 = 0;
  local_14 = 0;
  uStack48 = param_2;
  pbStack16 = param_1;
  FUN_00007e0c(&local_38);
  return CONCAT44(local_18,local_14);
}



void FUN_00008330(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  FUN_0000d758();
  piVar1 = DAT_000904c4;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)FUN_0000a6f4(0x10);
      *(int **)piVar1 = DAT_000904c4;
      piVar1[1] = param_1;
      piVar1[2] = param_1;
      piVar1[3] = param_3;
      DAT_000904c4 = piVar1;
      FUN_0001a7ec();
      return;
    }
    if (piVar1[1] == param_1) break;
    piVar1 = (int *)*piVar1;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 FUN_000083ac(byte *param_1,uint param_2,int param_3)

{
  byte bVar1;
  
  if (param_1 == (byte *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  do {
    param_1 = *(byte **)(param_1 + 0xc);
    if (param_1 == (byte *)0x0) {
      return 0;
    }
  } while ((uint)param_1[1] != param_2);
  bVar1 = param_1[(~(uint)*param_1 & 1) + 2];
  if (param_3 == 0) {
    if (bVar1 != 2) {
      return 0;
    }
  }
  else {
    if (bVar1 == 0 || bVar1 == 2) {
      return 0;
    }
  }
  return 1;
}



void FUN_000083e4(int param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    while (iVar1 != 0) {
      if ((uint)*(byte *)(iVar1 + 1) == param_2) {
        return;
      }
      iVar1 = *(int *)(iVar1 + 0xc);
    }
    if ((*(byte *)(param_1 + 3) < DAT_000912c4) &&
       (puVar2 = (undefined4 *)FUN_00000154(0x10), puVar2 != (undefined4 *)0x0)) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      *(undefined *)((int)puVar2 + 1) = (char)param_2;
      puVar2[3] = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 **)(param_1 + 0xc) = puVar2;
      *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + '\x01';
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 * FUN_00008434(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  *param_1 = 0;
  uVar2 = **_FUN_00008464 << 2;
  puVar1 = (undefined4 *)FUN_00000154(uVar2);
  *(undefined4 **)(param_1 + 1) = puVar1;
  FUN_00000610(puVar1,uVar2);
  puVar1 = (undefined4 *)FUN_00000154(uVar2);
  *(undefined4 **)(param_1 + 2) = puVar1;
  FUN_00000610(puVar1,uVar2);
  return param_1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00008464(char *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  byte *pbVar1;
  char cVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint uVar13;
  bool bVar14;
  longlong lVar15;
  uint local_84;
  uint uStack128;
  char *local_7c;
  uint *puStack120;
  undefined4 local_74;
  bool local_70;
  int *local_6c;
  char *pcStack104;
  uint local_64;
  uint uStack96;
  int local_5c;
  undefined4 auStack88 [3];
  char *pcStack76;
  char *local_48;
  uint uStack68;
  undefined4 uStack64;
  uint uStack20;
  
  pcStack76 = param_1;
  local_48 = param_1;
  uStack68 = param_3;
  uStack64 = param_4;
  uStack20 = param_3;
  FUN_000065ec(199,*(undefined4 *)(param_1 + 0x30),(uint)(byte)param_1[0x38],
               (uint)(byte)param_1[0x39],(uint)(byte)param_1[0x80]);
  FUN_0000c3ae();
  if (param_1[0x48] == '\0') {
    param_1[0x48] = '\x01';
    param_1[0x49] = '\0';
    *(uint *)(param_1 + 0x4c) = DAT_000912e4;
    FUN_0000d758();
    uVar8 = _DAT_00083000;
    uVar7 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    *(uint *)(param_1 + 0x50) = uVar8;
    *(uint *)(param_1 + 0x54) = uVar7;
  }
  cVar2 = param_1[0x2e];
  if (cVar2 == '\x01') {
    param_1[0x38] = param_1[0x39];
    local_70 = param_1[0x39] == '\0';
    puStack120 = &uStack68;
    local_74 = *(undefined4 *)(param_1 + 0x30);
    local_6c = (int *)(param_1 + 0x3c);
    pcStack104 = param_1 + 0x40;
    local_7c = local_48;
    if ((param_1[0x39] != '\x01') ||
       (*(int *)(PTR_DAT_000912d0 + *(int *)(param_1 + 0x30) * 0x40 + 0x38) == 0)) {
      if ((!local_70) && ((*(uint *)(param_1 + 0x78) | *(uint *)(param_1 + 0x7c)) != 0)) {
        FUN_0000d758();
        uVar8 = _DAT_00083000;
        uVar7 = _DAT_00083004 & 0xffffff;
        FUN_0001a7ec();
        iVar6 = *local_6c;
        if (param_1[0x80] != '\0') {
          local_5c = *local_6c;
          if (param_1[0x39] == '\0') {
            piVar5 = FUN_000071d0();
            FUN_00008fb0(piVar5,*(int *)(param_1 + 0x4c),*(int *)(param_1 + 0x44),auStack88,
                         &local_5c);
          }
          else {
            piVar5 = FUN_0000826c();
            FUN_00008fb0(piVar5,*(int *)(param_1 + 0x4c),*(int *)(param_1 + 0x44),auStack88,
                         &local_5c);
          }
        }
        uVar10 = *(uint *)(param_1 + 0x78);
        if ((*(int *)(param_1 + 0x7c) + (uint)(uVar8 < uVar10) <= uVar7) ||
           (*(int *)(param_1 + 0x7c) - (uVar7 + (uVar10 < uVar8)) <
            (uint)(uVar10 - uVar8 < (uint)(iVar6 << 1)))) goto LAB_000088fa;
      }
      if (param_1[0x39] == '\x01') {
        uVar8 = 0;
        do {
          uVar7 = (&DAT_00093978)[uVar8];
          while (uVar7 != 0) {
            iVar6 = count_leading_zeroes(uVar7);
            uVar7 = uVar7 & ~(1 << 0x1f - iVar6);
            local_84 = 0;
            uStack128 = 0;
            pbVar11 = PTR_DAT_000912d8 + ((0x1f - iVar6) + uVar8 * 0x20) * 0x1c;
            iVar6 = FUN_000083ac(pbVar11,*(uint *)(param_1 + 0x30),(uint)local_70);
            if (iVar6 != 0) {
              iVar6 = FUN_000073a0(pbVar11,&local_7c,&local_84);
              if (iVar6 == 0) {
                param_1[0x49] = '\x01';
                goto LAB_00008b26;
              }
              if ((uStack128 | local_84) != 0) {
                iVar6 = (int)((ulonglong)
                              ((longlong)(int)(pbVar11 + -(int)PTR_DAT_000912d8) * -0x6db6db6d +
                              ((longlong)(int)(pbVar11 + -(int)PTR_DAT_000912d8) << 0x20)) >> 0x20);
                uVar10 = (iVar6 >> 4) - (iVar6 >> 0x1f);
                if (0x9f < uVar10) goto LAB_0000884a;
                *(uint *)(param_1 + (uVar10 >> 5) * 4 + 0x60) =
                     1 << (uVar10 & 0x1f) | *(uint *)(param_1 + (uVar10 >> 5) * 4 + 0x60);
                FUN_000065ec(0xd9,*(undefined4 *)(param_1 + 0x30),
                             *(undefined4 *)(PTR_DAT_000912d4 + (uint)*pbVar11 * 0x1c),
                             *(undefined4 *)(pbVar11 + 4),0);
                FUN_000065ec(0xda,local_84,uStack128,0,0);
              }
              if (*(uint *)(param_1 + 0x5c) < uStack128 + (*(uint *)(param_1 + 0x58) < local_84)) {
                *(uint *)(param_1 + 0x58) = local_84;
                *(uint *)(param_1 + 0x5c) = uStack128;
              }
            }
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < 5);
      }
      uVar8 = 1;
      pbVar3 = FUN_00017fb4(0x326b6c63,0);
      pbVar11 = pbVar3;
      if (pbVar3 != (byte *)0x0) {
        pbVar11 = *(byte **)(pbVar3 + 8);
      }
      if (((pbVar3 == (byte *)0x0 || pbVar11 == (byte *)0x0) ||
          (uVar8 = FUN_00008cb8((int)param_1,&local_7c,pbVar3), uVar8 != 0)) &&
         ((pbVar11 = FUN_00017fb4(0x616f646c,10), pbVar11 == (byte *)0x0 || uVar8 == 0 ||
          (uVar8 = FUN_00008cb8((int)param_1,&local_7c,pbVar11), uVar8 != 0)))) {
        uVar10 = 0;
        uVar7 = DAT_000912cc;
        if (DAT_000912cc != 0) {
          do {
            pbVar12 = PTR_DAT_000912d8 + uVar10 * 0x1c;
            bVar14 = pbVar12 != (byte *)0x0;
            pbVar11 = PTR_DAT_000912d8;
            if (bVar14) {
              pbVar11 = *(byte **)(pbVar12 + 8);
            }
            pbVar1 = pbVar11;
            if (bVar14 && pbVar11 != (byte *)0x0) {
              pbVar1 = DAT_000904a0;
            }
            if ((bVar14 && pbVar11 != (byte *)0x0) && pbVar12 != pbVar1) {
              local_64 = 0;
              uStack96 = 0;
              iVar6 = FUN_000083ac(pbVar12,*(uint *)(param_1 + 0x30),(uint)local_70);
              if (iVar6 == 0) {
                uVar8 = 1;
              }
              else {
                uVar7 = FUN_000073a0(pbVar12,&local_7c,&local_64);
                if (uVar7 == 0) {
                  uVar8 = 0;
                  param_1[0x49] = '\x01';
                  break;
                }
                if ((uStack96 | local_64) != 0) {
                  iVar6 = (int)((ulonglong)
                                ((longlong)(int)(pbVar12 + -(int)PTR_DAT_000912d8) * -0x6db6db6d +
                                ((longlong)(int)(pbVar12 + -(int)PTR_DAT_000912d8) << 0x20)) >> 0x20
                               );
                  uVar8 = (iVar6 >> 4) - (iVar6 >> 0x1f);
                  if (0x9f < uVar8) goto LAB_0000884a;
                  *(uint *)(param_1 + (uVar8 >> 5) * 4 + 0x60) =
                       1 << (uVar8 & 0x1f) | *(uint *)(param_1 + (uVar8 >> 5) * 4 + 0x60);
                  FUN_000065ec(0xd9,*(undefined4 *)(param_1 + 0x30),
                               *(undefined4 *)(PTR_DAT_000912d4 + (uint)*pbVar12 * 0x1c),
                               *(undefined4 *)(pbVar12 + 4),0);
                  FUN_000065ec(0xda,local_64,uStack96,0,0);
                }
                uVar13 = *(uint *)(param_1 + 0x5c);
                uVar7 = *(uint *)(param_1 + 0x58);
                if (*(uint *)(param_1 + 0x5c) < uStack96 + (*(uint *)(param_1 + 0x58) < local_64)) {
                  uVar13 = uStack96;
                  uVar7 = local_64;
                }
                uVar8 = 1;
                *(uint *)(param_1 + 0x5c) = uVar13;
                *(uint *)(param_1 + 0x58) = uVar7;
              }
            }
            uVar10 = uVar10 + 1;
            uVar7 = DAT_000912cc;
          } while (uVar10 < DAT_000912cc);
        }
        if ((DAT_000904a0 == (byte *)0x0 || uVar8 == 0) ||
           (uVar7 = FUN_00008cb8((int)param_1,&local_7c,DAT_000904a0), uVar8 = uVar7, uVar7 != 0)) {
          if (pbVar3 != (byte *)0x0) {
            uVar7 = *(uint *)(pbVar3 + 8);
          }
          if (pbVar3 != (byte *)0x0 && uVar7 != 0) {
            lVar15 = FUN_000082f4(pbVar3,*(undefined4 *)(param_1 + 0x30));
            uVar7 = (uint)((ulonglong)lVar15 >> 0x20);
            if (lVar15 != 0) {
              iVar6 = (int)((ulonglong)
                            ((longlong)(int)(pbVar3 + -(int)PTR_DAT_000912d8) * -0x6db6db6d +
                            ((longlong)(int)(pbVar3 + -(int)PTR_DAT_000912d8) << 0x20)) >> 0x20);
              uVar10 = (iVar6 >> 4) - (iVar6 >> 0x1f);
              if (0x9f < uVar10) {
LAB_0000884a:
                    // WARNING: Subroutine does not return
                FUN_00000060();
              }
              *(uint *)(param_1 + (uVar10 >> 5) * 4 + 0x60) =
                   1 << (uVar10 & 0x1f) | *(uint *)(param_1 + (uVar10 >> 5) * 4 + 0x60);
              FUN_000065ec(0xd9,*(undefined4 *)(param_1 + 0x30),
                           *(undefined4 *)(PTR_DAT_000912d4 + (uint)*pbVar3 * 0x1c),
                           *(undefined4 *)(pbVar3 + 4),0);
              FUN_000065ec(0xda,uVar7,(int)lVar15,0,0);
            }
            if ((int)lVar15 + (uint)(*(uint *)(param_1 + 0x58) < uVar7) <= *(uint *)(param_1 + 0x5c)
               ) {
              lVar15 = CONCAT44(*(uint *)(param_1 + 0x58),*(uint *)(param_1 + 0x5c));
            }
            *(int *)(param_1 + 0x58) = (int)((ulonglong)lVar15 >> 0x20);
            *(int *)(param_1 + 0x5c) = (int)lVar15;
          }
          if (uVar8 == 0) goto LAB_00008b26;
          goto LAB_000088ea;
        }
      }
      param_1[0x49] = '\x01';
      goto LAB_00008b26;
    }
LAB_000088fa:
    param_1[0x49] = '\x01';
    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;
    FUN_000065ec(0xd8,*(uint *)(PTR_DAT_000912d0 + *(int *)(param_1 + 0x30) * 0x40 + 0x38) |
                      *(int *)(param_1 + 0x30) << 0x10,*(undefined4 *)(param_1 + 0x7c),
                 *(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x3c));
LAB_000088ea:
    param_1[0x2e] = '\x02';
LAB_000088f0:
    if ((param_1[0x39] == '\x01') &&
       (iVar6 = FUN_00009840(*(int *)(param_1 + 0x34),local_48,&uStack68), iVar6 == 0))
    goto LAB_00008b26;
    uVar8 = *(uint *)(param_1 + 0x5c) | *(uint *)(param_1 + 0x58);
    bVar14 = uVar8 == 0;
    if (bVar14) {
      uVar8 = 0;
    }
    if (bVar14) {
      *(uint *)(param_1 + 0x40) = uVar8;
      cVar2 = '\x04';
    }
    else {
      cVar2 = '\x03';
    }
    param_1[0x2e] = cVar2;
    if (!bVar14) {
LAB_0000894c:
      uVar8 = 0;
      do {
        pcVar9 = param_1 + uVar8 * 4;
        iVar6 = *(int *)(pcVar9 + 0x60);
        while (iVar6 != 0) {
          iVar6 = count_leading_zeroes(iVar6);
          pbVar11 = PTR_DAT_000912d8 + ((0x1f - iVar6) + uVar8 * 0x20) * 0x1c;
          lVar15 = FUN_000082c8(pbVar11,*(uint *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x58),
                                *(undefined4 *)(param_1 + 0x5c));
          if (lVar15 == 0) {
            *(uint *)(pcVar9 + 0x60) = *(uint *)(pcVar9 + 0x60) & ~(1 << 0x1f - iVar6);
            FUN_000065ec(0xdb,*(undefined4 *)(param_1 + 0x30),
                         *(undefined4 *)(PTR_DAT_000912d4 + (uint)*pbVar11 * 0x1c),
                         *(undefined4 *)(pbVar11 + 4),0);
          }
          iVar6 = *(int *)(pcVar9 + 0x60);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 <= DAT_000912cc >> 5);
      *(undefined4 *)(param_1 + 0x40) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      param_1[0x2e] = '\x04';
    }
  }
  else {
    if (cVar2 == '\x02') goto LAB_000088f0;
    if (cVar2 == '\x03') goto LAB_0000894c;
    if (cVar2 != '\x04') goto LAB_00008b26;
  }
  if (param_1[0x39] == '\x01') {
    bVar14 = false;
    if (*(int *)(param_1 + 0x30) == 0) {
      FUN_00002d30(0,1);
    }
  }
  else {
    bVar14 = true;
    if (*(int *)(param_1 + 0x30) == 0) {
      FUN_00002d30(0,0);
    }
  }
  FUN_0000d758();
  uVar8 = _DAT_00083000;
  uVar7 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  *(uint *)(param_1 + 0x18) = uVar8;
  *(uint *)(param_1 + 0x1c) = uVar7;
  uVar13 = 0;
  uVar10 = 0;
  if (param_1[5] != '\0') {
    uVar13 = *(uint *)(param_1 + 8);
    uVar10 = *(uint *)(param_1 + 0xc);
  }
  FUN_0000925c((int)param_1);
  param_1[0x2e] = '\0';
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  if (((uVar13 | uVar10) == 0) || (uVar7 + (uVar13 < uVar8) <= uVar10)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  FUN_000065ec(200,*(undefined4 *)(param_1 + 0x30),uVar10,uVar13,uVar4);
  FUN_0000c3ac();
  uVar10 = uVar8 - *(int *)(param_1 + 0x50);
  if (param_1[0x49] == '\0') {
    if (param_1[0x39] == '\0') {
      *(uint *)(*(int *)(PTR_DAT_000912d0 + *(int *)(param_1 + 0x30) * 0x40 + 0x3c) + 0x30) = uVar10
      ;
      piVar5 = FUN_000071d0();
      FUN_00009030(piVar5,*(uint *)(param_1 + 0x4c),*(int *)(param_1 + 0x44),DAT_000912e4,uVar10,1);
    }
    else {
      *(uint *)(*(int *)(PTR_DAT_000912d0 + *(int *)(param_1 + 0x30) * 0x40 + 0x3c) + 0x2c) = uVar10
      ;
      piVar5 = FUN_0000826c();
      FUN_00009030(piVar5,*(uint *)(param_1 + 0x4c),*(int *)(param_1 + 0x44),DAT_000912e4,uVar10,1);
    }
  }
  if (bVar14) {
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x7c) = 0;
    if (PTR_DAT_000912d0[*(uint *)(param_1 + 0x30) * 0x40 + 0x30] == '\x02') {
      iVar6 = FUN_0000db90(*(uint *)(param_1 + 0x30));
      *(undefined4 *)(iVar6 + 0x28) = 1;
      iVar6 = *(int *)(PTR_DAT_000912d0 + *(int *)(param_1 + 0x30) * 0x40 + 0x3c);
      *(uint *)(iVar6 + 0x10) = uVar8;
      *(uint *)(iVar6 + 0x14) = uVar7;
      FUN_00017874(*(int *)(param_1 + 0x30));
    }
  }
  else {
    iVar6 = FUN_0000db90(*(uint *)(param_1 + 0x30));
    *(undefined4 *)(iVar6 + 0x28) = 0;
  }
  FUN_00017654(*(uint *)(param_1 + 0x30),2);
LAB_00008b26:
  if (param_1[0x2e] == '\0') {
    return;
  }
  param_1[0x49] = '\x01';
  FUN_0000c3ac();
  return;
}



undefined4 FUN_00008b54(int param_1,byte *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_28;
  
  uVar6 = 0;
  local_28 = param_4;
  iVar1 = FUN_000083ac(param_2,*(uint *)(param_1 + 0x30),(uint)(*(char *)(param_1 + 0x39) == '\0'));
  if (iVar1 != 0) {
    puVar2 = FUN_00006b20();
    iVar3 = puVar2[2];
    iVar1 = *(int *)(param_2 + iVar3 * 4 + 0x14);
    if (iVar1 == 0) {
      uVar5 = iVar3 + 1;
      if (1 < uVar5) {
        uVar5 = 0;
      }
      iVar1 = *(int *)(param_2 + uVar5 * 4 + 0x14);
      if (iVar1 == 0) {
        iVar1 = 0x4b00;
      }
      else {
        puVar2 = FUN_00006b20();
        uVar4 = puVar2[iVar3];
        puVar2 = FUN_00006b20();
        iVar1 = (int)((ulonglong)(((uint)puVar2[uVar5] / 1000) * iVar1) / ((ulonglong)uVar4 / 1000))
        ;
      }
    }
    *(int *)(param_1 + 0x3c) = iVar1 + *(int *)(param_1 + 0x3c);
    uVar6 = 1;
    uVar5 = (uint)(byte)PTR_DAT_000912d4[(uint)*param_2 * 0x1c + 4];
    local_28 = uVar5 * 2;
    iVar1 = -(uVar5 * 2 + 7 & 0xfffffff8);
    iVar3 = FUN_000083e4(param_2,*(undefined4 *)(param_1 + 0x30),
                         *(undefined *)((int)&local_28 + iVar1));
    FUN_0000da64((int *)((int)&local_28 + iVar1),uVar5,*(undefined4 *)(iVar3 + 4),uVar5,
                 *(undefined *)((int)&local_28 + iVar1));
    FUN_0000da64((int)&local_28 + uVar5 + iVar1,uVar5,*(undefined4 *)(iVar3 + 8),uVar5,
                 *(undefined *)((int)&local_28 + iVar1));
    iVar3 = (int)((ulonglong)
                  ((longlong)(int)(param_2 + -(int)PTR_DAT_000912d8) * -0x6db6db6d +
                  ((longlong)(int)(param_2 + -(int)PTR_DAT_000912d8) << 0x20)) >> 0x20);
    iVar3 = (iVar3 >> 4) - (iVar3 >> 0x1f);
    uVar5 = FUN_00016ce8(local_28,(int *)((int)&local_28 + iVar1),
                         *(undefined *)((int)&local_28 + iVar1));
    *(uint *)(param_1 + 0x44) = (uVar5 >> iVar3 | uVar5 << 0x20 - iVar3) ^ *(uint *)(param_1 + 0x44)
    ;
  }
  return uVar6;
}



longlong FUN_00008c5c(int *param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  uint uStack28;
  undefined4 uStack24;
  
  if (*(char *)((int)param_1 + 0x39) == '\0') {
    piVar1 = FUN_000071d0();
    iVar2 = FUN_00008fb0(piVar1,param_2,param_1[0x11],&uStack24,&uStack28);
  }
  else {
    piVar1 = FUN_0000826c();
    iVar2 = FUN_00008fb0(piVar1,param_2,param_1[0x11],&uStack24,&uStack28);
  }
  if (iVar2 != 0) {
    *param_3 = uStack24;
    *(undefined *)(param_1 + 0x20) = 1;
    return (longlong)((ulonglong)uStack28 << 0x20);
  }
  *(undefined *)(param_1 + 0x20) = 0;
  *param_3 = 0;
  lVar3 = (**(code **)(*param_1 + 8))(param_1);
  return lVar3;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

undefined4 FUN_00008cb8(int param_1,char **param_2,byte *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_18;
  uint uStack20;
  
  local_18 = 0;
  uStack20 = 0;
  iVar1 = FUN_000083ac(param_3,*(uint *)(param_1 + 0x30),(uint)*(byte *)(param_2 + 3));
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = FUN_000073a0(param_3,param_2,&local_18);
  if (iVar1 != 0) {
    if ((local_18 | uStack20) != 0) {
      iVar1 = (int)((ulonglong)
                    ((longlong)(int)(param_3 + -(int)PTR_DAT_000912d8) * -0x6db6db6d +
                    ((longlong)(int)(param_3 + -(int)PTR_DAT_000912d8) << 0x20)) >> 0x20);
      uVar2 = (iVar1 >> 4) - (iVar1 >> 0x1f);
      if (0x9f < uVar2) {
                    // WARNING: Subroutine does not return
        FUN_00000060();
      }
      iVar1 = param_1 + (uVar2 >> 5) * 4;
      *(uint *)(iVar1 + 0x60) = 1 << (uVar2 & 0x1f) | *(uint *)(iVar1 + 0x60);
      FUN_000065ec(0xd9,*(undefined4 *)(param_1 + 0x30),
                   *(undefined4 *)(PTR_DAT_000912d4 + (uint)*param_3 * 0x1c),
                   *(undefined4 *)(param_3 + 4),0);
      FUN_000065ec(0xda,local_18,uStack20,0,0);
    }
    uVar3 = *(uint *)(param_1 + 0x5c);
    uVar2 = *(uint *)(param_1 + 0x58);
    if (*(uint *)(param_1 + 0x5c) < uStack20 + (*(uint *)(param_1 + 0x58) < local_18)) {
      uVar3 = uStack20;
      uVar2 = local_18;
    }
    *(uint *)(param_1 + 0x58) = uVar2;
    *(uint *)(param_1 + 0x5c) = uVar3;
    return 1;
  }
  return 0;
}



void FUN_00008d80(undefined4 param_1)

{
  if (DAT_000904a0 != 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  DAT_000904a0 = param_1;
  return;
}



void FUN_00008d94(int *param_1,uint param_2,uint param_3,int *param_4)

{
  undefined *puVar1;
  int iVar2;
  uint local_28;
  undefined4 uVar3;
  byte *pbVar4;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  int *piVar8;
  
  if (*(char *)((int)param_1 + 0x2e) == '\0') {
    *(undefined *)((int)param_1 + 0x39) = (char)param_2;
    *(undefined *)((int)param_1 + 0x2e) = 1;
    param_1[0xf] = 0;
    param_1[0x11] = -0x4811c9b5;
    uVar5 = 0;
    piVar8 = param_4;
    local_28 = (uint)(param_2 == 0);
    if (DAT_000912cc != 0) {
      do {
        pbVar4 = PTR_DAT_000912d8 + uVar5 * 0x1c;
        puVar1 = PTR_DAT_000912d8;
        if (pbVar4 != (byte *)0x0) {
          puVar1 = *(undefined **)(pbVar4 + 8);
        }
        uVar7 = local_28;
        if (((pbVar4 != (byte *)0x0 && puVar1 != (undefined *)0x0) &&
            (iVar2 = FUN_000083ac(pbVar4,param_1[0xc],local_28), iVar2 != 0)) &&
           (iVar2 = FUN_00008b54((int)param_1,pbVar4,local_28,(int)piVar8), iVar2 != 0)) {
          local_28 = param_1[0x10];
          if ((uint)param_1[0x10] <= *(uint *)(PTR_DAT_000912d4 + (uint)*pbVar4 * 0x1c + 0x18)) {
            local_28 = *(uint *)(PTR_DAT_000912d4 + (uint)*pbVar4 * 0x1c + 0x18);
          }
          param_1[0x10] = local_28;
        }
        uVar5 = uVar5 + 1;
        local_28 = uVar7;
      } while (uVar5 < DAT_000912cc);
    }
    puVar1 = (undefined *)(param_1[0xf] + param_1[0x10]);
    bVar6 = puVar1 == (undefined *)0x0;
    *(undefined **)(param_1 + 0xf) = puVar1;
    if (bVar6) {
      puVar1 = &LAB_00002604_1;
    }
    if (bVar6) {
      *(undefined **)(param_1 + 0xf) = puVar1;
    }
    *(undefined *)(param_1 + 0x12) = 0;
    *(undefined *)((int)param_1 + 0x49) = 0;
  }
  else {
    if ((uint)*(byte *)((int)param_1 + 0x39) != param_2) {
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
  }
  if ((param_3 | (uint)param_4) != 0) {
    uVar3 = 1;
    piVar8 = param_4;
    FUN_000065ec(0xc6,param_1[0xc],1,param_3,param_4);
    *(undefined *)((int)param_1 + 5) = 1;
    param_1[2] = param_3;
    *(int **)(param_1 + 3) = param_4;
    FUN_00009246(param_1,0,uVar3,piVar8);
    return;
  }
  piVar8 = (int *)0x0;
  uVar3 = 0;
  FUN_000065ec(0xc6,param_1[0xc],0,0,0);
  FUN_00009246(param_1,1,uVar3,piVar8);
  return;
}



void FUN_00008e94(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00009338(param_1,param_4,0);
  *(undefined **)puVar1 = &DAT_0001da14;
  *(undefined *)((int)puVar1 + 0x2e) = 0;
  puVar1[0xc] = param_2;
  puVar1[0xd] = param_3;
  *(undefined *)(puVar1 + 0xe) = 0;
  *(undefined *)((int)puVar1 + 0x39) = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  *(undefined *)(puVar1 + 0x12) = 0;
  *(undefined *)((int)puVar1 + 0x49) = 0;
  puVar1[0x15] = 0;
  puVar1[0x13] = 0;
  puVar1[0x14] = 0;
  puVar1[0x16] = 0;
  puVar1[0x17] = 0;
  puVar1[0x1f] = 0;
  puVar1[0x1d] = 0;
  puVar1[0x1e] = 0;
  *(undefined *)(puVar1 + 0x20) = 0;
  puVar1[0x18] = 0;
  puVar1[0x19] = 0;
  puVar1[0x1a] = 0;
  puVar1[0x1b] = 0;
  puVar1[0x1c] = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00008eee(int *param_1,char *param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  cVar1 = *param_2;
  bVar6 = cVar1 == '\0';
  if (bVar6) {
    cVar1 = *(char *)((int)param_1 + 0x2e);
  }
  if (!bVar6 || cVar1 != '\x01') {
    return;
  }
  FUN_0000d758();
  uVar2 = _DAT_00083000;
  uVar5 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  if ((code *)param_1[0x10] != (code *)0x0) {
    (*(code *)param_1[0x10])(0);
  }
  FUN_0000d758();
  uVar3 = _DAT_00083000;
  uVar4 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  param_1[6] = uVar3;
  param_1[7] = uVar4;
  FUN_0000925c((int)param_1);
  param_1[0xe] = uVar3 - uVar2;
  param_1[0xf] = uVar4 - (uVar5 + (uVar3 < uVar2));
  if ((param_1[0xc] | param_1[0xd]) == 0) {
    return;
  }
  *(undefined *)((int)param_1 + 0x2e) = 1;
  FUN_0000d758();
  uVar2 = _DAT_00083000;
  uVar5 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  *(undefined *)((int)param_1 + 5) = 1;
  param_1[2] = uVar2 + param_1[0xc];
  param_1[3] = param_1[0xd] + uVar5 + (uint)CARRY4(uVar2,param_1[0xc]);
  FUN_00009246(param_1,0,param_3,param_4);
  return;
}



undefined4
FUN_00008fb0(int *param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1[1] != 0) {
    iVar2 = *param_1;
    do {
      if ((*(int *)(iVar2 + uVar3 * 0x14) == param_2) &&
         (*(int *)(iVar2 + uVar3 * 0x14 + 4) == param_3)) {
        iVar1 = param_1[2];
        param_1[2] = iVar1 + 1;
        *(int *)(iVar2 + uVar3 * 0x14 + 0x10) = iVar1 + 1;
        *param_4 = *(undefined4 *)(*param_1 + uVar3 * 0x14 + 8);
        iVar2 = uVar3 * 0x14 + 0xc;
        *param_5 = *(undefined4 *)(*param_1 + iVar2);
        FUN_000065ec(0xd6,*(undefined4 *)(*param_1 + iVar2),0,0,0);
        return 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)param_1[1]);
  }
  return 0;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00009030(int *param_1,uint param_2,int param_3,uint param_4,uint param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint param_2_00;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uStack48;
  uint uStack44;
  uint uStack40;
  
  param_2_00 = 0;
  uVar2 = 0;
  if (param_4 == param_2) {
    return;
  }
  uVar1 = 0;
  if (param_1[1] != 0) {
    iVar3 = *param_1;
    do {
      if ((*(uint *)(iVar3 + uVar1 * 0x14) == param_2) &&
         (*(int *)(iVar3 + uVar1 * 0x14 + 4) == param_3)) {
        if (param_6 != 0) {
          iVar5 = uVar1 * 0x14 + 8;
          param_2_00 = *(uint *)(iVar3 + iVar5);
          if (param_2_00 == param_4) {
            iVar5 = uVar1 * 0x14 + 0xc;
            param_2_00 = *(uint *)(iVar3 + iVar5);
            if (param_5 <= param_2_00) {
              param_5 = param_2_00;
            }
            *(uint *)(iVar3 + iVar5) = param_5;
          }
          else {
            iVar6 = uVar1 * 0x14 + 0xc;
            FUN_000065ec(0xd7,param_2_00,*(undefined4 *)(iVar3 + iVar6),param_4,param_5);
            *(uint *)(*param_1 + iVar5) = param_4;
            *(uint *)(*param_1 + iVar6) = param_5;
          }
          iVar3 = param_1[2];
          param_1[2] = iVar3 + 1;
          *(int *)(*param_1 + uVar1 * 0x14 + 0x10) = iVar3 + 1;
          return;
        }
        return;
      }
      uVar4 = param_1[2] - *(int *)(iVar3 + uVar1 * 0x14 + 0x10);
      if (uVar2 < uVar4) {
        uVar2 = uVar4;
        param_2_00 = uVar1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)param_1[1]);
  }
  *(uint *)(*param_1 + param_2_00 * 0x14) = param_2;
  *(int *)(*param_1 + param_2_00 * 0x14 + 4) = param_3;
  *(uint *)(*param_1 + param_2_00 * 0x14 + 8) = param_4;
  *(uint *)(*param_1 + param_2_00 * 0x14 + 0xc) = param_5;
  iVar3 = param_1[2];
  param_1[2] = iVar3 + 1;
  *(int *)(*param_1 + param_2_00 * 0x14 + 0x10) = iVar3 + 1;
  iVar3 = FUN_0001a108();
  if (iVar3 == 1) {
    uStack48 = FUN_0001a138(1);
    uStack44 = FUN_0001a138(0);
    param_2_00 = FUN_00017184(param_2,(int)(PTR_DAT_000912d8 + DAT_000912cc * 0x1c),4,
                              (int *)&uStack48,(int *)&uStack44);
    FUN_00009030(param_1,param_2_00,param_3,param_4,(param_5 << 2) / 3,0);
  }
  iVar3 = FUN_0001a108();
  if (iVar3 == 2) {
    uStack48 = FUN_0001a138(2);
    uStack44 = FUN_0001a138(1);
    uStack40 = FUN_0001a138(0);
    param_2_00 = FUN_00017184(param_2,(int)(PTR_DAT_000912d8 + DAT_000912cc * 0x1c),4,
                              (int *)&uStack48,(int *)&uStack44);
    FUN_00009030(param_1,param_2_00,param_3,param_4,
                 (uint)((ulonglong)(param_5 * (uStack48 / 1000)) / ((ulonglong)uStack44 / 1000)),0);
    param_2_00 = FUN_00017184(param_2,(int)(PTR_DAT_000912d8 + DAT_000912cc * 0x1c),4,
                              (int *)&uStack48,(int *)&uStack40);
    FUN_00009030(param_1,param_2_00,param_3,param_4,
                 (uint)((ulonglong)(param_5 * (uStack48 / 1000)) / ((ulonglong)uStack40 / 1000)),0);
    return;
  }
  return;
}



void FUN_00009246(int *param_1,int param_2,undefined4 param_3,int *param_4)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_00006ad0();
  FUN_00009370((uint)puVar1,param_1,param_2,param_4);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000925c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 5) != '\0') {
    FUN_0000d758();
    uVar1 = _DAT_00083000;
    uVar2 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    if (*(uint *)(param_1 + 0xc) < uVar2 + (*(uint *)(param_1 + 8) < uVar1)) {
      *(char *)(param_1 + 0x22) = *(char *)(param_1 + 0x22) + '\x01';
    }
  }
  *(undefined *)(param_1 + 5) = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int FUN_000092a8(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  
  piVar7 = param_1;
  uVar4 = param_3;
  uVar8 = param_4;
  if (*(char *)((int)param_1 + 5) != '\0') {
    uVar3 = param_1[4];
    uVar5 = param_1[5];
    FUN_0000d758();
    uVar1 = _DAT_00083000;
    uVar6 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    if (uVar5 < uVar6 + (uVar3 < uVar1)) {
      *(char *)(param_1 + 8) = *(char *)(param_1 + 8) + '\x01';
    }
  }
  (**(code **)(*param_1 + 0x18))(param_1,param_2,param_3,param_4,piVar7,param_2,uVar4,uVar8);
  FUN_0000d758();
  uVar8 = _DAT_00083000;
  uVar4 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  uVar4 = uVar4 + (param_3 < uVar8);
  if (uVar4 <= param_4) {
    return param_4 - uVar4;
  }
  iVar2 = (uint)*(byte *)((int)param_1 + 0x21) + 1;
  *(undefined *)((int)param_1 + 0x21) = (char)iVar2;
  return iVar2;
}



void FUN_00009338(undefined4 *param_1,undefined param_2,undefined param_3)

{
  *(undefined **)param_1 = &DAT_0001da5c;
  *(undefined *)(param_1 + 1) = param_2;
  *(undefined *)((int)param_1 + 5) = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined *)(param_1 + 8) = 0;
  *(undefined *)((int)param_1 + 0x21) = 0;
  *(undefined *)((int)param_1 + 0x22) = 0;
  *(undefined *)((int)param_1 + 0x23) = param_3;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined *)(param_1 + 0xb) = 0;
  *(undefined *)((int)param_1 + 0x2d) = 0;
  return;
}



void FUN_00009370(uint param_1,int *param_2,int param_3,int *param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  int *local_28;
  
  local_28 = param_4;
  uVar9 = FUN_0000d758();
  uVar3 = (uint)((ulonglong)uVar9 >> 0x20);
  uVar4 = (uint)uVar9;
  if (param_3 != 1) {
    uVar3 = (uint)*(byte *)((int)param_2 + 5);
  }
  if (param_3 == 1 || uVar3 == 0) {
    FUN_0000a180((uint *)(param_1 + 8),param_2);
    *(undefined *)(param_2 + 0xb) = 1;
    piVar5 = *(int **)(param_1 + 0x2c);
    bVar8 = piVar5 == param_2;
    bVar2 = piVar5 == (int *)0x0;
    if (!bVar8 && !bVar2) {
      piVar5 = *(int **)(param_1 + 0x30);
    }
    if ((((bVar8 || bVar2) || piVar5 == (int *)0x0) ||
        (FUN_0000a2a4(param_1 + 8,&local_28), local_28 != param_2)) ||
       (*(byte *)(*(int *)(param_1 + 0x30) + 4) <= *(byte *)(local_28 + 1))) goto LAB_0000946e;
  }
  else {
    uVar6 = param_2[2];
    uVar7 = param_2[3];
    piVar5 = *(int **)(param_1 + 0x20);
    while (piVar5 != (int *)0x0) {
      if (*(char *)((int)piVar5 + 5) != '\0') {
        uVar4 = piVar5[3];
        uVar3 = piVar5[2];
      }
      uVar1 = uVar4 + (uVar6 < uVar3);
      if (uVar7 < uVar1) {
LAB_0000941c:
        FUN_0000a41a((int *)(param_1 + 0x20),(int)piVar5,(int)param_2);
        *(undefined *)((int)param_2 + 0x2d) = 1;
        FUN_0000947c(param_1,*(int **)(param_1 + 0x20),*(int **)(param_1 + 0x24),DAT_000912e4);
        piVar5 = *(int **)(param_1 + 0x20);
        goto joined_r0x0000943e;
      }
      uVar4 = uVar4 ^ uVar7;
      uVar3 = uVar3 ^ uVar6 | uVar4;
      if (uVar3 == 0) {
        uVar9 = (**(code **)(*piVar5 + 8))(piVar5,*(code **)(*piVar5 + 8),uVar7 - uVar1);
        uVar10 = (**(code **)(*param_2 + 8))(param_2);
        uVar4 = (uint)uVar10;
        uVar1 = uVar4 + ((uint)((ulonglong)uVar9 >> 0x20) < (uint)((ulonglong)uVar10 >> 0x20));
        uVar3 = (uint)uVar9 - uVar1;
        if ((uint)uVar9 < uVar1) goto LAB_0000941c;
      }
      piVar5 = (int *)piVar5[9];
    }
    FUN_0000a496((int *)(param_1 + 0x20),(int)param_2);
    *(undefined *)((int)param_2 + 0x2d) = 1;
    FUN_0000947c(param_1,*(int **)(param_1 + 0x20),*(int **)(param_1 + 0x24),DAT_000912e4);
    piVar5 = *(int **)(param_1 + 0x20);
joined_r0x0000943e:
    if (param_2 != piVar5) goto LAB_0000946e;
  }
  *(undefined *)(param_1 + 0x28) = 1;
LAB_0000946e:
  FUN_0001a7ec();
  return;
}



void FUN_0000947c(uint param_1,int *param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *param_2_00;
  int iVar5;
  uint unaff_r8;
  bool bVar6;
  undefined8 uVar7;
  undefined4 local_20;
  
  local_20 = param_4;
  uVar7 = (**(code **)(*param_2 + 0xc))(param_2,param_4,&local_20);
  uVar1 = (uint)((ulonglong)uVar7 >> 0x20);
  piVar4 = (int *)uVar7;
  bVar6 = param_2 != param_3;
  param_2_00 = piVar4;
  if (bVar6) {
    param_2_00 = (int *)param_2[9];
  }
  uVar2 = uVar1;
  if (!bVar6 || param_2_00 == (int *)0x0) {
    uVar2 = 0xffffffff;
  }
  uVar7 = CONCAT44(uVar2,uVar2);
  if (bVar6 && param_2_00 != (int *)0x0) {
    uVar7 = FUN_0000947c(param_1,param_2_00,param_3,local_20);
  }
  uVar2 = (uint)((ulonglong)uVar7 >> 0x20);
  if (*(char *)((int)param_2 + 5) != '\0') {
    unaff_r8 = param_2[2];
    param_1 = param_2[3];
  }
  if (param_1 < (int)uVar7 + (uint)(unaff_r8 < uVar2)) {
    if (param_1 < (int)piVar4 + (uint)(unaff_r8 < uVar1)) {
      iVar3 = 0;
      iVar5 = iVar3;
    }
    else {
      iVar3 = unaff_r8 - uVar1;
      iVar5 = param_1 - ((int)piVar4 + (uint)(unaff_r8 < uVar1));
    }
  }
  else {
    iVar3 = uVar2 - uVar1;
    iVar5 = (int)uVar7 - ((int)piVar4 + (uint)(uVar2 < uVar1));
  }
  param_2[4] = iVar3;
  param_2[5] = iVar5;
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_000094f0(uint *param_1,uint param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  uint local_1c;
  int iStack24;
  
  if (*param_1 == param_2) {
    return;
  }
  local_1c = param_2;
  iStack24 = param_3;
  FUN_0000d758();
  puVar1 = FUN_00006b20();
  FUN_0000a4ac(puVar1,local_1c);
  DAT_000912e4 = FUN_00017184(DAT_000912e4,(int)(PTR_DAT_000912d8 + DAT_000912cc * 0x1c),4,
                              (int *)param_1,(int *)&local_1c);
  FUN_0000a10c(param_1 + 2);
  piVar2 = (int *)param_1[8];
  while (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x10))(piVar2);
    piVar2 = (int *)piVar2[9];
  }
  if ((int *)param_1[9] != (int *)0x0) {
    FUN_0000947c((uint)param_1,(int *)param_1[8],(int *)param_1[9],DAT_000912e4);
  }
  if (param_3 == 0) {
    *param_1 = local_1c;
  }
  FUN_0001a7ec();
  return;
}



void FUN_00009828(int param_1)

{
  *(undefined *)(param_1 + 0x28) = 1;
  return;
}



int FUN_00009830(int param_1)

{
  FUN_0000a6dc(*(int *)(param_1 + 0x1c));
  return param_1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_00009840(int param_1,char *param_2,uint *param_3)

{
  undefined *puVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  
  FUN_000065ec(0xe5,0,0,0,0);
  do {
    if (*param_2 != '\0') {
      return 0;
    }
    FUN_0000d758();
    uVar4 = _DAT_00083000;
    uVar6 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    if (param_3[1] + (uint)(uVar4 < *param_3) <= uVar6) {
      return 0;
    }
    if (*(char *)(param_1 + 0x38) == '\0') {
      puVar1 = FUN_00019790(*(int *)(param_1 + 0x30));
      if (puVar1 == (undefined *)0x0) {
        return 1;
      }
      iVar2 = FUN_00009954(param_1);
      *(undefined *)(param_1 + 0x38) = (char)iVar2;
      if (iVar2 != 0) goto LAB_000098b0;
    }
    else {
LAB_000098b0:
      if (*(int *)(*(int *)(param_1 + 0x48) + 0xc) != 2) {
        return 1;
      }
    }
    iVar2 = *(int *)(param_1 + 0x48);
    if (*(uint *)(param_1 + 0x3c) < *(uint *)(iVar2 + 4)) {
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    if ((*(uint *)(iVar2 + 0xc) < 3) && (*(int *)(iVar2 + 0x18) == *(uint *)(iVar2 + 4) - 0x14)) {
      pbVar3 = FUN_00017fb4(*(int *)(iVar2 + 0x10),*(int *)(iVar2 + 0x14));
      *(byte **)(param_1 + 0x58) = pbVar3;
      if (pbVar3 == (byte *)0x0) {
        pcVar5 = "resource does not exist";
        goto LAB_000098dc;
      }
      FUN_0000d748(*(char ***)(param_1 + 0x50),iVar2 + 0x1c,*(undefined4 *)(iVar2 + 0x18));
LAB_0000990a:
      if (*param_2 != '\0') {
        return 0;
      }
      FUN_00009e4c(param_1,param_2,param_3,*(int *)(param_1 + 0x48),0);
    }
    else {
      pcVar5 = "invalid header";
LAB_000098dc:
      if ((uint *)pcVar5 == (uint *)0x0) goto LAB_0000990a;
      FUN_00009da8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x48) + 8),(uint *)pcVar5,0x716572);
    }
    uVar4 = *(int *)(param_1 + 0x48) + *(int *)(*(int *)(param_1 + 0x48) + 4) + 8;
    *(uint *)(param_1 + 0x48) = uVar4;
    if ((uint)(*(int *)(param_1 + 0x40) + *(int *)(param_1 + 0x3c)) <= uVar4) {
      *(undefined *)(param_1 + 0x38) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_00009954(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  code *pcVar4;
  byte *pbVar5;
  uint *puVar6;
  int *piVar7;
  char *pcVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int local_2c;
  uint *local_28;
  undefined4 uStack36;
  
  FUN_0000d758();
  uVar2 = _DAT_00083000;
  uVar9 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  *(undefined4 *)(param_1 + 0x98) = uVar2;
  *(uint *)(param_1 + 0x9c) = uVar9;
  pcVar3 = (code *)FUN_00019790(*(int *)(param_1 + 0x30));
  if ((pcVar3 <= *(code **)(param_1 + 0x44)) &&
     (pcVar4 = (code *)FUN_000195e8(*(int *)(param_1 + 0x30),pcVar3,*(int *)(param_1 + 0x40),0),
     pcVar4 == pcVar3)) {
    *(code **)(param_1 + 0x3c) = pcVar4;
    piVar10 = *(int **)(param_1 + 0x40);
    iVar11 = *piVar10;
    if (((pcVar3 < FUN_0000001c) && (iVar11 != 0x646d63)) ||
       ((pcVar3 < entry && (iVar11 == 0x646d63)))) {
      FUN_00009da8(param_1,0,(uint *)"invalid message",0x716572);
      return 0;
    }
    if (iVar11 == 0x646d63) {
      *(int **)(param_1 + 0x4c) = piVar10;
      FUN_000065ec(0xe2,*(undefined4 *)(param_1 + 0x34),
                   *(undefined4 *)(*(int *)(param_1 + 0x48) + 8),0,0);
      FUN_0000d748(*(char ***)(param_1 + 0x50),piVar10 + 2,piVar10[1]);
      puVar6 = (uint *)FUN_0000d658(*(int **)(param_1 + 0x50),&local_2c,&uStack36,&local_28);
      puVar1 = puVar6;
      if (puVar6 != (uint *)0x0) {
        puVar1 = local_28;
      }
      if (puVar6 == (uint *)0x0 || puVar1 == (uint *)0x0) {
        FUN_00009da8(param_1,local_2c,(uint *)"Malformed command",0x646d63);
      }
      else {
        if (local_2c != 0x736e7274) goto LAB_00009a92;
        FUN_000175ec(*(int *)(param_1 + 0x34),*puVar1 & 0xff);
      }
    }
    else {
      if (iVar11 == 0x716572) {
        *(int **)(param_1 + 0x48) = piVar10;
        if (piVar10[3] == 2) {
          return 1;
        }
        if (((uint)piVar10[3] < 3) && (piVar10[6] == piVar10[1] + -0x14)) {
          pbVar5 = FUN_00017fb4(piVar10[4],piVar10[5]);
          *(byte **)(param_1 + 0x58) = pbVar5;
          if (pbVar5 != (byte *)0x0) {
            FUN_0000d748(*(char ***)(param_1 + 0x50),piVar10 + 7,piVar10[6]);
            return 1;
          }
          pcVar8 = "resource does not exist";
        }
        else {
          pcVar8 = "invalid header";
        }
        if ((uint *)pcVar8 == (uint *)0x0) {
          return 1;
        }
        FUN_00009da8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x48) + 8),(uint *)pcVar8,0x716572);
      }
      else {
        FUN_0000d758();
        piVar7 = (int *)DAT_000904c4;
        while (piVar7 != (int *)0x0) {
          if (piVar7[1] == iVar11) {
            (*(code *)piVar7[2])(*(undefined4 *)(param_1 + 0x34),piVar10 + 1,pcVar3 + -4,piVar7[3]);
            break;
          }
          piVar7 = (int *)*piVar7;
        }
        FUN_0001a7ec();
      }
    }
    return 0;
  }
LAB_00009a92:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00009afc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  longlong lVar14;
  undefined4 uStack48;
  undefined4 uStack44;
  
  uStack48 = param_3;
  uStack44 = param_4;
  FUN_0000d758();
  iVar11 = *(int *)(param_1 + 0x48);
  iVar3 = *(int *)(iVar11 + 0xc);
  bVar13 = iVar3 == 2;
  if (bVar13) {
    iVar3 = 0;
  }
  if (bVar13) {
    *(int *)(iVar11 + 0xc) = iVar3;
  }
  cVar1 = *(char *)(param_1 + 0x60);
  if (cVar1 == '\x01') {
    lVar14 = FUN_00009e4c(param_1,param_2,&uStack48,iVar11,1);
    uVar4 = (uint)((ulonglong)lVar14 >> 0x20);
    uVar12 = (uint)lVar14;
    *(undefined *)(param_1 + 0x62) = 0;
    *(undefined *)(param_1 + 0x38) = 0;
    uVar10 = uVar4 | uVar12;
    if (lVar14 == 0) {
      if (*(int *)(param_1 + 0x6c) == *(int *)(iVar11 + 8)) {
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 0x6c) = 0;
        *(undefined4 *)(param_1 + 0x70) = 0;
        *(undefined4 *)(param_1 + 0x74) = 0;
      }
      else {
        if (*(int *)(param_1 + 0x6c) != 0) {
          uVar10 = 1;
        }
      }
      if (*(int *)(param_1 + 0x7c) == *(int *)(iVar11 + 8)) {
        *(undefined4 *)(param_1 + 0x78) = 0;
        *(undefined4 *)(param_1 + 0x7c) = 0;
        *(undefined4 *)(param_1 + 0x80) = 0;
        *(undefined4 *)(param_1 + 0x84) = 0;
      }
      else {
        if (*(int *)(param_1 + 0x7c) != 0) {
          uVar10 = 1;
        }
      }
      if (*(int *)(param_1 + 0x8c) == *(int *)(iVar11 + 8)) {
        *(undefined4 *)(param_1 + 0x88) = 0;
        *(undefined4 *)(param_1 + 0x8c) = 0;
        *(undefined4 *)(param_1 + 0x90) = 0;
        *(undefined4 *)(param_1 + 0x94) = 0;
      }
      else {
        if (*(int *)(param_1 + 0x8c) != 0) {
          uVar10 = 1;
        }
      }
      *(undefined *)(param_1 + 0x61) = (char)uVar10;
      if (uVar10 == 0) {
        *(undefined *)(param_1 + 0x60) = 3;
        goto LAB_00009d44;
      }
    }
    else {
      uVar7 = *(undefined4 *)(iVar11 + 8);
      iVar3 = FUN_00018298(0x77b9,param_1,uVar4,uVar12);
      if (iVar3 == 0) goto LAB_00009d76;
      if (*(int *)(param_1 + 0x6c) == 0) {
        *(undefined4 *)(param_1 + 0x6c) = uVar7;
        *(uint *)(param_1 + 0x74) = uVar12;
        *(uint *)(param_1 + 0x70) = uVar4;
        *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x58);
      }
      else {
        if (*(int *)(param_1 + 0x7c) == 0) {
          *(undefined4 *)(param_1 + 0x7c) = uVar7;
          *(uint *)(param_1 + 0x84) = uVar12;
          *(uint *)(param_1 + 0x80) = uVar4;
          *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x58);
        }
        else {
          if (*(int *)(param_1 + 0x8c) != 0) goto LAB_00009d76;
          *(undefined4 *)(param_1 + 0x8c) = uVar7;
          *(uint *)(param_1 + 0x94) = uVar12;
          *(uint *)(param_1 + 0x90) = uVar4;
          *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x58);
        }
      }
      FUN_000065ec(0xd9,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(iVar11 + 0x10),
                   *(undefined4 *)(iVar11 + 0x14),*(undefined4 *)(iVar11 + 8));
      FUN_000065ec(0xda,uVar4,uVar12,0,0);
      if (*(char *)(param_1 + 0x61) == '\0') {
        *(undefined *)(param_1 + 0x61) = 1;
        *(undefined *)(param_1 + 0x60) = 3;
        goto LAB_00009d3e;
      }
    }
    *(undefined *)(param_1 + 0x60) = 2;
LAB_00009bc8:
    uVar2 = 0;
    FUN_0000d758();
    uVar4 = _DAT_00083000;
    uVar12 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    uVar10 = 0;
    do {
      iVar3 = param_1 + uVar10 * 0x10;
      uVar8 = *(uint *)(iVar3 + 0x70);
      uVar9 = *(uint *)(iVar3 + 0x74);
      if (((uVar8 | uVar9) != 0) && (uVar9 + (uVar4 < uVar8) <= uVar12)) {
        lVar14 = FUN_000082c8(*(byte **)(iVar3 + 0x68),*(uint *)(param_1 + 0x34),uVar8,uVar9);
        uVar8 = (uint)((ulonglong)lVar14 >> 0x20);
        uVar9 = (uint)lVar14;
        if (lVar14 == 0) {
          FUN_000065ec(0xdb,*(undefined4 *)(param_1 + 0x34),
                       *(undefined4 *)(PTR_DAT_000912d4 + (uint)**(byte **)(param_1 + 0x58) * 0x1c),
                       *(undefined4 *)(*(byte **)(param_1 + 0x58) + 4),*(undefined4 *)(iVar3 + 0x6c)
                      );
          FUN_00009da8(param_1,*(undefined4 *)(iVar3 + 0x6c),(uint *)0x0,0x716572);
          *(undefined4 *)(iVar3 + 0x68) = 0;
          *(undefined4 *)(iVar3 + 0x6c) = 0;
          *(undefined4 *)(iVar3 + 0x70) = 0;
          *(undefined4 *)(iVar3 + 0x74) = 0;
        }
        else {
          *(uint *)(iVar3 + 0x70) = uVar8;
          *(uint *)(iVar3 + 0x74) = uVar9;
          uVar2 = 1;
          iVar5 = FUN_00018298(0x77b9,param_1,uVar8,uVar9);
          if (iVar5 == 0) goto LAB_00009d76;
          FUN_000065ec(0xd9,*(undefined4 *)(param_1 + 0x34),
                       *(undefined4 *)(PTR_DAT_000912d4 + (uint)**(byte **)(param_1 + 0x58) * 0x1c),
                       *(undefined4 *)(*(byte **)(param_1 + 0x58) + 4),*(undefined4 *)(iVar3 + 0x6c)
                      );
          FUN_000065ec(0xda,uVar8,uVar9,0,0);
        }
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < 3);
    *(undefined *)(param_1 + 0x61) = uVar2;
    *(undefined *)(param_1 + 0x60) = 3;
  }
  else {
    if (cVar1 == '\x02') goto LAB_00009bc8;
    if (cVar1 != '\x03') goto LAB_00009d92;
  }
LAB_00009d3e:
  while (*(char *)(param_1 + 0x38) == '\0') {
LAB_00009d44:
    puVar6 = FUN_00019790(*(int *)(param_1 + 0x30));
    if (puVar6 == (undefined *)0x0) {
      if (*(char *)(param_1 + 0x38) == '\0') goto LAB_00009d7a;
      break;
    }
    uVar7 = FUN_00009954(param_1);
    *(undefined *)(param_1 + 0x38) = (char)uVar7;
  }
  if ((*(int *)(iVar11 + 0xc) == 2) &&
     (iVar3 = FUN_000197c2(*(int *)(param_1 + 0x30),3), iVar3 == 0)) {
LAB_00009d7a:
    *(undefined *)(param_1 + 0x39) = 1;
    *(undefined *)(param_1 + 0x60) = 0;
  }
  else {
    if (*(char *)(param_1 + 0x39) != '\0') {
LAB_00009d76:
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    *(undefined *)(param_1 + 0x60) = 1;
    *(undefined *)(param_1 + 0x62) = 1;
  }
LAB_00009d92:
  FUN_0001a7ec();
  return;
}



void FUN_00009da8(int param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int local_48;
  undefined4 local_44;
  int *local_40;
  undefined4 local_3c;
  int *local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int iStack36;
  undefined4 uStack32;
  uint *puStack28;
  int iStack24;
  
  uVar4 = 0x2367736d;
  if (param_4 == 0x646d63) {
    uVar4 = 0x736e7274;
  }
  iStack36 = param_1;
  uStack32 = param_2;
  puStack28 = param_3;
  iStack24 = param_4;
  FUN_0000d5e6(*(int **)(param_1 + 0x5c));
  FUN_0000d6ec(*(char ***)(param_1 + 0x5c),uVar4,4,&uStack32);
  if (param_3 != (uint *)0x0) {
    puVar1 = FUN_00000378(param_3);
    FUN_0000d6ec(*(char ***)(param_1 + 0x5c),0x727265,(uint)puVar1,param_3);
  }
  local_48 = param_4;
  local_44 = FUN_0000d6e6(*(int **)(param_1 + 0x5c));
  local_40 = &local_34;
  local_38 = &local_48;
  local_34 = 0;
  local_3c = 8;
  local_2c = FUN_0000d6de(*(int **)(param_1 + 0x5c));
  local_30 = local_44;
  FUN_000065ec(0xd2,*(undefined4 *)(param_1 + 0x34),param_4,0,0);
  piVar2 = FUN_000197f2(*(int *)(param_1 + 0x30),&local_40,0);
  iVar3 = FUN_0000d6e6(*(int **)(param_1 + 0x5c));
  if ((int *)(iVar3 + 8) != piVar2) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

longlong FUN_00009e4c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  int *piVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  longlong lVar15;
  longlong lVar16;
  uint local_38;
  uint uStack52;
  int local_2c;
  
  local_38 = 0;
  uStack52 = 0;
  FUN_00006b20();
  uVar7 = 0;
  iVar12 = 0;
  FUN_0000d758();
  uVar1 = _DAT_00083000;
  uVar8 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  FUN_00006b20();
  FUN_000065ec(0xd1,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_4 + 0x10),
               *(undefined4 *)(param_4 + 0x14),0);
  uVar2 = FUN_0000d61a(*(int **)(param_1 + 0x50));
  if (uVar2 == 0) {
    piVar5 = *(int **)(param_1 + 0x50);
  }
  else {
    piVar5 = (int *)0x0;
  }
  local_2c = FUN_00007568(*(byte **)(param_1 + 0x58),*(uint *)(param_1 + 0x34),
                          *(uint *)(param_4 + 0xc) & 0xff,piVar5,&local_38);
  lVar15 = CONCAT44(local_38,uStack52);
  if ((uStack52 | local_38) != 0) {
    FUN_0000d758();
    uVar2 = _DAT_00083000;
    uVar9 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    lVar15 = CONCAT44(local_38,uStack52);
    if (((uint)DAT_000901fe | param_5 - 1U) == 0) {
      if (uVar9 < uStack52 + (uVar2 < local_38)) {
        uVar7 = local_38 - uVar2;
        iVar12 = uStack52 - (uVar9 + (local_38 < uVar2));
      }
      else {
        lVar15 = FUN_000082c8(*(byte **)(param_1 + 0x58),*(uint *)(param_1 + 0x34),local_38,uStack52
                             );
      }
    }
    else {
      if ((local_38 | uStack52) != 0) {
        do {
          local_38 = (uint)((ulonglong)lVar15 >> 0x20);
          uStack52 = (uint)lVar15;
          lVar16 = lVar15;
          lVar15 = FUN_000082c8(*(byte **)(param_1 + 0x58),*(uint *)(param_1 + 0x34),local_38,
                                uStack52);
          local_38 = (uint)((ulonglong)lVar16 >> 0x20);
          uStack52 = (uint)lVar16;
        } while (lVar15 != 0);
      }
      FUN_0000d758();
      uVar10 = _DAT_00083000;
      local_38 = (uint)((ulonglong)lVar15 >> 0x20);
      uStack52 = (uint)lVar15;
      uVar13 = _DAT_00083004 & 0xffffff;
      FUN_0001a7ec();
      local_38 = (uint)((ulonglong)lVar15 >> 0x20);
      uStack52 = (uint)lVar15;
      uVar7 = uVar10 - uVar2;
      iVar12 = uVar13 - (uVar9 + (uVar10 < uVar2));
    }
  }
  if (lVar15 == 0) {
    FUN_00009da8(param_1,*(undefined4 *)(param_4 + 8),(uint *)0x0,0x716572);
    local_38 = (uint)((ulonglong)lVar15 >> 0x20);
    uStack52 = (uint)lVar15;
  }
  FUN_0000d758();
  uVar2 = _DAT_00083000;
  local_38 = (uint)((ulonglong)lVar15 >> 0x20);
  uStack52 = (uint)lVar15;
  uVar10 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  local_38 = (uint)((ulonglong)lVar15 >> 0x20);
  uStack52 = (uint)lVar15;
  uVar9 = uVar2 - uVar1;
  iVar11 = uVar10 - (uVar8 + (uVar2 < uVar1));
  if (((uint)DAT_000901fe | param_5 - 1U) != 0) {
    bVar14 = uVar9 < uVar7;
    uVar9 = uVar9 - uVar7;
    iVar11 = iVar11 - (iVar12 + (uint)bVar14);
  }
  if (local_2c != 0) {
    pbVar6 = *(byte **)(param_1 + 0x58);
    puVar3 = FUN_00006b20();
    local_38 = (uint)((ulonglong)lVar15 >> 0x20);
    uStack52 = (uint)lVar15;
    pbVar4 = pbVar6 + puVar3[2] * 4;
    if (iVar11 + (uint)(*(uint *)(pbVar4 + 0x14) < uVar9) != 0) {
      *(uint *)(pbVar4 + 0x14) = uVar9;
    }
    iVar12 = (uint)*pbVar6 * 0x1c + 0x18;
    if (uVar7 <= *(uint *)(PTR_DAT_000912d4 + iVar12)) {
      uVar7 = *(uint *)(PTR_DAT_000912d4 + iVar12);
    }
    *(uint *)(PTR_DAT_000912d4 + iVar12) = uVar7;
  }
  return lVar15;
}



void FUN_00009ff8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00019434((uint *)"rpm_requests",PTR_DAT_000912d0[*(int *)(param_1 + 0x34) * 0x40 + 4],
                       0,*(undefined4 *)(PTR_DAT_000912d0 + *(int *)(param_1 + 0x34) * 0x40 + 8),
                       &LAB_00007020_1,param_1);
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  return;
}



undefined4 * FUN_0000a044(undefined4 *param_1,undefined4 param_2,int param_3,undefined param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_00009338(param_1,param_4,0);
  *(undefined **)puVar1 = &DAT_0001da80;
  puVar1[0xc] = 0;
  puVar1[0xd] = param_2;
  *(undefined *)(puVar1 + 0xe) = 0;
  *(undefined *)((int)puVar1 + 0x39) = 1;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = param_3;
  puVar1[0x12] = 0;
  puVar1[0x15] = 0;
  puVar1[0x16] = 0;
  *(undefined *)(puVar1 + 0x18) = 0;
  *(undefined *)((int)puVar1 + 0x61) = 0;
  *(undefined *)((int)puVar1 + 0x62) = 0;
  puVar1[0x26] = 0;
  puVar1[0x27] = 0;
  puVar1[0x2a] = 0;
  puVar1[0x28] = 0;
  puVar1[0x29] = 0;
  if (puVar1 + 0x10 != (int *)0x0) {
    iVar2 = FUN_00000154(param_3);
    puVar1[0x10] = iVar2;
  }
  puVar3 = FUN_0000d5f6(0);
  *(undefined4 **)(puVar1 + 0x14) = puVar3;
  puVar3 = FUN_0000d5f6(0x40);
  puVar1[0x1a] = 0;
  *(undefined4 **)(puVar1 + 0x17) = puVar3;
  puVar1[0x1b] = 0;
  puVar1[0x1c] = 0;
  puVar1[0x1d] = 0;
  puVar1[0x1e] = 0;
  puVar1[0x1f] = 0;
  puVar1[0x20] = 0;
  puVar1[0x21] = 0;
  puVar1[0x22] = 0;
  puVar1[0x23] = 0;
  puVar1[0x24] = 0;
  puVar1[0x25] = 0;
  return puVar1;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0000a0d4(uint *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint *puVar16;
  uint uVar17;
  undefined4 uVar18;
  int *piVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  
  uVar3 = 0;
  if (param_1[4] == 0) {
    return;
  }
  do {
    if (*(int *)(param_1[5] + uVar3 * 0x18 + 0x10) == param_2) {
      uVar4 = param_1[5];
      puVar16 = (uint *)(uVar3 * 0x18 + 8 + uVar4);
      uVar10 = *puVar16;
      uVar6 = puVar16[1];
      uVar17 = *param_1;
      *param_1 = uVar17 - uVar10;
      param_1[1] = param_1[1] - (uVar6 + (uVar17 < uVar10));
      puVar7 = (undefined4 *)(uVar4 + uVar3 * 0x18);
      uVar6 = param_1[4];
      param_1[4] = uVar6 - 1;
      puVar5 = (undefined4 *)(uVar4 + (uVar6 - 1) * 0x18);
      uVar8 = puVar5[1];
      uVar11 = puVar5[2];
      uVar18 = puVar5[3];
      *puVar7 = *puVar5;
      puVar7[1] = uVar8;
      puVar7[2] = uVar11;
      puVar7[3] = uVar18;
      uVar8 = puVar5[5];
      puVar7[4] = puVar5[4];
      puVar7[5] = uVar8;
      while( true ) {
        uVar6 = uVar3 * 2 + 1;
        uVar10 = uVar3 * 2 + 2;
        uVar4 = uVar3;
        if (uVar6 < param_1[4]) {
          piVar19 = (int *)(param_1[5] + uVar6 * 0x18);
          piVar9 = (int *)(param_1[5] + uVar3 * 0x18);
          bVar1 = *(byte *)(piVar19[4] + 4);
          bVar2 = *(byte *)(piVar9[4] + 4);
          if ((bVar1 < bVar2) ||
             ((bVar1 == bVar2 && (param_1[2] - *piVar9 < param_1[2] - *piVar19)))) {
            uVar4 = uVar6;
          }
        }
        if (uVar10 < param_1[4]) {
          uVar6 = param_1[5];
          piVar9 = (int *)(uVar6 + uVar10 * 0x18);
          piVar19 = (int *)(uVar6 + uVar3 * 0x18);
          bVar2 = *(byte *)(piVar9[4] + 4);
          bVar1 = *(byte *)(piVar19[4] + 4);
          if ((bVar2 < bVar1) ||
             ((bVar2 == bVar1 && (param_1[2] - *piVar19 < param_1[2] - *piVar9)))) {
            piVar19 = (int *)(uVar6 + uVar4 * 0x18);
            bVar1 = *(byte *)(piVar19[4] + 4);
            if ((bVar2 < bVar1) ||
               ((bVar2 == bVar1 && (param_1[2] - *piVar19 < param_1[2] - *piVar9)))) {
              uVar4 = uVar10;
            }
          }
        }
        if (uVar4 == uVar3) break;
        puVar5 = (undefined4 *)(param_1[5] + uVar3 * 0x18);
        puVar7 = (undefined4 *)(param_1[5] + uVar4 * 0x18);
        uVar8 = *puVar5;
        uVar11 = puVar5[1];
        uVar18 = puVar5[2];
        uVar12 = puVar5[3];
        uVar13 = puVar5[4];
        uVar20 = puVar5[5];
        uVar14 = puVar7[1];
        uVar15 = puVar7[2];
        uVar21 = puVar7[3];
        *puVar5 = *puVar7;
        puVar5[1] = uVar14;
        puVar5[2] = uVar15;
        puVar5[3] = uVar21;
        uVar14 = puVar7[5];
        puVar5[4] = puVar7[4];
        puVar5[5] = uVar14;
        *puVar7 = uVar8;
        puVar7[1] = uVar11;
        puVar7[2] = uVar18;
        puVar7[3] = uVar12;
        puVar7[4] = uVar13;
        puVar7[5] = uVar20;
        uVar3 = uVar4;
      }
      return;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < param_1[4]);
  return;
}



void FUN_0000a10c(uint *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 local_28;
  
  local_28 = DAT_000912e4;
  *param_1 = 0;
  param_1[1] = 0;
  uVar6 = 0;
  if (param_1[4] != 0) {
    do {
      uVar1 = local_28;
      iVar7 = uVar6 * 0x18 + 0x10;
      (**(code **)(**(int **)(param_1[5] + iVar7) + 0x10))();
      piVar2 = *(int **)(param_1[5] + iVar7);
      uVar8 = (**(code **)(*piVar2 + 0xc))(piVar2,uVar1,&local_28);
      uVar3 = (uint)((ulonglong)uVar8 >> 0x20);
      puVar4 = (uint *)(param_1[5] + uVar6 * 0x18 + 8);
      *puVar4 = uVar3;
      puVar4[1] = (uint)uVar8;
      uVar5 = *param_1;
      *param_1 = uVar5 + uVar3;
      param_1[1] = (uint)uVar8 + param_1[1] + (uint)CARRY4(uVar5,uVar3);
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_1[4]);
    return;
  }
  return;
}



void FUN_0000a180(uint *param_1,int *param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined8 uVar24;
  
  uVar2 = param_1[4];
  param_1[4] = uVar2 + 1;
  if (param_1[3] < uVar2 + 1) {
    puVar3 = (undefined4 *)FUN_0000a6ec(param_1[3] * 0x30);
    uVar2 = param_1[3];
    if (uVar2 != 0) {
      puVar4 = puVar3;
      iVar8 = 0;
      do {
        puVar12 = (undefined4 *)(param_1[5] + iVar8 * 0x18);
        uVar16 = puVar12[1];
        uVar18 = puVar12[2];
        uVar19 = puVar12[3];
        *puVar4 = *puVar12;
        puVar4[1] = uVar16;
        puVar4[2] = uVar18;
        puVar4[3] = uVar19;
        uVar16 = puVar12[5];
        puVar4[4] = puVar12[4];
        puVar4[5] = uVar16;
        puVar4 = puVar4 + 6;
        uVar2 = uVar2 - 1;
        iVar8 = iVar8 + 1;
      } while (uVar2 != 0);
    }
    FUN_0000a6dc(param_1[5]);
    *(undefined4 **)(param_1 + 5) = puVar3;
    param_1[3] = param_1[3] << 1;
  }
  uVar13 = param_1[4] - 1;
  *(uint *)(param_1[5] + uVar13 * 0x18) = param_1[2];
  param_1[2] = param_1[2] + 1;
  uVar24 = (**(code **)(*param_2 + 8))(param_2);
  iVar8 = uVar13 * 0x18 + 8;
  puVar3 = (undefined4 *)(param_1[5] + iVar8);
  *puVar3 = (int)((ulonglong)uVar24 >> 0x20);
  puVar3[1] = (int)uVar24;
  *(int **)(param_1[5] + uVar13 * 0x18 + 0x10) = param_2;
  puVar5 = (uint *)(param_1[5] + iVar8);
  uVar9 = *puVar5;
  uVar10 = puVar5[1];
  uVar2 = *param_1;
  *param_1 = uVar9 + uVar2;
  param_1[1] = param_1[1] + uVar10 + (uint)CARRY4(uVar9,uVar2);
  do {
    if (uVar13 == 0) {
      return;
    }
    uVar2 = uVar13 - 1;
    piVar6 = (int *)(param_1[5] + uVar13 * 0x18);
    uVar13 = uVar2 >> 1;
    piVar7 = (int *)(param_1[5] + (uVar13 + (uVar2 & 0xfffffffe)) * 8);
    iVar8 = piVar6[4];
    bVar1 = *(byte *)(iVar8 + 4);
    if (*(byte *)(piVar7[4] + 4) <= bVar1) {
      if (bVar1 != *(byte *)(piVar7[4] + 4)) {
        return;
      }
      if (param_1[2] - *piVar6 <= param_1[2] - *piVar7) {
        return;
      }
    }
    iVar11 = *piVar6;
    iVar22 = piVar6[1];
    iVar14 = piVar6[2];
    iVar15 = piVar6[3];
    iVar20 = piVar7[1];
    iVar21 = piVar7[2];
    iVar23 = piVar7[3];
    iVar17 = piVar6[5];
    *piVar6 = *piVar7;
    piVar6[1] = iVar20;
    piVar6[2] = iVar21;
    piVar6[3] = iVar23;
    iVar20 = piVar7[5];
    piVar6[4] = piVar7[4];
    piVar6[5] = iVar20;
    piVar7[5] = iVar17;
    piVar7[2] = iVar14;
    piVar7[3] = iVar15;
    piVar7[4] = iVar8;
    *piVar7 = iVar11;
    piVar7[1] = iVar22;
  } while( true );
}



undefined4 FUN_0000a2a4(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x10);
    return 1;
  }
  return 0;
}



void FUN_0000a3ec(uint *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined4 uVar17;
  int *piVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  
  if (param_1[4] == 0) {
    return;
  }
  puVar3 = (undefined4 *)param_1[5];
  uVar10 = puVar3[2];
  iVar6 = puVar3[3];
  uVar16 = *param_1;
  *param_1 = uVar16 - uVar10;
  param_1[1] = param_1[1] - (iVar6 + (uint)(uVar16 < uVar10));
  uVar10 = param_1[4];
  param_1[4] = uVar10 - 1;
  puVar4 = puVar3 + (uVar10 - 1) * 6;
  uVar8 = puVar4[1];
  uVar11 = puVar4[2];
  uVar17 = puVar4[3];
  *puVar3 = *puVar4;
  puVar3[1] = uVar8;
  puVar3[2] = uVar11;
  puVar3[3] = uVar17;
  uVar8 = puVar4[5];
  puVar3[4] = puVar4[4];
  puVar3[5] = uVar8;
  uVar10 = 0;
  while( true ) {
    uVar5 = uVar10 * 2 + 1;
    uVar7 = uVar10 * 2 + 2;
    uVar16 = uVar10;
    if (uVar5 < param_1[4]) {
      piVar18 = (int *)(param_1[5] + uVar5 * 0x18);
      piVar9 = (int *)(param_1[5] + uVar10 * 0x18);
      bVar1 = *(byte *)(piVar18[4] + 4);
      bVar2 = *(byte *)(piVar9[4] + 4);
      if ((bVar1 < bVar2) || ((bVar1 == bVar2 && (param_1[2] - *piVar9 < param_1[2] - *piVar18)))) {
        uVar16 = uVar5;
      }
    }
    if (uVar7 < param_1[4]) {
      uVar5 = param_1[5];
      piVar9 = (int *)(uVar5 + uVar7 * 0x18);
      piVar18 = (int *)(uVar5 + uVar10 * 0x18);
      bVar2 = *(byte *)(piVar9[4] + 4);
      bVar1 = *(byte *)(piVar18[4] + 4);
      if ((bVar2 < bVar1) || ((bVar2 == bVar1 && (param_1[2] - *piVar18 < param_1[2] - *piVar9)))) {
        piVar18 = (int *)(uVar5 + uVar16 * 0x18);
        bVar1 = *(byte *)(piVar18[4] + 4);
        if ((bVar2 < bVar1) || ((bVar2 == bVar1 && (param_1[2] - *piVar18 < param_1[2] - *piVar9))))
        {
          uVar16 = uVar7;
        }
      }
    }
    if (uVar16 == uVar10) break;
    puVar3 = (undefined4 *)(param_1[5] + uVar10 * 0x18);
    puVar4 = (undefined4 *)(param_1[5] + uVar16 * 0x18);
    uVar8 = *puVar3;
    uVar11 = puVar3[1];
    uVar17 = puVar3[2];
    uVar12 = puVar3[3];
    uVar13 = puVar3[4];
    uVar19 = puVar3[5];
    uVar14 = puVar4[1];
    uVar15 = puVar4[2];
    uVar20 = puVar4[3];
    *puVar3 = *puVar4;
    puVar3[1] = uVar14;
    puVar3[2] = uVar15;
    puVar3[3] = uVar20;
    uVar14 = puVar4[5];
    puVar3[4] = puVar4[4];
    puVar3[5] = uVar14;
    *puVar4 = uVar8;
    puVar4[1] = uVar11;
    puVar4[2] = uVar17;
    puVar4[3] = uVar12;
    puVar4[4] = uVar13;
    puVar4[5] = uVar19;
    uVar10 = uVar16;
  }
  return;
}



undefined4 * FUN_0000a3fa(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_2;
  param_1[4] = 0;
  uVar1 = FUN_0000a6ec(param_2 * 0x18);
  param_1[5] = uVar1;
  return param_1;
}



void FUN_0000a41a(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*param_1 == param_2) {
    *(undefined4 *)(param_3 + 0x28) = 0;
    *(int *)(param_3 + 0x24) = *param_1;
    iVar2 = *param_1;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x28) = param_3;
    }
    if (iVar2 == 0) {
      param_1[1] = param_3;
    }
    *param_1 = param_3;
    return;
  }
  uVar1 = *(undefined4 *)(param_2 + 0x28);
  *(int *)(param_3 + 0x24) = param_2;
  *(undefined4 *)(param_3 + 0x28) = uVar1;
  *(int *)(*(int *)(param_2 + 0x28) + 0x24) = param_3;
  *(int *)(param_2 + 0x28) = param_3;
  return;
}



void FUN_0000a444(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_2 + 0x28);
  if (iVar1 != 0) {
    param_4 = *(undefined4 *)(param_2 + 0x24);
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x24) = param_4;
  }
  else {
    if (*param_1 != param_2) goto LAB_0000a47e;
    *param_1 = *(int *)(param_2 + 0x24);
  }
  iVar1 = *(int *)(param_2 + 0x24);
  if (iVar1 != 0) {
    param_1 = *(int **)(param_2 + 0x28);
  }
  if (iVar1 != 0) {
    *(int **)(iVar1 + 0x28) = param_1;
  }
  else {
    iVar1 = param_1[1];
    bVar2 = iVar1 == param_2;
    if (bVar2) {
      iVar1 = *(int *)(param_2 + 0x28);
    }
    if (!bVar2) {
LAB_0000a47e:
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    param_1[1] = iVar1;
  }
  *(undefined4 *)(param_2 + 0x28) = 0;
  *(undefined4 *)(param_2 + 0x24) = 0;
  return;
}



void FUN_0000a482(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x24);
  *param_1 = iVar2;
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x28) = 0;
  }
  if (iVar2 == 0) {
    param_1[1] = 0;
  }
  *(undefined4 *)(iVar1 + 0x24) = 0;
  return;
}



void FUN_0000a496(int *param_1,int param_2)

{
  *(int *)(param_2 + 0x28) = param_1[1];
  *(undefined4 *)(param_2 + 0x24) = 0;
  if (param_1[1] == 0) {
    *param_1 = param_2;
  }
  else {
    *(int *)(param_1[1] + 0x24) = param_2;
  }
  param_1[1] = param_2;
  return;
}



void FUN_0000a4ac(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *param_1;
  uVar3 = 0;
  if (uVar1 == 0) {
    param_1[2] = 0;
    *param_1 = param_2;
    return;
  }
  if (param_2 < uVar1) {
    uVar1 = uVar1 - param_2;
  }
  else {
    uVar1 = param_2 - uVar1;
  }
  if (uVar1 != 0) {
    uVar2 = 0xffffffff;
    if (uVar1 != 0xffffffff) {
      uVar2 = uVar1;
    }
    uVar3 = 1;
    uVar1 = param_1[1];
    if (uVar1 == 0) {
      param_1[1] = param_2;
      param_1[2] = 1;
      return;
    }
    if (param_2 < uVar1) {
      uVar1 = uVar1 - param_2;
    }
    else {
      uVar1 = param_2 - uVar1;
    }
    if (uVar1 != 0) {
      param_1[2] = (uint)(uVar1 < uVar2);
      return;
    }
  }
  param_1[2] = uVar3;
  return;
}



// WARNING: Control flow encountered bad instruction data

void FUN_0000a508(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



undefined8 FUN_0000a5d0(int param_1)

{
  return CONCAT44(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c));
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_0000a5dc(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  if (*(byte *)((int)param_1 + 5) != 0) {
    uVar4 = param_1[2];
    uVar5 = param_1[3];
    FUN_0000d758();
    uVar1 = _DAT_00083000;
    uVar3 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    uVar6 = (**(code **)(*param_1 + 8))(param_1);
    uVar2 = (uint)((ulonglong)uVar6 >> 0x20);
    return (uint)(uVar5 < (int)uVar6 + uVar3 + (uint)CARRY4(uVar1,uVar2) +
                          (uint)(uVar4 < uVar1 + uVar2));
  }
  return (uint)*(byte *)((int)param_1 + 5);
}



longlong FUN_0000a62c(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (*(char *)(param_1 + 0x39) == '\0') {
    iVar6 = *(int *)(param_1 + 0x58);
    puVar2 = FUN_00006b20();
    iVar4 = puVar2[2];
    iVar3 = *(int *)(iVar6 + iVar4 * 4 + 0x14);
    if (iVar3 == 0) {
      uVar1 = iVar4 + 1;
      if (1 < uVar1) {
        uVar1 = 0;
      }
      iVar3 = *(int *)(iVar6 + uVar1 * 4 + 0x14);
      if (iVar3 == 0) {
        iVar3 = 0x4b00;
      }
      else {
        puVar2 = FUN_00006b20();
        uVar5 = puVar2[iVar4];
        puVar2 = FUN_00006b20();
        iVar3 = (int)((ulonglong)(iVar3 * ((uint)puVar2[uVar1] / 1000)) / ((ulonglong)uVar5 / 1000))
        ;
      }
    }
    if (DAT_000901fe == 0) {
      return CONCAT44(iVar3,(uint)DAT_000901fe);
    }
    uVar1 = iVar3 + *(int *)(PTR_DAT_000912d4 + (uint)**(byte **)(param_1 + 0x58) * 0x1c + 0x18);
  }
  else {
    uVar1 = 0;
  }
  return (longlong)((ulonglong)uVar1 << 0x20);
}



void FUN_0000a6dc(int param_1)

{
  FUN_0000a6e4(param_1);
  return;
}



void FUN_0000a6e4(int param_1)

{
  FUN_00000168(param_1);
  return;
}



void FUN_0000a6ec(int param_1)

{
  FUN_0000a6f4(param_1);
  return;
}



void FUN_0000a6f4(int param_1)

{
  code **ppcVar1;
  code *pcVar2;
  int iVar3;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while (iVar3 = FUN_00000154(param_1), iVar3 == 0) {
    ppcVar1 = (code **)FUN_000006e8();
    pcVar2 = *ppcVar1;
    if (pcVar2 == (code *)0x0) {
      pcVar2 = thunk_FUN_0000082c + 1;
    }
    (*pcVar2)();
  }
  return;
}



int FUN_0000a71c(int param_1,int param_2,int param_3,undefined *param_4,undefined4 param_5,
                undefined *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 * param_2;
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  if (param_6 == (undefined *)0x0) {
    iVar2 = FUN_0000a6ec(iVar2 + param_3);
  }
  else {
    iVar2 = (*(code *)param_6)();
    if (iVar2 == 0) {
      iVar2 = 0;
      goto LAB_0000a74c;
    }
  }
  iVar2 = param_3 + iVar2;
LAB_0000a74c:
  if (iVar2 != 0) {
    if (param_3 != 0) {
      *(int *)(iVar2 + -8) = param_2;
      *(int *)(iVar2 + -4) = param_1;
    }
    if (param_4 != (undefined *)0x0) {
      iVar1 = 0;
      iVar3 = iVar2;
      while (iVar1 < param_1) {
        (*(code *)param_4)(iVar3);
        iVar1 = iVar1 + 1;
        iVar3 = iVar3 + param_2;
      }
    }
  }
  return iVar2;
}



void FUN_0000a7ae(undefined4 *param_1,undefined param_2)

{
  undefined4 uVar1;
  
  uVar1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
  *param_1 = uVar1;
  param_1[1] = uVar1;
  return;
}



undefined4 FUN_0000a804(void)

{
  return 8;
}



void FUN_0000a824(void)

{
  FUN_00016b50();
  DAT_000900bc = 0x96038;
  DAT_000900c0 = 0x9d080;
  FUN_00016a76(0x7048);
  return;
}



void FUN_0000a850(void)

{
  return;
}



uint FUN_0000a8a4(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)FUN_00000154(0x10);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = param_1;
    piVar1[2] = param_2;
    piVar1[3] = param_3;
    piVar2 = (int *)FUN_000006f0();
    *piVar1 = *piVar2;
    *(int **)piVar2 = piVar1;
  }
  return (uint)(piVar1 == (int *)0x0);
}



void FUN_0000a8d4(int param_1,int param_2,undefined *param_3)

{
  FUN_0000a944(param_2,param_1,0,param_3,0);
  return;
}



void FUN_0000a8ec(int *param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  int **ppiVar3;
  int iVar4;
  
  ppiVar1 = (int **)FUN_000006f0();
  do {
    ppiVar2 = ppiVar1;
    do {
      do {
        ppiVar3 = ppiVar2;
        ppiVar2 = (int **)*ppiVar3;
        if (ppiVar2 == (int **)0x0) {
          return;
        }
      } while ((param_1 != (int *)0x0) && (ppiVar2[3] != param_1));
      *ppiVar3 = *ppiVar2;
      iVar4 = (int)*ppiVar1;
      (*(code *)ppiVar2[2])(ppiVar2[1]);
      FUN_00000168((int)ppiVar2);
      ppiVar2 = ppiVar3;
    } while (*ppiVar1 == (int *)iVar4);
  } while( true );
}



undefined4 FUN_0000a92e(int *param_1)

{
  if (*param_1 != 0) {
    return 0;
  }
  *param_1 = 1;
  return 1;
}



void FUN_0000a944(int param_1,int param_2,int param_3,undefined *param_4,undefined4 param_5)

{
  FUN_0000a71c(param_1,param_2,param_3,param_4,param_5,(undefined *)0x0);
  return;
}



void thunk_FUN_00000060(void)

{
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void thunk_FUN_00000060(void)

{
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000a988(void)

{
  return;
}



void FUN_0000aa28(int param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = param_1 == 1;
  if (DAT_00090434 == 0 && bVar1) {
    param_1 = 1;
  }
  if (DAT_00090434 != 0 || !bVar1) {
    return;
  }
  *(int *)(param_2 + 0x10) = param_1;
  return;
}



void FUN_0000ab20(int param_1,uint *param_2,uint *param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined8 uVar12;
  
  uVar3 = *(int *)(param_1 + 4) * param_2[2];
  if (uVar3 < 0x3d090000) {
    uVar3 = uVar3 / 1000000;
  }
  else {
    uVar3 = 0x3ff;
  }
  uVar7 = *param_2;
  uVar8 = param_2[1];
  uVar9 = *(int *)(param_1 + 4) * 1000;
  uVar2 = (uint)((ulonglong)uVar7 * (ulonglong)uVar3);
  uVar12 = FUN_000001b0(uVar2 + (uVar9 - 1),
                        uVar8 * uVar3 + (int)((ulonglong)uVar7 * (ulonglong)uVar3 >> 0x20) +
                        ((uint)(uVar9 != 0) - 1) + (uint)CARRY4(uVar2,uVar9 - 1),uVar9,0);
  if ((int)uVar12 + (uint)(0x7fff < (uint)((ulonglong)uVar12 >> 0x20)) == 0) {
    uVar2 = (uint)((ulonglong)uVar7 * (ulonglong)uVar3);
    uVar12 = FUN_000001b0(uVar2 + (uVar9 - 1),
                          uVar8 * uVar3 + (int)((ulonglong)uVar7 * (ulonglong)uVar3 >> 0x20) +
                          ((uint)(uVar9 != 0) - 1) + (uint)CARRY4(uVar2,uVar9 - 1),uVar9,0);
    uVar2 = (uint)((ulonglong)uVar12 >> 0x20);
  }
  else {
    uVar2 = 0x7fff;
  }
  uVar4 = param_2[4];
  uVar9 = param_2[5];
  uVar5 = param_2[6];
  uVar10 = param_2[7];
  uVar6 = param_2[8];
  uVar11 = param_2[9];
  lVar1 = (ulonglong)(uVar4 - uVar7) * (ulonglong)uVar3;
  *param_3 = uVar3;
  param_3[1] = uVar2;
  uVar12 = FUN_000002c4((uint)lVar1,
                        (uVar9 - (uVar8 + (uVar4 < uVar7))) * uVar3 +
                        (int)((ulonglong)lVar1 >> 0x20),*(int *)(param_1 + 4) * 1000,0);
  *(short *)(param_3 + 2) = (short)((ulonglong)uVar12 >> 0x20);
  lVar1 = (ulonglong)(uVar5 - uVar7) * (ulonglong)uVar3;
  uVar12 = FUN_000002c4((uint)lVar1,
                        (uVar10 - (uVar8 + (uVar5 < uVar7))) * uVar3 +
                        (int)((ulonglong)lVar1 >> 0x20),*(int *)(param_1 + 4) * 1000,0);
  *(undefined2 *)((int)param_3 + 10) = (short)((ulonglong)uVar12 >> 0x20);
  lVar1 = (ulonglong)(uVar6 - uVar7) * (ulonglong)uVar3;
  uVar12 = FUN_000002c4((uint)lVar1,
                        (uVar11 - (uVar8 + (uVar6 < uVar7))) * uVar3 +
                        (int)((ulonglong)lVar1 >> 0x20),*(int *)(param_1 + 4) * 1000,0);
  *(short *)(param_3 + 3) = (short)((ulonglong)uVar12 >> 0x20);
  return;
}



uint FUN_0000ac70(int *param_1,int param_2,int param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  uint uStack48;
  uint uStack44;
  ushort uStack40;
  ushort uStack38;
  ushort uStack36;
  
  if ((uint)param_1[7] < 0x20010001) {
    return param_1[7];
  }
  if (param_1[1] == 0) {
    return 0;
  }
  uVar1 = param_3 - 1;
  if (2 < uVar1) {
    return uVar1;
  }
  iVar3 = uVar1 * 0x100 + 0x8808;
  iVar4 = uVar1 * 0x100 + 0x8820;
  iVar5 = uVar1 * 0x100 + 0x8824;
  iVar2 = uVar1 * 0x100 + 0x8804;
  iVar6 = uVar1 * 0x100 + 0x8828;
  uVar1 = *param_4 | param_4[1];
  bVar7 = uVar1 != 0;
  if (bVar7) {
    uVar1 = param_4[2];
  }
  if (!bVar7 || uVar1 == 0) {
    *(undefined4 *)(*param_1 + param_2 * 0x4000 + iVar2) = 0;
    *(undefined4 *)(*param_1 + param_2 * 0x4000 + iVar3) = 0;
    *(undefined4 *)(*param_1 + param_2 * 0x4000 + iVar4) = 0;
    *(undefined4 *)(*param_1 + param_2 * 0x4000 + iVar5) = 0;
    *(undefined4 *)(*param_1 + param_2 * 0x4000 + iVar6) = 0;
    return *(uint *)(*param_1 + param_2 * 0x4000 + iVar6);
  }
  FUN_0000ab20((int)param_1,param_4,&uStack48);
  *(uint *)(*param_1 + param_2 * 0x4000 + iVar2) = uStack48 & 0x3ff;
  *(uint *)(*param_1 + param_2 * 0x4000 + iVar3) = uStack44 & 0xffff;
  *(uint *)(*param_1 + param_2 * 0x4000 + iVar4) = (uint)uStack40;
  *(uint *)(*param_1 + param_2 * 0x4000 + iVar5) = (uint)uStack38;
  *(uint *)(*param_1 + param_2 * 0x4000 + iVar6) = (uint)uStack36;
  return *(uint *)(*param_1 + param_2 * 0x4000 + iVar6);
}



uint * FUN_0000af5c(int *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  uint uStack48;
  uint uStack44;
  ushort uStack40;
  ushort uStack38;
  ushort uStack36;
  
  if (param_1[1] == 0) {
    return param_3;
  }
  iVar2 = param_2 * 0x4000 + 0x8328;
  iVar3 = param_2 * 0x4000 + 0x8324;
  iVar4 = param_2 * 0x4000 + 0x8320;
  iVar5 = param_2 * 0x4000 + 0x8308;
  iVar6 = param_2 * 0x4000 + 0x8304;
  uVar1 = *param_3 | param_3[1];
  bVar7 = uVar1 != 0;
  if (bVar7) {
    uVar1 = param_3[2];
  }
  if (!bVar7 || uVar1 == 0) {
    *(undefined4 *)(*param_1 + iVar6) = 0;
    *(undefined4 *)(*param_1 + iVar5) = 0;
    *(undefined4 *)(*param_1 + iVar4) = 0;
    *(undefined4 *)(*param_1 + iVar3) = 0;
    *(undefined4 *)(*param_1 + iVar2) = 0;
    return *(uint **)(*param_1 + iVar2);
  }
  FUN_0000ab20((int)param_1,param_3,&uStack48);
  *(uint *)(*param_1 + iVar6) = uStack48 & 0x3ff;
  *(uint *)(*param_1 + iVar5) = uStack44 & 0xffff;
  *(uint *)(*param_1 + iVar4) = (uint)uStack40;
  *(uint *)(*param_1 + iVar3) = (uint)uStack38;
  *(uint *)(*param_1 + iVar2) = (uint)uStack36;
  return *(uint **)(*param_1 + iVar2);
}



uint * FUN_0000b084(int *param_1,int param_2,int param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar6 = param_2 * 0x4000 + 0x8340;
  iVar3 = param_2 * 0x4000 + 0x8344;
  iVar4 = param_2 * 0x4000 + 0x8348;
  iVar5 = param_2 * 0x4000 + 0x834c;
  if (param_3 == 0) {
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    uVar2 = (param_4[1] & 3) << 8 | *param_4 & 3;
    *(uint *)(*param_1 + iVar5) = uVar2;
    *(uint *)(*param_1 + iVar4) = uVar2;
    *(uint *)(*param_1 + iVar3) = uVar2;
    *(uint *)(*param_1 + iVar6) = uVar2;
    puVar1 = FUN_0000af5c(param_1,param_2,&local_48);
    return puVar1;
  }
  if (param_3 == 1 || param_3 == 3) {
    *(uint *)(*param_1 + iVar5) =
         (param_4[4] & 3) << 8 | (uint)*(byte *)(param_4 + 3) << 0x1f | param_4[5] & 3;
    *(uint *)(*param_1 + iVar4) =
         (param_4[7] & 3) << 8 | (uint)*(byte *)(param_4 + 6) << 0x1f | param_4[8] & 3;
    *(uint *)(*param_1 + iVar3) =
         (param_4[10] & 3) << 8 | (uint)*(byte *)(param_4 + 9) << 0x1f | param_4[0xb] & 3;
    *(uint *)(*param_1 + iVar6) =
         (param_4[0xd] & 3) << 8 | (uint)*(byte *)(param_4 + 0xc) << 0x1f | param_4[0xe] & 3;
    return *(uint **)(*param_1 + iVar6);
  }
  return (uint *)param_1;
}



void FUN_0000b1ac(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  piVar1 = DAT_00090514;
  if (DAT_00090514 == (int *)0x0) {
    return;
  }
  iVar2 = *DAT_00090514;
  uVar3 = FUN_000001b0((uint)((ulonglong)param_1 * 0x4b00),
                       (uint)((ulonglong)param_1 * 0x4b00 >> 0x20),1000,0);
  do {
  } while ((int)uVar3 + (uint)((uint)(*piVar1 - iVar2) < (uint)((ulonglong)uVar3 >> 0x20)) != 0);
  return;
}



void FUN_0000b1e0(void)

{
  int iVar1;
  uint auStack32 [2];
  undefined4 uStack24;
  int aiStack16 [4];
  
  FUN_0000346c(0x200009b,aiStack16);
  iVar1 = FUN_000034e4(aiStack16,(uint *)"QTIMER_BASE",0,auStack32);
  if (iVar1 == 0) {
    DAT_00090514 = uStack24;
    return;
  }
  return;
}



int FUN_0000b220(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < *(uint *)(param_1 + 4)) {
    iVar1 = *(int *)(param_1 + 0xc) + param_2;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



void FUN_0000b22e(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



undefined4 * FUN_0000b234(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_00000154(0x10);
  if (puVar1 == (undefined4 *)0x0) {
LAB_0000b262:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  if (param_1 != 0) {
    iVar2 = FUN_00000154(param_1);
    puVar1[3] = iVar2;
    if (iVar2 == 0) goto LAB_0000b262;
    puVar1[2] = param_1;
  }
  return puVar1;
}



void FUN_0000b266(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00000154(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined *)puVar1 = 1;
    puVar1[1] = param_2;
    puVar1[2] = param_2;
    puVar1[3] = param_1;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000b288(char *param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (*param_1 != '\0') {
    return;
  }
  uVar1 = *(uint *)(param_1 + 4);
  uVar3 = uVar1 + param_3;
  if (uVar3 < uVar1) {
LAB_0000b2e6:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (*(uint *)(param_1 + 8) < uVar3) {
    if ((uVar1 & 0x80000000) == 0) {
      uVar1 = uVar1 << 1;
    }
    else {
      uVar1 = 0xffffffff;
    }
    if (uVar1 <= uVar3) {
      uVar1 = uVar3;
    }
    iVar2 = FUN_00000182(*(int *)(param_1 + 0xc),uVar1);
    *(int *)(param_1 + 0xc) = iVar2;
    if (iVar2 == 0) goto LAB_0000b2e6;
    *(uint *)(param_1 + 8) = uVar1;
  }
  FUN_0000044c(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 4),param_2,param_3);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_3;
  return;
}



undefined4 FUN_0000b2ea(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



void FUN_0000b2ee(char *param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*param_1 == '\0') && (*(int *)(param_1 + 0xc) != 0)) {
    FUN_00000168(*(int *)(param_1 + 0xc));
    *param_1 = '\x01';
  }
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *param_1 = '\x01';
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000b31c(void)

{
  FUN_0000b33c();
  thunk_FUN_00004908(1);
  DAT_00090574 = _DAT_6044d004;
  return;
}



void FUN_0000b33c(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = FUN_00002248();
  if (uVar1 != 0) {
    FUN_00005d60();
  }
  thunk_FUN_0000d758();
  bVar2 = DAT_000934d8 == 1;
  if (bVar2) {
    DAT_000934d8 = 2;
  }
  DAT_00090178 = (uint)bVar2;
  if (DAT_000934dc == 1) {
    DAT_000934dc = 2;
    DAT_00090178 = DAT_00090178 | 2;
  }
  if (DAT_00090178 != 0) {
    FUN_00003970();
  }
  bVar2 = DAT_000934e0 == 1;
  if (bVar2) {
    DAT_000934e0 = 2;
  }
  DAT_0009017c = (uint)bVar2;
  if (DAT_000934e4 == 1) {
    DAT_000934e4 = 2;
    DAT_0009017c = DAT_0009017c | 2;
  }
  if (DAT_0009017c != 0) {
    FUN_00003970();
  }
  thunk_FUN_0001a7ec();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000b3cc(void)

{
  uint uVar1;
  
  uVar1 = (uint)(DAT_000934d8 == 2);
  if (DAT_000934dc == 2) {
    uVar1 = uVar1 | 2;
  }
  if (uVar1 != 0) {
    do {
    } while ((_DAT_6044c0a0 & 1) != 0);
    _DAT_6044c020 = _DAT_6044c020 | 0x11;
    _DAT_6044d004 = DAT_00090574 & 0xfcffffff;
    FUN_0000b1ac(1);
    _DAT_6044d004 = _DAT_6044d004 & 0xfcffffff | DAT_00090574 & 0x3000000;
    (**DAT_00090578)(0x60000000,0,uVar1,&LAB_0000396c_1);
  }
  thunk_FUN_00004908(0);
  FUN_0000b46c();
  return;
}



void FUN_0000b46c(void)

{
  uint uVar1;
  uint uVar2;
  
  thunk_FUN_0000d758();
  if ((DAT_00090178 & 1) != 0) {
    DAT_000934d8 = 1;
  }
  if ((DAT_00090178 & 2) != 0) {
    DAT_000934dc = 1;
  }
  if (DAT_00090178 != 0) {
    FUN_00003984();
  }
  if ((DAT_0009017c & 1) != 0) {
    DAT_000934e0 = 1;
  }
  if ((DAT_0009017c & 2) != 0) {
    DAT_000934e4 = 1;
  }
  if (DAT_0009017c != 0) {
    FUN_00003984();
  }
  thunk_FUN_0001a7ec();
  uVar1 = FUN_00002248();
  if (uVar1 != 0) {
    if (DAT_0009359c != '\0') {
      DAT_0009359c = 0;
      *(undefined4 *)(DAT_0009019c + 0xfb0) = 0xc5acce55;
      uVar1 = *(uint *)(DAT_00090198 + 0xe80);
      uVar2 = *(uint *)(DAT_0009019c + 0x304);
      *(uint *)(DAT_0009019c + 0x304) = *(uint *)(DAT_0009019c + 0x304) & 0x6773 | 0x1000;
      *(uint *)(DAT_0009019c + 0x304) = *(uint *)(DAT_0009019c + 0x304) & 0x7773 | 0x40;
      do {
      } while ((*(uint *)(DAT_0009019c + 0x304) & 0x40) != 0);
      do {
      } while (-1 < *(int *)(DAT_0009019c + 0xc) << 0x1d);
      if ((uVar1 & 1) != 0) {
        *(uint *)(DAT_0009019c + 0x304) = *(uint *)(DAT_0009019c + 0x304) & 0x7773 | 0x4000;
        do {
        } while (-1 < *(int *)(DAT_0009019c + 0xc) << 0x1d);
      }
      *(undefined4 *)(DAT_0009019c + 0x20) = 0;
      *(uint *)(DAT_0009019c + 0x304) = uVar2 & 0x7773;
      *(undefined4 *)(DAT_0009019c + 0x28) = 2;
      *(undefined4 *)(DAT_0009019c + 0x20) = 1;
      do {
      } while (*(int *)(DAT_0009019c + 0xc) << 0x1d < 0);
      *(undefined4 *)(DAT_0009019c + 0xfb0) = 0x3a5331aa;
      return;
    }
    return;
  }
  return;
}



void FUN_0000b4dc(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0009055c;
  if (param_1 != 0) {
    iVar1 = DAT_00090560;
  }
  if (iVar1 != 0) {
    return;
  }
  if (param_1 == 0) {
    DAT_0009055c = DAT_00090550;
    return;
  }
  iVar1 = *(int *)(DAT_00090550 + 8);
  if (iVar1 != 2) {
    if (iVar1 == 4) {
      iVar1 = 0xa8;
      goto LAB_0000b50c;
    }
    if (iVar1 != 5) {
      iVar1 = 0;
      goto LAB_0000b50c;
    }
  }
  iVar1 = 0xb8;
LAB_0000b50c:
  DAT_00090560 = DAT_00090550 + iVar1;
  return;
}



undefined4 FUN_0000b51c(void)

{
  return DAT_0009054c;
}



undefined4 FUN_0000b528(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = &DAT_00090548;
  puVar1 = DAT_00090568;
  if (DAT_00090568 != (undefined4 *)0x0) goto LAB_0000b530;
  iVar2 = FUN_0000b4dc(0);
  iVar2 = *(int *)(iVar2 + 8);
  if (iVar2 == 2) {
LAB_0000b55e:
    iVar2 = 0xb8;
  }
  else {
    if (iVar2 == 4) {
      iVar2 = 0xa8;
    }
    else {
      if (iVar2 == 5) goto LAB_0000b55e;
      iVar2 = 0;
    }
  }
  puVar1 = (undefined4 *)(iVar2 * 2 + 0x68600190);
  *(undefined4 **)(puVar3 + 0x20) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
LAB_0000b530:
  return *puVar1;
}



void FUN_0000b5c0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x0000b5d6. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(DAT_00090578 + 0x18))(0x60000000,0,param_1,param_2);
  return;
}



void FUN_0000b5e0(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = DAT_000934d8;
  if (DAT_000934d8 != 1) {
    iVar2 = DAT_000934dc;
  }
  if ((DAT_000934d8 != 1 && iVar2 != 1) ||
     ((**(code **)(DAT_00090578 + 0x34))
                (0x60000000,0,*(code **)(DAT_00090578 + 0x34),param_4,param_4),
     *(uint *)(param_1 + 8) <= DAT_000934f4)) goto LAB_0000b77c;
  bVar1 = *param_1;
  iVar2 = FUN_0000b4dc(0);
  iVar3 = *(int *)(iVar2 + 8);
  if (iVar3 == 2) {
LAB_0000b6ac:
    iVar3 = 0xb8;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = 0xa8;
    }
    else {
      if (iVar3 == 5) goto LAB_0000b6ac;
      iVar3 = 0;
    }
  }
  iVar2 = iVar2 + iVar3 * 2;
  iVar3 = FUN_0000b528();
  if (iVar3 == 0x44445200) {
    iVar2 = iVar2 + 0x2fc;
  }
  if ((((*(int *)(iVar2 + 4) == 0x4030201) && (iVar2 != -0xc)) && (6 < bVar1)) && (bVar1 < 10)) {
    *(undefined4 *)(&DAT_0009057c + (uint)bVar1 * 4) = *(undefined4 *)(iVar2 + 0x10);
  }
  (**(code **)(DAT_00090578 + 0x20))
            (0x60000000,0,*(undefined4 *)(&DAT_0009057c + (uint)*param_1 * 4));
  uVar4 = 0x12b128;
  if ((DAT_00090570 == 0x962) && (0x12b128 < *(uint *)(param_1 + 8))) {
LAB_0000b694:
    (**(code **)(DAT_00090578 + 0x3c))(0x60000000,0,0,0x271,uVar4);
  }
  else {
    if (*DAT_0009056c != 1) {
      uVar4 = *(undefined4 *)(param_1 + 8);
      goto LAB_0000b694;
    }
    if (*(uint *)(param_1 + 8) < 0x12b129) {
      if (*(uint *)(param_1 + 8) - 0x100591 < 0x2ab98) {
        (**(code **)(DAT_00090578 + 0x24))(0x60000000,0,(uint)(ushort)DAT_0009056c[10]);
        (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,0,DAT_0009056c + 0xb);
        (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,1,DAT_0009056c + 0xf);
      }
      else {
        (**(code **)(DAT_00090578 + 0x24))(0x60000000,0,(uint)(ushort)DAT_0009056c[1]);
        (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,0,DAT_0009056c + 2);
        (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,1,DAT_0009056c + 6);
      }
    }
    else {
      (**(code **)(DAT_00090578 + 0x24))(0x60000000,0,(uint)(ushort)DAT_0009056c[0x13]);
      (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,0,DAT_0009056c + 0x14);
      (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,1,DAT_0009056c + 0x18);
    }
  }
  (**(code **)(DAT_00090578 + 0x2c))(0x60000000,0);
LAB_0000b77c:
  DAT_000934f4 = *(undefined4 *)(param_1 + 8);
  return;
}



void thunk_FUN_0000b46c(void)

{
  uint uVar1;
  uint uVar2;
  
  thunk_FUN_0000d758();
  if ((DAT_00090178 & 1) != 0) {
    DAT_000934d8 = 1;
  }
  if ((DAT_00090178 & 2) != 0) {
    DAT_000934dc = 1;
  }
  if (DAT_00090178 != 0) {
    FUN_00003984();
  }
  if ((DAT_0009017c & 1) != 0) {
    DAT_000934e0 = 1;
  }
  if ((DAT_0009017c & 2) != 0) {
    DAT_000934e4 = 1;
  }
  if (DAT_0009017c != 0) {
    FUN_00003984();
  }
  thunk_FUN_0001a7ec();
  uVar1 = FUN_00002248();
  if (uVar1 != 0) {
    if (DAT_0009359c != '\0') {
      DAT_0009359c = 0;
      *(undefined4 *)(DAT_0009019c + 0xfb0) = 0xc5acce55;
      uVar1 = *(uint *)(DAT_00090198 + 0xe80);
      uVar2 = *(uint *)(DAT_0009019c + 0x304);
      *(uint *)(DAT_0009019c + 0x304) = *(uint *)(DAT_0009019c + 0x304) & 0x6773 | 0x1000;
      *(uint *)(DAT_0009019c + 0x304) = *(uint *)(DAT_0009019c + 0x304) & 0x7773 | 0x40;
      do {
      } while ((*(uint *)(DAT_0009019c + 0x304) & 0x40) != 0);
      do {
      } while (-1 < *(int *)(DAT_0009019c + 0xc) << 0x1d);
      if ((uVar1 & 1) != 0) {
        *(uint *)(DAT_0009019c + 0x304) = *(uint *)(DAT_0009019c + 0x304) & 0x7773 | 0x4000;
        do {
        } while (-1 < *(int *)(DAT_0009019c + 0xc) << 0x1d);
      }
      *(undefined4 *)(DAT_0009019c + 0x20) = 0;
      *(uint *)(DAT_0009019c + 0x304) = uVar2 & 0x7773;
      *(undefined4 *)(DAT_0009019c + 0x28) = 2;
      *(undefined4 *)(DAT_0009019c + 0x20) = 1;
      do {
      } while (*(int *)(DAT_0009019c + 0xc) << 0x1d < 0);
      *(undefined4 *)(DAT_0009019c + 0xfb0) = 0x3a5331aa;
      return;
    }
    return;
  }
  return;
}



void FUN_0000b7a8(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    return;
  }
  (**(code **)(DAT_00090578 + 0x10))(0x60000000,param_2,&LAB_0000b314_1);
                    // WARNING: Could not recover jumptable at 0x0000b7dc. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(DAT_00090578 + 0x14))(0x60000000,0,param_1,param_2);
  return;
}



void FUN_0000b7ec(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_000934d8;
  if (DAT_000934d8 != 1) {
    iVar2 = DAT_000934dc;
  }
  if (DAT_000934d8 != 1 && iVar2 != 1) {
    return;
  }
  if (DAT_000934f4 <= *(uint *)(param_1 + 8)) goto LAB_0000b8c2;
  bVar1 = *param_1;
  iVar2 = FUN_0000b4dc(0);
  iVar3 = *(int *)(iVar2 + 8);
  if (iVar3 == 2) {
LAB_0000b892:
    iVar3 = 0xb8;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = 0xa8;
    }
    else {
      if (iVar3 == 5) goto LAB_0000b892;
      iVar3 = 0;
    }
  }
  iVar2 = iVar2 + iVar3 * 2;
  iVar3 = FUN_0000b528();
  if (iVar3 == 0x44445200) {
    iVar2 = iVar2 + 0x2fc;
  }
  if ((((*(int *)(iVar2 + 4) == 0x4030201) && (iVar2 != -0xc)) && (6 < bVar1)) && (bVar1 < 10)) {
    *(undefined4 *)(&DAT_0009057c + (uint)bVar1 * 4) = *(undefined4 *)(iVar2 + 0x10);
  }
  (**(code **)(DAT_00090578 + 0x20))
            (0x60000000,0,*(undefined4 *)(&DAT_0009057c + (uint)*param_1 * 4),
             *(code **)(DAT_00090578 + 0x20),param_4);
  if ((DAT_00090570 == 0x962) && (0x12b128 < *(uint *)(param_1 + 8))) {
    (**(code **)(DAT_00090578 + 0x3c))(0x60000000,0,0,0x271,0x12b128);
  }
  else {
    if (*DAT_0009056c == 1) {
      if (*(uint *)(param_1 + 8) < 0x12b129) {
        if (*(uint *)(param_1 + 8) - 0x100591 < 0x2ab98) {
          (**(code **)(DAT_00090578 + 0x24))(0x60000000,0,(uint)(ushort)DAT_0009056c[10]);
          (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,0,DAT_0009056c + 0xb);
          (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,1,DAT_0009056c + 0xf);
        }
        else {
          (**(code **)(DAT_00090578 + 0x24))(0x60000000,0,(uint)(ushort)DAT_0009056c[1]);
          (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,0,DAT_0009056c + 2);
          (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,1,DAT_0009056c + 6);
        }
      }
      else {
        (**(code **)(DAT_00090578 + 0x24))(0x60000000,0,(uint)(ushort)DAT_0009056c[0x13]);
        (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,0,DAT_0009056c + 0x14);
        (**(code **)(DAT_00090578 + 0x28))(0x60000000,0,1,DAT_0009056c + 0x18);
      }
    }
    else {
      (**(code **)(DAT_00090578 + 0x3c))(0x60000000,0,0,0x271,*(undefined4 *)(param_1 + 8));
    }
  }
  (**(code **)(DAT_00090578 + 0x2c))(0x60000000,0);
LAB_0000b8c2:
                    // WARNING: Could not recover jumptable at 0x0000b8d2. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(DAT_00090578 + 0x30))(0x60000000,0);
  return;
}



void thunk_FUN_0000b33c(void)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = FUN_00002248();
  if (uVar1 != 0) {
    FUN_00005d60();
  }
  thunk_FUN_0000d758();
  bVar2 = DAT_000934d8 == 1;
  if (bVar2) {
    DAT_000934d8 = 2;
  }
  DAT_00090178 = (uint)bVar2;
  if (DAT_000934dc == 1) {
    DAT_000934dc = 2;
    DAT_00090178 = DAT_00090178 | 2;
  }
  if (DAT_00090178 != 0) {
    FUN_00003970();
  }
  bVar2 = DAT_000934e0 == 1;
  if (bVar2) {
    DAT_000934e0 = 2;
  }
  DAT_0009017c = (uint)bVar2;
  if (DAT_000934e4 == 1) {
    DAT_000934e4 = 2;
    DAT_0009017c = DAT_0009017c | 2;
  }
  if (DAT_0009017c != 0) {
    FUN_00003970();
  }
  thunk_FUN_0001a7ec();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000b9bc(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00014250((uint *)"vddcx");
  iVar2 = FUN_00014250((uint *)"vddmx");
  DAT_000934f4 = 0x118c30;
  FUN_00014d30(iVar1,0,(int)&LAB_0000b7e8_1,0);
  FUN_00014d30(iVar1,1,(int)&LAB_0000b5dc_1,0);
  FUN_00014d30(iVar2,0,(int)(FUN_0000b7ec + 1),0);
  FUN_00014d30(iVar2,1,(int)(FUN_0000b5e0 + 1),0);
  iVar1 = FUN_0000b51c();
  DAT_00090570 = (uint)(_DAT_61110010 << 4) >> 0x10;
  DAT_00090578 = *(undefined4 *)(iVar1 + 4);
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_0000ba4c(uint param_1,undefined4 param_2,uint param_3,uint param_4,undefined *param_5,
                uint param_6,int *param_7)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  undefined8 uVar9;
  
  if (DAT_000939e0 == '\0') {
    return 0xe;
  }
  uVar1 = ((uint)DAT_000939f0 + 1) % 10;
  DAT_000939f0 = (byte)uVar1;
  (&DAT_00093a0c)[uVar1 * 0x18] = 1;
  (&DAT_000939fe)[(uint)DAT_000939f0 * 0x18] = (char)param_1;
  (&DAT_000939f8)[(uint)DAT_000939f0 * 0x18] = (char)param_3;
  *(short *)(&DAT_000939fa + (uint)DAT_000939f0 * 0x18) = (short)param_4;
  (&DAT_000939ff)[(uint)DAT_000939f0 * 0x18] = (char)param_6;
  uVar9 = FUN_0000699c();
  uVar1 = (uint)DAT_000939f0;
  *(int *)(&DAT_00093a00 + uVar1 * 0x18) = (int)((ulonglong)uVar9 >> 0x20);
  *(int *)(&DAT_00093a04 + uVar1 * 0x18) = (int)uVar9;
  iVar2 = FUN_00005730(param_1,param_2,param_3,param_4,(int)param_5,param_6,param_7);
  if (iVar2 != 0) {
    iVar3 = FUN_0000687c();
    if (iVar3 == 0) {
      iVar2 = 10;
    }
    else {
      iVar3 = FUN_00006948();
      if (iVar3 == 0) {
        iVar2 = 9;
      }
    }
  }
  iVar3 = (uint)DAT_000939f0 * 0x18;
  uVar1 = (uint)(byte)(&DAT_000939fe)[iVar3];
  bVar8 = uVar1 == param_1;
  if (bVar8) {
    uVar1 = (uint)(byte)(&DAT_000939f8)[iVar3];
  }
  if (bVar8 && uVar1 == param_3) {
    uVar1 = (uint)*(ushort *)(&DAT_000939fa + iVar3);
    bVar8 = uVar1 == param_4;
    if (bVar8) {
      uVar1 = (uint)(byte)(&DAT_000939ff)[iVar3];
    }
    if (bVar8 && uVar1 == param_6) {
      (&DAT_00093a0c)[iVar3] = 2;
      (&DAT_000939fd)[(uint)DAT_000939f0 * 0x18] = (char)iVar2;
      if (param_5 != (undefined *)0x0) {
        (&DAT_000939fc)[(uint)DAT_000939f0 * 0x18] = *param_5;
      }
      iVar5 = *(int *)(&DAT_00093a00 + (uint)DAT_000939f0 * 0x18);
      iVar3 = FUN_0000699c();
      *(int *)(&DAT_00093a08 + (uint)DAT_000939f0 * 0x18) = iVar3 - iVar5;
      goto LAB_0000bb82;
    }
  }
  DAT_00093c80 = 1;
LAB_0000bb82:
  if (iVar2 != 0) {
    if (iVar2 != 0x18) {
      *(short *)(&DAT_00093c50 + param_1 * 2) = *(short *)(&DAT_00093c50 + param_1 * 2) + 1;
    }
    uVar1 = ((uint)DAT_000939f1 + 1) % 5;
    DAT_000939f1 = (byte)uVar1;
    iVar3 = (uint)DAT_000939f0 * 0x18;
    iVar5 = uVar1 * 0x18;
    uVar4 = *(undefined4 *)(&DAT_000939fc + iVar3);
    uVar6 = *(undefined4 *)(&DAT_00093a00 + iVar3);
    uVar7 = *(undefined4 *)(&DAT_00093a04 + iVar3);
    *(undefined4 *)(&DAT_00093ae8 + iVar5) = *(undefined4 *)(&DAT_000939f8 + iVar3);
    *(undefined4 *)(&DAT_00093aec + iVar5) = uVar4;
    *(undefined4 *)(&DAT_00093af0 + iVar5) = uVar6;
    *(undefined4 *)(&DAT_00093af4 + iVar5) = uVar7;
    uVar6 = *(undefined4 *)(&DAT_00093a0c + iVar3);
    *(undefined4 *)(&DAT_00093af8 + iVar5) = *(undefined4 *)(&DAT_00093a08 + iVar3);
    *(undefined4 *)(&DAT_00093afc + iVar5) = uVar6;
    FUN_00005a38((undefined4 *)&DAT_00093c74);
    if (iVar2 == 8) {
      FUN_00006a54(DAT_00091840,0,"Fatal: Timeout while executing SPMI transaction",uVar4);
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    if (iVar2 == 1) {
      FUN_00006a54(DAT_00091840,0,"Fatal: SPMI bus busy",uVar4);
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
  }
  return iVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000bc6c(void)

{
  do {
  } while (_DAT_68600b18 == 0x53444247);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000bd18(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r1;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int local_2c;
  bool bVar10;
  undefined8 uVar11;
  
  DAT_00091320 = 1;
  uVar1 = FUN_0001a108();
  FUN_0001682c((char)uVar1);
  uVar2 = (uint)DAT_00091321;
  if (DAT_00091321 != 0) {
    uVar2 = 10;
  }
  FUN_000167f0(uVar2);
  FUN_0000d758();
  uVar2 = _DAT_00083000;
  uVar7 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  uVar5 = uVar2 + DAT_00095520;
  uVar7 = uVar7 + DAT_00095524 + (uint)CARRY4(uVar2,DAT_00095520);
  FUN_0001a3dc();
  uVar11 = FUN_00018118();
  uVar2 = (uint)((ulonglong)uVar11 >> 0x20);
  if (DAT_0009551c < (int)uVar11 + (uint)(DAT_00095518 < uVar2)) {
    uVar8 = uVar2 - DAT_00095518;
    uVar9 = (int)uVar11 - (DAT_0009551c + (uVar2 < DAT_00095518));
  }
  else {
    uVar8 = 0;
    uVar9 = uVar8;
  }
  uVar2 = FUN_0001a144();
  if (uVar2 != 0) {
    uVar2 = FUN_0001a150();
    bVar10 = uVar8 < uVar2;
    uVar8 = uVar8 - uVar2;
    uVar9 = uVar9 - bVar10;
  }
  if (uVar7 < uVar9 + (uVar5 < uVar8)) {
    uVar2 = uVar8 - uVar5;
    uVar9 = uVar9 - (uVar7 + (uVar8 < uVar5));
  }
  else {
    uVar2 = 0;
    uVar9 = uVar2;
  }
  if ((uVar2 | uVar9) == 0) {
    FUN_000065ec(0x142,DAT_00095528,0,0,0);
    DAT_00091320 = 0;
    DAT_00091328 = DAT_00091328 + 1;
    return;
  }
  uVar5 = uVar2 + DAT_00091338;
  local_2c = uVar9 + DAT_0009133c + (uint)CARRY4(uVar2,DAT_00091338);
  uVar2 = (_DAT_e000e004 & 0x1f) + 1;
  FUN_0001aea4();
  iVar3 = FUN_0000d5a0();
  if ((DAT_00091324 == (undefined4 *)0x0) &&
     (DAT_00091324 = (undefined4 *)FUN_00000154(uVar2 * 4), DAT_00091324 == (undefined4 *)0x0)) {
LAB_0000bef2:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (uVar2 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = uVar2 & 1;
    if (uVar7 == 1) {
      *DAT_00091324 = _DAT_e000e100;
      _DAT_e000e180 = 0xffffffff;
    }
  }
  if (uVar7 < uVar2) {
    do {
      iVar4 = uVar7 * 4;
      DAT_00091324[uVar7] = *(undefined4 *)(&DAT_e000e100 + iVar4);
      *(undefined4 *)(&DAT_e000e180 + iVar4) = 0xffffffff;
      DAT_00091324[uVar7 + 1] = *(undefined4 *)(&DAT_e000e104 + iVar4);
      *(undefined4 *)(&DAT_e000e184 + iVar4) = 0xffffffff;
      uVar7 = uVar7 + 2;
    } while ((int)uVar7 < (int)uVar2);
  }
  _DAT_e000e284 = 0x400;
  _DAT_e000e104 = 0x400;
  if (iVar3 != 0) {
    FUN_000065ec(0x142,DAT_00095528,1,0,0);
    DAT_00091320 = 0;
    DAT_00091328 = DAT_00091328 + 1;
    return;
  }
  FUN_00004838();
  FUN_0000c3ae();
  if (1 < DAT_00095528) goto LAB_0000bef2;
  iVar3 = DAT_00091330 + DAT_00095528 * 0x30;
  *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
  FUN_0000d758();
  uVar2 = _DAT_00083000;
  uVar9 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  uVar7 = DAT_00095528;
  iVar3 = DAT_00091330 + DAT_00095528 * 0x30;
  *(uint *)(iVar3 + 8) = uVar2;
  *(uint *)(iVar3 + 0xc) = uVar9;
  uVar1 = *(undefined4 *)(iVar3 + 4);
  uVar2 = 0;
  FUN_000065ec(0x140,uVar7,uVar1,0,0);
  FUN_000162d4();
  FUN_000027ec(1,(uint)DAT_00091322);
  FUN_0000dcb8();
  uVar2 = FUN_0001114c(1,extraout_r1,uVar1,uVar2);
  if (uVar2 != 0) goto LAB_0000bef2;
  FUN_000027ec(1,0);
  FUN_000065ec(0x146,DAT_00095528,uVar5,0,0);
  iVar3 = 0;
  puVar6 = (undefined4 *)&DAT_604a0000;
  uVar2 = 0;
  uVar7 = FUN_00002248();
  FUN_000065ec(0x148,_DAT_604a008c,_DAT_604a0090,0,0);
  if (uVar7 != 0) {
    FUN_000062ac();
  }
  _DAT_604a1000 = _DAT_604a1000 & 3 | 0x100;
  _DAT_00080004 = 7;
  if ((uVar7 != 0) && (iVar3 = -((_DAT_60802fb4 << 0x1e) >> 0x1f), iVar3 != 0)) {
    _DAT_60802fb0 = 0xc5acce55;
    _DAT_60802060 = _DAT_60802060 | 1;
  }
  do {
    puVar6 = puVar6 + 1;
    (&DAT_0009420c)[uVar2] = *puVar6;
    puVar6 = puVar6 + 2;
    uVar9 = uVar2 + 2;
    (&DAT_00094210)[uVar2] = *puVar6;
    uVar2 = uVar9;
  } while (uVar9 < 0x32);
  FUN_000167f0(4);
  uVar2 = _DAT_604a5000 + uVar5;
  uVar5 = (_DAT_604a5004 & 0xffffff) + local_2c + (uint)CARRY4(_DAT_604a5000,uVar5);
  if (uVar5 < (_DAT_604a5004 & 0xffffff) + (uint)(uVar2 < _DAT_604a5000)) {
    uVar2 = 0xffffffff;
    uVar5 = 0xffffff;
  }
  DAT_00090630 = uVar2;
  DAT_00090634 = uVar5;
  FUN_000065ec(0x149,uVar2,uVar5,0,0);
  _DAT_604a502c = _DAT_604a502c & 7 | 1;
  iVar4 = _DAT_604a0070 << 0xf;
  _DAT_604a5020 = uVar2;
  _DAT_604a5024 = uVar5;
  FUN_0000c3ac();
  local_2c = FUN_00018410();
  if (local_2c == 0) {
    FUN_00000108();
  }
  else {
    FUN_000065ec(0x142,3,2,0,0);
    DAT_00090628 = DAT_00090628 + 1;
  }
  FUN_0000c3ae();
  if (iVar3 != 0) {
    _DAT_60802060 = _DAT_60802060 & 0xfffffffe;
    _DAT_60802fb0 = 0;
  }
  _DAT_604a1000 = _DAT_604a1000 & 3;
  _DAT_00080004 = 1;
  if (iVar4 < 0 || (_DAT_604a0074 & 0xf) != 9) {
    if ((_DAT_604a0074 & 0xf) == 0) goto LAB_00004fb6;
  }
  else {
    _DAT_604a0080 = 1;
  }
  do {
  } while ((_DAT_604a0074 & 0xf) != 5);
LAB_00004fb6:
  _DAT_604a502c = _DAT_604a502c & 6;
  FUN_000167f0(5);
  uVar5 = _DAT_604a0090;
  uVar2 = _DAT_604a008c;
  DAT_00090638 = _DAT_604a00ac;
  DAT_0009063c = _DAT_604a00b0;
  if (uVar7 != 0) {
    FUN_00006280();
  }
  FUN_000065ec(0x145,DAT_00090638 & uVar2,DAT_0009063c & uVar5,0,0);
  do {
  } while ((_DAT_604a0074 & 0xf) != 0);
  _DAT_604a0084 = 0xffffffff;
  _DAT_604a0088 = 0xffffffff;
  _DAT_604a008c = uVar2;
  _DAT_604a0090 = uVar5;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000bf44(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  FUN_0000d758();
  FUN_0001a7ec();
  FUN_000065ec(0x141,DAT_00095528,0,0,0);
  if (DAT_00091320 != '\0') {
    FUN_0000488c();
    FUN_000026cc(1,0);
    iVar1 = FUN_000111e0(1);
    if (iVar1 != 0) {
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    FUN_000026cc(1,(uint)DAT_00091322);
    FUN_0001558c();
  }
  uVar3 = (_DAT_e000e004 & 0x1f) + 1;
  if (uVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = uVar3 & 1;
    if (uVar2 == 1) {
      _DAT_e000e100 = *DAT_00091324;
    }
  }
  if (uVar2 < uVar3) {
    do {
      *(undefined4 *)(&DAT_e000e100 + uVar2 * 4) = DAT_00091324[uVar2];
      *(undefined4 *)(&DAT_e000e104 + uVar2 * 4) = DAT_00091324[uVar2 + 1];
      uVar2 = uVar2 + 2;
    } while ((int)uVar2 < (int)uVar3);
  }
  FUN_0001aeb4();
  _DAT_e000e184 = 0x400;
  thunk_FUN_00004adc();
  FUN_0000c3ac();
  FUN_000065ec(0x147,DAT_00095528,0,0,0);
  if (DAT_00091321 == '\0') {
    FUN_000167f0(1);
    FUN_00016764(0);
    iVar1 = 1;
  }
  else {
    FUN_000167f0(0xb);
    FUN_00016764(6);
    iVar1 = 7;
  }
  FUN_00016764(iVar1);
  if (DAT_00091320 == '\0') {
    return;
  }
  FUN_0000d758();
  uVar3 = _DAT_00083000;
  uVar5 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  iVar1 = DAT_00091330 + DAT_00095528 * 0x30;
  *(uint *)(iVar1 + 0x10) = uVar3;
  *(uint *)(iVar1 + 0x14) = uVar5;
  uVar2 = uVar3 - *(uint *)(iVar1 + 8);
  uVar4 = *(uint *)(iVar1 + 0x18);
  *(int *)(iVar1 + 0x18) = uVar2 + uVar4;
  *(int *)(iVar1 + 0x1c) =
       (uVar5 - (*(int *)(iVar1 + 0xc) + (uint)(uVar3 < *(uint *)(iVar1 + 8)))) +
       *(int *)(iVar1 + 0x1c) + (uint)CARRY4(uVar2,uVar4);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000c0a4(int param_1)

{
  if (param_1 != 0) {
    param_1 = 3;
  }
  _DAT_00080044 = param_1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000c0b4(void)

{
  if (DAT_00090440 != '\0') {
    return;
  }
  DAT_00090440 = 1;
  _DAT_00080008 = 0;
  FUN_0000b1ac(0x99);
  FUN_0000d758();
  do {
  } while ((_DAT_0008004c & 0x100000) == 0);
  _DAT_0008004c = _DAT_0008004c & 0x100000 | 0x400;
  FUN_0001a7ec();
  FUN_0000d758();
  do {
  } while ((_DAT_00080050 & 0x100000) == 0);
  _DAT_00080050 = _DAT_00080050 & 0x100000 | 0x800;
  FUN_0001a7ec();
  _DAT_00080044 = 3;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000c120(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 in_lr;
  
  if (DAT_00090444 == 0) {
    FUN_0000d758();
    do {
    } while ((_DAT_00080040 & 2) == 0);
    _DAT_00080040 = _DAT_00080040 & 3 | 1;
    (&DAT_000937d0)[DAT_00093810 * 0x10] = 0;
    *(undefined4 *)(&DAT_000937d4 + DAT_00093810 * 0x10) = in_lr;
    FUN_0000d758();
    uVar2 = _DAT_00083000;
    uVar3 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    iVar1 = DAT_00093810 * 0x10;
    *(undefined4 *)(&DAT_000937d8 + iVar1) = uVar2;
    *(uint *)(&DAT_000937dc + iVar1) = uVar3;
    DAT_00093810 = DAT_00093810 + 1 & 3;
    FUN_0001a7ec();
    return;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000c1a0(uint param_1)

{
  FUN_0000d758();
  do {
  } while ((_DAT_0008004c & 0x100000) == 0);
  _DAT_0008004c = _DAT_0008004c & 0x100000 | param_1 & 0xfffff;
  FUN_0001a7ec();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000c1ca(uint param_1)

{
  FUN_0000d758();
  do {
  } while ((_DAT_00080050 & 0x100000) == 0);
  _DAT_00080050 = _DAT_00080050 & 0x100000 | param_1 & 0xfffff;
  FUN_0001a7ec();
  return;
}



void FUN_0000c1f4(undefined4 param_1,undefined4 param_2)

{
  FUN_000065ec(0xd3,param_1,param_2,0,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000c230(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  disableIRQinterrupts();
  _DAT_00080030 = 0xffffffff;
  _DAT_00080034 = 0xffffffff;
  _DAT_00080038 = 0xffffffff;
  _DAT_0008003c = 0xffffffff;
  iVar2 = (_DAT_e000e004 & 0x1f) + 1;
  uVar3 = iVar2 * 0x20;
  if (uVar3 < 0x20) {
    iVar4 = 0;
  }
  else {
    iVar4 = -(iVar2 * -0x80000000 >> 0x1f);
    if (iVar4 == 1) {
      _DAT_e000e180 = 0xffffffff;
    }
  }
  while (iVar4 < (int)uVar3 >> 5) {
    *(undefined4 *)(&DAT_e000e180 + iVar4 * 4) = 0xffffffff;
    *(undefined4 *)(&DAT_e000e184 + iVar4 * 4) = 0xffffffff;
    iVar4 = iVar4 + 2;
  }
  if (uVar3 < 0x20) {
    iVar4 = 0;
  }
  else {
    iVar4 = -(iVar2 * -0x80000000 >> 0x1f);
    if (iVar4 == 1) {
      _DAT_e000e280 = 0xffffffff;
    }
  }
  while (iVar4 < (int)uVar3 >> 5) {
    *(undefined4 *)(&DAT_e000e280 + iVar4 * 4) = 0xffffffff;
    *(undefined4 *)(&DAT_e000e284 + iVar4 * 4) = 0xffffffff;
    iVar4 = iVar4 + 2;
  }
  _DAT_e000ed0c = 0x5fa0000;
  if (iVar2 == 2 || uVar3 < 0x40) {
    iVar4 = 0;
    while (iVar4 < (int)uVar3 >> 2) {
      *(undefined4 *)(&DAT_e000e400 + iVar4 * 4) = 0xffffffff;
      iVar4 = iVar4 + 1;
    }
    _DAT_e000ed08 = &DAT_00090200;
    _DAT_e000ed14 = _DAT_e000ed14 | 0x210;
    _DAT_e000ed18 = 0;
    _DAT_e000ed1c = 0xc0000000;
    _DAT_e000ed20 = 0xffff0080;
    _DAT_e000ed24 = 0x70000;
    iVar4 = 0;
    if (iVar2 != 0) {
      do {
        if ((&PTR_DAT_00090240)[iVar4] == (undefined *)0x0) {
          (&PTR_DAT_00090240)[iVar4] = &DAT_0000a98b;
        }
        if ((&PTR_DAT_00090240)[iVar4] != &DAT_0000a98b) {
          *(int *)(&DAT_e000e100 + ((int)(iVar4 + ((uint)(iVar4 >> 0x1f) >> 0x1b)) >> 5) * 4) =
               1 << iVar4 % 0x20;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 + iVar2 * -0x20 < 0 != SBORROW4(iVar4,uVar3));
    }
    _DAT_e000e430 = _DAT_e000e430 & 0xffff00ff;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0);
    }
    iVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar2 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0x10);
    }
    if ((DAT_000900c4 == 0) || (iVar2 != 0)) {
      enableIRQinterrupts();
      DAT_000900c4 = DAT_000900c4 + 1;
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 FUN_0000c3a4(void)

{
  return DAT_0009001c;
}



void FUN_0000c3ac(void)

{
  return;
}



void FUN_0000c3ae(void)

{
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000c3b0(int param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  
  if ((*(uint *)(param_1 + 0x20) | *(uint *)(param_1 + 0x24)) == 0) {
    pbVar6 = *(byte **)(param_1 + 0x14);
    bVar1 = *pbVar6;
    bVar2 = pbVar6[1];
    *(undefined4 *)((uint)bVar2 * 0x1000 + 0x61000000) = 0x303;
    *(int *)((uint)bVar1 * 0x20 + (uint)(bVar2 >> 5) * 4 + 0x61003020) = 1 << ((uint)bVar2 & 0x1f);
    if (*(short *)(pbVar6 + 2) == 0) {
      return;
    }
    FUN_0000d758();
    uVar3 = _DAT_00083000;
    uVar7 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    iVar4 = uVar3 + (uint)*(ushort *)(pbVar6 + 2);
    iVar5 = uVar7 + CARRY4(uVar3,(uint)*(ushort *)(pbVar6 + 2));
  }
  else {
    iVar4 = 0;
    iVar5 = iVar4;
  }
  *(int *)(param_1 + 0x20) = iVar4;
  *(int *)(param_1 + 0x24) = iVar5;
  return;
}



void FUN_0000c42c(void)

{
  FUN_00017124(0x6f697067,3,4,FUN_0000c454 + 1,0xc3b1,0);
  return;
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0000c454(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack32;
  int iStack28;
  int *piStack24;
  
  iVar5 = *(int *)(param_1 + 0x10);
  uVar2 = FUN_0000d61a(*(int **)(param_1 + 0x14));
  if (uVar2 != 0) {
    return;
  }
  do {
    piVar3 = (int *)FUN_0000d658(*(int **)(param_1 + 0x14),&iStack28,&uStack32,&piStack24);
    piVar1 = piVar3;
    if (piVar3 != (int *)0x0) {
      piVar1 = piStack24;
    }
    if (piVar3 == (int *)0x0 || piVar1 == (int *)0x0) goto LAB_0000c4ce;
    iVar4 = *piVar1;
    if (iStack28 == 0x626d756e) {
      if (uStack32 != 4) goto LAB_0000c4ce;
      *(undefined *)(iVar5 + 1) = (char)iVar4;
    }
    else {
      if (iStack28 == 0x74617473) {
        if (uStack32 != 4) goto LAB_0000c4ce;
        *(bool *)iVar5 = iVar4 != 0;
      }
      else {
        if (iStack28 != 0x74746573) goto LAB_0000c49a;
      }
      if (uStack32 != 4) {
LAB_0000c4ce:
                    // WARNING: Subroutine does not return
        FUN_00000060();
      }
      *(undefined2 *)(iVar5 + 2) = (short)iVar4;
    }
LAB_0000c49a:
    uVar2 = FUN_0000d61a(*(int **)(param_1 + 0x14));
    if (uVar2 != 0) {
      return;
    }
  } while( true );
}



void FUN_0000c4dc(int *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 != (int *)0x0) {
    iVar3 = *param_1;
    if ((uint)param_1[1] < *(uint *)(iVar3 + 8)) {
      *(undefined4 *)(*(int *)(iVar3 + 0xc) + param_1[1] * 4) = param_2;
      uVar1 = 1;
      uVar2 = **(uint **)(iVar3 + 0xc);
      if (1 < *(uint *)(iVar3 + 8)) {
        do {
          uVar4 = (*(uint **)(iVar3 + 0xc))[uVar1];
          if (uVar2 <= uVar4) {
            uVar2 = uVar4;
          }
          uVar1 = uVar1 + 1;
        } while (uVar1 < *(uint *)(iVar3 + 8));
      }
      FUN_0000ec02(*(int *)(iVar3 + 4),uVar2);
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000c51c(int param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(*(int *)(DAT_000905b8 + 0x68) + param_4 * 4) + 8);
  do {
    if (*(uint *)(DAT_000905b8 + 100) <= param_4) {
      return;
    }
    puVar1 = *(undefined4 **)(*(int *)(DAT_000905b8 + 0x68) + param_4 * 4);
    if (puVar1[2] != iVar2) {
      return;
    }
    if (param_1 == 0) {
      if (param_3 < param_2) goto LAB_0000c54a;
    }
    else {
      if ((param_1 == 1) && (param_2 < param_3)) {
LAB_0000c54a:
        FUN_0001a814(puVar1,param_2,param_3,0);
      }
    }
    param_4 = param_4 + 1;
  } while( true );
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0000c578(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined3 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  undefined4 uStack88;
  undefined4 uStack84;
  undefined4 uStack80;
  undefined4 uStack76;
  undefined4 uStack72;
  undefined4 uStack68;
  undefined4 uStack64;
  undefined4 uStack60;
  undefined4 uStack56;
  undefined4 uStack52;
  undefined4 uStack48;
  undefined4 uStack44;
  undefined4 uStack40;
  undefined4 uStack36;
  undefined4 uStack32;
  uint uStack28;
  
  DAT_000905b8 = FUN_0000c668(param_1,param_2,param_3,param_4);
  if (DAT_000905b8 != 0) {
    bVar8 = *(int *)(DAT_000905b8 + 100) != 0;
    if (!bVar8) {
      return;
    }
    uVar6 = 0;
    uVar1 = uStack88._1_3_;
    if (bVar8) {
      do {
        uStack88._1_3_ = uVar1;
        puVar5 = *(undefined4 **)(*(int *)(DAT_000905b8 + 0x68) + uVar6 * 4);
        iVar2 = FUN_000015c0((uint *)puVar5[1],puVar5 + 2);
        if (iVar2 != 0) goto LAB_0000c648;
        uStack88 = 0;
        uStack84 = 0;
        uStack80 = 0;
        uStack76 = 0;
        uStack72 = 0;
        uStack68 = 0;
        uStack64 = 0;
        uStack60 = 0;
        uStack56 = 0;
        uStack52 = 0;
        uStack48 = 0;
        uStack44 = 0;
        uStack32 = 0;
        uStack40 = 1;
        uStack36 = 0;
        puVar4 = (undefined *)puVar5[5];
        uStack88._1_3_ = 0;
        uVar1 = uStack88._1_3_;
        FUN_000039ee(*puVar5,puVar5[4],puVar4,&uStack88);
        uStack88 = (uint)(byte)uStack88;
        FUN_00001544(puVar5[2],&uStack28,puVar4);
        uStack88 = (uint)(byte)uStack88;
        FUN_0001a814(puVar5,0,uStack28 / 1000,1);
        uStack88._1_3_ = 0;
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(DAT_000905b8 + 100));
    }
    uVar1 = uStack88._1_3_;
    iVar2 = 0;
    uVar6 = 0;
    if (*(int *)(DAT_000905b8 + 100) == 0) {
      return;
    }
    while( true ) {
      iVar7 = *(int *)(*(int *)(DAT_000905b8 + 0x68) + uVar6 * 4);
      iVar3 = *(int *)(iVar7 + 8);
      if ((iVar3 != iVar2) &&
         (uStack88._1_3_ = uVar1, iVar7 = FUN_00002958(iVar3,(int *)(iVar7 + 0xc),0xc51d,uVar6),
         iVar2 = iVar3, uStack88._1_3_ = uVar1, iVar7 != 0)) break;
      uVar6 = uVar6 + 1;
      if (*(uint *)(DAT_000905b8 + 100) <= uVar6) {
        return;
      }
    }
  }
LAB_0000c648:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int FUN_0000c668(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint auStack24 [2];
  int local_10;
  
  if (((DAT_00090180 == 0) &&
      (iVar1 = FUN_000034b4((uint *)"/dev/icb/rpm",(undefined4 *)&DAT_00090184,param_3,param_4),
      iVar1 == 0)) &&
     (iVar1 = FUN_000034e4((int *)&DAT_00090184,(uint *)"system",0,auStack24), iVar1 == 0)) {
    DAT_00090180 = local_10;
  }
  return DAT_00090180;
}



void FUN_0000c6a4(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 in_r2;
  uint in_r3;
  uint uVar4;
  uint auStack24 [2];
  uint *puStack16;
  
  if (((DAT_00090180 == (uint *)0x0) &&
      (iVar2 = FUN_000034b4((uint *)"/dev/icb/rpm",(undefined4 *)&DAT_00090184,in_r2,in_r3),
      iVar2 == 0)) &&
     (iVar2 = FUN_000034e4((int *)&DAT_00090184,(uint *)"system",0,auStack24), iVar2 == 0)) {
    DAT_00090180 = puStack16;
  }
  if (DAT_00090180 != (uint *)0x0) {
    uVar4 = 0;
    if (*DAT_00090180 != 0) {
      do {
        iVar2 = *(int *)(DAT_00090180[1] + uVar4 * 4);
        cVar1 = *(char *)(iVar2 + 8);
        if (cVar1 == '\0') {
          puVar3 = *(undefined4 **)(iVar2 + 0x10);
          *puVar3 = *(undefined4 *)(iVar2 + 4);
          FUN_000039a8(puVar3);
        }
        else {
          if (cVar1 == '\x01') {
            puVar3 = *(undefined4 **)(iVar2 + 0x10);
            *puVar3 = *(undefined4 *)(iVar2 + 4);
            FUN_000052e0((int)puVar3);
          }
          else {
            if (cVar1 != '\x02') goto LAB_0000c72c;
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *DAT_00090180);
    }
    uVar4 = 0;
    if (DAT_00090180[0x11] != 0) {
      do {
        iVar2 = *(int *)(DAT_00090180[0x12] + uVar4 * 4);
        cVar1 = *(char *)(iVar2 + 8);
        if (cVar1 == '\0') {
          puVar3 = *(undefined4 **)(iVar2 + 0x10);
          *puVar3 = *(undefined4 *)(iVar2 + 4);
          FUN_000039a8(puVar3);
        }
        else {
          if (cVar1 == '\x01') {
            puVar3 = *(undefined4 **)(iVar2 + 0x10);
            *puVar3 = *(undefined4 *)(iVar2 + 4);
            FUN_000052e0((int)puVar3);
          }
          else {
            if (cVar1 != '\x02') goto LAB_0000c72c;
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < DAT_00090180[0x11]);
    }
    FUN_0000f110(DAT_00090180[2],DAT_00090180[3],&LAB_0000c774_1,0);
    return;
  }
LAB_0000c72c:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000c800(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 **ppuVar9;
  undefined4 auStack48 [2];
  undefined4 *local_28;
  undefined auStack36 [4];
  
  ppuVar9 = &local_28;
  uVar1 = 0;
  if (*(uint *)(DAT_000905b4 + 0x58) == 0) {
    return;
  }
  while (**(int **)(*(int *)(DAT_000905b4 + 0x60) + uVar1 * 4) != *(int *)(param_1 + 4)) {
    uVar1 = uVar1 + 1;
    if (*(uint *)(DAT_000905b4 + 0x58) <= uVar1) {
      return;
    }
  }
  iVar7 = *(int *)(*(int *)(DAT_000905b4 + 0x60) + uVar1 * 4);
  if (iVar7 != 0) {
    puVar8 = *(undefined4 **)(param_1 + 0x18);
    if (*(int *)(param_1 + 0x14) == 0) {
      ppuVar9 = (undefined4 **)auStack48;
      auStack48[0] = 0;
    }
    puVar5 = (undefined4 *)0x0;
    uVar1 = 0;
    iVar2 = FUN_00016b8c(*(undefined4 *)(param_1 + 0x28),*(undefined *)ppuVar9);
    if (iVar2 != 0) {
      do {
        FUN_00016b82(*(undefined4 *)(param_1 + 0x28),uVar1,auStack36,&local_28,*(undefined *)ppuVar9
                    );
        puVar3 = local_28;
        if (local_28 != (undefined4 *)0x0) {
          puVar3 = (undefined4 *)*local_28;
        }
        if ((puVar5 == (undefined4 *)0x0) ||
           ((puVar3 == (undefined4 *)0x0 || puVar3 <= puVar5) &&
            (puVar3 != (undefined4 *)0x0 && puVar5 != puVar3))) {
          puVar5 = puVar3;
        }
        uVar1 = uVar1 + 1;
        uVar4 = FUN_00016b8c(*(undefined4 *)(param_1 + 0x28),*(undefined *)ppuVar9);
      } while (uVar1 < uVar4);
    }
    *(undefined4 **)puVar8 = puVar5;
    *(undefined4 *)((undefined *)ppuVar9 + -8) = 0;
    FUN_000065ec(0x49,*(undefined4 *)(param_1 + 4),puVar5,0,
                 *(undefined4 *)((undefined *)ppuVar9 + -8));
    uVar6 = *puVar8;
    FUN_00016b6c(0x766c7362,*(undefined4 *)(iVar7 + 4),&local_28,*(undefined *)ppuVar9);
    if (local_28 == (undefined4 *)0x0) {
      FUN_0000d98c(iVar7,uVar6,0,0,*(undefined *)ppuVar9);
      return;
    }
    FUN_0000d98c(iVar7,uVar6,*local_28,local_28[1],*(undefined *)ppuVar9);
    return;
  }
  return;
}



void FUN_0000c8fc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  DAT_000905b4 = FUN_0000c668(param_1,param_2,param_3,param_4);
  if (DAT_000905b4 == 0) {
LAB_0000c960:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  bVar4 = *(int *)(DAT_000905b4 + 0x58) != 0;
  if (!bVar4) {
    return;
  }
  uVar2 = 0;
  if (bVar4) {
    do {
      iVar3 = *(int *)(*(int *)(DAT_000905b4 + 0x60) + uVar2 * 4);
      piVar1 = FUN_0000e418(*(uint **)(iVar3 + 0xc),(uint *)"ICB Latency Driver",0x40,0,0);
      *(int **)(iVar3 + 0x10) = piVar1;
      if (piVar1 == (int *)0x0) goto LAB_0000c960;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(DAT_000905b4 + 0x58));
  }
  FUN_0001702c(0x74616c62,*(uint *)(DAT_000905b4 + 0x58),*(int *)(DAT_000905b4 + 0x5c),4,
               (uint)(FUN_0000c988 + 1),(uint)(FUN_0000c800 + 1),0);
  return;
}



void FUN_0000c988(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iStack36;
  int iStack32;
  undefined4 *apuStack28 [2];
  
  uVar1 = 0;
  if (*(uint *)(DAT_000905b4 + 0x58) == 0) {
    return;
  }
  while (**(int **)(*(int *)(DAT_000905b4 + 0x60) + uVar1 * 4) != *(int *)(param_1 + 4)) {
    uVar1 = uVar1 + 1;
    if (*(uint *)(DAT_000905b4 + 0x58) <= uVar1) {
      return;
    }
  }
  if (*(int *)(*(int *)(DAT_000905b4 + 0x60) + uVar1 * 4) == 0) {
    return;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x10);
  uVar1 = FUN_0000d61a(*(int **)(param_1 + 0x14));
  if (uVar1 != 0) {
    return;
  }
  do {
    iVar2 = FUN_0000d658(*(int **)(param_1 + 0x14),&iStack36,&iStack32,apuStack28);
    if (iVar2 != 0) {
      if (iStack32 == 4) {
        uVar3 = *apuStack28[0];
      }
      else {
        if (iStack32 != 0) goto LAB_0000ca12;
        uVar3 = 0;
      }
      if (iStack36 == 0x736e746c) {
        *puVar4 = uVar3;
        FUN_000065ec(0x48,*(undefined4 *)(param_1 + 4),uVar3,0,0);
      }
    }
LAB_0000ca12:
    uVar1 = FUN_0000d61a(*(int **)(param_1 + 0x14));
    if (uVar1 != 0) {
      return;
    }
  } while( true );
}



void FUN_0000ca28(int param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int *piVar2;
  uint *local_28;
  
  uVar1 = 0;
  local_28 = param_4;
  if (*(int *)(DAT_000905b4 + 0x58) != 0) {
    do {
      piVar2 = *(int **)(*(int *)(DAT_000905b4 + 0x60) + uVar1 * 4);
      if (piVar2[1] == param_1) {
        FUN_00016b6c(0x74616c62,*piVar2,&local_28);
        if (local_28 == (uint *)0x0) {
          FUN_0000d98c((int)piVar2,0,param_3,(int)param_4);
        }
        else {
          FUN_0000d98c((int)piVar2,*local_28,param_3,(int)param_4);
        }
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(DAT_000905b4 + 0x58));
    return;
  }
  return;
}



void FUN_0000cab2(int param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint extraout_r1;
  uint uVar3;
  uint extraout_r1_00;
  uint extraout_r1_01;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  int iVar13;
  uint in_r12;
  uint *puVar14;
  undefined *puVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  uint auStack128 [2];
  undefined auStack120 [8];
  uint uStack112;
  undefined4 uStack108;
  undefined4 local_68 [2];
  uint local_60;
  uint uStack92;
  uint *local_58;
  uint local_50;
  uint uStack76;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  
  puVar14 = local_68;
  while (**(int **)(param_4 + param_2 * 4) != param_3) {
    param_2 = param_2 + 1;
    if (in_r12 <= param_2) {
      return;
    }
  }
  iVar8 = *(int *)(param_4 + param_2 * 4);
  if (iVar8 == 0) {
    return;
  }
  local_58 = *(uint **)(param_1 + 0x18);
  puVar4 = *(uint **)(param_1 + 0x10);
  if (puVar4 == (uint *)0x0) {
    puVar14 = &uStack112;
    puVar4 = &uStack112;
    uStack112 = 0;
    uStack108 = 0;
  }
  puVar2 = *(uint **)(param_1 + 0x14);
  puVar15 = (undefined *)puVar14;
  if (puVar2 == (uint *)0x0) {
    puVar15 = (undefined *)puVar14 + -8;
    puVar2 = (uint *)((undefined *)puVar14 + -8);
    *(undefined4 *)((undefined *)puVar14 + -8) = 0;
    *(undefined4 *)((undefined *)puVar14 + -4) = 0;
  }
  uVar5 = *local_58 - *puVar4;
  uVar7 = uVar5 + *puVar2;
  uVar10 = (local_58[1] - (puVar4[1] + (uint)(*local_58 < *puVar4))) +
           puVar2[1] + (uint)CARRY4(uVar5,*puVar2);
  *(undefined4 *)(puVar15 + -8) = 0;
  FUN_000065ec(0x44,*(undefined4 *)(param_1 + 4),uVar10,uVar7,*(undefined4 *)(puVar15 + -8));
  uVar5 = *local_58;
  uStack92 = local_58[1];
  local_60 = uVar5;
  if ((uVar7 | uVar10) != 0) {
    *(uint *)(puVar15 + -8) = uVar7;
    *(uint *)(puVar15 + -4) = uVar10;
    FUN_0001a95c(iVar8,uVar5,uVar5,uStack92,*(uint *)(puVar15 + -8),*(uint *)(puVar15 + -4));
    uVar5 = extraout_r1;
  }
  if ((*(int *)(iVar8 + 0x10) != 0) && (uVar5 = uStack92 ^ uVar10, (local_60 ^ uVar7 | uVar5) != 0))
  {
    uVar5 = *(uint *)(iVar8 + 4);
    uVar9 = *(uint *)(iVar8 + 8);
    if (*(char *)(uVar5 + 8) == '\0') {
      iVar13 = *(int *)(iVar8 + 0x18);
      if (*(int *)(iVar13 + 4) == 3 || *(int *)(iVar13 + 4) == 1) {
        local_68[0] = *(undefined4 *)(uVar5 + 0x10);
        uVar6 = 0;
        uVar17 = FUN_000001b0(uVar7 + uVar9 + -1,
                              uVar10 + CARRY4(uVar7,uVar9) + ((uint)(uVar7 + uVar9 != 0) - 1),uVar9,
                              0,*puVar15);
        uVar11 = (uint)((ulonglong)uVar17 >> 0x20);
        uVar3 = (uint)uVar17;
        local_50 = uVar11;
        uStack76 = uVar3;
        local_48 = *(undefined4 *)(iVar8 + 0x14);
        uVar1 = *(uint *)(iVar13 + 0x50);
        uVar5 = uVar3;
        if (uVar1 == 0) {
          uVar5 = 0;
        }
        uVar17 = CONCAT44(uVar1,uVar5);
        if (uVar1 != 0) {
          uVar5 = (uint)((ulonglong)uVar1 * (ulonglong)uVar11);
          uVar6 = 0;
          uVar17 = FUN_000001b0(uVar5 + 99,
                                uVar1 * uVar3 + (int)((ulonglong)uVar1 * (ulonglong)uVar11 >> 0x20)
                                + (uint)(0xffffff9c < uVar5),100,0,*puVar15);
        }
        uVar12 = (undefined4)uVar17;
        local_40 = (int)((ulonglong)uVar17 >> 0x20);
        uStack60 = uVar12;
        uVar5 = *(uint *)(iVar13 + 0x54);
        if (uVar5 == 0) {
          uVar12 = 0;
        }
        uVar17 = CONCAT44(uVar5,uVar12);
        if (uVar5 != 0) {
          uVar1 = (uint)((ulonglong)uVar5 * (ulonglong)uVar11);
          uVar6 = 0;
          uVar17 = FUN_000001b0(uVar1 + 99,
                                uVar5 * uVar3 + (int)((ulonglong)uVar5 * (ulonglong)uVar11 >> 0x20)
                                + (uint)(0xffffff9c < uVar1),100,0,*puVar15);
        }
        uVar5 = (uint)uVar17;
        local_38 = (int)((ulonglong)uVar17 >> 0x20);
        uStack52 = uVar5;
        uVar1 = *(uint *)(iVar13 + 0x58);
        if (uVar1 == 0) {
          uVar5 = 0;
        }
        uVar16 = (ulonglong)uVar5;
        if (uVar1 != 0) {
          uVar5 = (uint)((ulonglong)uVar1 * (ulonglong)uVar11);
          uVar6 = 0;
          uVar16 = FUN_000001b0(uVar5 + 99,
                                uVar1 * uVar3 + (int)((ulonglong)uVar1 * (ulonglong)uVar11 >> 0x20)
                                + (uint)(0xffffff9c < uVar5),100,0,*puVar15);
        }
        uVar5 = (uint)uVar16;
        uVar11 = 0;
        local_30 = (int)(uVar16 >> 0x20);
        uStack44 = uVar5;
        if (uVar9 != 0) {
          do {
            FUN_00003a06(local_68[0],*(undefined4 *)(*(int *)(iVar8 + 0x10) + uVar11 * 4),&local_50,
                         uVar6,*puVar15);
            uVar11 = uVar11 + 1;
            uVar5 = extraout_r1_00;
          } while (uVar11 < uVar9);
        }
      }
    }
    else {
      if ((*(char *)(uVar5 + 8) == '\x01') &&
         (**(char **)(iVar8 + 0x18) == '\x03' || **(char **)(iVar8 + 0x18) == '\x01')) {
        uVar12 = *(undefined4 *)(uVar5 + 0x10);
        uVar6 = 0;
        uVar17 = FUN_000001b0(uVar7 + uVar9 + -1,
                              uVar10 + CARRY4(uVar7,uVar9) + ((uint)(uVar7 + uVar9 != 0) - 1),uVar9,
                              0,*puVar15);
        uVar5 = (uint)uVar17;
        local_50 = (uint)((ulonglong)uVar17 >> 0x20);
        uStack76 = uVar5;
        uVar11 = 0;
        local_48 = *(undefined4 *)(iVar8 + 0x14);
        if (uVar9 != 0) {
          do {
            FUN_000052ea(uVar12,*(undefined4 *)(*(int *)(iVar8 + 0x10) + uVar11 * 4),&local_50,uVar6
                         ,*puVar15);
            uVar11 = uVar11 + 1;
            uVar5 = extraout_r1_01;
          } while (uVar11 < uVar9);
        }
      }
    }
  }
  if ((uVar7 | uVar10) == 0) {
    *(uint *)(puVar15 + -8) = uVar7;
    *(uint *)(puVar15 + -4) = uVar10;
    FUN_0001a95c(iVar8,uVar5,local_60,uStack92,*(uint *)(puVar15 + -8),*(uint *)(puVar15 + -4));
  }
  *local_58 = uVar7;
  local_58[1] = uVar10;
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0000cce4(undefined4 param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *unaff_r5;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined4 uStack64;
  undefined4 uStack60;
  undefined4 uStack56;
  undefined4 uStack52;
  undefined4 uStack48;
  undefined4 uStack44;
  
  DAT_000905a8 = FUN_0000c668(param_1,param_2,param_3,(uint)param_4);
  uVar15 = CONCAT44(uStack48,uStack44);
  uVar14 = CONCAT44(uStack56,uStack52);
  uVar13 = CONCAT44(uStack64,uStack60);
  if (DAT_000905a8 != 0) {
    bVar12 = *(int *)(DAT_000905a8 + 0x20) != 0;
    if (!bVar12) {
      return;
    }
    uVar11 = 0;
    if (bVar12) {
      do {
        iVar8 = *(int *)(*(int *)(DAT_000905a8 + 0x28) + uVar11 * 4);
        bVar12 = *(int *)(iVar8 + 0x10) != 0;
        if (bVar12) {
          unaff_r5 = *(byte **)(iVar8 + 0x18);
        }
        if (bVar12 && unaff_r5 != (byte *)0x0) {
          iVar2 = *(int *)(iVar8 + 4);
          cVar1 = *(char *)(iVar2 + 8);
          if (cVar1 == '\0') {
            piVar10 = *(int **)(iVar2 + 0x10);
            uVar9 = 0;
            if (*(int *)(iVar8 + 8) != 0) {
              do {
                if (*(int *)(unaff_r5 + 4) != 2) {
                  param_4 = unaff_r5 + 8;
                  FUN_00003a2c(piVar10,*(undefined4 *)(*(int *)(iVar8 + 0x10) + uVar9 * 4));
                  uStack48 = (undefined4)((ulonglong)uVar15 >> 0x20);
                  uStack44 = (undefined4)uVar15;
                  uStack56 = (undefined4)((ulonglong)uVar14 >> 0x20);
                  uStack52 = (undefined4)uVar14;
                  uStack64 = (undefined4)((ulonglong)uVar13 >> 0x20);
                  uStack60 = (undefined4)uVar13;
                  if (*(int *)(unaff_r5 + 4) != 0) {
                    uVar6 = *(uint *)(iVar8 + 8);
                    param_4 = (byte *)0x0;
                    uVar16 = uVar13;
                    uVar13 = FUN_000001b0(*(uint *)(unaff_r5 + 0x48) + (uVar6 - 1),
                                          *(int *)(unaff_r5 + 0x4c) + ((uint)(uVar6 != 0) - 1) +
                                          (uint)CARRY4(*(uint *)(unaff_r5 + 0x48),uVar6 - 1),uVar6,0
                                         );
                    uStack48 = (undefined4)((ulonglong)uVar15 >> 0x20);
                    uStack44 = (undefined4)uVar15;
                    uStack56 = (undefined4)((ulonglong)uVar14 >> 0x20);
                    uStack52 = (undefined4)uVar14;
                    uStack64 = (undefined4)((ulonglong)uVar16 >> 0x20);
                    uStack60 = (undefined4)uVar16;
                    uVar6 = (uint)((ulonglong)uVar13 >> 0x20);
                    iVar4 = (int)uVar13;
                    uVar3 = *(uint *)(unaff_r5 + 0x50);
                    iVar2 = iVar4;
                    if (uVar3 == 0) {
                      iVar2 = 0;
                    }
                    uVar13 = CONCAT44(uVar3,iVar2);
                    uVar17 = uVar14;
                    if (uVar3 != 0) {
                      uVar7 = (uint)((ulonglong)uVar3 * (ulonglong)uVar6);
                      param_4 = (byte *)0x0;
                      uVar13 = FUN_000001b0(uVar7 + 99,
                                            uVar3 * iVar4 +
                                            (int)((ulonglong)uVar3 * (ulonglong)uVar6 >> 0x20) +
                                            (uint)(0xffffff9c < uVar7),100,0);
                      uStack48 = (undefined4)((ulonglong)uVar15 >> 0x20);
                      uStack44 = (undefined4)uVar15;
                      uStack56 = (undefined4)((ulonglong)uVar17 >> 0x20);
                      uStack52 = (undefined4)uVar17;
                      uStack64 = (undefined4)((ulonglong)uVar16 >> 0x20);
                      uStack60 = (undefined4)uVar16;
                    }
                    uVar5 = (undefined4)uVar13;
                    uVar3 = *(uint *)(unaff_r5 + 0x54);
                    if (uVar3 == 0) {
                      uVar5 = 0;
                    }
                    uVar14 = CONCAT44(uVar3,uVar5);
                    uVar16 = uVar15;
                    if (uVar3 != 0) {
                      uVar7 = (uint)((ulonglong)uVar3 * (ulonglong)uVar6);
                      param_4 = (byte *)0x0;
                      uVar14 = FUN_000001b0(uVar7 + 99,
                                            uVar3 * iVar4 +
                                            (int)((ulonglong)uVar3 * (ulonglong)uVar6 >> 0x20) +
                                            (uint)(0xffffff9c < uVar7),100,0);
                      uStack48 = (undefined4)((ulonglong)uVar16 >> 0x20);
                      uStack44 = (undefined4)uVar16;
                      uStack56 = (undefined4)((ulonglong)uVar17 >> 0x20);
                      uStack52 = (undefined4)uVar17;
                      uStack64 = (undefined4)((ulonglong)uVar13 >> 0x20);
                      uStack60 = (undefined4)uVar13;
                    }
                    uVar5 = (undefined4)uVar14;
                    uVar3 = *(uint *)(unaff_r5 + 0x58);
                    if (uVar3 == 0) {
                      uVar5 = 0;
                    }
                    uVar15 = CONCAT44(uVar3,uVar5);
                    if (uVar3 != 0) {
                      uVar7 = (uint)((ulonglong)uVar3 * (ulonglong)uVar6);
                      param_4 = (byte *)0x0;
                      uVar15 = FUN_000001b0(uVar7 + 99,
                                            uVar3 * iVar4 +
                                            (int)((ulonglong)uVar3 * (ulonglong)uVar6 >> 0x20) +
                                            (uint)(0xffffff9c < uVar7),100,0);
                      uStack48 = (undefined4)((ulonglong)uVar16 >> 0x20);
                      uStack44 = (undefined4)uVar16;
                      uStack64 = (undefined4)((ulonglong)uVar13 >> 0x20);
                      uStack60 = (undefined4)uVar13;
                      uStack56 = (undefined4)((ulonglong)uVar14 >> 0x20);
                      uStack52 = (undefined4)uVar14;
                    }
                    FUN_00003a06(piVar10,*(uint *)(*(int *)(iVar8 + 0x10) + uVar9 * 4),
                                 (uint *)&stack0xffffffb0,(uint)param_4);
                    uStack56 = (undefined4)((ulonglong)uVar14 >> 0x20);
                    uStack52 = (undefined4)uVar14;
                    uStack64 = (undefined4)((ulonglong)uVar13 >> 0x20);
                    uStack60 = (undefined4)uVar13;
                    uStack48 = (undefined4)((ulonglong)uVar15 >> 0x20);
                    uStack44 = (undefined4)uVar15;
                  }
                }
                FUN_00003a1c(piVar10,*(uint *)(*(int *)(iVar8 + 0x10) + uVar9 * 4),
                             *(uint *)(unaff_r5 + 4),(uint)param_4);
                uStack48 = (undefined4)((ulonglong)uVar15 >> 0x20);
                uStack44 = (undefined4)uVar15;
                uStack56 = (undefined4)((ulonglong)uVar14 >> 0x20);
                uStack52 = (undefined4)uVar14;
                uStack64 = (undefined4)((ulonglong)uVar13 >> 0x20);
                uStack60 = (undefined4)uVar13;
                uVar9 = uVar9 + 1;
              } while (uVar9 < *(uint *)(iVar8 + 8));
            }
          }
          else {
            if (cVar1 == '\x01') {
              piVar10 = *(int **)(iVar2 + 0x10);
              uVar9 = 0;
              if (*(int *)(iVar8 + 8) != 0) {
                do {
                  if (*unaff_r5 != 2) {
                    param_4 = unaff_r5 + 4;
                    FUN_00005310(piVar10,*(undefined4 *)(*(int *)(iVar8 + 0x10) + uVar9 * 4));
                    uStack48 = (undefined4)((ulonglong)uVar15 >> 0x20);
                    uStack44 = (undefined4)uVar15;
                    uStack56 = (undefined4)((ulonglong)uVar14 >> 0x20);
                    uStack52 = (undefined4)uVar14;
                    uStack64 = (undefined4)((ulonglong)uVar13 >> 0x20);
                    uStack60 = (undefined4)uVar13;
                    if (*unaff_r5 != 0) {
                      FUN_000052ea(piVar10,*(uint *)(*(int *)(iVar8 + 0x10) + uVar9 * 4),
                                   (uint *)(unaff_r5 + 0x10),(uint)param_4);
                      uStack48 = (undefined4)((ulonglong)uVar15 >> 0x20);
                      uStack44 = (undefined4)uVar15;
                      uStack56 = (undefined4)((ulonglong)uVar14 >> 0x20);
                      uStack52 = (undefined4)uVar14;
                      uStack64 = (undefined4)((ulonglong)uVar13 >> 0x20);
                      uStack60 = (undefined4)uVar13;
                    }
                  }
                  FUN_00005300(piVar10,*(uint *)(*(int *)(iVar8 + 0x10) + uVar9 * 4),(uint)*unaff_r5
                               ,(uint)param_4);
                  uStack48 = (undefined4)((ulonglong)uVar15 >> 0x20);
                  uStack44 = (undefined4)uVar15;
                  uStack56 = (undefined4)((ulonglong)uVar14 >> 0x20);
                  uStack52 = (undefined4)uVar14;
                  uStack64 = (undefined4)((ulonglong)uVar13 >> 0x20);
                  uStack60 = (undefined4)uVar13;
                  uVar9 = uVar9 + 1;
                } while (uVar9 < *(uint *)(iVar8 + 8));
              }
            }
            else {
              if (cVar1 != '\x02') goto LAB_0000cd30;
            }
          }
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)(DAT_000905a8 + 0x20));
    }
    FUN_0001702c(0x73616d62,*(uint *)(DAT_000905a8 + 0x20),*(int *)(DAT_000905a8 + 0x24),8,
                 (uint)(FUN_0000cec0 + 1),(uint)&LAB_0000ca9c_1,0);
    uStack48 = (undefined4)((ulonglong)uVar15 >> 0x20);
    uStack44 = (undefined4)uVar15;
    uStack56 = (undefined4)((ulonglong)uVar14 >> 0x20);
    uStack52 = (undefined4)uVar14;
    uStack64 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uStack60 = (undefined4)uVar13;
    return;
  }
LAB_0000cd30:
                    // WARNING: Subroutine does not return
  FUN_00000060();
  uStack48 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uStack44 = (undefined4)uVar15;
  uStack56 = (undefined4)((ulonglong)uVar14 >> 0x20);
  uStack52 = (undefined4)uVar14;
  uStack64 = (undefined4)((ulonglong)uVar13 >> 0x20);
  uStack60 = (undefined4)uVar13;
}



void FUN_0000cec0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iStack28;
  int iStack24;
  undefined4 *puStack20;
  
  uVar1 = 0;
  if (*(uint *)(DAT_000905a8 + 0x20) == 0) {
    return;
  }
  while (**(int **)(*(int *)(DAT_000905a8 + 0x28) + uVar1 * 4) != *(int *)(param_1 + 4)) {
    uVar1 = uVar1 + 1;
    if (*(uint *)(DAT_000905a8 + 0x20) <= uVar1) {
      return;
    }
  }
  if (*(int *)(*(int *)(DAT_000905a8 + 0x28) + uVar1 * 4) == 0) {
    return;
  }
  puVar5 = *(undefined4 **)(param_1 + 0x10);
  uVar1 = FUN_0000d61a(*(int **)(param_1 + 0x14));
  if (uVar1 != 0) {
    return;
  }
  do {
    iVar2 = FUN_0000d658(*(int **)(param_1 + 0x14),&iStack28,&iStack24,&puStack20);
    if (iVar2 != 0) {
      if (iStack24 == 8) {
        uVar3 = puStack20[1];
        uVar4 = *puStack20;
      }
      else {
        if (iStack24 != 0) goto LAB_0000cf52;
        uVar3 = 0;
        uVar4 = uVar3;
      }
      if (iStack28 == 0x7762) {
        *puVar5 = uVar4;
        puVar5[1] = uVar3;
        FUN_000065ec(0x43,*(undefined4 *)(param_1 + 4),uVar3,uVar4,0);
      }
    }
LAB_0000cf52:
    uVar1 = FUN_0000d61a(*(int **)(param_1 + 0x14));
    if (uVar1 != 0) {
      return;
    }
  } while( true );
}



void FUN_0000cf64(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint extraout_r1;
  uint extraout_r1_00;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  undefined4 *puVar14;
  undefined8 uVar15;
  undefined4 local_40 [2];
  undefined local_38 [8];
  uint local_30;
  undefined4 local_2c;
  undefined4 uStack40;
  
  puVar13 = &uStack40;
  uStack40 = param_4;
  uVar2 = 0;
  if (*(uint *)(DAT_000905a4 + 0x14) == 0) {
    return;
  }
  while (**(int **)(*(int *)(DAT_000905a4 + 0x1c) + uVar2 * 4) != *(int *)(param_1 + 4)) {
    uVar2 = uVar2 + 1;
    if (*(uint *)(DAT_000905a4 + 0x14) <= uVar2) {
      return;
    }
  }
  puVar9 = *(undefined4 **)(*(int *)(DAT_000905a4 + 0x1c) + uVar2 * 4);
  if (puVar9 == (undefined4 *)0x0) {
    return;
  }
  puVar11 = *(uint **)(param_1 + 0x18);
  puVar5 = *(uint **)(param_1 + 0x10);
  if (puVar5 == (uint *)0x0) {
    puVar13 = &local_30;
    puVar5 = &local_30;
    local_30 = 0;
    local_2c = 0;
  }
  puVar3 = *(uint **)(param_1 + 0x14);
  puVar14 = puVar13;
  if (puVar3 == (uint *)0x0) {
    puVar14 = puVar13 + -2;
    puVar3 = puVar13 + -2;
    puVar13[-2] = 0;
    puVar13[-1] = 0;
  }
  uVar2 = *puVar11 - *puVar5;
  uVar10 = uVar2 + *puVar3;
  uVar6 = (puVar11[1] - (puVar5[1] + (uint)(*puVar11 < *puVar5))) + puVar3[1] +
          (uint)CARRY4(uVar2,*puVar3);
  *(undefined4 *)((undefined *)puVar14 + -8) = 0;
  FUN_000065ec(0x42,*(undefined4 *)(param_1 + 4),uVar6,uVar10,
               *(undefined4 *)((undefined *)puVar14 + -8));
  uVar15 = CONCAT44(uVar10,uVar6);
  uVar2 = uVar6;
  if ((*puVar11 ^ uVar10 | puVar11[1] ^ uVar6) != 0) {
    if (*(char *)(puVar9[1] + 0x14) == '\x01') {
      uVar2 = *(uint *)(puVar9[1] + 0x18);
      lVar1 = (ulonglong)uVar2 * (ulonglong)uVar10;
      uVar12 = (uint)lVar1;
      uVar15 = FUN_000001b0(uVar12 + 99,
                            uVar2 * uVar6 + (int)((ulonglong)lVar1 >> 0x20) +
                            (uint)(0xffffff9c < uVar12),100,0,*(undefined *)puVar14);
    }
    uVar2 = (uint)((ulonglong)uVar15 >> 0x20);
    iVar8 = puVar9[6];
    iVar7 = iVar8;
    if (iVar8 == 0) {
      iVar7 = 1;
    }
    if (iVar8 == 0) {
      iVar8 = 1;
    }
    uVar12 = puVar9[7] * iVar8 * 1000;
    iVar8 = uVar12 + uVar2;
    uVar15 = FUN_000001b0(iVar8 + -1,
                          (int)uVar15 + (uint)CARRY4(uVar12,uVar2) + ((uint)(iVar8 != 0) - 1),
                          puVar9[7] * iVar7 * 1000,0,*(undefined *)puVar14);
    uVar4 = (undefined4)((ulonglong)uVar15 >> 0x20);
    FUN_0000c4dc(puVar9[8],uVar4,*(undefined *)puVar14);
    uVar12 = 0;
    uVar2 = extraout_r1;
    if (puVar9[9] != 0) {
      do {
        FUN_0000c4dc(puVar9[10] + uVar12 * 8,uVar4,*(undefined *)puVar14);
        uVar12 = uVar12 + 1;
        uVar2 = extraout_r1_00;
      } while (uVar12 < (uint)puVar9[9]);
    }
  }
  *puVar11 = uVar10;
  puVar11[1] = uVar6;
  if (*(char *)(puVar9 + 5) == '\0') {
    return;
  }
  FUN_0000ca28(*puVar9,uVar2,uVar10,uVar6,*(undefined *)puVar14);
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0000d0b4(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  bool bVar6;
  
  DAT_000905a4 = FUN_0000c668(param_1,param_2,param_3,param_4);
  if (DAT_000905a4 == 0) {
LAB_0000d0ee:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  bVar6 = *(int *)(DAT_000905a4 + 0x14) != 0;
  if (!bVar6) {
    return;
  }
  uVar4 = 0;
  if (bVar6) {
    do {
      iVar2 = *(int *)(*(int *)(DAT_000905a4 + 0x1c) + uVar4 * 4);
      if (*(int *)(iVar2 + 0x10) != 0) {
        cVar1 = *(char *)(*(int *)(iVar2 + 4) + 8);
        if (cVar1 == '\0') {
          piVar5 = *(int **)(*(int *)(iVar2 + 4) + 0x10);
          uVar3 = 0;
          if (*(int *)(iVar2 + 8) != 0) {
            do {
              FUN_00003998(piVar5,*(uint *)(*(int *)(iVar2 + 0xc) + uVar3 * 4),
                           (uint)*(byte *)(iVar2 + 0x13),param_4);
              uVar3 = uVar3 + 1;
            } while (uVar3 < *(uint *)(iVar2 + 8));
          }
        }
        else {
          if (cVar1 != '\x01' && cVar1 != '\x02') goto LAB_0000d0ee;
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(DAT_000905a4 + 0x14));
  }
  FUN_0001702c(0x766c7362,*(uint *)(DAT_000905a4 + 0x14),*(int *)(DAT_000905a4 + 0x18),8,
               (uint)(FUN_0000d154 + 1),(uint)(FUN_0000cf64 + 1),0);
  return;
}



void FUN_0000d154(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iStack28;
  int iStack24;
  undefined4 *apuStack20 [2];
  
  uVar3 = 0;
  if (*(uint *)(DAT_000905a4 + 0x14) == 0) {
    return;
  }
  while (**(int **)(*(int *)(DAT_000905a4 + 0x1c) + uVar3 * 4) != *(int *)(param_1 + 4)) {
    uVar3 = uVar3 + 1;
    if (*(uint *)(DAT_000905a4 + 0x14) <= uVar3) {
      return;
    }
  }
  if (*(int *)(*(int *)(DAT_000905a4 + 0x1c) + uVar3 * 4) == 0) {
    return;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x10);
  iVar1 = FUN_0000d658(*(int **)(param_1 + 0x14),&iStack28,&iStack24,apuStack20);
  if (iVar1 == 0) {
    return;
  }
  if (iStack28 == 0x7762) {
    if (iStack24 == 8) {
      uVar2 = apuStack20[0][1];
      *puVar4 = *apuStack20[0];
      puVar4[1] = uVar2;
      FUN_000065ec(0x41,*(undefined4 *)(param_1 + 4),puVar4[1],*puVar4,0);
      return;
    }
    if (iStack24 == 0) {
      *puVar4 = 0;
      puVar4[1] = 0;
      FUN_000065ec(0x41,*(undefined4 *)(param_1 + 4),puVar4[1],*puVar4,0);
      return;
    }
    return;
  }
  return;
}



void FUN_0000d200(int param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  bool bVar10;
  int local_38 [2];
  undefined auStack48 [4];
  int *local_2c;
  
  piVar9 = (int *)auStack48;
  local_2c = *(int **)(param_1 + 0x18);
  piVar2 = *(int **)(param_1 + 0x10);
  if (piVar2 == (int *)0x0) {
    piVar9 = local_38;
    piVar2 = local_38;
    local_38[0] = 0;
  }
  iVar6 = (**(int **)(param_1 + 0x18) - *piVar2) + **(int **)(param_1 + 0x14);
  *(undefined4 *)((undefined *)piVar9 + -8) = 0;
  FUN_000065ec(0x46,iVar6,0,0,*(undefined4 *)((undefined *)piVar9 + -8));
  uVar5 = *(uint *)(param_1 + 4);
  bVar10 = iVar6 != 0;
  if ((uVar5 < 2) && ((bool)*(char *)((int)&DAT_000905ac + uVar5) != bVar10)) {
    if (bVar10) {
      pcVar1 = FUN_000012a0;
    }
    else {
      pcVar1 = FUN_00000f94;
    }
    if (uVar5 == 0) {
      iVar8 = *(int *)(DAT_000905b0 + 0x40);
      uVar7 = *(uint *)(DAT_000905b0 + 0x38);
    }
    else {
      if (uVar5 != 1) goto LAB_0000d2b8;
      iVar8 = *(int *)(DAT_000905b0 + 0x34);
      uVar7 = *(uint *)(DAT_000905b0 + 0x2c);
    }
    uVar4 = 0;
    if (uVar7 != 0) {
      do {
        iVar3 = (*(pcVar1 + 1))(*(undefined4 *)(iVar8 + uVar4 * 4));
        if (iVar3 != 0) {
                    // WARNING: Subroutine does not return
          FUN_00000060();
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar7);
    }
    *(bool *)((int)&DAT_000905ac + uVar5) = bVar10;
    *(undefined4 *)((undefined *)piVar9 + -8) = 0;
    FUN_000065ec(0x47,&DAT_000905ac,0,0,*(undefined4 *)((undefined *)piVar9 + -8));
  }
LAB_0000d2b8:
  *local_2c = iVar6;
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0000d2d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  DAT_000905b0 = FUN_0000c668(param_1,param_2,param_3,param_4);
  if (DAT_000905b0 != 0) {
    DAT_000905ac = 0;
    bVar4 = *(int *)(DAT_000905b0 + 0x38) != 0;
    if (!bVar4) {
      DAT_000905ac = 0;
      return;
    }
    bVar1 = true;
    uVar3 = 0;
    if (bVar4) {
      do {
        iVar2 = FUN_000015c0(*(uint **)(*(int *)(DAT_000905b0 + 0x3c) + uVar3 * 4),
                             (int *)(*(int *)(DAT_000905b0 + 0x40) + uVar3 * 4));
        if (iVar2 != 0) {
          bVar1 = false;
          break;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(DAT_000905b0 + 0x38));
    }
    uVar3 = 0;
    if (*(int *)(DAT_000905b0 + 0x2c) != 0) {
      do {
        iVar2 = FUN_000015c0(*(uint **)(*(int *)(DAT_000905b0 + 0x30) + uVar3 * 4),
                             (int *)(*(int *)(DAT_000905b0 + 0x34) + uVar3 * 4));
        if (iVar2 != 0) goto LAB_0000d356;
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(DAT_000905b0 + 0x2c));
    }
    if (bVar1) {
      FUN_00017124(0x63707362,2,4,FUN_0000d36c + 1,FUN_0000d200 + 1,0);
      return;
    }
  }
LAB_0000d356:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000d36c(int param_1)

{
  int iVar1;
  int *piVar2;
  int iStack20;
  int iStack16;
  int *piStack12;
  
  piVar2 = *(int **)(param_1 + 0x10);
  iVar1 = FUN_0000d658(*(int **)(param_1 + 0x14),&iStack20,&iStack16,&piStack12);
  if (iVar1 == 0) {
    return;
  }
  if (iStack20 != 0x6e65) {
    return;
  }
  if (iStack16 == 4) {
    iVar1 = *piStack12;
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    *piVar2 = iVar1;
    FUN_000065ec(0x45,iVar1,0,0,0);
    return;
  }
  if (iStack16 == 0) {
    *piVar2 = 0;
    FUN_000065ec(0x45,0,0,0,0);
    return;
  }
  return;
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: stack

undefined4 FUN_0000d3d4(uint param_1)

{
  char *pcVar1;
  undefined4 uStack152;
  char acStack77 [20];
  undefined uStack57;
  char acStack56 [32];
  int iStack24;
  
  DAT_000905bc = FUN_00019bfc(0x1d5,&iStack24);
  if (DAT_000905bc == 0) {
    return 3;
  }
  if (iStack24 == 0x1000) {
    if (param_1 < 0x20) {
      _DAT_00080070 = 2;
      FUN_00000610(&uStack152,0x80);
      pcVar1 = FUN_0000030c("QC_IMAGE_VERSION_STRING=RPM.BF.2.1.1.C8-00002",'=');
      if (pcVar1 == (char *)0x0) {
        FUN_0001a0cc((char *)((int)&uStack152 + 3),"QC_IMAGE_VERSION_STRING=RPM.BF.2.1.1.C8-00002",0x48)
        ;
      }
      else {
        FUN_0001a0cc((char *)((int)&uStack152 + 3),pcVar1 + 1,0x48);
      }
      pcVar1 = FUN_0000030c("IMAGE_VARIANT_STRING=AAAAANAAR",'=');
      if (pcVar1 == (char *)0x0) {
        FUN_0001a0cc(acStack77,"IMAGE_VARIANT_STRING=AAAAANAAR",0x14);
      }
      else {
        FUN_0001a0cc(acStack77,pcVar1 + 1,0x14);
      }
      pcVar1 = FUN_0000030c("OEM_IMAGE_VERSION_STRING=CRM",'=');
      if (pcVar1 == (char *)0x0) {
        FUN_0001a0cc(acStack56,"OEM_IMAGE_VERSION_STRING=CRM",0x20);
      }
      else {
        FUN_0001a0cc(acStack56,pcVar1 + 1,0x20);
      }
      uStack152._1_1_ = (char)param_1 + (char)(param_1 / 10) * -10 + '0';
      uStack152._2_1_ = 0x3a;
      uStack57 = 0x3a;
      FUN_0000044c(DAT_000905bc + param_1 * 0x80,&uStack152,0x80);
      _DAT_00080070 = 0;
      return 0;
    }
    return 5;
  }
  return 4;
}



void FUN_0000d4f0(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 1 << (param_1 & 0x1f);
  param_1 = param_1 >> 5;
  if (param_2 == 0) {
    *(uint *)(&DAT_00080030 + param_1 * 4) = *(uint *)(&DAT_00080030 + param_1 * 4) | uVar1;
    uVar1 = *(uint *)(&DAT_00080038 + param_1 * 4) | uVar1;
  }
  else {
    if (param_2 == 1) {
      *(uint *)(&DAT_00080030 + param_1 * 4) = *(uint *)(&DAT_00080030 + param_1 * 4) & ~uVar1;
      uVar1 = *(uint *)(&DAT_00080038 + param_1 * 4) | uVar1;
    }
    else {
      if (param_2 == 2) {
        *(uint *)(&DAT_00080030 + param_1 * 4) = *(uint *)(&DAT_00080030 + param_1 * 4) | uVar1;
        uVar1 = *(uint *)(&DAT_00080038 + param_1 * 4) & ~uVar1;
      }
      else {
        if (param_2 != 3) {
          return;
        }
        *(uint *)(&DAT_00080030 + param_1 * 4) = *(uint *)(&DAT_00080030 + param_1 * 4) & ~uVar1;
        uVar1 = *(uint *)(&DAT_00080038 + param_1 * 4) & ~uVar1;
      }
    }
  }
  *(uint *)(&DAT_00080038 + param_1 * 4) = uVar1;
  return;
}



void FUN_0000d57c(int param_1,undefined *param_2)

{
  (&PTR_DAT_00090240)[param_1] = param_2;
  return;
}



void FUN_0000d58c(uint param_1)

{
  if (0x3f < param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  uRame000ef00 = param_1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000d5a0(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  iVar2 = 0;
  while( true ) {
    if ((int)(((_DAT_e000e004 & 0x1f) + 1) * 0x20) >> 5 <= iVar2) {
      return;
    }
    if (bVar1) break;
    if ((*(uint *)(&DAT_e000e100 + iVar2 * 4) & *(uint *)(&DAT_e000e200 + iVar2 * 4)) != 0) {
      bVar1 = true;
    }
    iVar2 = iVar2 + 1;
  }
  return;
}



void FUN_0000d5e6(int *param_1)

{
  FUN_0000b22e(*param_1);
  param_1[1] = 0;
  return;
}



undefined4 * FUN_0000d5f6(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)FUN_00000154(8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar2 = FUN_0000b234(param_1);
    *(undefined4 **)puVar1 = puVar2;
    return puVar1;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



uint FUN_0000d61a(int *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_0000b2ea(*param_1);
  return (uint)(uVar1 <= (uint)param_1[1]);
}



undefined4 * FUN_0000d630(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_00000154(8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    uVar2 = FUN_0000b266(param_2,param_1);
    *puVar1 = uVar2;
    return puVar1;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 FUN_0000d658(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_0000b2ea(*param_1);
  uVar3 = param_1[1];
  uVar4 = 0;
  if ((uVar1 <= uVar3) || (uVar1 - uVar3 < 8)) {
    return 0;
  }
  puVar2 = (undefined4 *)FUN_0000b220(*param_1,uVar3);
  param_1[1] = param_1[1] + 8;
  if (puVar2 == (undefined4 *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  *param_2 = *puVar2;
  *param_3 = puVar2[1];
  if (puVar2[1] == 0) {
    *param_4 = 0;
  }
  else {
    uVar1 = FUN_0000b2ea(*param_1);
    if ((uint)param_1[1] < uVar1) {
      uVar4 = uVar1 - param_1[1];
    }
    if (uVar4 < (puVar2[1] + 3 & 0xfffffffc)) {
      return 0;
    }
    *(undefined4 **)param_4 = puVar2 + 2;
    param_1[1] = param_1[1] + (puVar2[1] + 3 & 0xfffffffc);
  }
  return 1;
}



void FUN_0000d6de(int *param_1)

{
  FUN_0000b220(*param_1,0);
  return;
}



void FUN_0000d6e6(int *param_1)

{
  FUN_0000b2ea(*param_1);
  return;
}



void FUN_0000d6ec(char **param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  int local_2c;
  char **ppcStack36;
  undefined4 uStack32;
  uint local_1c;
  undefined4 uStack24;
  
  iVar1 = DAT_00090168;
  local_2c = DAT_00090168;
  local_30 = 0;
  iVar2 = ((param_3 & 3) + 3 & 0xfffffffc) - (param_3 & 3);
  ppcStack36 = param_1;
  uStack32 = param_2;
  local_1c = param_3;
  uStack24 = param_4;
  FUN_0000b288(*param_1,&uStack32,4);
  FUN_0000b288(*param_1,&local_1c,4);
  FUN_0000b288(*param_1,param_4,local_1c);
  if (iVar2 != 0) {
    FUN_0000b288(*param_1,&local_30,iVar2);
  }
                    // WARNING: Subroutine does not return
  if (local_2c != iVar1) {
    thunk_FUN_00000060();
  }
  return;
}



void FUN_0000d748(char **param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0000b2ee(*param_1,param_2,param_3);
  param_1[1] = (char *)0x0;
  return;
}



void FUN_0000d758(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar2 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x10);
  }
  if ((DAT_000900c4 != 0) && (iVar2 == 0)) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  DAT_000900c4 = DAT_000900c4 + 1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_0000d778(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  switch(param_1) {
  case 0:
    if (((_DAT_61106000 & 0x7f) != param_2) && ((_DAT_61106004 & 0x7f) != param_2)) {
      return uVar1;
    }
    break;
  case 1:
    while ((*(uint *)(&DAT_61105000 + iVar2 * 4) & 0x7f) != param_2) {
      iVar2 = iVar2 + 1;
      if (9 < iVar2) {
        return uVar1;
      }
    }
    break;
  case 2:
    while ((*(uint *)(&DAT_61104000 + iVar2 * 4) & 0x7f) != param_2) {
      iVar2 = iVar2 + 1;
      if (5 < iVar2) {
        return uVar1;
      }
    }
    break;
  case 3:
    if ((_DAT_61103000 & 0x7f) != param_2) {
      return uVar1;
    }
    break;
  case 4:
    while ((*(uint *)(&DAT_61102000 + iVar2 * 4) & 0x7f) != param_2) {
      iVar2 = iVar2 + 1;
      if (7 < iVar2) {
        return uVar1;
      }
    }
    break;
  case 5:
    if (((_DAT_61101000 & 0x7f) != param_2) && ((_DAT_61101004 & 0x7f) != param_2)) {
      return uVar1;
    }
    break;
  default:
    return uVar1;
  }
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000d834(void)

{
  char **ppcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  FUN_0000bc6c();
  FUN_0000c230();
  FUN_0000b1e0();
  FUN_0001a770();
  FUN_0000c0b4();
  FUN_0000c1ca(0x1500);
  FUN_0000c1a0(0x1000);
  DAT_00090148 = _DAT_6194d000;
  FUN_0000dc88();
  FUN_0001a744();
  FUN_0001a554();
  FUN_000065ec(0xc0,0,0,0,0);
  uVar3 = 0;
  do {
    FUN_0000c120();
    (*(code *)(&DAT_0001b038)[uVar3])();
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x21);
  FUN_0000c1a0(0x400);
  FUN_0000c1ca(0x800);
  ppcVar1 = (char **)FUN_0000d5f6(0);
  FUN_0000d5e6((int *)ppcVar1);
  FUN_0000d6ec(ppcVar1,DAT_000900ac,4,&stack0xfffffff8);
  FUN_000171f8(0x306b6c63,0,0,(int *)ppcVar1);
  FUN_00014020();
  FUN_000065ec(0xc1,0,0,0,0);
  FUN_00016e3c();
  FUN_00010214();
  _DAT_e000e280 = 0x1000;
  _DAT_e000e100 = 0x1000;
  while (DAT_000900c4 == 0) {
    while( true ) {
      FUN_00018200();
      if (DAT_000900c4 != 0) goto LAB_0000d96c;
      iVar2 = FUN_0000ef84();
      if (iVar2 == 0) break;
      FUN_0000ef94();
      if (DAT_000900c4 != 0) goto LAB_0000d96c;
    }
    if (DAT_000900c4 != 0) break;
    FUN_0000d758();
    iVar2 = FUN_0000ef84();
    if (iVar2 == 0) {
      uVar5 = FUN_00018158();
      FUN_0000d758();
      uVar3 = _DAT_00083000;
      uVar4 = _DAT_00083004 & 0xffffff;
      FUN_0001a7ec();
      if (uVar4 + ((uint)((ulonglong)uVar5 >> 0x20) < uVar3) <= (uint)uVar5) {
        FUN_000184e8();
      }
    }
    FUN_0001a7ec();
    if (DAT_000900c4 != 0) break;
  }
LAB_0000d96c:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000d98c(int param_1,uint param_2,uint param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  undefined8 uVar10;
  
  piVar5 = *(int **)(param_1 + 8);
  uVar3 = 0;
  if (param_2 != 0) {
    iVar4 = *piVar5;
    uVar3 = iVar4 - 1;
    if (iVar4 < 1) {
      uVar6 = 0;
    }
    else {
      uVar6 = ~uVar3 & 1;
    }
    iVar4 = iVar4 - uVar6;
    uVar7 = iVar4 - 1;
    if ((int)uVar7 < (int)uVar3) {
      uVar6 = piVar5[2];
      do {
        if (*(ushort *)(uVar6 + uVar3 * 2) <= param_2) goto LAB_0000d9fe;
        uVar3 = uVar3 - 1;
      } while ((int)uVar7 < (int)uVar3);
    }
    if (-1 < (int)uVar7) {
      uVar6 = piVar5[2];
    }
    uVar3 = uVar7;
    if (uVar7 != 0xffffffff && iVar4 < 0 == SBORROW4(uVar7,-1)) {
      do {
        if (*(ushort *)(uVar6 + uVar3 * 2) <= param_2) break;
        if (*(ushort *)(uVar6 + uVar3 * 2 + -2) <= param_2) {
          uVar3 = uVar3 - 1;
          break;
        }
        uVar3 = uVar3 - 2;
      } while (uVar3 < 0x80000000);
    }
LAB_0000d9fe:
    if ((int)uVar3 < 0) {
      uVar3 = 0;
    }
    iVar4 = *(int *)(piVar5[4] + uVar3 * 4);
    uVar10 = FUN_000001b0(param_3 + 999999,param_4 + (uint)(0xfff0bdc0 < param_3),1000000,0);
    uVar2 = (ushort)((ulonglong)uVar10 >> 0x20);
    uVar3 = piVar5[1];
    uVar6 = 0;
    if (uVar3 != 0) {
      do {
        uVar1 = *(ushort *)(iVar4 + uVar6 * 2);
        bVar9 = uVar1 <= uVar2;
        bVar8 = uVar2 == uVar1;
        if (bVar9 && !bVar8) {
          uVar6 = uVar6 + 1;
        }
        if (bVar9 && !bVar8) {
          bVar9 = uVar6 <= uVar3;
          bVar8 = uVar3 == uVar6;
        }
      } while (bVar9 && !bVar8);
    }
    if (uVar6 < uVar3) {
      uVar3 = (uint)*(ushort *)(piVar5[3] + uVar6 * 2);
    }
    else {
      uVar3 = (uint)*(ushort *)(piVar5[3] + uVar3 * 2 + -2);
    }
  }
  FUN_0000ec02(*(int *)(param_1 + 0x10),uVar3 * 1000);
  return;
}



uint FUN_0000da64(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  if (param_4 < param_2) {
    param_2 = param_4;
  }
  FUN_0000044c(param_1,param_3,param_2);
  return param_2;
}



void FUN_0000da80(void)

{
  DAT_00090468 = FUN_00014250((uint *)"vddmx");
  DAT_0009046c = FUN_00014250((uint *)"vddcx");
  if (DAT_00090468 != -1 && DAT_0009046c != -1) {
    FUN_00014d30(DAT_00090468,1,(int)&LAB_0000dc18_1,DAT_00090468);
    FUN_00014d30(DAT_0009046c,1,(int)&LAB_0000dc18_1,DAT_0009046c);
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int FUN_0000dad8(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  switch(param_1) {
  case 0:
    iVar2 = 0;
    break;
  case 1:
    iVar2 = 1;
    break;
  case 2:
    iVar2 = 4;
    break;
  case 3:
    iVar2 = 3;
    break;
  case 4:
    iVar2 = 2;
    break;
  default:
    goto switchD_0000dade_caseD_5;
  }
  iVar1 = iVar2 * 0x1000;
  piVar3 = &DAT_00093918 + iVar2 * 2;
  uVar4 = param_2 + 3U & 0xfffffffc;
  if (uVar4 <= 0x150U - *piVar3) {
    if (*piVar3 == 0) {
      *(undefined4 *)(iVar1 + 0x600601c8) = 0;
      *(undefined4 *)(iVar1 + 0x600601cc) = 0;
      *(undefined4 *)(iVar1 + 0x600601d0) = 0;
      *(undefined4 *)(iVar1 + 0x600601d4) = 0;
      *(undefined4 *)(&DAT_600601d8 + iVar1) = 0;
      *(undefined4 *)(&DAT_600601dc + iVar1) = 0;
      *(undefined4 *)(&DAT_600601e0 + iVar1) = 0;
      *(undefined4 *)(&DAT_600601e4 + iVar1) = 0;
      *(undefined4 *)(iVar1 + 0x600601e8) = 0;
      *(undefined4 *)(iVar1 + 0x600601ec) = 0;
      *(undefined4 *)(&DAT_600601f0 + iVar1) = 0;
      *(undefined4 *)(&DAT_600601f4 + iVar1) = 0;
      *(undefined4 *)(&DAT_600601f8 + iVar1) = 0;
      *(undefined4 *)(&DAT_600601fc + iVar1) = 0;
      FUN_00000610((undefined4 *)(iVar1 + 0x60060150),0x78);
    }
    iVar2 = iVar1 + 0x60060000 + *piVar3;
    *piVar3 = *piVar3 + uVar4;
    FUN_000005cc(iVar2,uVar4);
    return iVar2;
  }
  if ((*(int *)(iVar2 * 8 + 0x9391c) == 0) && (uVar4 < 0x801)) {
    *(undefined4 *)(iVar2 * 8 + 0x9391c) = 1;
    return iVar1 + 0x60060800;
  }
switchD_0000dade_caseD_5:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int FUN_0000db90(uint param_1)

{
  if (4 < param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  return param_1 * 0x1000 + 0x60060150;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000dba4(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  FUN_0000d758();
  uVar2 = _DAT_00083000;
  uVar5 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  if (4 < param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  iVar1 = param_1 * 0x1000;
  if (param_2 != 0) {
    uVar3 = *(uint *)(iVar1 + 0x60060188);
    if ((uVar3 | *(uint *)(iVar1 + 0x6006018c)) != 0) {
      *(uint *)(iVar1 + 0x60060190) = uVar2;
      *(uint *)(iVar1 + 0x60060194) = uVar5;
      uVar4 = *(uint *)(iVar1 + 0x60060198);
      *(int *)(iVar1 + 0x60060198) = uVar4 + (uVar2 - uVar3);
      *(int *)(iVar1 + 0x6006019c) =
           *(int *)(iVar1 + 0x6006019c) +
           (uVar5 - (*(uint *)(iVar1 + 0x6006018c) + (uint)(uVar2 < uVar3))) +
           (uint)CARRY4(uVar4,uVar2 - uVar3);
      return;
    }
    return;
  }
  *(uint *)(iVar1 + 0x60060188) = uVar2;
  *(uint *)(iVar1 + 0x6006018c) = uVar5;
  *(int *)(iVar1 + 0x60060184) = *(int *)(iVar1 + 0x60060184) + 1;
  return;
}



int FUN_0000dc40(uint param_1)

{
  if (5 < param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  return param_1 * 0x1000 + 0x600601c8;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_0000dc54(void)

{
  return (uint)(_DAT_600611cc == 0x52414a55);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void thunk_FUN_00004908(int param_1)

{
  if (param_1 == 0) {
    if (*(int *)(DAT_000941fc + 0x10) == 0) {
      return;
    }
    _DAT_604a0070 = _DAT_604a0070 & 0xf5fbf | 0x80;
  }
  else {
    if (*(int *)(DAT_000941fc + 0x10) == 0) {
      return;
    }
    _DAT_604a0070 = _DAT_604a0070 & 0xf5fff | 0xc0;
  }
  return;
}



void thunk_FUN_00004958(undefined param_1)

{
  DAT_00090620 = param_1;
  return;
}



void FUN_0000dc74(void)

{
  FUN_00004bb4();
  return;
}



void FUN_0000dc7e(void)

{
  FUN_00004c28();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000dc88(void)

{
  FUN_00004cec((undefined4 *)0x0);
  _DAT_604a0068 = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void thunk_FUN_00004d48(void)

{
  int *piVar1;
  
  piVar1 = DAT_000941fc;
  if (DAT_000904cb == '\x01') {
    DAT_00090618 = 0x82;
    FUN_00005074();
    FUN_0000f54c(0,1,0x82);
  }
  else {
    DAT_00090618 = 0;
  }
  if (*piVar1 + DAT_00090618 == 0) {
    return;
  }
  _DAT_604a0078 = _DAT_604a0078 & 0xffff | (*piVar1 + DAT_00090618) * 0x10000;
  return;
}



void FUN_0000dc9c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DAT_00090340 = param_4;
  DAT_00090344 = param_2;
  DAT_00090348 = param_3;
  DAT_0009034c = param_1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000dcb8(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  int local_30;
  uint local_2c;
  uint local_28;
  uint uStack36;
  uint local_20;
  uint uStack28;
  
  FUN_000048e0();
  if ((DAT_00090344 < DAT_0009034c) || (DAT_00090340 < DAT_00090348)) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  _DAT_604a0064 = 0x28;
  uVar6 = 0x80028;
  uVar4 = (uint)DAT_00090620;
  if (DAT_00090620 != 0) {
    uVar4 = *(uint *)(DAT_000941fc + 8);
  }
  if (DAT_00090620 == 0 || uVar4 == 0) {
    uVar6 = 0xc0228;
  }
  if (*(int *)(DAT_000941fc + 0xc) == 0) {
    uVar6 = uVar6 | 0x20400;
  }
  _DAT_604a0070 =
       _DAT_604a0070 & ~(uVar6 | 0x70600) & 0xf5fff | (uVar6 | 0x10000) & (uVar6 | 0x70600);
  uVar4 = 0;
  local_30 = 0;
  local_28 = DAT_0009034c;
  uStack36 = DAT_00090348;
  local_20 = DAT_00090344;
  uStack28 = DAT_00090340;
  uVar6 = 0;
  uVar3 = 0;
  local_2c = 0;
  iVar1 = FUN_0000fe38(&local_30);
  if (iVar1 != 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  do {
    piVar2 = (int *)(local_2c + uVar6 * 0x10);
    iVar1 = *piVar2;
    if (iVar1 == 0) {
      uVar4 = piVar2[1];
    }
    if (iVar1 == 0 && uVar4 == 0) {
      iVar5 = piVar2[2];
      bVar7 = iVar5 == 0;
      if (bVar7) {
        iVar5 = piVar2[3];
      }
      if (bVar7 && iVar5 == 0) break;
    }
    uVar4 = piVar2[2] | piVar2[1] << 8;
    *(uint *)(&DAT_604a0030 + uVar6 * 4) = uVar4 | iVar1 << 0x18 | piVar2[3] << 0x1c;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0xc);
  do {
    piVar2 = (int *)(local_30 + uVar3 * 0x10);
    iVar1 = *piVar2;
    if (iVar1 == 0) {
      local_2c = piVar2[1];
    }
    if (iVar1 == 0 && local_2c == 0) {
      iVar5 = piVar2[2];
      bVar7 = iVar5 == 0;
      if (bVar7) {
        iVar5 = piVar2[3];
      }
      if (bVar7 && iVar5 == 0) break;
    }
    local_2c = piVar2[2] | piVar2[1] << 8;
    *(uint *)(&DAT_604a0000 + uVar3 * 4) = local_2c | iVar1 << 0x18 | piVar2[3] << 0x1c;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0xc);
  if (uVar6 != 0) {
    _DAT_604a0060 = uVar6 * 0x10 - 0x10 & 0xf0 | _DAT_604a0060 & 0xf;
  }
  if (uVar3 == 0) {
    return;
  }
  _DAT_604a0060 = _DAT_604a0060 & 0xf0 | uVar3 - 1 & 0xf;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void thunk_FUN_00004adc(void)

{
  _DAT_604a0070 = _DAT_604a0070 & 0xc0;
  _DAT_604a0080 = 1;
  _DAT_604a00b4 = 0;
  _DAT_604a00b8 = 0;
  return;
}



void FUN_0000dcec(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  code **ppcVar4;
  undefined8 uVar5;
  
  uVar5 = FUN_0000699c();
  iVar1 = (int)((ulonglong)uVar5 >> 0x20);
  uVar2 = ((uint)DAT_000939f2 + 1) % 10;
  DAT_000939f2 = (byte)uVar2;
  (&DAT_00093b60)[uVar2 * 0x18] = (char)param_1;
  (&DAT_00093b61)[(uint)DAT_000939f2 * 0x18] = (char)param_2;
  uVar2 = (uint)DAT_000939f2;
  *(int *)(&DAT_00093b68 + uVar2 * 0x18) = iVar1;
  *(int *)(&DAT_00093b6c + uVar2 * 0x18) = (int)uVar5;
  *(undefined4 *)(&DAT_00093b70 + (uint)DAT_000939f2 * 0x18) = 0;
  if (param_1 < 0x81) {
    ppcVar4 = *(code ***)(DAT_000939e8 + param_1 * 4);
    while (ppcVar4 != (code **)0x0) {
      if ((*ppcVar4 != (code *)0x0) && ((*(byte *)(ppcVar4 + 2) & param_2) != 0)) {
        FUN_0000699c();
        (**ppcVar4)(ppcVar4[1],*(byte *)(ppcVar4 + 2) & param_2);
      }
      ppcVar4 = (code **)ppcVar4[4];
    }
    iVar3 = FUN_0000699c();
    *(int *)(&DAT_00093b70 + (uint)DAT_000939f2 * 0x18) = iVar3 - iVar1;
    return;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0000e174(void)

{
  _DAT_0008000c = 0x4000040;
  return;
}



void FUN_0000e180(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *local_18;
  
  local_18 = param_4;
  if (param_1 != 0) {
    FUN_0000d758();
    iVar3 = *(int *)(param_1 + 0x38);
    iVar2 = *(int *)(param_1 + 0x1c);
    *(int *)(param_1 + 0x1c) = param_2;
    iVar1 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x34);
    *(int *)(param_1 + 0x38) = iVar1;
    if ((*(int *)(param_1 + 0x10) == 0) || ((param_2 == iVar2 && (iVar1 == iVar3)))) {
LAB_0000e1d2:
      FUN_0001a7ec();
      return;
    }
    iVar1 = FUN_000032d6(DAT_000937c8,&local_18);
    if (iVar1 == 0) {
      *local_18 = param_1;
      local_18[1] = iVar2;
      local_18[2] = *(int *)(param_1 + 0x1c);
      local_18[3] = iVar3;
      local_18[4] = *(int *)(param_1 + 0x38);
      iVar1 = FUN_0000342a(DAT_000937c8,(int)local_18);
      if (iVar1 == 0) goto LAB_0000e1d2;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 FUN_0000e1e0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *in_r12;
  bool bVar10;
  bool bVar11;
  undefined4 local_28;
  uint local_24;
  int local_20;
  
  iVar9 = 0;
  piVar2 = param_1;
  if (param_1 != (int *)0x0) {
    piVar2 = (int *)*param_1;
  }
  if (param_1 == (int *)0x0 || piVar2 == (int *)0x0) {
LAB_0000e314:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  FUN_0000d758();
  piVar2 = (int *)((undefined4 *)*param_1)[4];
  local_28 = **(undefined4 **)(undefined4 *)*param_1;
  local_24 = param_1[2];
  local_20 = param_1[4];
  if (param_1[2] != param_1[1]) {
    iVar9 = 3;
  }
  uVar8 = (uint)(param_1[3] < param_1[4]);
  if (param_1[4] < param_1[3]) {
    uVar8 = 2;
  }
  do {
    if (piVar2 == (int *)0x0) {
      FUN_0001a7ec();
      return 0;
    }
    cVar1 = *(char *)(piVar2 + 4);
    if (cVar1 == '\x01') {
      if (iVar9 != 0) {
        uVar4 = 3;
joined_r0x0000e248:
        if (piVar2 == (int *)0xffffffe4) goto LAB_0000e314;
LAB_0000e294:
        in_r12 = (undefined4 *)piVar2[7];
        (*(code *)in_r12)(piVar2[8],uVar4,&local_28,0xc);
      }
    }
    else {
      if (cVar1 == '\x02') {
        iVar5 = piVar2[5];
        iVar3 = piVar2[6];
        if (iVar5 <= iVar3) {
          uVar4 = uVar8;
          if (uVar8 == 1) {
            if ((param_1[3] < iVar3) && (iVar3 <= param_1[4])) goto joined_r0x0000e248;
          }
          else {
            if (((uVar8 == 2) && (iVar5 < param_1[3])) && (param_1[4] <= iVar5)) {
              if (piVar2 != (int *)0xffffffe4) goto LAB_0000e294;
              goto LAB_0000e314;
            }
          }
        }
      }
      else {
        if (cVar1 != '\x03') goto LAB_0000e314;
        if (iVar9 != 0) {
          uVar4 = piVar2[5];
          uVar6 = piVar2[6];
          if (uVar4 <= uVar6) {
            if ((local_24 < uVar4) && (uVar4 <= (uint)param_1[1])) {
              in_r12 = &DAT_00000004;
            }
            else {
              if ((local_24 <= uVar6) || (uVar6 < (uint)param_1[1])) {
                bVar11 = local_24 <= uVar4;
                bVar10 = uVar4 == local_24;
                if (!bVar11 || bVar10) {
                  bVar11 = uVar6 <= local_24;
                  bVar10 = local_24 == uVar6;
                }
                if (!bVar11 || bVar10) {
                  uVar7 = param_1[1];
                  bVar11 = uVar7 <= uVar4;
                  bVar10 = uVar4 == uVar7;
                  if (!bVar11 || bVar10) {
                    bVar11 = uVar6 <= uVar7;
                    bVar10 = uVar7 == uVar6;
                  }
                  if (bVar11 && !bVar10) {
                    in_r12 = (undefined4 *)((int)&DAT_00000004 + 1);
                  }
                  if (bVar11 && !bVar10) goto LAB_0000e2e6;
                }
                goto LAB_0000e302;
              }
              in_r12 = (undefined4 *)((int)&DAT_00000004 + 2);
            }
LAB_0000e2e6:
            if ((code **)(piVar2 + 7) == (code **)0x0) goto LAB_0000e314;
            (*(code *)piVar2[7])(piVar2[8],in_r12,&local_28,0xc);
          }
        }
      }
    }
LAB_0000e302:
    piVar2 = (int *)*piVar2;
  } while( true );
}



void FUN_0000e3a8(int param_1)

{
  if (param_1 != 0) {
    FUN_0000f1ee(param_1);
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int * FUN_0000e40c(uint *param_1)

{
  uint uVar1;
  int *piVar2;
  
  if (param_1 == (uint *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  piVar2 = DAT_000937ac;
  if (param_1 != (uint *)0x0 && DAT_000937ac != (int *)0x0) {
    do {
      uVar1 = FUN_000003b6(param_1,(uint *)piVar2[1],0x40);
      if (uVar1 == 0) {
        if (piVar2 == (int *)0x0) {
          return (int *)0x0;
        }
        if (*(int *)piVar2[2] == 0) {
          return (int *)0x0;
        }
        return (int *)piVar2[2];
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
  }
  return (int *)0x0;
}



int * FUN_0000e418(uint *param_1,uint *param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  code *pcVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  
  if ((param_2 != (uint *)0x0) && (puVar1 = FUN_00000378(param_2), puVar1 <= FUN_0000003c + 3)) {
    piVar3 = DAT_000937ac;
    if (param_1 != (uint *)0x0 && DAT_000937ac != (int *)0x0) {
      do {
        uVar2 = FUN_000003b6(param_1,(uint *)piVar3[1],0x40);
        if (uVar2 == 0) {
          if (piVar3 == (int *)0x0) {
            return (int *)0x0;
          }
          piVar5 = (int *)piVar3[2];
          if (*piVar5 == 0) {
            return (int *)0x0;
          }
          iVar6 = piVar3[1];
          if ((*(uint *)(piVar5[5] + 4) & param_3) == 0) {
            return (int *)0x0;
          }
          piVar3 = FUN_0000308c((int *)&DAT_0009374c);
          if (piVar3 != (int *)0x0) {
            *piVar3 = 0;
            piVar3[4] = 0;
            piVar3[6] = 0;
            piVar3[7] = 0;
            piVar3[8] = 0;
            piVar3[9] = 0;
            piVar3[10] = 0;
            piVar3[5] = param_3;
            piVar3[0xb] = 0;
            *(uint **)(piVar3 + 1) = param_2;
            piVar3[2] = iVar6;
            *(int **)(piVar3 + 3) = piVar5;
            piVar3[0xc] = 0;
            *(code **)(piVar3 + 0xd) = FUN_0000ec28 + 1;
            FUN_0000d758();
            uVar2 = *(uint *)(*piVar5 + 0x10);
            bVar7 = (uVar2 & 2) != 0;
            if (bVar7) {
              uVar2 = piVar5[3];
            }
            if (!bVar7 || uVar2 == 0) {
              pcVar4 = *(code **)(piVar5[5] + 0x10);
              if (pcVar4 == (code *)0x0) {
                if (*(int *)(piVar5[5] + 8) != 0) {
                  (**(code **)(*(int *)(*(int *)piVar3[3] + 0xc) + 8))(piVar3);
                }
              }
              else {
                iVar6 = (*pcVar4)(piVar3,param_4,param_5);
                if (iVar6 != 0) goto LAB_0000e4d0;
              }
              *piVar3 = piVar5[3];
              *(int **)(piVar5 + 3) = piVar3;
              FUN_0001a7ec();
              return piVar3;
            }
LAB_0000e4d0:
            FUN_0001a7ec();
            if ((undefined4 *)piVar3[0xc] != (undefined4 *)0x0) {
              FUN_000031cc((int)&DAT_0009376c,(undefined4 *)piVar3[0xc]);
            }
            FUN_000031cc((int)&DAT_0009374c,piVar3);
            return (int *)0x0;
          }
          goto LAB_0000e4bc;
        }
        piVar3 = (int *)*piVar3;
      } while (piVar3 != (int *)0x0);
    }
    return (int *)0x0;
  }
LAB_0000e4bc:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000e51c(undefined *param_1,int param_2,undefined *param_3,undefined *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  undefined *puVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined **ppuVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint uVar11;
  
  uVar11 = 0;
  puVar4 = param_1;
  if (param_1 != (undefined *)0x0) {
    puVar4 = *(undefined **)(param_1 + 0x1c);
  }
  if ((param_1 != (undefined *)0x0 && puVar4 != (undefined *)0x0) && (*(int *)(param_1 + 0x18) != 0)
     ) {
    if (*(int *)(param_1 + 0x18) != 0) {
      do {
        puVar10 = *(uint **)(*(int *)(param_1 + 0x1c) + uVar11 * 0x20);
        if (puVar10 == (uint *)0x0) goto LAB_0000e5fe;
        FUN_0000d758();
        piVar6 = (int *)DAT_000937ac;
        while (piVar6 != (int *)0x0) {
          uVar5 = FUN_000003b6(puVar10,(uint *)piVar6[1],0x40);
          if (uVar5 == 0) {
            if (piVar6 != (int *)0x0) {
              piVar6 = (int *)piVar6[2];
              iVar7 = *piVar6;
              if (iVar7 != 0) {
                piVar6 = (int *)0x0;
              }
              if (iVar7 != 0 || piVar6 != (int *)0x0) goto LAB_0000e5a8;
              goto LAB_0000e5fe;
            }
            break;
          }
          piVar6 = (int *)*piVar6;
        }
        piVar6 = FUN_0000308c((int *)&DAT_0009372c);
        if (piVar6 == (int *)0x0) goto LAB_0000e5fe;
        FUN_00000610(piVar6,0x48);
        piVar6[0xf] = 1;
        *piVar6 = 0;
        piVar6[0x10] = DAT_000937b8;
        FUN_0000ed80(puVar10,piVar6);
LAB_0000e5a8:
        FUN_0001a7ec();
        if (piVar6 == (int *)0x0) goto LAB_0000e5fe;
        iVar7 = param_2;
        if (param_2 != 0) {
          iVar7 = *(int *)(param_2 + uVar11 * 4);
        }
        uVar11 = uVar11 + 1;
        piVar6[6] = iVar7;
      } while (uVar11 < *(uint *)(param_1 + 0x18));
    }
    uVar11 = 0;
    while (uVar11 < *(uint *)(param_1 + 0x10)) {
      uVar11 = uVar11 + 1;
    }
    ppuVar8 = (undefined **)FUN_0000308c((int *)&DAT_0009376c);
    if (ppuVar8 != (undefined **)0x0) {
      ppuVar8[3] = (undefined *)0x0;
      ppuVar8[4] = (undefined *)0x0;
      *ppuVar8 = param_3;
      ppuVar8[1] = param_4;
      ppuVar8[2] = param_1;
      FUN_0000e608(ppuVar8);
      if (DAT_000937b0 == (undefined4 *)0x0) {
        return;
      }
      do {
        FUN_0000d758();
        puVar2 = DAT_000937b0;
        DAT_000937b0 = (undefined4 *)*DAT_000937b0;
        FUN_0001a7ec();
        if (puVar2 != (undefined4 *)0x0) {
          piVar6 = (int *)puVar2[2];
          if (*piVar6 != 0) {
LAB_0000e39e:
                    // WARNING: Subroutine does not return
            FUN_00000060();
          }
          puVar1 = (undefined4 *)piVar6[4];
          while (puVar1 != (undefined4 *)0x0) {
            if (*(char *)(puVar1 + 4) != '\0') goto LAB_0000e39e;
            puVar10 = (uint *)puVar2[1];
            puVar3 = FUN_00000378(puVar10);
            if ((code **)(puVar1 + 7) == (code **)0x0) goto LAB_0000e39e;
            (*(code *)puVar1[7])(puVar1[8],0,puVar10,puVar3);
            puVar9 = (undefined4 *)*puVar1;
            FUN_000031cc((int)&DAT_0009376c,puVar1);
            puVar1 = puVar9;
          }
          FUN_000031cc((int)&DAT_0009372c,piVar6);
          FUN_000031cc((int)&DAT_0009378c,puVar2);
        }
        if (DAT_000937b0 == (undefined4 *)0x0) {
          return;
        }
      } while( true );
    }
  }
LAB_0000e5fe:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0000e608(undefined **param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  int *piVar4;
  uint **ppuVar5;
  undefined4 uVar6;
  int iVar7;
  uint **ppuVar8;
  code *pcVar9;
  uint **ppuVar10;
  uint *puVar11;
  int **ppiVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  uint *local_90;
  uint *local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int *local_50;
  uint local_4c;
  code *local_44;
  undefined4 local_40;
  undefined4 local_34;
  uint *local_2c;
  
  if (param_1 != (undefined **)0x0) {
    ppuVar10 = (uint **)param_1[2];
    puVar2 = (uint *)param_1[3];
    while ((puVar2 < ppuVar10[4] &&
           (puVar2 = (uint *)ppuVar10[5][(int)puVar2 * 3], ppiVar12 = DAT_000937ac,
           puVar2 != (uint *)0x0 && DAT_000937ac != (int **)0x0))) {
      while (uVar1 = FUN_000003b6(puVar2,(uint *)ppiVar12[1],0x40), uVar1 != 0) {
        ppiVar12 = (int **)*ppiVar12;
        if (ppiVar12 == (int **)0x0) goto LAB_0000e664;
      }
      if ((ppiVar12 == (int **)0x0) || (*ppiVar12[2] == 0 || ppiVar12[2] == (int *)0x0)) break;
      puVar2 = (uint *)(param_1[3] + 1);
      *(uint **)(param_1 + 3) = puVar2;
    }
LAB_0000e664:
    puVar2 = (uint *)param_1[3];
    if (puVar2 != ppuVar10[4]) {
      puVar14 = ppuVar10[5];
      param_1[3] = (undefined *)((int)puVar2 + 1);
      FUN_0000f038((uint *)puVar14[(int)puVar2 * 3],(undefined *)0xe609,(int)param_1);
      return;
    }
    if (param_1 != (undefined **)0x0 && ppuVar10 != (uint **)0x0) {
      puVar2 = ppuVar10[7];
    }
    if ((param_1 != (undefined **)0x0 && ppuVar10 != (uint **)0x0) && puVar2 != (uint *)0x0) {
      local_2c = (uint *)(uint)(((uint)ppuVar10[2] & 1) == 0);
      puVar2 = (uint *)0x0;
      ppuVar8 = (uint **)ppuVar10[5];
      if (ppuVar10[4] != (uint *)0x0) {
        do {
          ppuVar8[2] = (uint *)0x0;
          puVar14 = ppuVar8[1];
          if (puVar14 != (uint *)0x7fffffff) {
            puVar15 = *ppuVar10;
            puVar11 = *ppuVar8;
            local_40 = 0;
            local_34 = 0;
            local_44 = FUN_0000ec28 + 1;
            if ((puVar15 == (uint *)0x0) ||
               (puVar3 = FUN_00000378(puVar15), FUN_0000003c + 3 < puVar3)) goto LAB_0000e9ba;
            ppiVar12 = DAT_000937ac;
            if (puVar11 == (uint *)0x0 || DAT_000937ac == (int **)0x0) {
LAB_0000e75a:
              ppuVar8[2] = (uint *)0x0;
              goto LAB_0000e9ba;
            }
            while (uVar1 = FUN_000003b6(puVar11,(uint *)ppiVar12[1],0x40), uVar1 != 0) {
              ppiVar12 = (int **)*ppiVar12;
              if (ppiVar12 == (int **)0x0) goto LAB_0000e75a;
            }
            if ((ppiVar12 == (int **)0x0) || (piVar4 = ppiVar12[2], *piVar4 == 0)) {
              puVar11 = (uint *)0x0;
            }
            else {
              local_50 = ppiVar12[1];
              if ((*(uint *)(piVar4[5] + 4) & (uint)puVar14) == 0) goto LAB_0000e75a;
              puVar11 = (uint *)FUN_0000308c((int *)&DAT_0009374c);
              if (puVar11 == (uint *)0x0) goto LAB_0000e9ba;
              *puVar11 = 0;
              puVar11[4] = 0;
              puVar11[6] = 0;
              puVar11[7] = 0;
              puVar11[8] = 0;
              puVar11[9] = 0;
              puVar11[10] = 0;
              puVar11[0xb] = 0;
              *(uint **)(puVar11 + 1) = puVar15;
              puVar11[0xc] = 0;
              *(int **)(puVar11 + 2) = local_50;
              *(uint **)(puVar11 + 5) = puVar14;
              *(int **)(puVar11 + 3) = piVar4;
              *(code **)(puVar11 + 0xd) = local_44;
              FUN_0000d758();
              if (((*(uint *)(*piVar4 + 0x10) & 2) == 0) || (piVar4[3] == 0)) {
                pcVar9 = *(code **)(piVar4[5] + 0x10);
                if (pcVar9 == (code *)0x0) {
                  if (*(int *)(piVar4[5] + 8) != 0) {
                    (**(code **)(*(int *)(*(int *)puVar11[3] + 0xc) + 8))(puVar11);
                  }
                }
                else {
                  iVar7 = (*pcVar9)(puVar11,local_40,local_34);
                  if (iVar7 != 0) goto LAB_0000e778;
                }
                *puVar11 = piVar4[3];
                *(uint **)(piVar4 + 3) = puVar11;
                FUN_0001a7ec();
              }
              else {
LAB_0000e778:
                FUN_0001a7ec();
                if ((undefined4 *)puVar11[0xc] != (undefined4 *)0x0) {
                  FUN_000031cc((int)&DAT_0009376c,(undefined4 *)puVar11[0xc]);
                }
                FUN_000031cc((int)&DAT_0009374c,puVar11);
                puVar11 = (uint *)0x0;
              }
            }
            ppuVar8[2] = puVar11;
            if (puVar11 == (uint *)0x0) goto LAB_0000e9ba;
          }
          puVar2 = (uint *)((int)puVar2 + 1);
          ppuVar8 = (uint **)(ppuVar10[5] + (int)puVar2 * 3);
        } while (puVar2 < ppuVar10[4]);
      }
      local_90 = (uint *)0x0;
      ppuVar8 = (uint **)ppuVar10[7];
      if (ppuVar10[6] != (uint *)0x0) {
        do {
          puVar2 = *ppuVar8;
          ppiVar12 = DAT_000937ac;
          if (puVar2 == (uint *)0x0 || DAT_000937ac == (int **)0x0) goto LAB_0000e9ba;
          while (uVar1 = FUN_000003b6(puVar2,(uint *)ppiVar12[1],0x40), puVar14 = local_2c,
                uVar1 != 0) {
            ppiVar12 = (int **)*ppiVar12;
            if (ppiVar12 == (int **)0x0) goto LAB_0000e9ba;
          }
          if (((ppiVar12 == (int **)0x0) || (ppuVar8 == (uint **)0x0 || ppuVar10 == (uint **)0x0))
             || (ppuVar5 = (uint **)FUN_0000308c((int *)&DAT_0009372c), ppuVar5 == (uint **)0x0))
          goto LAB_0000e9ba;
          FUN_00000610(ppuVar5,0x48);
          *(uint ***)ppuVar5 = ppuVar8;
          ppuVar5[5] = ppuVar8[3];
          puVar2 = ppuVar8[2];
          ppuVar5[0xf] = puVar14;
          *(uint ***)(ppuVar5 + 2) = ppuVar10;
          ppuVar5[0xd] = puVar2;
          ppuVar5[0x10] = DAT_000937b8;
          if (((uint)ppuVar8[4] & 8) != 0) {
            local_4c = (int)ppuVar8[2] << 2;
            ppuVar8[4] = (uint *)((uint)ppuVar8[4] | 1);
            if (ppuVar5 + 0xc == (uint **)0x0) goto LAB_0000e9ba;
            puVar2 = (uint *)FUN_00000154(local_4c);
            ppuVar5[0xc] = puVar2;
            FUN_00000610(puVar2,local_4c);
          }
          puVar14 = ppuVar8[3];
          puVar2 = puVar14 + 2;
          if (*puVar2 != 0) {
            puVar14 = (uint *)puVar14[4];
          }
          if (*puVar2 != 0 && puVar14 != (uint *)0x0) goto LAB_0000e9ba;
          *(uint ***)(ppuVar8 + 7) = ppuVar5;
          ppuVar5[6] = (uint *)ppiVar12[2][6];
          *(uint **)(ppuVar8[7] + 1) = local_90;
          local_90 = (uint *)((int)local_90 + 1);
          ppuVar8 = (uint **)(ppuVar10[7] + (int)local_90 * 8);
        } while (local_90 < ppuVar10[6]);
      }
      local_88 = 0;
      local_84 = 0;
      local_80 = 0;
      local_7c = 0;
      local_78 = 0;
      local_70 = 0;
      local_6c = 0;
      local_68 = 0;
      local_60 = 0;
      local_64 = 0;
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
      local_74 = 1;
      puVar14 = ppuVar10[6];
      puVar2 = ppuVar10[7];
      puVar11 = (uint *)0x0;
      if (puVar14 != (uint *)0x0) {
        do {
          uVar13 = puVar2[7];
          uVar6 = (**(code **)(*(int *)(uVar13 + 8) + 4))
                            (uVar13,&local_88,*(undefined4 *)(uVar13 + 0x18));
          uVar17 = *(uint *)(uVar13 + 0x38);
          uVar16 = *(uint *)(uVar13 + 0x1c);
          *(undefined4 *)(uVar13 + 0x1c) = uVar6;
          uVar1 = *(int *)(uVar13 + 0x18) - *(int *)(uVar13 + 0x34);
          *(uint *)(uVar13 + 0x38) = uVar1;
          if ((*(int *)(uVar13 + 0x10) != 0) &&
             (*(uint *)(uVar13 + 0x1c) != uVar16 || uVar1 != uVar17)) {
            iVar7 = FUN_000032d6(DAT_000937c8,(int **)&local_8c);
            if (iVar7 != 0) goto LAB_0000e9ba;
            *local_8c = uVar13;
            local_8c[1] = uVar16;
            local_8c[2] = *(uint *)(uVar13 + 0x1c);
            local_8c[3] = uVar17;
            local_8c[4] = *(uint *)(uVar13 + 0x38);
            iVar7 = FUN_0000342a(DAT_000937c8,(int)local_8c);
            if (iVar7 != 0) goto LAB_0000e9ba;
          }
          *(undefined4 *)(uVar13 + 0x18) = 0;
          puVar11 = (uint *)((int)puVar11 + 1);
          puVar14 = ppuVar10[6];
          puVar2 = ppuVar10[7] + (int)puVar11 * 8;
        } while (puVar11 < puVar14);
      }
      puVar2 = (uint *)0x0;
      ppuVar8 = (uint **)ppuVar10[7];
      if (puVar14 != (uint *)0x0) {
        do {
          FUN_0000ed80(*ppuVar8,(int *)ppuVar8[7]);
          puVar2 = (uint *)((int)puVar2 + 1);
          ppuVar8 = (uint **)(ppuVar10[7] + (int)puVar2 * 8);
        } while (puVar2 < ppuVar10[6]);
      }
      if (*param_1 != (undefined *)0x0) {
        puVar2 = *ppuVar10;
        puVar14 = FUN_00000378(puVar2);
        if (param_1 == (undefined **)0x0) goto LAB_0000e9ba;
        (*(code *)*param_1)(param_1[1],0,puVar2,puVar14);
      }
      if (param_1 == (undefined **)0x0) {
        return;
      }
      FUN_000031cc((int)&DAT_0009376c,param_1);
      return;
    }
  }
LAB_0000e9ba:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



uint FUN_0000ea28(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_2 + (*(uint *)(param_2 + 0x28) ^ 1) * 8 + 0x18);
  if ((*(uint *)(*param_1 + 0x10) & 8) == 0) {
    return uVar1;
  }
  if (*(uint *)(*param_1 + 8) < uVar1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  param_1[0xd] = uVar1;
  iVar2 = *(int *)(param_2 + (*(uint *)(param_2 + 0x28) ^ 1) * 8 + 0x18);
  param_1[6] = iVar2;
  FUN_000004de(param_1[0xc],*(undefined4 *)(param_2 + (*(uint *)(param_2 + 0x28) ^ 1) * 8 + 0x1c),
               iVar2 << 2);
  return param_1[6];
}



void FUN_0000ea78(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uStack20;
  undefined4 uStack16;
  
  if (DAT_000937b4 != 0) {
    return;
  }
  puVar1 = FUN_0000f1e4();
  if (puVar1 != (undefined *)0x0) {
    DAT_000937b4 = 1;
    DAT_000937b8 = 1;
    if ((undefined4 *)(puVar1 + 4) != (undefined4 *)0x0) {
      uStack20 = *(undefined4 *)(puVar1 + 4);
      uStack16 = *(undefined4 *)(puVar1 + 8);
      FUN_0000312c((undefined4 *)&DAT_0009372c,(uint *)&stack0xffffffe8);
      if ((undefined4 *)(puVar1 + 0xc) != (undefined4 *)0x0) {
        uStack20 = *(undefined4 *)(puVar1 + 0xc);
        uStack16 = *(undefined4 *)(puVar1 + 0x10);
        FUN_0000312c((undefined4 *)&DAT_0009374c,(uint *)&stack0xffffffe8);
        if ((undefined4 *)(puVar1 + 0x14) != (undefined4 *)0x0) {
          uStack20 = *(undefined4 *)(puVar1 + 0x14);
          uStack16 = *(undefined4 *)(puVar1 + 0x18);
          FUN_0000312c((undefined4 *)&DAT_0009376c,(uint *)&stack0xffffffe8);
          if ((undefined4 *)(puVar1 + 0x1c) != (undefined4 *)0x0) {
            uStack20 = *(undefined4 *)(puVar1 + 0x1c);
            uStack16 = *(undefined4 *)(puVar1 + 0x20);
            FUN_0000312c((undefined4 *)&DAT_0009378c,(uint *)&stack0xffffffe8);
            if (*(int *)(puVar1 + 0x38) == 0) {
              iVar2 = *(int *)(puVar1 + 0x34);
            }
            else {
              iVar2 = FUN_00003300(&DAT_000937c8,FUN_0000e1e0 + 1,*(int *)(puVar1 + 0x24),
                                   *(int *)(puVar1 + 0x28),0x14);
              if (iVar2 != 0) goto LAB_0000eb3e;
              iVar2 = *(int *)(puVar1 + 0x34);
            }
            if (iVar2 == -1) {
              FUN_0000f1ec();
              DAT_00090150 = &DAT_0009372c;
              return;
            }
          }
        }
      }
    }
  }
LAB_0000eb3e:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000eb5c(int param_1)

{
  if (param_1 != 0) {
                    // WARNING: Could not recover jumptable at 0x0000eb62. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(param_1 + 0x34))(param_1,1);
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000eb68(int param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int *unaff_r5;
  uint uVar3;
  bool bVar4;
  
  if (param_1 != 0) {
    unaff_r5 = *(int **)(param_1 + 0xc);
  }
  if (param_1 != 0 && unaff_r5 != (int *)0x0) {
    uVar3 = *(uint *)(*unaff_r5 + 8);
    *(uint *)(param_1 + (*(uint *)(param_1 + 0x28) ^ 1) * 8 + 0x18) = param_2;
    uVar1 = FUN_0000d758();
    bVar4 = param_2 == 0;
    if (!bVar4) {
      uVar1 = unaff_r5[0xd];
    }
    if ((bVar4 || param_2 <= uVar1) && (!bVar4 && uVar1 != param_2)) {
      unaff_r5[0xd] = param_2;
    }
    if ((!bVar4 && param_2 > uVar1 || (bVar4 || uVar1 == param_2)) &&
       (*(int *)(param_1 + *(int *)(param_1 + 0x28) * 8 + 0x18) == unaff_r5[0xd])) {
      piVar2 = (int *)unaff_r5[3];
      while (piVar2 != (int *)0x0) {
        if (piVar2[5] == 0x200) {
          uVar1 = param_2;
          if (piVar2 != (int *)param_1) {
            uVar1 = piVar2[piVar2[10] * 2 + 6];
          }
          if ((uVar1 == 0 || uVar1 <= uVar3) && (uVar1 != 0 && uVar3 != uVar1)) {
            uVar3 = uVar1;
          }
        }
        piVar2 = (int *)*piVar2;
      }
      unaff_r5[0xd] = uVar3;
    }
    FUN_0001a7ec();
                    // WARNING: Could not recover jumptable at 0x0000ec00. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(param_1 + 0x34))
              (param_1,(uint)(*(int *)(param_1 + (*(uint *)(param_1 + 0x28) ^ 1) * 8 + 0x18) !=
                             *(int *)(param_1 + *(uint *)(param_1 + 0x28) * 8 + 0x18)));
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000ec02(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(int *)(param_1 + (*(uint *)(param_1 + 0x28) ^ 1) * 8 + 0x18) = param_2;
    param_2 = *(int *)(param_1 + *(int *)(param_1 + 0x28) * 8 + 0x18) - param_2;
    if (param_2 != 0) {
      param_2 = 1;
    }
                    // WARNING: Could not recover jumptable at 0x0000ec20. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(param_1 + 0x34))(param_1,param_2);
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000ec28(int param_1,int param_2,undefined4 param_3,uint **param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code **ppcVar4;
  uint *unaff_r5;
  uint *puVar5;
  uint *puVar6;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar7;
  uint **local_20;
  
  local_20 = param_4;
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 1;
    uVar1 = *(uint *)(param_1 + 0x28) ^ 1;
    *(uint *)(param_1 + 0x28) = uVar1;
    if (*(int *)(param_1 + 0x14) == 0x400) {
      if (*(int *)(param_1 + 0x30) == 0) {
        return;
      }
      iVar3 = param_1 + uVar1 * 8;
      if (*(int *)(iVar3 + 0x1c) == *(int *)(*(int *)(param_1 + 0x30) + 0xc)) {
        *(undefined4 *)(iVar3 + 0x1c) = 0;
        goto LAB_0000ed42;
      }
    }
    else {
LAB_0000ed42:
      if (*(int *)(param_1 + 0x30) == 0) {
        return;
      }
    }
    ppcVar4 = *(code ***)(param_1 + 0x30);
    UNRECOVERED_JUMPTABLE = *ppcVar4;
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      return;
    }
    goto LAB_0000ecfc;
  }
  if (param_1 != 0) {
    unaff_r5 = *(uint **)(param_1 + 0xc);
  }
  if (param_1 == 0 || unaff_r5 == (uint *)0x0) goto LAB_0000ecc8;
  FUN_0000d758();
  uVar1 = unaff_r5[0x11];
  unaff_r5[0x11] = uVar1 + 0x100;
  *(uint *)(param_1 + 0x2c) = uVar1 + 0x100;
  uVar2 = (**(code **)unaff_r5[5])(unaff_r5,param_1);
  unaff_r5[6] = uVar2;
  uVar1 = *unaff_r5;
  puVar5 = (uint *)(uVar1 + 0x10);
  if (((*puVar5 & 8) == 0) && (uVar1 = unaff_r5[0xd], uVar1 <= uVar2)) {
    uVar2 = uVar1;
  }
  bVar7 = (*puVar5 & 1) == 0;
  if (bVar7) {
    uVar1 = unaff_r5[7];
  }
  if (!bVar7 || uVar1 != uVar2) {
    uVar2 = (**(code **)(unaff_r5[2] + 4))(unaff_r5,param_1,uVar2);
  }
  puVar6 = (uint *)unaff_r5[0xe];
  puVar5 = (uint *)unaff_r5[7];
  unaff_r5[7] = uVar2;
  *(uint **)(unaff_r5 + 0xe) = (uint *)(unaff_r5[6] - unaff_r5[0xd]);
  if ((unaff_r5[4] != 0) &&
     ((uint *)unaff_r5[7] != puVar5 || (uint *)(unaff_r5[6] - unaff_r5[0xd]) != puVar6)) {
    iVar3 = FUN_000032d6(DAT_000937c8,(int **)&local_20);
    if (iVar3 != 0) {
LAB_0000ecc8:
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    *local_20 = unaff_r5;
    local_20[1] = puVar5;
    local_20[2] = (uint *)unaff_r5[7];
    local_20[3] = puVar6;
    local_20[4] = (uint *)unaff_r5[0xe];
    iVar3 = FUN_0000342a(DAT_000937c8,(int)local_20);
    if (iVar3 != 0) goto LAB_0000ecc8;
  }
  FUN_0001a7ec();
  uVar1 = *(uint *)(param_1 + 0x28) ^ 1;
  *(uint *)(param_1 + 0x28) = uVar1;
  if (*(int *)(param_1 + 0x14) == 0x400) {
    if (*(int *)(param_1 + 0x30) == 0) {
      return;
    }
    iVar3 = param_1 + uVar1 * 8;
    if (*(int *)(iVar3 + 0x1c) == *(int *)(*(int *)(param_1 + 0x30) + 0xc)) {
      *(undefined4 *)(iVar3 + 0x1c) = 0;
      goto LAB_0000ece2;
    }
  }
  else {
LAB_0000ece2:
    if (*(int *)(param_1 + 0x30) == 0) {
      return;
    }
  }
  ppcVar4 = *(code ***)(param_1 + 0x30);
  UNRECOVERED_JUMPTABLE = *ppcVar4;
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return;
  }
LAB_0000ecfc:
                    // WARNING: Could not recover jumptable at 0x0000ed08. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)(ppcVar4[1],0,param_1,4);
  return;
}



void FUN_0000ed80(uint *param_1,int *param_2)

{
  bool bVar1;
  int **ppiVar2;
  int **ppiVar3;
  int **ppiVar4;
  uint uVar5;
  int **ppiVar6;
  
  if ((param_2 != (int *)0x0 && param_1 != (uint *)0x0) &&
     (ppiVar4 = (int **)FUN_0000308c((int *)&DAT_0009378c), ppiVar4 != (int **)0x0)) {
    *(uint **)(ppiVar4 + 1) = param_1;
    ppiVar4[2] = param_2;
    FUN_0000d758();
    ppiVar6 = DAT_000937ac;
    while (ppiVar6 != (int **)0x0) {
      uVar5 = FUN_000003b6(param_1,(uint *)ppiVar6[1],0x40);
      if (uVar5 == 0) {
        if ((ppiVar6 == (int **)0x0) || (*ppiVar6[2] == 0)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (!bVar1) goto LAB_0000edd6;
        goto LAB_0000ee14;
      }
      ppiVar6 = (int **)*ppiVar6;
    }
    ppiVar6 = (int **)0x0;
LAB_0000edd6:
    *(int ***)ppiVar4 = DAT_000937ac;
    DAT_000937ac = ppiVar4;
    if (ppiVar6 != (int **)0x0) {
      if (ppiVar4 != ppiVar6) {
        ppiVar3 = (int **)*ppiVar4;
        while (ppiVar2 = ppiVar3, ppiVar2 != (int **)0x0) {
          if (ppiVar2 == ppiVar6) {
            *ppiVar4 = *ppiVar2;
            goto LAB_0000edfc;
          }
          ppiVar3 = (int **)*ppiVar2;
          ppiVar4 = ppiVar2;
        }
        goto LAB_0000ee14;
      }
      DAT_000937ac = (int **)*ppiVar6;
LAB_0000edfc:
      *(int ***)ppiVar6 = DAT_000937b0;
      DAT_000937b0 = ppiVar6;
    }
    FUN_0001a7ec();
    return;
  }
LAB_0000ee14:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int * FUN_0000eeb8(uint *param_1,uint *param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  undefined **ppuVar4;
  int iVar5;
  
  piVar3 = DAT_000937ac;
  if (param_1 != (uint *)0x0 && DAT_000937ac != (int *)0x0) {
    do {
      uVar1 = FUN_000003b6(param_1,(uint *)piVar3[1],0x40);
      if (uVar1 == 0) {
        if (piVar3 == (int *)0x0) {
          return (int *)0x0;
        }
        ppuVar4 = (undefined **)piVar3[2];
        if ((*ppuVar4 == (undefined *)0x0) && (param_3 != 0)) {
          return (int *)0x0;
        }
        if (DAT_000937c8 == 0) {
          return (int *)0x0;
        }
        iVar5 = piVar3[1];
        if (ppuVar4 == &PTR_PTR_s_marker_resource_00090390) {
          return (int *)0x0;
        }
        if ((((ppuVar4 != (undefined **)0x0) &&
             (puVar2 = FUN_00000378(param_2), puVar2 < FUN_0000003c + 4)) && (param_4 != 0)) &&
           (piVar3 = FUN_0000308c((int *)&DAT_0009376c), piVar3 != (int *)0x0)) {
          *piVar3 = 0;
          piVar3[4] = 0;
          piVar3[6] = 0;
          *(uint **)(piVar3 + 1) = param_2;
          piVar3[2] = iVar5;
          *(undefined ***)(piVar3 + 3) = ppuVar4;
          *(char *)(piVar3 + 4) = (char)param_3;
          piVar3[5] = 1;
          piVar3[7] = param_4;
          piVar3[8] = param_5;
          FUN_0000d758();
          *(undefined **)piVar3 = ppuVar4[4];
          *(int **)(ppuVar4 + 4) = piVar3;
          FUN_0001a7ec();
          return piVar3;
        }
                    // WARNING: Subroutine does not return
        FUN_00000060();
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
  }
  return (int *)0x0;
}



undefined4 FUN_0000ef84(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_000937c8;
  if (DAT_000937c8 != 0) {
    iVar1 = *(int *)(DAT_000937c8 + 0x1c);
  }
  if (DAT_000937c8 != 0 && iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x28);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



undefined4 FUN_0000ef94(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 in_r3;
  undefined4 uVar4;
  undefined4 local_10;
  
  iVar1 = DAT_000937c8;
  uVar4 = 0;
  if (DAT_000937c8 == 0) {
    return 0xffffffff;
  }
  pcVar3 = *(code **)(DAT_000937c8 + 4);
  iVar2 = DAT_000937c8;
  if (pcVar3 != (code *)0x0) {
    iVar2 = *(int *)(DAT_000937c8 + 8);
  }
  local_10 = in_r3;
  if (pcVar3 == (code *)0x0 || iVar2 == 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  iVar2 = (*pcVar3)(DAT_000937c8,&local_10);
  if (iVar2 == 0) {
    (**(code **)(iVar1 + 8))(local_10);
    if (*(code **)(iVar1 + 0xc) != (code *)0x0) {
      (**(code **)(iVar1 + 0xc))(iVar1,local_10);
    }
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}



int FUN_0000efa4(undefined **param_1,int param_2,undefined *param_3)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_1 == (undefined **)0x0) {
    return 2;
  }
  if (param_1 == &PTR_PTR_s_marker_resource_00090390) {
    return 1;
  }
  if ((*(code **)(*param_1 + 0x18) != (code *)0x0) &&
     (iVar1 = (**(code **)(*param_1 + 0x18))(param_1,param_2), iVar1 != 1)) {
    return iVar1;
  }
  if (param_2 == 2) {
    *param_3 = 0;
    puVar2 = *(undefined **)(*param_1 + 8);
  }
  else {
    if (param_2 < 3) {
      if (param_2 == 0) {
        *param_3 = 0;
        puVar2 = param_1[7];
      }
      else {
        if (param_2 != 1) goto LAB_0000f000;
        *param_3 = 0;
        puVar2 = param_1[0xd];
      }
    }
    else {
      if (param_2 != 0x400) {
        if (param_2 == 0x401) {
          *param_3 = 1;
          *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_1[2] + 8);
          return 0;
        }
LAB_0000f000:
        *param_3 = 3;
        *(undefined4 *)(param_3 + 4) = 0;
        return 1;
      }
      *param_3 = 1;
      puVar2 = *(undefined **)(*param_1 + 0x10);
    }
  }
  *(undefined **)(param_3 + 4) = puVar2;
  return 0;
}



void FUN_0000f02c(int param_1,int param_2,undefined *param_3)

{
  if (param_1 != 0) {
    FUN_0000efa4(*(undefined ***)(param_1 + 0xc),param_2,param_3);
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000f038(uint *param_1,undefined *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  
  if (param_1 != (uint *)0x0 && param_2 != (undefined *)0x0) {
    FUN_0000d758();
    FUN_0000d758();
    piVar3 = (int *)DAT_000937ac;
    while (piVar3 != (int *)0x0) {
      uVar1 = FUN_000003b6(param_1,(uint *)piVar3[1],0x40);
      if (uVar1 == 0) {
        if (piVar3 != (int *)0x0) {
          piVar3 = (int *)piVar3[2];
          iVar2 = *piVar3;
          if (iVar2 != 0) {
            piVar3 = (int *)0x0;
          }
          if (iVar2 != 0 || piVar3 != (int *)0x0) goto LAB_0000f0ae;
          goto LAB_0000f0cc;
        }
        break;
      }
      piVar3 = (int *)*piVar3;
    }
    piVar3 = FUN_0000308c((int *)&DAT_0009372c);
    if (piVar3 != (int *)0x0) {
      FUN_00000610(piVar3,0x48);
      *piVar3 = 0;
      piVar3[0xf] = 1;
      piVar3[0x10] = DAT_000937b8;
      FUN_0000ed80(param_1,piVar3);
LAB_0000f0ae:
      FUN_0001a7ec();
      if (piVar3 == (int *)0x0) {
        FUN_0001a7ec();
        puVar4 = FUN_00000378(param_1);
        (*(code *)param_2)(param_3,0,param_1,puVar4);
        return;
      }
      piVar3 = FUN_0000eeb8(param_1,(uint *)"Resource Available Callback",0,(int)param_2,param_3);
      if (piVar3 != (int *)0x0) {
        FUN_0001a7ec();
        return;
      }
    }
  }
LAB_0000f0cc:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000f110(code *param_1,code *param_2,code *param_3,code *param_4)

{
  code **ppcVar1;
  uint uVar2;
  code **ppcVar3;
  code *pcVar4;
  code **ppcVar5;
  undefined4 unaff_r4;
  int *piVar6;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  uint *puVar7;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 in_lr;
  
  if ((((param_1 != (code *)0x0) && (param_2 == (code *)0x0)) || (param_3 == (code *)0x0)) ||
     (ppcVar1 = (code **)FUN_0000308c((int *)&DAT_0009376c), ppcVar1 == (code **)0x0)) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  ppcVar1[4] = (code *)0x0;
  *ppcVar1 = param_3;
  ppcVar1[1] = param_4;
  ppcVar1[2] = param_2;
  ppcVar1[3] = param_1;
  ppcVar5 = (code **)0x0;
  pcVar4 = (code *)0x0;
  ppcVar3 = ppcVar1;
  if (ppcVar1 != (code **)0x0) {
    pcVar4 = ppcVar1[4];
    while ((pcVar4 < ppcVar1[3] &&
           (puVar7 = *(uint **)(ppcVar1[2] + (int)pcVar4 * 4), piVar6 = DAT_000937ac,
           puVar7 != (uint *)0x0 && DAT_000937ac != (int *)0x0))) {
      while (uVar2 = FUN_000003b6(puVar7,(uint *)piVar6[1],0x40), uVar2 != 0) {
        piVar6 = (int *)*piVar6;
        if (piVar6 == (int *)0x0) goto LAB_0000f1a0;
      }
      if ((piVar6 == (int *)0x0) || (*(int *)piVar6[2] == 0 || (int *)piVar6[2] == (int *)0x0))
      break;
      pcVar4 = ppcVar1[4] + 1;
      ppcVar1[4] = pcVar4;
    }
LAB_0000f1a0:
    ppcVar5 = (code **)ppcVar1[3];
    ppcVar3 = (code **)ppcVar1[4];
    if (ppcVar3 != ppcVar5) {
      ppcVar1[4] = (code *)((int)ppcVar3 + 1);
      FUN_0000f038(*(uint **)(ppcVar1[2] + (int)ppcVar3 * 4),(undefined *)0xf14d,(int)ppcVar1);
      return;
    }
    pcVar4 = ppcVar1[2];
    if (ppcVar1 != (code **)0x0) {
      (**ppcVar1)(ppcVar1[1]);
      FUN_000031cc((int)&DAT_0009376c,ppcVar1);
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060(ppcVar3,0,pcVar4,ppcVar5,unaff_r4,unaff_r5,unaff_r6,unaff_r7,unaff_r8,in_lr);
}



undefined * FUN_0000f1e4(void)

{
  return &DAT_00090660;
}



void FUN_0000f1ec(void)

{
  return;
}



void FUN_0000f1ee(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *unaff_r6;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x14) != 0x200) {
    *(undefined4 *)(param_1 + (*(uint *)(param_1 + 0x28) ^ 1) * 8 + 0x18) = 0;
    iVar2 = *(int *)(param_1 + *(int *)(param_1 + 0x28) * 8 + 0x18);
    if (iVar2 != 0) {
      iVar2 = 1;
    }
                    // WARNING: Could not recover jumptable at 0x0000f21c. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(param_1 + 0x34))(param_1,iVar2);
    return;
  }
  if (param_1 != 0) {
    unaff_r6 = *(int **)(param_1 + 0xc);
  }
  if (param_1 != 0 && unaff_r6 != (int *)0x0) {
    uVar4 = *(uint *)(*unaff_r6 + 8);
    *(undefined4 *)(param_1 + (*(uint *)(param_1 + 0x28) ^ 1) * 8 + 0x18) = 0;
    FUN_0000d758();
    if (*(int *)(param_1 + *(int *)(param_1 + 0x28) * 8 + 0x18) == unaff_r6[0xd]) {
      piVar1 = (int *)unaff_r6[3];
      while (piVar1 != (int *)0x0) {
        if (((piVar1[5] == 0x200) && (piVar1 != (int *)param_1)) &&
           (uVar3 = piVar1[piVar1[10] * 2 + 6],
           (uVar3 == 0 || uVar3 <= uVar4) && (uVar3 != 0 && uVar4 != uVar3))) {
          uVar4 = uVar3;
        }
        piVar1 = (int *)*piVar1;
      }
      unaff_r6[0xd] = uVar4;
    }
    FUN_0001a7ec();
                    // WARNING: Could not recover jumptable at 0x0000f2a4. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(param_1 + 0x34))
              (param_1,(uint)(*(int *)(param_1 + (*(uint *)(param_1 + 0x28) ^ 1) * 8 + 0x18) !=
                             *(int *)(param_1 + *(uint *)(param_1 + 0x28) * 8 + 0x18)));
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0000f2a8(undefined4 param_1,ushort *param_2,uint param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *local_20;
  
  if (*(char *)((int)param_2 + 3) == '\x02') {
    return;
  }
  local_20 = *(undefined4 **)(&DAT_00095d40 + param_3 * 4);
  if (local_20 == (undefined4 *)0x0) {
    FUN_0000fe18(0x34,(int *)&local_20);
    *local_20 = param_1;
    iVar3 = FUN_00013d80(1);
    local_20[10] = iVar3;
    if (iVar3 == 0) goto LAB_0000f37a;
    iVar3 = FUN_00013d80(0x1a);
    local_20[0xb] = iVar3;
    if (iVar3 == 0) goto LAB_0000f37a;
    iVar3 = FUN_00013d80(0x1b);
    local_20[0xc] = iVar3;
    if (iVar3 == 0) goto LAB_0000f37a;
    iVar3 = FUN_00013d80(0x1c);
    puVar2 = local_20;
    local_20[9] = iVar3;
    if (iVar3 == 0) goto LAB_0000f37a;
    local_20[1] = 0xe;
    uVar4 = 0;
    FUN_000005bc((uint *)((int)local_20 + 0x16),0xd,99);
    do {
      iVar3 = puVar2[9];
      bVar1 = *(byte *)(iVar3 + uVar4);
      if (bVar1 < 0xd) {
        iVar3 = (int)puVar2 + (uint)bVar1;
      }
      if (bVar1 < 0xd) {
        *(undefined *)(iVar3 + 0x16) = (char)uVar4;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 0xe);
    iVar3 = FUN_0000f948(param_3);
    if (iVar3 == 8) {
      *(undefined *)((int)local_20 + 0x22) = 2;
    }
    FUN_00000610(local_20 + 2,0xe);
    *(undefined4 **)(&DAT_00095d40 + param_3 * 4) = local_20;
    if (local_20 == (undefined4 *)0x0) {
      return;
    }
  }
  uVar4 = (uint)*(ushort *)local_20[10];
  if ((uVar4 <= *param_2) &&
     (uVar4 = (*param_2 - uVar4) / (uint)((ushort *)local_20[10])[1], uVar4 < 0xe)) {
    *(undefined *)((int)local_20 + uVar4 + 8) = *(undefined *)((int)param_2 + 3);
    return;
  }
LAB_0000f37a:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 FUN_0000f38c(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 7) {
    uVar1 = *(undefined4 *)(&DAT_00095d40 + param_1 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



uint FUN_0000f3a0(uint param_1)

{
  if ((param_1 < 7) && (*(int *)(&DAT_00095d40 + param_1 * 4) != 0)) {
    return *(uint *)(*(int *)(&DAT_00095d40 + param_1 * 4) + 4) & 0xff;
  }
  return 0;
}



int FUN_0000f3bc(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  short *psVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  
  puVar2 = (undefined4 *)FUN_0000f38c(param_1);
  bVar5 = 0;
  uVar6 = 0;
  if ((puVar2 == (undefined4 *)0x0) || (0xc < param_2)) {
    iVar7 = 0x16;
  }
  else {
    bVar1 = *(byte *)((int)puVar2 + param_2 + 0x16);
    uVar6 = (uint)bVar1;
    if (((bVar1 == 99) || (0xd < bVar1)) || (*(char *)((int)puVar2 + uVar6 + 8) == '\0')) {
      iVar7 = 0x2f;
    }
    else {
      psVar4 = (short *)puVar2[10];
      if (param_3 == 1) {
        bVar5 = 0xff;
      }
      iVar7 = FUN_0000f74c((byte)*(undefined4 *)*puVar2,
                           psVar4[1] * (ushort)bVar1 + *psVar4 + psVar4[3],1,bVar5,0);
      if (iVar7 == 0) {
        if (DAT_00091e5c == 0) {
          return 0;
        }
        uVar3 = 0x215;
        goto LAB_0000f436;
      }
    }
  }
  uVar3 = 0x217;
  param_3 = iVar7;
LAB_0000f436:
  FUN_000065ec(uVar3,param_1,6,uVar6,param_3);
  return iVar7;
}



int FUN_0000f444(uint param_1,int param_2,undefined4 *param_3,uint param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined uVar4;
  undefined4 *puVar5;
  uint local_18;
  
  puVar5 = param_3;
  local_18 = param_4;
  piVar2 = (int *)FUN_0000f38c(param_1);
  local_18 = local_18 & 0xffffff00;
  if (piVar2 != (int *)0x0) {
    puVar5 = (undefined4 *)*piVar2;
  }
  if ((piVar2 == (int *)0x0 || puVar5 == (undefined4 *)0x0) || (param_2 != 0)) {
    return 0x16;
  }
  if (param_3 == (undefined4 *)0x0) {
    return 0x72;
  }
  bVar1 = *(byte *)((int)piVar2 + 0x16);
  if (bVar1 != 99) {
    if (bVar1 < 0xe) {
      param_4 = piVar2[1];
    }
    if ((bVar1 < 0xe && (uint)bVar1 < param_4) && (*(char *)((int)piVar2 + (uint)bVar1 + 8) == '\f')
       ) {
      iVar3 = FUN_0000f65c((byte)*puVar5,
                           ((short *)piVar2[10])[1] * (ushort)bVar1 +
                           *(short *)piVar2[10] + *(short *)piVar2[0xb],(undefined *)&local_18,0);
      if (iVar3 == 0) {
        if ((local_18 & 0x80) == 0) {
          *(undefined *)param_3 = 0;
          return 0;
        }
        uVar4 = 1;
      }
      else {
        uVar4 = 2;
      }
      *(undefined *)param_3 = uVar4;
      return iVar3;
    }
  }
  return 0x3b;
}



int FUN_0000f4c4(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  short *psVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  
  puVar2 = (undefined4 *)FUN_0000f38c(param_1);
  bVar5 = 0;
  uVar6 = 0;
  if ((puVar2 == (undefined4 *)0x0) || (0xc < param_2)) {
    iVar7 = 0x16;
  }
  else {
    bVar1 = *(byte *)((int)puVar2 + param_2 + 0x16);
    uVar6 = (uint)bVar1;
    if (((bVar1 == 99) || (0xd < bVar1)) || (*(char *)((int)puVar2 + uVar6 + 8) == '\0')) {
      iVar7 = 0x2f;
    }
    else {
      psVar4 = (short *)puVar2[10];
      if (param_3 == 1) {
        bVar5 = 0xff;
      }
      iVar7 = FUN_0000f74c((byte)*(undefined4 *)*puVar2,
                           psVar4[1] * (ushort)bVar1 + *psVar4 + psVar4[3],0x80,bVar5,0);
      if (iVar7 == 0) {
        if (DAT_00091e5c == 0) {
          return 0;
        }
        uVar3 = 0x214;
        goto LAB_0000f53e;
      }
    }
  }
  uVar3 = 0x216;
  param_3 = iVar7;
LAB_0000f53e:
  FUN_000065ec(uVar3,param_1,6,uVar6,param_3);
  return iVar7;
}



uint FUN_0000f54c(uint param_1,int param_2,uint param_3)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int extraout_r1;
  int iVar4;
  uint uVar5;
  uint local_10;
  
  uVar5 = 0;
  local_10 = param_3;
  piVar2 = (int *)FUN_0000f38c(param_1);
  iVar4 = extraout_r1;
  if (piVar2 != (int *)0x0) {
    iVar4 = *piVar2;
  }
  if ((piVar2 == (int *)0x0 || iVar4 == 0) || (param_2 != 1)) {
    return 0x16;
  }
  bVar1 = *(byte *)((int)piVar2 + 0x17);
  if (bVar1 != 99) {
    if (bVar1 < 0xe) {
      param_3 = piVar2[1];
    }
    if ((bVar1 < 0xe && (uint)bVar1 < param_3) &&
       (*(char *)((int)piVar2 + (uint)bVar1 + 8) == '\x01')) {
      if (0x7ff < local_10) {
        uVar5 = 0x16;
        local_10 = 0x7ff;
      }
      uVar3 = FUN_0000f724((byte)*(undefined4 *)*piVar2,
                           (ushort)bVar1 * ((short *)piVar2[10])[1] +
                           *(short *)piVar2[10] + *(short *)piVar2[0xc],4,(undefined *)&local_10,0);
      return uVar3 | uVar5;
    }
  }
  return 0x3b;
}



undefined4 FUN_0000f5c8(void)

{
  int iVar1;
  
  iVar1 = FUN_000066cc();
  if (iVar1 != 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  DAT_000917a4 = 1;
  return 0;
}



int FUN_0000f5e4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0000f910();
  return DAT_000917a8 + (param_1 * iVar1 + param_2) * 0xc;
}



void FUN_0000f604(void)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = 0;
  iVar5 = 0;
  uVar1 = FUN_0000f910();
  FUN_0000fe18(uVar1 * 0x54,&DAT_000917a8);
  do {
    uVar4 = 0;
    if (uVar1 != 0) {
      do {
        piVar2 = (int *)(DAT_000917a8 + iVar5 * 0xc);
        *(undefined *)(piVar2 + 2) = 0;
        piVar2[1] = uVar3;
        FUN_0000f970(uVar3,uVar4 & 0xff,piVar2);
        uVar4 = uVar4 + 1;
        iVar5 = iVar5 + 1;
      } while (uVar4 < uVar1);
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 7);
  return;
}



undefined4 FUN_0000f65c(byte param_1,ushort param_2,undefined *param_3,undefined4 param_4)

{
  int iVar1;
  int local_18 [2];
  
  local_18[0] = 0;
  if ((DAT_000917a4 == 1) &&
     (iVar1 = FUN_00006730(param_1,param_4,param_2,param_3,(uint)DAT_000917a4,local_18), iVar1 == 0)
     ) {
    return 0;
  }
  return 9;
}



undefined4
FUN_0000f694(byte param_1,ushort param_2,uint param_3,undefined *param_4,undefined4 param_5)

{
  int iVar1;
  int local_10;
  
  local_10 = 0;
  if ((DAT_000917a4 == '\x01') &&
     (iVar1 = FUN_00006730(param_1,param_5,param_2,param_4,param_3,&local_10), iVar1 == 0)) {
    return 0;
  }
  return 9;
}



undefined4 FUN_0000f6c8(byte param_1,uint param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined auStack24 [12];
  
  if ((DAT_000917a4 == '\x01') &&
     (iVar1 = FUN_00006750((uint)param_1,param_2 >> 8,param_3,param_4,param_5,auStack24), iVar1 == 0
     )) {
    return 0;
  }
  return 9;
}



undefined4 FUN_0000f6f8(byte param_1,ushort param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack16;
  undefined4 uStack12;
  
  if ((DAT_000917a4 == 1) &&
     (uStack16 = param_3, uStack12 = param_4,
     iVar1 = FUN_00006800(param_1,param_4,param_2,(undefined *)&uStack16,(uint)DAT_000917a4),
     iVar1 == 0)) {
    return 0;
  }
  return 9;
}



undefined4
FUN_0000f724(byte param_1,ushort param_2,uint param_3,undefined *param_4,undefined4 param_5)

{
  int iVar1;
  
  if ((DAT_000917a4 == '\x01') &&
     (iVar1 = FUN_00006800(param_1,param_5,param_2,param_4,param_3), iVar1 == 0)) {
    return 0;
  }
  return 9;
}



undefined4 FUN_0000f74c(byte param_1,ushort param_2,byte param_3,byte param_4,undefined4 param_5)

{
  int iVar1;
  byte local_28 [4];
  int local_24;
  
  local_24 = 1;
  local_28[0] = 0;
  if (DAT_000917a4 == '\x01') {
    iVar1 = FUN_00006730(param_1,param_5,param_2,local_28,1,&local_24);
    if (iVar1 != 0) {
      return 0;
    }
    local_28[0] = local_28[0] & ~param_3 | param_4 & param_3;
    iVar1 = FUN_00006800(param_1,param_5,param_2,local_28,1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 9;
}



undefined8 FUN_0000f7b4(uint param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_000001b0((uint)((ulonglong)param_1 * 19200000),
                       param_2 * 19200000 + (int)((ulonglong)param_1 * 19200000 >> 0x20),1000000,0);
  return uVar1;
}



undefined8 FUN_0000f7dc(uint param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_000001b0((uint)((ulonglong)param_1 * 1000000),
                       param_2 * 1000000 + (int)((ulonglong)param_1 * 1000000 >> 0x20),19200000,0);
  return uVar1;
}



uint FUN_0000f804(uint *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = 3;
  bVar5 = *(char *)(param_1[2] + param_3 * 8 + 6) == '\x1c';
  uVar3 = (uint)bVar5;
  if (bVar5) {
    uVar4 = 2;
  }
  uVar1 = FUN_00010216((int *)param_1,param_2,param_3,uVar3);
  uVar2 = FUN_00010286(param_1,param_2,param_3,uVar3,0);
  uVar4 = FUN_00010372((int *)param_1,param_2,param_3,uVar3,uVar4);
  uVar3 = FUN_00010306((int)param_1,param_2,param_3,uVar3,0xf8b9,param_4);
  return uVar3 | uVar4 | uVar2 | uVar1;
}



uint FUN_0000f878(uint *param_1,undefined4 *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)(*(char *)(param_1[2] + param_3 * 8 + 6) == '\x1c');
  uVar1 = FUN_00010216((int *)param_1,param_2,param_3,uVar2);
  uVar2 = FUN_00010286(param_1,param_2,param_3,uVar2,param_4);
  return uVar2 | uVar1;
}



undefined4 FUN_0000f8b8(uint param_1,byte param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  
  if (4 < DAT_000934cc) {
    DAT_000934cc = 0;
  }
  uVar2 = FUN_0001a750();
  iVar1 = (uint)DAT_000934cc * 0x10;
  *(undefined4 *)(&DAT_00095fd8 + iVar1) = uVar2;
  *(undefined4 *)(&DAT_00095fdc + iVar1) = extraout_r1;
  *(uint *)(&DAT_00095fe0 + iVar1) = param_1 >> 0x10;
  *(uint *)(&DAT_00095fe4 + iVar1) = param_1 & 0xffff;
  DAT_000934cc = DAT_000934cc + 1;
  DAT_000934d0 = DAT_000934d0 + 1;
  FUN_0000f6f8((byte)(param_1 >> 0x10),(short)(param_1 & 0xffff) * 0x100 + 0x14,(uint)param_2,0);
  return 0;
}



undefined4 FUN_0000f910(void)

{
  return 2;
}



undefined4 FUN_0000f914(uint param_1,undefined4 *param_2)

{
  if (((param_2 != (undefined4 *)0x0) && (DAT_000917f0 != '\0')) && (param_1 < 7)) {
    *param_2 = (&DAT_00095758)[param_1 * 3];
    param_2[1] = (&DAT_0009575c)[param_1 * 3];
    param_2[2] = (&DAT_00095760)[param_1 * 3];
    return 0;
  }
  return 0x16;
}



undefined4 FUN_0000f948(uint param_1)

{
  if ((DAT_000917f0 != '\0') && (param_1 < 7)) {
    return (&DAT_00095758)[param_1 * 3];
  }
  return 0x7fffffff;
}



undefined4 FUN_0000f970(uint param_1,uint param_2,int *param_3)

{
  if ((((param_3 != (int *)0x0) && (DAT_000917f0 != '\0')) && (param_2 < 2)) && (param_1 < 7)) {
    *param_3 = (&DAT_000957ac)[param_1] + param_2;
    return 0;
  }
  return 0x16;
}



// WARNING (jumptable): Heritage AFTER dead removal. Example location: s0xffffffe0 : 0x0000fac0
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0000fa44(undefined4 param_1,ushort *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  bool bVar5;
  undefined4 *local_20;
  undefined local_1c [4];
  
  local_1c[0] = 0;
  local_20 = *(undefined4 **)(&DAT_00095d5c + param_3 * 4);
  if (*(undefined4 **)(&DAT_00095d5c + param_3 * 4) == (undefined4 *)0x0) {
    FUN_0000fe18(0x18,(int *)&local_20);
    *local_20 = param_1;
    iVar2 = FUN_00013d80(3);
    local_20[1] = iVar2;
    if (iVar2 == 0) goto LAB_0000fc04;
    iVar2 = FUN_00013da4(0x67,param_3);
    local_20[2] = iVar2;
    if (iVar2 == 0) goto LAB_0000fc04;
    FUN_0000fe18(iVar2 << 3,local_20 + 3);
    *(ushort *)(local_20[3] + 4) = *param_2;
    FUN_0000fe18(local_20[2],local_20 + 5);
    FUN_0000fe18(local_20[2],local_20 + 4);
    *(undefined4 **)(&DAT_00095d5c + param_3 * 4) = local_20;
    if (local_20 == (undefined4 *)0x0) {
      return;
    }
  }
  if ((((uint)*param_2 < (uint)*(ushort *)(local_20[3] + 4)) ||
      (uVar4 = ((uint)*param_2 - (uint)*(ushort *)(local_20[3] + 4)) /
               (uint)*(ushort *)(local_20[1] + 2), (uint)local_20[2] <= uVar4)) ||
     (*(undefined *)(local_20[5] + uVar4) = *(undefined *)((int)param_2 + 3),
     (uint)local_20[2] <= uVar4)) goto LAB_0000fc04;
  iVar2 = uVar4 * 8 + 6;
  *(undefined *)(local_20[3] + iVar2) = *(undefined *)(param_2 + 1);
  *(ushort *)(local_20[3] + uVar4 * 8 + 4) = *param_2;
  bVar5 = *(char *)(local_20[3] + iVar2) == '!';
  puVar3 = local_20;
  if (bVar5) {
    puVar3 = (undefined4 *)(uVar4 * 8 + 7);
  }
  if (bVar5) {
    *(undefined *)(local_20[3] + (int)puVar3) = 0;
  }
  else {
    iVar2 = FUN_0000f65c((byte)*(undefined4 *)*puVar3,*param_2 + *(short *)(puVar3[1] + 0xc),
                         local_1c,0);
    if (iVar2 == 0) {
      *(undefined *)(local_20[3] + uVar4 * 8 + 7) = local_1c[0];
    }
    else {
      *(undefined *)(local_20[3] + uVar4 * 8 + 7) = 0xff;
    }
  }
  iVar2 = 0;
  if (*(char *)(param_2 + 1) != '\x04') {
    if (*(char *)(param_2 + 1) == '!') {
      bVar1 = *(byte *)((int)param_2 + 3);
      if (bVar1 != 0xb) {
        switch(bVar1) {
        case 0:
          goto switchD_0000fb68_caseD_0;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
          goto switchD_0000fbc4_caseD_1;
        case 8:
        case 9:
        case 10:
          break;
        default:
          if (bVar1 != 0x29) {
            if (bVar1 < 0x2a) {
              if (bVar1 == 0x14) {
switchD_0000fbc4_caseD_1:
                iVar2 = 0x27;
                goto LAB_0000fbb0;
              }
              if (bVar1 < 0x15) {
                if (bVar1 != 0xc) {
                  if (bVar1 != 0x13) goto switchD_0000fb68_caseD_0;
                  goto switchD_0000fbc4_caseD_1;
                }
              }
              else {
                if (bVar1 == 0x15) goto switchD_0000fbc4_caseD_1;
                if (bVar1 != 0x28) goto switchD_0000fb68_caseD_0;
              }
            }
            else {
              if ((bVar1 != 0x2a && bVar1 != 0x2b) && (bVar1 != 0x2c && bVar1 != 0x2d))
              goto switchD_0000fb68_caseD_0;
            }
          }
        }
      }
      iVar2 = 0x25;
      goto LAB_0000fbb0;
    }
    goto switchD_0000fb68_caseD_0;
  }
  bVar1 = *(byte *)((int)param_2 + 3);
  if (bVar1 == 10) {
switchD_0000fb68_caseD_8:
    iVar2 = 0xc;
    goto LAB_0000fbb0;
  }
  switch(bVar1) {
  case 0:
    break;
  case 1:
  case 2:
  case 3:
    iVar2 = FUN_00013d80(9);
    break;
  case 4:
  case 6:
    iVar2 = 10;
    goto LAB_0000fbb0;
  case 5:
  case 7:
    iVar2 = 0xb;
LAB_0000fbb0:
    iVar2 = FUN_00013d80(iVar2);
    break;
  case 8:
  case 9:
    goto switchD_0000fb68_caseD_8;
  default:
    if (bVar1 == 0x28) goto switchD_0000fb68_caseD_8;
    if (bVar1 < 0x29) {
      if (bVar1 == 0xb || bVar1 == 0xc) goto switchD_0000fb68_caseD_8;
      if (bVar1 == 0x10 || bVar1 == 0x18) {
        iVar2 = 0xd;
        goto LAB_0000fbb0;
      }
    }
    else {
      if ((bVar1 == 0x29 || bVar1 == 0x2a) || (bVar1 == 0x2b || bVar1 == 0x2c))
      goto switchD_0000fb68_caseD_8;
    }
  }
switchD_0000fb68_caseD_0:
  *(int *)(local_20[3] + uVar4 * 8) = iVar2;
  if (iVar2 != 0) {
    return;
  }
LAB_0000fc04:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 FUN_0000fc24(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 7) {
    uVar1 = *(undefined4 *)(&DAT_00095d5c + param_1 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



uint FUN_0000fc38(uint param_1)

{
  if ((param_1 < 7) && (*(int *)(&DAT_00095d5c + param_1 * 4) != 0)) {
    return *(uint *)(*(int *)(&DAT_00095d5c + param_1 * 4) + 8) & 0xff;
  }
  return 0;
}



uint FUN_0000fc54(uint param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  bool bVar7;
  
  uVar4 = 0;
  puVar2 = (undefined4 *)FUN_0000fc24(param_1);
  uVar6 = 0;
  if (puVar2 == (undefined4 *)0x0) {
    uVar4 = 0x16;
  }
  else {
    if (param_2 < (uint)puVar2[2]) {
      if (param_3 < 5) {
        uVar6 = (uint)*(byte *)(puVar2[3] + param_2 * 8 + 6);
        uVar1 = *(short *)(puVar2[1] + 6) + *(short *)(puVar2[3] + param_2 * 8 + 4);
        if (param_3 == 0) {
          if (*(char *)(puVar2[4] + param_2) != '\0') {
            puVar5 = (undefined4 *)*puVar2;
            if (puVar5 == (undefined4 *)0x0) {
LAB_0000fd7a:
                    // WARNING: Subroutine does not return
              FUN_00000060();
            }
            uVar4 = FUN_0000f74c((byte)*puVar5,uVar1,0x40,0x40,0);
            thunk_FUN_0000b1ac(100);
            uVar3 = FUN_0000f74c((byte)*puVar5,uVar1,0x60,0,0);
            uVar3 = uVar3 | uVar4;
            bVar7 = uVar3 == 0;
            if (bVar7) {
              uVar3 = puVar2[4];
            }
            if (bVar7) {
              *(undefined *)(uVar3 + param_2) = 0;
            }
          }
          uVar4 = FUN_0000f74c((byte)*(undefined4 *)*puVar2,uVar1,0x80,0,0);
LAB_0000fd6e:
          if (uVar4 != 0) goto LAB_0000fd9a;
        }
        else {
          if (param_3 != 1) {
            if (param_3 != 4) {
              uVar4 = 0xf;
              goto LAB_0000fd9a;
            }
            if (*(char *)(puVar2[4] + param_2) != '\0') {
              puVar5 = (undefined4 *)*puVar2;
              if (puVar5 == (undefined4 *)0x0) goto LAB_0000fd7a;
              uVar4 = FUN_0000f74c((byte)*puVar5,uVar1,0x40,0x40,0);
              thunk_FUN_0000b1ac(100);
              uVar3 = FUN_0000f74c((byte)*puVar5,uVar1,0x60,0,0);
              uVar3 = uVar3 | uVar4;
              bVar7 = uVar3 == 0;
              if (bVar7) {
                uVar3 = puVar2[4];
              }
              if (bVar7) {
                *(undefined *)(uVar3 + param_2) = 0;
              }
            }
            uVar4 = FUN_0000f74c((byte)*(undefined4 *)*puVar2,uVar1,0x80,0x80,0);
            goto LAB_0000fd6e;
          }
          if (*(char *)(puVar2[4] + param_2) == '\0') {
            uVar4 = FUN_0000f74c((byte)*(undefined4 *)*puVar2,uVar1,0x20,0x20,0);
            if (uVar4 != 0) goto LAB_0000fd9a;
            *(undefined *)(puVar2[4] + param_2) = 1;
          }
        }
        if (DAT_00091e5c == 0) {
          return uVar4;
        }
        uVar3 = 0x206;
        goto LAB_0000fdc4;
      }
      uVar4 = 0x24;
    }
    else {
      uVar4 = 0x2f;
    }
  }
LAB_0000fd9a:
  uVar3 = 0x20c;
  param_3 = uVar4;
LAB_0000fdc4:
  FUN_000065ec(uVar3,param_1,uVar6,param_2,param_3);
  return uVar4;
}



void FUN_0000fe18(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    iVar1 = FUN_00000154(param_1);
    *param_2 = iVar1;
    if (iVar1 != 0) {
      FUN_000005cc(iVar1,param_1);
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_0000fe38(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_000917b0;
  if (DAT_000917b0 != 0) {
    iVar1 = DAT_000917ac;
  }
  if (DAT_000917b0 != 0 && iVar1 != 0) {
    iVar1 = DAT_000917b4;
    if (DAT_000917b4 != 0) {
      iVar1 = DAT_000917b8;
    }
    if (DAT_000917b4 != 0 && iVar1 != 0) {
      DAT_000917bc = 0;
      iVar1 = FUN_0000ff04(param_1[3],param_1[5],0);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_0000ff04(param_1[2],param_1[4],1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = FUN_00010080((int)param_1,DAT_000917ac,DAT_000917b0,DAT_000917b8,DAT_000917b4,
                           (uint *)&DAT_000917bc);
      iVar1 = DAT_000917b0;
      if (iVar2 != 0) {
        return iVar2;
      }
      if (DAT_000917bc != 0) {
        *(int *)(DAT_000917b0 + 0x4c) = DAT_000917bc;
        iVar2 = DAT_000917ac;
        *param_1 = iVar1;
        param_1[1] = iVar2;
        return 0;
      }
      return 0x16;
    }
  }
  return 0x72;
}



void FUN_0000fec4(void)

{
  int iVar1;
  
  iVar1 = DAT_000917b0;
  if (DAT_000917b0 != 0) {
    iVar1 = DAT_000917ac;
  }
  if (DAT_000917b0 == 0 || iVar1 == 0) {
    DAT_000917b0 = FUN_00013dd0(0x12d);
    DAT_000917ac = FUN_00013dd0(0x12e);
    DAT_000917b4 = FUN_00013dd0(0x12f);
    DAT_000917b8 = FUN_00013dd0(0x130);
    return;
  }
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_0000ff04(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint local_30;
  byte local_2c [4];
  uint auStack40 [2];
  
  local_30 = 0;
  local_2c[0] = 0;
  if (param_3 < 2) {
    piVar8 = (int *)(DAT_000917b4 + param_3 * 0xc);
    uVar9 = *(uint *)(DAT_000917b8 + param_3 * 0xc);
    iVar10 = *(int *)(DAT_000917b8 + param_3 * 0xc + 4);
    if ((uVar9 != 0 && iVar10 != 0) && piVar8 != (int *)0x0) {
      iVar1 = FUN_00010b04(uVar9,iVar10,param_2,&local_30);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = 0x10;
      uVar3 = 0;
      uVar5 = 8;
      uVar11 = ((param_2 - param_1) + 0x5db) / 0x5dc + 0x32;
      uVar7 = 0;
      if (uVar11 < 0x3e9) {
        do {
          uVar4 = (ushort)uVar5;
          if ((uint)*(ushort *)(&DAT_000917c0 + uVar5 * 2) == uVar11) break;
          if ((uint)*(ushort *)(&DAT_000917c0 + uVar5 * 2) < uVar11) {
            if (uVar7 == 3) {
              uVar4 = uVar4 + 1;
              break;
            }
          }
          else {
            uVar2 = uVar5;
            uVar5 = uVar3;
            if (uVar7 == 3) break;
          }
          uVar6 = uVar2 + uVar5 >> 1;
          uVar4 = (ushort)uVar6;
          uVar7 = uVar7 + 1;
          uVar3 = uVar5;
          uVar5 = uVar6;
        } while (uVar7 < 4);
        uVar2 = (uint)uVar4;
      }
      else {
        uVar2 = 0xf;
      }
      if (DAT_000917bc < uVar2) {
        DAT_000917bc = uVar2;
      }
      iVar1 = FUN_00010b04(uVar9,iVar10,param_1,auStack40);
      if (iVar1 == 0) {
        *(uint *)(DAT_000917ac + *piVar8 * 0x10 + 8) = auStack40[0];
        *(uint *)(DAT_000917b0 + piVar8[1] * 0x10 + 8) = local_30;
        iVar10 = FUN_000136b8(uVar9,iVar10,local_2c);
        if (iVar10 == 0) {
          *(uint *)(DAT_000917b0 + piVar8[2] * 0x10 + 8) = (uint)local_2c[0];
          return 0;
        }
        return iVar10;
      }
      return iVar1;
    }
  }
  return 0x16;
}



uint FUN_0001001c(int param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0;
  uVar3 = 8;
  uVar1 = ((param_2 - param_1) + 0x5dbU) / 0x5dc + 0x32;
  uVar6 = 0x10;
  uVar4 = 0;
  if (1000 < uVar1) {
    return 0xf;
  }
  do {
    uVar2 = (ushort)uVar3;
    if ((uint)*(ushort *)(&DAT_000917c0 + uVar3 * 2) == uVar1) break;
    if ((uint)*(ushort *)(&DAT_000917c0 + uVar3 * 2) < uVar1) {
      uVar5 = uVar3;
      if (uVar4 == 3) {
        uVar2 = uVar2 + 1;
        break;
      }
    }
    else {
      uVar6 = uVar3;
      if (uVar4 == 3) break;
    }
    uVar3 = uVar6 + uVar5 >> 1;
    uVar2 = (ushort)uVar3;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 4);
  return (uint)uVar2;
}



int FUN_00010080(int param_1,int param_2,int param_3,int param_4,int param_5,uint *param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined auStack88 [4];
  int local_54;
  undefined4 local_4c;
  undefined local_48 [4];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined auStack56 [8];
  undefined4 local_30;
  
  local_44 = 0;
  local_4c = 0;
  local_48[0] = 0;
  local_30 = 0;
  local_40 = 0;
  if ((param_3 == 0 || param_2 == 0) || ((param_5 == 0 || param_4 == 0) || param_6 == (uint *)0x0))
  {
    iVar6 = 0x72;
  }
  else {
    local_3c = *(undefined4 *)(param_1 + 8);
    uVar4 = *(uint *)(param_1 + 0x10);
    iVar6 = *(int *)(param_4 + 0x18);
    local_54 = *(int *)(param_4 + 0x1c);
    if (iVar6 == 0 || local_54 == 0) {
      return 0;
    }
    if ((int *)(param_5 + 0x18) != (int *)0x0) {
      iVar1 = FUN_00013708(iVar6,local_54,auStack88 + 0xc,auStack88[0]);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = *(uint *)(auStack88 + 0xc);
      if (uVar2 <= uVar4) {
LAB_000101e2:
                    // WARNING: Subroutine does not return
        FUN_00000060();
      }
      iVar1 = FUN_00010b04(iVar6,*(undefined4 *)(auStack88 + 4),uVar2,auStack88 + 0x14,auStack88[0])
      ;
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = *(int *)(param_4 + 0x14) + *(int *)(auStack88 + 0x1c);
      uVar4 = *(uint *)(param_4 + 0x20);
      if (*(uint *)(param_4 + 0x20) < uVar2) {
        uVar4 = uVar2;
      }
      uVar2 = FUN_0001001c(uVar4,*(undefined4 *)(auStack88 + 0xc),auStack88[0]);
      if (uVar2 <= *param_6) {
        uVar2 = *param_6;
      }
      *param_6 = uVar2;
      iVar1 = FUN_00010b04(iVar6,*(undefined4 *)(auStack88 + 4),uVar4,auStack88 + 0x20,auStack88[0])
      ;
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = *(int *)(param_5 + 0x18);
      if (iVar1 != 0xff) {
        *(undefined4 *)(param_2 + iVar1 * 0x10 + 8) = *(undefined4 *)(auStack88 + 0x20);
      }
      if (*(int *)(param_5 + 0x1c) != 0xff) {
        *(undefined4 *)(param_3 + *(int *)(param_5 + 0x1c) * 0x10 + 8) =
             *(undefined4 *)(auStack88 + 0x14);
      }
      iVar6 = FUN_000136b8(iVar6,*(undefined4 *)(auStack88 + 4),auStack88 + 0x10,auStack88[0]);
      if (iVar6 != 0) {
        return iVar6;
      }
      if (*(int *)(param_5 + 0x20) != 0xff) {
        *(uint *)(param_3 + *(int *)(param_5 + 0x20) * 0x10 + 8) = (uint)(byte)auStack88[0x10];
      }
      uVar5 = *(undefined4 *)(param_4 + 0x24);
      uVar3 = *(undefined4 *)(param_4 + 0x28);
      if (param_5 != -0x24) {
        iVar6 = FUN_00013708(uVar5,uVar3,auStack88 + 0x28,auStack88[0]);
        if (iVar6 != 0) {
          return iVar6;
        }
        iVar6 = *(int *)(auStack88 + 0x28);
        if (iVar6 != 0) {
          iVar6 = FUN_00010b04(uVar5,uVar3,iVar6,auStack88 + 0x18,auStack88[0]);
          if (iVar6 != 0) {
            return iVar6;
          }
          if (*(int *)(param_5 + 0x28) != 0xff) {
            *(undefined4 *)(param_3 + *(int *)(param_5 + 0x28) * 0x10 + 8) =
                 *(undefined4 *)(auStack88 + 0x18);
            return 0;
          }
          return 0;
        }
        goto LAB_000101e2;
      }
    }
    iVar6 = 0x16;
  }
  return iVar6;
}



void FUN_000101e8(undefined4 param_1,int param_2)

{
  undefined4 *local_18;
  
  local_18 = *(undefined4 **)(&DAT_00095d78 + param_2 * 4);
  if (local_18 != (undefined4 *)0x0) {
    return;
  }
  FUN_0000fe18(4,(int *)&local_18);
  *local_18 = param_1;
  *(undefined4 **)(&DAT_00095d78 + param_2 * 4) = local_18;
  return;
}



void FUN_00010214(void)

{
  return;
}



int FUN_00010216(int *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_3 < (uint)param_1[1]) {
    bVar1 = *(byte *)(param_1[2] + param_3 * 8 + 6);
    uVar2 = (uint)bVar1;
    if (bVar1 != 0) {
      if (param_4 < 2) {
        if (param_4 >= 2) {
          iVar3 = 0x24;
        }
        if ((iVar3 == 0) &&
           (iVar3 = FUN_0000f6f8((byte)*param_2,
                                 *(short *)(*param_1 + 0x26) +
                                 *(short *)(param_1[2] + param_3 * 8 + 4),(uint)(param_4 < 2),0),
           iVar3 == 0)) {
          return 0;
        }
      }
      else {
        iVar3 = 0x24;
        uVar2 = 0;
      }
      goto LAB_00010272;
    }
  }
  iVar3 = 0x2f;
  uVar2 = 0;
LAB_00010272:
  FUN_000065ec(0x20d,param_2[1],uVar2,param_3,iVar3);
  return iVar3;
}



int FUN_00010286(uint *param_1,undefined4 *param_2,uint param_3,uint param_4,int param_5)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = 0;
  if (param_3 < param_1[1]) {
    bVar1 = *(byte *)(param_1[2] + param_3 * 8 + 6);
    uVar5 = (uint)bVar1;
    if (bVar1 != 0) {
      if (param_4 < 2) {
        if (param_4 >= 2) {
          iVar4 = 0x24;
        }
        uVar3 = *param_1;
        if (param_5 == 1) {
          uVar3 = (uint)*(ushort *)(uVar3 + 0x28);
        }
        sVar2 = (short)uVar3;
        if (param_5 != 1) {
          sVar2 = *(short *)(uVar3 + 0x2a);
        }
        if ((iVar4 == 0) &&
           (iVar4 = FUN_0000f6f8((byte)*param_2,sVar2 + *(short *)(param_1[2] + param_3 * 8 + 4),
                                 (uint)(param_4 < 2),0), iVar4 == 0)) {
          return 0;
        }
      }
      else {
        iVar4 = 0x24;
        uVar5 = 0;
      }
      goto LAB_000102f0;
    }
  }
  iVar4 = 0x2f;
  uVar5 = 0;
LAB_000102f0:
  FUN_000065ec(0x20d,param_2[1],uVar5,param_3,iVar4);
  return iVar4;
}



int FUN_00010306(int param_1,undefined4 *param_2,uint param_3,uint param_4,uint param_5,uint param_6
                )

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(uint *)(param_1 + 4) <= param_3) {
    iVar1 = 0x2f;
    goto LAB_0001034c;
  }
  if (param_4 < 2) {
    if (param_5 == 0) {
      iVar1 = 0x72;
      goto LAB_0001034c;
    }
    uVar2 = (uint)*(byte *)(*(int *)(param_1 + 8) + param_3 * 8 + 6);
    if (param_4 < 2) {
      iVar1 = FUN_0000f6c8((byte)*param_2,(uint)*(ushort *)(*(int *)(param_1 + 8) + param_3 * 8 + 4)
                           ,1,param_5,param_6);
      if (iVar1 == 0) {
        return 0;
      }
      goto LAB_0001034c;
    }
  }
  iVar1 = 0x24;
LAB_0001034c:
  FUN_000065ec(0x20d,param_2[1],uVar2,param_3,iVar1);
  return iVar1;
}



uint FUN_00010372(int *param_1,undefined4 *param_2,uint param_3,uint param_4,uint param_5)

{
  short sVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  
  uVar9 = 0;
  if ((uint)param_1[1] <= param_3) {
LAB_000103a8:
    uVar9 = 0x2f;
    uVar12 = 0;
    goto LAB_00010448;
  }
  bVar8 = *(byte *)(param_1[2] + param_3 * 8 + 6);
  uVar12 = (uint)bVar8;
  if (bVar8 == 0) goto LAB_000103a8;
  uVar6 = 0;
  if (1 < param_4 || 4 < param_5) {
switchD_000103f0_caseD_5:
    uVar9 = 0x24;
    uVar12 = uVar6;
    goto LAB_00010448;
  }
  iVar5 = *param_1;
  sVar3 = *(short *)(param_1[2] + param_3 * 8 + 4);
  sVar1 = *(short *)(iVar5 + 0x22);
  sVar2 = *(short *)(iVar5 + 0x24);
  bVar8 = 0;
  bVar10 = 0;
  bVar11 = 0;
  bVar4 = param_4 < 2;
  if (!bVar4) {
    uVar9 = 0x24;
  }
  uVar6 = uVar12;
  switch(param_5) {
  case 0:
    break;
  case 1:
    bVar10 = 0xff;
    goto LAB_0001040e;
  case 2:
    bVar8 = 0xff;
    bVar10 = 0xff;
    goto LAB_0001040e;
  case 3:
    bVar8 = 0xff;
    break;
  case 4:
    bVar8 = 0xff;
    bVar10 = 0xff;
    break;
  default:
    goto switchD_000103f0_caseD_5;
  }
  bVar11 = 0xff;
LAB_0001040e:
  if (uVar9 == 0) {
    uVar6 = FUN_0000f74c((byte)*param_2,*(short *)(iVar5 + 0x20) + sVar3,bVar4,bVar8,0);
    uVar7 = FUN_0000f74c((byte)*param_2,sVar1 + sVar3,bVar4,bVar10,0);
    uVar9 = FUN_0000f74c((byte)*param_2,sVar2 + sVar3,bVar4,bVar11,0);
    uVar9 = uVar9 | uVar7 | uVar6;
    if (uVar9 == 0) {
      return 0;
    }
  }
LAB_00010448:
  FUN_000065ec(0x20d,param_2[1],uVar12,param_3,uVar9);
  return uVar9;
}



int FUN_00010460(int *param_1,undefined4 *param_2,uint param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (param_3 < (uint)param_1[1]) {
    bVar1 = *(byte *)(param_1[2] + param_3 * 8 + 6);
    uVar5 = (uint)bVar1;
    if (bVar1 == 0) goto LAB_000104a2;
    iVar2 = FUN_0000f74c((byte)*param_2,
                         *(short *)(*param_1 + 10) + *(short *)(param_1[2] + param_3 * 8 + 4),0xf,
                         (byte)param_4,1);
    if (iVar2 == 0) {
      if (DAT_00091e5c == 0) {
        return 0;
      }
      uVar3 = 0x202;
      uVar4 = param_2[1];
      goto LAB_000104c6;
    }
  }
  else {
LAB_000104a2:
    iVar2 = 0x2f;
    uVar5 = 0;
  }
  uVar3 = 0x209;
  uVar4 = param_2[1];
  param_4 = iVar2;
LAB_000104c6:
  FUN_000065ec(uVar3,uVar4,uVar5,param_3,param_4);
  return iVar2;
}



int FUN_000104d4(int *param_1,undefined4 *param_2,uint param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (param_3 < (uint)param_1[1]) {
    bVar1 = *(byte *)(param_1[2] + param_3 * 8 + 6);
    uVar5 = (uint)bVar1;
    if (bVar1 == 0) goto LAB_00010516;
    iVar2 = FUN_0000f74c((byte)*param_2,
                         *(short *)(*param_1 + 6) + *(short *)(param_1[2] + param_3 * 8 + 4),0x1f,
                         (byte)param_4,0);
    if (iVar2 == 0) {
      if (DAT_00091e5c == 0) {
        return 0;
      }
      uVar3 = 0x203;
      uVar4 = param_2[1];
      goto LAB_0001053a;
    }
  }
  else {
LAB_00010516:
    iVar2 = 0x2f;
    uVar5 = 0;
  }
  uVar3 = 0x209;
  uVar4 = param_2[1];
  param_4 = iVar2;
LAB_0001053a:
  FUN_000065ec(uVar3,uVar4,uVar5,param_3,param_4);
  return iVar2;
}



int FUN_00010548(int *param_1,undefined4 *param_2,uint param_3,undefined *param_4,uint param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_3 < (uint)param_1[1]) {
    bVar1 = *(byte *)(param_1[2] + param_3 * 8 + 6);
    if (bVar1 != 0) {
      if (param_4 == (undefined *)0x0) {
        iVar2 = 0x72;
      }
      else {
        iVar2 = FUN_0000f694((byte)*param_2,
                             *(short *)(*param_1 + 4) + *(short *)(param_1[2] + param_3 * 8 + 4),
                             param_5,param_4,0);
        uVar3 = (uint)bVar1;
        if (iVar2 == 0) {
          return 0;
        }
      }
      goto LAB_00010590;
    }
  }
  iVar2 = 0x2f;
LAB_00010590:
  FUN_000065ec(0x208,param_2[1],uVar3,param_3,iVar2);
  return iVar2;
}



uint FUN_000105a8(int *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_3 < (uint)param_1[1]) {
    bVar1 = *(byte *)(param_1[2] + param_3 * 8 + 6);
    uVar5 = (uint)bVar1;
    if (bVar1 == 0) goto LAB_00010608;
    if (param_4 < 2) {
      uVar2 = *(short *)(*param_1 + 10) + *(short *)(param_1[2] + param_3 * 8 + 4);
      if (param_4 == 0) {
        uVar6 = FUN_0000f74c((byte)*param_2,uVar2,0x80,0,0);
      }
      else {
        uVar6 = FUN_0000f74c((byte)*param_2,uVar2,0x80,0x80,0);
      }
      if (uVar6 == 0) {
        if (DAT_00091e5c == 0) {
          return 0;
        }
        uVar3 = 0x201;
        uVar4 = param_2[1];
        goto LAB_0001062c;
      }
    }
    else {
      uVar6 = 0x24;
      uVar5 = 0;
    }
  }
  else {
LAB_00010608:
    uVar6 = 0x2f;
    uVar5 = 0;
  }
  uVar3 = 0x208;
  uVar4 = param_2[1];
  param_4 = uVar6;
LAB_0001062c:
  FUN_000065ec(uVar3,uVar4,uVar5,param_3,param_4);
  return uVar6;
}



int FUN_0001063c(int *param_1,undefined4 *param_2,uint param_3,undefined *param_4)

{
  int iVar1;
  byte bVar2;
  
  if ((param_3 < (uint)param_1[1]) && (*(char *)(param_1[2] + param_3 * 8 + 6) != '\0')) {
    if (param_4 != (undefined *)0x0) {
      bVar2 = 0;
      iVar1 = FUN_0000f65c((byte)*param_2,
                           *(short *)(*param_1 + 10) + *(short *)(param_1[2] + param_3 * 8 + 4),
                           &stack0xffffffe8,0);
      if (iVar1 != 0) {
        *param_4 = 2;
        return iVar1;
      }
      if ((bVar2 & 0x80) == 0) {
        *param_4 = 0;
        return 0;
      }
      *param_4 = 1;
      return 0;
    }
    iVar1 = 0x72;
  }
  else {
    iVar1 = 0x2f;
  }
  FUN_000065ec(0x208,param_2[1],0,param_3,iVar1);
  return iVar1;
}



int FUN_000106b8(int *param_1,undefined4 *param_2,uint param_3,undefined *param_4)

{
  int iVar1;
  byte bVar2;
  
  if ((param_3 < (uint)param_1[1]) && (*(char *)(param_1[2] + param_3 * 8 + 6) != '\0')) {
    if (param_4 != (undefined *)0x0) {
      bVar2 = 0;
      iVar1 = FUN_0000f65c((byte)*param_2,
                           *(short *)(*param_1 + 4) + *(short *)(param_1[2] + param_3 * 8 + 4),
                           &stack0xffffffe8,0);
      if (iVar1 != 0) {
        *param_4 = 0;
        return iVar1;
      }
      if ((bVar2 & 0x80) == 0) {
        *param_4 = 0;
        return 0;
      }
      *param_4 = 1;
      return 0;
    }
    iVar1 = 0x72;
  }
  else {
    iVar1 = 0x2f;
  }
  FUN_000065ec(0x208,param_2[1],0,param_3,iVar1);
  return iVar1;
}



undefined4
FUN_000107a2(int param_1,int param_2,uint param_3,uint param_4,uint *param_5,int *param_6)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = 0;
  if (param_3 < *(uint *)(param_1 + 4)) {
    if (param_5 == (uint *)0x0 || param_6 == (int *)0x0) {
      uVar5 = 0x72;
    }
    else {
      iVar3 = *(int *)(param_1 + 8);
      bVar1 = *(byte *)(iVar3 + param_3 * 8 + 6);
      uVar6 = (uint)bVar1;
      bVar2 = *(byte *)(iVar3 + param_3 * 8 + 7);
      uVar7 = (uint)bVar2;
      if ((((bVar2 != 0xff) &&
           (iVar3 = *(int *)(iVar3 + param_3 * 8), param_4 <= *(uint *)(iVar3 + uVar7 * 0xc + 4)))
          && (uVar4 = *(uint *)(iVar3 + uVar7 * 0xc), uVar4 <= param_4)) &&
         (uVar7 = *(uint *)(iVar3 + uVar7 * 0xc + 8), uVar7 != 0)) {
        uVar6 = (param_4 - uVar4) / uVar7 & 0xff;
        if (bVar2 == 1 && bVar1 == 0x22) {
          uVar6 = uVar6 | 0x60;
        }
        if (uVar6 * uVar7 + uVar4 < param_4) {
          uVar6 = uVar6 + 1;
          *param_6 = uVar6 * uVar7 + uVar4;
        }
        *param_5 = uVar6;
        return 0;
      }
      uVar5 = 0x14;
    }
  }
  else {
    uVar5 = 0x2f;
  }
  FUN_000065ec(0x20a,*(undefined4 *)(param_2 + 4),uVar6,param_3,uVar5);
  return uVar5;
}



uint FUN_0001084c(int *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar9 = 0;
  if (param_3 < (uint)param_1[1]) {
    iVar4 = param_1[2];
    bVar2 = *(byte *)(iVar4 + param_3 * 8 + 6);
    uVar9 = (uint)bVar2;
    bVar1 = *(byte *)(iVar4 + param_3 * 8 + 7);
    uVar7 = (uint)bVar1;
    if ((((bVar1 == 0xff) ||
         (iVar6 = *(int *)(iVar4 + param_3 * 8), *(uint *)(iVar6 + uVar7 * 0xc + 4) < param_4)) ||
        (uVar8 = *(uint *)(iVar6 + uVar7 * 0xc), param_4 < uVar8)) ||
       (uVar7 = *(uint *)(iVar6 + uVar7 * 0xc + 8), uVar7 == 0)) {
      uVar7 = 0x14;
    }
    else {
      uVar7 = (param_4 - uVar8) / uVar7 & 0xff;
      uVar3 = *(short *)(*param_1 + 0xe) + *(short *)(iVar4 + param_3 * 8 + 4);
      if (bVar2 == 0x22 && bVar1 == 1) {
        uVar7 = FUN_0000f74c((byte)*param_2,uVar3,0x1f,(byte)uVar7,0);
      }
      else {
        uVar7 = FUN_0000f6f8((byte)*param_2,uVar3,uVar7,0);
      }
      if (uVar7 == 0) {
        if (DAT_00091e5c == 0) {
          return 0;
        }
        uVar8 = 0x204;
        uVar5 = param_2[1];
        goto LAB_0001090e;
      }
    }
  }
  else {
    uVar7 = 0x2f;
  }
  uVar8 = 0x20a;
  uVar5 = param_2[1];
  param_4 = uVar7;
LAB_0001090e:
  FUN_000065ec(uVar8,uVar5,uVar9,param_3,param_4);
  return uVar7;
}



int FUN_0001091c(int *param_1,undefined4 *param_2,uint param_3,int *param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined uStack44;
  byte local_2b;
  int local_28;
  
  iVar3 = DAT_00090168;
  local_28 = DAT_00090168;
  uVar6 = 0;
  if (param_3 < (uint)param_1[1]) {
    if (param_4 == (int *)0x0) {
      iVar5 = 0x72;
    }
    else {
      bVar1 = *(byte *)(param_1[2] + param_3 * 8 + 6);
      uVar6 = (uint)bVar1;
      iVar5 = FUN_0000f694((byte)*param_2,
                           *(short *)(param_1[2] + param_3 * 8 + 4) + *(short *)(*param_1 + 0xc),2,
                           &uStack44,0);
      if (iVar5 == 0) {
        bVar2 = *(byte *)(param_1[2] + param_3 * 8 + 7);
        uVar6 = (uint)local_2b;
        if (bVar2 == 1 && bVar1 == 0x22) {
          uVar6 = uVar6 & 0x1f;
        }
        iVar4 = *(int *)(param_1[2] + param_3 * 8);
        *param_4 = uVar6 * *(int *)(iVar4 + (uint)bVar2 * 0xc + 8) +
                   *(int *)(iVar4 + (uint)bVar2 * 0xc);
        goto LAB_0001098a;
      }
    }
  }
  else {
    iVar5 = 0x2f;
  }
  FUN_000065ec(0x20a,param_2[1],uVar6,param_3,iVar5);
LAB_0001098a:
                    // WARNING: Subroutine does not return
  if (local_28 == iVar3) {
    return iVar5;
  }
  thunk_FUN_00000060();
}



int FUN_000109d8(int *param_1,undefined4 *param_2,uint param_3,undefined *param_4)

{
  int iVar1;
  byte bVar2;
  
  if (param_3 < (uint)param_1[1]) {
    if (param_4 != (undefined *)0x0) {
      bVar2 = 0;
      iVar1 = FUN_0000f65c((byte)*param_2,
                           *(short *)(*param_1 + 4) + *(short *)(param_1[2] + param_3 * 8 + 4),
                           &stack0xffffffe8,0);
      if (iVar1 != 0) {
        *param_4 = 0;
        return iVar1;
      }
      if ((bVar2 & 1) == 0) {
        *param_4 = 0;
        return 0;
      }
      *param_4 = 1;
      return 0;
    }
    iVar1 = 0x72;
  }
  else {
    iVar1 = 0x2f;
  }
  FUN_000065ec(0x20a,param_2[1],0,param_3,iVar1);
  return iVar1;
}



void FUN_00010a48(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint unaff_r6;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar6 = 0;
  uVar1 = FUN_0000f910();
  local_20 = 0;
  local_1c = 0;
  do {
    iVar2 = FUN_0000f948(uVar6 & 0xff);
    if (iVar2 != 0) {
      unaff_r6 = 0;
    }
    if (iVar2 != 0 && uVar1 != 0) {
      do {
        puVar3 = (undefined4 *)FUN_0000f5e4(uVar6,unaff_r6);
        uVar5 = 0;
        do {
          local_20 = local_20 & 0xffff0000 | (uVar5 & 0xff) << 8;
          iVar2 = FUN_00013e3c(puVar3,(ushort *)&local_20);
          if (iVar2 == 0) {
            uVar4 = uVar6 & 0xff;
            if (local_20._2_1_ == '\a') {
              FUN_00013758(puVar3,(int)&local_20,uVar4);
            }
            else {
              switch(local_20._2_1_) {
              case '\0':
              case '\x02':
                break;
              case '\x01':
                FUN_000101e8(puVar3,uVar4);
                break;
              case '\x03':
switchD_00010aac_caseD_1c:
                FUN_000137c4(puVar3,(ushort *)&local_20,uVar4);
                break;
              case '\x04':
switchD_00010aac_caseD_21:
                FUN_0000fa44(puVar3,(ushort *)&local_20,uVar4);
                break;
              case '\x05':
switchD_00010aac_caseD_1b:
                    // WARNING: Subroutine does not return
                FUN_00000060();
              case '\x06':
                FUN_0000f2a8(puVar3,(ushort *)&local_20,uVar4);
                break;
              default:
                switch(local_20._2_1_) {
                case '\x1b':
                case '\x1f':
                  goto switchD_00010aac_caseD_1b;
                case '!':
                  goto switchD_00010aac_caseD_21;
                case '\x1c':
                case '\"':
                  goto switchD_00010aac_caseD_1c;
                }
              }
            }
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < 0x100);
        unaff_r6 = unaff_r6 + 1;
      } while (unaff_r6 < uVar1);
    }
    uVar6 = uVar6 + 1;
    if (6 < uVar6) {
      return;
    }
  } while( true );
}



// WARNING: Restarted to delay deadcode elimination for space: stack

undefined4 FUN_00010b04(uint param_1,int param_2,uint param_3,uint *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int aiStack24 [4];
  
  uVar3 = param_2 - 1U & 0xff;
  if (param_4 == (uint *)0x0) {
    return 0x72;
  }
  uVar4 = (param_1 >> 0x18) - 0x61;
  if ((param_1 & 0xffffff) == 0x6f646c) {
    piVar1 = (int *)FUN_0000fc24(uVar4 & 0xff);
    aiStack24[0] = 0;
    if (piVar1 != (int *)0x0) {
      uVar2 = FUN_000107a2((int)(piVar1 + 1),*piVar1,uVar3,param_3,param_4,aiStack24);
      return uVar2;
    }
    return 0x16;
  }
  if ((param_1 & 0xffffff) != 0x706d73) {
    return 0;
  }
  piVar1 = (int *)FUN_000139dc(uVar4 & 0xff);
  aiStack24[0] = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = FUN_000107a2((int)(piVar1 + 1),*piVar1,uVar3,param_3,param_4,aiStack24);
    return uVar2;
  }
  return 0x16;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_00010b50(uint param_1,int param_2,int param_3,int *param_4,undefined4 *param_5,uint param_6
                 ,int param_7)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  byte local_3c [4];
  uint local_38;
  int iStack52;
  int iStack48;
  int *local_2c;
  
  local_3c[0] = 0;
  if (param_7 == 1) {
    uVar2 = param_3 * 10;
  }
  else {
    uVar2 = param_3 << 1;
  }
  local_38 = param_1;
  iStack52 = param_2;
  iStack48 = param_3;
  local_2c = param_4;
  uVar5 = FUN_0000f7b4(uVar2,0);
  uVar2 = (uint)((ulonglong)uVar5 >> 0x20);
  uVar4 = uVar2 + local_38;
  iVar3 = iStack52 + (uint)CARRY4(uVar2,local_38);
  FUN_0000d758();
  uVar1 = _DAT_00083004;
  uVar2 = _DAT_00083000;
  FUN_0001a7ec();
  FUN_000109d8(local_2c,param_5,param_6,local_3c);
  do {
    if (local_3c[0] != 0) {
LAB_00010c50:
      return (uint)local_3c[0];
    }
    if ((int)uVar5 + iVar3 + (uint)(uVar2 < uVar4) <= (uVar1 & 0xffffff)) {
      uVar5 = FUN_0000f7dc(uVar2 - local_38,
                           (uVar1 & 0xffffff) - (iStack52 + (uint)(uVar2 < local_38)));
      DAT_00095ddc = (undefined4)((ulonglong)uVar5 >> 0x20);
      iVar3 = param_6 * 8 + 6;
      DAT_00095de4 = *(undefined *)(local_2c[2] + iVar3);
      DAT_00095de5 = (undefined)param_6;
      DAT_00095de6 = (undefined)param_5[1];
      DAT_00095de0 = param_3;
      FUN_00010548(local_2c,param_5,param_6,&DAT_00095de7,5);
      FUN_000065ec(0x219,param_5[1],(uint)*(byte *)(local_2c[2] + iVar3),param_6,0);
      if (param_7 == 1) {
                    // WARNING: Subroutine does not return
        FUN_00000060();
      }
      goto LAB_00010c50;
    }
    thunk_FUN_0000b1ac(0x19);
    FUN_0000d758();
    uVar1 = _DAT_00083004;
    uVar2 = _DAT_00083000;
    FUN_0001a7ec();
    FUN_000109d8(local_2c,param_5,param_6,local_3c);
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_00010c60(uint param_1,int param_2,int param_3,int *param_4,undefined4 *param_5,uint param_6
                 ,int param_7)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  byte local_3c [4];
  uint local_38;
  int iStack52;
  int iStack48;
  int *local_2c;
  
  local_3c[0] = 0;
  if (param_7 == 1) {
    uVar2 = param_3 * 10;
  }
  else {
    uVar2 = param_3 << 1;
  }
  local_38 = param_1;
  iStack52 = param_2;
  iStack48 = param_3;
  local_2c = param_4;
  uVar5 = FUN_0000f7b4(uVar2,0);
  uVar2 = (uint)((ulonglong)uVar5 >> 0x20);
  uVar4 = uVar2 + local_38;
  iVar3 = iStack52 + (uint)CARRY4(uVar2,local_38);
  FUN_0000d758();
  uVar1 = _DAT_00083004;
  uVar2 = _DAT_00083000;
  FUN_0001a7ec();
  FUN_000106b8(local_2c,param_5,param_6,local_3c);
  do {
    if (local_3c[0] != 0) {
LAB_00010d60:
      return (uint)local_3c[0];
    }
    if ((uint)((int)uVar5 + iVar3) < (uVar1 & 0xffffff) + (uint)(uVar4 < uVar2)) {
      uVar5 = FUN_0000f7dc(uVar2 - local_38,
                           (uVar1 & 0xffffff) - (iStack52 + (uint)(uVar2 < local_38)));
      DAT_00095dcc = (undefined4)((ulonglong)uVar5 >> 0x20);
      iVar3 = param_6 * 8 + 6;
      DAT_00095dd4 = *(undefined *)(local_2c[2] + iVar3);
      DAT_00095dd5 = (undefined)param_6;
      DAT_00095dd6 = (undefined)param_5[1];
      DAT_00095dd0 = param_3;
      FUN_00010548(local_2c,param_5,param_6,&DAT_00095dd7,5);
      FUN_000065ec(0x218,param_5[1],(uint)*(byte *)(local_2c[2] + iVar3),param_6,0);
      if (param_7 == 1) {
                    // WARNING: Subroutine does not return
        FUN_00000060();
      }
      goto LAB_00010d60;
    }
    thunk_FUN_0000b1ac(0x19);
    FUN_0000d758();
    uVar1 = _DAT_00083004;
    uVar2 = _DAT_00083000;
    FUN_0001a7ec();
    FUN_000106b8(local_2c,param_5,param_6,local_3c);
  } while( true );
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_00010d70(uint **param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint local_30;
  uint *puStack44;
  int iStack40;
  
  puVar4 = *param_1;
  uVar1 = FUN_00016b8c((int)param_1[10]);
  uVar3 = 0;
  local_30 = 0;
  if ((*(uint *)(*(int *)(puVar4[2] + ((*puVar4 >> 0x18) - 0x61 & 0xff) * 4) +
                (int)param_1[1] * 4 + -4) & 1) == 0) {
    return 0;
  }
  if (uVar1 != 0) {
    do {
      puStack44 = (uint *)0x0;
      FUN_00016b82((byte *)param_1[10],uVar3,&iStack40,&puStack44);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  iVar2 = FUN_0001123c(&local_30,param_1[6],4);
  return iVar2;
}



void FUN_00010e34(uint **param_1,uint param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int **ppiVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  
  uVar7 = *param_1[6];
  puVar2 = *param_1;
  if (puVar2 != (uint *)0x0) {
    param_2 = puVar2[1];
  }
  if (puVar2 != (uint *)0x0 && param_2 != 0) {
    if (param_1[1] == (uint *)0x0) {
      return;
    }
    if (*(uint **)(param_2 + 4) < param_1[1]) {
      return;
    }
    if (((*puVar2 >> 0x18) - 0x61 & 0xff) < 7) {
      iVar3 = FUN_00010d70(param_1);
      if (iVar3 == 0) {
        return;
      }
      puVar2 = *param_1;
      if (puVar2 != (uint *)0x0) {
        iVar3 = *(int *)(puVar2[3] + ((*puVar2 >> 0x18) - 0x61 & 0xff) * 4);
        if (iVar3 != 0) {
          ppiVar5 = (int **)(iVar3 + (int)param_1[1] * 0xc);
          if (ppiVar5 != (int **)0x0) {
            param_4 = *ppiVar5;
          }
          if ((ppiVar5 != (int **)0x0 && param_4 != (int *)0x0) &&
             ((uVar6 = *param_1[6], uVar7 * -0x80000000 < uVar6 * -0x80000000 ||
              ((uVar7 << 0x1b) >> 0x1c < (uVar6 << 0x1b) >> 0x1c)))) {
            iVar3 = *param_4;
            piVar1 = param_4 + 1;
            param_4 = &DAT_00000004;
            FUN_00016e4c(iVar3,*piVar1,(uint)ppiVar5[2],4,param_1[6]);
          }
        }
        puVar2 = param_1[1];
        puVar8 = param_1[6];
        uVar6 = (*param_1)[1];
        uVar9 = (**param_1 >> 0x18) - 0x61 & 0xff;
        if (uVar6 != 0) {
          uVar4 = *puVar8;
          if (uVar4 * -0x80000000 + uVar7 * -0x80000000 != 0) {
            FUN_0000f4c4(uVar9,(uint)*(byte *)(*(int *)(uVar6 + 0x24) + ((uint)puVar2 & 0xff)),
                         uVar4 & 1);
          }
          uVar4 = (*puVar8 << 0x1b) >> 0x1c;
          if (uVar4 != (uVar7 << 0x1b) >> 0x1c) {
            FUN_0000f3bc(uVar9,(uint)*(byte *)(*(int *)(uVar6 + 0x24) + ((uint)puVar2 & 0xff)),uVar4
                        );
          }
        }
        puVar2 = *param_1;
        if (puVar2 != (uint *)0x0) {
          iVar3 = *(int *)(puVar2[3] + ((*puVar2 >> 0x18) - 0x61 & 0xff) * 4);
          if (iVar3 == 0) {
            return;
          }
          ppiVar5 = (int **)(iVar3 + (int)param_1[1] * 0xc);
          if (ppiVar5 != (int **)0x0) {
            param_4 = *ppiVar5;
          }
          if (ppiVar5 == (int **)0x0 || param_4 == (int *)0x0) {
            return;
          }
          uVar6 = *param_1[6];
          if (((uVar7 & 1) <= (uVar6 & 1)) && ((uVar7 << 0x1b) >> 0x1c <= (uVar6 << 0x1b) >> 0x1c))
          {
            return;
          }
          FUN_00016e4c(*param_4,param_4[1],(uint)ppiVar5[2],4,param_1[6]);
          return;
        }
      }
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00010f88(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  undefined4 *local_20;
  
  iVar5 = 0;
  local_20 = (undefined4 *)0x0;
  if (param_2 == 0) {
    return;
  }
  if (*(int *)(&DAT_00095fbc + param_3 * 4) == 0) {
    return;
  }
  iVar1 = *(int *)(*(int *)(&DAT_00095fbc + param_3 * 4) + 0xc);
  if (iVar1 != 0) {
    iVar5 = *(int *)(iVar1 + param_3 * 4);
  }
  uVar3 = 1;
  uVar6 = param_2 + 1;
  if (1 < uVar6) {
    do {
      FUN_00016b6c(param_1,uVar3,&local_20);
      if (local_20 != (undefined4 *)0x0) {
        *local_20 = 0;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < uVar6);
  }
  bVar7 = iVar5 != 0;
  uVar3 = (uint)bVar7;
  if (bVar7 && param_2 == -1 || (!bVar7 || uVar6 == 1)) {
    return;
  }
  do {
    piVar4 = *(int **)(iVar5 + uVar3 * 0xc);
    if (piVar4 != (int *)0x0) {
      uVar2 = 4;
      FUN_00016ff8(*piVar4,piVar4[1],0xc,4);
      iVar1 = FUN_00016aa6(*piVar4,piVar4[1],0xc,uVar2);
      *(int *)(iVar5 + uVar3 * 0xc + 8) = iVar1;
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < uVar6);
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0001101c(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint *local_20 [2];
  
  local_20[0] = (uint *)0x0;
  if (param_2 == 0) {
    return;
  }
  uVar1 = FUN_0000f38c(param_3);
  if (uVar1 != 0) {
    if (param_3 < 7) {
      iVar2 = *(int *)(&DAT_00095fbc + param_3 * 4);
    }
    else {
      iVar2 = 0;
    }
    if (iVar2 == 0) {
      FUN_0000fe18(0x10,(int *)local_20);
      *local_20[0] = param_1;
      local_20[0][1] = uVar1;
      uVar1 = FUN_00013dd0(0x71);
      local_20[0][3] = uVar1;
      if (uVar1 != 0) {
        uVar1 = FUN_00013dd0(0x74);
        local_20[0][2] = uVar1;
        if (uVar1 != 0) {
          FUN_00017124(param_1,param_2 + 1,4,FUN_000110b4 + 1,0x10e35,local_20[0]);
          *(uint **)(&DAT_00095fbc + param_3 * 4) = local_20[0];
          return;
        }
      }
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    return;
  }
  return;
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_000110b4(int *param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  bool bVar4;
  undefined4 uStack32;
  int iStack28;
  int aiStack24 [2];
  
  iVar1 = *param_1;
  bVar4 = iVar1 == 0;
  if (!bVar4) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  if (bVar4 || iVar1 == 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (param_1[1] == 0) {
    return;
  }
  if (*(uint *)(iVar1 + 4) < (uint)param_1[1]) {
    return;
  }
  *(uint *)param_1[4] = *(uint *)param_1[4] & 0x1f;
  iVar1 = FUN_0000d658((int *)param_1[5],&iStack28,aiStack24,&uStack32);
  if (iVar1 == 0) {
    return;
  }
  do {
    if (aiStack24[0] == 4) {
      if (iStack28 == 0x62636370) {
        puVar2 = (uint *)param_1[4];
        uVar3 = *puVar2 & 0xffffffe1 | (*uStack32 & 0xf) << 1;
      }
      else {
        if (iStack28 != 0x6e657773) goto LAB_0001112e;
        puVar2 = (uint *)param_1[4];
        uVar3 = *puVar2 & 0xfffffffe | *uStack32 & 1;
      }
      *puVar2 = uVar3;
    }
LAB_0001112e:
    iVar1 = FUN_0000d658((int *)param_1[5],&iStack28,aiStack24,&uStack32);
    if (iVar1 == 0) {
      return;
    }
  } while( true );
}



// WARNING: Could not reconcile some variable overlaps

uint FUN_0001114c(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint local_20;
  
  iVar7 = 0;
  uVar6 = 0;
  local_20 = param_4 & 0xffffff00;
  if (param_1 < 2) {
    piVar8 = (int *)(DAT_00091800 + param_1 * 4);
    while( true ) {
      iVar2 = *piVar8;
      uVar1 = *(ushort *)(iVar2 + iVar7 * 6 + 2);
      if ((uVar1 == 0xffff) || (uVar6 != 0)) break;
      uVar6 = FUN_0000f6f8(*(byte *)(iVar2 + iVar7 * 6),uVar1,(uint)*(byte *)(iVar2 + iVar7 * 6 + 4)
                           ,0);
      iVar7 = iVar7 + 1;
    }
    uVar3 = FUN_0000f65c(0,0x505c,(undefined *)&local_20,0);
    uVar4 = FUN_0000f6f8(0,0x5951,local_20 & 0xff,0);
    uVar5 = FUN_0000f6f8(0,0x5952,(uint)(byte)((char)local_20 + 2),0);
    return uVar5 | uVar6 | uVar3 | uVar4;
  }
  return 0xe;
}



int FUN_000111e0(uint param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  iVar3 = 0;
  if (param_1 < 2) {
    piVar5 = (int *)(DAT_00091804 + param_1 * 4);
    while( true ) {
      iVar2 = *piVar5;
      uVar1 = *(ushort *)(iVar2 + iVar4 * 6 + 2);
      if ((uVar1 == 0xffff) || (iVar3 != 0)) break;
      iVar3 = FUN_0000f6f8(*(byte *)(iVar2 + iVar4 * 6),uVar1,(uint)*(byte *)(iVar2 + iVar4 * 6 + 4)
                           ,0);
      iVar4 = iVar4 + 1;
    }
    return iVar3;
  }
  return 0xe;
}



int FUN_0001123c(uint *param_1,uint *param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = FUN_00000320(param_2,param_1,param_3);
  if (iVar1 != 0) {
    FUN_0000da64(param_2,param_3,param_1,param_3);
  }
  return iVar1;
}



int FUN_00011264(uint **param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint *local_30;
  int local_2c [2];
  
  uVar12 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  puVar10 = *param_1;
  local_30 = (uint *)0x0;
  piVar14 = (int *)puVar10[1];
  uVar3 = (*puVar10 >> 0x18) - 0x61;
  local_38 = 0;
  local_34 = 0;
  uVar11 = uVar3 & 0xff;
  uVar2 = FUN_00016b8c((int)param_1[10]);
  uVar4 = *(uint *)(*(int *)(puVar10[2] + uVar11 * 4) + (int)param_1[1] * 0xc + -0xc);
  uVar13 = (uVar4 << 8) >> 0x14;
  if ((uVar4 & 0x2000000) == 0) {
    return 0;
  }
  local_48 = local_48 & 0xff003fff | ((uint)param_1[1] & 0xff) << 0xe | (uVar3 & 3) << 0x16;
  if (uVar2 != 0) {
    do {
      FUN_00016b82((byte *)param_1[10],uVar12,local_2c,&local_30);
      if ((local_2c[0] == 0 || local_2c[0] == 3) && (local_30 != (uint *)0x0)) {
        uVar3 = *local_30 & 1;
        if ((*local_30 & 1) < (local_48 & 1)) {
          uVar3 = local_48 & 1;
        }
        uVar9 = ((local_48 & 0xfffffffe | uVar3) << 0x1b) >> 0x1c;
        uVar4 = (*local_30 << 0x1b) >> 0x1c;
        if (uVar4 < uVar9) {
          uVar4 = uVar9;
        }
        uVar9 = ((*local_30 << 0x17) >> 0x1c) << 5;
        uVar1 = ((*local_30 << 0x12) >> 0x1b) << 9;
        uVar5 = local_30[3];
        if (local_30[3] < local_3c) {
          uVar5 = local_3c;
        }
        uVar6 = local_30[2];
        uVar7 = uVar13;
        if (uVar13 <= uVar6 >> 0xd) {
          uVar7 = uVar6 >> 0xd;
        }
        if (local_44 <= local_30[3] + uVar7 * 1000) {
          uVar7 = uVar13;
          if (uVar13 <= uVar6 >> 0xd) {
            uVar7 = uVar6 >> 0xd;
          }
          local_44 = local_30[3] + uVar7 * 1000;
        }
        uVar7 = (local_40 >> 0xd | local_40 << 0x13) + local_30[2] * 0x80000;
        uVar6 = uVar7 & 0x7ffff;
        if (uVar6 <= local_30[2] >> 0xd) {
          uVar6 = local_30[2] >> 0xd;
        }
        local_40 = uVar7 >> 0x13 | uVar6 << 0xd;
        uVar7 = ((local_48 & 0xffffffe0 | uVar3 | uVar4 << 1 | uVar9 | uVar1) << 6) >> 0x1f;
        uVar6 = (*local_30 << 6) >> 0x1f;
        if (uVar7 <= uVar6) {
          uVar7 = uVar6;
        }
        local_48 = local_48 & 0xfdffffe0 | uVar3 | uVar4 << 1 | uVar9 | uVar1 | uVar7 << 0x19;
        local_3c = uVar5;
      }
      uVar12 = uVar12 + 1;
    } while (uVar12 < uVar2);
  }
  if ((*(uint *)(*(int *)(puVar10[2] + uVar11 * 4) + (int)param_1[1] * 0xc + -0xc) & 0x4000000) != 0
     ) {
    local_48 = local_48 | 1;
  }
  if ((*(uint *)(*(int *)(puVar10[2] + uVar11 * 4) + (int)param_1[1] * 0xc + -0xc) & 0x40000000) !=
      0) {
    local_48 = local_48 | 0x2000000;
  }
  uVar2 = (uint)(*(int *)(*(int *)(puVar10[2] + uVar11 * 4) + (int)param_1[1] * 0xc + -0xc) << 2) >>
          0x1d;
  if ((local_48 << 0x1b) >> 0x1c < uVar2) {
    local_48 = local_48 & 0xffffffe1 | uVar2 << 1;
  }
  uVar3 = *(uint *)(*(int *)(puVar10[2] + uVar11 * 4) + (int)param_1[1] * 0xc + -8);
  uVar2 = uVar3 & 0xffff;
  if (local_3c < uVar2 * 1000) {
    iVar8 = uVar2 * 1000 - local_3c;
  }
  else {
    uVar2 = uVar3 >> 0x10;
    if (local_3c <= uVar2 * 1000) goto LAB_0001148a;
    iVar8 = -(local_3c + uVar2 * -1000);
  }
  local_3c = uVar2 * 1000;
  local_44 = local_44 + iVar8;
LAB_0001148a:
  if (local_3c != 0) {
    FUN_000107a2((int)(piVar14 + 1),*piVar14,(int)param_1[1] - 1U & 0xff,local_3c,&local_34,
                 (int *)&local_38);
  }
  if (local_38 != 0) {
    local_44 = local_44 + (local_38 - local_3c);
    local_3c = local_38;
  }
  iVar8 = FUN_0001123c(&local_48,param_1[6],0x10);
  return iVar8;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_000114ce(uint **param_1)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *unaff_r8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  undefined8 uVar12;
  undefined auStack112 [20];
  uint uStack92;
  uint uStack88;
  uint uStack76;
  uint local_48;
  char local_40 [4];
  char local_3c [4];
  uint local_38;
  uint uStack52;
  uint local_30;
  uint uStack44;
  int local_28;
  
  puVar4 = param_1[6];
  local_30 = puVar4[2];
  uStack44 = puVar4[3];
  local_48 = 0;
  local_3c[0] = '\0';
  local_38 = *puVar4;
  uStack52 = puVar4[1];
  local_40[0] = '\0';
  local_28 = 0;
  puVar4 = *param_1;
  if (puVar4 != (uint *)0x0) {
    unaff_r8 = (undefined4 *)puVar4[1];
  }
  if (puVar4 == (uint *)0x0 || unaff_r8 == (undefined4 *)0x0) {
LAB_0001153a:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  puVar3 = param_1[1];
  if (puVar3 == (uint *)0x0) {
    return;
  }
  if ((uint *)unaff_r8[2] < puVar3) {
    return;
  }
  uVar8 = (int)puVar3 - 1U & 0xff;
  uStack92 = (*puVar4 >> 0x18) - 0x61 & 0xff;
  if (6 < uStack92) goto LAB_0001153a;
  if (((uint)param_1[9] | (uint)param_1[8]) == 0) {
    uVar8 = FUN_00011264(param_1);
    if ((uVar8 & 0xff) == 0) {
      return;
    }
    FUN_000117d0(param_1,&local_38);
    return;
  }
  if ((*param_1[6] & 1) != 0) {
    puVar3 = (uint *)(puVar4[7] + uVar8 * 8);
    uVar9 = *puVar3;
    uVar10 = puVar3[1];
    puVar3 = (uint *)(puVar4[8] + uVar8 * 8);
    uStack88 = *puVar3;
    uStack76 = puVar3[1];
    FUN_0000d758();
    uVar2 = _DAT_00083000;
    uVar7 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    if ((uVar9 | uVar10) != 0) {
      if (uVar10 < uVar7 + (uVar9 < uVar2)) {
        FUN_0000f7dc(uVar2 - uVar9,uVar7 - (uVar10 + (uVar2 < uVar9)));
      }
      if (local_48 < (*(uint *)(*(int *)(puVar4[2] + uStack92 * 4) + uVar8 * 0xc + 8) & 0xffff))
      goto LAB_0001166c;
    }
    FUN_000106b8(unaff_r8 + 1,(undefined4 *)*unaff_r8,uVar8,local_3c);
    cVar1 = *(char *)(unaff_r8[3] + uVar8 * 8 + 6);
    if (cVar1 == '\x04') {
      if ((*(char *)(unaff_r8[5] + uVar8) == '\x06') || (*(char *)(unaff_r8[5] + uVar8) == '\a'))
      goto LAB_0001162c;
    }
    else {
      if ((cVar1 == '!') &&
         ((cVar1 = *(char *)(unaff_r8[5] + uVar8), cVar1 == '\x06' ||
          ((cVar1 == '\a' || cVar1 == '\x14') || cVar1 == '\x15')))) {
LAB_0001162c:
        FUN_000109d8(unaff_r8 + 1,(undefined4 *)*unaff_r8,uVar8,local_40);
      }
    }
    if ((local_3c[0] == '\0') || ((local_28 == 1 && (local_40[0] == '\0')))) {
      if ((uVar9 | uVar10) == 0) {
        puVar3 = (uint *)(puVar4[7] + uVar8 * 8);
        *puVar3 = uVar2;
        puVar3[1] = uVar7;
        uVar12 = FUN_0000f7b4(0x32,0);
        uVar9 = (uint)((ulonglong)uVar12 >> 0x20);
        piVar6 = (int *)(puVar4[8] + uVar8 * 8);
        *piVar6 = uVar9 + uVar2;
        piVar6[1] = (int)uVar12 + uVar7 + (uint)CARRY4(uVar9,uVar2);
        FUN_00011fb4(param_1);
      }
      else {
        if ((uStack76 + (uVar2 < uStack88) <= uVar7) ||
           (uVar12 = FUN_0000f7dc(uStack88 - uVar2,uStack76 - (uVar7 + (uStack88 < uVar2))),
           (uint)((ulonglong)uVar12 >> 0x20) < 0x32)) {
          FUN_00011fb4(param_1);
        }
      }
      goto LAB_0001166c;
    }
  }
  param_1[8] = (uint *)0x0;
  param_1[9] = (uint *)0x0;
  puVar5 = (undefined4 *)(puVar4[8] + uVar8 * 8);
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5 = (undefined4 *)(puVar4[7] + uVar8 * 8);
  *puVar5 = 0;
  puVar5[1] = 0;
LAB_0001166c:
  if (((uint)param_1[9] | (uint)param_1[8]) != 0) {
    return;
  }
  if (*(char *)(puVar4[4] + uVar8) != '\0') {
    FUN_0000fc54(uStack92,uVar8,1);
  }
  puVar4 = *param_1;
  bVar11 = (*(uint *)(*(int *)(puVar4[2] + ((*puVar4 >> 0x18) - 0x61 & 0xff) * 4) +
                     ((int)param_1[1] - 1U) * 0xc) & 0x80000000) != 0;
  if (bVar11) {
    puVar4 = (uint *)puVar4[1];
  }
  if (bVar11 && puVar4 != (uint *)0x0) {
    if ((*param_1[6] & 1) != 0) {
      FUN_0000f878(puVar4 + 1,*puVar4,(int)param_1[1] - 1U & 0xff,1,auStack112[0]);
    }
    return;
  }
  return;
}



void FUN_00011734(byte param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *local_20;
  
  local_20 = (uint *)0x0;
  if ((6 < param_1) || (iVar5 = *(int *)(&DAT_00095fa0 + (uint)param_1 * 4), iVar5 == 0)) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  FUN_00016b6c((uint)param_1 * 0x1000000 + 0x616f646c,param_2,&local_20);
  iVar1 = *(int *)(iVar5 + 0x10);
  uVar4 = param_2 - 1;
  if ((uint)*(byte *)(iVar1 + uVar4) == param_3) {
    return;
  }
  if ((*local_20 & 1) != 0) {
    if (param_3 == 1) {
      *(undefined *)(iVar1 + uVar4) = 1;
      puVar3 = (uint *)(*(int *)(iVar5 + 0x1c) + param_2 * 8 + -8);
      if ((puVar3[1] | *puVar3) != 0) {
        return;
      }
      uVar2 = 1;
    }
    else {
      if (param_3 != 0) {
        return;
      }
      *(undefined *)(iVar1 + uVar4) = 0;
      uVar2 = 4;
    }
    FUN_0000fc54((uint)param_1,uVar4 & 0xff,uVar2);
    return;
  }
  return;
}



void FUN_000117d0(uint **param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int **ppiVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  bool bVar8;
  
  puVar6 = *param_1;
  puVar4 = param_1[6];
  piVar7 = (int *)((*puVar6 >> 0x18) - 0x61 & 0xff);
  uVar1 = *puVar4;
  bVar8 = (uVar1 & 1) == (*param_2 & 1);
  if ((uVar1 & 1) <= (*param_2 & 1)) {
    bVar8 = (uVar1 & 0x1e0) == 0;
  }
  if (bVar8) {
    uVar1 = uVar1 & 0xfeffffff;
  }
  else {
    uVar1 = uVar1 | 0x1000000;
  }
  *puVar4 = uVar1;
  iVar2 = *(int *)(puVar6[3] + (int)piVar7 * 4);
  if (iVar2 != 0) {
    ppiVar3 = (int **)(iVar2 + (int)param_1[1] * 0xc);
    if (ppiVar3 != (int **)0x0) {
      piVar7 = *ppiVar3;
    }
    if ((ppiVar3 != (int **)0x0 && piVar7 != (int *)0x0) &&
       ((((param_2[1] < puVar4[1] || (param_2[3] < puVar4[3])) || ((*puVar4 & 0x1000000) != 0)) ||
        (((param_2[2] & 0x1fff) < (puVar4[2] & 0x1fff) ||
         ((*param_2 << 6) >> 0x1f < (*puVar4 << 6) >> 0x1f)))))) {
      FUN_00016e4c(*piVar7,piVar7[1],(uint)ppiVar3[2],0x10,puVar4);
    }
  }
  FUN_000118fe(param_1,param_2);
  puVar4 = *param_1;
  puVar6 = param_1[6];
  uVar1 = *puVar4;
  uVar5 = *puVar6;
  if ((uVar5 & 0x1e0) == 0) {
    uVar5 = uVar5 & 0xfeffffff;
  }
  else {
    uVar5 = uVar5 | 0x1000000;
  }
  *puVar6 = uVar5;
  iVar2 = *(int *)(puVar4[3] + ((uVar1 >> 0x18) - 0x61 & 0xff) * 4);
  if (iVar2 != 0) {
    puVar4 = param_1[1];
    piVar7 = (int *)((int)puVar4 * 3);
    ppiVar3 = (int **)(iVar2 + (int)puVar4 * 0xc);
    if (ppiVar3 != (int **)0x0) {
      piVar7 = *ppiVar3;
    }
    if (ppiVar3 != (int **)0x0 && piVar7 != (int *)0x0) {
      if ((param_2[1] < puVar6[1]) && (param_2[3] < puVar6[3])) {
        if (((*puVar6 & 1) == (*param_2 & 1)) &&
           ((*param_2 << 0x17) >> 0x1c <= (*puVar6 << 0x17) >> 0x1c)) {
          return;
        }
      }
      *puVar6 = *puVar6 & 0xffc03fff | ((uint)puVar4 & 0xff) << 0xe;
      FUN_00016e4c(**ppiVar3,(*ppiVar3)[1],(uint)ppiVar3[2],0x10,puVar6);
      return;
    }
    return;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_000118fe(uint **param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint **ppuVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  undefined4 *puVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  uint *puVar17;
  uint uVar18;
  bool bVar19;
  undefined8 uVar20;
  
  puVar17 = param_1[6];
  puVar15 = *param_1;
  uVar16 = (int)param_1[1] - 1U & 0xff;
  uVar2 = (*puVar15 >> 0x18) - 0x61 & 0xff;
  uVar12 = 0;
  puVar10 = (undefined4 *)puVar15[1];
  uVar18 = 0;
  if (puVar10 == (undefined4 *)0x0) {
    return;
  }
  if (*(char *)(puVar15[4] + uVar16) != '\0') goto LAB_0001195e;
  uVar3 = (*puVar17 << 0x1b) >> 0x1c;
  uVar8 = (*param_2 << 0x1b) >> 0x1c;
  if ((*puVar17 & 0x1e) == 0) {
    if ((uVar3 == uVar8) && ((puVar17[2] & 0x1fff) == (param_2[2] & 0x1fff))) goto LAB_0001195e;
    if ((puVar17[2] & 0x1fff) < (*(uint *)(*(int *)(puVar15[2] + uVar2 * 4) + uVar16 * 0xc) & 0xfff)
       ) {
      FUN_0000fc54(uVar2,uVar16,0);
      goto LAB_0001195e;
    }
  }
  else {
    if (uVar3 == uVar8) goto LAB_0001195e;
  }
  FUN_0000fc54(uVar2,uVar16,4);
LAB_0001195e:
  if (puVar17[3] != param_2[3] && puVar17[3] != 0) {
    puVar4 = *param_1;
    bVar19 = (*(uint *)(*(int *)(puVar4[2] + ((*puVar4 >> 0x18) - 0x61 & 0xff) * 4) +
                       ((int)param_1[1] - 1U) * 0xc) & 0x80000000) != 0;
    if (bVar19) {
      puVar4 = (uint *)puVar4[1];
    }
    if (bVar19 && puVar4 != (uint *)0x0) {
      FUN_0000f878(puVar4 + 1,(undefined4 *)*puVar4,(int)param_1[1] - 1U & 0xff,0);
    }
    FUN_0001084c(puVar10 + 1,(undefined4 *)*puVar10,uVar16,puVar17[3]);
    if (*(char *)(puVar10[3] + uVar16 * 8 + 6) == '!') {
      uVar12 = puVar15[6];
    }
    else {
      uVar12 = puVar15[5];
    }
    uVar3 = puVar17[3];
    uVar8 = param_2[3];
    if (uVar8 < uVar3) {
      uVar3 = uVar3 - uVar8;
    }
    else {
      uVar3 = uVar8 - uVar3;
    }
    uVar12 = (uVar3 / *(uint *)(uVar12 + 8)) * *(int *)(uVar12 + 4);
  }
  uVar3 = (*puVar17 << 0x17) >> 0x1c;
  if (uVar3 != (*param_2 << 0x17) >> 0x1c) {
    FUN_00010460(puVar10 + 1,(undefined4 *)*puVar10,uVar16,uVar3);
  }
  uVar3 = (*puVar17 << 0x12) >> 0x1b;
  if (uVar3 != (*param_2 << 0x12) >> 0x1b) {
    FUN_000104d4(puVar10 + 1,(undefined4 *)*puVar10,uVar16,uVar3);
  }
  if ((*puVar17 & 1) != (*param_2 & 1)) {
    if (((*puVar17 & 1) == 0) && (*(char *)(puVar15[4] + uVar16) == '\x01')) {
      FUN_0000fc54(uVar2,uVar16,4);
      *(undefined *)(puVar15[4] + uVar16) = 0;
    }
    puVar4 = *param_1;
    bVar19 = (*(uint *)(*(int *)(puVar4[2] + ((*puVar4 >> 0x18) - 0x61 & 0xff) * 4) +
                       ((int)param_1[1] - 1U) * 0xc) & 0x80000000) != 0;
    if (bVar19) {
      puVar4 = (uint *)puVar4[1];
    }
    if (bVar19 && puVar4 != (uint *)0x0) {
      FUN_0000f878(puVar4 + 1,(undefined4 *)*puVar4,(int)param_1[1] - 1U & 0xff,0);
    }
    FUN_000105a8(puVar10 + 1,(undefined4 *)*puVar10,uVar16,*puVar17 & 1);
    if ((*param_2 & 1) < (*puVar17 & 1)) {
      uVar18 = *(uint *)(*(int *)(puVar15[2] + uVar2 * 4) + uVar16 * 0xc + 8) & 0xffff;
      if (*(char *)(puVar10[3] + uVar16 * 8 + 6) == '!') {
        uVar12 = *(uint *)puVar15[6];
      }
      else {
        uVar12 = *(uint *)puVar15[5];
      }
      if (uVar12 <= uVar18) {
        uVar12 = uVar18;
      }
    }
    iVar5 = FUN_0000f948(uVar2);
    if (iVar5 == 0xb && uVar16 == 10) {
      uVar12 = 0x19;
    }
  }
  ppuVar6 = (uint **)(puVar15[7] + uVar16 * 8);
  puVar9 = *ppuVar6;
  puVar4 = ppuVar6[1];
  if ((((uVar12 != 0) || (((uint)puVar9 | (uint)puVar4) != 0)) && ((*puVar17 & 1) != 0)) &&
     ((*(uint *)(*(int *)(puVar15[2] + uVar2 * 4) + uVar16 * 0xc + 8) & 0x20000) != 0)) {
    FUN_0000d758();
    uVar1 = _DAT_00083000;
    uVar3 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    if (((uint)puVar4 | (uint)puVar9) == 0) {
      puVar10 = (undefined4 *)(puVar15[7] + uVar16 * 8);
      *puVar10 = uVar1;
      puVar10[1] = uVar3;
      uVar20 = FUN_0000f7b4(uVar12,0);
      uVar8 = (uint)((ulonglong)uVar20 >> 0x20);
      puVar11 = (uint *)(uVar8 + uVar2);
      puVar14 = (uint *)((int)uVar20 + uVar3 + CARRY4(uVar8,uVar2));
    }
    else {
      ppuVar6 = (uint **)(puVar15[8] + uVar16 * 8);
      puVar11 = *ppuVar6;
      puVar14 = ppuVar6[1];
      if (uVar12 == 0) {
        uVar20 = FUN_0000f7dc((uint)((int)puVar11 - (int)puVar9),
                              (int)((int)puVar14 - ((int)puVar4 + (uint)(puVar11 < puVar9))));
        uVar12 = (uint)((ulonglong)uVar20 >> 0x20);
      }
      else {
        uVar20 = FUN_0000f7b4(uVar12,0);
        uVar12 = (uint)((ulonglong)uVar20 >> 0x20);
        puVar7 = (uint *)(uVar12 + uVar2);
        puVar13 = (uint *)((int)uVar20 + uVar3 + CARRY4(uVar12,uVar2));
        if ((uint *)((int)puVar13 + (uint)(puVar11 < puVar7)) <= puVar14) {
          puVar13 = puVar14;
          puVar7 = puVar11;
        }
        puVar11 = puVar7;
        uVar20 = FUN_0000f7dc((uint)((int)puVar11 - (int)puVar9),
                              (int)((int)puVar13 - ((int)puVar4 + (uint)(puVar11 < puVar9))));
        uVar12 = (uint)((ulonglong)uVar20 >> 0x20);
        puVar14 = puVar13;
      }
    }
    ppuVar6 = (uint **)(puVar15[8] + uVar16 * 8);
    *ppuVar6 = puVar11;
    ppuVar6[1] = puVar14;
    param_1[8] = puVar11;
    param_1[9] = puVar14;
    if ((uVar12 < 0x32) || (param_1[3] == (uint *)&DAT_00000003)) {
      if (uVar18 != 0) {
        thunk_FUN_0000b1ac(uVar18);
      }
      FUN_00011fb4(param_1);
      puVar15 = *param_1;
      bVar19 = (*(uint *)(*(int *)(puVar15[2] + ((*puVar15 >> 0x18) - 0x61 & 0xff) * 4) +
                         ((int)param_1[1] - 1U) * 0xc) & 0x80000000) != 0;
      if (bVar19) {
        puVar15 = (uint *)puVar15[1];
      }
      if ((bVar19 && puVar15 != (uint *)0x0) && ((*param_1[6] & 1) != 0)) {
        FUN_0000f878(puVar15 + 1,(undefined4 *)*puVar15,(int)param_1[1] - 1U & 0xff,1);
      }
    }
  }
  *puVar17 = *puVar17 & 0xfeffffff;
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00011ca0(uint param_1,int **param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int **ppiVar7;
  int **ppiVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  bool bVar14;
  uint *local_48;
  uint local_44;
  byte local_40 [4];
  uint uStack60;
  uint *apuStack56 [2];
  uint uStack48;
  int **ppiStack44;
  uint uStack40;
  
  uStack40 = param_3;
  ppiStack44 = param_2;
  uStack48 = param_1;
  local_48 = (uint *)0x0;
  local_44 = 0;
  local_40[0] = 0;
  iVar10 = 0;
  if (param_2 == (int **)0x0) {
    return;
  }
  iVar1 = *(int *)(&DAT_00095fa0 + param_3 * 4);
  if (iVar1 == 0) {
    return;
  }
  if (*(int *)(iVar1 + 0xc) != 0) {
    iVar10 = *(int *)(*(int *)(iVar1 + 0xc) + param_3 * 4);
  }
  puVar9 = *(undefined4 **)(iVar1 + 4);
  if (puVar9 != (undefined4 *)0x0) {
    puVar12 = (undefined4 *)((int)param_2 + 1);
    puVar5 = (undefined4 *)&UNK_00000001;
    while (puVar5 < puVar12) {
      FUN_00016b6c(uStack48,(int)puVar5,&local_48);
      if (local_48 != (uint *)0x0) {
        *local_48 = 0;
        local_48[1] = 0;
        local_48[2] = 0;
        local_48[3] = 0;
        uVar3 = (int)puVar5 - 1U & 0xff;
        FUN_0001091c(puVar9 + 1,(undefined4 *)*puVar9,uVar3,(int *)&local_44);
        local_48[3] = local_44;
        FUN_0001063c(puVar9 + 1,(undefined4 *)*puVar9,uVar3,local_40);
        *local_48 = *local_48 & 0xff003ffe | (uint)local_40[0] & 1 | 0x1e | (param_3 & 3) << 0x16 |
                    (int)puVar5 << 0xe;
      }
      puVar5 = (undefined4 *)((uint)((int)puVar5 + 1) & 0xff);
    }
    bVar14 = iVar10 != 0;
    if (bVar14) {
      puVar9 = (undefined4 *)&UNK_00000001;
    }
    if ((!bVar14 || param_2 != (int **)0xffffffff) &&
        (bVar14 && puVar12 != (undefined4 *)&UNK_00000001)) {
      do {
        piVar6 = *(int **)(iVar10 + (int)puVar9 * 0xc);
        if (piVar6 != (int *)0x0) {
          uVar4 = 0x10;
          FUN_00016ff8(*piVar6,piVar6[1],10,0x10);
          iVar1 = FUN_00016aa6(*piVar6,piVar6[1],10,uVar4);
          *(int *)(iVar10 + (int)puVar9 * 0xc + 8) = iVar1;
        }
        puVar9 = (undefined4 *)((uint)((int)puVar9 + 1) & 0xff);
      } while (puVar9 < puVar12);
    }
    uStack60 = uStack48;
    apuStack56[0] = (uint *)0x0;
    uVar3 = 0;
    ppiVar7 = (int **)0x0;
    uVar13 = 0;
    uVar11 = (uStack48 >> 0x18) - 0x61;
    if (param_2 == (int **)0x0) {
      return;
    }
    if ((uVar11 & 0xff) < 7) {
      iVar10 = *(int *)(&DAT_00095fa0 + (uVar11 & 0xff) * 4);
      ppiVar8 = param_2;
      if (iVar10 != 0) {
        ppiVar8 = *(int ***)(iVar10 + 4);
      }
      if (iVar10 != 0 && ppiVar8 != (int **)0x0) {
        iVar1 = *(int *)(iVar10 + 8);
        bVar14 = iVar1 != 0;
        if (bVar14) {
          iVar1 = *(int *)(iVar1 + uVar11 * 4);
        }
        if (bVar14 && iVar1 != 0) {
          if (param_2 == (int **)0x0) {
            return;
          }
          do {
            if ((*(uint *)(*(int *)(*(int *)(iVar10 + 8) + uVar11 * 4) + (int)ppiVar7 * 0xc) &
                0x80000000) != 0) {
              if (ppiVar8[3] != (int *)0x0) {
                uVar13 = (uint)(*(ushort *)(ppiVar8[3] + (int)ppiVar7 * 2 + 1) >> 8);
              }
              uVar2 = FUN_0000f804((uint *)(ppiVar8 + 1),*ppiVar8,(uint)ppiVar7 & 0xff,
                                   uVar13 + **ppiVar8 * 0x10000);
              uVar3 = uVar3 | uVar2;
              FUN_00016b6c(uStack60,(int)ppiVar7 + 1,apuStack56);
              if ((apuStack56[0] != (uint *)0x0) && ((*apuStack56[0] & 1) != 0)) {
                uVar2 = FUN_0000f878((uint *)(ppiVar8 + 1),*ppiVar8,(uint)ppiVar7 & 0xff,1);
                uVar3 = uVar3 | uVar2;
              }
              if (uVar3 != 0) break;
            }
            ppiVar7 = (int **)((int)ppiVar7 + 1);
            if (param_2 <= ppiVar7) {
              return;
            }
          } while( true );
        }
      }
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00011e5c(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *local_38 [2];
  uint uStack48;
  uint uStack44;
  uint uStack40;
  
  uVar6 = 0;
  local_38[0] = (uint *)0x0;
  if (param_2 == 0) {
    return;
  }
  uVar5 = param_3;
  uStack48 = param_1;
  uStack44 = param_2;
  uStack40 = param_3;
  uVar1 = FUN_0000fc24(param_3);
  if (uVar1 == 0) {
    return;
  }
  if (param_3 < 7) {
    iVar2 = *(int *)(&DAT_00095fa0 + param_3 * 4);
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 != 0) {
    return;
  }
  FUN_0000fe18(0x24,(int *)local_38);
  local_38[0][1] = uVar1;
  *local_38[0] = uStack48;
  uVar3 = FUN_00013dd0(0x6d);
  local_38[0][3] = uVar3;
  if (uVar3 != 0) {
    uVar3 = FUN_00013dd0(0x86);
    local_38[0][2] = uVar3;
    if (uVar3 != 0) {
      uVar5 = *(uint *)(uVar3 + param_3 * 4);
    }
    if (uVar3 != 0 && uVar5 != 0) {
      if (param_2 != 0) {
        iVar2 = *(int *)(uVar1 + 0xc);
        do {
          if (*(char *)(iVar2 + uVar6 * 8 + 6) != '\0') {
            uVar1 = (uint)*(byte *)(iVar2 + uVar6 * 8 + 7);
            iVar4 = *(int *)(iVar2 + uVar6 * 8);
            uVar3 = *(uint *)(uVar5 + uVar6 * 0xc + 4);
            if (((uVar3 & 0xffff) * 1000 < *(uint *)(iVar4 + uVar1 * 0xc)) ||
               (*(uint *)(iVar4 + uVar1 * 0xc + 4) < (uVar3 >> 0x10) * 1000)) goto LAB_00011f38;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < param_2);
      }
      FUN_0000fe18(param_2,(int *)(local_38[0] + 4));
      FUN_000005cc(local_38[0][4],param_2);
      uVar6 = FUN_00013d80(0x16);
      local_38[0][5] = uVar6;
      uVar6 = FUN_00013d80(0x2b);
      local_38[0][6] = uVar6;
      FUN_0000fe18(param_2 << 3,(int *)(local_38[0] + 7));
      FUN_0000fe18(param_2 << 3,(int *)(local_38[0] + 8));
      FUN_00017124(uStack48,param_2 + 1,0x10,FUN_00012110 + 1,0x114cf,local_38[0]);
      *(uint **)(&DAT_00095fa0 + param_3 * 4) = local_38[0];
      return;
    }
  }
LAB_00011f38:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00011fb4(uint **param_1)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  undefined8 uVar12;
  
  puVar11 = param_1[6];
  puVar7 = *param_1;
  uVar5 = (int)param_1[1] - 1U & 0xff;
  puVar2 = (uint *)(puVar7[7] + uVar5 * 8);
  uVar8 = *puVar2;
  uVar9 = puVar2[1];
  puVar2 = (uint *)(puVar7[8] + uVar5 * 8);
  uVar3 = *puVar2;
  uVar10 = (*puVar7 >> 0x18) - 0x61 & 0xff;
  if ((uVar8 | uVar9) == 0) {
    return;
  }
  uVar12 = FUN_0000f7dc(uVar3 - uVar8,puVar2[1] - (uVar9 + (uVar3 < uVar8)));
  iVar4 = (int)((ulonglong)uVar12 >> 0x20);
  puVar6 = (undefined4 *)puVar7[1];
  if (puVar6 == (undefined4 *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060(iVar4,(int)uVar12);
  }
  uVar3 = FUN_00010c60(uVar8,uVar9,iVar4,puVar6 + 1,(undefined4 *)*puVar6,uVar5,
                       (uint)(*(int *)(*(int *)(puVar7[2] + uVar10 * 4) + (int)param_1[1] * 0xc + -4
                                      ) << 0xf) >> 0x1f);
  cVar1 = *(char *)(puVar6[3] + uVar5 * 8 + 6);
  if (cVar1 == '\x04') {
    if (*(char *)(puVar6[5] + uVar5) != '\x06' && *(char *)(puVar6[5] + uVar5) != '\a')
    goto LAB_000120a2;
  }
  else {
    if ((cVar1 != '!') ||
       ((cVar1 = *(char *)(puVar6[5] + uVar5), cVar1 != '\x06' && cVar1 != '\a' &&
        (cVar1 != '\x14' && cVar1 != '\x15')))) goto LAB_000120a2;
  }
  FUN_00010b50(uVar8,uVar9,iVar4,puVar6 + 1,(undefined4 *)*puVar6,uVar5,
               (uint)(*(int *)(*(int *)(puVar7[2] + uVar10 * 4) + (int)param_1[1] * 0xc + -4) << 0xf
                     ) >> 0x1f);
LAB_000120a2:
  iVar4 = FUN_0000f948(uVar10);
  if (((iVar4 == 0xb && uVar5 == 10) && ((*puVar11 & 1) != 0)) && (uVar3 == 0)) {
    if (*(char *)(puVar7[4] + 10) == '\x01') {
      FUN_0000fc54(uVar10,uVar5,4);
      *(undefined *)(puVar7[4] + 10) = 0;
    }
    FUN_000105a8(puVar6 + 1,(undefined4 *)*puVar6,uVar5,0);
    *puVar11 = *puVar11 & 0xfffffffe;
  }
  param_1[8] = (uint *)0x0;
  param_1[9] = (uint *)0x0;
  puVar6 = (undefined4 *)(puVar7[8] + uVar5 * 8);
  *puVar6 = 0;
  puVar6[1] = 0;
  puVar6 = (undefined4 *)(puVar7[7] + uVar5 * 8);
  *puVar6 = 0;
  puVar6[1] = 0;
  return;
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00012110(uint **param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined4 uStack32;
  int iStack28;
  int iStack24;
  
  puVar2 = *param_1;
  bVar7 = puVar2 == (uint *)0x0;
  if (!bVar7) {
    puVar2 = (uint *)puVar2[1];
  }
  if (bVar7 || puVar2 == (uint *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  puVar4 = param_1[1];
  if (puVar4 == (uint *)0x0) {
    return;
  }
  if ((uint *)puVar2[2] < puVar4) {
    return;
  }
  uVar6 = *param_1[4];
  uVar5 = ((uint)puVar4 & 0xff) << 0xe;
  *param_1[4] = uVar6 & 0xffc03fff | uVar5;
  uVar1 = ((**param_1 >> 0x18) - 0x61) * 0x400000 & 0xc00000;
  *param_1[4] = uVar6 & 0xff003fff | uVar5 | uVar1;
  *param_1[4] = uVar6 & 0x3003fff | uVar5 | uVar1;
  iVar3 = FUN_0000d658((int *)param_1[5],&iStack28,&iStack24,&uStack32);
  if (iVar3 == 0) {
    return;
  }
  do {
    if (iStack24 == 4) {
      if (iStack28 == 0x646d6370) {
        *param_1[4] = *param_1[4] & 0xffffc1ff | (*uStack32 & 0x1f) << 9;
      }
      else {
        if (iStack28 < 0x646d6371) {
          if (iStack28 == 0x616d) {
            puVar2 = param_1[4];
            uVar5 = puVar2[2] & 0xffffe000 | *uStack32 & 0x1fff;
          }
          else {
            if (iStack28 != 0x7268) {
              if (iStack28 == 0x7675) {
                param_1[4][3] = *uStack32;
                param_1[4][1] = *uStack32;
              }
              else {
                if (iStack28 == 0x61707962) {
                  puVar2 = param_1[4];
                  uVar5 = *puVar2 & 0xfdffffff | (*uStack32 & 1) << 0x19;
                  goto LAB_000121d8;
                }
              }
              goto LAB_00012226;
            }
            puVar2 = param_1[4];
            uVar5 = puVar2[2] & 0x1fff | *uStack32 << 0xd;
          }
          puVar2[2] = uVar5;
        }
        else {
          if (iStack28 == 0x646d736c) {
            puVar2 = param_1[4];
            uVar5 = *puVar2 & 0xffffffe1 | (*uStack32 & 0xf) << 1;
          }
          else {
            if (iStack28 == 0x6e656370) {
              puVar2 = param_1[4];
              uVar5 = *puVar2 & 0xfffffe1f | (*uStack32 & 0xf) << 5;
            }
            else {
              if (iStack28 != 0x6e657773) goto LAB_00012226;
              puVar2 = param_1[4];
              uVar5 = *puVar2 & 0xfffffffe | *uStack32 & 1;
            }
          }
LAB_000121d8:
          *puVar2 = uVar5;
        }
      }
    }
LAB_00012226:
    iVar3 = FUN_0000d658((int *)param_1[5],&iStack28,&iStack24,&uStack32);
    if (iVar3 == 0) {
      return;
    }
  } while( true );
}



int FUN_00012254(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  
  if (*(int *)(param_2 + 0x14) != 1) {
    uVar2 = 0;
    puVar3 = *(uint **)(param_1[2] + 0xc);
    uVar4 = puVar3[1];
    if (*puVar3 != 0) {
      do {
        piVar5 = (int *)(uVar4 + uVar2 * 0x10);
        iVar1 = *(int *)(*param_1 + 0x14);
        switch(*(undefined *)(iVar1 + uVar2 * 8 + 4)) {
        case 0:
          FUN_00016e4c(*piVar5,piVar5[1],piVar5[3],0x10,*(int *)(iVar1 + uVar2 * 8) + param_3 * 0x10
                      );
          break;
        case 1:
        case 3:
          FUN_00016e4c(*piVar5,piVar5[1],piVar5[3],0xc,*(int *)(iVar1 + uVar2 * 8) + param_3 * 0xc);
          break;
        case 2:
        case 5:
        case 6:
          FUN_00016e4c(*piVar5,piVar5[1],piVar5[3],4,*(int *)(iVar1 + uVar2 * 8) + param_3 * 4);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *puVar3);
    }
  }
  return param_3;
}



void FUN_000122f0(void)

{
  return;
}



void FUN_000122f4(void)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  
  iVar10 = 0;
  FUN_00012488();
  iVar1 = FUN_00013dd0(0x72);
  puVar11 = (uint *)FUN_00013dd0(0x73);
  if (iVar1 != 0 && puVar11 != (uint *)0x0) {
    DAT_000917f4 = *puVar11;
    if (DAT_000917f4 == 0) {
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    FUN_0000fe18(DAT_000917f4 << 5,&DAT_000917f8);
    FUN_0000fe18(DAT_000917f4 << 5,&DAT_000917fc);
    uVar2 = 0;
    if (DAT_000917f4 != 0) {
      do {
        puVar4 = (undefined4 *)(iVar1 + uVar2 * 0x20);
        puVar6 = (undefined4 *)(DAT_000917fc + uVar2 * 0x20);
        *puVar6 = *puVar4;
        puVar6[1] = 0x12480;
        puVar6[2] = puVar4[1];
        *(undefined ***)(puVar6 + 3) = &PTR_FUN_0000ea28_1_0001b44c;
        puVar6[4] = puVar4[2];
        puVar6[5] = puVar4[3];
        puVar6 = (undefined4 *)(DAT_000917f8 + uVar2 * 0x20);
        uVar2 = uVar2 + 1;
        *puVar6 = puVar4[4];
        *(code **)(puVar6 + 1) = FUN_00012254 + 1;
        puVar6[2] = puVar4[5];
        puVar6[3] = puVar4[6];
        puVar6[4] = 0;
        uVar5 = puVar4[7];
        puVar6[7] = 0;
        puVar6[5] = uVar5;
        puVar6[6] = 1;
      } while (uVar2 < DAT_000917f4);
    }
  }
  uVar2 = 0;
  if (DAT_000917f4 != 0) {
    do {
      uVar9 = 0;
      puVar11 = *(uint **)(DAT_000917f8 + uVar2 * 0x20 + 0xc);
      uVar12 = puVar11[1];
      if (*puVar11 != 0) {
        do {
          piVar8 = (int *)(uVar12 + uVar9 * 0x10);
          iVar1 = piVar8[2];
          if (iVar1 == 1) {
LAB_00012466:
            iVar10 = 0xc;
LAB_000123fc:
            iVar7 = iVar10;
            FUN_00016ff8(*piVar8,piVar8[1],iVar1,iVar10);
            iVar1 = FUN_00016aa6(*piVar8,piVar8[1],iVar1,iVar7);
            piVar8[3] = iVar1;
          }
          else {
            if (iVar1 == 3) {
              iVar10 = 0x10;
              goto LAB_000123fc;
            }
            if ((iVar1 == 5 || iVar1 == 6) || iVar1 == 2) {
              iVar10 = 4;
            }
            if ((iVar1 == 5 || iVar1 == 6) || iVar1 == 2) goto LAB_000123fc;
            if (iVar1 == 7) goto LAB_00012466;
            if (iVar10 != 0) goto LAB_000123fc;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < *puVar11);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_000917f4);
  }
  uVar2 = 0;
  if (DAT_000917f4 != 0) {
    do {
      puVar3 = (undefined *)(DAT_000917f8 + uVar2 * 0x20);
      *(uint *)(puVar3 + 0x1c) = DAT_000917fc + uVar2 * 0x20;
      FUN_0000e51c(puVar3,0,(undefined *)0x0,(undefined *)0x0);
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_000917f4);
    return;
  }
  return;
}



void FUN_00012488(void)

{
  uint uVar1;
  int **ppiVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = FUN_000139f0(uVar3);
    if (uVar1 != 0) {
      FUN_00013294(uVar3 * 0x1000000 + 0x61706d73,uVar1,uVar3);
    }
    uVar1 = FUN_0000fc38(uVar3);
    if (uVar1 != 0) {
      FUN_00011e5c(uVar3 * 0x1000000 + 0x616f646c,uVar1,uVar3);
    }
    uVar1 = FUN_0000f3a0(uVar3);
    if (uVar1 != 0) {
      FUN_0001101c(uVar3 * 0x1000000 + 0x616b6c63,uVar1 - 1,uVar3);
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 7);
  uVar3 = 0;
  do {
    uVar1 = FUN_000139f0(uVar3);
    if (uVar1 != 0) {
      FUN_000130d4(uVar3 * 0x1000000 + 0x61706d73,uVar1,uVar3);
    }
    ppiVar2 = (int **)FUN_0000fc38(uVar3);
    if (ppiVar2 != (int **)0x0) {
      FUN_00011ca0(uVar3 * 0x1000000 + 0x616f646c,ppiVar2,uVar3);
    }
    uVar1 = FUN_0000f3a0(uVar3);
    if (uVar1 != 0) {
      FUN_00010f88(uVar3 * 0x1000000 + 0x616b6c63,uVar1 - 1,uVar3);
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 7);
  return;
}



void FUN_0001248c(void)

{
  uint uVar1;
  int **ppiVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = FUN_000139f0(uVar3);
    if (uVar1 != 0) {
      FUN_00013294(uVar3 * 0x1000000 + 0x61706d73,uVar1,uVar3);
    }
    uVar1 = FUN_0000fc38(uVar3);
    if (uVar1 != 0) {
      FUN_00011e5c(uVar3 * 0x1000000 + 0x616f646c,uVar1,uVar3);
    }
    uVar1 = FUN_0000f3a0(uVar3);
    if (uVar1 != 0) {
      FUN_0001101c(uVar3 * 0x1000000 + 0x616b6c63,uVar1 - 1,uVar3);
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 7);
  uVar3 = 0;
  do {
    uVar1 = FUN_000139f0(uVar3);
    if (uVar1 != 0) {
      FUN_000130d4(uVar3 * 0x1000000 + 0x61706d73,uVar1,uVar3);
    }
    ppiVar2 = (int **)FUN_0000fc38(uVar3);
    if (ppiVar2 != (int **)0x0) {
      FUN_00011ca0(uVar3 * 0x1000000 + 0x616f646c,ppiVar2,uVar3);
    }
    uVar1 = FUN_0000f3a0(uVar3);
    if (uVar1 != 0) {
      FUN_00010f88(uVar3 * 0x1000000 + 0x616b6c63,uVar1 - 1,uVar3);
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 7);
  return;
}



void FUN_00012534(void)

{
  DAT_00091800 = FUN_00013dd0(0x75);
  DAT_00091804 = FUN_00013dd0(0x76);
  if (DAT_00091800 != 0 && DAT_00091804 != 0) {
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0001255c(uint **param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  int *piVar15;
  bool bVar16;
  uint local_68;
  uint local_64;
  uint local_60;
  uint *local_48;
  uint local_44;
  uint local_40;
  uint local_3c [2];
  uint local_34;
  
  uVar13 = 0;
  local_34 = 0;
  puVar14 = *param_1;
  local_48 = (uint *)0x0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  piVar15 = (int *)puVar14[1];
  local_44 = 0;
  local_3c[0] = 0;
  uVar11 = (*puVar14 >> 0x18) - 0x61 & 0xff;
  uVar1 = FUN_00016b8c((int)param_1[10]);
  uVar12 = 0;
  local_68 = local_68 | 0x4000;
  if (uVar1 != 0) {
    do {
      FUN_00016b82((byte *)param_1[10],uVar12,&local_40,&local_48);
      if (local_40 < 2) {
        puVar2 = *(uint **)(*(int *)(puVar14[2] + uVar11 * 4) + (int)param_1[1] * 0xc + -0xc);
        bVar16 = ((uint)puVar2 & 0x10000) != 0;
        if (bVar16) {
          puVar2 = local_48;
        }
        if (bVar16 && puVar2 != (uint *)0x0) {
          uVar3 = local_68 & 1;
          if ((local_68 & 1) <= (*puVar2 & 1)) {
            uVar3 = *puVar2 & 1;
          }
          uVar5 = ((local_68 & 0xfffffffe | uVar3) << 0x1b) >> 0x1c;
          uVar4 = (*puVar2 << 0x1b) >> 0x1c;
          if (uVar5 <= uVar4) {
            uVar5 = uVar4;
          }
          uVar4 = puVar2[1];
          if (puVar2[1] < local_64) {
            uVar4 = local_64;
          }
          uVar8 = (local_60 >> 0xd | local_60 << 0x13) + puVar2[2] * 0x80000 >> 0x13;
          uVar7 = uVar8 | local_60 & 0xffffe000;
          uVar6 = puVar2[2];
          uVar10 = (uVar6 << 10) >> 0x1c;
          if ((uVar7 << 10) >> 0x1c < uVar10) {
            uVar6 = (puVar2[2] << 0xe) >> 0x1b;
            local_60 = uVar8 | local_60 & 0xffc3e000 | uVar10 << 0x12;
LAB_00012696:
            uVar7 = local_60 & 0xfffc1fff | uVar6 << 0xd;
          }
          else {
            if (((local_60 & 0x3c0000) == 0) && ((uVar6 & 0x3e000) != 0)) {
              if ((local_60 & 0x3e000) != 0) {
                uVar6 = (uVar6 << 0xe) >> 0x1b;
                uVar8 = (uVar7 << 0xe) >> 0x1b;
                local_60 = uVar7;
                if (uVar8 < uVar6) {
                  uVar6 = uVar8;
                }
                goto LAB_00012696;
              }
              uVar7 = uVar8 | local_60 & 0xfffc0000 | ((uVar6 << 0xe) >> 0x1b) << 0xd;
            }
          }
          local_60 = uVar7;
          uVar7 = (local_60 << 8) >> 0x1e;
          uVar8 = (puVar2[2] << 8) >> 0x1e;
          if (uVar8 < uVar7) {
            uVar8 = uVar7;
          }
          uVar7 = local_68 >> 0xf;
          if (uVar7 <= *puVar2 >> 0xf) {
            uVar7 = *puVar2 >> 0xf;
          }
          local_68 = local_68 & 0x7fe0 | uVar3 | uVar5 << 1 | ((*puVar2 << 0x17) >> 0x1c) << 5 |
                     ((*puVar2 << 0x12) >> 0x1b) << 9 | uVar7 << 0xf;
          uVar5 = ((local_60 & 0xff3fffff | uVar8 << 0x16) << 7) >> 0x1f;
          uVar3 = (puVar2[2] << 7) >> 0x1f;
          if (uVar3 < uVar5) {
            uVar3 = uVar5;
          }
          local_60 = local_60 & 0xfe3fffff | uVar8 << 0x16 | uVar3 << 0x18;
          local_64 = uVar4;
        }
      }
      else {
        if (local_40 == 10) {
          if ((*local_48 & 0x3fc000) != 0) {
            uVar3 = *local_48 & 1;
            if (uVar3 < (local_68 & 1)) {
              uVar3 = local_68 & 1;
            }
            local_68 = local_68 & 0xfffffffe | uVar3 | ((*local_48 << 0x17) >> 0x1c) << 5;
            if ((*local_48 & 0x1e1) != 0) {
              bVar16 = local_48[2] >> 0xd == 0;
              if (bVar16) {
                bVar16 = (*local_48 & 0x2000000) == 0;
              }
              if (bVar16) {
                uVar3 = local_48[3];
                uVar4 = local_48[1];
                uVar5 = uVar4;
                if (uVar3 < local_34) {
                  if (uVar13 == uVar3) {
                    uVar3 = uVar13;
                    if (uVar4 <= local_34) {
                      uVar5 = local_34;
                    }
                  }
                  else {
                    uVar3 = uVar13;
                    uVar5 = local_34;
                    if ((uVar13 < uVar4) && (uVar3 = uVar4, uVar5 = uVar4, uVar4 < local_34)) {
                      uVar3 = local_34;
                      uVar5 = local_34;
                    }
                  }
                }
              }
              else {
                uVar4 = local_48[1];
                uVar3 = uVar4;
                uVar5 = uVar4;
                if ((uVar4 < local_34) && (uVar3 = uVar13, uVar5 = local_34, uVar13 < uVar4)) {
                  uVar3 = local_34;
                }
              }
              local_34 = uVar5;
              local_60 = (local_60 >> 0xd | local_60 << 0x13) + local_48[2] * 0x80000 >> 0x13 |
                         local_60 & 0xffffe000;
              uVar13 = uVar3;
            }
          }
        }
        else {
          if (local_40 == 0xb) {
            uVar3 = local_68 & 1;
            if ((local_68 & 1) <= (*local_48 & 1)) {
              uVar3 = *local_48 & 1;
            }
            local_68 = local_68 & 0xfffffffe | uVar3 | ((*local_48 << 0x1b) >> 0x1c) << 5;
            local_60 = (local_60 >> 0xd | local_60 << 0x13) + (*local_48 & 0x3ffe0) * 0x4000 >> 0x13
                       | local_60 & 0xffffe000;
          }
        }
      }
      uVar12 = uVar12 + 1;
    } while (uVar12 < uVar1);
  }
  if (uVar13 < local_64) {
    uVar13 = local_64;
  }
  if ((*(uint *)(*(int *)(puVar14[2] + uVar11 * 4) + (int)param_1[1] * 0xc + -0xc) & 0x20000) != 0)
  {
    local_68 = local_68 | 1;
  }
  uVar1 = (uint)(*(int *)(*(int *)(puVar14[2] + uVar11 * 4) + (int)param_1[1] * 0xc + -0xc) << 9) >>
          0x1b;
  if ((local_68 << 0x1b) >> 0x1c < uVar1) {
    local_68 = local_68 & 0xffffffe1 | (uVar1 & 0xf) << 1;
  }
  uVar1 = *(uint *)(*(int *)(puVar14[2] + uVar11 * 4) + (int)param_1[1] * 0xc + -8);
  uVar12 = uVar1 & 0xffff;
  if ((uVar13 < uVar12 * 1000) && (uVar13 != 0)) {
    local_64 = uVar12 * 1000;
  }
  else {
    uVar1 = uVar1 >> 0x10;
    local_64 = uVar13;
    if (uVar1 * 1000 < uVar13) {
      local_64 = uVar1 * 1000;
    }
  }
  iVar9 = *(int *)(*(int *)(puVar14[2] + uVar11 * 4) + (int)param_1[1] * 0xc + -0xc);
  uVar1 = (uint)(iVar9 << 1) >> 0x1c;
  uVar13 = (local_60 << 0xe) >> 0x1b;
  if (((uVar13 < uVar1) && ((local_60 & 0x3e000) != 0)) ||
     ((uVar1 = (uint)(iVar9 << 5) >> 0x1c, uVar1 < uVar13 && ((local_60 & 0x3e000) != 0)))) {
    local_60 = local_60 & 0xfffc1fff | uVar1 << 0xd;
  }
  if (local_64 != 0) {
    FUN_000107a2((int)(piVar15 + 1),*piVar15,(int)param_1[1] - 1U & 0xff,local_64,local_3c,
                 (int *)&local_44);
  }
  if (local_44 != 0) {
    local_64 = local_44;
  }
  FUN_0001123c(&local_68,param_1[6],0xc);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_000128fc(uint **param_1)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *unaff_r11;
  undefined8 uVar15;
  char local_40 [4];
  char local_3c [4];
  uint local_38;
  uint uStack52;
  uint local_30;
  int iStack44;
  
  puVar8 = param_1[6];
  local_38 = *puVar8;
  uStack52 = puVar8[1];
  local_30 = puVar8[2];
  local_40[0] = '\0';
  local_3c[0] = '\0';
  puVar8 = *param_1;
  if (puVar8 != (uint *)0x0) {
    unaff_r11 = (undefined4 *)puVar8[1];
  }
  if (puVar8 == (uint *)0x0 || unaff_r11 == (undefined4 *)0x0) {
LAB_00012964:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  puVar3 = param_1[1];
  if (puVar3 == (uint *)0x0) {
    return;
  }
  if ((uint *)unaff_r11[2] < puVar3) {
    return;
  }
  uVar12 = (int)puVar3 - 1U & 0xff;
  uVar4 = (*puVar8 >> 0x18) - 0x61 & 0xff;
  if (6 < uVar4) goto LAB_00012964;
  iStack44 = uVar12 * 3;
  if (*(int *)(*(int *)(puVar8[2] + uVar4 * 4) + uVar12 * 0xc) << 0x10 < 0) {
    return;
  }
  if (((uint)param_1[8] | (uint)param_1[9]) == 0) {
    iVar5 = FUN_0001255c(param_1);
    if (iVar5 != 0) {
      FUN_00012bb8(param_1,&local_38);
      return;
    }
    if (DAT_000934c8 != '\x01') {
      return;
    }
    DAT_000934c8 = '\0';
    FUN_00012b1c((int)param_1,0);
    return;
  }
  if ((*param_1[6] & 1) != 0) {
    puVar3 = (uint *)(puVar8[6] + uVar12 * 8);
    uVar13 = *puVar3;
    uVar14 = puVar3[1];
    puVar3 = (uint *)(puVar8[7] + uVar12 * 8);
    uVar7 = *puVar3;
    uVar6 = puVar3[1];
    FUN_0000d758();
    uVar2 = _DAT_00083000;
    uVar11 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    if ((uVar13 | uVar14) != 0) {
      if (uVar14 < uVar11 + (uVar13 < uVar2)) {
        FUN_0000f7dc(uVar2 - uVar13,uVar11 - (uVar14 + (uVar2 < uVar13)));
      }
      if ((*(uint *)(*(int *)(puVar8[2] + uVar4 * 4) + iStack44 * 4 + 8) & 0xffff) != 0)
      goto LAB_00012a86;
    }
    FUN_000106b8(unaff_r11 + 1,(undefined4 *)*unaff_r11,uVar12,local_40);
    FUN_000109d8(unaff_r11 + 1,(undefined4 *)*unaff_r11,uVar12,local_3c);
    cVar1 = local_40[0];
    if (local_40[0] != '\0') {
      cVar1 = local_3c[0];
    }
    if (local_40[0] == '\0' || cVar1 == '\0') {
      if ((uVar13 | uVar14) == 0) {
        puVar3 = (uint *)(puVar8[6] + uVar12 * 8);
        *puVar3 = uVar2;
        puVar3[1] = uVar11;
        uVar15 = FUN_0000f7b4(0x32,0);
        uVar6 = (uint)((ulonglong)uVar15 >> 0x20);
        piVar10 = (int *)(puVar8[7] + uVar12 * 8);
        *piVar10 = uVar6 + uVar2;
        piVar10[1] = (int)uVar15 + uVar11 + (uint)CARRY4(uVar6,uVar2);
        FUN_000133d4(param_1);
      }
      else {
        if ((uVar6 + (uVar2 < uVar7) <= uVar11) ||
           (uVar15 = FUN_0000f7dc(uVar7 - uVar2,uVar6 - (uVar11 + (uVar7 < uVar2))),
           (uint)((ulonglong)uVar15 >> 0x20) < 0x32)) {
          FUN_000133d4(param_1);
        }
      }
      goto LAB_00012a86;
    }
  }
  param_1[8] = (uint *)0x0;
  param_1[9] = (uint *)0x0;
  puVar9 = (undefined4 *)(puVar8[7] + uVar12 * 8);
  *puVar9 = 0;
  puVar9[1] = 0;
  puVar9 = (undefined4 *)(puVar8[6] + uVar12 * 8);
  *puVar9 = 0;
  puVar9[1] = 0;
LAB_00012a86:
  if (((uint)param_1[9] | (uint)param_1[8]) != 0) {
    return;
  }
  FUN_00012ce0(param_1,1);
  if (*(char *)(unaff_r11[3] + uVar12 * 8 + 6) != '\x03') {
    return;
  }
  FUN_00013a0c(uVar4,uVar12,1);
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00012b1c(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *local_28;
  int iStack36;
  
  local_28 = (uint *)0x0;
  iVar6 = *(int *)(param_1 + 0x18);
  uVar2 = FUN_00016b8c(*(int *)(param_1 + 0x28));
  uVar3 = FUN_00016b98();
  if (uVar2 <= uVar3) {
    return;
  }
  do {
    FUN_00016b82(*(byte **)(param_1 + 0x28),uVar3,&iStack36,&local_28);
    if ((iStack36 == 10) && (uVar4 = *local_28, (uVar4 & 0x3fc000) != 0)) {
      if (param_2 == 1) {
        bVar1 = (byte)((uVar4 << 8) >> 0x18);
        uVar5 = 0;
LAB_00012ba2:
        FUN_00011734(bVar1 >> 6,(uVar4 << 10) >> 0x18,uVar5);
      }
      else {
        if ((*(uint *)(iVar6 + 4) == local_28[3]) && ((uVar4 & 0x2000000) == 0)) {
          if ((uVar4 & 0x1000000) == 0) {
            bVar1 = (byte)((uVar4 << 8) >> 0x18);
            uVar5 = 1;
            goto LAB_00012ba2;
          }
          DAT_000934c8 = 1;
        }
      }
    }
    uVar3 = uVar3 + 1;
    if (uVar2 <= uVar3) {
      return;
    }
  } while( true );
}



void FUN_00012bb8(uint **param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int **ppiVar5;
  uint *puVar6;
  
  puVar6 = param_1[6];
  iVar1 = *(int *)((*param_1)[3] + ((**param_1 >> 0x18) - 0x61 & 0xff) * 4);
  if ((iVar1 != 0) && (ppiVar5 = (int **)(iVar1 + (int)param_1[1] * 0xc), ppiVar5 != (int **)0x0)) {
    if ((ppiVar5[1] != (int *)0x0) &&
       ((((*puVar6 & 0x4000) == 0 || ((*puVar6 & 1) != (*param_2 & 1))) || (puVar6[1] != param_2[1])
        ))) {
      FUN_00012b1c((int)param_1,1);
    }
    piVar2 = *ppiVar5;
    if (piVar2 != (int *)0x0) {
      uVar3 = *puVar6;
      uVar4 = *param_2;
      if (((uVar4 >> 0xf < uVar3 >> 0xf) || (param_2[1] < puVar6[1])) ||
         ((uVar4 * -0x80000000 <= uVar3 * -0x80000000 &&
           uVar3 * -0x80000000 + uVar4 * -0x80000000 != 0 ||
          ((uVar4 << 0x17) >> 0x1c < (uVar3 << 0x17) >> 0x1c)))) {
        FUN_00016e4c(*piVar2,piVar2[1],(uint)ppiVar5[2],0xc,param_1[6]);
      }
    }
  }
  FUN_00012d5c(param_1,param_2);
  puVar6 = param_1[6];
  iVar1 = *(int *)((*param_1)[3] + ((**param_1 >> 0x18) - 0x61 & 0xff) * 4);
  if (iVar1 == 0) {
    return;
  }
  ppiVar5 = (int **)(iVar1 + (int)param_1[1] * 0xc);
  if (ppiVar5 == (int **)0x0) {
    return;
  }
  if ((ppiVar5[1] != (int *)0x0) && ((*puVar6 & 0x4000) != 0)) {
    FUN_00012b1c((int)param_1,0);
  }
  piVar2 = *ppiVar5;
  if (piVar2 == (int *)0x0) {
    return;
  }
  uVar3 = *puVar6;
  uVar4 = *param_2;
  if ((((uVar4 >> 0xf <= uVar3 >> 0xf) && (param_2[1] <= puVar6[1])) &&
      (uVar4 << 0x1f <= uVar3 << 0x1f)) && ((uVar4 << 0x17) >> 0x1c <= (uVar3 << 0x17) >> 0x1c)) {
    return;
  }
  FUN_00016e4c(*piVar2,piVar2[1],(uint)ppiVar5[2],0xc,param_1[6]);
  return;
}



void FUN_00012ce0(uint **param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar3 = *param_1;
  uVar2 = (int)param_1[1] - 1;
  puVar1 = *(undefined4 **)
            (*(int *)(puVar3[2] + ((*puVar3 >> 0x18) - 0x61 & 0xff) * 4) + uVar2 * 0xc);
  bVar5 = ((uint)puVar1 & 0x80000000) != 0;
  if (bVar5) {
    puVar1 = (undefined4 *)puVar3[1];
  }
  puVar4 = &stack0xfffffff8;
  if (!bVar5 || puVar1 == (undefined4 *)0x0) {
    puVar4 = (undefined *)register0x00000054;
  }
  if (!bVar5 || puVar1 == (undefined4 *)0x0) {
    return;
  }
  if (puVar1[3] == 0) {
    return;
  }
  if (*(char *)(puVar1[3] + uVar2 * 8 + 6) != '\x1c') {
    if (param_2 != 1) {
      FUN_0000f878(puVar1 + 1,*puVar1,uVar2 & 0xff,0,puVar4[8]);
      return;
    }
    if ((*param_1[6] & 1) != 0) {
      FUN_0000f878(puVar1 + 1,*puVar1,uVar2 & 0xff,1,puVar4[8]);
      return;
    }
    return;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00012d5c(uint **param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint **ppuVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint *puVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  uint *puVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
  bool bVar20;
  undefined8 uVar21;
  
  uVar15 = 0;
  puVar16 = param_1[6];
  puVar17 = *param_1;
  uVar18 = (int)param_1[1] - 1U & 0xff;
  uVar19 = 0;
  uVar2 = (*puVar17 >> 0x18) - 0x61 & 0xff;
  puVar11 = (undefined4 *)puVar17[1];
  if (puVar11 == (undefined4 *)0x0) {
    return;
  }
  iVar13 = uVar18 * 8 + 6;
  cVar1 = *(char *)(puVar11[3] + iVar13);
  uVar3 = *puVar16;
  if (((uVar3 & 0x1e) == 0) && ((uVar3 << 0x1b) >> 0x1c != (*param_2 << 0x1b) >> 0x1c)) {
    FUN_00013bb4(uVar2,uVar18,2);
    goto LAB_00012e26;
  }
  uVar3 = (uVar3 << 0x1b) >> 0x1c;
  uVar10 = (*param_2 << 0x1b) >> 0x1c;
  if (uVar3 == 1) {
    if ((uVar10 == 1) && ((puVar16[2] & 0x1fff) == (param_2[2] & 0x1fff))) goto LAB_00012e26;
    if ((puVar16[2] & 0x1fff) <
        (*(uint *)(*(int *)(puVar17[2] + uVar2 * 4) + uVar18 * 0xc) & 0x7fff)) {
      FUN_00013bb4(uVar2,uVar18,0);
      goto LAB_00012e26;
    }
  }
  else {
    if (uVar3 == uVar10) goto LAB_00012e26;
  }
  FUN_00013bb4(uVar2,uVar18,4);
LAB_00012e26:
  uVar3 = (*puVar16 << 0x17) >> 0x1c;
  if (uVar3 != (*param_2 << 0x17) >> 0x1c) {
    FUN_00010460(puVar11 + 1,(undefined4 *)*puVar11,uVar18,uVar3);
  }
  uVar3 = (*puVar16 << 0x12) >> 0x1b;
  if (uVar3 != (*param_2 << 0x12) >> 0x1b) {
    FUN_000104d4(puVar11 + 1,(undefined4 *)*puVar11,uVar18,uVar3);
  }
  uVar3 = (puVar16[2] << 0xe) >> 0x1b;
  bVar20 = uVar3 == (param_2[2] << 0xe) >> 0x1b;
  if (!bVar20) {
    bVar20 = (puVar16[2] & 0x3e000) == 0;
  }
  if (!bVar20) {
    FUN_00013c86(uVar2,uVar18,uVar3);
  }
  uVar3 = (puVar16[2] << 8) >> 0x1e;
  if (uVar3 != (param_2[2] << 8) >> 0x1e) {
    FUN_00013aa4(uVar2,uVar18,uVar3,0xfa);
  }
  if (puVar16[1] != param_2[1] && puVar16[1] != 0) {
    FUN_00012ce0(param_1,0);
    FUN_0001084c(puVar11 + 1,(undefined4 *)*puVar11,uVar18,puVar16[1]);
    if (*(char *)(puVar11[3] + iVar13) == '\"') {
      uVar15 = puVar17[5];
    }
    else {
      uVar15 = puVar17[4];
    }
    uVar10 = puVar16[1];
    uVar3 = param_2[1];
    if (uVar3 < uVar10) {
      uVar10 = uVar10 - uVar3;
    }
    else {
      uVar10 = uVar3 - uVar10;
    }
    uVar15 = (uVar10 / *(uint *)(uVar15 + 8)) * *(int *)(uVar15 + 4);
  }
  if ((*puVar16 & 1) != (*param_2 & 1)) {
    FUN_00012ce0(param_1,0);
    if ((cVar1 == '\x03') && ((*param_2 & 1) < (*puVar16 & 1))) {
      FUN_00013a0c(uVar2,uVar18,0);
    }
    FUN_000105a8(puVar11 + 1,(undefined4 *)*puVar11,uVar18,*puVar16 & 1);
    if ((*param_2 & 1) < (*puVar16 & 1)) {
      uVar19 = *(uint *)(*(int *)(puVar17[2] + uVar2 * 4) + uVar18 * 0xc + 8) & 0xffff;
      uVar15 = *(uint *)puVar17[4];
      if (*(uint *)puVar17[4] <= uVar19) {
        uVar15 = uVar19;
      }
    }
  }
  bVar20 = uVar15 == 0;
  ppuVar7 = (uint **)(puVar17[6] + uVar18 * 8);
  puVar4 = *ppuVar7;
  puVar8 = ppuVar7[1];
  if (bVar20) {
    bVar20 = ((uint)puVar4 | (uint)puVar8) == 0;
  }
  if (bVar20) {
    return;
  }
  if ((*puVar16 & 1) == 0) {
    return;
  }
  if ((*(uint *)(*(int *)(puVar17[2] + uVar2 * 4) + uVar18 * 0xc + 8) & 0x20000) == 0) {
    return;
  }
  FUN_0000d758();
  uVar3 = _DAT_00083000;
  uVar10 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  if (((uint)puVar8 | (uint)puVar4) == 0) {
    puVar4 = (uint *)(puVar17[6] + uVar18 * 8);
    *puVar4 = uVar3;
    puVar4[1] = uVar10;
    uVar21 = FUN_0000f7b4(uVar15,0);
    uVar5 = (uint)((ulonglong)uVar21 >> 0x20);
    puVar12 = (uint *)(uVar5 + uVar3);
    puVar14 = (uint *)((int)uVar21 + uVar10 + CARRY4(uVar5,uVar3));
  }
  else {
    ppuVar7 = (uint **)(puVar17[7] + uVar18 * 8);
    puVar12 = *ppuVar7;
    puVar14 = ppuVar7[1];
    if (uVar15 == 0) {
      uVar21 = FUN_0000f7dc((uint)((int)puVar12 - (int)puVar4),
                            (int)((int)puVar14 - ((int)puVar8 + (uint)(puVar12 < puVar4))));
      uVar15 = (uint)((ulonglong)uVar21 >> 0x20);
    }
    else {
      uVar21 = FUN_0000f7b4(uVar15,0);
      uVar15 = (uint)((ulonglong)uVar21 >> 0x20);
      puVar6 = (uint *)(uVar15 + uVar3);
      puVar9 = (uint *)((int)uVar21 + uVar10 + (uint)CARRY4(uVar15,uVar3));
      if (puVar14 < (uint *)((int)puVar9 + (uint)(puVar12 < puVar6))) {
        puVar14 = puVar9;
        puVar12 = puVar6;
      }
      uVar21 = FUN_0000f7dc((uint)((int)puVar12 - (int)puVar4),
                            (int)((int)puVar14 - ((int)puVar8 + (uint)(puVar12 < puVar4))));
      uVar15 = (uint)((ulonglong)uVar21 >> 0x20);
    }
  }
  ppuVar7 = (uint **)(puVar17[7] + uVar18 * 8);
  *ppuVar7 = puVar12;
  ppuVar7[1] = puVar14;
  param_1[8] = puVar12;
  param_1[9] = puVar14;
  if ((0x31 < uVar15) &&
     (puVar17 = param_1[3],
     (puVar17 != (uint *)&UNK_00000001 && puVar17 != (uint *)(entry + 2)) && puVar17 != (uint *)0xb)
     ) {
    return;
  }
  if (uVar19 != 0) {
    thunk_FUN_0000b1ac(uVar19);
  }
  FUN_000133d4(param_1);
  FUN_00012ce0(param_1,1);
  if (cVar1 != '\x03') {
    return;
  }
  if ((*puVar16 & 1) <= (*param_2 & 1)) {
    return;
  }
  FUN_00013a0c(uVar2,uVar18,1);
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_000130d4(uint param_1,uint param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int **ppiVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int **ppiVar11;
  int iVar12;
  bool bVar13;
  uint *local_48;
  uint local_44;
  byte local_40 [4];
  uint uStack60;
  uint *puStack56;
  uint uStack52;
  uint uStack48;
  uint uStack44;
  int iStack40;
  
  iStack40 = param_3;
  uStack44 = param_2;
  uStack48 = param_1;
  iVar8 = 0;
  local_48 = (uint *)0x0;
  local_44 = 0;
  local_40[0] = 0;
  if (param_2 == 0) {
    return;
  }
  iVar12 = *(int *)(&DAT_00095f84 + param_3 * 4);
  if (iVar12 == 0) {
    return;
  }
  if (*(int *)(iVar12 + 0xc) != 0) {
    iVar8 = *(int *)(*(int *)(iVar12 + 0xc) + param_3 * 4);
  }
  ppiVar11 = (int **)(param_2 + 1);
  ppiVar5 = (int **)&UNK_00000001;
  while (ppiVar5 < ppiVar11) {
    FUN_00016b6c(uStack48,(int)ppiVar5,&local_48);
    if (local_48 != (uint *)0x0) {
      puVar6 = *(undefined4 **)(iVar12 + 4);
      if (puVar6 == (undefined4 *)0x0) goto LAB_0001327e;
      local_48[1] = 0;
      local_48[2] = 0;
      *local_48 = 0x4000;
      uVar3 = (int)ppiVar5 - 1U & 0xff;
      FUN_0001091c(puVar6 + 1,(undefined4 *)*puVar6,uVar3,(int *)&local_44);
      local_48[1] = local_44;
      FUN_0001063c(puVar6 + 1,(undefined4 *)*puVar6,uVar3,local_40);
      *local_48 = *local_48 & 0xfffffffe | (uint)local_40[0] & 1 | 0x1e;
    }
    ppiVar5 = (int **)((uint)((int)ppiVar5 + 1) & 0xff);
  }
  bVar13 = iVar8 != 0;
  if (bVar13) {
    ppiVar5 = (int **)&UNK_00000001;
  }
  if ((!bVar13 || param_2 != 0xffffffff) && (bVar13 && ppiVar11 != (int **)&UNK_00000001)) {
    do {
      piVar7 = *(int **)(iVar8 + (int)ppiVar5 * 0xc);
      if (piVar7 != (int *)0x0) {
        uVar4 = 0xc;
        FUN_00016ff8(*piVar7,piVar7[1],8,0xc);
        iVar12 = FUN_00016aa6(*piVar7,piVar7[1],8,uVar4);
        *(int *)(iVar8 + (int)ppiVar5 * 0xc + 8) = iVar12;
      }
      ppiVar5 = (int **)((uint)((int)ppiVar5 + 1) & 0xff);
    } while (ppiVar5 < ppiVar11);
  }
  uStack60 = uStack48;
  puStack56 = (uint *)0x0;
  uVar9 = 0;
  uVar3 = 0;
  uVar10 = (uStack48 >> 0x18) - 0x61;
  if (param_2 == 0) {
    return;
  }
  if ((uVar10 & 0xff) < 7) {
    iVar8 = *(int *)(&DAT_00095f84 + (uVar10 & 0xff) * 4);
    if (iVar8 != 0) {
      ppiVar5 = *(int ***)(iVar8 + 4);
    }
    if (iVar8 != 0 && ppiVar5 != (int **)0x0) {
      iVar12 = *(int *)(iVar8 + 8);
      bVar13 = iVar12 != 0;
      if (bVar13) {
        iVar12 = *(int *)(iVar12 + uVar10 * 4);
      }
      if (bVar13 && iVar12 != 0) {
        if (param_2 == 0) {
          return;
        }
        do {
          cVar1 = *(char *)((int)ppiVar5[3] + uVar3 * 8 + 6);
          if ((cVar1 != '\0') &&
             ((*(uint *)(*(int *)(*(int *)(iVar8 + 8) + uVar10 * 4) + uVar3 * 0xc) & 0x80000000) !=
              0)) {
            uStack52 = uVar3 & 0xff;
            uVar2 = FUN_0000f804((uint *)(ppiVar5 + 1),*ppiVar5,uStack52,
                                 (uint)(*(ushort *)(ppiVar5[3] + uVar3 * 2 + 1) >> 8) +
                                 **ppiVar5 * 0x10000);
            uVar9 = uVar9 | uVar2;
            if ((cVar1 == '\x1c') ||
               ((FUN_00016b6c(uStack60,uVar3 + 1,&puStack56), puStack56 != (uint *)0x0 &&
                ((*puStack56 & 1) != 0)))) {
              uVar2 = FUN_0000f878((uint *)(ppiVar5 + 1),*ppiVar5,uStack52,1);
              uVar9 = uVar9 | uVar2;
            }
            if (uVar9 != 0) break;
          }
          uVar3 = uVar3 + 1;
          if (param_2 <= uVar3) {
            return;
          }
        } while( true );
      }
    }
  }
LAB_0001327e:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00013294(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint *local_38 [2];
  uint uStack48;
  uint uStack44;
  uint uStack40;
  
  uVar6 = 0;
  local_38[0] = (uint *)0x0;
  if (param_2 == 0) {
    return;
  }
  uStack48 = param_1;
  uStack44 = param_2;
  uStack40 = param_3;
  uVar1 = FUN_000139dc(param_3);
  if (uVar1 == 0) {
    return;
  }
  if (param_3 < 7) {
    iVar2 = *(int *)(&DAT_00095f84 + param_3 * 4);
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 != 0) {
    return;
  }
  FUN_0000fe18(0x20,(int *)local_38);
  local_38[0][1] = uVar1;
  *local_38[0] = uStack48;
  uVar3 = FUN_00013dd0(0x6e);
  local_38[0][3] = uVar3;
  if (uVar3 != 0) {
    uVar3 = FUN_00013dd0(0x87);
    local_38[0][2] = uVar3;
    puVar5 = local_38[0];
    if (uVar3 != 0) {
      puVar5 = *(uint **)(uVar3 + param_3 * 4);
    }
    if (uVar3 != 0 && puVar5 != (uint *)0x0) {
      if (param_2 != 0) {
        iVar2 = *(int *)(uVar1 + 0xc);
        do {
          if (*(char *)(iVar2 + uVar6 * 8 + 6) != '\0') {
            uVar1 = (uint)*(byte *)(iVar2 + uVar6 * 8 + 7);
            iVar4 = *(int *)(iVar2 + uVar6 * 8);
            if (((puVar5[uVar6 * 3 + 1] & 0xffff) * 1000 < *(uint *)(iVar4 + uVar1 * 0xc)) ||
               (*(uint *)(iVar4 + uVar1 * 0xc + 4) < (puVar5[uVar6 * 3 + 1] >> 0x10) * 1000))
            goto LAB_0001336c;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < param_2);
      }
      uVar6 = FUN_00013d80(0x17);
      local_38[0][4] = uVar6;
      uVar6 = FUN_00013d80(0x2c);
      local_38[0][5] = uVar6;
      FUN_0000fe18(param_2 << 3,(int *)(local_38[0] + 6));
      FUN_0000fe18(param_2 << 3,(int *)(local_38[0] + 7));
      FUN_00017124(uStack48,param_2 + 1,0xc,FUN_000134b0 + 1,FUN_000128fc + 1,local_38[0]);
      *(uint **)(&DAT_00095f84 + param_3 * 4) = local_38[0];
      return;
    }
  }
LAB_0001336c:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_000133d4(uint **param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined8 uVar10;
  
  puVar6 = *param_1;
  uVar7 = (int)param_1[1] - 1U & 0xff;
  puVar1 = (uint *)(puVar6[6] + uVar7 * 8);
  uVar4 = *puVar1;
  uVar5 = puVar1[1];
  puVar1 = (uint *)(puVar6[7] + uVar7 * 8);
  uVar2 = *puVar1;
  uVar9 = (*puVar6 >> 0x18) - 0x61 & 0xff;
  if ((uVar4 | uVar5) == 0) {
    return;
  }
  uVar10 = FUN_0000f7dc(uVar2 - uVar4,puVar1[1] - (uVar5 + (uVar2 < uVar4)));
  iVar3 = (int)((ulonglong)uVar10 >> 0x20);
  puVar8 = (undefined4 *)puVar6[1];
  if (puVar8 == (undefined4 *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060(iVar3,(int)uVar10);
  }
  FUN_00010c60(uVar4,uVar5,iVar3,puVar8 + 1,(undefined4 *)*puVar8,uVar7,
               (uint)(*(int *)(*(int *)(puVar6[2] + uVar9 * 4) + (int)param_1[1] * 0xc + -4) << 0xf)
               >> 0x1f);
  FUN_00010b50(uVar4,uVar5,iVar3,puVar8 + 1,(undefined4 *)*puVar8,uVar7,
               (uint)(*(int *)(*(int *)(puVar6[2] + uVar9 * 4) + (int)param_1[1] * 0xc + -4) << 0xf)
               >> 0x1f);
  param_1[8] = (uint *)0x0;
  param_1[9] = (uint *)0x0;
  puVar8 = (undefined4 *)(puVar6[7] + uVar7 * 8);
  *puVar8 = 0;
  puVar8[1] = 0;
  puVar8 = (undefined4 *)(puVar6[6] + uVar7 * 8);
  *puVar8 = 0;
  puVar8[1] = 0;
  return;
}



void FUN_000134b0(uint **param_1,undefined4 param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puStack120;
  uint uStack116;
  undefined4 uStack112;
  undefined4 uStack108;
  int iStack104;
  int iStack100;
  uint *puStack96;
  uint *puStack92;
  uint *puStack88;
  uint *puStack84;
  uint *puStack72;
  uint uStack48;
  uint uStack44;
  uint uStack40;
  
  puVar1 = *param_1;
  if (puVar1 != (uint *)0x0) {
    param_3 = puVar1[1];
  }
  if (puVar1 != (uint *)0x0 && param_3 != 0) {
    puVar3 = param_1[1];
    if (puVar3 == (uint *)0x0) {
      return;
    }
    if (*(uint **)(param_3 + 8) < puVar3) {
      return;
    }
    uVar4 = (*puVar1 >> 0x18) - 0x61 & 0xff;
    if (uVar4 < 7) {
      iVar5 = *(int *)(*(int *)(puVar1[2] + uVar4 * 4) + (int)puVar3 * 0xc + -0xc) << 0x10;
      if (iVar5 < 0) {
        uStack116 = 0;
        uStack112 = 0;
        puStack72 = &uStack116;
        uStack108 = 0;
      }
      else {
        puStack72 = param_1[4];
      }
      *puStack72 = *puStack72 | 0x4000;
      puStack72[2] = puStack72[2] & 0x1ffffff;
      iVar2 = FUN_0000d658((int *)param_1[5],&iStack104,&iStack100,&puStack120);
      do {
        if (iVar2 == 0) {
          if (iVar5 < 0) {
            puStack96 = *param_1;
            puStack88 = param_1[2];
            puStack84 = param_1[3];
            puStack92 = param_1[1];
            uStack48 = *puStack72;
            uStack40 = puStack72[2];
            uStack44 = puStack72[1];
            if ((*puStack72 & 1) == 0) {
              uStack48 = uStack48 | 1;
            }
            else {
              uStack48 = uStack48 & 0xfffffffe;
            }
            uStack44 = puStack72[1] - 1;
            FUN_00012bb8(&puStack96,&uStack48);
            return;
          }
          return;
        }
        if (iStack100 != 4) goto LAB_00013616;
        iVar2 = iStack104 + -0x646d6370;
        if (iStack104 == 0x646d6370) {
          uVar4 = *puStack72 & 0xffffc1ff | (*puStack120 & 0x1f) << 9;
LAB_000135d8:
          *puStack72 = uVar4;
        }
        else {
          if (iStack104 < 0x646d6371) {
            if (iStack104 == 0x7268) {
              uVar4 = *puStack72 & 0x7fff | *puStack120 << 0xf;
              goto LAB_000135d8;
            }
            if (iStack104 < 0x7269) {
              if (iStack104 == 0x616d) {
                uVar4 = puStack72[2] & 0xffffe000 | *puStack120 & 0x1fff;
              }
              else {
                if (iStack104 != 0x6d71) goto LAB_00013616;
                uVar4 = puStack72[2] & 0xff3fffff | (*puStack120 & 3) << 0x16;
              }
LAB_00013606:
              puStack72[2] = uVar4;
            }
            else {
              if (iStack104 == 0x7675) {
                puStack72[1] = *puStack120;
              }
              else {
                if (iStack104 == 0x61707962) {
                  uVar4 = puStack72[2] & 0xfeffffff | (*puStack120 & 1) << 0x18;
                  goto LAB_00013606;
                }
              }
            }
          }
          else {
            if (iVar2 == 0x9f81403) {
              *puStack72 = *puStack72 & 0xfffffffe | *puStack120 & 1;
            }
            else {
              if (iVar2 < 0x9f81404) {
                if (iVar2 == 0x1003) {
                  uVar4 = *puStack72 & 0xffffffe1 | (*puStack120 & 0xf) << 1;
                }
                else {
                  if (iVar2 != 0x9f80000) goto LAB_00013616;
                  uVar4 = *puStack72 & 0xfffffe1f | (*puStack120 & 0xf) << 5;
                }
                goto LAB_000135d8;
              }
              if (iVar2 == 0xa060202) {
                puStack72[2] = puStack72[2] & 0xffc3ffff | (*puStack120 & 0xf) << 0x12;
              }
              else {
                if (iVar2 == 0xcf80ef6) {
                  uVar4 = puStack72[2] & 0xfffc1fff | (*puStack120 & 0x1f) << 0xd;
                  goto LAB_00013606;
                }
              }
            }
          }
        }
LAB_00013616:
        iVar2 = FUN_0000d658((int *)param_1[5],&iStack104,&iStack100,&puStack120);
      } while( true );
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_000136b8(uint param_1,int param_2,undefined *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined uVar7;
  
  uVar4 = param_2 - 1U & 0xff;
  if (param_3 == (undefined *)0x0) {
    return 0x72;
  }
  uVar6 = (param_1 >> 0x18) - 0x61;
  if ((param_1 & 0xffffff) == 0x6f646c) {
    puVar1 = (undefined4 *)FUN_0000fc24(uVar6 & 0xff);
    if (puVar1 == (undefined4 *)0x0) {
      return 0x16;
    }
    puVar2 = (undefined4 *)*puVar1;
  }
  else {
    if ((param_1 & 0xffffff) != 0x706d73) {
      return 0;
    }
    puVar1 = (undefined4 *)FUN_000139dc(uVar6 & 0xff);
    if (puVar1 == (undefined4 *)0x0) {
      return 0x16;
    }
    puVar2 = (undefined4 *)*puVar1;
  }
  uVar6 = 0;
  if (uVar4 < (uint)puVar1[2]) {
    iVar3 = puVar1[3];
    iVar5 = uVar4 * 8 + 6;
    if (*(char *)(iVar3 + iVar5) != '\0') {
      if (param_3 == (undefined *)0x0) {
        iVar3 = 0x72;
      }
      else {
        uVar7 = 0xff;
        uVar6 = (uint)*(byte *)(iVar3 + iVar5);
        iVar3 = FUN_0000f65c((byte)*puVar2,
                             *(short *)(puVar1[1] + 6) + *(short *)(iVar3 + uVar4 * 8 + 4),
                             &stack0xffffffe0,0);
        if (iVar3 == 0) {
          *param_3 = uVar7;
          return 0;
        }
      }
      goto LAB_0001078c;
    }
  }
  iVar3 = 0x2f;
LAB_0001078c:
  FUN_000065ec(0x20c,puVar2[1],uVar6,uVar4,iVar3);
  return iVar3;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

int FUN_00013708(uint param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_2 - 1U & 0xff;
  if (param_3 == (int *)0x0) {
    return 0x72;
  }
  uVar4 = (param_1 >> 0x18) - 0x61;
  if ((param_1 & 0xffffff) == 0x6f646c) {
    puVar1 = (undefined4 *)FUN_0000fc24(uVar4 & 0xff);
    if (puVar1 != (undefined4 *)0x0) {
      iVar2 = FUN_0001091c(puVar1 + 1,(undefined4 *)*puVar1,uVar3,param_3);
      return iVar2;
    }
    return 0x16;
  }
  if ((param_1 & 0xffffff) != 0x706d73) {
    return 0;
  }
  puVar1 = (undefined4 *)FUN_000139dc(uVar4 & 0xff);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_0001091c(puVar1 + 1,(undefined4 *)*puVar1,uVar3,param_3);
    return iVar2;
  }
  return 0x16;
}



void FUN_00013758(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *local_18;
  
  if (*(char *)(param_2 + 3) != '\x01') {
    return;
  }
  local_18 = *(undefined4 **)(&DAT_00095d94 + param_3 * 4);
  if (local_18 != (undefined4 *)0x0) {
    return;
  }
  FUN_0000fe18(4,(int *)&local_18);
  *local_18 = param_1;
  *(undefined4 **)(&DAT_00095d94 + param_3 * 4) = local_18;
  return;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_000137c4(undefined4 param_1,ushort *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *local_30;
  byte local_2c [4];
  int local_28;
  int local_24;
  undefined4 local_20;
  
  local_30 = (undefined4 *)0x0;
  local_2c[0] = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  cVar1 = *(char *)(param_2 + 1);
  if (cVar1 == '\x03') {
    if ((*(char *)((int)param_2 + 3) != '\b') && (*(char *)((int)param_2 + 3) != '\t')) {
      return;
    }
  }
  else {
    if (cVar1 == '\x1c') {
      if ((*(char *)((int)param_2 + 3) != '\b') && (*(char *)((int)param_2 + 3) != '\t')) {
        return;
      }
    }
    else {
      if (cVar1 != '\"') {
        return;
      }
      cVar1 = *(char *)((int)param_2 + 3);
      if ((cVar1 != '\r') && ((cVar1 != '\x0e' && cVar1 != '\x0f') && cVar1 != '\x10')) {
        return;
      }
    }
  }
  local_30 = *(undefined4 **)(&DAT_00095db0 + param_3 * 4);
  if (local_30 == (undefined4 *)0x0) {
    FUN_0000fe18(0x10,(int *)&local_30);
    *local_30 = param_1;
    iVar2 = FUN_00013d80(2);
    local_30[1] = iVar2;
    if (iVar2 == 0) goto LAB_000139d0;
    iVar2 = FUN_00013da4(0x65,param_3);
    local_30[2] = iVar2;
    if (iVar2 == 0) goto LAB_000139d0;
    FUN_0000fe18(iVar2 << 3,local_30 + 3);
    if (local_30[3] == 0) goto LAB_000139d0;
    *(ushort *)(local_30[3] + 4) = *param_2;
    *(undefined4 **)(&DAT_00095db0 + param_3 * 4) = local_30;
    if (local_30 == (undefined4 *)0x0) {
      return;
    }
  }
  if ((uint)*param_2 < (uint)*(ushort *)(local_30[3] + 4)) goto LAB_000139d0;
  uVar3 = ((uint)*param_2 - (uint)*(ushort *)(local_30[3] + 4)) / (uint)*(ushort *)(local_30[1] + 2)
          & 0xffff;
  iVar2 = FUN_0000f914(param_3,&local_28);
  if (iVar2 != 0) goto LAB_000139d0;
  iVar2 = local_28;
  if (local_28 == 8) {
    iVar2 = local_24;
  }
  if ((local_28 == 8 && iVar2 == 1) && (3 < uVar3)) {
    uVar3 = (uint)(ushort)((short)uVar3 - 1);
  }
  if ((uint)local_30[2] <= uVar3) goto LAB_000139d0;
  iVar2 = uVar3 * 8 + 6;
  *(undefined *)(local_30[3] + iVar2) = *(undefined *)(param_2 + 1);
  *(ushort *)(local_30[3] + uVar3 * 8 + 4) = *param_2;
  if (*(char *)(local_30[3] + iVar2) == '\"') {
    iVar2 = FUN_0000f65c((byte)*(undefined4 *)*local_30,*param_2 + *(short *)(local_30[1] + 0xe),
                         local_2c,0);
    if (iVar2 == 0) {
      local_2c[0] = local_2c[0] & 0x60;
      if (local_2c[0] == 0x60) {
        *(undefined *)(local_30[3] + uVar3 * 8 + 7) = 1;
      }
      else {
        *(undefined *)(local_30[3] + uVar3 * 8 + 7) = 0;
      }
    }
    else {
      *(undefined *)(local_30[3] + uVar3 * 8 + 7) = 0xff;
    }
  }
  else {
    iVar2 = FUN_0000f65c((byte)*(undefined4 *)*local_30,*param_2 + *(short *)(local_30[1] + 0xc),
                         local_2c,0);
    if (iVar2 == 0) {
      *(byte *)(local_30[3] + uVar3 * 8 + 7) = local_2c[0];
    }
    else {
      *(undefined *)(local_30[3] + uVar3 * 8 + 7) = 0xff;
    }
  }
  cVar1 = *(char *)(param_2 + 1);
  iVar2 = 0;
  if (cVar1 == '\x03') {
    iVar2 = 7;
    goto LAB_000139a2;
  }
  if (cVar1 == '\x1c') {
    if (*(char *)((int)param_2 + 3) == '\b') {
      iVar2 = FUN_00013d80(6);
    }
    else {
      if (*(char *)((int)param_2 + 3) == '\t') {
        iVar2 = 0x1e;
        goto LAB_000139a2;
      }
    }
  }
  else {
    if (cVar1 == '\"') {
      cVar1 = *(char *)((int)param_2 + 3);
      if ((cVar1 == '\r') || (cVar1 == '\x0e' || cVar1 == '\x0f')) {
        iVar2 = 0x21;
      }
      else {
        if (cVar1 != '\x10') goto LAB_000139be;
        iVar2 = 0x23;
      }
LAB_000139a2:
      iVar2 = FUN_00013d80(iVar2);
    }
  }
LAB_000139be:
  *(int *)(local_30[3] + uVar3 * 8) = iVar2;
  if (iVar2 != 0) {
    return;
  }
LAB_000139d0:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 FUN_000139dc(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 7) {
    uVar1 = *(undefined4 *)(&DAT_00095db0 + param_1 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



uint FUN_000139f0(uint param_1)

{
  if ((param_1 < 7) && (*(int *)(&DAT_00095db0 + param_1 * 4) != 0)) {
    return *(uint *)(*(int *)(&DAT_00095db0 + param_1 * 4) + 8) & 0xff;
  }
  return 0;
}



int FUN_00013a0c(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  
  puVar3 = (undefined4 *)FUN_000139dc(param_1);
  uVar5 = 0;
  if (puVar3 != (undefined4 *)0x0) {
    if ((uint)puVar3[2] <= param_2) {
      iVar4 = 0x2f;
      goto LAB_00013a50;
    }
    bVar1 = *(byte *)(puVar3[3] + param_2 * 8 + 6);
    uVar5 = (uint)bVar1;
    sVar2 = *(short *)(puVar3[3] + param_2 * 8 + 4);
    bVar6 = 0;
    if (bVar1 == 3) {
      if (param_3 == 1) {
        bVar6 = 0x80;
      }
      iVar4 = FUN_0000f6f8((byte)*(undefined4 *)*puVar3,*(short *)(puVar3[1] + 0x1c) + sVar2,0xa5,0)
      ;
      if ((iVar4 == 0) &&
         (iVar4 = FUN_0000f74c((byte)*(undefined4 *)*puVar3,*(short *)(puVar3[1] + 0x2c) + sVar2,
                               0x80,bVar6,0), iVar4 == 0)) {
        return 0;
      }
      goto LAB_00013a50;
    }
  }
  iVar4 = 0x16;
LAB_00013a50:
  FUN_000065ec(0x21a,param_1,uVar5,param_2,iVar4);
  return iVar4;
}



int FUN_00013aa4(uint param_1,uint param_2,uint param_3,int param_4)

{
  char cVar1;
  ushort uVar2;
  undefined4 *puVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  puVar3 = (undefined4 *)FUN_000139dc(param_1);
  uVar7 = 0;
  if (puVar3 == (undefined4 *)0x0) {
    iVar6 = 0x16;
    goto LAB_00013b98;
  }
  if ((uint)puVar3[2] <= param_2) {
    iVar6 = 0x2f;
    goto LAB_00013b98;
  }
  if (param_3 < 3) {
    uVar5 = param_4 - 0xfa;
    if (0x226 < uVar5) {
      iVar6 = 0x14;
      goto LAB_00013b98;
    }
    uVar7 = (uint)*(byte *)(puVar3[3] + param_2 * 8 + 6);
    uVar4 = *(short *)(puVar3[1] + 0x1a) + 0x1000;
    uVar2 = *(short *)(puVar3[1] + 0x14) + *(short *)(puVar3[3] + param_2 * 8 + 4);
    cVar1 = (char)((int)uVar5 >> 0x1f);
    if (param_3 == 0) {
      FUN_0000f74c((byte)*(undefined4 *)*puVar3,uVar4,0x80,0,0);
      iVar6 = FUN_0000f74c((byte)*(undefined4 *)*puVar3,uVar2,0x30,0,0);
    }
    else {
      if (param_3 == 1) {
        FUN_0000f74c((byte)*(undefined4 *)*puVar3,uVar4,0x80,0x80,0);
        iVar6 = FUN_0000f74c((byte)*(undefined4 *)*puVar3,uVar2,0x3f,
                             ((char)((int)uVar5 / 0x32) + cVar1) -
                             ((char)((int)uVar5 / 0x3200000) + cVar1 >> 7) | 0x20,0);
      }
      else {
        if (param_3 != 2) goto LAB_00013b2c;
        FUN_0000f74c((byte)*(undefined4 *)*puVar3,uVar4,0x80,0x80,0);
        iVar6 = FUN_0000f74c((byte)*(undefined4 *)*puVar3,uVar2,0x3f,0x30,0);
      }
    }
    if (iVar6 == 0) {
      return 0;
    }
  }
  else {
LAB_00013b2c:
    iVar6 = 0x24;
  }
LAB_00013b98:
  FUN_000065ec(0x20f,param_1,uVar7,param_2,iVar6);
  return iVar6;
}



uint FUN_00013bb4(uint param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  puVar1 = (undefined4 *)FUN_000139dc(param_1);
  uVar6 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    uVar5 = 0x16;
  }
  else {
    if (param_2 < (uint)puVar1[2]) {
      if (param_3 < 5) {
        uVar6 = (uint)*(byte *)(puVar1[3] + param_2 * 8 + 6);
        bVar4 = 0;
        if (param_3 == 0) {
          bVar3 = 0xff;
        }
        else {
          if (param_3 == 2) {
            bVar3 = 0xc0;
            bVar4 = 0x40;
          }
          else {
            if (param_3 != 4) {
              uVar5 = 0xf;
              goto LAB_00013c34;
            }
            bVar3 = 0xc0;
            bVar4 = 0x80;
          }
        }
        uVar5 = FUN_0000f74c((byte)*(undefined4 *)*puVar1,
                             *(short *)(puVar1[1] + 6) + *(short *)(puVar1[3] + param_2 * 8 + 4),
                             bVar3,bVar4,0);
        if (uVar5 == 0) {
          if (DAT_00091e5c == 0) {
            return 0;
          }
          uVar2 = 0x206;
          goto LAB_00013c54;
        }
      }
      else {
        uVar5 = 0x24;
      }
    }
    else {
      uVar5 = 0x2f;
    }
  }
LAB_00013c34:
  uVar2 = 0x20c;
  param_3 = uVar5;
LAB_00013c54:
  FUN_000065ec(uVar2,param_1,uVar6,param_2,param_3);
  return uVar5;
}



int FUN_00013c86(uint param_1,uint param_2,uint param_3)

{
  byte bVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  puVar3 = (undefined4 *)FUN_000139dc(param_1);
  uVar5 = 0;
  if (puVar3 == (undefined4 *)0x0) {
LAB_00013cda:
    iVar4 = 0x16;
  }
  else {
    if ((uint)puVar3[2] <= param_2) {
      iVar4 = 0x2f;
      goto LAB_00013d46;
    }
    if (0x1f < param_3) {
      iVar4 = 0x24;
      goto LAB_00013d46;
    }
    piVar6 = puVar3 + 1;
    bVar1 = *(byte *)(puVar3[3] + param_2 * 8 + 6);
    uVar5 = (uint)bVar1;
    sVar2 = *(short *)(puVar3[3] + param_2 * 8 + 4);
    if (bVar1 == 3) {
      iVar4 = FUN_0000f6f8((byte)*(undefined4 *)*puVar3,*(short *)(*piVar6 + 0x1c) + sVar2 + 0x200,
                           0xa5,0);
      if (iVar4 != 0) goto LAB_00013d46;
      iVar4 = FUN_0000f74c((byte)*(undefined4 *)*puVar3,*(short *)(*piVar6 + 0x12) + sVar2 + 0x200,
                           0x1f,(byte)param_3,0);
    }
    else {
      if (bVar1 != 0x1c) goto LAB_00013cda;
      iVar4 = FUN_0000f6f8((byte)*(undefined4 *)*puVar3,*(short *)(*piVar6 + 0x1c) + sVar2,0xa5,0);
      if (iVar4 != 0) goto LAB_00013d46;
      iVar4 = FUN_0000f74c((byte)*(undefined4 *)*puVar3,*(short *)(*piVar6 + 0x12) + sVar2,0x1f,
                           (byte)param_3,0);
    }
    if (iVar4 == 0) {
      return 0;
    }
  }
LAB_00013d46:
  FUN_000065ec(0x210,param_1,uVar5,param_2,iVar4);
  return iVar4;
}



undefined4 FUN_00013d80(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000034e4((int *)&DAT_000917e0,(uint *)0x0,param_1,(uint *)&DAT_00095740);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = uRam00095748;
  }
  return uVar2;
}



undefined4 FUN_00013da4(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = FUN_000034e4((int *)&DAT_000917e8,(uint *)0x0,param_1,(uint *)&DAT_0009574c);
  if ((iVar1 == 0) && (param_2 < 7)) {
    return *(undefined4 *)(DAT_00095754 + param_2 * 4);
  }
  return 0;
}



undefined4 FUN_00013dd0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000034e4((int *)&DAT_000917e8,(uint *)0x0,param_1,(uint *)&DAT_0009574c);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = DAT_00095754;
  }
  return uVar2;
}



void FUN_00013df4(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  FUN_000034b4((uint *)"/rpm/pmic/target",(undefined4 *)&DAT_000917e8,param_3,param_4);
  FUN_000034b4((uint *)"/rpm/pmic/common",(undefined4 *)&DAT_000917e0,param_3,param_4);
  return;
}



// WARNING: Could not reconcile some variable overlaps

undefined4 FUN_00013e3c(undefined4 *param_1,ushort *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  iVar1 = DAT_00090168;
  local_14 = DAT_00090168;
  local_1c = 0;
  local_18 = 0;
  if (param_1 == (undefined4 *)0x0) {
    uVar3 = 0x6a;
  }
  else {
    *(undefined *)(param_2 + 1) = 0;
    *(undefined *)((int)param_2 + 3) = 0;
    *(undefined *)(param_2 + 2) = 0;
    *(undefined *)((int)param_2 + 5) = 0;
    *(undefined *)(param_2 + 3) = 0;
    *(undefined *)((int)param_2 + 7) = 0;
    FUN_0000f694((byte)*param_1,*param_2,7,(undefined *)&local_1c,0);
    uVar2 = (uint)local_18._1_1_;
    bVar4 = uVar2 != (local_18 >> 0x10 & 0xff);
    if (bVar4) {
      uVar2 = local_18 & 0xff;
    }
    if (bVar4 && uVar2 != 0) {
      *(char *)(param_2 + 1) = (char)uVar2;
      *(byte *)((int)param_2 + 3) = local_18._1_1_;
      *(undefined *)(param_2 + 3) = local_1c._1_1_;
      *(undefined *)((int)param_2 + 7) = (undefined)local_1c;
      *(undefined *)(param_2 + 2) = local_1c._3_1_;
      *(undefined *)((int)param_2 + 5) = local_1c._2_1_;
      uVar3 = 0;
    }
    else {
      uVar3 = 0x2f;
    }
  }
                    // WARNING: Subroutine does not return
  if (local_14 == iVar1) {
    return uVar3;
  }
  thunk_FUN_00000060();
}



// WARNING: Could not reconcile some variable overlaps

int FUN_00013ec4(void)

{
  int iVar1;
  uint extraout_r1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_30;
  int local_2c;
  
  iVar1 = DAT_00090168;
  local_2c = DAT_00090168;
  iVar5 = 0;
  local_30 = 0;
  uVar3 = 0;
  uVar4 = 0;
  if (DAT_000917f0 == '\0') {
    FUN_000005bc(&DAT_000957ac,0x1c,0xff);
    do {
      iVar5 = FUN_0000f694((byte)uVar3,0x102,4,(undefined *)&local_30,0);
      uVar2 = extraout_r1;
      if (iVar5 == 0) {
        uVar2 = local_30 >> 0x10 & 0xff;
      }
      if (iVar5 == 0 && uVar2 == 0x51) {
        (&DAT_00095758)[uVar4 * 3] = (uint)local_30._3_1_;
        uVar2 = (uint)local_30._1_1_;
        (&DAT_0009575c)[uVar4 * 3] = uVar2;
        (&DAT_00095760)[uVar4 * 3] = local_30 & 0xff;
        (&DAT_000957ac)[uVar4] = uVar3;
        if (local_30._3_1_ == 1) {
          if (local_30._1_1_ < 2) {
            uVar2 = uVar2 + 1;
          }
          if (local_30._1_1_ < 2) {
            (&DAT_0009575c)[uVar4 * 3] = uVar2;
          }
        }
        else {
          if (local_30._1_1_ == 0) {
            (&DAT_0009575c)[uVar4 * 3] = 1;
          }
        }
      }
      else {
        iVar5 = 0;
      }
      uVar3 = uVar3 + 2;
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar3 < 0xe && uVar4 < 7);
    DAT_000917f0 = '\x01';
  }
                    // WARNING: Subroutine does not return
  if (local_2c == iVar1) {
    return iVar5;
  }
  thunk_FUN_00000060();
}



undefined4 FUN_00013f8c(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  do {
    uVar4 = *(uint *)(DAT_00092018 + (uint)DAT_000957c8 * 0x1000 + uVar3 * 4 + 0x1900000);
    uVar2 = 0;
    do {
      if (uVar4 == 0) break;
      if ((uVar4 >> uVar2 & 1) != 0) {
        iVar1 = DAT_00092018 + (uVar2 + uVar3 * 0x20 & 0xff) * 0x1000;
        *(uint *)(iVar1 + 0x1800008) =
             *(uint *)(iVar1 + 0x1800008) & 0xffffff00 | *(uint *)(iVar1 + 0x1800004) & 0xff;
        if (DAT_000957cc != (code *)0x0) {
          (*DAT_000957cc)();
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x20);
    uVar3 = uVar3 + 1;
    if (3 < uVar3) {
      return 0;
    }
  } while( true );
}



void FUN_00013ffc(void)

{
  DAT_00090000 = 2;
  DAT_00090010 = &DAT_0009d8b0;
  DAT_00090014 = &DAT_0009dba0;
  DAT_00090018 = 0x9dc00;
  return;
}



void FUN_00014020(void)

{
  DAT_000900b4 = 1;
  return;
}



int ** FUN_0001402c(int **param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  
  FUN_0000d758();
  ppiVar1 = (int **)*param_1;
  ppiVar2 = (int **)0x0;
  if (0 < (int)param_1[2]) {
    *param_1 = *ppiVar1;
    *(int ***)(*ppiVar1 + 1) = param_1;
    param_1[2] = (int *)((int)param_1[2] + -1);
    *ppiVar1 = (int *)0x0;
    ppiVar2 = ppiVar1;
  }
  FUN_0001a7ec();
  return ppiVar2;
}



void FUN_0001405a(int param_1)

{
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



void FUN_00014064(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  param_2[1] = 0;
  return;
}



void FUN_0001406e(int param_1,int *param_2)

{
  FUN_0000d758();
  *param_2 = param_1;
  param_2[1] = *(int *)(param_1 + 4);
  **(int ***)(param_1 + 4) = param_2;
  *(int **)(param_1 + 4) = param_2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  FUN_0001a7ec();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_00014094(void)

{
  if (((((~(_DAT_6005e020 >> 0x11) & 1) != 0) && ((_DAT_6005e020 & 0x10000) == 0)) &&
      ((_DAT_6005e020 & 0x8000) == 0)) &&
     ((((_DAT_6005e020 & 0x4000) == 0 && ((_DAT_6005e020 & 0x40000) == 0)) &&
      ((_DAT_6005e020 & 1) == 0)))) {
    return 1;
  }
  return 0;
}



int FUN_000140e4(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = FUN_00000998();
  uVar2 = FUN_000009e8();
  if (iVar1 == 0x2c) {
switchD_00014102_caseD_26:
    iVar3 = -0x17fb000;
  }
  else {
    switch(iVar1) {
    case 0x20:
      if (0x1ffff < uVar2) goto switchD_00014102_caseD_26;
      iVar3 = -0x3bd5000;
      break;
    case 0x21:
    case 0x22:
    case 0x24:
    case 0x25:
    case 0x29:
    case 0x2a:
      goto switchD_00014102_caseD_21;
    case 0x23:
      if (uVar2 < 0x20000) {
        iVar3 = -0x3bd5800;
      }
      else {
        iVar3 = -0x17f8800;
      }
      break;
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x2b:
      goto switchD_00014102_caseD_26;
    default:
      iVar3 = 0x68600000;
      if (iVar1 != 0x36) {
        if (iVar1 < 0x37) {
          if (iVar1 == 0x2d) goto switchD_00014102_caseD_26;
          if (iVar1 != 0x34 && iVar1 != 0x35) {
            return 0;
          }
        }
        else {
          if (iVar1 != 0x3a && iVar1 != 0x3c) {
            return 0;
          }
        }
      }
    }
  }
  iVar3 = iVar3 + 0x728;
switchD_00014102_caseD_21:
  return iVar3;
}



int FUN_000141a0(uint param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 < DAT_00091130) {
    if (param_2 < *(byte *)(*(int *)(PTR_DAT_0009112c + param_1 * 0xf4) + 5)) {
      if (param_1 == 0) {
        iVar1 = DAT_000906a4 + 8;
      }
      else {
        iVar1 = FUN_000141ec(param_1 - 1);
        iVar1 = iVar1 + 0x10;
      }
      return iVar1 + 8 + param_2 * 0x48;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int FUN_000141ec(uint param_1)

{
  int iVar1;
  
  if (DAT_00091130 <= param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (*(byte *)(*(int *)(PTR_DAT_0009112c + param_1 * 0xf4) + 5) != 0) {
    iVar1 = FUN_000141a0(param_1,(uint)*(byte *)(*(int *)(PTR_DAT_0009112c + param_1 * 0xf4) + 5) -
                                 1);
    return iVar1 + 0x48;
  }
  iVar1 = FUN_00014224(param_1);
  return iVar1 + 8;
}



int FUN_00014224(uint param_1)

{
  int iVar1;
  
  if (DAT_00091130 <= param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (param_1 != 0) {
    iVar1 = FUN_000141ec(param_1 - 1);
    return iVar1 + 0x10;
  }
  return DAT_000906a4 + 8;
}



int FUN_00014250(uint *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_00000660(param_1,(uint *)(&PTR_s_vddmx_000903ec)[iVar2 * 9]);
    if (iVar1 == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  return -1;
}



void FUN_0001428c(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  
  bVar3 = param_1 != 0;
  uVar2 = param_2;
  if (bVar3) {
    uVar2 = 0x7ffffff;
  }
  if ((!bVar3 || param_2 <= uVar2) && (bVar3 && uVar2 != param_2)) {
    *(uint *)(param_1 + 0xc) = param_2;
    uVar1 = FUN_00016fa4(param_2);
    *(undefined *)(param_1 + 8) = (char)uVar1;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_000142aa(int param_1,uint param_2)

{
  if ((param_1 != 0) && (param_2 < 10)) {
    *(undefined *)(param_1 + 8) = (char)param_2;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Removing unreachable block (ram,0x000142ce)

void FUN_000142b8(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    piVar1 = (int *)FUN_00000154(8);
    if (piVar1 == (int *)0x0) break;
    *piVar1 = iVar3;
    iVar2 = FUN_0001ab80();
    piVar1[1] = iVar2;
    if (iVar2 == 0) break;
    FUN_000173ec((&DAT_000903fc)[iVar3 * 9],(undefined1 *)(&DAT_000903f0)[iVar3 * 9],0x18,
                 (uint)(FUN_0001514c + 1),(uint)(FUN_0001441c + 1),(uint)piVar1);
    iVar3 = iVar3 + 1;
    if (1 < iVar3) {
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00014324(int param_1,byte *param_2,int param_3)

{
  bool bVar1;
  byte *pbVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  uint extraout_r1;
  uint uVar6;
  int iVar7;
  
  if ((param_2 == (byte *)0x0) || (1 < param_1)) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (*(code **)(&DAT_0009040c + param_1 * 0x24) != (code *)0x0) {
    (**(code **)(&DAT_0009040c + param_1 * 0x24))(param_1);
  }
  iVar4 = DAT_000903e0;
  *param_2 = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  bVar5 = 0x94;
  iVar7 = param_1 * 200 + 0x94;
  bVar1 = false;
  pbVar2 = *(byte **)(DAT_000903e0 + iVar7);
  while (pbVar2 != (byte *)0x0) {
    if (param_3 != 0) {
      bVar5 = pbVar2[0x1c];
    }
    if (param_3 == 0 || bVar5 == 0) {
      if (*param_2 < *pbVar2) {
        *param_2 = *pbVar2;
      }
      bVar5 = *pbVar2;
      if (bVar5 != 0) {
        if (!bVar1) {
          bVar5 = pbVar2[0x1d];
        }
        if (!bVar1 && bVar5 == 0) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
      }
      if (param_3 == 0) {
        bVar5 = pbVar2[8];
        if (*param_2 < bVar5) {
          *param_2 = bVar5;
        }
      }
    }
    pbVar2 = *(byte **)(pbVar2 + 0x20);
  }
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 * 200 + 0x98 + iVar4 + (uint)*param_2 * 4);
  uVar3 = FUN_00016f64((uint)*param_2);
  *(undefined4 *)(param_2 + 4) = uVar3;
  iVar4 = *(int *)(DAT_000903e0 + iVar7);
  uVar6 = extraout_r1;
  while (iVar4 != 0) {
    if (param_3 != 0) {
      uVar6 = (uint)*(byte *)(iVar4 + 0x1c);
    }
    if (param_3 == 0 || uVar6 == 0) {
      if (*(uint *)(param_2 + 8) < *(uint *)(iVar4 + 0x10)) {
        *(uint *)(param_2 + 8) = *(uint *)(iVar4 + 0x10);
      }
      uVar6 = *(uint *)(iVar4 + 0x10);
      if (uVar6 != 0) {
        if (!bVar1) {
          uVar6 = (uint)*(byte *)(iVar4 + 0x1d);
        }
        if (!bVar1 && uVar6 == 0) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
      }
    }
    iVar4 = *(int *)(iVar4 + 0x20);
  }
  if (bVar1) {
    return;
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *param_2 = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  return;
}



uint FUN_0001441c(int **param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined *puVar7;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  piVar4 = *param_1;
  piVar3 = param_1[5];
  if (param_1[5] == (int *)0x0) {
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    piVar3 = &local_38;
  }
  iVar6 = *piVar4;
  piVar5 = param_1[2];
  if (iVar6 == -1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  piVar1 = (int *)FUN_0001abce((undefined4 *)piVar4[1]);
  if (piVar1 <= piVar5) {
    FUN_0001ab96((uint *)piVar4[1],(int)piVar5 + 1);
  }
  puVar7 = (undefined *)FUN_0001ab70((uint *)piVar4[1],(uint)piVar5);
  if (puVar7 == (undefined *)0x0) {
    piVar1 = (int *)FUN_00016b98();
    puVar7 = (undefined *)FUN_00014504(iVar6,piVar1 <= param_1[2],piVar5);
    FUN_0001abc0((uint *)piVar4[1],(uint)piVar5,puVar7);
  }
  FUN_000144e4(puVar7,(uint)*(byte *)(piVar3 + 2));
  FUN_00014c14(puVar7,piVar3[3]);
  FUN_00015124((int)puVar7,piVar3[1]);
  FUN_00014e60((int)puVar7,*piVar3 != 0);
  FUN_000142aa((int)puVar7,(uint)*(byte *)((int)piVar3 + 0x11));
  FUN_0001428c((int)puVar7,piVar3[5]);
  uVar2 = (uint)DAT_000901fd;
  if (DAT_000901fd == 0) {
    uVar2 = FUN_00015020();
  }
  return uVar2;
}



void FUN_000144e4(undefined *param_1,uint param_2)

{
  char cVar1;
  bool bVar2;
  
  if ((param_1 != (undefined *)0x0) && (param_2 < 10)) {
    *param_1 = (char)param_2;
    bVar2 = param_2 == 0;
    if (bVar2) {
      cVar1 = param_1[0x1e];
    }
    else {
      cVar1 = '\x01';
    }
    if (!bVar2) {
      param_1[0x1e] = cVar1;
    }
    if (!bVar2 || cVar1 != '\0') {
      param_1 = (undefined *)(uint)(byte)param_1[0x1f];
    }
    if (bVar2 && cVar1 == '\0' || param_1 == (undefined *)0x0) {
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00014504(int param_1,undefined param_2,undefined4 param_3)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  if ((param_1 < 2) && (puVar2 = (undefined *)FUN_00000154(0x24), puVar2 != (undefined *)0x0)) {
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 4) = 0;
    puVar2[8] = 0;
    *(undefined4 *)(puVar2 + 0xc) = 0;
    puVar2[0x1e] = 0;
    puVar2[0x1f] = 0;
    *(undefined4 *)(puVar2 + 0x10) = 0;
    puVar2[0x1c] = param_2;
    *(undefined4 *)(puVar2 + 0x14) = param_3;
    *(int *)(puVar2 + 0x18) = param_1;
    puVar2[0x1d] = 1;
    iVar1 = DAT_000903e0;
    iVar3 = param_1 * 200 + 0x94;
    *(undefined4 *)(puVar2 + 0x20) = *(undefined4 *)(DAT_000903e0 + iVar3);
    *(undefined **)(iVar1 + iVar3) = puVar2;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00014560(int param_1,uint param_2,uint param_3)

{
  if ((1 < param_1) || (9 < param_2)) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (param_2 != 0) {
    if (param_3 < *(uint *)(DAT_000903e0 + param_1 * 200 + param_2 * 4 + 0x94)) {
      FUN_00014560(param_1,param_2 - 1 & 0xff,param_3);
    }
    if (8 < param_2) goto LAB_000145cc;
  }
  if (*(uint *)(DAT_000903e0 + param_1 * 200 + param_2 * 4 + 0x9c) < param_3) {
    FUN_00014560(param_1,param_2 + 1 & 0xff,param_3);
  }
LAB_000145cc:
  *(uint *)(DAT_000903e0 + param_1 * 200 + param_2 * 4 + 0x98) = param_3;
  return;
}



// WARNING: Removing unreachable block (ram,0x000149ac)
// WARNING: Restarted to delay deadcode elimination for space: ram

void FUN_000145e8(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  
  iVar7 = 0;
  do {
    FUN_00014324(iVar7,(byte *)(iVar7 * 200 + 0xc + DAT_000903e0),0);
    iVar6 = DAT_000903e0;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  iVar7 = 0;
  do {
    puVar3 = (undefined4 *)(iVar7 * 200 + 0xc + iVar6);
    puVar5 = (undefined4 *)(iVar7 * 200 + 0x18 + iVar6);
    uVar9 = puVar3[1];
    uVar4 = puVar3[2];
    *puVar5 = *puVar3;
    puVar5[1] = uVar9;
    puVar5[2] = uVar4;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  iVar7 = 0;
  do {
    if ((&DAT_000903f8)[iVar7 * 0x24] == '\x01') {
      uVar8 = (uint)(byte)(&PTR_DAT_00090404)[iVar7 * 9][(&DAT_00090400)[iVar7 * 9] + -1];
      iVar11 = DAT_000903e0 + iVar7 * 200;
      iVar6 = iVar7 * 200 + 0x20;
      uVar10 = *(uint *)(DAT_000903e0 + iVar6);
      if (*(uint *)(iVar11 + uVar8 * 4 + 0x98) < uVar10) goto LAB_000149ee;
      uVar1 = (&DAT_00090400)[iVar7 * 9] - 2;
      if (-1 < (int)uVar1) {
        do {
          uVar2 = (uint)(byte)(&PTR_DAT_00090404)[iVar7 * 9][uVar1];
          if ((uVar2 < *(byte *)(DAT_000903e0 + iVar7 * 200 + 0x18)) ||
             (*(uint *)(iVar11 + uVar2 * 4 + 0x98) < uVar10)) break;
          uVar1 = uVar1 - 1;
          uVar8 = uVar2;
        } while (uVar1 < 0x80000000);
      }
      *(undefined *)(DAT_000903e0 + iVar7 * 200 + 0x18) = (char)uVar8;
      uVar4 = FUN_00016f64(uVar8);
      iVar11 = DAT_000903e0;
      *(undefined4 *)(DAT_000903e0 + iVar7 * 200 + 0x1c) = uVar4;
      *(undefined4 *)(iVar11 + iVar6) = *(undefined4 *)(iVar11 + iVar7 * 200 + uVar8 * 4 + 0x98);
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  iVar7 = 0;
  do {
    if (((&DAT_000903f8)[iVar7 * 0x24] == '\x01') &&
       (uVar8 = *(uint *)(DAT_000903e0 + iVar7 * 200 + 0x20),
       uVar8 != (&DAT_000903f4)[iVar7 * 9] * (uVar8 / (uint)(&DAT_000903f4)[iVar7 * 9])))
    goto LAB_000149ee;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  iVar6 = 0;
  iVar7 = DAT_000903e0 + DAT_000903d8 * 200;
  do {
    if ((&DAT_000903f8)[iVar6 * 0x24] == '\x01') {
      uVar8 = (uint)*(byte *)(DAT_000903e0 + iVar6 * 200 + 0x18);
      if (uVar8 < (uint)*(byte *)(iVar7 + 0x18)) {
        uVar8 = (uint)*(byte *)(iVar7 + 0x18);
      }
      *(undefined *)(iVar7 + 0x18) = (char)uVar8;
      uVar10 = *(uint *)(iVar7 + uVar8 * 4 + 0x98);
      if (uVar10 <= *(uint *)(iVar7 + 0x20)) {
        uVar10 = *(uint *)(iVar7 + 0x20);
      }
      *(uint *)(iVar7 + 0x20) = uVar10;
      uVar4 = FUN_00016f64(uVar8);
      *(undefined4 *)(iVar7 + 0x1c) = uVar4;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  FUN_00014c4c(DAT_000903d8);
  if (DAT_000903dc != -1) {
    iVar6 = DAT_000903e0 + DAT_000903dc * 200;
    if (*(byte *)(iVar6 + 0xc) < 2) {
      *(undefined *)(iVar6 + 0x18) = 1;
      uVar4 = FUN_00016f64(1);
      *(undefined4 *)(iVar6 + 0x1c) = uVar4;
      uVar4 = *(undefined4 *)(iVar6 + 0x9c);
    }
    else {
      *(undefined *)(iVar6 + 0x18) = *(undefined *)(iVar7 + 0x18);
      uVar4 = FUN_00016f64((uint)*(byte *)(iVar7 + 0x18));
      *(undefined4 *)(iVar6 + 0x1c) = uVar4;
      uVar4 = *(undefined4 *)(iVar6 + (uint)*(byte *)(iVar7 + 0x18) * 4 + 0x98);
    }
    *(undefined4 *)(iVar6 + 0x20) = uVar4;
  }
  if ((*(uint *)(DAT_000903e0 + DAT_000903d8 * 200 + 8) <
       *(uint *)(DAT_000903e0 + DAT_000903d8 * 200 + 0x20)) ||
     (*(byte *)(DAT_000903e0 + DAT_000903d8 * 200) <
      *(byte *)(DAT_000903e0 + DAT_000903d8 * 200 + 0x18))) {
    FUN_00014f0c(DAT_000903d8);
  }
  if ((DAT_000903dc != -1) &&
     ((*(uint *)(DAT_000903e0 + DAT_000903dc * 200 + 8) <
       *(uint *)(DAT_000903e0 + DAT_000903dc * 200 + 0x20) ||
      (*(byte *)(DAT_000903e0 + DAT_000903dc * 200) <
       *(byte *)(DAT_000903e0 + DAT_000903dc * 200 + 0x18))))) {
    FUN_00014f0c(DAT_000903dc);
  }
  iVar7 = 0;
  do {
    if (((&DAT_000903f8)[iVar7 * 0x24] == '\x01') &&
       ((*(int *)(DAT_000903e0 + iVar7 * 200 + 0x20) != *(int *)(DAT_000903e0 + iVar7 * 200 + 8) ||
        (*(char *)(DAT_000903e0 + iVar7 * 200 + 0x18) != *(char *)(DAT_000903e0 + iVar7 * 200))))) {
      FUN_00014f0c(iVar7);
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  if ((DAT_000903dc != -1) &&
     ((*(uint *)(DAT_000903e0 + DAT_000903dc * 200 + 0x20) <
       *(uint *)(DAT_000903e0 + DAT_000903dc * 200 + 8) ||
      (*(byte *)(DAT_000903e0 + DAT_000903dc * 200 + 0x18) <
       *(byte *)(DAT_000903e0 + DAT_000903dc * 200))))) {
    FUN_00014f0c(DAT_000903dc);
  }
  if ((*(uint *)(DAT_000903e0 + DAT_000903d8 * 200 + 0x20) <
       *(uint *)(DAT_000903e0 + DAT_000903d8 * 200 + 8)) ||
     (*(byte *)(DAT_000903e0 + DAT_000903d8 * 200 + 0x18) <
      *(byte *)(DAT_000903e0 + DAT_000903d8 * 200))) {
    if (param_1 == 0) {
      FUN_00014f0c(DAT_000903d8);
    }
    else {
      DAT_000906a0 = DAT_000906a0 + 1;
    }
  }
  iVar7 = 0;
  while (((param_1 != 0 && (iVar7 == DAT_000903d8)) ||
         ((*(int *)(DAT_000903e0 + iVar7 * 200 + 0x20) == *(int *)(DAT_000903e0 + iVar7 * 200 + 8)
          && (*(byte *)(DAT_000903e0 + iVar7 * 200) <= *(byte *)(DAT_000903e0 + DAT_000903d8 * 200))
          )))) {
    iVar7 = iVar7 + 1;
    if (1 < iVar7) {
      return;
    }
  }
LAB_000149ee:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined4 FUN_00014a48(int param_1,uint param_2)

{
  if ((param_1 < 2) && (param_2 < 10)) {
    return *(undefined4 *)(DAT_000903e0 + param_1 * 200 + param_2 * 4 + 0x98);
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00014a7c(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((param_1 < 2) && (param_2 != (undefined4 *)0x0)) {
    puVar1 = (undefined4 *)(DAT_000903e0 + param_1 * 200);
    uVar3 = puVar1[1];
    uVar2 = puVar1[2];
    *param_2 = *puVar1;
    param_2[1] = uVar3;
    param_2[2] = uVar2;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00014ab4(int param_1,int param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  byte abStack40 [8];
  uint local_20;
  byte abStack28 [8];
  uint local_14;
  
  bVar3 = SBORROW4(2,param_1);
  iVar1 = -param_1;
  bVar2 = param_1 == 2;
  if (param_1 < 2) {
    bVar3 = SBORROW4(2,param_2);
    iVar1 = -param_2;
    bVar2 = param_2 == 2;
  }
  if (!bVar2 && iVar1 + 2 < 0 == bVar3) {
    FUN_00014324(param_1,abStack40,1);
    FUN_00014324(param_2,abStack28,1);
    *param_3 = local_20;
    if (local_14 < local_20) {
      *param_4 = local_20;
    }
    else {
      *param_4 = local_14;
    }
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00014b00(void)

{
  int iVar1;
  undefined *puVar2;
  
  DAT_000903e0 = (undefined4 *)FUN_00000154(400);
  if (DAT_000903e0 != (undefined4 *)0x0) {
    FUN_00000610(DAT_000903e0,400);
    DAT_000903dc = FUN_00014250((uint *)"vdda_ebi");
    DAT_000903d8 = FUN_00014250((uint *)"vddmx");
    if (DAT_000903d8 != -1) {
      FUN_00014e6c();
      FUN_000142b8();
      FUN_00015044();
      DAT_0009015c = &DAT_000903e0;
      DAT_00090160 = &DAT_0001b1bc;
      iVar1 = FUN_00014250((uint *)"vddcx");
      if (iVar1 != -1) {
        puVar2 = (undefined *)FUN_00014504(iVar1,1,0x65);
        FUN_000144e4(puVar2,3);
        puVar2 = (undefined *)FUN_00014504(iVar1,0,0x6c);
        FUN_000144e4(puVar2,1);
        FUN_00014e60((int)puVar2,1);
        puVar2 = (undefined *)FUN_00014504(DAT_000903d8,1,0x66);
        FUN_000144e4(puVar2,3);
        puVar2 = (undefined *)FUN_00014504(DAT_000903d8,0,0x6d);
        FUN_000144e4(puVar2,1);
        FUN_00014e60((int)puVar2,1);
        if (DAT_000903dc == -1) {
          return;
        }
        puVar2 = (undefined *)FUN_00014504(DAT_000903dc,1,0x6f);
        FUN_000144e4(puVar2,1);
        puVar2 = (undefined *)FUN_00014504(DAT_000903dc,0,0x70);
        FUN_000144e4(puVar2,1);
        FUN_00014e60((int)puVar2,1);
        return;
      }
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00014c14(undefined *param_1,uint param_2)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  bool bVar4;
  
  bVar4 = param_1 != (undefined *)0x0;
  uVar3 = param_2;
  if (bVar4) {
    uVar3 = 0x7ffffff;
  }
  if ((!bVar4 || param_2 <= uVar3) && (bVar4 && uVar3 != param_2)) {
    *(uint *)(param_1 + 4) = param_2;
    bVar4 = param_2 == 0;
    if (bVar4) {
      cVar2 = param_1[0x1f];
    }
    else {
      cVar2 = '\x01';
    }
    if (!bVar4) {
      param_1[0x1f] = cVar2;
    }
    if (!bVar4 || cVar2 != '\0') {
      uVar1 = FUN_00016fa4(param_2);
      *param_1 = (char)uVar1;
    }
    cVar2 = param_1[0x1e];
    bVar4 = cVar2 != '\0';
    if (bVar4) {
      cVar2 = param_1[0x1f];
    }
    if (!bVar4 || cVar2 == '\0') {
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00014c4c(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  iVar1 = (&DAT_00090400)[param_1 * 9];
  uVar5 = (uint)(byte)(&PTR_DAT_00090404)[param_1 * 9][iVar1 + -1];
  uVar6 = 0x20;
  iVar7 = DAT_000903e0 + param_1 * 200;
  iVar9 = param_1 * 200 + 0x20;
  uVar8 = *(uint *)(DAT_000903e0 + iVar9);
  if (*(uint *)(iVar7 + uVar5 * 4 + 0x98) < uVar8) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  uVar2 = iVar1 - 2;
  iVar10 = param_1 * 200 + 0x18;
  if (-1 < (int)uVar2) {
    uVar6 = (uint)*(byte *)(DAT_000903e0 + iVar10);
  }
  if (uVar2 != 0xffffffff && iVar1 + -1 < 0 == SBORROW4(uVar2,-1)) {
    do {
      uVar4 = (uint)(byte)(&PTR_DAT_00090404)[param_1 * 9][uVar2];
      if ((uVar4 < uVar6) || (*(uint *)(iVar7 + uVar4 * 4 + 0x98) < uVar8)) break;
      uVar2 = uVar2 - 1;
      uVar5 = uVar4;
    } while (uVar2 < 0x80000000);
  }
  *(undefined *)(DAT_000903e0 + iVar10) = (char)uVar5;
  uVar3 = FUN_00016f64(uVar5);
  iVar1 = DAT_000903e0;
  *(undefined4 *)(DAT_000903e0 + param_1 * 200 + 0x1c) = uVar3;
  *(undefined4 *)(iVar1 + iVar9) = *(undefined4 *)(iVar1 + param_1 * 200 + uVar5 * 4 + 0x98);
  return;
}



void FUN_00014d10(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  
  if (DAT_00090434 == 0) {
    param_1 = *(int *)(param_1 + 8);
  }
  if (DAT_00090434 == 0 && param_1 == 0) {
    cVar1 = *(char *)(param_2 + 8);
    bVar2 = cVar1 == '\x03';
    if (bVar2) {
      cVar1 = '\x04';
    }
    if (bVar2) {
      *(char *)(param_2 + 8) = cVar1;
    }
    return;
  }
  return;
}



void FUN_00014d30(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  if (((param_2 < 4) && (param_3 != 0)) && (param_1 < 2)) {
    iVar3 = DAT_000903e0 + param_1 * 200;
    bVar1 = (&DAT_0001b47c)[param_2];
    if (bVar1 == 0) {
      if (param_2 == 0) {
        iVar2 = *(int *)(iVar3 + 0x4c);
        if (iVar2 == 0) {
          iVar3 = iVar3 + (uint)bVar1 * 0x38;
          while (*(int *)(iVar3 + iVar2 * 8 + 0x24) != 0) {
            iVar2 = iVar2 + 1;
            if (4 < iVar2) {
              return;
            }
          }
LAB_00014dac:
          iVar3 = iVar3 + iVar2 * 8;
          *(int *)(iVar3 + 0x24) = param_3;
          *(undefined4 *)(iVar3 + 0x28) = param_4;
          return;
        }
      }
      else {
        if (param_2 == 2) {
          param_1 = *(int *)(iVar3 + 0x54);
        }
        if (param_2 == 2 && param_1 == 0) {
          *(int *)(iVar3 + 0x54) = param_3;
          *(undefined4 *)(iVar3 + 0x58) = param_4;
          return;
        }
      }
    }
    else {
      if (bVar1 == 1) {
        iVar2 = DAT_000903e0 + param_1 * 200;
        if (param_2 == 1) {
          if (*(int *)(iVar3 + 0x8c) == 0) {
            iVar2 = 1;
            iVar3 = iVar3 + (uint)bVar1 * 0x38;
            while (*(int *)(iVar3 + iVar2 * 8 + 0x24) != 0) {
              iVar2 = iVar2 + 1;
              if (6 < iVar2) {
                return;
              }
            }
            goto LAB_00014dac;
          }
        }
        else {
          bVar4 = param_2 == 3;
          if (bVar4) {
            param_2 = *(uint *)(iVar3 + 0x5c);
          }
          if (bVar4 && param_2 == 0) {
            *(int *)(iVar3 + 0x5c) = param_3;
          }
          if (bVar4 && param_2 == 0) {
            *(undefined4 *)(iVar2 + 0x60) = param_4;
            return;
          }
        }
      }
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00014e1c(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_00014560(param_1,param_2,param_3);
  iVar2 = 0;
  iVar1 = DAT_000903e0 + param_1 * 200;
  do {
    if (*(uint *)(iVar1 + iVar2 * 4 + 0x9c) < *(uint *)(iVar1 + iVar2 * 4 + 0x98)) {
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 9);
  return;
}



void FUN_00014e60(int param_1,undefined param_2)

{
  if (param_1 == 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  *(undefined *)(param_1 + 0x1d) = param_2;
  return;
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00014e6c(void)

{
  int iVar1;
  undefined4 uStack32;
  int iStack24;
  
  iVar1 = FUN_00000998();
  FUN_000056c0(&uStack32);
  if (DAT_00090434 != 0) {
    DAT_00090434 = -1;
  }
  if (iVar1 != 0x3a) {
    return;
  }
  if (uStack32 == 1) {
    if (iStack24 == 0) {
      DAT_00090434 = 0;
      return;
    }
LAB_00014ecc:
    if (iStack24 != 1) {
LAB_00014ed2:
      if (iStack24 != 2) {
        return;
      }
      DAT_00090434 = 2;
      return;
    }
  }
  else {
    if (uStack32 == 8) {
      if (iStack24 == 0 || iStack24 == 3) {
        DAT_00090434 = 0;
        return;
      }
    }
    else {
      if (uStack32 == 1) goto LAB_00014ecc;
      if (uStack32 != 8) {
        if (uStack32 == 1) goto LAB_00014ed2;
        if (uStack32 != 8) {
          if (uStack32 != 0x15) {
            return;
          }
          if (iStack24 != 1) {
            return;
          }
          DAT_00090434 = 2;
          return;
        }
        goto LAB_00014eee;
      }
    }
    if (iStack24 != 1) {
LAB_00014eee:
      if (iStack24 != 2) {
        return;
      }
      DAT_00090434 = 2;
      return;
    }
  }
  DAT_00090434 = 1;
  return;
}



void FUN_00014f0c(int param_1)

{
  uint *local_28;
  int iVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  puVar6 = (undefined4 *)(DAT_000903e0 + param_1 * 200);
  uVar7 = puVar6[8];
  puVar5 = puVar6 + 6;
  iVar4 = 0;
  do {
    pcVar2 = (code *)(puVar6 + iVar4 * 2)[9];
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(puVar5,(puVar6 + iVar4 * 2)[10]);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 7);
  FUN_000065ec(0x28a,param_1,puVar6[8],0,0);
  if (*(uint *)(DAT_000903e0 + param_1 * 200 + 8) != uVar7) {
    iVar4 = DAT_000903e0 + param_1 * 200;
    if (((&DAT_000903fc)[param_1 * 9] & 0xffffff) == 0x6f646c) {
      local_28 = *(uint **)(iVar4 + 0xc4);
      if (uVar7 == 0) {
        uVar3 = *local_28 & 0xfffffffe;
      }
      else {
        uVar3 = *local_28 | 1;
      }
      local_28[3] = uVar7;
      *local_28 = uVar3;
      uVar7 = *(uint *)(iVar4 + 0xc0);
      iVar1 = (&DAT_000903f0)[param_1 * 9];
      iVar4 = (&DAT_000903fc)[param_1 * 9];
      uVar3 = 0x10;
    }
    else {
      if (((&DAT_000903fc)[param_1 * 9] & 0xffffff) != 0x706d73) {
                    // WARNING: Subroutine does not return
        FUN_00000060();
      }
      local_28 = *(uint **)(iVar4 + 0xc4);
      if (uVar7 == 0) {
        uVar3 = *local_28 & 0xfffffffe;
      }
      else {
        uVar3 = *local_28 | 1;
      }
      local_28[1] = uVar7;
      *local_28 = uVar3;
      uVar7 = *(uint *)(iVar4 + 0xc0);
      iVar1 = (&DAT_000903f0)[param_1 * 9];
      iVar4 = (&DAT_000903fc)[param_1 * 9];
      uVar3 = 0xc;
    }
    FUN_00016e4c(iVar4,iVar1,uVar7,uVar3,local_28);
  }
  puVar6[2] = puVar6[8];
  *puVar6 = *puVar5;
  puVar6[1] = puVar6[7];
  iVar4 = 0;
  do {
    pcVar2 = (code *)(puVar6 + iVar4 * 2 + 0xe)[9];
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(puVar5,(puVar6 + iVar4 * 2 + 0xe)[10]);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 7);
  return;
}



void FUN_00015020(void)

{
  int iVar1;
  
  if (DAT_0009069c != '\0') {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  DAT_0009069c = 1;
  iVar1 = FUN_00018338();
  FUN_000145e8(iVar1);
  DAT_0009069c = 0;
  return;
}



// WARNING: Removing unreachable block (ram,0x00015054)

void FUN_00015044(void)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte *pbVar6;
  uint uVar7;
  undefined4 uVar8;
  
  uVar7 = 0;
  do {
    pbVar6 = (byte *)(DAT_000903e0 + uVar7 * 200);
    puVar2 = (undefined4 *)(&PTR_DAT_00090408)[uVar7 * 9];
    uVar4 = puVar2[1];
    uVar5 = puVar2[2];
    uVar8 = puVar2[3];
    *(undefined4 *)(pbVar6 + 0x98) = *puVar2;
    *(undefined4 *)(pbVar6 + 0x9c) = uVar4;
    *(undefined4 *)(pbVar6 + 0xa0) = uVar5;
    *(undefined4 *)(pbVar6 + 0xa4) = uVar8;
    uVar4 = puVar2[5];
    uVar5 = puVar2[6];
    uVar8 = puVar2[7];
    *(undefined4 *)(pbVar6 + 0xa8) = puVar2[4];
    *(undefined4 *)(pbVar6 + 0xac) = uVar4;
    *(undefined4 *)(pbVar6 + 0xb0) = uVar5;
    *(undefined4 *)(pbVar6 + 0xb4) = uVar8;
    uVar4 = puVar2[9];
    *(undefined4 *)(pbVar6 + 0xb8) = puVar2[8];
    *(undefined4 *)(pbVar6 + 0xbc) = uVar4;
    bVar1 = (&DAT_000903f9)[uVar7 * 0x24];
    uVar8 = *(undefined4 *)(pbVar6 + (uint)bVar1 * 4 + 0x98);
    *pbVar6 = bVar1;
    uVar4 = FUN_00016f64((uint)bVar1);
    *(undefined4 *)(pbVar6 + 4) = uVar4;
    *(undefined4 *)(pbVar6 + 8) = uVar8;
    iVar3 = FUN_00016aa6((&DAT_000903fc)[uVar7 * 9],(&DAT_000903f0)[uVar7 * 9],0,uVar5);
    *(int *)(pbVar6 + 0xc0) = iVar3;
    if (((&DAT_000903fc)[uVar7 * 9] & 0xffffff) == 0x6f646c) {
      puVar2 = (undefined4 *)FUN_00000154(0x10);
      *(undefined4 **)(pbVar6 + 0xc4) = puVar2;
      if (puVar2 == (undefined4 *)0x0) goto LAB_00015110;
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
    }
    else {
      if (((&DAT_000903fc)[uVar7 * 9] & 0xffffff) != 0x706d73) {
LAB_00015110:
                    // WARNING: Subroutine does not return
        FUN_00000060();
      }
      puVar2 = (undefined4 *)FUN_00000154(0xc);
      *(undefined4 **)(pbVar6 + 0xc4) = puVar2;
      if (puVar2 == (undefined4 *)0x0) goto LAB_00015110;
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
    }
    uVar7 = uVar7 + 1;
    if (1 < uVar7) {
      return;
    }
  } while( true );
}



void FUN_00015124(int param_1,int param_2)

{
  if ((param_1 != 0) &&
     ((param_2 == 0 || ((&DAT_000903fa)[*(int *)(param_1 + 0x18) * 0x24] != '\0')))) {
    *(int *)(param_1 + 0x10) = param_2;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0001514c(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *local_30;
  int local_2c;
  int local_28;
  
  uVar6 = *(uint *)(param_1 + 8) & 0xff;
  puVar5 = *(uint **)(param_1 + 0x10);
  uVar2 = FUN_0000d61a(*(int **)(param_1 + 0x14));
  do {
    if (uVar2 != 0) {
      FUN_00014d10(param_1,(int)puVar5);
      return;
    }
    FUN_0000d658(*(int **)(param_1 + 0x14),&local_2c,&local_28,&local_30);
    if (local_28 == 0) {
      if (local_2c == 0x6c637772) {
LAB_000151f4:
        *(undefined *)(puVar5 + 2) = 0;
      }
      else {
        if (local_2c < 0x6c637773) {
          if (local_2c == 0x7675) {
            puVar5[1] = 0;
          }
          else {
            if (local_2c == 0x636676) {
              *(undefined *)((int)puVar5 + 0x11) = 0;
            }
            else {
              if (local_2c == 0x6c6676) {
                puVar5[5] = 0;
              }
            }
          }
        }
        else {
          if (local_2c == 0x6c766c76) {
            puVar5[3] = 0;
          }
          else {
            if (local_2c == 0x6e657773) {
              *puVar5 = 0;
            }
            else {
              if (local_2c == 0x6e726f63) goto LAB_000151f4;
            }
          }
        }
      }
    }
    else {
      if (local_2c == 0x6c637772) {
        if (local_28 != 4) goto LAB_000152e0;
        uVar2 = *local_30;
        *(char *)(puVar5 + 2) = (char)(uVar2 & 0xff);
        if ((uVar2 & 0xff) != 0) {
          (&DAT_000942d4)[uVar6 * 2] = 1;
          cVar1 = (&DAT_000942d5)[uVar6 * 2];
joined_r0x0001527e:
          if (cVar1 != '\0') {
LAB_000152e0:
                    // WARNING: Subroutine does not return
            FUN_00000060();
          }
        }
      }
      else {
        if (local_2c < 0x6c637772) {
          if (local_2c == 0x7675) {
            if (local_28 != 4) goto LAB_000152e0;
            puVar5[1] = *local_30;
          }
          else {
            puVar4 = (undefined4 *)(local_2c + -0x636676);
            if (puVar4 == (undefined4 *)0x0) {
              if (local_28 != 4) goto LAB_000152e0;
              uVar2 = *local_30;
              if (6 >= uVar2) {
                puVar4 = (undefined4 *)(uVar2 & 0xff);
              }
              if (6 < uVar2 || (undefined4 *)0x8 < puVar4) goto LAB_000152e0;
              cVar1 = (&DAT_0001b480)[uVar2];
              *(char *)((int)puVar5 + 0x11) = cVar1;
              if (cVar1 != '\0') {
                (&DAT_000942d4)[uVar6 * 2] = 1;
                cVar1 = (&DAT_000942d5)[uVar6 * 2];
                goto joined_r0x0001527e;
              }
            }
            else {
              if (puVar4 == &DAT_00090000) {
                if (local_28 != 4) goto LAB_000152e0;
                uVar2 = *local_30;
                puVar5[5] = uVar2;
                if (uVar2 != 0) {
                  (&DAT_000942d5)[uVar6 * 2] = 1;
                  cVar1 = (&DAT_000942d4)[uVar6 * 2];
                  goto joined_r0x0001527e;
                }
              }
            }
          }
        }
        else {
          if (local_2c == 0x6c766c76) {
            if (local_28 != 4) goto LAB_000152e0;
            uVar2 = *local_30;
            puVar5[3] = uVar2;
            if (uVar2 != 0) {
              (&DAT_000942d5)[uVar6 * 2] = 1;
              cVar1 = (&DAT_000942d4)[uVar6 * 2];
              goto joined_r0x0001527e;
            }
          }
          else {
            if (local_2c == 0x6e657773) {
              if (local_28 != 4) goto LAB_000152e0;
              *puVar5 = *local_30;
            }
            else {
              uVar2 = local_2c + 0x918d909d;
              if (uVar2 == 0) {
                if (local_28 != 4) goto LAB_000152e0;
                uVar3 = *local_30;
                if (6 >= uVar3) {
                  uVar2 = uVar3 & 0xff;
                }
                if (6 < uVar3 || 8 < uVar2) goto LAB_000152e0;
                cVar1 = (&DAT_0001b480)[uVar3];
                *(char *)(puVar5 + 2) = cVar1;
                if (cVar1 != '\0') {
                  (&DAT_000942d4)[uVar6 * 2] = 1;
                  cVar1 = (&DAT_000942d5)[uVar6 * 2];
                  goto joined_r0x0001527e;
                }
              }
            }
          }
        }
      }
    }
    uVar2 = FUN_0000d61a(*(int **)(param_1 + 0x14));
  } while( true );
}



void FUN_00015318(int **param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(char *)(*param_1 + 1) != '\x02') {
    return;
  }
  iVar4 = 0;
  if (*(char *)((int)*param_1 + 5) != '\0') {
    do {
      iVar2 = 0;
      do {
        iVar3 = **param_1;
        iVar1 = iVar2 + 3;
        iVar5 = iVar4 * 0x2c + iVar2 * 2;
        iVar2 = iVar2 + 1;
        *(short *)(iVar3 + iVar5) =
             (short)((uint)(*(int *)(iVar3 + iVar4 * 0x2c + 0x1c) * (*param_1)[iVar1]) / 1000000) +
             *(short *)(iVar3 + iVar5) + (short)*(undefined4 *)(iVar3 + iVar4 * 0x2c + 0x20);
      } while (iVar2 < 8);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)*(byte *)((int)*param_1 + 5));
    return;
  }
  return;
}



void FUN_0001532c(int **param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  do {
    iVar2 = 0;
    do {
      iVar3 = **param_1;
      iVar1 = iVar2 + 3;
      iVar4 = param_4 * 0x2c + iVar2 * 2;
      iVar2 = iVar2 + 1;
      *(short *)(iVar3 + iVar4) =
           (short)((uint)(*(int *)(iVar3 + param_4 * 0x2c + 0x1c) * (*param_1)[iVar1]) / 1000000) +
           *(short *)(iVar3 + iVar4) + (short)*(undefined4 *)(iVar3 + param_4 * 0x2c + 0x20);
    } while (iVar2 < 8);
    param_4 = param_4 + 1;
  } while (param_4 < (int)(uint)*(byte *)((int)*param_1 + 5));
  return;
}



void FUN_00015434(int param_1,uint param_2)

{
  if (param_2 < 10) {
    if (*(int *)(param_1 + param_2 * 4 + 0x34) != -1) {
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int FUN_00015448(int **param_1,uint param_2)

{
  if ((param_2 < 10) && (param_1[param_2 + 0xd] != (int *)0xffffffff)) {
    return **param_1 + (int)param_1[param_2 + 0xd] * 0x2c;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0001558c(void)

{
  int **ppiVar1;
  int iVar2;
  
  iVar2 = 0;
  ppiVar1 = (int **)PTR_DAT_0009112c;
  if (0 < DAT_00091130) {
    do {
      if (*(char *)(ppiVar1 + 8) != '\0') {
        FUN_00016256(ppiVar1);
        FUN_000055fe((int)ppiVar1[7],1);
        FUN_00005376((int)ppiVar1[7]);
        *(int *)(&DAT_e000e280 + (uint)(*(byte *)((int)ppiVar1[1] + 0x16) >> 5) * 4) =
             1 << ((uint)*(byte *)((int)ppiVar1[1] + 0x16) & 0x1f);
        FUN_00005648((int)ppiVar1[7],(uint)*(byte *)((int)ppiVar1[1] + 0x19));
        FUN_00005630((int)ppiVar1[7],(uint)*(byte *)((int)ppiVar1[1] + 0x1a));
        FUN_000053e6((int)ppiVar1[7],1);
      }
      iVar2 = iVar2 + 1;
      ppiVar1 = ppiVar1 + 0x3d;
    } while (iVar2 < DAT_00091130);
    return;
  }
  return;
}



int FUN_00015604(uint *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  undefined **ppuVar4;
  
  if (param_2 == 0) {
    return 0;
  }
  ppuVar4 = (undefined **)0x0;
  uVar3 = 0;
  do {
    iVar1 = FUN_00000660(param_1,(uint *)(&PTR_s_vddmx_00091af4)[uVar3 * 3]);
    if (iVar1 == 0) {
      ppuVar4 = &PTR_s_vddmx_00091af4 + uVar3 * 3;
      break;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 3);
  if (ppuVar4 != (undefined **)0x0) {
    puVar2 = (undefined *)0x0;
    if (ppuVar4[1] != (undefined *)0x0) {
      do {
        if ((uint)(byte)ppuVar4[2][(int)puVar2 * 0xc] == param_2) {
          return (int)*(short *)(ppuVar4[2] + (int)puVar2 * 0xc + 4);
        }
        puVar2 = puVar2 + 1;
      } while (puVar2 < ppuVar4[1]);
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int FUN_0001560c(uint *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  undefined **ppuVar4;
  
  ppuVar4 = (undefined **)0x0;
  uVar3 = 0;
  do {
    iVar1 = FUN_00000660(param_1,(uint *)(&PTR_s_vddmx_00091af4)[uVar3 * 3]);
    if (iVar1 == 0) {
      ppuVar4 = &PTR_s_vddmx_00091af4 + uVar3 * 3;
      break;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 3);
  if (ppuVar4 != (undefined **)0x0) {
    puVar2 = (undefined *)0x0;
    if (ppuVar4[1] != (undefined *)0x0) {
      do {
        if ((uint)(byte)ppuVar4[2][(int)puVar2 * 0xc] == param_2) {
          return (int)*(short *)(ppuVar4[2] + (int)puVar2 * 0xc + 4);
        }
        puVar2 = puVar2 + 1;
      } while (puVar2 < ppuVar4[1]);
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Removing unreachable block (ram,0x00015694)

void FUN_00015680(void)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint **ppuVar8;
  uint uVar9;
  uint uVar10;
  undefined *puVar11;
  bool bVar12;
  
  uVar10 = 0;
  do {
    uVar7 = 0;
    if ((&DAT_00091af8)[uVar10 * 3] != 0) {
      do {
        puVar11 = (&PTR_DAT_00091afc)[uVar10 * 3] + uVar7 * 0xc;
        iVar6 = 0;
        uVar5 = 0;
        iVar4 = 0;
        if (puVar11[2] != 0) {
          do {
            ppuVar8 = (uint **)(*(int *)(puVar11 + 8) + iVar4 * 0xc);
            iVar3 = 0;
            uVar9 = (uint)ppuVar8[2] >> (int)ppuVar8[1];
            while (uVar9 != 0) {
              iVar3 = iVar3 + 1;
              uVar9 = uVar9 >> 1;
            }
            uVar5 = uVar5 << iVar3 | (**ppuVar8 & (uint)ppuVar8[2]) >> (int)ppuVar8[1];
            iVar4 = iVar4 + 1;
            iVar6 = iVar6 + iVar3;
          } while (iVar4 < (int)(uint)(byte)puVar11[2]);
        }
        uVar9 = 1 << iVar6 + -1;
        sVar2 = (short)uVar9;
        uVar1 = sVar2 - 1U & (ushort)uVar5;
        puVar11[1] = (char)iVar6;
        *(ushort *)(puVar11 + 4) = uVar1;
        bVar12 = (uVar9 & uVar5) != 0;
        if (bVar12) {
          sVar2 = -uVar1;
        }
        if (bVar12) {
          *(short *)(puVar11 + 4) = sVar2;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(&DAT_00091af8)[uVar10 * 3]);
    }
    uVar10 = uVar10 + 1;
  } while (uVar10 < 3);
  return;
}



void FUN_0001573c(int **param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  bVar1 = *(byte *)(param_1 + 9);
  uVar11 = (uint)bVar1;
  *(undefined *)((int)param_1 + 0x22) = 1;
  FUN_00005380((int)param_1[7],(int)(param_1 + 0x17));
  DAT_0009043c = FUN_00005478((int)param_1[7]);
  FUN_00005376((int)param_1[7]);
  FUN_00005576((int)param_1[7],(int)(param_1 + 0x17),bVar1);
  uVar2 = FUN_00015434((int)param_1,uVar11);
  FUN_000165ec((uint)*(byte *)((int)param_1 + 0x21),uVar2);
  iVar3 = FUN_00015448(param_1,uVar11);
  uVar10 = *(uint *)(iVar3 + 0x14);
  uVar9 = *(uint *)(iVar3 + 0x18);
  uVar4 = FUN_00014a48((int)param_1[6],uVar11);
  uVar2 = DAT_0009043c;
  if ((DAT_0009043c & 0x10) == 0) {
    uVar5 = DAT_0009043c & 4;
    if (uVar5 != 0) {
      uVar5 = 0xffffffff;
      *(short *)((int)param_1 + 0xee) = *(short *)((int)param_1 + 0xee) + 1;
    }
  }
  else {
    uVar5 = 1;
    *(short *)(param_1 + 0x3b) = *(short *)(param_1 + 0x3b) + 1;
  }
  uVar7 = param_1[1][3] * uVar5 + uVar4;
  uVar5 = uVar7;
  if (uVar7 <= uVar9) {
    uVar5 = uVar9;
  }
  uVar8 = uVar10;
  if ((uVar5 <= uVar10) && (uVar8 = uVar7, uVar7 <= uVar9)) {
    uVar8 = uVar9;
  }
  if ((uVar2 & 4) == 0) {
    if ((uVar2 & 0x10) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 2;
    }
  }
  else {
    uVar6 = 1;
  }
  FUN_000065ec(0x29f,(uint)*(byte *)((int)param_1 + 0x21),uVar11,uVar6,0);
  FUN_000065ec(0x2a0,(uint)*(byte *)((int)param_1 + 0x21),(uint)(uVar8 == uVar9),
               (uint)(uVar8 == uVar10),uVar8);
  if (uVar4 == uVar8) {
    *(short *)(param_1 + 0x3c) = *(short *)(param_1 + 0x3c) + 1;
  }
  else {
    *(short *)((int)param_1 + 0xe6) = *(short *)((int)param_1 + 0xe6) + 1;
    FUN_00014e1c((int)param_1[6],uVar11,uVar8);
    uVar2 = FUN_00015434((int)param_1,uVar11);
    FUN_000166c4((uint)*(byte *)((int)param_1 + 0x21),uVar2,uVar8);
    FUN_00015020();
  }
  if (uVar8 == uVar9) {
    *(short *)(param_1 + 0x3a) = *(short *)(param_1 + 0x3a) + 1;
    uVar2 = FUN_00015434((int)param_1,uVar11);
    FUN_00016618((uint)*(byte *)((int)param_1 + 0x21),uVar2);
  }
  if (uVar8 == uVar10) {
    *(short *)((int)param_1 + 0xea) = *(short *)((int)param_1 + 0xea) + 1;
    uVar2 = FUN_00015434((int)param_1,uVar11);
    FUN_00016608((uint)*(byte *)((int)param_1 + 0x21),uVar2);
  }
  *(undefined *)((int)param_1 + 0x22) = 0;
  FUN_00005380((int)param_1[7],(int)(param_1 + 0x17));
  if (*(char *)(param_1 + 8) == '\0') {
    if (*(char *)(param_1 + 9) == '\0') {
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 9) != '\0') {
      FUN_000054d2((int)param_1[7],(uint)(uVar4 != uVar8));
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_000158fe(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined *param_4)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int **ppiVar4;
  int iVar5;
  
  *param_1 = 1;
  FUN_00015680();
  iVar3 = FUN_00015c44();
  if (iVar3 == 0) {
    FUN_00015958();
  }
  FUN_00016634();
  iVar3 = 0;
  if (0 < DAT_00091130) {
    do {
      puVar1 = PTR_DAT_0009112c;
      iVar5 = iVar3 * 0xf4 + 0x21;
      ppiVar4 = (int **)(PTR_DAT_0009112c + iVar3 * 0xf4);
      PTR_DAT_0009112c[iVar5] = (char)iVar3;
      FUN_00015a90(ppiVar4,puVar1,iVar5,param_4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00091130);
  }
  puVar1 = PTR_DAT_0009112c;
  if (*(char *)(*(int *)(PTR_DAT_0009112c + 0xf4) + 4) != '\x02') {
    return;
  }
  iVar3 = 0;
  do {
    FUN_00005484(*(int *)(puVar1 + 0x110),*(uint *)(&DAT_0001b4e8 + iVar3 * 4) & 0xff,1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  if (DAT_00090434 == 0) {
    uVar2 = FUN_000009e8();
    if (uVar2 == 0x10000) {
      iVar3 = 0;
      do {
        FUN_00005484(*(int *)(puVar1 + 0x110),*(uint *)(&DAT_0001b4f0 + iVar3 * 4) & 0xff,1);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 2);
    }
    if (DAT_00090434 == 0) {
      return;
    }
  }
  iVar3 = 0;
  do {
    FUN_00005328(*(int *)(puVar1 + 0x110),(&DAT_0001b4f8)[iVar3] & 0xff,1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 6);
  return;
}



// WARNING: Removing unreachable block (ram,0x00015990)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00015958(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  
  if (DAT_00090439 != '\0') {
    return;
  }
  DAT_00090439 = 1;
  uVar2 = FUN_000009e8();
  uVar7 = _DAT_60058004 << 6;
  uVar8 = _DAT_6005800c << 0x15;
  iVar3 = FUN_00000998();
  piVar10 = (int *)0x0;
  iVar5 = 0;
  do {
    if (*(int *)(PTR_DAT_00090d88 + iVar5 * 0xc + 8) == iVar3) {
      piVar10 = (int *)(PTR_DAT_00090d88 + iVar5 * 0xc);
      break;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 1);
  if (piVar10 == (int *)0x0) {
    return;
  }
  iVar5 = 0;
  iVar3 = 0;
  if (0 < *piVar10) {
    iVar9 = piVar10[1];
    do {
      if (uVar2 < *(uint *)(iVar9 + iVar3 * 0xc + 4)) break;
      uVar4 = 0;
      uVar11 = *(uint *)(iVar9 + iVar3 * 0xc + 8);
      if (uVar11 != 0) {
        iVar6 = *(int *)(iVar9 + iVar3 * 0xc);
        do {
          if ((*(uint *)(iVar6 + uVar4 * 0xc + 4) == uVar7 >> 0x1f) &&
             (*(uint *)(iVar6 + uVar4 * 0xc + 8) == uVar8 >> 0x1d)) {
            iVar5 = *(int *)(iVar6 + uVar4 * 0xc);
            break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar11);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *piVar10);
    if (iVar5 != 0) goto LAB_00015a4e;
  }
  iVar5 = **(int **)piVar10[1];
  *(undefined *)(iVar5 + 4) = 1;
LAB_00015a4e:
  iVar3 = DAT_00091130;
  puVar1 = PTR_DAT_0009112c;
  iVar9 = 0;
  if (DAT_00091130 < 1) {
    return;
  }
  do {
    iVar6 = iVar9 + 1;
    *(int *)(puVar1 + iVar9 * 0xf4) = iVar5 + iVar9 * 0x2c;
    iVar9 = iVar6;
  } while (iVar6 < iVar3);
  return;
}



// WARNING: Removing unreachable block (ram,0x00015990)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00015962(int param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  
  *(undefined *)(param_1 + 1) = 1;
  uVar2 = FUN_000009e8();
  uVar7 = _DAT_60058004 << 6;
  uVar8 = _DAT_6005800c << 0x15;
  iVar3 = FUN_00000998();
  piVar10 = (int *)0x0;
  iVar5 = 0;
  do {
    if (*(int *)(PTR_DAT_00090d88 + iVar5 * 0xc + 8) == iVar3) {
      piVar10 = (int *)(PTR_DAT_00090d88 + iVar5 * 0xc);
      break;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 1);
  if (piVar10 == (int *)0x0) {
    return;
  }
  iVar5 = 0;
  iVar3 = 0;
  if (0 < *piVar10) {
    iVar9 = piVar10[1];
    do {
      if (uVar2 < *(uint *)(iVar9 + iVar3 * 0xc + 4)) break;
      uVar4 = 0;
      uVar11 = *(uint *)(iVar9 + iVar3 * 0xc + 8);
      if (uVar11 != 0) {
        iVar6 = *(int *)(iVar9 + iVar3 * 0xc);
        do {
          if ((*(uint *)(iVar6 + uVar4 * 0xc + 4) == uVar7 >> 0x1f) &&
             (*(uint *)(iVar6 + uVar4 * 0xc + 8) == uVar8 >> 0x1d)) {
            iVar5 = *(int *)(iVar6 + uVar4 * 0xc);
            break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar11);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *piVar10);
    if (iVar5 != 0) goto LAB_00015a4e;
  }
  iVar5 = **(int **)piVar10[1];
  *(undefined *)(iVar5 + 4) = 1;
LAB_00015a4e:
  iVar3 = DAT_00091130;
  puVar1 = PTR_DAT_0009112c;
  iVar9 = 0;
  if (DAT_00091130 < 1) {
    return;
  }
  do {
    iVar6 = iVar9 + 1;
    *(int *)(puVar1 + iVar9 * 0xf4) = iVar5 + iVar9 * 0x2c;
    iVar9 = iVar6;
  } while (iVar6 < iVar3);
  return;
}



void FUN_00015a90(int **param_1,undefined4 param_2,undefined4 param_3,undefined *param_4)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 extraout_r1;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  int **ppiVar8;
  bool bVar9;
  
  piVar3 = *param_1;
  bVar9 = piVar3 != (int *)0x0;
  if (bVar9) {
    piVar3 = (int *)(uint)*(byte *)(piVar3 + 1);
  }
  if (!bVar9 || piVar3 == (int *)0x0) {
    return;
  }
  iVar4 = 0;
  do {
    pcVar6 = (code *)(param_1 + iVar4);
    iVar4 = iVar4 + 1;
    ((int **)pcVar6)[0xd] = (int *)0xffffffff;
  } while (iVar4 < 10);
  piVar3 = (int *)0x0;
  if (*(char *)((int)*param_1 + 5) != '\0') {
    pcVar6 = FUN_00000010;
    do {
      param_4 = (undefined *)((int)piVar3 * 0x2c + 0x10);
      if (9 < (byte)((code *)param_4)[**param_1]) goto LAB_00015b74;
      param_1[(uint)(byte)((code *)param_4)[**param_1] + 0xd] = piVar3;
      piVar3 = (int *)((int)piVar3 + 1);
    } while ((int)piVar3 < (int)(uint)*(byte *)((int)*param_1 + 5));
  }
  piVar3 = (int *)FUN_00014250((uint *)param_1[1][2]);
  param_1[6] = piVar3;
  if (piVar3 != (int *)0xffffffff) {
    FUN_00015318(param_1);
    if ((*(char *)((int)*param_1 + 6) == '\0') &&
       (ppiVar8 = (int **)0x0, *(char *)((int)*param_1 + 5) != '\0')) {
      do {
        iVar4 = **param_1;
        pcVar6 = (code *)((int)ppiVar8 * 0x2c + 0x24);
        param_4 = *(code **)(iVar4 + (int)pcVar6);
        if ((code *)param_4 == (code *)0x0) {
          FUN_000163c4((int)param_1,iVar4 + (int)ppiVar8 * 0x2c);
        }
        else {
          pcVar6 = (code *)ppiVar8;
          (*(code *)param_4)(iVar4 + (int)ppiVar8 * 0x2c,param_1);
        }
        ppiVar8 = (int **)((int)ppiVar8 + 1);
      } while ((int)ppiVar8 < (int)(uint)*(byte *)((int)*param_1 + 5));
    }
    if (*(char *)(*param_1 + 1) == '\x01') {
      return;
    }
    piVar3 = (int *)FUN_00005438((uint *)param_1[1][2]);
    param_1[7] = piVar3;
    if (piVar3 != (int *)0x0) {
      FUN_00015b78((int)param_1,extraout_r1,pcVar6,param_4);
      if (*(char *)((int)*param_1 + 7) != '\0') {
        FUN_000164a0(param_1);
      }
      piVar3 = (int *)FUN_000065c0(param_1,(ushort)*(byte *)((int)param_1[1] + 0x16));
      param_1[0xc] = piVar3;
      FUN_00014d30((int)param_1[6],0,0x161cb,param_1);
      FUN_00014d30((int)param_1[6],1,(int)&LAB_00016168_1,param_1);
      FUN_000055fe((int)param_1[7],1);
      FUN_00005376((int)param_1[7]);
      FUN_0000d57c((uint)*(byte *)((int)param_1[1] + 0x16),&LAB_00015dec_1);
      FUN_0000d4f0((uint)*(byte *)((int)param_1[1] + 0x16),0);
      *(int *)(&DAT_e000e280 + (uint)(*(byte *)((int)param_1[1] + 0x16) >> 5) * 4) =
           1 << ((uint)*(byte *)((int)param_1[1] + 0x16) & 0x1f);
      iVar4 = (uint)(*(byte *)((int)param_1[1] + 0x16) >> 5) * 4;
      iVar2 = 1 << ((uint)*(byte *)((int)param_1[1] + 0x16) & 0x1f);
      *(int *)(&DAT_e000e280 + iVar4) = iVar2;
      *(int *)(&DAT_e000e100 + iVar4) = iVar2;
      FUN_00014a7c((int)param_1[6],param_1 + 9);
      if (*(byte *)(param_1 + 9) == 0) {
        return;
      }
      iVar4 = FUN_00015448(param_1,(uint)*(byte *)(param_1 + 9));
      uVar7 = 0;
      do {
        uVar1 = *(ushort *)(iVar4 + uVar7 * 2);
        uVar5 = (uint)*(byte *)((int)param_1[1] + 0x1b);
        if (uVar1 == 0) {
          uVar5 = 0;
        }
        FUN_00005566((int)param_1[7],uVar7 & 0xff,uVar5,(uint)uVar1);
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < 8);
      FUN_00005420((int)param_1[7],4,1);
      iVar4 = FUN_00015448(param_1,(uint)*(byte *)(param_1 + 9));
      if (param_1[0xb] < *(int **)(iVar4 + 0x14)) {
        FUN_000056a4((int)param_1[7],(uint)*(byte *)((int)param_1[1] + 0x17));
        FUN_00005420((int)param_1[7],0x10,1);
      }
      else {
        FUN_000056a4((int)param_1[7],0xffffffff);
        FUN_00005420((int)param_1[7],0x10,0);
      }
      FUN_000053e6((int)param_1[7],1);
      *(undefined *)(param_1 + 8) = 1;
      return;
    }
  }
LAB_00015b74:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00015b78(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  
  iVar1 = FUN_000015c0(**(uint ***)(param_1 + 4),(int *)(param_1 + 8));
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0xc) == '\0') {
      *(undefined *)(param_1 + 0xc) = 1;
      FUN_000012a0(*(undefined4 **)(param_1 + 8),extraout_r1,param_3,param_4);
    }
    iVar1 = FUN_000015c0(*(uint **)(*(int *)(param_1 + 4) + 4),(int *)(param_1 + 0x10));
    if (iVar1 == 0) {
      if (*(char *)(param_1 + 0x14) == '\0') {
        *(undefined *)(param_1 + 0x14) = 1;
        FUN_000012a0(*(undefined4 **)(param_1 + 0x10),extraout_r1_00,param_3,param_4);
      }
      FUN_000054b8(*(int *)(param_1 + 0x1c),0);
      iVar1 = 0;
      if (*(char *)(*(int *)(param_1 + 4) + 0x24) != '\0') {
        do {
          FUN_00005484(*(int *)(param_1 + 0x1c),
                       (uint)*(byte *)(*(int *)(*(int *)(param_1 + 4) + 0x20) + iVar1),1);
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)(uint)*(byte *)(*(int *)(param_1 + 4) + 0x24));
      }
      FUN_0000535c(*(int *)(param_1 + 0x1c),0);
      FUN_00005678(*(int *)(param_1 + 0x1c),*(byte *)(*(int *)(param_1 + 4) + 0x15),
                   (uint)*(byte *)(*(int *)(param_1 + 4) + 0x14));
      FUN_000056a4(*(int *)(param_1 + 0x1c),(uint)*(byte *)(*(int *)(param_1 + 4) + 0x17));
      FUN_00005660(*(int *)(param_1 + 0x1c),(uint)*(byte *)(*(int *)(param_1 + 4) + 0x18));
      FUN_00005648(*(int *)(param_1 + 0x1c),(uint)*(byte *)(*(int *)(param_1 + 4) + 0x19));
      FUN_00005630(*(int *)(param_1 + 0x1c),(uint)*(byte *)(*(int *)(param_1 + 4) + 0x1a));
      FUN_000055d0(*(int *)(param_1 + 0x1c),(uint)*(byte *)(*(int *)(param_1 + 4) + 0x1c));
      FUN_000047f4(*(byte **)(param_1 + 0x1c));
      FUN_00004822(*(int *)(param_1 + 0x1c));
      iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + 8);
      *(uint *)(iVar1 + 0x4c) = *(uint *)(iVar1 + 0x4c) & 0x100ff | 0x100;
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_00015c44(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int in_r3;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  int local_28;
  
  local_28 = in_r3;
  piVar3 = (int *)FUN_00019bfc(0x1d9,&local_28);
  _DAT_00080070 = 2;
  if ((piVar3 == (int *)0x0) || (*piVar3 != 2)) {
    _DAT_00080070 = 0;
    return 0;
  }
  if (piVar3[1] * 0x13c + 8 != local_28) {
LAB_00015de4:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  uVar10 = 0;
  if (piVar3[1] != 0) {
    do {
      piVar8 = piVar3 + uVar10 * 0x4f;
      piVar1 = piVar8 + 2;
      if ((*(char *)piVar1 != '\0') && (iVar9 = 0, 0 < DAT_00091130)) {
LAB_00015cc6:
        iVar4 = FUN_00000660(*(uint **)(*(int *)(PTR_DAT_0009112c + iVar9 * 0xf4 + 4) + 8),
                             (uint *)((int)piVar8 + 9));
        if (iVar4 != 0) goto code_r0x00015ce2;
        iVar4 = FUN_00014250((uint *)((int)piVar8 + 9));
        uVar7 = 2;
        do {
          FUN_00014e1c(iVar4,uVar7 & 0xff,piVar1[uVar7 + 5]);
          uVar7 = uVar7 + 1;
        } while ((int)uVar7 < 10);
        piVar5 = (int *)FUN_00000154(0x2c);
        if (piVar5 == (int *)0x0) goto LAB_00015de4;
        *piVar5 = 0;
        piVar5[1] = 0;
        piVar5[2] = 0;
        piVar5[3] = 0;
        piVar5[4] = 0;
        piVar5[5] = 0;
        piVar5[6] = 0;
        piVar5[7] = 0;
        piVar5[8] = 0;
        piVar5[9] = 0;
        piVar5[10] = 0;
        *(undefined *)((int)piVar5 + 7) = 0;
        *(char *)(piVar5 + 1) = *(char *)piVar1;
        if (7 < (uint)piVar8[0x11]) goto LAB_00015de4;
        uVar7 = piVar8[0x11] & 0xff;
        *(undefined *)((int)piVar5 + 5) = (char)uVar7;
        iVar4 = FUN_00000154(uVar7 * 0x2c);
        *piVar5 = iVar4;
        if (iVar4 == 0) goto LAB_00015de4;
        iVar4 = 0;
        if (*(char *)((int)piVar5 + 5) != '\0') {
          do {
            piVar6 = (int *)(*piVar5 + iVar4 * 0x2c);
            piVar8 = piVar1 + iVar4 * 9;
            iVar11 = piVar8[0x11];
            iVar12 = piVar8[0x12];
            iVar13 = piVar8[0x13];
            *piVar6 = piVar8[0x10];
            piVar6[1] = iVar11;
            piVar6[2] = iVar12;
            piVar6[3] = iVar13;
            iVar4 = iVar4 + 1;
            iVar11 = piVar8[0x15];
            iVar12 = piVar8[0x16];
            iVar13 = piVar8[0x17];
            piVar6[4] = piVar8[0x14];
            piVar6[5] = iVar11;
            piVar6[6] = iVar12;
            piVar6[7] = iVar13;
            piVar6[8] = piVar8[0x18];
          } while (iVar4 < (int)(uint)*(byte *)((int)piVar5 + 5));
        }
        cVar2 = *(char *)(piVar5 + 1);
        bVar14 = cVar2 != '\0';
        if (bVar14) {
          cVar2 = '\x01';
        }
        if (bVar14) {
          *(char *)((int)piVar5 + 6) = cVar2;
        }
        *(int **)(PTR_DAT_0009112c + iVar9 * 0xf4) = piVar5;
      }
LAB_00015dca:
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uint)piVar3[1]);
  }
  _DAT_00080070 = 0;
  return 1;
code_r0x00015ce2:
  iVar9 = iVar9 + 1;
  if (DAT_00091130 <= iVar9) goto LAB_00015dca;
  goto LAB_00015cc6;
}



uint FUN_00015e34(int **param_1,uint param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = 0;
  bVar1 = *(byte *)((int)*param_1 + 5);
  iVar6 = 0;
  if (bVar1 != 0) {
    iVar2 = **param_1;
    do {
      if ((uint)*(byte *)(iVar2 + iVar6 * 0x2c + 0x11) == param_2) {
        iVar9 = iVar2 + iVar6 * 0x2c;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uint)bVar1);
    if (iVar9 != 0) {
      uVar5 = *(uint *)(iVar9 + 0x14);
      uVar7 = *(uint *)(iVar9 + 0x18);
      uVar3 = uVar5 + param_1[1][4] * param_3;
      uVar8 = uVar7;
      if (uVar7 < uVar3) {
        uVar8 = uVar3;
      }
      uVar4 = uVar5;
      if ((uVar8 <= uVar5) && (uVar4 = uVar3, uVar3 <= uVar7)) {
        uVar4 = uVar7;
      }
      uVar8 = param_1[1][3];
      iVar6 = uVar4 - uVar8 * (uVar4 / uVar8);
      if (iVar6 != 0) {
        uVar4 = uVar4 + (uVar8 - iVar6);
      }
      if (uVar5 == uVar8 * (uVar5 / uVar8)) {
        if (uVar5 < uVar4) {
          uVar4 = uVar5;
        }
        return uVar4;
      }
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00015ec4(int param_1)

{
  byte bVar1;
  
  FUN_00005616(*(int *)(param_1 + 0x1c),0);
  FUN_000055fe(*(int *)(param_1 + 0x1c),0);
  FUN_00005630(*(int *)(param_1 + 0x1c),0);
  FUN_00005648(*(int *)(param_1 + 0x1c),0);
  FUN_00005420(*(int *)(param_1 + 0x1c),0x14,0);
  FUN_00005376(*(int *)(param_1 + 0x1c));
  FUN_000054d2(*(int *)(param_1 + 0x1c),1);
  FUN_000054d2(*(int *)(param_1 + 0x1c),0);
  FUN_000053e6(*(int *)(param_1 + 0x1c),0);
  FUN_00005376(*(int *)(param_1 + 0x1c));
  bVar1 = *(byte *)(*(int *)(param_1 + 4) + 0x16);
  *(int *)(&DAT_e000e280 + (uint)(bVar1 >> 5) * 4) = 1 << ((uint)bVar1 & 0x1f);
  FUN_00006558(*(int *)(param_1 + 0x30));
  return;
}



void FUN_00015f3c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int **ppiVar6;
  
  ppiVar6 = (int **)(PTR_DAT_0009112c + 0xf4);
  iVar1 = FUN_00015604("vddcx",(uint)*(byte *)(param_1 + 0x11));
  iVar2 = FUN_00015604("vddmx",(uint)*(byte *)(param_1 + 0x11));
  iVar3 = FUN_00015604("vddapc0",(uint)*(byte *)(param_1 + 0x11));
  if (iVar3 < iVar1) {
    iVar3 = iVar1;
  }
  uVar4 = FUN_00015e34(ppiVar6,(uint)*(byte *)(param_1 + 0x11),iVar3);
  uVar5 = FUN_00015e34((int **)param_2,(uint)*(byte *)(param_1 + 0x11),iVar2);
  if (uVar4 <= uVar5) {
    uVar4 = FUN_00015e34((int **)param_2,(uint)*(byte *)(param_1 + 0x11),iVar2);
  }
  uVar5 = *(uint *)(*(int *)(param_2 + 4) + 0xc);
  iVar3 = uVar4 - uVar5 * (uVar4 / uVar5);
  if (iVar3 != 0) {
    uVar4 = uVar4 + (uVar5 - iVar3);
  }
  if (uVar4 <= *(uint *)(param_1 + 0x14)) {
    FUN_00014e1c(*(int *)(param_2 + 0x18),(uint)*(byte *)(param_1 + 0x10),uVar4);
    *(uint *)(param_1 + 0x14) = uVar4;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00015fe0(int param_1,int **param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined *puVar9;
  int iVar10;
  undefined *puVar11;
  undefined *puVar12;
  
  iVar10 = **param_2 + param_3 * 0x2c;
  if (DAT_00090434 != 0) {
    FUN_000163c4((int)param_2,iVar10);
    return;
  }
  iVar2 = FUN_00015604("vddcx",(uint)*(byte *)(param_1 + 0x11));
  iVar3 = FUN_00015604("vddapc0",(uint)*(byte *)(param_1 + 0x11));
  puVar4 = *(undefined **)(param_1 + 0x14);
  if (iVar3 < iVar2) {
    iVar3 = iVar2;
  }
  iVar7 = iVar3;
  if (0 < iVar3) {
    iVar7 = 0;
  }
  puVar9 = &LAB_00009c40 +
           *(int *)(iVar10 + 0x28) + (uint)((int)puVar4 * 0x5a) / 100 + iVar7 * 10000;
  uVar8 = param_2[1][3];
  if (puVar9 + -(uVar8 * ((uint)puVar9 / uVar8)) != (undefined *)0x0) {
    puVar9 = puVar9 + (uVar8 - (int)(puVar9 + -(uVar8 * ((uint)puVar9 / uVar8))));
  }
  if (puVar9 < *(undefined **)(param_1 + 0x18)) {
    puVar9 = *(undefined **)(param_1 + 0x18);
  }
  if (puVar4 < puVar9) {
    puVar9 = puVar4;
  }
  if (*(char *)((int)param_2[1] + 0x25) == '\0') {
    *(undefined **)(param_1 + 0x18) = puVar9;
  }
  puVar11 = puVar4 + param_2[1][4] * iVar3;
  puVar5 = *(undefined **)(param_1 + 0x18);
  puVar9 = puVar11;
  if (puVar11 <= puVar5) {
    puVar9 = puVar5;
  }
  puVar12 = puVar4;
  if ((puVar9 <= puVar4) && (puVar12 = puVar11, puVar11 <= puVar5)) {
    puVar12 = puVar5;
  }
  uVar8 = param_2[1][3];
  if (puVar12 + -(uVar8 * ((uint)puVar12 / uVar8)) != (undefined *)0x0) {
    puVar12 = puVar12 + (uVar8 - (int)(puVar12 + -(uVar8 * ((uint)puVar12 / uVar8))));
  }
  if (puVar4 < puVar12) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  FUN_00014e1c((int)param_2[6],(uint)*(byte *)(param_1 + 0x10),(uint)puVar12);
  *(undefined **)(param_1 + 0x14) = puVar12;
  uVar8 = FUN_00015434((int)param_2,(uint)*(byte *)(param_1 + 0x10));
  FUN_00016710((uint)*(byte *)((int)param_2 + 0x21),uVar8,puVar12);
  if (iVar3 - iVar2 == 0) {
    return;
  }
  if (*(char *)(*param_2 + 1) != '\x02') {
    return;
  }
  uVar8 = param_2[1][3];
  uVar6 = param_2[1][4] * (iVar3 - iVar2);
  iVar10 = uVar6 - uVar8 * (uVar6 / uVar8);
  if (iVar10 != 0) {
    uVar6 = uVar6 + (uVar8 - iVar10);
  }
  iVar10 = 0;
  do {
    sVar1 = (short)((uVar6 * (*param_2)[iVar10 + 3]) / 1000000) + *(short *)(param_1 + iVar10 * 2);
    *(short *)(param_1 + iVar10 * 2) = sVar1;
    *(short *)(param_1 + iVar10 * 2) = sVar1 + (short)*(undefined4 *)(param_1 + 0x20);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 8);
  return;
}



// WARNING: Heritage AFTER dead removal. Example location: s0xffffffe0 : 0x0001622e
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_000161ca(byte *param_1,int **param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  byte local_20 [16];
  
  if (param_1 == (byte *)0x0 || param_2 == (int **)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  FUN_0000da64(local_20,0xc,param_2 + 9,0xc);
  FUN_0000da64(param_2 + 9,0xc,param_1,0xc);
  bVar1 = *(byte *)((int)param_2 + 0x22);
  bVar6 = bVar1 == 0;
  if (!bVar6) {
    bVar1 = *param_1;
  }
  if ((bVar6 || bVar1 == 0) && (*(char *)(param_2 + 8) != '\0')) {
    FUN_00015ec4((int)param_2);
    *(undefined *)(param_2 + 8) = 0;
  }
  bVar1 = *param_1;
  if ((uint)bVar1 != (uint)local_20[0] && bVar1 != 0) {
    iVar3 = FUN_00015448(param_2,(uint)bVar1);
    uVar5 = 0;
    do {
      uVar2 = *(ushort *)(iVar3 + uVar5 * 2);
      uVar4 = (uint)*(byte *)((int)param_2[1] + 0x1b);
      if (uVar2 == 0) {
        uVar4 = 0;
      }
      FUN_00005566((int)param_2[7],uVar5 & 0xff,uVar4,(uint)uVar2);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 8);
    return;
  }
  return;
}



void FUN_00016256(int **param_1)

{
  int iVar1;
  
  iVar1 = FUN_00015448(param_1,(uint)*(byte *)(param_1 + 9));
  if (param_1[0xb] != *(int **)(iVar1 + 0x18)) {
    FUN_00005420((int)param_1[7],4,1);
    FUN_00005616((int)param_1[7],0);
  }
  if (param_1[0xb] == *(int **)(iVar1 + 0x18)) {
    FUN_00005420((int)param_1[7],4,0);
    FUN_00005616((int)param_1[7],1);
  }
  if (param_1[0xb] == *(int **)(iVar1 + 0x14)) {
    FUN_000056a4((int)param_1[7],0xffffffff);
    FUN_00005420((int)param_1[7],0x10,0);
    return;
  }
  FUN_000056a4((int)param_1[7],(uint)*(byte *)((int)param_1[1] + 0x17));
  FUN_00005420((int)param_1[7],0x10,1);
  return;
}



void FUN_000162d4(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = PTR_DAT_0009112c;
  if (0 < DAT_00091130) {
    do {
      if (puVar1[0x20] != '\0') {
        FUN_00005616(*(int *)(puVar1 + 0x1c),0);
        FUN_000055fe(*(int *)(puVar1 + 0x1c),0);
        FUN_00005630(*(int *)(puVar1 + 0x1c),0);
        FUN_00005648(*(int *)(puVar1 + 0x1c),0);
        FUN_00005420(*(int *)(puVar1 + 0x1c),0x14,0);
        FUN_00005376(*(int *)(puVar1 + 0x1c));
        FUN_000054d2(*(int *)(puVar1 + 0x1c),1);
        FUN_000054d2(*(int *)(puVar1 + 0x1c),0);
        FUN_000053e6(*(int *)(puVar1 + 0x1c),0);
        FUN_00005376(*(int *)(puVar1 + 0x1c));
        *(int *)(&DAT_e000e280 + (uint)(*(byte *)(*(int *)(puVar1 + 4) + 0x16) >> 5) * 4) =
             1 << ((uint)*(byte *)(*(int *)(puVar1 + 4) + 0x16) & 0x1f);
        FUN_00006558(*(int *)(puVar1 + 0x30));
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0xf4;
    } while (iVar2 < DAT_00091130);
    return;
  }
  return;
}



void FUN_00016374(int param_1)

{
  byte bVar1;
  
  FUN_000055fe(*(int *)(param_1 + 0x1c),1);
  FUN_00005376(*(int *)(param_1 + 0x1c));
  bVar1 = *(byte *)(*(int *)(param_1 + 4) + 0x16);
  *(int *)(&DAT_e000e280 + (uint)(bVar1 >> 5) * 4) = 1 << ((uint)bVar1 & 0x1f);
  FUN_00005648(*(int *)(param_1 + 0x1c),(uint)*(byte *)(*(int *)(param_1 + 4) + 0x19));
  FUN_00005630(*(int *)(param_1 + 0x1c),(uint)*(byte *)(*(int *)(param_1 + 4) + 0x1a));
  FUN_000053e6(*(int *)(param_1 + 0x1c),1);
  return;
}



void FUN_000163c4(int param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint uVar6;
  undefined *puVar7;
  undefined *puVar8;
  
  iVar1 = FUN_00015604(*(undefined4 *)(*(int *)(param_1 + 4) + 8),(uint)*(byte *)(param_2 + 0x11));
  puVar2 = *(undefined **)(param_2 + 0x14);
  iVar3 = iVar1;
  if (0 < iVar1) {
    iVar3 = 0;
  }
  puVar4 = &LAB_00009c40 +
           *(int *)(param_2 + 0x28) + (uint)((int)puVar2 * 0x5a) / 100 + iVar3 * 10000;
  uVar6 = *(uint *)(*(int *)(param_1 + 4) + 0xc);
  if (puVar4 + -(uVar6 * ((uint)puVar4 / uVar6)) != (undefined *)0x0) {
    puVar4 = puVar4 + (uVar6 - (int)(puVar4 + -(uVar6 * ((uint)puVar4 / uVar6))));
  }
  if (puVar4 < *(undefined **)(param_2 + 0x18)) {
    puVar4 = *(undefined **)(param_2 + 0x18);
  }
  if (puVar2 < puVar4) {
    puVar4 = puVar2;
  }
  if (*(char *)(*(int *)(param_1 + 4) + 0x25) == '\0') {
    *(undefined **)(param_2 + 0x18) = puVar4;
  }
  puVar7 = puVar2 + *(int *)(*(int *)(param_1 + 4) + 0x10) * iVar1;
  puVar5 = *(undefined **)(param_2 + 0x18);
  puVar4 = puVar7;
  if (puVar7 <= puVar5) {
    puVar4 = puVar5;
  }
  puVar8 = puVar2;
  if ((puVar4 <= puVar2) && (puVar8 = puVar7, puVar7 <= puVar5)) {
    puVar8 = puVar5;
  }
  uVar6 = *(uint *)(*(int *)(param_1 + 4) + 0xc);
  if (puVar8 + -(uVar6 * ((uint)puVar8 / uVar6)) != (undefined *)0x0) {
    puVar8 = puVar8 + (uVar6 - (int)(puVar8 + -(uVar6 * ((uint)puVar8 / uVar6))));
  }
  if (puVar2 < puVar8) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  FUN_00014e1c(*(int *)(param_1 + 0x18),(uint)*(byte *)(param_2 + 0x10),(uint)puVar8);
  *(undefined **)(param_2 + 0x14) = puVar8;
  uVar6 = FUN_00015434(param_1,(uint)*(byte *)(param_2 + 0x10));
  FUN_00016710((uint)*(byte *)(param_1 + 0x21),uVar6,puVar8);
  return;
}



void FUN_000164a0(int **param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  byte abStack56 [4];
  byte local_34;
  byte local_32;
  byte local_30 [12];
  
  puVar4 = (undefined *)FUN_00014504((int)param_1[6],1,0x6b);
  uVar7 = (uint)*(byte *)(param_1[1] + 6);
  uVar7 = uVar7 - (*(byte *)((int)param_1[1] + 0x17) + uVar7 >> 1);
  if ((-1 < (int)uVar7) && (param_1[7][2] != 0)) {
    iVar11 = 0;
    if (*(char *)((int)*param_1 + 7) != '\0') {
      do {
        bVar1 = *(byte *)((*param_1)[2] + iVar11);
        uVar10 = (uint)bVar1;
        FUN_000144e4(puVar4,uVar10);
        FUN_00015020();
        FUN_00014a7c((int)param_1[6],(undefined4 *)local_30);
        if ((uint)local_30[0] != uVar10) goto LAB_000165e8;
        iVar5 = FUN_00015448(param_1,uVar10);
        uVar9 = 0;
        do {
          uVar3 = *(ushort *)(iVar5 + uVar9 * 2);
          uVar8 = (uint)*(byte *)((int)param_1[1] + 0x1b);
          if (uVar3 == 0) {
            uVar8 = 0;
          }
          FUN_00005566((int)param_1[7],uVar9 & 0xff,uVar8,(uint)uVar3);
          uVar9 = uVar9 + 1;
        } while ((int)uVar9 < 8);
        FUN_000053e6((int)param_1[7],1);
        FUN_000054e4((int)param_1[7],abStack56,uVar8);
        FUN_000053e6((int)param_1[7],0);
        FUN_000053e6((int)param_1[7],1);
        while( true ) {
          FUN_000054e4((int)param_1[7],abStack56,uVar8);
          iVar5 = FUN_00014a48((int)param_1[6],uVar10);
          uVar8 = iVar5 - param_1[1][3];
          bVar12 = false;
          bVar13 = local_32 == 0;
          bVar2 = local_32;
          if (!bVar13) {
            bVar2 = local_34;
          }
          uVar9 = (uint)bVar2;
          if (!bVar13) {
            bVar12 = (int)(uVar9 - uVar7) < 0;
          }
          if ((bVar13 || uVar9 == uVar7) || bVar12 != (!bVar13 && SBORROW4(uVar9,uVar7))) break;
          if (9 < bVar1) goto LAB_000165e8;
          piVar6 = (param_1 + uVar10)[0xd];
          if (piVar6 == (int *)0xffffffff) goto LAB_000165e8;
          if (uVar8 < *(uint *)(**param_1 + (int)piVar6 * 0x2c + 0x18)) break;
          FUN_00014e1c((int)param_1[6],uVar10,uVar8);
          piVar6 = (param_1 + uVar10)[0xd];
          if (piVar6 == (int *)0xffffffff) goto LAB_000165e8;
          FUN_000166c4((uint)*(byte *)((int)param_1 + 0x21),(uint)piVar6,uVar8);
          FUN_00015020();
          FUN_000054d2((int)param_1[7],1);
        }
        FUN_000053e6((int)param_1[7],0);
        iVar11 = iVar11 + 1;
      } while (iVar11 < (int)(uint)*(byte *)((int)*param_1 + 7));
    }
    FUN_000144e4(puVar4,0);
    return;
  }
LAB_000165e8:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_000165ec(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = FUN_000141a0(param_1,param_2);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  *(int *)(DAT_000906a4 + 4) = *(int *)(DAT_000906a4 + 4) + 1;
  return;
}



void FUN_00016608(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = FUN_000141a0(param_1,param_2);
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
  return;
}



void FUN_00016618(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = FUN_000141a0(param_1,param_2);
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
  *(int *)(DAT_000906a4 + 4) = *(int *)(DAT_000906a4 + 4) + 1;
  return;
}



void FUN_00016634(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = DAT_00091130;
  DAT_000906a4 = (uint *)&DAT_0009d8b0;
  if (DAT_00091130 == 0) {
    uVar4 = 8;
  }
  else {
    iVar2 = FUN_000141ec(DAT_00091130 - 1);
    uVar4 = (iVar2 + 0x10) - (int)DAT_000906a4;
  }
  if ((undefined *)((int)DAT_000906a4 + uVar4) <= &DAT_0009dba0) {
    FUN_00000610(DAT_000906a4,uVar4);
    uVar4 = 0;
    *DAT_000906a4 = uVar1;
    if (uVar1 != 0) {
      do {
        if (DAT_00091130 <= uVar4) goto LAB_0001667c;
        if (uVar4 == 0) {
          puVar3 = DAT_000906a4 + 2;
        }
        else {
          iVar2 = FUN_000141ec(uVar4 - 1);
          puVar3 = (uint *)(iVar2 + 0x10);
        }
        uVar5 = uVar4 + 1;
        *puVar3 = (uint)*(byte *)(*(int *)(PTR_DAT_0009112c + uVar4 * 0xf4) + 5);
        puVar3[1] = 3;
        uVar4 = uVar5;
      } while (uVar5 < uVar1);
    }
    DAT_000906a4[1] = DAT_000906a4[1] + 1;
    return;
  }
LAB_0001667c:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_000166c4(uint param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_000141a0(param_1,param_2);
  *(undefined4 *)(iVar2 + 4) = param_3;
  FUN_00000542(iVar2 + 0x28,iVar2 + 0x18,0x20);
  *(undefined4 *)(iVar2 + 0x18) = param_3;
  FUN_0000d758();
  uVar1 = _DAT_00083000;
  uVar3 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  *(undefined4 *)(iVar2 + 0x20) = uVar1;
  *(uint *)(iVar2 + 0x24) = uVar3;
  *(int *)(DAT_000906a4 + 4) = *(int *)(DAT_000906a4 + 4) + 1;
  return;
}



void FUN_00016710(uint param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000141a0(param_1,param_2);
  *puVar1 = param_3;
  *(int *)(DAT_000906a4 + 4) = *(int *)(DAT_000906a4 + 4) + 1;
  return;
}



void FUN_0001672c(uint param_1,undefined *param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)FUN_000141ec(param_1);
  *puVar1 = *param_2;
  *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(param_2 + 8);
  *(int *)(DAT_000906a4 + 4) = *(int *)(DAT_000906a4 + 4) + 1;
  return;
}



undefined8 FUN_0001674c(int param_1,int param_2)

{
  return CONCAT44(*(undefined4 *)(&DAT_00095b70 + param_1 * 8 + param_2 * 0x50),
                  *(undefined4 *)(&DAT_00095b70 + param_1 * 8 + param_2 * 0x50 + 1));
}



undefined8 FUN_00016764(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  bool bVar10;
  
  iVar1 = param_1 * 0x10;
  iVar2 = (uint)(byte)(&DAT_00091b20)[iVar1] * 0x10;
  iVar3 = (uint)(byte)(&DAT_00091b21)[iVar1] * 0x10;
  cVar4 = (&DAT_00095c68)[iVar2];
  bVar10 = cVar4 != '\0';
  if (bVar10) {
    cVar4 = (&DAT_00095c68)[iVar3];
  }
  puVar6 = (undefined *)0x0;
  uVar8 = 0;
  if (bVar10 && cVar4 != '\0') {
    puVar5 = (undefined *)(*(uint *)(&DAT_00095c60 + iVar3) - *(uint *)(&DAT_00095c60 + iVar2));
    uVar7 = *(int *)(&DAT_00095c64 + iVar3) -
            (*(int *)(&DAT_00095c64 + iVar2) +
            (uint)(*(uint *)(&DAT_00095c60 + iVar3) < *(uint *)(&DAT_00095c60 + iVar2)));
    puVar9 = (undefined4 *)(&DAT_00095b70 + param_1 * 8 + (uint)DAT_00091b18 * 0x50);
    puVar6 = (undefined *)*puVar9;
    uVar8 = puVar9[1];
    if ((uVar8 < uVar7 + (puVar6 < puVar5)) &&
       (uVar7 < *(int *)(&DAT_00091b2c + iVar1) + (uint)(puVar5 < (&PTR_DAT_00091b28)[param_1 * 4]))
       ) {
      *(undefined **)puVar9 = puVar5;
      puVar9[1] = uVar7;
      puVar6 = puVar5;
      uVar8 = uVar7;
    }
  }
  (&DAT_00095c68)[iVar2] = 0;
  (&DAT_00095c68)[iVar3] = 0;
  return CONCAT44(puVar6,uVar8);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

ulonglong FUN_000167f0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_0000d758();
  uVar2 = _DAT_00083004;
  uVar1 = _DAT_00083000;
  uVar3 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  param_1 = param_1 * 0x10;
  *(undefined4 *)(&DAT_00095c60 + param_1) = uVar1;
  *(uint *)(&DAT_00095c64 + param_1) = uVar3;
  (&DAT_00095c68)[param_1] = 1;
  return CONCAT44(uVar1,uVar2) & 0xffffffff00ffffff;
}



void FUN_0001682c(undefined param_1)

{
  DAT_00091b18 = param_1;
  return;
}



undefined4
FUN_00016838(int param_1,uint param_2,undefined4 *param_3,int param_4,undefined4 *param_5)

{
  if ((*(char *)(param_1 + 0x4c) == '\x01') &&
     (FUN_000064cc(*(uint *)(param_1 + 0x50),0x10100b01,param_3,param_2), param_4 != 0)) {
    FUN_000064cc(*(uint *)(param_1 + 0x50),0x10100b01,param_5,param_4);
  }
  return 0;
}



int FUN_00016870(int *param_1,uint *param_2,undefined4 *param_3,uint *param_4,uint param_5)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  uVar1 = param_5 - 0x58;
  if (param_3 == (undefined4 *)0x0 || param_1 == (int *)0x0) {
    return -1;
  }
  if (uVar1 < 0x40) {
    return 1;
  }
  iVar3 = 0;
  do {
    uVar1 = uVar1 >> 1;
    iVar3 = iVar3 + 1;
  } while (uVar1 != 1);
  uVar1 = 1 << iVar3;
  FUN_000005cc(param_3,param_5,param_3,param_4,param_4);
  if (param_1 == (int *)0x0) {
    return -1;
  }
  if (param_5 < 0x58) {
    return 1;
  }
  FUN_000005cc(param_3,0x58);
  puVar2 = FUN_00000378(param_2);
  if ((FUN_00000010 + 7 < puVar2) || (puVar2 = FUN_00000378(param_2), puVar2 == (uint *)0x0)) {
    return 2;
  }
  FUN_0001a0cc((char *)(param_3 + 2),(char *)param_2,0x18);
  *(undefined4 **)param_3 = DAT_00090500;
  DAT_00090500 = param_3;
  param_3[1] = 0x1000;
  param_3[0x14] = 0;
  *(undefined *)(param_3 + 0x13) = 0;
  puVar4 = param_3 + 0x16;
  *(byte *)((int)param_3 + 0x4e) = *(byte *)((int)param_3 + 0x4e) | 1;
  *(undefined4 **)param_1 = param_3;
  if (((uint)puVar4 & 3) != 0) {
    puVar4 = (undefined4 *)((uint)(param_3 + 0x17) & 0xfffffffc);
  }
  iVar3 = -1;
  if (param_3 == (undefined4 *)0x0) {
    return -1;
  }
  if (((uint)puVar4 & 3) != 0) {
    return -1;
  }
  iVar6 = param_3[9];
  if (iVar6 == 0) {
    uVar5 = uVar1;
    if (uVar1 < 0x40) {
      uVar5 = 0x40;
    }
    iVar6 = 0;
    do {
      uVar5 = uVar5 >> 1;
      iVar6 = iVar6 + 1;
    } while (uVar5 != 1);
    uVar5 = 1 << iVar6;
    if (uVar1 < uVar5) {
      iVar3 = -1;
    }
    else {
      *(undefined4 **)(param_3 + 9) = puVar4;
      param_3[10] = uVar5;
      iVar3 = uVar5 - 1;
    }
    if (uVar5 <= uVar1) {
      param_3[0xb] = iVar3;
      iVar3 = 0;
    }
    if (param_3[9] == 0) goto LAB_00016982;
  }
  param_3[8] = param_3[8] | 1;
LAB_00016982:
  if (iVar3 == 0) {
    iVar3 = *param_1;
    if (iVar3 != 0) {
      uVar5 = *(uint *)(iVar3 + 0x20);
      bVar7 = (uVar5 & 1) != 0;
      if (bVar7) {
        iVar6 = *(int *)(iVar3 + 0x24);
      }
      if (bVar7 && iVar6 != 0) {
        bVar7 = (uVar5 & 2) == 0;
        if (bVar7) {
          uVar5 = uVar5 | 2;
        }
        if (bVar7) {
          *(uint *)(iVar3 + 0x20) = uVar5;
        }
      }
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = uVar1;
    }
    return 0;
  }
  return iVar3;
}



undefined4 FUN_000169c0(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack48;
  undefined4 uStack44;
  undefined4 uStack40;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 uStack28;
  
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x4c) == '\0') {
      iVar1 = *(int *)(param_1 + 0x24);
      if (*(uint *)(param_1 + 0x28) < (*(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x3c)) + 0x20U)
      {
        if (*(int *)(param_1 + 0x30) == *(int *)(param_1 + 0x3c)) {
          *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 1;
        }
        *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 0x20;
      }
      uVar2 = *(uint *)(param_1 + 0x38) & *(uint *)(param_1 + 0x2c);
      *(undefined4 *)(iVar1 + (uVar2 & 0xfffffffc)) = 0;
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 4;
      uVar3 = param_2[1];
      uVar4 = param_2[2];
      uVar5 = param_2[3];
      iVar6 = iVar1 + (uVar2 & 0xfffffffc);
      *(undefined4 *)(iVar6 + 4) = *param_2;
      *(undefined4 *)(iVar6 + 8) = uVar3;
      *(undefined4 *)(iVar6 + 0xc) = uVar4;
      *(undefined4 *)(iVar6 + 0x10) = uVar5;
      uVar4 = param_2[5];
      uVar3 = param_2[6];
      *(undefined4 *)(iVar6 + 0x14) = param_2[4];
      *(undefined4 *)(iVar6 + 0x18) = uVar4;
      *(undefined4 *)(iVar6 + 0x1c) = uVar3;
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 0x1c;
      *(undefined4 *)(iVar1 + (uVar2 & 0xfffffffc)) = 0x200000;
    }
    else {
      local_38 = 0x200000;
      local_34 = *param_2;
      uStack48 = param_2[1];
      uStack44 = param_2[2];
      uStack40 = param_2[3];
      local_24 = param_2[4];
      local_20 = param_2[5];
      uStack28 = param_2[6];
      (***(code ***)(param_1 + 0x54))(param_1,0x20,&local_38,0,0);
    }
    return 0;
  }
  return 0xffffffff;
}



void FUN_00016a76(int param_1)

{
  DAT_0009001c = param_1 + DAT_0009001c;
  return;
}



void FUN_00016a82(uint *param_1,uint param_2,int param_3,uint param_4)

{
  int *piVar1;
  bool bVar2;
  
  bVar2 = param_1 != (uint *)0x0;
  if (bVar2) {
    param_4 = *param_1;
  }
  if ((((!bVar2 || param_2 <= param_4) && (bVar2 && param_4 != param_2)) && (param_3 != 0)) &&
     (piVar1 = (int *)(param_1[1] + param_2 * 0xc), *piVar1 == 0)) {
    *piVar1 = param_3;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int FUN_00016aa6(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  
  pbVar4 = FUN_00017fb4(param_1,param_2);
  if (pbVar4 == (byte *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (param_3 == 0) {
    uVar5 = (uint)(byte)(PTR_DAT_000912d4 + (uint)*pbVar4 * 0x1c)[4];
LAB_00007d3c:
    if (uVar5 != 0) {
      uVar6 = (uint)pbVar4[2];
      uVar2 = uVar6 + 1 & 0xff;
      pbVar4[2] = (byte)uVar2;
      iVar3 = FUN_00000182(*(int *)(pbVar4 + 0x10),uVar2 << 3);
      *(int *)(pbVar4 + 0x10) = iVar3;
      if (iVar3 != 0) {
        *(int *)(iVar3 + uVar6 * 8) = param_3;
        iVar3 = FUN_00000154(uVar5);
        *(int *)(*(int *)(pbVar4 + 0x10) + uVar6 * 8 + 4) = iVar3;
        FUN_000005cc(iVar3,uVar5);
        return DAT_000912c4 + uVar6;
      }
    }
  }
  else {
    piVar1 = *(int **)(PTR_DAT_000912d4 + (uint)*pbVar4 * 0x1c + 0x14);
    while (piVar1 != (int *)0x0) {
      if (*piVar1 == param_3) {
        uVar5 = piVar1[1];
        goto LAB_00007d3c;
      }
      piVar1 = (int *)piVar1[2];
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



uint * FUN_00016ac0(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)FUN_0000a6f4(0xc);
  *puVar1 = param_2;
  uVar2 = FUN_0000a8d4(0xc,param_2,(undefined *)0x8435);
  puVar1[1] = uVar2;
  *(undefined *)(puVar1 + 2) = 0;
  FUN_00017124(param_1,param_2,8,FUN_00006e3c + 1,0x6c09,puVar1);
  return puVar1;
}



uint * FUN_00016b08(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)FUN_0000a6f4(0xc);
  *puVar1 = param_2;
  uVar2 = FUN_0000a8d4(0xc,param_2,(undefined *)0x8435);
  puVar1[1] = uVar2;
  *(undefined *)(puVar1 + 2) = 1;
  FUN_00017124(param_1,param_2,8,FUN_00006e3c + 1,0x6c09,puVar1);
  return puVar1;
}



void FUN_00016b50(void)

{
  if (DAT_00090164 != '\0') {
    return;
  }
  DAT_0009001c = 0;
  DAT_00090164 = 1;
  return;
}



void FUN_00016b6c(int param_1,int param_2,undefined4 *param_3)

{
  byte *pbVar1;
  
  pbVar1 = FUN_00017fb4(param_1,param_2);
  if (pbVar1 == (byte *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  *param_3 = *(undefined4 *)(pbVar1 + 8);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00016b82(byte *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_1 == (byte *)0x0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  uVar2 = **_FUN_000077a4;
  if (param_2 < param_1[2] + uVar2) {
    if (uVar2 <= param_2) {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x10) + (param_2 - uVar2) * 8);
      *param_3 = *puVar1;
      *param_4 = puVar1[1];
      return;
    }
    *param_3 = 0;
    if (param_1 != (byte *)0x0) {
      do {
        param_1 = *(byte **)(param_1 + 0xc);
        if (param_1 == (byte *)0x0) goto LAB_00007786;
      } while ((uint)param_1[1] != param_2);
      if (param_1[(uint)*param_1 + 2] != 0) {
        *param_4 = *(undefined4 *)(param_1 + (uint)*param_1 * 4 + 4);
        return;
      }
LAB_00007786:
      *param_4 = 0;
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int FUN_00016b8c(int param_1)

{
  if (param_1 != 0) {
    return (uint)*(byte *)(param_1 + 2) + **_FUN_000077b4;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_00016b98(void)

{
  return *(undefined4 *)*_FUN_00016ba0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int FUN_00016ba0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  
  DAT_00091320 = 0;
  iVar1 = FUN_0001a150();
  DAT_00095520 = iVar1 + 0x100;
  DAT_00095524 = 0;
  DAT_00095518 = iVar1 + 0x700;
  DAT_0009551c = 0;
  FUN_0000d758();
  uVar4 = _DAT_00083000;
  uVar6 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  uVar2 = DAT_00095520 + DAT_00095518;
  uVar6 = uVar6 + DAT_00095524 + DAT_0009551c + (uint)CARRY4(DAT_00095520,DAT_00095518) +
          (uint)CARRY4(uVar4,uVar2);
  uVar7 = FUN_00018158();
  uVar4 = (int)uVar7 + (uint)(uVar4 + uVar2 < (uint)((ulonglong)uVar7 >> 0x20));
  if (uVar6 < uVar4) {
    DAT_00091320 = 1;
    uVar3 = FUN_0001a108();
    FUN_0001682c((char)uVar3);
    FUN_000167f0(6);
    uVar7 = FUN_00018158();
    uVar4 = (uint)((ulonglong)uVar7 >> 0x20);
    iVar5 = uVar4 - DAT_00095518;
    iVar1 = (int)uVar7 - (DAT_0009551c + (uint)(uVar4 < DAT_00095518));
    FUN_000065ec(0x143,iVar1,iVar5,0,0);
    _DAT_0008302c = 1;
    _DAT_e000e284 = 0x40000;
    _DAT_e000e104 = 0x40000;
    _DAT_00083020 = iVar5;
    _DAT_00083024 = iVar1;
    FUN_0001a440(1);
    FUN_0001a31c();
    FUN_0000c0a4(0);
    FUN_000167f0(8);
    FUN_00000128();
    FUN_000167f0(9);
    FUN_0000c0a4(1);
    FUN_0001a30c();
    FUN_0001a440(1);
    _DAT_e000e184 = 0x40000;
    _DAT_0008302c = 0;
    iVar1 = FUN_0001a6a0(8);
    return iVar1;
  }
  return uVar6 - uVar4;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int FUN_00016ba4(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  
  DAT_00091320 = 0;
  iVar1 = FUN_0001a150();
  DAT_00095520 = iVar1 + 0x100;
  DAT_00095524 = 0;
  DAT_00095518 = iVar1 + 0x700;
  DAT_0009551c = 0;
  FUN_0000d758();
  uVar4 = _DAT_00083000;
  uVar6 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  uVar2 = DAT_00095520 + DAT_00095518;
  uVar6 = uVar6 + DAT_00095524 + DAT_0009551c + (uint)CARRY4(DAT_00095520,DAT_00095518) +
          (uint)CARRY4(uVar4,uVar2);
  uVar7 = FUN_00018158();
  uVar4 = (int)uVar7 + (uint)(uVar4 + uVar2 < (uint)((ulonglong)uVar7 >> 0x20));
  if (uVar6 < uVar4) {
    DAT_00091320 = 1;
    uVar3 = FUN_0001a108();
    FUN_0001682c((char)uVar3);
    FUN_000167f0(6);
    uVar7 = FUN_00018158();
    uVar4 = (uint)((ulonglong)uVar7 >> 0x20);
    iVar5 = uVar4 - DAT_00095518;
    iVar1 = (int)uVar7 - (DAT_0009551c + (uint)(uVar4 < DAT_00095518));
    FUN_000065ec(0x143,iVar1,iVar5,0,0);
    _DAT_0008302c = 1;
    _DAT_e000e284 = 0x40000;
    _DAT_e000e104 = 0x40000;
    _DAT_00083020 = iVar5;
    _DAT_00083024 = iVar1;
    FUN_0001a440(1);
    FUN_0001a31c();
    FUN_0000c0a4(0);
    FUN_000167f0(8);
    FUN_00000128();
    FUN_000167f0(9);
    FUN_0000c0a4(1);
    FUN_0001a30c();
    FUN_0001a440(1);
    _DAT_e000e184 = 0x40000;
    _DAT_0008302c = 0;
    iVar1 = FUN_0001a6a0(8);
    return iVar1;
  }
  return uVar6 - uVar4;
}



ulonglong FUN_00016ca8(undefined4 param_1,uint param_2)

{
  ulonglong uVar1;
  
  if (DAT_00091320 == '\0') {
    return (ulonglong)param_2;
  }
  FUN_000065ec(0x144,0,0,0,0);
  FUN_0001a6a0(0x10);
  FUN_000167f0(7);
  FUN_00016764(4);
  uVar1 = FUN_00016764(5);
  return uVar1;
}



uint FUN_00016ce8(uint param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  bool bVar7;
  
  if (param_1 == 8) {
    uVar2 = (uint)(*param_2 * -0x3361d2af) >> 0x11 | *param_2 * 0x16a88000;
    uVar2 = (uVar2 * 0x1b873593 >> 0x13 | uVar2 * -0x194da000) * 5 + 0xe6546b64 ^
            ((uint)(param_2[1] * -0x3361d2af) >> 0x11 | param_2[1] * 0x16a88000) * 0x1b873593;
    uVar2 = (uVar2 >> 0x13 | uVar2 << 0xd) * 5 + 0xe6546b64;
    uVar2 = (uVar2 ^ 8 ^ uVar2 >> 0x10) * -0x7a143595;
    uVar2 = (uVar2 ^ uVar2 >> 0xd) * -0x3d4d51cb;
    return uVar2 ^ uVar2 >> 0x10;
  }
  pbVar5 = (byte *)((int)param_2 + (param_1 & 0xfffffffc));
  uVar2 = 0;
  iVar3 = -(param_1 >> 2);
  while (iVar3 != 0) {
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    uVar2 = uVar2 ^ ((uint)(*(int *)(pbVar5 + iVar1) * -0x3361d2af) >> 0x11 |
                    *(int *)(pbVar5 + iVar1) * 0x16a88000) * 0x1b873593;
    uVar2 = (uVar2 >> 0x13 | uVar2 << 0xd) * 5 + 0xe6546b64;
  }
  uVar4 = 0;
  uVar6 = param_1 & 3;
  if (uVar6 != 1) {
    if (uVar6 != 2) {
      bVar7 = uVar6 == 3;
      if (bVar7) {
        uVar6 = (uint)pbVar5[2];
      }
      uVar4 = uVar6 << 0x10;
      if (!bVar7) goto LAB_00016dae;
    }
    uVar4 = uVar4 ^ (uint)pbVar5[1] << 8;
  }
  uVar2 = uVar2 ^ ((uVar4 ^ *pbVar5) * -0x3361d2af >> 0x11 | (uVar4 ^ *pbVar5) * 0x16a88000) *
                  0x1b873593;
LAB_00016dae:
  uVar2 = (param_1 ^ uVar2 ^ (param_1 ^ uVar2) >> 0x10) * -0x7a143595;
  uVar2 = (uVar2 ^ uVar2 >> 0xd) * -0x3d4d51cb;
  return uVar2 ^ uVar2 >> 0x10;
}



uint FUN_00016ddc(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  
  param_1 = param_1 ^ ((uint)(param_2 * -0x3361d2af) >> 0x11 | param_2 * 0x16a88000) * 0x1b873593;
  uVar1 = (param_1 >> 0x13 | param_1 << 0xd) * 5 + 0xe6546b64 ^
          ((uint)(param_3 * -0x3361d2af) >> 0x11 | param_3 * 0x16a88000) * 0x1b873593;
  uVar1 = (uVar1 >> 0x13 | uVar1 << 0xd) * 5 + 0xe6546b64;
  uVar1 = (uVar1 ^ 8 ^ uVar1 >> 0x10) * -0x7a143595;
  uVar1 = (uVar1 ^ uVar1 >> 0xd) * -0x3d4d51cb;
  return uVar1 ^ uVar1 >> 0x10;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00016e3c(void)

{
  _DAT_68600b1c = _DAT_68600b1c | 2;
  return;
}



void FUN_00016e4c(int param_1,int param_2,uint param_3,uint param_4,undefined4 param_5)

{
  byte *pbVar1;
  longlong lVar2;
  
  lVar2 = 0;
  pbVar1 = FUN_00017fb4(param_1,param_2);
  if (pbVar1 != (byte *)0x0) {
    do {
      lVar2 = FUN_00007ef0(pbVar1,param_3,param_4,param_5,(int)((ulonglong)lVar2 >> 0x20),(int)lVar2
                          );
    } while (lVar2 != 0);
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_00016e88(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uStack68;
  uint uStack64;
  undefined4 uStack60;
  undefined4 uStack56;
  undefined4 uStack52;
  undefined4 uStack48;
  undefined4 uStack44;
  
  FUN_0000d758();
  uStack68 = _DAT_00083000;
  uStack64 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  if (DAT_00090449 != '\0') {
    return;
  }
  uStack44 = param_5;
  DAT_0009044c = DAT_0009044c + 1;
  uStack60 = param_1;
  uStack56 = param_2;
  uStack52 = param_3;
  uStack48 = param_4;
  FUN_000169c0(DAT_00090454,&uStack68);
  if ((DAT_0009044c & 0xff) != 0) {
    return;
  }
  uVar1 = FUN_0000c3a4();
  FUN_000065ec(0xe3,uVar1,0,0,0);
  return;
}



uint FUN_00016f14(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  uVar2 = 0;
  while( true ) {
    iVar1 = *(int *)(uVar2 * 8 + 0x912f8);
    if (iVar1 == param_1) {
      return uVar2;
    }
    if ((iVar1 == 0) &&
       (iVar1 = FUN_00000660(*(uint **)(param_1 + 4),(uint *)(&PTR_DAT_000912f4)[uVar2 * 2]),
       iVar1 == 0)) break;
    uVar2 = uVar2 + 1;
    if (3 < uVar2) {
      return 0xffffffff;
    }
  }
  *(int *)(uVar2 * 8 + 0x912f8) = param_1;
  return uVar2;
}



undefined4 FUN_00016f64(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return 0;
  case 1:
    return 0x10;
  case 2:
    return 0x40;
  case 3:
    return 0x80;
  case 4:
    return 0xc0;
  case 5:
    return 0x100;
  case 6:
    return 0x140;
  default:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  case 8:
    return 0x180;
  }
}



undefined4 FUN_00016fa4(uint param_1)

{
  if (param_1 < 0x7ffffff) {
    if (param_1 == 0xc0) {
      return 4;
    }
    if ((int)param_1 < 0xc1) {
      if (param_1 == 0) {
        return 0;
      }
      if (param_1 == 0x10) {
        return 1;
      }
      if (param_1 == 0x40) {
        return 2;
      }
      if (param_1 == 0x80) {
        return 3;
      }
    }
    else {
      if (param_1 == 0x100) {
        return 5;
      }
      if (param_1 == 0x140) {
        return 6;
      }
      if (param_1 == 0x180) {
        return 8;
      }
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00016ff8(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  byte *pbVar2;
  undefined *puVar3;
  
  pbVar2 = FUN_00017fb4(param_1,param_2);
  if ((pbVar2 == (byte *)0x0) ||
     (puVar3 = PTR_DAT_000912d4 + (uint)*pbVar2 * 0x1c, puVar3 == (undefined *)0x0)) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (param_3 != 0) {
    piVar1 = *(int **)(puVar3 + 0x14);
    while( true ) {
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)FUN_0000a6f4(0xc);
        *piVar1 = param_3;
        piVar1[1] = param_4;
        piVar1[2] = *(int *)(puVar3 + 0x14);
        *(int **)(puVar3 + 0x14) = piVar1;
        return;
      }
      if (*piVar1 == param_3) break;
      piVar1 = (int *)piVar1[2];
    }
    if (piVar1[1] == param_4) {
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0001702c(uint param_1,uint param_2,int param_3,uint param_4,uint param_5,uint param_6,
                 uint param_7)

{
  uint uVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint *puVar5;
  bool bVar6;
  bool bVar7;
  
  uVar1 = (uint)DAT_000904c0;
  if (DAT_000904c0 == 0) {
    if (DAT_000912c8 != 0) {
      do {
        puVar5 = (uint *)(PTR_DAT_000912d4 + uVar1 * 0x1c);
        uVar4 = *puVar5;
        bVar6 = uVar4 == param_1;
        if (bVar6) {
          uVar4 = (uint)*(byte *)(puVar5 + 1);
        }
        if (bVar6 && uVar4 == param_4) {
          uVar4 = puVar5[2];
          bVar6 = uVar4 == param_5;
          if (bVar6) {
            uVar4 = puVar5[3];
          }
          bVar7 = bVar6 && uVar4 == param_6;
          if (bVar6 && uVar4 == param_6) {
            bVar7 = puVar5[4] == param_7;
          }
          if (bVar7) {
            if (-1 < (int)uVar1) {
              return;
            }
            break;
          }
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < DAT_000912c8);
    }
    uVar1 = 0;
    if (DAT_000912c8 != 0) {
      do {
        if (*(int *)(PTR_DAT_000912d4 + uVar1 * 0x1c) == 0) {
          if (-1 < (int)uVar1) {
            puVar5 = (uint *)(PTR_DAT_000912d4 + uVar1 * 0x1c);
            *puVar5 = param_1;
            *(char *)(puVar5 + 1) = (char)param_4;
            puVar5[4] = param_7;
            puVar5[5] = 0;
            puVar5[2] = param_5;
            puVar5[3] = param_6;
            uVar4 = 0;
            if (param_2 == 0) {
              return;
            }
            while (pbVar2 = FUN_00017fb4(param_1,*(int *)(param_3 + uVar4 * 4)),
                  pbVar2 == (byte *)0x0) {
              puVar3 = FUN_00017aa4(param_1,*(int *)(param_3 + uVar4 * 4));
              FUN_00006b50(puVar3,uVar1,*(int *)(param_3 + uVar4 * 4));
              uVar4 = uVar4 + 1;
              if (param_2 <= uVar4) {
                return;
              }
            }
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < DAT_000912c8);
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00017124(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  bool bVar6;
  uint auStack64 [3];
  undefined auStack52 [4];
  undefined4 auStack48 [4];
  
  iVar1 = -(param_2 * 4 + 7 & 0xfffffff8);
  if (param_2 != 0) {
    bVar6 = (param_2 & 1) != 0;
    puVar2 = (undefined4 *)auStack52;
    if (bVar6) {
      *(undefined4 *)((int)auStack48 + iVar1) = 0;
      puVar2 = auStack48;
    }
    puVar5 = (undefined *)puVar2 + iVar1;
    uVar3 = (uint)bVar6;
    uVar4 = param_2 >> 1;
    while (uVar4 != 0) {
      *(uint *)(puVar5 + 4) = uVar3;
      *(uint *)(puVar5 + 8) = uVar3 + 1;
      uVar3 = uVar3 + 2;
      puVar5 = puVar5 + 8;
      uVar4 = uVar4 - 1;
    }
  }
  *(uint *)((int)auStack64 + iVar1) = param_4;
  *(undefined4 *)((int)auStack64 + iVar1 + 4) = param_5;
  *(undefined4 *)((int)auStack64 + iVar1 + 8) = param_6;
  FUN_0001702c(param_1,param_2,(int)((int)auStack48 + iVar1),param_3,
               *(uint *)((int)auStack64 + iVar1),*(uint *)((int)auStack64 + iVar1 + 4),
               *(uint *)((int)auStack64 + iVar1 + 8));
  return;
}



uint FUN_00017184(uint param_1,int param_2,uint param_3,int *param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (int)((ulonglong)
                ((longlong)(param_2 - (int)PTR_DAT_000912d8) * -0x6db6db6d +
                ((longlong)(param_2 - (int)PTR_DAT_000912d8) << 0x20)) >> 0x20);
  iVar1 = (iVar1 >> 4) - (iVar1 >> 0x1f);
  if (param_4 != (int *)0x0) {
    uVar2 = FUN_00016ce8(param_3,param_4);
    param_1 = param_1 ^ (uVar2 >> iVar1 | uVar2 << 0x20 - iVar1);
  }
  if (param_5 != (int *)0x0) {
    uVar2 = FUN_00016ce8(param_3,param_5);
    param_1 = param_1 ^ (uVar2 >> iVar1 | uVar2 << 0x20 - iVar1);
  }
  return param_1;
}



void FUN_000171f8(int param_1,int param_2,uint param_3,int *param_4)

{
  byte *pbVar1;
  uint local_18;
  undefined4 uStack20;
  
  local_18 = 0;
  uStack20 = 0;
  if ((param_3 < DAT_000912c4) && (pbVar1 = FUN_00017fb4(param_1,param_2), pbVar1 != (byte *)0x0)) {
    FUN_00007568(pbVar1,param_3,0,param_4,&local_18);
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00017240(void)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  pbVar1 = FUN_00017fb4(0x766c7362,0);
  iVar2 = (int)((ulonglong)
                ((longlong)(int)(pbVar1 + -(int)PTR_DAT_000912d8) * -0x6db6db6d +
                ((longlong)(int)(pbVar1 + -(int)PTR_DAT_000912d8) << 0x20)) >> 0x20);
  uVar4 = (iVar2 >> 4) - (iVar2 >> 0x1f);
  pbVar1 = FUN_00017fb4(0x766c7362,2);
  iVar2 = (int)((ulonglong)
                ((longlong)(int)(pbVar1 + -(int)PTR_DAT_000912d8) * -0x6db6db6d +
                ((longlong)(int)(pbVar1 + -(int)PTR_DAT_000912d8) << 0x20)) >> 0x20);
  uVar5 = (iVar2 >> 4) - (iVar2 >> 0x1f);
  pbVar1 = FUN_00017fb4(0x73616d62,3);
  iVar2 = (int)((ulonglong)
                ((longlong)(int)(pbVar1 + -(int)PTR_DAT_000912d8) * -0x6db6db6d +
                ((longlong)(int)(pbVar1 + -(int)PTR_DAT_000912d8) << 0x20)) >> 0x20);
  uVar3 = (iVar2 >> 4) - (iVar2 >> 0x1f);
  DAT_00093978 = 0;
  DAT_0009397c = 0;
  DAT_00093980 = 0;
  DAT_00093984 = 0;
  DAT_00093988 = 0;
  if (0x9f < uVar4 || 0x9f < uVar5) {
    DAT_00093978 = 0;
    DAT_0009397c = 0;
    DAT_00093980 = 0;
    DAT_00093984 = 0;
    DAT_00093988 = 0;
    return;
  }
  if (0x9f < uVar3) {
    DAT_00093978 = 0;
    DAT_0009397c = 0;
    DAT_00093980 = 0;
    DAT_00093984 = 0;
    DAT_00093988 = 0;
    return;
  }
  (&DAT_00093978)[uVar4 >> 5] = (&DAT_00093978)[uVar4 >> 5] | 1 << (uVar4 & 0x1f);
  (&DAT_00093978)[uVar5 >> 5] = (&DAT_00093978)[uVar5 >> 5] | 1 << (uVar5 & 0x1f);
  (&DAT_00093978)[uVar3 >> 5] = (&DAT_00093978)[uVar3 >> 5] | 1 << (uVar3 & 0x1f);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00017334(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  bool bVar5;
  
  _DAT_00082044 = 0x21;
  _DAT_0008402c = _DAT_0008402c & 7 | 1;
  FUN_0000d57c(0x33,(undefined *)0x72f9);
  FUN_0000d4f0(0x33,2);
  _DAT_e000e284 = 0x80000;
  _DAT_e000e104 = 0x80000;
  puVar3 = (undefined4 *)FUN_00000154(0x18);
  DAT_000904a8 = puVar3;
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0xffffffff;
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    uVar4 = 0;
    if (DAT_000912c4 == 1) {
      return;
    }
    while( true ) {
      puVar1 = (undefined4 *)FUN_00000154(0x18);
      *(undefined4 **)(puVar3 + 4) = puVar1;
      if (puVar1 == (undefined4 *)0x0) break;
      *puVar1 = 0xffffffff;
      puVar1[1] = 0xffffffff;
      *(undefined4 *)(puVar3[4] + 8) = 0;
      *(undefined4 *)(puVar3[4] + 0xc) = 0;
      uVar2 = DAT_000912c4 - 2;
      bVar5 = uVar2 == uVar4;
      if (bVar5) {
        uVar2 = puVar3[4];
      }
      if (bVar5) {
        *(undefined4 *)(uVar2 + 0x10) = 0;
      }
      else {
        puVar3 = (undefined4 *)puVar3[4];
      }
      uVar4 = uVar4 + 1;
      if (DAT_000912c4 - 1U <= uVar4) {
        return;
      }
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_000173ec(uint param_1,undefined1 *param_2,uint param_3,uint param_4,uint param_5,
                 uint param_6)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  
  uVar3 = 0;
  if (DAT_000912c8 != 0) {
    do {
      puVar2 = (uint *)(PTR_DAT_000912d4 + uVar3 * 0x1c);
      uVar4 = *puVar2;
      bVar5 = uVar4 == param_1;
      if (bVar5) {
        uVar4 = (uint)*(byte *)(puVar2 + 1);
      }
      if (bVar5 && uVar4 == param_3) {
        uVar4 = puVar2[2];
        bVar5 = uVar4 == param_4;
        if (bVar5) {
          uVar4 = puVar2[3];
        }
        bVar6 = bVar5 && uVar4 == param_5;
        if (bVar5 && uVar4 == param_5) {
          bVar6 = puVar2[4] == param_6;
        }
        if (bVar6) {
          if (-1 < (int)uVar3) goto LAB_00017486;
          break;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < DAT_000912c8);
  }
  uVar3 = 0;
  if (DAT_000912c8 != 0) {
    do {
      if (*(int *)(PTR_DAT_000912d4 + uVar3 * 0x1c) == 0) {
        if (-1 < (int)uVar3) {
          puVar2 = (uint *)(PTR_DAT_000912d4 + uVar3 * 0x1c);
          *puVar2 = param_1;
          *(char *)(puVar2 + 1) = (char)param_3;
          puVar2[4] = param_6;
          puVar2[5] = 0;
          puVar2[2] = param_4;
          puVar2[3] = param_5;
LAB_00017486:
          pbVar1 = FUN_00017fb4(param_1,(int)param_2);
          if (pbVar1 != (byte *)0x0) {
            uVar3 = FUN_00006f04(param_2,uVar3);
            pbVar1[1] = (byte)uVar3;
            return;
          }
        }
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < DAT_000912c8);
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Heritage AFTER dead removal. Example location: r0x000912d0 : 0x00017586
// WARNING: Restarted to delay deadcode elimination for space: ram

void FUN_000174ac(void)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar2 = DAT_000912c4;
  uVar5 = 0;
  uVar10 = 0;
  if (DAT_000912c4 != 0) {
    do {
      uVar9 = 0;
      uVar8 = 0;
      puVar6 = PTR_DAT_000912d0 + uVar10 * 0x40;
      uVar11 = *(uint *)(puVar6 + 0x10);
      *(uint *)(puVar6 + 0x34) = uVar11;
      *(undefined4 *)(puVar6 + 0x38) = 0;
      puVar6[0x30] = 0;
      puVar6[0x31] = 0;
      if (uVar11 != 0) {
        do {
          uVar7 = *(uint *)(*(int *)(puVar6 + 0x14) + uVar8 * 4);
          if (uVar5 < uVar7) {
            uVar5 = uVar7;
          }
          FUN_0000d4f0(uVar7,2);
          FUN_0000d57c(uVar7,(undefined *)0x7681);
          uVar7 = *(uint *)(*(int *)(puVar6 + 0x1c) + uVar8 * 4);
          if (uVar5 < uVar7) {
            uVar5 = uVar7;
          }
          FUN_0000d4f0(uVar7,2);
          FUN_0000d57c(uVar7,FUN_0000816c + 1);
          iVar1 = (uVar7 >> 5) * 4;
          iVar4 = 1 << (uVar7 & 0x1f);
          *(int *)(&DAT_e000e280 + iVar1) = iVar4;
          *(int *)(&DAT_e000e100 + iVar1) = iVar4;
          uVar9 = 1 << uVar8 | uVar9;
          uVar8 = uVar8 + 1;
          **(uint **)(puVar6 + 0x3c) = uVar9;
        } while (uVar8 < uVar11);
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar2);
  }
  uVar5 = (uVar5 + 1) * 2;
  DAT_000912f0 = (uint *)FUN_0000a6ec(uVar5);
  FUN_000005bc(DAT_000912f0,uVar5,0xff);
  puVar3 = DAT_000912f0;
  uVar5 = 0;
  if (uVar2 != 0) {
    do {
      puVar6 = PTR_DAT_000912d0 + uVar5 * 0x40;
      uVar10 = 0;
      uVar8 = *(uint *)(puVar6 + 0x10);
      if (uVar8 != 0) {
        do {
          *(char *)((int)puVar3 + *(int *)(*(int *)(puVar6 + 0x1c) + uVar10 * 4) * 2) = (char)uVar5;
          *(undefined *)((int)puVar3 + *(int *)(*(int *)(puVar6 + 0x1c) + uVar10 * 4) * 2 + 1) =
               (char)uVar10;
          *(char *)((int)puVar3 + *(int *)(*(int *)(puVar6 + 0x14) + uVar10 * 4) * 2) = (char)uVar5;
          *(undefined *)((int)puVar3 + *(int *)(*(int *)(puVar6 + 0x14) + uVar10 * 4) * 2 + 1) =
               (char)uVar10;
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar8);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar2);
    return;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_000175ec(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*_FUN_00017650 + 0xc) + param_1 * 0x40;
  *(undefined *)(iVar2 + 0x31) = 1;
  if (param_2 == 0) {
    FUN_0000d58c(**(uint **)(iVar2 + 0x1c));
    return;
  }
  if (param_2 != 1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (*(char *)(iVar2 + 0x30) == '\0') {
    return;
  }
  if (*(char *)(iVar2 + 0x30) == '\x03') {
    return;
  }
  FUN_0000d58c(**(uint **)(iVar2 + 0x14));
  iVar1 = (**(uint **)(iVar2 + 0x14) >> 5) * 4;
  iVar2 = 1 << (**(uint **)(iVar2 + 0x14) & 0x1f);
  *(int *)(&DAT_e000e280 + iVar1) = iVar2;
  *(int *)(&DAT_e000e100 + iVar1) = iVar2;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00017650(uint param_1)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  int iVar16;
  
  FUN_0000d758();
  cVar2 = '\0';
  puVar7 = PTR_DAT_000912d0 + param_1 * 0x40;
  piVar8 = *(int **)(puVar7 + 0x2c);
  iVar9 = param_1 * 0x40 + 0x38;
  iVar10 = param_1 * 0x40 + 0x30;
LAB_00017694:
  do {
    cVar1 = puVar7[0x30];
    if (cVar1 == '\0') {
      cVar2 = '\0';
      if (*(int *)(puVar7 + 0x34) == 0) {
        cVar2 = '\x01';
        PTR_DAT_000912d0[iVar10] = 1;
        goto LAB_00017694;
      }
      uVar11 = *(undefined4 *)(PTR_DAT_000912d0 + iVar9);
      bVar4 = (byte)uVar11;
      bVar5 = (byte)((uint)uVar11 >> 8);
      bVar6 = (byte)((uint)uVar11 >> 0x10);
      bVar3 = (byte)((uint)uVar11 >> 0x18);
      uVar15 = (uint)(byte)((((((((bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) <<
                                1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) <<
                             1 | bVar4 >> 7) << 1) << 0x18 |
               (uint)(byte)((((((((bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1) << 1 | bVar5 >> 3 & 1) <<
                                1 | bVar5 >> 4 & 1) << 1 | bVar5 >> 5 & 1) << 1 | bVar5 >> 6 & 1) <<
                             1 | bVar5 >> 7) << 1) << 0x10 |
               (uint)(byte)((((((((bVar6 >> 1 & 1) << 1 | bVar6 >> 2 & 1) << 1 | bVar6 >> 3 & 1) <<
                                1 | bVar6 >> 4 & 1) << 1 | bVar6 >> 5 & 1) << 1 | bVar6 >> 6 & 1) <<
                             1 | bVar6 >> 7) << 1) << 8 |
               (uint)(byte)((((((((bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) <<
                                1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) <<
                             1 | bVar3 >> 7) << 1);
      iVar12 = count_leading_zeroes(uVar15);
      if (iVar12 != 0x20) {
        iVar16 = param_1 * 0x40 + 0x31;
        do {
          FUN_000065ec(0xc3,param_1,iVar12,(uint)(byte)PTR_DAT_000912d0[iVar16],0);
          if (PTR_DAT_000912d0[iVar16] == '\0') {
            _DAT_00080014 =
                 1 << *(int *)(*(int *)(PTR_DAT_000912d0 + param_1 * 0x40 + 0x18) + iVar12 * 4);
          }
          else {
            PTR_DAT_000912d0[iVar16] = 0;
            FUN_00009da8(*(int *)(PTR_DAT_000912d0 + param_1 * 0x40 + 0x28),4,(uint *)0x0,0x646d63);
          }
          uVar15 = uVar15 & ~(0x80000000U >> iVar12);
          iVar12 = count_leading_zeroes(uVar15);
        } while (iVar12 != 0x20);
      }
      if (*(int *)(PTR_DAT_000912d0 + iVar9) != 0) {
        FUN_0000d758();
        uVar11 = _DAT_00083000;
        uVar15 = _DAT_00083004 & 0xffffff;
        FUN_0001a7ec();
        iVar12 = *(int *)(PTR_DAT_000912d0 + param_1 * 0x40 + 0x3c);
        *(undefined4 *)(iVar12 + 0x20) = uVar11;
        *(uint *)(iVar12 + 0x24) = uVar15;
      }
      *(undefined4 *)(PTR_DAT_000912d0 + iVar9) = 0;
    }
    else {
      if (cVar1 == '\x01') {
        if (cVar2 != '\0') {
          iVar12 = FUN_0000dc40(param_1 & 0xff);
          uVar13 = *(uint *)(iVar12 + 0xc);
          uVar15 = *(uint *)(iVar12 + 8);
          if ((~*(uint *)(iVar12 + 8) | ~uVar13) == 0) {
            uVar13 = 0;
            uVar15 = uVar13;
          }
          piVar8[0x1e] = uVar15;
          piVar8[0x1f] = uVar13;
          FUN_00008d94(piVar8,1,0,(int *)0x0);
        }
        if (param_1 != 2) {
          if (param_1 == 1) {
            puVar14 = FUN_00006ad0();
            FUN_00009828((int)puVar14);
          }
          goto LAB_00017796;
        }
        cVar2 = *(char *)(piVar8 + 0xe);
        if (cVar2 != '\x01') goto LAB_00017796;
        PTR_DAT_000912d0[iVar10] = 2;
        goto LAB_00017694;
      }
      if (cVar1 == '\x02') {
        if (cVar2 != '\0') {
          FUN_00008d94(piVar8,0,piVar8[0x1e],(int *)piVar8[0x1f]);
        }
        if (*(int *)(puVar7 + 0x34) == 0) goto LAB_00017796;
        cVar2 = '\x01';
        PTR_DAT_000912d0[iVar10] = 3;
        goto LAB_00017694;
      }
      if (cVar1 == '\x03') {
        if ((cVar2 != '\0') &&
           ((*(char *)(piVar8 + 0xe) == '\x01' || (*(char *)((int)piVar8 + 0x2e) != '\0')))) {
          FUN_00008d94(piVar8,0,0,(int *)0x0);
        }
        if ((*(char *)(piVar8 + 0xe) != '\0') || (*(char *)((int)piVar8 + 0x2e) != '\0'))
        goto LAB_00017796;
        cVar2 = '\x01';
        PTR_DAT_000912d0[iVar10] = 0;
        goto LAB_00017694;
      }
    }
    if (cVar2 == '\0') {
LAB_00017796:
      FUN_0001a7ec();
      return;
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00017654(uint param_1,int param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  int iVar16;
  
  FUN_0000d758();
  cVar2 = '\0';
  puVar7 = PTR_DAT_000912d0 + param_1 * 0x40;
  piVar8 = *(int **)(puVar7 + 0x2c);
  iVar9 = param_1 * 0x40 + 0x38;
  iVar10 = param_1 * 0x40 + 0x30;
LAB_00017694:
  do {
    cVar1 = puVar7[0x30];
    if (cVar1 == '\0') {
      cVar2 = '\0';
      if (*(int *)(puVar7 + 0x34) == 0) {
        cVar2 = '\x01';
        PTR_DAT_000912d0[iVar10] = 1;
        goto LAB_00017694;
      }
      uVar11 = *(undefined4 *)(PTR_DAT_000912d0 + iVar9);
      bVar4 = (byte)uVar11;
      bVar5 = (byte)((uint)uVar11 >> 8);
      bVar6 = (byte)((uint)uVar11 >> 0x10);
      bVar3 = (byte)((uint)uVar11 >> 0x18);
      uVar15 = (uint)(byte)((((((((bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) <<
                                1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) <<
                             1 | bVar4 >> 7) << 1) << 0x18 |
               (uint)(byte)((((((((bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1) << 1 | bVar5 >> 3 & 1) <<
                                1 | bVar5 >> 4 & 1) << 1 | bVar5 >> 5 & 1) << 1 | bVar5 >> 6 & 1) <<
                             1 | bVar5 >> 7) << 1) << 0x10 |
               (uint)(byte)((((((((bVar6 >> 1 & 1) << 1 | bVar6 >> 2 & 1) << 1 | bVar6 >> 3 & 1) <<
                                1 | bVar6 >> 4 & 1) << 1 | bVar6 >> 5 & 1) << 1 | bVar6 >> 6 & 1) <<
                             1 | bVar6 >> 7) << 1) << 8 |
               (uint)(byte)((((((((bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) <<
                                1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) <<
                             1 | bVar3 >> 7) << 1);
      iVar12 = count_leading_zeroes(uVar15);
      if (iVar12 != 0x20) {
        iVar16 = param_1 * 0x40 + 0x31;
        do {
          FUN_000065ec(0xc3,param_1,iVar12,(uint)(byte)PTR_DAT_000912d0[iVar16],0);
          if (PTR_DAT_000912d0[iVar16] == '\0') {
            _DAT_00080014 =
                 1 << *(int *)(*(int *)(PTR_DAT_000912d0 + param_1 * 0x40 + 0x18) + iVar12 * 4);
          }
          else {
            PTR_DAT_000912d0[iVar16] = 0;
            FUN_00009da8(*(int *)(PTR_DAT_000912d0 + param_1 * 0x40 + 0x28),4,(uint *)0x0,0x646d63);
          }
          uVar15 = uVar15 & ~(0x80000000U >> iVar12);
          iVar12 = count_leading_zeroes(uVar15);
        } while (iVar12 != 0x20);
      }
      if (*(int *)(PTR_DAT_000912d0 + iVar9) != 0) {
        FUN_0000d758();
        uVar11 = _DAT_00083000;
        uVar15 = _DAT_00083004 & 0xffffff;
        FUN_0001a7ec();
        iVar12 = *(int *)(PTR_DAT_000912d0 + param_1 * 0x40 + 0x3c);
        *(undefined4 *)(iVar12 + 0x20) = uVar11;
        *(uint *)(iVar12 + 0x24) = uVar15;
      }
      *(undefined4 *)(PTR_DAT_000912d0 + iVar9) = 0;
    }
    else {
      if (cVar1 == '\x01') {
        if (cVar2 != '\0') {
          iVar12 = FUN_0000dc40(param_1 & 0xff);
          uVar13 = *(uint *)(iVar12 + 0xc);
          uVar15 = *(uint *)(iVar12 + 8);
          if ((~*(uint *)(iVar12 + 8) | ~uVar13) == 0) {
            uVar13 = 0;
            uVar15 = uVar13;
          }
          piVar8[0x1e] = uVar15;
          piVar8[0x1f] = uVar13;
          FUN_00008d94(piVar8,1,0,(int *)0x0);
        }
        if (param_2 != 2) {
          if (param_2 == 1) {
            puVar14 = FUN_00006ad0();
            FUN_00009828((int)puVar14);
          }
          goto LAB_00017796;
        }
        cVar2 = *(char *)(piVar8 + 0xe);
        if (cVar2 != '\x01') goto LAB_00017796;
        PTR_DAT_000912d0[iVar10] = 2;
        goto LAB_00017694;
      }
      if (cVar1 == '\x02') {
        if (cVar2 != '\0') {
          FUN_00008d94(piVar8,0,piVar8[0x1e],(int *)piVar8[0x1f]);
        }
        if (*(int *)(puVar7 + 0x34) == 0) goto LAB_00017796;
        cVar2 = '\x01';
        PTR_DAT_000912d0[iVar10] = 3;
        goto LAB_00017694;
      }
      if (cVar1 == '\x03') {
        if ((cVar2 != '\0') &&
           ((*(char *)(piVar8 + 0xe) == '\x01' || (*(char *)((int)piVar8 + 0x2e) != '\0')))) {
          FUN_00008d94(piVar8,0,0,(int *)0x0);
        }
        if ((*(char *)(piVar8 + 0xe) != '\0') || (*(char *)((int)piVar8 + 0x2e) != '\0'))
        goto LAB_00017796;
        cVar2 = '\x01';
        PTR_DAT_000912d0[iVar10] = 0;
        goto LAB_00017694;
      }
    }
    if (cVar2 == '\0') {
LAB_00017796:
      FUN_0001a7ec();
      return;
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00017874(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*_FUN_000178d8 + 0xc);
  if (*(char *)(iVar2 + param_1 * 0x40 + 0x31) == '\0') {
    _DAT_0008000c = *(undefined4 *)(iVar2 + param_1 * 0x40 + 0x24);
    return;
  }
  iVar2 = iVar2 + param_1 * 0x40;
  *(undefined *)(iVar2 + 0x31) = 1;
  if (*(char *)(iVar2 + 0x30) == '\0' || *(char *)(iVar2 + 0x30) == '\x03') {
    return;
  }
  FUN_0000d58c(**(uint **)(iVar2 + 0x14));
  iVar1 = (**(uint **)(iVar2 + 0x14) >> 5) * 4;
  iVar2 = 1 << (**(uint **)(iVar2 + 0x14) & 0x1f);
  *(int *)(&DAT_e000e280 + iVar1) = iVar2;
  *(int *)(&DAT_e000e100 + iVar1) = iVar2;
  return;
}



// WARNING: Could not reconcile some variable overlaps
// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_000178d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uStack60;
  int iStack56;
  undefined4 *apuStack52 [2];
  undefined4 uStack20;
  
  puVar6 = *(undefined4 **)(param_1 + 0x10);
  uStack20 = param_3;
  uVar2 = FUN_0000d61a(*(int **)(param_1 + 0x14));
  if (uVar2 != 0) {
    return;
  }
  while( true ) {
    puVar3 = (undefined4 *)FUN_0000d658(*(int **)(param_1 + 0x14),&iStack56,&uStack60,apuStack52);
    puVar5 = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      puVar5 = apuStack52[0];
    }
    uVar1 = SUB41(puVar5,0);
    if (puVar3 == (undefined4 *)0x0 || puVar5 == (undefined4 *)0x0) break;
    if (iStack56 == 0x65707974) {
      if (uStack60 == 4) {
        puVar5 = (undefined4 *)*puVar5;
      }
      if (uStack60 != 4) break;
      *(undefined4 **)(puVar6 + 2) = puVar5;
    }
    else {
      if (iStack56 == 0x6b736d62) {
        if (uStack60 != 8) break;
        uVar4 = puVar5[1];
        *puVar6 = *puVar5;
        puVar6[1] = uVar4;
      }
      else {
        if (iStack56 == 0x74746573) {
          if (uStack60 == 4) {
            uVar1 = *(undefined *)puVar5;
          }
          if (uStack60 != 4) break;
          *(undefined *)(puVar6 + 3) = uVar1;
        }
      }
    }
    uVar2 = FUN_0000d61a(*(int **)(param_1 + 0x14));
    if (uVar2 != 0) {
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00017a0c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  DAT_00090154 = &DAT_000912c4;
  DAT_00090158 = FUN_00006ad0();
  uVar5 = 0;
  if (DAT_000912c4 != 0) {
    do {
      piVar4 = (int *)(PTR_DAT_000912d0 + uVar5 * 0x40);
      puVar1 = (undefined4 *)FUN_0000a6f4(0xb0);
      puVar1 = FUN_0000a044(puVar1,uVar5,piVar4[3],(char)((uint)(*piVar4 << 0x19) >> 0x18));
      FUN_00009ff8((int)puVar1);
      *(undefined4 **)(piVar4 + 10) = puVar1;
      if (piVar4[4] == 0) {
        piVar4[0xb] = 0;
      }
      else {
        puVar2 = (undefined4 *)FUN_0000a6f4(0x88);
        iVar3 = FUN_00008e94(puVar2,uVar5,puVar1,(char)*piVar4 * '\x02' + '\x01');
        piVar4[0xb] = iVar3;
        iVar3 = FUN_0000db90(uVar5);
        piVar4[0xf] = iVar3;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < DAT_000912c4);
  }
  FUN_000174ac();
  FUN_00007ec8();
  return;
}



undefined4 * FUN_00017aa4(int param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 *local_48;
  undefined *local_44;
  uint local_40;
  int local_3c;
  undefined *local_38;
  int local_34;
  int local_2c;
  int iStack40;
  
  uVar9 = DAT_000912cc;
  local_2c = param_1;
  iStack40 = param_2;
  uVar2 = FUN_00016ddc(0,param_1,param_2);
  local_3c = uVar2 - uVar9 * (uVar2 / uVar9);
  if (*(short *)(PTR_DAT_000912dc + local_3c * 2) == 0) {
    uVar2 = 0;
    if (uVar9 != 0) {
      do {
        puVar7 = (undefined4 *)(PTR_DAT_000912d8 + uVar2 * 0x1c);
        if (puVar7[2] == 0) {
          *(ushort *)(PTR_DAT_000912dc + local_3c * 2) = ~(ushort)uVar2;
          return puVar7;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar9);
    }
  }
  else {
    local_48 = (undefined4 *)((uVar9 + 0x1f >> 5) * 4);
    uVar14 = (int)local_48 + 7U & 0xfffffff8;
    iVar16 = -uVar14;
    FUN_00000610((undefined **)((int)&local_48 + iVar16),local_48,
                 *(undefined *)((int)&local_48 + iVar16));
    uVar2 = 0;
    if (uVar9 != 0) {
      do {
        pbVar3 = PTR_DAT_000912d8 + uVar2 * 0x1c;
        if ((*(int *)(pbVar3 + 8) != 0) &&
           (uVar4 = FUN_00016ddc(0,*(undefined4 *)(PTR_DAT_000912d4 + (uint)*pbVar3 * 0x1c),
                                 *(undefined4 *)(pbVar3 + 4),*(undefined *)((int)&local_48 + iVar16)
                                ), uVar4 - uVar9 * (uVar4 / uVar9) == local_3c)) {
          *(uint *)((int)&local_48 + (uVar2 >> 5) * 4 + iVar16) =
               1 << (uVar2 & 0x1f) | *(uint *)((int)&local_48 + (uVar2 >> 5) * 4 + iVar16);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar9);
    }
    local_44 = (undefined *)((int)&local_48 + uVar14 * -2);
    local_40 = 1;
    do {
      FUN_00000610(local_44,local_48,*(undefined *)((int)&local_48 + uVar14 * -2));
      uVar4 = FUN_00016ddc(local_40,local_2c,iStack40,*(undefined *)((int)&local_48 + uVar14 * -2));
      uVar2 = DAT_000912cc;
      uVar4 = uVar4 - uVar9 * (uVar4 / uVar9);
      pbVar3 = PTR_DAT_000912d8 + uVar4 * 0x1c;
      if (((*(int *)(pbVar3 + 8) == 0) ||
          (uVar5 = FUN_00016ddc(0,*(undefined4 *)(PTR_DAT_000912d4 + (uint)*pbVar3 * 0x1c),
                                *(undefined4 *)(pbVar3 + 4),
                                *(undefined *)((int)&local_48 + uVar14 * -2)),
          *(short *)(PTR_DAT_000912dc + (uVar5 - uVar2 * (uVar5 / uVar2)) * 2) < 0)) ||
         ((*(uint *)((int)&local_48 + (uVar4 >> 5) * 4 + iVar16) & 1 << (uVar4 & 0x1f)) != 0)) {
        uVar2 = 0;
        *(uint *)(local_44 + (uVar4 >> 5) * 4) =
             *(uint *)(local_44 + (uVar4 >> 5) * 4) | 1 << (uVar4 & 0x1f);
        if (uVar9 != 0) {
          do {
            puVar1 = PTR_DAT_000912d8;
            if ((*(uint *)((int)&local_48 + (uVar2 >> 5) * 4 + iVar16) & 1 << (uVar2 & 0x1f)) != 0)
            {
              local_38 = PTR_DAT_000912d4;
              uVar5 = FUN_00016ddc(local_40,*(undefined4 *)
                                             (PTR_DAT_000912d4 +
                                             (uint)(byte)PTR_DAT_000912d8[uVar2 * 0x1c] * 0x1c),
                                   *(undefined4 *)(PTR_DAT_000912d8 + uVar2 * 0x1c + 4),
                                   *(undefined *)((int)&local_48 + uVar14 * -2));
              uVar4 = DAT_000912cc;
              uVar5 = uVar5 - uVar9 * (uVar5 / uVar9);
              pbVar3 = puVar1 + uVar5 * 0x1c;
              if (((*(int *)(pbVar3 + 8) != 0) &&
                  (uVar6 = FUN_00016ddc(0,*(undefined4 *)(local_38 + (uint)*pbVar3 * 0x1c),
                                        *(undefined4 *)(pbVar3 + 4),
                                        *(undefined *)((int)&local_48 + uVar14 * -2)),
                  -1 < *(short *)(PTR_DAT_000912dc + (uVar6 - uVar4 * (uVar6 / uVar4)) * 2))) &&
                 ((*(uint *)((int)&local_48 + (uVar5 >> 5) * 4 + iVar16) & 1 << (uVar5 & 0x1f)) == 0
                 )) goto LAB_00017cbe;
              uVar4 = 1 << (uVar5 & 0x1f);
              if ((*(uint *)(local_44 + (uVar5 >> 5) * 4) & uVar4) != 0) goto LAB_00017cbe;
              *(uint *)(local_44 + (uVar5 >> 5) * 4) =
                   uVar4 | *(uint *)(local_44 + (uVar5 >> 5) * 4);
            }
            uVar2 = uVar2 + 1;
            if (uVar9 <= uVar2) break;
          } while( true );
        }
        uVar2 = 0;
        *(short *)(PTR_DAT_000912dc + local_3c * 2) = (short)local_40;
        if (uVar9 != 0) goto LAB_00017d38;
        goto LAB_00017eea;
      }
LAB_00017cbe:
      local_40 = local_40 + 1;
    } while (local_40 < 0x10000);
  }
  goto LAB_00017ccc;
LAB_00017d38:
  do {
    puVar1 = PTR_DAT_000912d8;
    if ((*(uint *)((int)&local_48 + (uVar2 >> 5) * 4 + iVar16) & 1 << (uVar2 & 0x1f)) != 0) {
      puVar7 = (undefined4 *)(PTR_DAT_000912d8 + uVar2 * 0x1c);
      local_44 = PTR_DAT_000912d4;
      local_38 = (undefined *)puVar7[1];
      uVar5 = FUN_00016ddc(local_40,*(undefined4 *)(PTR_DAT_000912d4 + (uint)*(byte *)puVar7 * 0x1c)
                           ,(undefined *)puVar7[1],*(undefined *)((int)&local_48 + uVar14 * -2));
      uVar4 = DAT_000912cc;
      uVar5 = uVar5 - uVar9 * (uVar5 / uVar9);
      if (uVar5 != uVar2) {
        puVar15 = (undefined4 *)(puVar1 + uVar5 * 0x1c);
        local_34 = puVar15[2];
        if (puVar15[2] != 0) {
          local_48 = (undefined4 *)(puVar1 + uVar5 * 0x1c);
          local_3c = local_48[2];
          if (local_48[2] == 0) goto LAB_00017ccc;
          puVar8 = (undefined4 *)(local_44 + (uint)*(byte *)local_48 * 0x1c);
          local_44 = (undefined *)local_48[1];
          uVar5 = FUN_00016ddc(0,*puVar8,(undefined *)local_48[1],
                               *(undefined *)((int)&local_48 + uVar14 * -2));
          iVar11 = uVar5 - uVar4 * (uVar5 / uVar4);
          if (*(short *)(PTR_DAT_000912dc + iVar11 * 2) == 0) goto LAB_00017ccc;
          if (0 < *(short *)(PTR_DAT_000912dc + iVar11 * 2)) {
            local_48 = (undefined4 *)*puVar15;
            local_44 = (undefined *)puVar15[1];
            uVar12 = puVar15[3];
            local_3c = puVar15[4];
            uVar10 = puVar15[5];
            uVar18 = puVar15[6];
            uVar13 = puVar7[2];
            uVar17 = puVar7[3];
            *puVar15 = *puVar7;
            *(undefined **)(puVar15 + 1) = local_38;
            puVar15[2] = uVar13;
            puVar15[3] = uVar17;
            uVar13 = puVar7[4];
            uVar17 = puVar7[5];
            puVar15[6] = puVar7[6];
            puVar15[4] = uVar13;
            puVar15[5] = uVar17;
            *(undefined4 **)puVar7 = local_48;
            *(undefined **)(puVar7 + 1) = local_44;
            puVar7[2] = local_34;
            puVar7[3] = uVar12;
            puVar7[6] = uVar18;
            puVar7[4] = local_3c;
            puVar7[5] = uVar10;
            uVar2 = uVar2 - 1;
            goto LAB_00017ee0;
          }
          uVar5 = 0;
          if (uVar4 == 0) goto LAB_00017ccc;
          while (puVar8 = (undefined4 *)(puVar1 + uVar5 * 0x1c), puVar8[2] != 0) {
            uVar5 = uVar5 + 1;
            if (uVar4 <= uVar5) goto LAB_00017ccc;
          }
          uVar13 = local_48[3];
          *puVar8 = *local_48;
          *(undefined **)(puVar8 + 1) = local_44;
          puVar8[2] = local_3c;
          puVar8[3] = uVar13;
          uVar10 = local_48[5];
          uVar13 = local_48[6];
          puVar8[4] = local_48[4];
          puVar8[5] = uVar10;
          puVar8[6] = uVar13;
          *local_48 = 0;
          local_48[1] = 0;
          local_48[2] = 0;
          local_48[3] = 0;
          local_48[4] = 0;
          local_48[5] = 0;
          local_48[6] = 0;
          *(ushort *)(PTR_DAT_000912dc + iVar11 * 2) = ~(ushort)uVar5;
        }
        uVar13 = puVar7[1];
        uVar10 = puVar7[2];
        uVar17 = puVar7[3];
        *puVar15 = *puVar7;
        puVar15[1] = uVar13;
        puVar15[2] = uVar10;
        puVar15[3] = uVar17;
        uVar13 = puVar7[4];
        uVar10 = puVar7[5];
        puVar15[6] = puVar7[6];
        puVar15[4] = uVar13;
        puVar15[5] = uVar10;
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar7[4] = 0;
        puVar7[5] = 0;
        puVar7[6] = 0;
      }
    }
LAB_00017ee0:
    uVar2 = uVar2 + 1;
  } while (uVar2 < uVar9);
LAB_00017eea:
  uVar4 = FUN_00016ddc(local_40,local_2c,iStack40,*(undefined *)((int)&local_48 + uVar14 * -2));
  puVar1 = PTR_DAT_000912d8;
  uVar2 = DAT_000912cc;
  puVar7 = (undefined4 *)(PTR_DAT_000912d8 + (uVar4 - uVar9 * (uVar4 / uVar9)) * 0x1c);
  iVar16 = puVar7[2];
  if (iVar16 == 0) {
    return puVar7;
  }
  uVar13 = puVar7[1];
  uVar9 = FUN_00016ddc(0,*(undefined4 *)(PTR_DAT_000912d4 + (uint)*(byte *)puVar7 * 0x1c),uVar13,
                       *(undefined *)((int)&local_48 + uVar14 * -2));
  iVar11 = uVar9 - uVar2 * (uVar9 / uVar2);
  if ((*(short *)(PTR_DAT_000912dc + iVar11 * 2) < 0) && (uVar9 = 0, uVar2 != 0)) {
    do {
      puVar15 = (undefined4 *)(puVar1 + uVar9 * 0x1c);
      if (puVar15[2] == 0) {
        uVar10 = puVar7[3];
        *puVar15 = *puVar7;
        puVar15[1] = uVar13;
        puVar15[2] = iVar16;
        puVar15[3] = uVar10;
        uVar13 = puVar7[4];
        uVar10 = puVar7[5];
        puVar15[6] = puVar7[6];
        puVar15[4] = uVar13;
        puVar15[5] = uVar10;
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar7[4] = 0;
        puVar7[5] = 0;
        puVar7[6] = 0;
        *(ushort *)(PTR_DAT_000912dc + iVar11 * 2) = ~(ushort)uVar9;
        return puVar7;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar2);
  }
LAB_00017ccc:
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



byte * FUN_00017fb4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar1 = DAT_000912cc;
  uVar2 = FUN_00016ddc(0,param_1,param_2);
  uVar2 = SEXT24(*(short *)(PTR_DAT_000912dc + (uVar2 - uVar1 * (uVar2 / uVar1)) * 2));
  if (uVar2 == 0) {
    return (byte *)0x0;
  }
  if ((int)uVar2 < 0) {
    pbVar3 = PTR_DAT_000912d8 + ~uVar2 * 0x1c;
  }
  else {
    uVar2 = FUN_00016ddc(uVar2,param_1,param_2);
    pbVar3 = PTR_DAT_000912d8 + (uVar2 - uVar1 * (uVar2 / uVar1)) * 0x1c;
  }
  if ((*(int *)(pbVar3 + 4) == param_2) &&
     (*(int *)(PTR_DAT_000912d4 + (uint)*pbVar3 * 0x1c) == param_1)) {
    return pbVar3;
  }
  return (byte *)0x0;
}



void FUN_0001803c(uint param_1)

{
  uint *puVar1;
  
  puVar1 = FUN_00006ad0();
  FUN_000094f0(puVar1,param_1,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_00018050(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  puVar2 = FUN_00006ad0();
  if (*puVar2 == param_1) {
    return 1;
  }
  FUN_0000d758();
  uVar6 = *puVar2;
  FUN_000094f0(puVar2,param_1,0);
  if (puVar2[6] == 0) {
    uVar3 = puVar2[8];
    if (uVar3 == 0) {
      uVar4 = 0xffffffff;
      uVar3 = uVar4;
    }
    else {
      uVar4 = *(uint *)(uVar3 + 0x10);
      uVar3 = *(uint *)(uVar3 + 0x14);
    }
  }
  else {
    uVar4 = 0;
    uVar3 = uVar4;
  }
  FUN_0000d758();
  uVar1 = _DAT_00083000;
  uVar5 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  FUN_000094f0(puVar2,uVar6,0);
  FUN_0001a7ec();
  return (uint)(uVar3 < uVar5 + (uVar4 < uVar1)) ^ 1;
}



void FUN_000180de(uint param_1)

{
  uint *puVar1;
  
  puVar1 = FUN_00006ad0();
  if (*puVar1 == param_1) {
    return;
  }
  FUN_0000d758();
  FUN_000094f0(puVar1,param_1,1);
  FUN_0001a7ec();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_00018106(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  undefined4 local_28 [2];
  
  puVar3 = FUN_00006ad0();
  uVar8 = *puVar3;
  local_28[0] = param_4;
  if (uVar8 != param_1) {
    FUN_0000d758();
    FUN_000094f0(puVar3,param_1,0);
  }
  else {
    FUN_0000d758();
    FUN_0000a10c(puVar3 + 2);
  }
  FUN_0000d758();
  uVar1 = _DAT_00083000;
  uVar7 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  uVar5 = uVar1 + puVar3[2];
  iVar6 = uVar7 + puVar3[3] + (uint)CARRY4(uVar1,puVar3[2]);
  piVar4 = (int *)puVar3[8];
  local_28[0] = DAT_000912e4;
  while ((piVar4 != (int *)0x0 &&
         (piVar4[5] + (uint)(uVar5 + 2000 < (uint)piVar4[4]) <= iVar6 + (uint)(0xfffff82f < uVar5)))
        ) {
    uVar10 = (**(code **)(*piVar4 + 0xc))(piVar4,local_28[0],local_28);
    uVar2 = (uint)((ulonglong)uVar10 >> 0x20);
    bVar9 = CARRY4(uVar2,uVar5);
    uVar5 = uVar2 + uVar5;
    piVar4 = (int *)piVar4[9];
    iVar6 = iVar6 + (int)uVar10 + (uint)bVar9;
  }
  if (uVar8 != param_1) {
    FUN_000094f0(puVar3,uVar8,0);
  }
  FUN_0001a7ec();
  return CONCAT44(uVar5 - uVar1,iVar6 - (uVar7 + (uVar5 < uVar1)));
}



void FUN_00018118(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = FUN_00006ad0();
  if (puVar2[6] != 0) {
    return;
  }
  iVar3 = puVar2[8];
  while( true ) {
    if (iVar3 == 0) {
      return;
    }
    if (*(char *)(iVar3 + 0x23) == '\0') {
      uVar4 = *(uint *)(iVar3 + 0x14);
      uVar1 = *(uint *)(iVar3 + 0x10);
    }
    else {
      uVar4 = 0;
      uVar1 = uVar4;
    }
    if ((uVar1 | uVar4) != 0) break;
    iVar3 = *(int *)(iVar3 + 0x24);
  }
  return;
}



void FUN_00018158(void)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_00006ad0();
  if (puVar1[6] == 0) {
    return;
  }
  return;
}



undefined8 FUN_0001817c(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 in_r3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 local_20;
  
  local_20 = in_r3;
  puVar2 = FUN_00006ad0();
  uVar7 = 0;
  iVar8 = 0;
  local_20 = DAT_000912e4;
  if (puVar2[6] != 0) {
    return 0;
  }
  piVar4 = (int *)puVar2[8];
  uVar9 = (**(code **)(*piVar4 + 0xc))(piVar4,DAT_000912e4,&local_20);
  if (*(char *)((int)piVar4 + 5) != '\0') {
    uVar7 = piVar4[2];
    iVar8 = piVar4[3];
  }
  piVar4 = (int *)piVar4[9];
  while (uVar1 = (uint)((ulonglong)uVar9 >> 0x20), piVar4 != (int *)0x0) {
    if (piVar4[5] + (uint)(uVar7 + 2000 < (uint)piVar4[4]) <= iVar8 + (uint)(0xfffff82f < uVar7)) {
      uVar10 = (**(code **)(*piVar4 + 0xc))(piVar4,local_20,&local_20);
      uVar3 = (uint)((ulonglong)uVar10 >> 0x20);
      iVar5 = uVar3 + uVar1;
      iVar6 = (int)uVar9 + (int)uVar10 + (uint)CARRY4(uVar3,uVar1);
      uVar9 = CONCAT44(iVar5,iVar6);
      if (*(char *)((int)piVar4 + 5) != '\0') {
        iVar8 = piVar4[3];
        uVar7 = piVar4[2];
        uVar9 = CONCAT44(iVar5,iVar6);
      }
    }
    piVar4 = (int *)piVar4[9];
  }
  return uVar9;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00018200(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int *piVar6;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 in_lr;
  undefined8 uVar10;
  undefined8 uVar11;
  int local_30;
  int aiStack44 [2];
  undefined4 uStack36;
  undefined4 uStack4;
  
  uVar10 = CONCAT44(unaff_r5,unaff_r6);
  uStack4 = in_lr;
  puVar4 = FUN_00006ad0();
  uStack36 = unaff_r4;
  do {
    FUN_0000c120();
    local_30 = 0;
    FUN_0000d758();
    *(undefined *)(puVar4 + 10) = 0;
    puVar4[0xb] = puVar4[8];
    FUN_0000d758();
    uVar1 = _DAT_00083000;
    uVar9 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    if (puVar4[0xb] == 0) {
      uVar7 = 0xffffffff;
      uVar8 = uVar7;
LAB_000096d6:
      puVar4[0xb] = 0;
      puVar4[0xc] = 0;
      iVar2 = FUN_0000a2a4((int)(puVar4 + 2),puVar4 + 0xb);
      if (iVar2 != 0) {
        FUN_0001a440(0);
        uVar10 = CONCAT44(uVar7,uVar8);
        if ((~uVar7 | ~uVar8) != 0) {
          uVar10 = FUN_0000947c((uint)puVar4,(int *)puVar4[8],(int *)puVar4[9],DAT_000912e4);
          uVar1 = (int)uVar10 + (uint)(uVar1 < (uint)((ulonglong)uVar10 >> 0x20));
          iVar2 = uVar9 - uVar1;
          if (uVar1 <= uVar9) {
            iVar2 = puVar4[8];
          }
          if (uVar1 <= uVar9) {
            puVar4[0xb] = iVar2;
            goto LAB_000096c0;
          }
        }
        puVar4[0xc] = puVar4[0xb];
        FUN_0000a3ec(puVar4 + 2);
        *(undefined *)(puVar4[0xb] + 0x2c) = 0;
      }
    }
    else {
      iVar2 = FUN_0001a440(0);
      if (iVar2 != 0) {
        uVar10 = FUN_0000947c((uint)puVar4,(int *)puVar4[8],(int *)puVar4[9],DAT_000912e4);
      }
      uVar7 = *(uint *)(puVar4[0xb] + 0x10);
      uVar8 = *(uint *)(puVar4[0xb] + 0x14);
      if (uVar9 + (0xfffff82f < uVar1) < uVar8 + (uVar1 + 2000 < uVar7)) goto LAB_000096d6;
LAB_000096c0:
      uVar10 = 0xffffffffffffffff;
      FUN_0000a482(puVar4 + 8);
      *(undefined *)(puVar4[0xb] + 0x2d) = 0;
    }
    FUN_0001a7ec();
    iVar2 = DAT_000912e4;
    piVar6 = (int *)puVar4[0xb];
    if (piVar6 == (int *)0x0) {
      return;
    }
    (**(code **)(*piVar6 + 0xc))(piVar6,DAT_000912e4,aiStack44);
    uVar11 = uVar10;
    FUN_000092a8((int *)puVar4[0xb],puVar4 + 10,(uint)((ulonglong)uVar10 >> 0x20),(uint)uVar10);
    FUN_0000d758();
    if (*(char *)((int *)puVar4[0xb] + 0xb) == '\0') {
LAB_00009792:
      iVar3 = (**(code **)(*(int *)puVar4[0xb] + 0x14))();
      piVar6 = (int *)uVar11;
      if (iVar3 != 0) {
        puVar5 = &UNK_00000001;
        FUN_00009370((uint)puVar4,(int *)puVar4[0xb],1,piVar6);
        uVar11 = CONCAT44(puVar5,piVar6);
      }
    }
    else {
      iVar3 = (**(code **)(*(int *)puVar4[0xb] + 0x14))();
      if (iVar3 == 0) {
        FUN_0000a0d4(puVar4 + 2,puVar4[0xb]);
        *(undefined *)(puVar4[0xb] + 0x2c) = 0;
      }
      else {
        if (*(char *)(puVar4[0xb] + 0x2c) == '\0') goto LAB_00009792;
      }
    }
    piVar6 = (int *)puVar4[0xb];
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      if (*(char *)((int)piVar6 + 5) != '\0') {
        local_30 = 1;
        FUN_00009370((uint)puVar4,piVar6,0,(int *)uVar11);
      }
    }
    else {
      if (*(char *)((int)piVar6 + 5) == '\0') {
        local_30 = 1;
        FUN_0000a444(puVar4 + 8,(int)piVar6,(int)((ulonglong)uVar11 >> 0x20),(int *)uVar11);
        *(undefined *)(puVar4[0xb] + 0x2d) = 0;
        if ((int *)puVar4[8] != (int *)0x0) {
          FUN_0000947c((uint)puVar4,(int *)puVar4[8],(int *)puVar4[9],DAT_000912e4);
        }
      }
    }
    if (((aiStack44[0] == 0) || (DAT_000912e4 != aiStack44[0])) || (local_30 != 0)) {
      if ((int *)puVar4[8] != (int *)0x0) {
        FUN_0000947c((uint)puVar4,(int *)puVar4[8],(int *)puVar4[9],DAT_000912e4);
      }
      if (aiStack44[0] != 0) {
        FUN_000065ec(0xc9,puVar4[0xb],iVar2,aiStack44[0],DAT_000912e4);
      }
    }
    puVar4[0xb] = 0;
    puVar4[0xc] = 0;
    FUN_0001a7ec();
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0001820e(void)

{
  _DAT_0008000c = 0x20;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00018216(void)

{
  _DAT_0008000c = 0x80;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00018258(undefined4 *param_1)

{
  *param_1 = 700000;
  *param_1 = *(undefined4 *)(&DAT_0001b5d8 + ((uint)(_DAT_6005c00c << 0x18) >> 0x1d) * 4);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0001827c(undefined4 *param_1)

{
  *param_1 = *(undefined4 *)(&DAT_0001b5f8 + (_DAT_6005c00c & 3) * 4);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_00018298(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  
  FUN_0000d758();
  puVar2 = DAT_000904a8;
  if (DAT_000904a8 == (uint *)0x0) {
    return 0;
  }
  puVar3 = DAT_000904a8 + 2;
  DAT_000904a8 = (uint *)DAT_000904a8[4];
  *puVar3 = param_2;
  puVar2[3] = param_1;
  puVar2[4] = 0;
  *puVar2 = param_3;
  puVar2[1] = param_4;
  iVar4 = 0x84000;
  if (DAT_000904a4 != (uint *)0x0) {
    puVar3 = DAT_000904a4;
    puVar5 = (uint *)0x0;
    if (DAT_000904a4[1] + (uint)(param_3 < *DAT_000904a4) <= param_4) {
      while ((puVar3 != (uint *)0x0 &&
             (uVar1 = puVar3[1] + (uint)(param_3 < *puVar3), iVar4 = param_4 - uVar1,
             uVar1 <= param_4))) {
        puVar3 = (uint *)puVar3[4];
        puVar5 = puVar3;
      }
      if (puVar5 != (uint *)0x0) {
        *(uint **)(puVar5 + 4) = puVar2;
      }
      if (puVar5 == (uint *)0x0) {
                    // WARNING: Subroutine does not return
        FUN_00000060(puVar3,iVar4);
      }
      *(uint **)(puVar2 + 4) = puVar3;
      goto LAB_00018304;
    }
    *(uint **)(puVar2 + 4) = DAT_000904a4;
  }
  DAT_000904a4 = puVar2;
  _DAT_00084020 = *puVar2;
  _DAT_00084024 = puVar2[1];
  _DAT_0008402c = 1;
LAB_00018304:
  FUN_0001a7ec();
  return 1;
}



undefined4 FUN_00018338(void)

{
  uint uVar1;
  bool bVar2;
  byte abStack16 [4];
  int iStack12;
  
  if (DAT_000904d4 == (undefined **)0x0) {
    return 0;
  }
  uVar1 = FUN_0000efa4(DAT_000904d4,0,abStack16);
  bVar2 = uVar1 == 0;
  if (bVar2) {
    uVar1 = (uint)abStack16[0];
  }
  if (bVar2 && uVar1 == 0) {
    if ((DAT_000904c9 != '\0') && (iStack12 == 0)) {
      return 1;
    }
    return 0;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0001837c(void)

{
  uint in_r3;
  uint uStack16;
  uint uStack12;
  
  DAT_000904cc = FUN_00014250((uint *)"vddcx");
  DAT_000904d0 = FUN_00014250((uint *)"vddmx");
  if (DAT_000904cc != -1 && DAT_000904d0 != -1) {
    FUN_00018258(&uStack12);
    FUN_00014e1c(DAT_000904cc,1,uStack12);
    FUN_0001827c(&uStack16);
    if (uStack16 <= uStack12) {
      uStack16 = uStack12;
    }
    FUN_00014e1c(DAT_000904d0,1,uStack16);
    FUN_00018468();
    FUN_0000f444(0,0,(undefined4 *)&DAT_000904cb,in_r3);
    thunk_FUN_00004d48();
    DAT_000904d4 = FUN_0000e40c((uint *)"/xo/cxo");
    if (DAT_000904d4 != (int *)0x0) {
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00018410(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (DAT_00091324 == 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  iVar2 = 0;
  while( true ) {
    if ((int)(((_DAT_e000e004 & 0x1f) + 1) * 0x20) >> 5 <= iVar2) {
      return;
    }
    if (bVar1) break;
    if ((*(uint *)(DAT_00091324 + iVar2 * 4) & *(uint *)(&DAT_e000e200 + iVar2 * 4)) != 0) {
      bVar1 = true;
    }
    iVar2 = iVar2 + 1;
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x000184aa)

void FUN_00018468(void)

{
  undefined4 *puVar1;
  
  DAT_00095520 = 0;
  DAT_00095524 = 0;
  DAT_00095528 = 1;
  DAT_00095518 = 0;
  DAT_0009551c = 0;
  FUN_00001628((uint *)"VDD_BIMC",(int *)&DAT_0009132c);
  DAT_00091328 = 0;
  DAT_00091322 = 1;
  FUN_0000d4f0(0x2a,2);
  FUN_0000d4f0(0x32,2);
  DAT_00091330 = (undefined4 *)&DAT_0009dba0;
  FUN_00000610((undefined4 *)&DAT_0009dba0,0x60);
  puVar1 = DAT_00091330;
  DAT_00091330[8] = 0;
  *puVar1 = 0x776f6c76;
  puVar1[0x14] = 0;
  puVar1[0xc] = 0x6e696d76;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_000184e8(void)

{
  int iVar1;
  uint uVar2;
  uint extraout_r1;
  uint uVar3;
  bool bVar4;
  undefined8 uVar5;
  byte abStack24 [4];
  int iStack20;
  
  if (DAT_000904c8 == 0) {
    return (uint)DAT_000904c8;
  }
  FUN_0000d758();
  iVar1 = FUN_0000d5a0();
  uVar5 = CONCAT44(DAT_000904d8,DAT_000904dc);
  if (iVar1 == 0) {
    uVar5 = FUN_00018158();
    FUN_0000d758();
    uVar2 = _DAT_00083000;
    DAT_000904d8 = (undefined4)((ulonglong)uVar5 >> 0x20);
    DAT_000904dc = (uint)uVar5;
    uVar3 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    DAT_000904d8 = (undefined4)((ulonglong)uVar5 >> 0x20);
    DAT_000904dc = (uint)uVar5;
    if (uVar3 + (0xfffff82f < uVar2) < DAT_000904dc) {
      if (DAT_000904d4 != (undefined **)0x0) {
        uVar2 = FUN_0000efa4(DAT_000904d4,0,abStack24);
        DAT_000904d8 = (undefined4)((ulonglong)uVar5 >> 0x20);
        DAT_000904dc = (uint)uVar5;
        bVar4 = uVar2 == 0;
        if (bVar4) {
          uVar2 = (uint)abStack24[0];
        }
        if (!bVar4 || uVar2 != 0) {
                    // WARNING: Subroutine does not return
          FUN_00000060();
          DAT_000904d8 = (undefined4)((ulonglong)uVar5 >> 0x20);
          DAT_000904dc = (uint)uVar5;
        }
        if ((DAT_000904c9 != '\0') && (iStack20 == 0)) {
          uVar2 = (uint)DAT_000904ca;
          if (DAT_000904ca != 0) {
            uVar2 = 1;
          }
          FUN_0001aa04(uVar2);
          DAT_000904d8 = (undefined4)((ulonglong)uVar5 >> 0x20);
          DAT_000904dc = (uint)uVar5;
          FUN_0001aaac();
          DAT_000904d8 = (undefined4)((ulonglong)uVar5 >> 0x20);
          DAT_000904dc = (uint)uVar5;
          goto LAB_00018568;
        }
      }
      iVar1 = FUN_00016ba4();
      DAT_000904d8 = (undefined4)((ulonglong)uVar5 >> 0x20);
      DAT_000904dc = (uint)uVar5;
      FUN_00016ca8(iVar1,extraout_r1);
      DAT_000904d8 = (undefined4)((ulonglong)uVar5 >> 0x20);
      DAT_000904dc = (uint)uVar5;
    }
  }
LAB_00018568:
  FUN_0001a7ec();
  DAT_000904d8 = (undefined4)((ulonglong)uVar5 >> 0x20);
  DAT_000904dc = (uint)uVar5;
  return 0;
}



void FUN_00018590(int *param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  
  if (param_2[5] != 0x40) {
    return;
  }
  uVar1 = FUN_00016f14((int)param_2);
  if ((int)uVar1 < 0) {
    return;
  }
  if ((DAT_00091330 != 0) &&
     ((*(uint *)(DAT_00091330 + 0x20) >> uVar1 & 1) == param_2[(param_2[10] ^ 1U) * 2 + 6])) {
    return;
  }
  FUN_0000dba4(uVar1,param_2[(param_2[10] ^ 1U) * 2 + 6]);
  if (DAT_00091330 == 0) {
    return;
  }
  *(int *)(DAT_00091330 + 0x20) = *(int *)(DAT_00091330 + 0x20) << 8;
  if (param_1 != (int *)0x0) {
    do {
      if ((((int **)param_1)[5] == (int *)(FUN_0000003c + 4)) &&
         (uVar1 = FUN_00016f14((int)param_1), -1 < (int)uVar1)) {
        piVar2 = ((int **)param_1)[10];
        if (param_1 == param_2) {
          piVar2 = (int *)((uint)piVar2 ^ 1);
        }
        if (((int **)param_1)[(int)piVar2 * 2 + 6] != (int *)0x0) {
          *(uint *)(DAT_00091330 + 0x20) = 1 << uVar1 | *(uint *)(DAT_00091330 + 0x20);
        }
      }
      param_1 = (int *)*param_1;
    } while ((int **)param_1 != (int **)0x0);
    return;
  }
  return;
}



void FUN_0001862c(int param_1,undefined4 *param_2)

{
  bool bVar1;
  
  bVar1 = param_2 < &DAT_00000004;
  if (bVar1) {
    param_2 = (undefined4 *)&DAT_000935a8;
  }
  if (!bVar1) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  *(undefined4 **)(param_1 + 0x14) = param_2;
  return;
}



void FUN_0001863c(char *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  undefined *puVar5;
  
  uVar3 = 0xffffffff;
  switch(*param_1) {
  case '\0':
  case '\x01':
  case '\x02':
  case '\x03':
  case '\a':
  case '\b':
    uVar3 = *(uint *)(param_1 + 4);
    break;
  case '\x04':
  case '\x05':
    FUN_0001871c(param_1);
    break;
  case '\x06':
    puVar5 = FUN_00018794();
    if (puVar5 == (undefined *)0x0) {
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    FUN_00018afe(puVar5,1);
    if (*param_1 == '\x01') {
      pcVar4 = *(code **)(param_1 + 8);
      iVar2 = *(int *)(param_1 + 0xc);
      if (*(int *)(param_1 + 4) == 3) {
        if (pcVar4 == (code *)0x0) goto LAB_0001870c;
        goto LAB_000186b8;
      }
      piVar1 = (int *)FUN_00018f2c(*(int *)(param_1 + 4));
      if (*(int *)piVar1[2] == 0) {
        do {
                    // WARNING: Do nothing block with infinite loop
        } while( true );
      }
      goto LAB_000186c0;
    }
    if (*param_1 != '\a') goto LAB_0001870c;
    goto LAB_00018690;
  default:
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (uVar3 == 0xffffffff) {
    return;
  }
  if (0x3f < uVar3) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  iVar2 = FUN_00018f18(uVar3);
  puVar5 = *(undefined **)(iVar2 + 0x14);
  if (puVar5 == (undefined *)0x0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  FUN_00018afe(puVar5,1);
  if (*param_1 == '\x01') {
    pcVar4 = *(code **)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if (*(int *)(param_1 + 4) == 3) {
      if (pcVar4 != (code *)0x0) {
LAB_000186b8:
        (*pcVar4)(iVar2);
      }
    }
    else {
      piVar1 = (int *)FUN_00018f2c(*(int *)(param_1 + 4));
      if (*(int *)piVar1[2] == 0) {
        do {
                    // WARNING: Do nothing block with infinite loop
        } while( true );
      }
LAB_000186c0:
      *(code **)(piVar1 + 6) = pcVar4;
      piVar1[7] = iVar2;
      FUN_00019084(piVar1,0);
    }
  }
  else {
    if (*param_1 == '\a') {
LAB_00018690:
      iVar2 = FUN_00018f18(*(int *)(param_1 + 4));
      *(undefined **)(iVar2 + 0x38) = &LAB_00018814_1;
      FUN_00018910(*(int *)(param_1 + 4));
    }
  }
LAB_0001870c:
  FUN_00018afe(puVar5,0);
  return;
}



// WARNING: Removing unreachable block (ram,0x00018744)

void FUN_0001871c(char *param_1)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  
  FUN_00018afe(&DAT_000935a8,1);
  if (*param_1 == '\x01') {
    pcVar3 = *(code **)(param_1 + 8);
    iVar1 = *(int *)(param_1 + 0xc);
    if (*(int *)(param_1 + 4) == 3) {
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
    }
    else {
      piVar2 = (int *)FUN_00018f2c(*(int *)(param_1 + 4));
      if (*(int *)piVar2[2] == 0) {
        do {
                    // WARNING: Do nothing block with infinite loop
        } while( true );
      }
      *(code **)(piVar2 + 6) = pcVar3;
      piVar2[7] = iVar1;
      FUN_00019084(piVar2,0);
    }
  }
  else {
    if (*param_1 == '\a') {
      iVar1 = FUN_00018f18(*(int *)(param_1 + 4));
      *(undefined **)(iVar1 + 0x38) = &LAB_00018814_1;
      FUN_00018910(*(int *)(param_1 + 4));
    }
  }
  FUN_00018afe(&DAT_000935a8,0);
  return;
}



undefined * FUN_00018794(void)

{
  return &DAT_000935a8;
}



undefined4 FUN_0001879c(void)

{
  return 1;
}



void FUN_000187a0(void)

{
  return;
}



undefined4 FUN_000187a2(void)

{
  return 1;
}



void FUN_000187a6(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_0000d758();
    return;
  }
  FUN_0001a7ec();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined1 * FUN_000187b0(int param_1)

{
  undefined1 *puVar1;
  
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  puVar1 = FUN_000187e8((uint)*(byte *)(param_1 + 4));
  if (*(int *)(puVar1 + 8) == 0x7ffffff) {
    return puVar1;
  }
  if (*(int *)(puVar1 + 8) != 2) {
switchD_0000385a_caseD_0:
    return (undefined1 *)0xffffffff;
  }
  switch(*(undefined4 *)(puVar1 + 4)) {
  default:
    goto switchD_0000385a_caseD_0;
  case 1:
  case 2:
  case 3:
    _DAT_0008000c = 0x1000;
    return (undefined1 *)0x0;
  case 4:
    _DAT_0008000c = 0x10;
    FUN_0000b1ac(1);
    _DAT_0008000c = 0x10;
    break;
  case 6:
    _DAT_0008000c = 0x100;
    return (undefined1 *)0x0;
  case 9:
    _DAT_0008000c = 0x10000;
  }
  return (undefined1 *)0x0;
}



undefined1 * FUN_000187e8(uint param_1)

{
  byte bVar1;
  
  if (param_1 < 0x14) {
    bVar1 = (&DAT_000905c8)[param_1 * 2];
    if (bVar1 == 6) {
      bVar1 = (&DAT_000905c9)[param_1 * 2];
    }
    return &DAT_000935cc + (uint)bVar1 * 0x18;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_000188a6(void)

{
  uint uVar1;
  
  FUN_00018f44();
  uVar1 = FUN_00019fa8(0x6b,0x20000,0xffffffff);
  if (uVar1 != 0) {
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_000188d0(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x10) != '\x01') {
    return;
  }
  FUN_000187a6(*(undefined4 *)(param_1 + 0x48),1);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4c);
  uVar1 = *(undefined4 *)(param_1 + 0x50);
  FUN_000187a6(*(undefined4 *)(param_1 + 0x48),0);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00018902. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)(param_1,1,uVar1);
  return;
}



undefined4 FUN_00018910(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00018f2c(param_1);
  *(undefined **)(piVar1 + 8) = &LAB_00018904_1;
  *(code **)(piVar1 + 9) = FUN_00018950 + 1;
  *(code **)(piVar1 + 10) = FUN_000189a2 + 1;
  *(code **)(piVar1 + 0xb) = FUN_000188d0 + 1;
  *(undefined **)(piVar1 + 0xc) = &LAB_000189dc_1;
  *(code **)(piVar1 + 0xd) = FUN_000189ea + 1;
  FUN_00019084(piVar1,1);
  return 6;
}



void FUN_00018950(int param_1)

{
  undefined *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar2;
  
  puVar1 = (undefined *)0x0;
  FUN_000187a6(*(undefined4 *)(param_1 + 0x40),1);
  if (*(int *)(param_1 + 0x4c) == 0) {
    FUN_000187a6(*(undefined4 *)(param_1 + 0x40),0);
    return;
  }
  if (*(char *)(param_1 + 0x3c) == '\0') {
    puVar1 = FUN_000196ae(param_1);
  }
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4c);
  uVar2 = *(undefined4 *)(param_1 + 0x50);
  FUN_000187a6(*(undefined4 *)(param_1 + 0x40),0);
  if (puVar1 != (undefined *)0x0) {
                    // WARNING: Could not recover jumptable at 0x000189a0. Too many branches
                    // WARNING: Treating indirect jump as call
    (*UNRECOVERED_JUMPTABLE)(param_1,2,uVar2);
    return;
  }
  return;
}



void FUN_000189a2(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  code *pcVar1;
  undefined4 uVar2;
  bool bVar3;
  
  uVar2 = 0;
  FUN_000187a6(*(undefined4 *)(param_1 + 0x48),1);
  pcVar1 = *(code **)(param_1 + 0x54);
  bVar3 = pcVar1 != (code *)0x0;
  if (bVar3) {
    pcVar1 = *(code **)(param_1 + 0x4c);
  }
  UNRECOVERED_JUMPTABLE = (code *)0x0;
  if (bVar3 && pcVar1 != (code *)0x0) {
    uVar2 = *(undefined4 *)(param_1 + 0x50);
    UNRECOVERED_JUMPTABLE = pcVar1;
  }
  FUN_000187a6(*(undefined4 *)(param_1 + 0x48),0);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    // WARNING: Could not recover jumptable at 0x000189da. Too many branches
                    // WARNING: Treating indirect jump as call
    (*UNRECOVERED_JUMPTABLE)(param_1,3,uVar2);
    return;
  }
  return;
}



void FUN_000189ea(int param_1)

{
  FUN_000187a6(*(undefined4 *)(param_1 + 0x40),1);
  *(undefined *)(param_1 + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x24) = 0;
  FUN_000187a6(*(undefined4 *)(param_1 + 0x40),0);
  FUN_000187a6(*(undefined4 *)(param_1 + 0x44),1);
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x28) = 0;
  FUN_000187a6(*(undefined4 *)(param_1 + 0x44),0);
  if (*(code **)(param_1 + 0x4c) == (code *)0x0) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00018a2c. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(param_1 + 0x4c))(param_1,9,*(undefined4 *)(param_1 + 0x50));
  return;
}



void FUN_00018a2e(int param_1)

{
  code **ppcVar1;
  int iVar2;
  
  FUN_00018afe(param_1,1);
  iVar2 = *(int *)(param_1 + 0x18);
  while (iVar2 != 0) {
    ppcVar1 = (code **)(iVar2 + 0x38);
    iVar2 = *(int *)(iVar2 + 0x10);
    (**ppcVar1)();
  }
  FUN_00018afe(param_1,0);
  return;
}



undefined * FUN_00018a52(int param_1,int param_2,int param_3,undefined *param_4,int param_5)

{
  code *pcVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  pcVar1 = (code *)param_4;
  if (param_1 != 0) {
    pcVar1 = *(code **)(param_1 + 0xa0);
  }
  if (param_1 == 0 || pcVar1 == (code *)0x0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  puVar3 = *(undefined **)(param_1 + 0x94);
  if (puVar3 < param_4 + param_5) {
    puVar2 = puVar3 + -param_5;
    (*pcVar1)(param_2,param_3 + param_5,puVar2);
    param_4 = param_4 + -(int)puVar2;
    param_5 = 0;
  }
  else {
    puVar2 = (undefined *)0x0;
  }
  (**(code **)(param_1 + 0xa0))(puVar2 + param_2,param_3 + param_5,param_4);
  param_4 = param_4 + param_5;
  if (param_4 == puVar3) {
    param_4 = (undefined *)0x0;
  }
  return param_4;
}



undefined * FUN_00018aa8(int param_1,int param_2,int param_3,undefined *param_4,int param_5)

{
  code *pcVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  pcVar1 = (code *)param_4;
  if (param_1 != 0) {
    pcVar1 = *(code **)(param_1 + 0xa0);
  }
  if (param_1 == 0 || pcVar1 == (code *)0x0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  puVar3 = *(undefined **)(param_1 + 0x94);
  if (puVar3 < param_4 + param_5) {
    puVar2 = puVar3 + -param_5;
    (*pcVar1)(param_2 + param_5,param_3,puVar2);
    param_4 = param_4 + -(int)puVar2;
    param_5 = 0;
  }
  else {
    puVar2 = (undefined *)0x0;
  }
  (**(code **)(param_1 + 0xa0))(param_2 + param_5,puVar2 + param_3,param_4);
  param_4 = param_4 + param_5;
  if (param_4 == puVar3) {
    param_4 = (undefined *)0x0;
  }
  return param_4;
}



void FUN_00018afe(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_0000d758();
    return;
  }
  FUN_0001a7ec();
  return;
}



char * FUN_00018b08(char *param_1,char *param_2,int param_3)

{
  FUN_0001a0cc(param_1,param_2,param_3);
  return param_1;
}



void FUN_00018b14(void)

{
  uint uVar1;
  
  DAT_000901c8 = 1;
  DAT_000901cc = 1;
  DAT_000901b8 = 1;
  DAT_000901bc = 1;
  DAT_000901c0 = 1;
  DAT_000935c4 = 1;
  DAT_000901c4 = 1;
  FUN_00018b88();
  DAT_000935c8 = 1;
  uVar1 = 0;
  do {
    if ((&DAT_000935dc)[uVar1 * 6] != 0x7ffffff) {
      FUN_000038a2();
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 7);
  return;
}



void FUN_00018b88(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  int iVar8;
  undefined4 *puVar9;
  uint auStack56 [2];
  char *local_30;
  int aiStack40 [3];
  
  iVar8 = 7;
  puVar1 = &DAT_000935cc;
  puVar2 = &DAT_000935d0;
  puVar3 = &DAT_000935d4;
  puVar5 = &DAT_000935d8;
  puVar7 = &DAT_000935e0;
  puVar9 = &DAT_000935dc;
  do {
    *puVar1 = 8;
    *puVar2 = 0;
    puVar4 = puVar3 + 6;
    *puVar3 = 0x7ffffff;
    puVar6 = puVar5 + 6;
    *puVar5 = 0;
    *puVar9 = 0x7ffffff;
    *puVar7 = 0;
    iVar8 = iVar8 + -1;
    puVar1 = puVar1 + 0x18;
    puVar2 = puVar2 + 6;
    puVar3 = puVar4;
    puVar5 = puVar6;
    puVar7 = puVar7 + 0x18;
    puVar9 = puVar9 + 6;
  } while (iVar8 != 0);
  iVar8 = FUN_000034b4((uint *)"/core/mproc/smd",aiStack40,puVar4,(uint)puVar6);
  if ((iVar8 == 0) &&
     (iVar8 = FUN_000034e4(aiStack40,(uint *)"smd_intr_enabled",0,auStack56), iVar8 == 0)) {
    if (*local_30 != '\0') {
      DAT_000935cc = 0;
      DAT_000935d0 = 4;
      DAT_000935d4 = 2;
      DAT_000935d8 = 0;
      DAT_000935dc = 8;
    }
    if (local_30[1] != '\0') {
      DAT_000935e4 = 1;
      DAT_000935f4 = 0x1a;
      DAT_000935e8 = 2;
      DAT_000935ec = 2;
      DAT_000935f0 = 0;
    }
    if (local_30[2] != '\0') {
      DAT_000935fc = 2;
      DAT_00093600 = 6;
      DAT_00093604 = 2;
      DAT_00093608 = 0;
      DAT_0009360c = 0x38;
    }
    if (local_30[4] != '\0') {
      DAT_0009362c = 4;
      DAT_00093630 = 9;
      DAT_00093634 = 2;
      DAT_00093638 = 0;
      DAT_0009363c = 0x22;
    }
    if (local_30[6] != '\0') {
      DAT_0009365c = 6;
      DAT_00093660 = 0;
      DAT_00093664 = 0x7ffffff;
      DAT_00093668 = 0;
      DAT_0009366c = 0x7ffffff;
    }
    DAT_00093614 = 3;
    DAT_00093618 = 0xc;
    DAT_0009361c = 2;
    DAT_00093620 = 0;
    DAT_00093624 = 0xb;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_00018c94(uint *param_1,uint param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  uint local_50;
  uint uStack76;
  uint uStack72;
  uint uStack68;
  uint local_40;
  int local_3c;
  uint *local_34;
  uint uStack48;
  int iStack44;
  int iStack40;
  
  iVar2 = DAT_00090168;
  local_3c = DAT_00090168;
  uVar7 = 0x40;
  bVar11 = false;
  local_34 = param_1;
  uStack48 = param_2;
  iStack44 = param_3;
  iStack40 = param_4;
  FUN_00019f44(3);
  _DAT_00080070 = 2;
  uVar8 = 4;
  do {
    puVar3 = (uint *)(DAT_000905c4 + uVar8 * 0x20);
    if (*(char *)puVar3 == '\0') {
      if (uVar7 == 0x40) {
        uVar7 = uVar8;
      }
    }
    else {
      local_50 = *puVar3;
      uStack76 = puVar3[1];
      uStack72 = puVar3[2];
      uStack68 = puVar3[3];
      local_40 = puVar3[4];
      uVar9 = puVar3[6];
      uVar4 = FUN_000003b6(&local_50,local_34,0x13);
      bVar10 = uVar4 == 0;
      if (bVar10) {
        uVar4 = uVar9 & 0xff;
      }
      if (bVar10 && uVar4 == param_2) {
        if ((uVar9 & 0xf00) == 0) {
          uVar9 = uVar9 | param_4 << 8;
          uVar4 = DAT_000905c4 + uVar8 * 0x20;
          *(uint *)(uVar4 + 0x18) = uVar9;
        }
        bVar11 = param_4 == 0;
        if (!bVar11) {
          uVar4 = uVar9 & 0xf00;
        }
        bVar1 = uVar4 == param_4 * 0x100;
        bVar10 = bVar11 || bVar1;
        if (bVar11 || bVar1) {
          uVar4 = uVar9 & 0xf000;
        }
        if (bVar11 || bVar1) {
          bVar10 = uVar4 == param_3 * 0x1000;
        }
        bVar11 = !bVar10;
        uVar7 = uVar8;
        if (bVar10) {
          iVar5 = DAT_000905c4 + uVar8 * 0x20;
          *(int *)(iVar5 + 0x1c) = *(int *)(iVar5 + 0x1c) + 1;
        }
        goto LAB_00018d3a;
      }
    }
    uVar8 = uVar8 + 1;
    if (0x3f < uVar8) {
LAB_00018d3a:
      if (uVar8 == 0x40) {
        if (uVar7 == 0x40) {
          bVar11 = true;
        }
        else {
          pcVar6 = (char *)(DAT_000905c4 + uVar7 * 0x20);
          *(uint *)(pcVar6 + 0x14) = uVar7;
          FUN_00018b08(pcVar6,(char *)local_34,0x14);
          iVar5 = DAT_000905c4 + uVar7 * 0x20;
          *(uint *)(iVar5 + 0x18) = param_2 | param_3 << 0xc | param_4 << 8;
          *(int *)(iVar5 + 0x1c) = *(int *)(iVar5 + 0x1c) + 1;
        }
      }
      _DAT_00080070 = 0;
      FUN_00019f7c(3);
                    // WARNING: Subroutine does not return
      if (bVar11 == true || bVar11 == true) {
        FUN_00000060();
      }
      if (0x3f < uVar7) {
        do {
                    // WARNING: Do nothing block with infinite loop
        } while( true );
      }
                    // WARNING: Subroutine does not return
      if (local_3c == iVar2) {
        return uVar7;
      }
      thunk_FUN_00000060();
    }
  } while( true );
}



int ** FUN_00018dac(int *param_1)

{
  int **ppiVar1;
  
  if (*(int *)(&DAT_000940e8 + (int)param_1 * 4) != 0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  ppiVar1 = FUN_0001402c((int **)&DAT_000941e8);
  if (ppiVar1 != (int **)0x0) {
    FUN_00000610(ppiVar1,0xe0);
    FUN_00014064(ppiVar1,ppiVar1);
    ppiVar1[7] = param_1;
    *(int ***)(&DAT_000940e8 + (int)param_1 * 4) = ppiVar1;
    return ppiVar1;
  }
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void FUN_00018de8(short param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = (uint)*(byte *)(param_2 + 4);
  if (0x13 < *(byte *)(param_2 + 4)) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  bVar1 = (&DAT_000905c8)[uVar2 * 2];
  if ((bVar1 == 6) || ((&DAT_000905c9)[uVar2 * 2] == '\x06')) {
    if (bVar1 == 6) {
      bVar1 = (&DAT_000905c9)[uVar2 * 2];
    }
    uVar2 = FUN_00019ad4((uint)bVar1,(uint)(ushort)(param_1 + 0xe),0x58);
    if ((((uVar2 != 0) && (uVar3 = *(uint *)(param_2 + 0x94), (uVar3 & 0x1f) == 0)) &&
        (0x3ff < uVar3)) &&
       ((uVar3 < 0x20001 &&
        (uVar3 = FUN_00019ad4((uint)bVar1,(uint)(ushort)(param_1 + 0x152),uVar3 << 1), uVar3 != 0)))
       ) {
      iVar4 = *(int *)(param_2 + 0x94) + uVar3;
      if ((&DAT_000905c8)[(uint)*(byte *)(param_2 + 4) * 2] == '\x06') {
        *(uint *)(param_2 + 8) = uVar2;
        *(uint *)(param_2 + 0x98) = uVar3;
        *(int *)(param_2 + 0x9c) = iVar4;
        *(int *)(param_2 + 0xc) = uVar2 + 0x2c;
      }
      else {
        *(int *)(param_2 + 0x98) = iVar4;
        *(uint *)(param_2 + 0x9c) = uVar3;
        *(int *)(param_2 + 8) = uVar2 + 0x2c;
        *(uint *)(param_2 + 0xc) = uVar2;
      }
      *(undefined4 *)(param_2 + 0xa0) = 0x4d7;
      return;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_00018e94(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x14) = 1;
  FUN_000187b0(param_1);
  return;
}



void FUN_00018e9e(int param_1)

{
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x20) != 0) {
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x18) = 1;
  FUN_000187b0(param_1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00018eb4(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[7];
  if (*(int **)(&DAT_000940e8 + iVar1 * 4) != param_1) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  FUN_00019f44(3);
  iVar1 = DAT_000905c4 + iVar1 * 0x20;
  if (*(int *)(iVar1 + 0x1c) != 0) {
    *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + -1;
    _DAT_00080070 = 0;
    FUN_00019f7c(3);
    *(undefined4 *)(&DAT_000940e8 + param_1[7] * 4) = 0;
    param_1[7] = -1;
    *(undefined *)((int)param_1 + 0x21) = 0;
    param_1[5] = 0;
    FUN_0001406e((int)&DAT_000941e8,param_1);
    return;
  }
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void FUN_00018f18(int param_1)

{
  if (*(int *)(&DAT_000940e8 + param_1 * 4) != 0) {
    return;
  }
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



int FUN_00018f2c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(&DAT_000940e8 + param_1 * 4);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x18) == '\0')) {
    return iVar1 + 0x3c;
  }
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void FUN_00018f44(void)

{
  uint uVar1;
  int *piVar2;
  
  FUN_00000610((undefined4 *)&DAT_00093c88,0x460);
  FUN_00000610((undefined4 *)&DAT_000940e8,0x100);
  DAT_000905c4 = FUN_0001999c(0xd,0x800);
  FUN_0001405a((int)&DAT_000941e8);
  uVar1 = 0;
  do {
    piVar2 = (int *)(&DAT_00093c88 + uVar1 * 0xe0);
    (&DAT_00093ca4)[uVar1 * 0x38] = 0xffffffff;
    FUN_00014064(piVar2,piVar2);
    FUN_0001406e((int)&DAT_000941e8,piVar2);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 5);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00018fac(int *param_1)

{
  int **ppiVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  code *UNRECOVERED_JUMPTABLE;
  int iVar5;
  
  *(undefined4 *)param_1[0x11] = 0;
  iVar2 = param_1[0x11];
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 0x20) = 0;
  *(undefined4 *)(param_1[0x11] + 0x1c) = 1;
  FUN_000187b0((int)(param_1 + 0xf));
  if (*(int *)param_1[0x12] != 0) {
    return;
  }
  if (param_1[5] == 0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  ppiVar1 = (int **)(param_1[5] + 0x18);
  piVar3 = *ppiVar1;
  if (piVar3 == param_1) {
    *ppiVar1 = (int *)param_1[4];
  }
  else {
    do {
      piVar4 = piVar3;
      if (piVar4 == (int *)0x0) {
        do {
                    // WARNING: Do nothing block with infinite loop
        } while( true );
      }
      piVar3 = (int *)piVar4[4];
    } while ((int *)piVar4[4] != param_1);
    piVar4[4] = param_1[4];
  }
  iVar5 = param_1[7];
  UNRECOVERED_JUMPTABLE = (code *)param_1[0x15];
  iVar2 = param_1[0x16];
  if (*(int **)(&DAT_000940e8 + iVar5 * 4) != param_1) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  FUN_00019f44(3);
  iVar5 = DAT_000905c4 + iVar5 * 0x20;
  if (*(int *)(iVar5 + 0x1c) == 0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  *(int *)(iVar5 + 0x1c) = *(int *)(iVar5 + 0x1c) + -1;
  _DAT_00080070 = 0;
  FUN_00019f7c(3);
  *(undefined4 *)(&DAT_000940e8 + param_1[7] * 4) = 0;
  param_1[7] = -1;
  *(undefined *)((int)param_1 + 0x21) = 0;
  param_1[5] = 0;
  FUN_0001406e((int)&DAT_000941e8,param_1);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return;
  }
                    // WARNING: Could not recover jumptable at 0x00019072. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)(iVar2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00019084(int *param_1,int param_2)

{
  int **ppiVar1;
  int *piVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  bool bVar11;
  
  iVar9 = *param_1;
  piVar7 = *(int **)(&DAT_000940e8 + iVar9 * 4);
  if (piVar7 == (int *)0x0) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  do {
    uVar10 = *(undefined4 *)param_1[2];
    if ((param_2 == 3) && ((code *)param_1[0xc] != (code *)0x0)) {
      (*(code *)param_1[0xc])(param_1);
    }
    iVar8 = param_2;
    switch(uVar10) {
    case 0:
      if (param_2 == 1) {
        iVar6 = piVar7[5];
        if (iVar6 == 0) {
          do {
                    // WARNING: Do nothing block with infinite loop
          } while( true );
        }
        piVar7[4] = *(int *)(iVar6 + 0x18);
        *(int **)(iVar6 + 0x18) = piVar7;
        *(undefined *)(piVar7 + 0x13) = 0;
        piVar7[0x1d] = piVar7[0x34] + -4;
        (*(code *)piVar7[0x17])(piVar7 + 0xf);
        *(undefined4 *)(piVar7[0x11] + 0x14) = 0;
        *(undefined4 *)(piVar7[0x11] + 0x18) = 0;
        *(undefined4 *)(piVar7[0x11] + 0x1c) = 0;
        *(undefined4 *)piVar7[0x11] = 1;
        iVar6 = *(int *)piVar7[0x12];
        if ((iVar6 != 0 && iVar6 != 4) && (iVar6 != 5)) {
          iVar8 = 2;
        }
      }
      else {
        if (param_2 == 3) {
          if (piVar7[5] == 0) {
            do {
                    // WARNING: Do nothing block with infinite loop
            } while( true );
          }
          ppiVar1 = (int **)(piVar7[5] + 0x18);
          piVar2 = *ppiVar1;
          if (piVar2 == piVar7) {
            *ppiVar1 = (int *)piVar7[4];
          }
          else {
            do {
              piVar3 = piVar2;
              if (piVar3 == (int *)0x0) {
                do {
                    // WARNING: Do nothing block with infinite loop
                } while( true );
              }
              piVar2 = (int *)piVar3[4];
            } while ((int *)piVar3[4] != piVar7);
            piVar3[4] = piVar7[4];
          }
          pcVar4 = (code *)piVar7[0x15];
          iVar6 = piVar7[0x16];
          iVar5 = piVar7[7];
          if (*(int **)(&DAT_000940e8 + iVar5 * 4) != piVar7) {
            do {
                    // WARNING: Do nothing block with infinite loop
            } while( true );
          }
          FUN_00019f44(3);
          iVar5 = DAT_000905c4 + iVar5 * 0x20;
          if (*(int *)(iVar5 + 0x1c) == 0) {
            do {
                    // WARNING: Do nothing block with infinite loop
            } while( true );
          }
          *(int *)(iVar5 + 0x1c) = *(int *)(iVar5 + 0x1c) + -1;
          _DAT_00080070 = 0;
          FUN_00019f7c(3);
          *(undefined4 *)(&DAT_000940e8 + piVar7[7] * 4) = 0;
          piVar7[7] = -1;
          *(undefined *)((int)piVar7 + 0x21) = 0;
          piVar7[5] = 0;
          FUN_0001406e((int)&DAT_000941e8,piVar7);
          if (pcVar4 != (code *)0x0) {
            (*pcVar4)(iVar6);
          }
        }
      }
      break;
    case 1:
      if (param_2 == 0) {
LAB_000192ac:
        FUN_00018fac(piVar7);
      }
      else {
        if (param_2 == 2) {
          *(undefined4 *)piVar7[0x11] = 2;
        }
        else {
joined_r0x0001925c:
          if (param_2 == 7) {
            *(undefined4 *)piVar7[0x12] = 0;
            iVar6 = piVar7[0x12];
            *(undefined4 *)(iVar6 + 4) = 0;
            *(undefined4 *)(iVar6 + 8) = 0;
            *(undefined4 *)(iVar6 + 0xc) = 0;
            *(undefined4 *)(iVar6 + 0x10) = 0;
            *(undefined4 *)(iVar6 + 0x14) = 0;
            *(undefined4 *)(iVar6 + 0x18) = 0;
            *(undefined4 *)(iVar6 + 0x1c) = 0;
            *(undefined4 *)(iVar6 + 0x20) = 0;
            *(undefined4 *)piVar7[0x11] = 5;
          }
        }
      }
      break;
    case 2:
      if (param_2 == 0) goto LAB_000192ac;
      if (param_2 == 3) {
LAB_000192e2:
        *(undefined4 *)piVar7[0x11] = 4;
      }
      else {
        if (param_2 != 4) goto joined_r0x0001925c;
        *(undefined4 *)piVar7[0x11] = 3;
        *(undefined4 *)(piVar7[0x11] + 0x20) = 0;
      }
      break;
    case 3:
      if (param_2 == 0) {
        *(undefined *)((int)piVar7 + 0x4d) = 1;
      }
      else {
        if (param_2 != 3) goto joined_r0x0001925c;
        if (*(char *)((int)piVar7 + 0x4d) == '\0') goto LAB_000192e2;
        *(undefined *)((int)piVar7 + 0x4d) = 0;
        FUN_00018fac(piVar7);
      }
      break;
    case 4:
      if (param_2 == 0) goto LAB_000192ac;
      if (param_2 != 2 && param_2 != 6) goto joined_r0x0001925c;
LAB_000192f4:
      *(undefined *)(piVar7 + 0x13) = 0;
      piVar7[0x1d] = piVar7[0x34] + -4;
      (*(code *)piVar7[0x17])(piVar7 + 0xf);
      *(undefined4 *)(piVar7[0x11] + 0x14) = 0;
      *(undefined4 *)(piVar7[0x11] + 0x18) = 0;
      *(undefined4 *)(piVar7[0x11] + 0x1c) = 0;
      *(undefined4 *)piVar7[0x11] = 1;
      iVar8 = 2;
      break;
    case 5:
      if (param_2 == 0) goto LAB_000192ac;
      if (param_2 != 2) {
        if (param_2 == 3) goto LAB_000192e2;
        if (param_2 != 6) break;
      }
      *(undefined *)(piVar7 + 0x13) = 0;
      piVar7[0x1d] = piVar7[0x34] + -4;
      (*(code *)piVar7[0x17])(piVar7 + 0xf);
      *(undefined4 *)(piVar7[0x11] + 0x14) = 0;
      *(undefined4 *)(piVar7[0x11] + 0x18) = 0;
      *(undefined4 *)(piVar7[0x11] + 0x1c) = 0;
      *(undefined4 *)piVar7[0x11] = 1;
      iVar8 = 2;
      break;
    case 6:
      if ((param_2 == 2 || param_2 == 3) || param_2 == 6) goto LAB_000192f4;
      break;
    default:
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    bVar11 = param_2 == iVar8;
    param_2 = iVar8;
    if (bVar11) {
      if (*(int *)(&DAT_000940e8 + iVar9 * 4) == 0) {
        return;
      }
      if (*(char *)(*(int *)(&DAT_000940e8 + iVar9 * 4) + 0x18) == '\0') {
        *(undefined4 *)(param_1[2] + 0x1c) = 1;
        FUN_000187b0((int)param_1);
        return;
      }
      return;
    }
  } while( true );
}



void FUN_00019368(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)param_1[3];
  if (param_1[5] == iVar2) {
    return;
  }
  if (iVar2 == 0 || iVar2 == 4) {
LAB_000193fe:
    FUN_00019084(param_1,3);
  }
  else {
    switch(param_1[5]) {
    case 0:
      if ((iVar2 != 1 && iVar2 != 2) && iVar2 != 3) {
        if (iVar2 != 6) goto LAB_00019406;
        goto LAB_000193fe;
      }
      iVar1 = *(int *)param_1[2];
      if ((iVar1 == 4 || iVar1 == 5) || iVar1 == 6) {
LAB_000193b4:
        FUN_00019084(param_1,6);
        goto LAB_00019406;
      }
      break;
    case 1:
      if (iVar2 != 2 && iVar2 != 3) goto LAB_00019406;
      break;
    case 2:
      if (iVar2 != 3) goto LAB_00019406;
      iVar1 = *(int *)param_1[2];
      if ((iVar1 == 4 || iVar1 == 5) || iVar1 == 6) goto LAB_000193b4;
      break;
    case 3:
      if (iVar2 != 2) goto LAB_00019406;
      iVar1 = *(int *)param_1[2];
      if ((iVar1 == 4 || iVar1 == 5) || iVar1 == 6) goto LAB_000193b4;
      break;
    case 4:
      if ((iVar2 != 2 && iVar2 != 1) && iVar2 != 3) goto LAB_00019406;
      break;
    case 5:
      if ((iVar2 != 2 && iVar2 != 1) && iVar2 != 3) goto LAB_00019406;
      break;
    case 6:
      if ((iVar2 != 1 && iVar2 != 2) && iVar2 != 3) goto LAB_00019406;
      break;
    default:
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    FUN_00019084(param_1,2);
  }
LAB_00019406:
  param_1[5] = iVar2;
  return;
}



undefined4
FUN_00019434(uint *param_1,undefined param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  uint *local_28;
  undefined local_24;
  undefined4 local_20;
  undefined4 uStack28;
  undefined4 uStack24;
  undefined4 uStack20;
  undefined4 local_10;
  
  uStack24 = param_5;
  uStack20 = param_6;
  local_28 = param_1;
  local_24 = param_2;
  local_20 = param_3;
  uStack28 = param_4;
  iVar1 = FUN_0001945c(&local_28);
  if (iVar1 != 0) {
    local_10 = 0;
  }
  return local_10;
}



undefined4 FUN_0001945c(uint **param_1)

{
  byte bVar1;
  uint **ppuVar2;
  uint *puVar3;
  int **ppiVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint *puVar8;
  bool bVar9;
  char local_38 [4];
  int *local_34;
  bool local_30;
  
  puVar8 = *param_1;
  puVar7 = (undefined4 *)&UNK_00000001;
  ppuVar2 = param_1;
  if (puVar8 != (uint *)0x0) {
    ppuVar2 = (uint **)(uint)*(byte *)puVar8;
  }
  if ((puVar8 == (uint *)0x0 || ppuVar2 == (uint **)0x0) ||
     (bVar1 = *(byte *)(param_1 + 1), 0x13 < bVar1)) {
    return 0xfffffffe;
  }
  puVar3 = param_1[3];
  bVar9 = puVar3 == (uint *)0x0;
  if (bVar9) {
    puVar3 = (uint *)0x2000;
  }
  if (bVar9) {
    param_1[3] = puVar3;
  }
  else {
    if (((uint)puVar3 & 0x1f) != 0) {
      return 0xfffffffe;
    }
    if (puVar3 < (uint *)0x400) {
      return 0xfffffffe;
    }
    if ((uint *)0x20000 < puVar3) {
      return 0xfffffffe;
    }
  }
  if (((uint)param_1[2] & 4) == 0) {
    local_34 = (int *)FUN_00018c94(puVar8,(uint)bVar1,0,2);
  }
  else {
    local_34 = (int *)FUN_00018c94(puVar8,(uint)bVar1,0,1);
  }
  ppiVar4 = FUN_00018dac(local_34);
  FUN_00018b08((char *)((int)ppiVar4 + 0x21),(char *)*param_1,0x14);
  *(undefined *)(ppiVar4 + 6) = 0;
  *(undefined *)(ppiVar4 + 8) = *(undefined *)(param_1 + 1);
  ppiVar4[0xf] = local_34;
  *(undefined *)(ppiVar4 + 0x10) = *(undefined *)(param_1 + 1);
  *(uint **)(ppiVar4 + 0x34) = param_1[3];
  FUN_00018de8((short)local_34,(int)(ppiVar4 + 0xf));
  piVar5 = (int *)FUN_000187a2();
  ppiVar4[0x1f] = piVar5;
  piVar5 = (int *)FUN_0001879c();
  ppiVar4[0x20] = piVar5;
  piVar5 = (int *)FUN_000187a2();
  ppiVar4[0x21] = piVar5;
  *(uint **)(ppiVar4 + 0x22) = param_1[4];
  *(uint **)(ppiVar4 + 0x23) = param_1[5];
  ppiVar4[0x24] = (int *)0x0;
  if (ppiVar4[0x1f] != (int *)0x0) {
    piVar5 = ppiVar4[0x20];
    bVar9 = piVar5 != (int *)0x0;
    if (bVar9) {
      piVar5 = ppiVar4[0x21];
    }
    if (bVar9 && piVar5 != (int *)0x0) {
      ppiVar4[0x11][1] = 1;
      ppiVar4[0x11][3] = 1;
      ppiVar4[0x11][2] = 1;
      uVar6 = (uint)param_1[2] & 3;
      if (uVar6 != 0) {
        if (uVar6 == 1) {
          puVar7 = (undefined4 *)&UNK_00000002;
        }
        else {
          if (uVar6 == 2) {
            puVar7 = (undefined4 *)0x0;
          }
          else {
            if (uVar6 == 3) {
              puVar7 = (undefined4 *)&DAT_00000003;
            }
          }
        }
      }
      if (((uint)param_1[2] & 4) == 0) {
        *(undefined *)(ppiVar4 + 0x1e) = 0;
      }
      else {
        *(undefined *)(ppiVar4 + 0x1e) = 1;
      }
      FUN_0001862c((int)ppiVar4,puVar7);
      local_38[0] = '\a';
      uVar6 = FUN_00000660(*param_1,(uint *)"LOOPBACK");
      local_30 = uVar6 == 0;
      if (local_30) {
        uVar6 = (uint)*(byte *)(param_1 + 1);
      }
      local_30 = local_30 && uVar6 == 0;
      FUN_0001863c(local_38);
      *(int ***)(param_1 + 6) = ppiVar4 + 0xf;
      return 0;
    }
    FUN_000187a0();
  }
  if (ppiVar4[0x20] != (int *)0x0) {
    FUN_000187a0();
  }
  if (ppiVar4[0x21] != (int *)0x0) {
    FUN_000187a0();
  }
  FUN_00018eb4((int *)ppiVar4);
  return 0xffffffff;
}



undefined * FUN_000195e8(int param_1,undefined *param_2,int param_3,uint param_4)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  bool bVar6;
  bool bVar7;
  
  puVar5 = (undefined *)0x0;
  puVar1 = (undefined *)param_1;
  if ((param_1 == 0 || param_2 == (undefined *)0x0) || param_3 == 0) {
    puVar1 = (undefined *)0xffffffff;
  }
  if ((param_1 == 0 || param_2 == (undefined *)0x0) || param_3 == 0) {
    return puVar1;
  }
  FUN_000187a6(*(undefined4 *)(param_1 + 0x40),1);
  if ((*(char *)(param_1 + 0x3c) == '\0') &&
     (puVar5 = FUN_000196ae(param_1), puVar5 == (undefined *)0x0)) {
    FUN_000187a6(*(undefined4 *)(param_1 + 0x40),0);
    return (undefined *)0x0;
  }
  uVar3 = *(uint *)(*(int *)(param_1 + 0xc) + 0x24);
  uVar2 = *(uint *)(param_1 + 0x94);
  bVar7 = uVar3 <= uVar2;
  bVar6 = uVar2 == uVar3;
  if (bVar7 && !bVar6) {
    param_4 = *(uint *)(*(int *)(param_1 + 0xc) + 0x28);
  }
  if (bVar7 && !bVar6) {
    bVar7 = param_4 <= uVar2;
    bVar6 = uVar2 == param_4;
  }
  if (bVar7 && !bVar6) {
    puVar1 = (undefined *)(param_4 - uVar3);
    if (param_4 < uVar3) {
      puVar1 = puVar1 + uVar2;
    }
    if (*(char *)(param_1 + 0x3c) == '\0') {
      if ((undefined *)(uVar2 - 4) < puVar5) {
        puVar4 = puVar5 + (4 - uVar2);
        puVar5 = (undefined *)(uVar2 - 4);
        *(undefined **)(param_1 + 0x84) = puVar4;
      }
      if (puVar1 < puVar5) {
        puVar1 = (undefined *)0x0;
      }
      else {
        puVar1 = puVar5;
        if (param_2 < puVar5) {
          puVar1 = param_2;
        }
        puVar4 = FUN_00018a52(param_1,param_3,*(int *)(param_1 + 0x9c),puVar1,uVar3);
        if (param_2 < puVar5) {
          puVar4 = puVar4 + (int)(puVar5 + -(int)param_2);
          if (*(undefined **)(param_1 + 0x94) <= puVar4) {
            puVar4 = puVar4 + -(int)*(undefined **)(param_1 + 0x94);
          }
        }
        *(undefined **)(*(int *)(param_1 + 0xc) + 0x24) = puVar4;
        FUN_00018e9e(param_1);
        *(undefined4 *)(param_1 + 0x58) = 0;
      }
    }
    FUN_000187a6(*(undefined4 *)(param_1 + 0x40),0);
    return puVar1;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



undefined * FUN_000196ae(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined *unaff_r6;
  undefined *unaff_r7;
  bool bVar5;
  bool bVar6;
  
  iVar3 = *(int *)(param_1 + 0xc);
  puVar4 = *(undefined **)(iVar3 + 0x24);
  puVar1 = *(undefined **)(param_1 + 0x94);
  bVar6 = puVar4 <= puVar1;
  bVar5 = puVar1 == puVar4;
  if (bVar6 && !bVar5) {
    unaff_r7 = *(undefined **)(iVar3 + 0x28);
  }
  if (bVar6 && !bVar5) {
    bVar6 = unaff_r7 <= puVar1;
    bVar5 = puVar1 == unaff_r7;
  }
  if (!bVar6 || bVar5) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (unaff_r7 != puVar4) {
    unaff_r6 = unaff_r7 + -(int)puVar4;
  }
  if (unaff_r7 < puVar4) {
    unaff_r6 = unaff_r6 + (int)puVar1;
  }
  if (unaff_r7 != puVar4) {
    if (unaff_r6 == (undefined *)0x0) {
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    if (puVar1 <= unaff_r6) {
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    puVar2 = *(undefined **)(param_1 + 0x84);
    if (puVar2 != (undefined *)0x0) {
      if (puVar2 < unaff_r6) {
        puVar4 = puVar4 + (int)puVar2;
        if (puVar1 <= puVar4) {
          puVar4 = puVar4 + -(int)puVar1;
        }
        unaff_r6 = unaff_r6 + -(int)puVar2;
        *(undefined4 *)(param_1 + 0x84) = 0;
      }
      else {
        *(undefined **)(param_1 + 0x84) = puVar2 + -(int)unaff_r6;
        unaff_r6 = (undefined *)0x0;
        *(undefined **)(iVar3 + 0x24) = unaff_r7;
        FUN_00018e9e(param_1);
        puVar4 = unaff_r7;
      }
    }
    iVar3 = *(int *)(param_1 + 0x58);
    if ((undefined *)(0x14 - iVar3) < unaff_r6) {
      unaff_r6 = (undefined *)(0x14 - iVar3);
    }
    if (unaff_r6 != (undefined *)0x0) {
      FUN_0000044c(iVar3 + param_1 + 0x70,iVar3 + param_1 + 0x5c,unaff_r6);
      puVar4 = FUN_00018a52(param_1,*(int *)(param_1 + 0x58) + param_1 + 0x5c,
                            *(int *)(param_1 + 0x9c),unaff_r6,(int)puVar4);
      *(undefined **)(*(int *)(param_1 + 0xc) + 0x24) = puVar4;
      FUN_00018e9e(param_1);
    }
    puVar1 = unaff_r6 + *(int *)(param_1 + 0x58);
    *(undefined **)(param_1 + 0x58) = puVar1;
  }
  else {
    puVar1 = *(undefined **)(param_1 + 0x58);
  }
  if (puVar1 == (undefined *)0x14) {
    if (unaff_r7 < puVar4) {
      iVar3 = *(int *)(param_1 + 0x94) - (int)puVar4;
    }
    else {
      iVar3 = -(int)puVar4;
    }
    if ((*(undefined **)(param_1 + 0x5c) <= unaff_r7 + iVar3 + *(int *)(param_1 + 0x8c)) ||
       ((undefined *)(*(int *)(param_1 + 0x94) + -4) == unaff_r7 + iVar3)) {
      return *(undefined **)(param_1 + 0x5c);
    }
  }
  return (undefined *)0x0;
}



undefined * FUN_00019790(int param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 != 0) {
    FUN_000187a6(*(undefined4 *)(param_1 + 0x40),1);
    if (*(char *)(param_1 + 0x3c) == '\0') {
      puVar1 = FUN_000196ae(param_1);
    }
    FUN_000187a6(*(undefined4 *)(param_1 + 0x40),0);
    return puVar1;
  }
  return (undefined *)0xffffffff;
}



undefined4 FUN_000197c2(int param_1,int param_2)

{
  if (param_1 != 0) {
    if (param_2 == 0) {
      return *(undefined4 *)(*(int *)(param_1 + 0xc) + 4);
    }
    if (param_2 == 1) {
      return *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
    }
    if (param_2 == 2) {
      return *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);
    }
    if (param_2 == 3) {
      return *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
    }
  }
  return 0xffffffff;
}



int * FUN_000197f2(int param_1,int **param_2,uint param_3)

{
  int **ppiVar1;
  byte bVar2;
  int **ppiVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint uVar6;
  int *piVar7;
  undefined *puVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  bool bVar16;
  bool bVar17;
  int *piStack60;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (param_1 == 0 || param_2 == (int **)0x0) {
    return (int *)0xffffffff;
  }
  piVar13 = (int *)0x0;
  ppiVar3 = param_2;
  do {
    ppiVar1 = ppiVar3 + 1;
    ppiVar3 = (int **)*ppiVar3;
    piVar13 = (int *)((int)piVar13 + (int)*ppiVar1);
  } while (ppiVar3 != (int **)0x0);
  if (piVar13 == (int *)0x0) {
    return (int *)0x0;
  }
  FUN_000187a6(*(undefined4 *)(param_1 + 0x44),1);
  if ((*(int *)(param_1 + 0x88) != 0) && ((param_3 & 2) == 0)) {
    FUN_000187a6(*(undefined4 *)(param_1 + 0x44),0);
    return (int *)0xffffffff;
  }
  if ((**(int **)(param_1 + 8) == 2) && (*(int *)(*(int *)(param_1 + 0xc) + 8) != 0)) {
    (*(int **)(param_1 + 8))[8] = 0;
    DataSynchronizationBarrier(0xf);
    puVar5 = *(undefined **)(param_1 + 8);
    puVar4 = *(undefined **)(puVar5 + 0x28);
    puVar8 = *(undefined **)(param_1 + 0x94);
    bVar17 = puVar4 <= puVar8;
    bVar16 = puVar8 == puVar4;
    if (bVar17 && !bVar16) {
      puVar5 = *(undefined **)(puVar5 + 0x24);
    }
    if (bVar17 && !bVar16) {
      bVar17 = puVar5 <= puVar8;
      bVar16 = puVar8 == puVar5;
    }
    if (!bVar17 || bVar16) {
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    piVar11 = (int *)(puVar5 + -(int)puVar4);
    piVar12 = piVar11 + -1;
    if (puVar5 <= puVar4) {
      piVar12 = (int *)((int)piVar12 + (int)puVar8);
    }
    bVar2 = *(byte *)(param_1 + 0x3c);
    uVar6 = (uint)bVar2;
    if (bVar2 == 0) {
      uVar6 = *(uint *)(param_1 + 0x88);
    }
    if (bVar2 == 0 && uVar6 == 0) {
      if ((param_3 & 2) == 0) {
        piVar11 = piVar13 + 5;
      }
      else {
        piVar11 = (int *)0x15;
      }
      if (piVar12 < piVar11) {
        *(undefined4 *)(param_1 + 0x54) = 1;
        FUN_000187a6(*(undefined4 *)(param_1 + 0x44),0);
        if (piVar11 <= *(int **)(param_1 + 0x38)) {
          return (int *)0x0;
        }
        return (int *)0xffffffff;
      }
      local_2c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      piVar11 = (int *)(FUN_00000010 + 4);
      piStack60 = piVar13;
      puVar4 = FUN_00018aa8(param_1,*(int *)(param_1 + 0x98),(int)&piStack60,FUN_00000010 + 4,
                            (int)puVar4);
      piVar12 = piVar12 + -5;
    }
    else {
      if (piVar12 == (int *)0x0) goto LAB_0001995c;
    }
    piVar7 = *(int **)(param_1 + 0x88);
    piVar14 = (int *)((int)piVar13 - (int)piVar7);
    if (piVar12 < (int *)((int)piVar13 - (int)piVar7)) {
      piVar14 = piVar12;
    }
    if (param_2 != (int **)0x0) {
      do {
        piVar9 = param_2[1];
        if (piVar9 != (int *)0x0) {
          piVar11 = param_2[2];
        }
        if (piVar9 != (int *)0x0 && piVar11 != (int *)0x0) {
          if ((piVar7 == (int *)0x0) || (piVar7 < piVar9)) {
            piVar15 = (int *)((int)piVar9 - (int)piVar7);
            if (piVar14 < (int *)((int)piVar9 - (int)piVar7)) {
              piVar15 = piVar14;
            }
            iVar10 = (int)piVar11 + (int)piVar7;
            piVar11 = piVar15;
            puVar4 = FUN_00018aa8(param_1,*(int *)(param_1 + 0x98),iVar10,(undefined *)piVar15,
                                  (int)puVar4);
            piVar7 = (int *)0x0;
            piVar14 = (int *)((int)piVar14 - (int)piVar15);
            if (piVar14 == (int *)0x0) break;
          }
          else {
            piVar7 = (int *)((int)piVar7 - (int)piVar9);
          }
        }
        param_2 = (int **)*param_2;
      } while (param_2 != (int **)0x0);
    }
    DataSynchronizationBarrier(0xf);
    *(undefined **)(*(int *)(param_1 + 8) + 0x28) = puVar4;
    piVar11 = (int *)(*(int *)(param_1 + 0x88) + (int)piVar12);
    if (piVar11 < piVar13) {
      *(undefined4 *)(param_1 + 0x54) = 1;
      bVar16 = (param_3 & 2) != 0;
      if (bVar16) {
        piVar12 = (int *)0x80000000;
      }
      if (bVar16) {
        *(int **)(param_1 + 0x88) = piVar11;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(undefined4 *)(param_1 + 0x88) = 0;
      *(undefined4 *)(*(int *)(param_1 + 8) + 0x20) = 1;
      piVar12 = piVar13;
    }
    FUN_000187a6(*(undefined4 *)(param_1 + 0x44),0);
    if ((param_3 & 1) == 0) {
      FUN_00018e94(param_1);
    }
    return piVar12;
  }
LAB_0001995c:
  *(undefined4 *)(param_1 + 0x54) = 1;
  FUN_000187a6(*(undefined4 *)(param_1 + 0x44),0);
  return (int *)0x0;
}



void FUN_0001999c(uint param_1,int param_2)

{
  if (DAT_000901f4 == '\x01') {
    return;
  }
  if (8 < param_1) {
    FUN_000199bc(param_1,param_2,0);
    return;
  }
  FUN_00019b58(param_1,param_2);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int FUN_000199bc(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  if (param_1 < 9) {
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (DAT_000901f4 == 0) {
    FUN_00019d28((uint)DAT_000901f4,param_2);
  }
  if (0x1dd < param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  uVar5 = param_2 + 7U & 0xfffffff8;
  FUN_00019f44(3);
  iVar4 = DAT_0009367c;
  iVar1 = DAT_000901dc;
  iVar3 = DAT_000901d8;
  piVar6 = (int *)(DAT_000901dc + param_1 * 0x10);
  if (*piVar6 == 1) {
    if (*(uint *)(DAT_000901dc + param_1 * 0x10 + 8) != uVar5) goto LAB_00019abe;
    if ((*(uint *)(DAT_000901dc + param_1 * 0x10 + 0xc) & 0xfffffffc) == 0) {
      iVar4 = *(int *)(DAT_000901dc + param_1 * 0x10 + 4);
      iVar3 = DAT_000901e4;
    }
    else {
      iVar4 = *(int *)(DAT_000901dc + param_1 * 0x10 + 4);
      iVar3 = DAT_00093678;
    }
    iVar4 = iVar4 + iVar3;
  }
  else {
    uVar2 = DAT_00093680;
    if (param_3 == 0) {
      uVar2 = *(uint *)(DAT_000901d8 + 8);
    }
    if (uVar2 < uVar5) {
LAB_00019abe:
      _DAT_00080070 = 0;
      FUN_00019f7c(3);
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    if (param_3 == 0) {
      iVar4 = *(int *)(DAT_000901d8 + 4);
      *(int *)(DAT_000901d8 + 4) = iVar4 + uVar5;
      *(int *)(iVar3 + 8) = uVar2 - uVar5;
    }
    else {
      DAT_00093680 = uVar2 - uVar5;
      DAT_0009367c = DAT_0009367c + uVar5;
      iVar3 = param_1 * 0x10 + 0xc;
      *(uint *)(DAT_000901dc + iVar3) = *(uint *)(DAT_000901dc + iVar3) | DAT_00093674;
    }
    iVar3 = param_1 * 0x10 + 4;
    *(int *)(iVar1 + iVar3) = iVar4;
    *(uint *)(iVar1 + param_1 * 0x10 + 8) = uVar5;
    *piVar6 = 1;
    if (param_3 == 0) {
      iVar4 = DAT_000901e4 + iVar4;
    }
    else {
      iVar4 = *(int *)(iVar1 + iVar3) + DAT_00093678;
    }
    DataSynchronizationBarrier(0xf);
  }
  _DAT_00080070 = 0;
  FUN_00019f7c(3);
  return iVar4;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_00019ad4(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  if (param_2 < 9) {
    return 0;
  }
  uVar2 = FUN_0000dad8(param_1,param_3);
  iVar1 = DAT_000901dc;
  if ((DAT_00093678 <= uVar2) && (uVar2 + param_3 <= DAT_00093678 + DAT_00093684)) {
    piVar3 = (int *)(DAT_000901dc + param_2 * 0x10);
    if (*piVar3 == 1) {
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    iVar4 = param_2 * 0x10 + 0xc;
    *(uint *)(DAT_000901dc + iVar4) = *(uint *)(DAT_000901dc + iVar4) | DAT_00093674;
    *(int *)(iVar1 + param_2 * 0x10 + 4) = uVar2 - DAT_00093678;
    *(int *)(iVar1 + param_2 * 0x10 + 8) = param_3;
    *piVar3 = 1;
    _DAT_00080070 = 0;
    return uVar2;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00019adc(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  uVar2 = FUN_0000dad8(param_1,param_3);
  iVar1 = DAT_000901dc;
  if ((DAT_00093678 <= uVar2) && (uVar2 + param_3 <= DAT_00093678 + DAT_00093684)) {
    piVar3 = (int *)(DAT_000901dc + param_2 * 0x10);
    if (*piVar3 != 1) {
      iVar4 = param_2 * 0x10 + 0xc;
      *(uint *)(DAT_000901dc + iVar4) = *(uint *)(DAT_000901dc + iVar4) | DAT_00093674;
      *(int *)(iVar1 + param_2 * 0x10 + 4) = uVar2 - DAT_00093678;
      *(int *)(iVar1 + param_2 * 0x10 + 8) = param_3;
      *piVar3 = 1;
      _DAT_00080070 = 0;
      return;
    }
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int FUN_00019b58(uint param_1,int param_2)

{
  ushort uVar1;
  int extraout_r1;
  int iVar2;
  int iVar3;
  
  if (DAT_000901e4 == -1) {
    iVar3 = param_2;
    if (DAT_000901ec == 0) {
      DAT_000901ec = thunk_FUN_00019f18(0,param_2);
      iVar3 = extraout_r1;
    }
    if (DAT_000901e8 == 0xffffffff) {
      DAT_000901e8 = thunk_FUN_00019ee0(0,iVar3);
    }
    DAT_000901e4 = FUN_00019e40(DAT_000901e8);
  }
  if (DAT_000901d0 == 0) {
    DAT_000901d0 = FUN_00019eb0();
  }
  if (param_1 == 4) {
    if (param_2 == 8) {
      iVar2 = 0x20d0;
      iVar3 = DAT_000901e4;
LAB_00019be4:
      return iVar3 + iVar2;
    }
  }
  else {
    iVar3 = 0;
    while (uVar1 = *(ushort *)(PTR_DAT_000901e0 + iVar3 * 8),
          uVar1 != 0x1de && (uint)uVar1 != param_1) {
      iVar3 = iVar3 + 1;
    }
    if (((uint)uVar1 == param_1) && (*(int *)(PTR_DAT_000901e0 + iVar3 * 8 + 4) == param_2)) {
      iVar3 = FUN_00019ce4(param_1);
      iVar2 = DAT_000901e4;
      goto LAB_00019be4;
    }
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint thunk_FUN_00019ee0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  ulonglong uVar2;
  
  uVar2 = FUN_00019e50(param_1,param_2);
  piVar1 = (int *)(uVar2 >> 0x20);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 0x49494953)) {
    _DAT_00080070 = 0;
    return piVar1[2] & 0xfffffffU | 0x60000000;
  }
  _DAT_00080070 = 0;
  return 0x67d00000;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int thunk_FUN_00019f18(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  ulonglong uVar2;
  
  uVar2 = FUN_00019e50(param_1,param_2);
  piVar1 = (int *)(uVar2 >> 0x20);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 0x49494953)) {
    _DAT_00080070 = 0;
    return piVar1[1];
  }
  _DAT_00080070 = 0;
  return 0x100000;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_00019bfc(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1 < 9) {
    uVar1 = 0;
    do {
      if ((uint)*(ushort *)(PTR_DAT_000901e0 + uVar1 * 8) == param_1) break;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 9);
    if (*(short *)(PTR_DAT_000901e0 + uVar1 * 8) != 0x1de) {
      iVar2 = *(int *)(PTR_DAT_000901e0 + uVar1 * 8 + 4);
      *param_2 = iVar2;
      uVar1 = FUN_00019b58(param_1,iVar2);
      return uVar1;
    }
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (DAT_000901f4 == 0) {
    FUN_00019d28((uint)DAT_000901f4,param_2);
  }
  if (0x1dd < param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  FUN_00019f44(3);
  _DAT_00080070 = 2;
  if (*(int *)(DAT_000901dc + param_1 * 0x10) == 1) {
    *param_2 = *(int *)(DAT_000901dc + param_1 * 0x10 + 8);
    iVar2 = param_1 * 0x10 + 0xc;
    uVar1 = DAT_00093678;
    if ((*(uint *)(DAT_000901dc + iVar2) & 0xfffffffc) == 0) {
      uVar1 = DAT_000901e4;
    }
    uVar1 = *(int *)(DAT_000901dc + param_1 * 0x10 + 4) + uVar1;
    if ((uVar1 == 0) || (*(int *)(DAT_000901dc + iVar2) != 0)) goto LAB_00019cca;
    if (DAT_000901ec == 0) {
      DAT_000901ec = thunk_FUN_00019f18(0,iVar2);
    }
    bVar3 = uVar1 <= DAT_000901e4;
    if (DAT_000901e4 <= uVar1) {
      bVar3 = DAT_000901ec + DAT_000901e4 <= uVar1;
    }
    if ((!bVar3) && (*param_2 + uVar1 < DAT_000901ec + DAT_000901e4)) goto LAB_00019cca;
  }
  uVar1 = 0;
  *param_2 = 0;
LAB_00019cca:
  _DAT_00080070 = 0;
  FUN_00019f7c(3);
  return uVar1;
}



int FUN_00019ce4(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  while (*(ushort *)(PTR_DAT_000901e0 + iVar2 * 8) != 0x1de &&
         (uint)*(ushort *)(PTR_DAT_000901e0 + iVar2 * 8) != param_1) {
    iVar1 = iVar2 * 8;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + *(int *)(PTR_DAT_000901e0 + iVar1 + 4);
  }
  if ((uint)(ushort)(&DAT_0001b110)[iVar2 * 4] != param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  return iVar3;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00019d28(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 extraout_r1;
  uint uVar3;
  uint uVar4;
  
  if (DAT_000901f4 == '\x03') {
    return;
  }
  if (DAT_000901e4 == -1) {
    if (DAT_000901ec == 0) {
      DAT_000901ec = thunk_FUN_00019f18(0,param_2);
      param_2 = extraout_r1;
    }
    if (DAT_000901e8 == 0xffffffff) {
      DAT_000901e8 = thunk_FUN_00019ee0(0,param_2);
    }
    DAT_000901e4 = FUN_00019e40(DAT_000901e8);
  }
  if (DAT_000901d0 == 0) {
    DAT_000901d0 = FUN_00019eb0();
  }
  DAT_000901dc = FUN_00019ce4(2);
  DAT_000901dc = DAT_000901dc + DAT_000901e4;
  if ((DAT_000901d8 == (int *)0xffffffff) && (DAT_000901e4 != -1)) {
    iVar2 = FUN_00019ce4(1);
    DAT_000901d8 = (int *)(iVar2 + DAT_000901e4);
  }
  DAT_000901f0 = FUN_00019ce4(8);
  DAT_000901f0 = DAT_000901f0 + DAT_000901e4;
  _DAT_00080070 = 2;
  if (*DAT_000901d8 == 1) {
    _DAT_00080070 = 0;
    iVar2 = FUN_00019ce4(7);
    FUN_00019f70(iVar2 + DAT_000901e4,0,8);
    DataSynchronizationBarrier(0xf);
    DAT_000901f4 = '\x03';
    bVar1 = true;
    iVar2 = FUN_00019b58(3,0x80);
    if (iVar2 != 0) {
      *(uint *)(iVar2 + 0x38) = *(uint *)(iVar2 + 0x38) | 0xb0000;
      DataSynchronizationBarrier(0xf);
      uVar3 = 0;
      do {
        uVar4 = *(uint *)(iVar2 + uVar3 * 4) & 0xffff0000;
        if (uVar4 != 0 && uVar4 != 0xb0000) {
          bVar1 = false;
          break;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x20);
      _DAT_00080070 = 0;
      if (bVar1) {
        DAT_00093674 = 0x60000;
        DAT_00093678 = FUN_00019e40(0x60000);
        DAT_0009367c = 0;
        DAT_00093680 = 0x5000;
        DAT_00093684 = 0x5000;
        return;
      }
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



int FUN_00019e40(int param_1)

{
  if (param_1 == 0x60000) {
    param_1 = 0x60060000;
  }
  return param_1;
}



ulonglong FUN_00019e50(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  if (DAT_000905fc != -1) {
    return CONCAT44(DAT_000905fc,param_2);
  }
  if ((DAT_000905f4 == 0) &&
     ((iVar1 = FUN_000037f8(1,(uint *)"CORE_TOP_CSR",&DAT_000905f4), iVar1 != 0 ||
      (DAT_000905f4 == 0)))) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  if (*(uint *)(DAT_000905f4 + 0x3d000) != 0) {
    uVar2 = *(uint *)(DAT_000905f4 + 0x3d000);
    DAT_000905fc = uVar2 & 0xfffffff | 0x60000000;
    return CONCAT44(uVar2,*(undefined4 *)(DAT_000905f4 + 0x3d004)) & 0xfffffffffffffff |
           0x6000000000000000;
  }
  return 0;
}



void FUN_00019eb0(void)

{
  int iVar1;
  int local_8 [2];
  
  local_8[0] = 0;
  iVar1 = FUN_000037f8(1,(uint *)"CORE_TOP_CSR",local_8);
  if ((iVar1 == 0) && (local_8[0] != 0)) {
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_00019ee0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  ulonglong uVar2;
  
  uVar2 = FUN_00019e50(param_1,param_2);
  piVar1 = (int *)(uVar2 >> 0x20);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 0x49494953)) {
    _DAT_00080070 = 0;
    return piVar1[2] & 0xfffffffU | 0x60000000;
  }
  _DAT_00080070 = 0;
  return 0x67d00000;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int FUN_00019f18(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  ulonglong uVar2;
  
  uVar2 = FUN_00019e50(param_1,param_2);
  piVar1 = (int *)(uVar2 >> 0x20);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 0x49494953)) {
    _DAT_00080070 = 0;
    return piVar1[1];
  }
  _DAT_00080070 = 0;
  return 0x100000;
}



void FUN_00019f44(uint param_1)

{
  uint *puVar1;
  
  if (DAT_000905f0 <= param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  thunk_FUN_0000d758();
  *(int *)(&DAT_00095b50 + param_1 * 4) = *(int *)(&DAT_00095b50 + param_1 * 4) + 1;
  puVar1 = (uint *)(DAT_000901d0 + param_1 * 0x1000 + 0x5000);
  if ((*puVar1 & 0xff) != 6) {
    do {
      *puVar1 = 6;
    } while ((*puVar1 & 0xff) != 6);
    return;
  }
  return;
}



void thunk_FUN_0000d758(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar2 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x10);
  }
  if ((DAT_000900c4 != 0) && (iVar2 == 0)) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  DAT_000900c4 = DAT_000900c4 + 1;
  return;
}



void FUN_00019f70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_000905f0 = param_3;
  return;
}



void FUN_00019f7c(uint param_1)

{
  uint uVar1;
  
  if ((param_1 < DAT_000905f0) && (uVar1 = FUN_0001a020(param_1), uVar1 == 6)) {
    FUN_0001a070(param_1);
    FUN_0001a7ec();
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_00019fa8(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = 1;
  if ((param_1 != 3) && (bVar5 = 0x18 < param_1 - 0x6b, uVar4 = (uint)!bVar5, bVar5)) {
    return uVar4;
  }
  if (DAT_000901f4 != '\x01') {
    if (param_1 < 9) {
      iVar1 = FUN_00019b58(param_1,0x80);
    }
    else {
      iVar1 = FUN_000199bc(param_1,0x80,0);
    }
    if (iVar1 != 0) {
      *(uint *)(iVar1 + 0x38) = *(uint *)(iVar1 + 0x38) | param_2 & param_3;
      DataSynchronizationBarrier(0xf);
      uVar2 = 0;
      do {
        uVar3 = *(uint *)(iVar1 + uVar2 * 4) & param_3;
        if (uVar3 != 0 && uVar3 != (param_2 & param_3)) {
          _DAT_00080070 = 0;
          return 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < 0x20);
      _DAT_00080070 = 0;
      return uVar4;
    }
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



uint FUN_0001a020(int param_1)

{
  return *(uint *)(DAT_000901d0 + param_1 * 0x1000 + 0x5000) & 0xff;
}



void FUN_0001a070(int param_1)

{
  int iVar1;
  
  if (*(int *)(&DAT_00095b50 + param_1 * 4) == 0) {
    return;
  }
  iVar1 = *(int *)(&DAT_00095b50 + param_1 * 4) + -1;
  *(int *)(&DAT_00095b50 + param_1 * 4) = iVar1;
  if (iVar1 != 0) {
    return;
  }
  *(undefined4 *)(DAT_000901d0 + param_1 * 0x1000 + 0x5000) = 0;
  return;
}



void FUN_0001a0a0(void)

{
  (*DAT_0009182c)(DAT_00091830);
  *(int *)(&DAT_e000e280 + (DAT_0009183c >> 5) * 4) = 1 << (DAT_0009183c & 0x1f);
  return;
}



char * FUN_0001a0cc(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar2 = param_2;
  if (param_3 != 0) {
    iVar4 = param_3 + -1;
    pcVar2 = param_1;
    pcVar3 = param_2;
    pcVar3 = param_2;
    if (iVar4 != 0) {
      do {
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
        param_1 = pcVar2 + 1;
        *pcVar2 = cVar1;
        if (cVar1 == '\0') {
          if (iVar4 != 0) goto LAB_0001a0fe;
          break;
        }
        iVar4 = iVar4 + -1;
        pcVar2 = param_1;
        pcVar3 = pcVar3;
      } while (iVar4 != 0);
      pcVar2 = pcVar3;
      if (param_3 == 0) goto LAB_0001a0f6;
    }
    *param_1 = '\0';
    pcVar2 = pcVar3;
  }
LAB_0001a0f6:
  do {
    pcVar3 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar3;
  } while (cVar1 != '\0');
LAB_0001a0fe:
  return pcVar3 + (-1 - (int)param_2);
}



undefined4 FUN_0001a108(void)

{
  if (DAT_00090488 == 0) {
    return 2;
  }
  if (DAT_00090488 != 150000) {
    if (DAT_00090488 != 100000) {
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    return 0;
  }
  return 1;
}



undefined4 FUN_0001a138(int param_1)

{
  return (&DAT_0001b228)[param_1 * 2];
}



uint FUN_0001a144(void)

{
  return (uint)DAT_00090474;
}



undefined4 FUN_0001a150(void)

{
  return DAT_00090478;
}



void FUN_0001a1dc(byte *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  uVar1 = 0;
  do {
    if ((&DAT_0001b228)[uVar1 * 2] == 0) break;
    if ((byte)(&DAT_0001b22c)[uVar1 * 8] <= *param_1) {
      uVar3 = uVar1;
      uVar2 = (&DAT_0001b228)[uVar1 * 2];
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 3);
  if (DAT_00090488 <= uVar2) {
    return;
  }
  FUN_0000ec02(DAT_0009048c,uVar2);
  DAT_00090488 = uVar2;
  FUN_0001803c(uVar2);
  if ((uint)(&DAT_0001b228)[DAT_00090484 * 2] < uVar2) {
    FUN_000065ec(0xca,DAT_00090484,uVar3,0,0);
    FUN_0001a32c(uVar3,1);
  }
  if ((&DAT_0001b228)[DAT_00090484 * 2] != uVar2) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  return;
}



void FUN_0001a30c(void)

{
  FUN_0000ec02(DAT_0009048c,DAT_00090488);
  return;
}



void FUN_0001a31c(void)

{
  FUN_0000ec02(DAT_0009048c,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0001a32c(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (2 < param_1) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  FUN_0000d758();
  uVar1 = _DAT_00083000;
  uVar4 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  if ((param_1 != DAT_00090484) || (DAT_00090480 == 0)) {
    DAT_00090480 = 1;
    DAT_00090484 = param_1;
    FUN_000144e4(DAT_00090490,(uint)(byte)(&DAT_0001b22c)[param_1 * 8]);
    if (param_2 == 0) {
      FUN_00015020();
    }
  }
  FUN_0000d758();
  uVar2 = _DAT_00083000;
  uVar5 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  uVar3 = uVar2 - uVar1;
  if ((uVar5 - (uVar4 + (uVar2 < uVar1))) + (uint)(DAT_00090478 < uVar3) != 0) {
    DAT_00090478 = uVar3;
  }
  return;
}



uint FUN_0001a3dc(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  DAT_00090474 = 0;
  if (DAT_00090484 == 0) {
    uVar4 = FUN_0001817c();
    uVar1 = (uint)((ulonglong)uVar4 >> 0x20);
    uVar3 = (int)uVar4 * 3 + (int)((ulonglong)uVar1 * 3 >> 0x20);
    uVar2 = (uint)((ulonglong)uVar1 * 3) >> 2 | uVar3 * 0x40000000;
    if ((uVar3 >> 2) + (uint)CARRY4(uVar2,DAT_00090478) <
        (int)uVar4 + (uint)(uVar2 + DAT_00090478 < uVar1)) {
      FUN_000065ec(0xe6,uVar1,uVar2,DAT_00090478,0);
      FUN_000180de(150000);
      DAT_00090474 = 1;
    }
    else {
      FUN_000065ec(0xcf,uVar1,uVar2,DAT_00090478,0);
    }
  }
  return (uint)DAT_00090474;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_0001a440(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined8 uVar6;
  
  if (DAT_0009048c == 0) {
    return 0;
  }
  FUN_0000d758();
  uVar2 = _DAT_00083000;
  uVar3 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  uVar1 = DAT_00090478 * 3;
  uVar6 = FUN_00018158();
  bVar5 = (int)uVar6 + (uint)(uVar2 + uVar1 < (uint)((ulonglong)uVar6 >> 0x20)) <=
          uVar3 + CARRY4(uVar2,uVar1);
  if (((bVar5 | param_1) != 0) && ((bVar5 | DAT_00090484) != 0)) {
    if ((DAT_00090488 < 150000) || (!bVar5)) {
      if ((DAT_00090484 == 0) || (bVar5)) {
        uVar4 = 0;
        if ((DAT_00090484 == 0) && (bVar5)) {
          uVar6 = FUN_00018106(100000,100000,0,150000);
          uVar1 = (uint)((ulonglong)uVar6 >> 0x20);
          uVar2 = (uint)((ulonglong)uVar1 * 3) >> 2 |
                  (int)((ulonglong)uVar1 * 3 >> 0x20) * 0x40000000;
          if (CARRY4(uVar2,DAT_00090478) < (uVar2 + DAT_00090478 < uVar1)) {
            FUN_000065ec(0xce,uVar1,uVar2,DAT_00090478,0);
            FUN_0001a32c(1,0);
            uVar4 = 1;
          }
          else {
            FUN_000065ec(0xcf,uVar1,uVar2,DAT_00090478,0);
          }
        }
        return uVar4;
      }
      uVar1 = FUN_00018050(100000);
      if (uVar1 != 0) {
        FUN_000065ec(0xcd,0,0,0,0);
        FUN_0001a32c(0,0);
        return 1;
      }
      FUN_000065ec(0xcc,0,0,0,0);
    }
    else {
      FUN_000065ec(0xcb,DAT_00090488,0,0,0);
      FUN_0001a32c(1,0);
    }
  }
  return 0;
}



// WARNING: Removing unreachable block (ram,0x0001a5a0)

void FUN_0001a554(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = &DAT_00093818;
  puVar2 = &DAT_00093898;
  iVar4 = 0x10;
  do {
    iVar3 = iVar4;
    *puVar1 = 0xffffffff;
    puVar1[1] = 0xffffffff;
    *puVar2 = 0;
    puVar2[1] = 0;
    iVar4 = iVar3 + -1;
    puVar1 = puVar1 + 2;
    puVar2 = puVar2 + 2;
  } while (iVar4 != 0);
  DAT_00093868 = iVar3 - 2;
  DAT_0009386c = DAT_00093868 >> 4;
  DAT_00093870 = DAT_00093868 * 0x40;
  DAT_00093874 = DAT_00093870 >> 6;
  DAT_000938f0 = 0xe;
  DAT_000938f4 = 0;
  FUN_00016870(&DAT_00090454,(uint *)"RPM External Log",(undefined4 *)0x9dc00,(uint *)0x0,0x2400);
  return;
}



void FUN_0001a5dc(void)

{
  int iVar1;
  
  iVar1 = FUN_00005d10(&DAT_00090458);
  DAT_00090448 = iVar1 == 0;
  FUN_00017124(0x76657773,1,0x10,0x178dd,&LAB_00017970_1,0);
  return;
}



void FUN_0001a620(void)

{
  int iVar1;
  int iVar2;
  
  DAT_000904e8 = DAT_000904ec;
  iVar2 = 7;
  iVar1 = 0;
  do {
    *(int *)(DAT_000904e8 + iVar1 * 0x18) = DAT_000904e8 + iVar1 * 0x18 + 0x18;
    iVar2 = iVar2 + -1;
    iVar1 = iVar1 + 1;
  } while (iVar2 != 0);
  *(undefined4 *)(DAT_000904e8 + 0xa8) = 0;
  DAT_000904f0 = 0;
  DAT_000904f4 = 0;
  DAT_000904f8 = 0;
  DAT_000904fc = 0;
  FUN_000065ec(0x2be,0,0,0,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0001a6a0(uint param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint **ppuVar4;
  uint uVar5;
  uint **ppuVar6;
  uint **ppuVar7;
  uint **ppuVar8;
  bool bVar9;
  
  ppuVar6 = (uint **)0x0;
  FUN_000065ec(0x2bf,param_1,0,0,0);
  bVar2 = false;
  ppuVar8 = (uint **)0x0;
  ppuVar7 = DAT_000904f0;
  if (DAT_000904f0 == (uint **)0x0) {
    return;
  }
  do {
    if (((uint)ppuVar7[1] & param_1) == 0) {
LAB_0001a704:
      ppuVar4 = (uint **)*ppuVar7;
      ppuVar8 = ppuVar7;
    }
    else {
      bVar9 = _DAT_000904e0 == (uint **)0x0;
      if (!bVar9) {
        ppuVar6 = ppuRam000904e4;
      }
      bVar3 = _DAT_000904e0 != ppuVar6;
      bVar1 = ppuVar6 <= _DAT_000904e0;
      ppuVar4 = _DAT_000904e0;
      if ((bVar9 || bVar1) && (!bVar9 && bVar3)) {
        ppuVar4 = (uint **)((int)ppuVar6 + 1);
      }
      if ((bVar9 || bVar1) && (!bVar9 && bVar3)) {
        ppuRam000904e4 = ppuVar4;
      }
      if ((bVar9 || bVar1) && (!bVar9 && bVar3)) goto LAB_0001a704;
      FUN_00007800((int)ppuVar7);
      bVar2 = true;
      uVar5 = (uint)((int)ppuVar7[1] << 0xc) >> 0x1c;
      if ((uVar5 == 0) || (uVar5 = uVar5 - 1, uVar5 != 0)) {
        ppuVar6 = (uint **)((uint)ppuVar7[1] & 0xfff0ffff | (uVar5 & 0xf) << 0x10);
        *(uint ***)(ppuVar7 + 1) = ppuVar6;
        goto LAB_0001a704;
      }
      ppuVar4 = (uint **)*ppuVar7;
      ppuVar6 = ppuVar4;
      if (ppuVar8 != (uint **)0x0) {
        *(uint ***)ppuVar8 = ppuVar4;
        ppuVar6 = DAT_000904f0;
      }
      DAT_000904f0 = ppuVar6;
      *(uint ***)ppuVar7 = DAT_000904e8;
      ppuVar6 = DAT_000904f4;
      DAT_000904e8 = ppuVar7;
      if (DAT_000904f4 == ppuVar7) {
        DAT_000904f4 = ppuVar8;
      }
    }
    ppuVar7 = ppuVar4;
    if (ppuVar4 == (uint **)0x0) {
      if (bVar2) {
        ppuRam000904e4 = (uint **)0x0;
      }
      return;
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0001a744(void)

{
  _DAT_00082040 = 0x21;
  return;
}



undefined4 FUN_0001a750(void)

{
  do {
  } while (DAT_00090544[1] != DAT_00090544[1]);
  return *DAT_00090544;
}



undefined4 FUN_0001a764(void)

{
  return *DAT_00090544;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0001a770(void)

{
  int iVar1;
  uint auStack32 [2];
  int local_18;
  int aiStack16 [4];
  
  FUN_0000346c(0x200009b,aiStack16);
  iVar1 = FUN_000034e4(aiStack16,(uint *)"QTIMER_AC_BASE",0,auStack32);
  if (iVar1 == 0) {
    *(undefined4 *)(local_18 + 0x44) = 0x21;
  }
  iVar1 = FUN_000034e4(aiStack16,(uint *)"QTIMER_BASE",0,auStack32);
  if (iVar1 == 0) {
    DAT_00090544 = local_18;
    return;
  }
  return;
}



int FUN_0001a7ec(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar2 = getBasePriority();
  }
  if (DAT_000900c4 == 0 || iVar2 == 0) {
                    // WARNING: Subroutine does not return
    FUN_00000060();
  }
  DAT_000900c4 = DAT_000900c4 + -1;
  iVar2 = DAT_000900c4;
  if (DAT_000900c4 == 0) {
    iVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0);
    }
  }
  return iVar2;
}



void FUN_0001a814(undefined4 *param_1,uint param_2,uint param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uStack96;
  int iStack92;
  uint uStack72;
  uint uStack68;
  undefined4 uStack64;
  undefined4 uStack60;
  uint uStack56;
  uint uStack52;
  undefined4 uStack48;
  undefined4 uStack44;
  undefined4 uStack40;
  undefined4 uStack36;
  
  uVar4 = 0;
  uVar6 = param_1[7];
  iVar2 = param_1[8];
  uVar5 = 0;
  uVar3 = 0;
  if (uVar6 != 0) {
    do {
      if (param_2 / 1000 <= *(uint *)(iVar2 + uVar3 * 8)) {
        lVar1 = (ulonglong)*(uint *)(iVar2 + uVar3 * 8 + 4) * 1000000;
        uVar4 = (uint)lVar1;
        uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar6);
  }
  if (uVar6 <= uVar3) {
    lVar1 = (ulonglong)*(uint *)(iVar2 + uVar6 * 8 + -4) * 1000000;
    uVar4 = (uint)lVar1;
    uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  }
  uStack72 = 0;
  uStack68 = 0;
  uVar3 = 0;
  if (uVar6 != 0) {
    do {
      if (param_3 / 1000 <= *(uint *)(iVar2 + uVar3 * 8)) {
        lVar1 = (ulonglong)*(uint *)(iVar2 + uVar3 * 8 + 4) * 1000000;
        uStack72 = (uint)lVar1;
        uStack68 = (uint)((ulonglong)lVar1 >> 0x20);
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar6);
  }
  if (uVar6 <= uVar3) {
    lVar1 = (ulonglong)*(uint *)(iVar2 + uVar6 * 8 + -4) * 1000000;
    uStack72 = (uint)lVar1;
    uStack68 = (uint)((ulonglong)lVar1 >> 0x20);
  }
  if ((param_4 == 0) && ((uVar4 ^ uStack72 | uVar5 ^ uStack68) == 0)) {
    return;
  }
  if ((uStack72 | uStack68) == 0) {
    uStack96 = 0xffffffff;
    iStack92 = 0;
    FUN_000039dc(*param_1,param_1[4],param_1[5],&uStack96);
    FUN_000039ca(*param_1,param_1[4],param_1[5],0);
    return;
  }
  uStack48 = 0;
  uStack60 = 0;
  uStack44 = 0;
  uStack40 = 0;
  uStack36 = 0;
  uStack64 = param_1[6];
  uStack56 = uStack72;
  uStack52 = uStack68;
  FUN_000039b2(*param_1,param_1[4],param_1[5],&uStack72);
  if ((param_4 == 0) && ((uVar4 | uVar5) != 0)) {
    return;
  }
  uStack96 = 0xffffffff;
  iStack92 = 1 << param_1[5];
  FUN_000039ca(*param_1,param_1[4],param_1[5],1);
  FUN_000039dc(*param_1,param_1[4],param_1[5],&uStack96);
  return;
}



void FUN_0001a95c(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,uint param_6
                 )

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar7 = CONCAT44(param_5,param_6);
  if ((param_3 ^ param_5 | param_4 ^ param_6) == 0) {
    return;
  }
  if (*(char *)(*(int *)(param_1 + 4) + 0x14) == '\x01') {
    uVar2 = *(uint *)(*(int *)(param_1 + 4) + 0x18);
    lVar1 = (ulonglong)uVar2 * (ulonglong)param_5;
    uVar6 = (uint)lVar1;
    uVar7 = FUN_000001b0(uVar6 + 99,
                         uVar2 * param_6 + (int)((ulonglong)lVar1 >> 0x20) +
                         (uint)(0xffffff9c < uVar6),100,0);
  }
  uVar2 = (uint)((ulonglong)uVar7 >> 0x20);
  iVar3 = *(int *)(param_1 + 0x1c);
  iVar5 = iVar3;
  if (iVar3 == 0) {
    iVar5 = 1;
  }
  if (iVar3 == 0) {
    iVar3 = 1;
  }
  uVar6 = *(int *)(param_1 + 0x20) * iVar3 * 1000;
  iVar3 = uVar6 + uVar2;
  uVar7 = FUN_000001b0(iVar3 - 1,(int)uVar7 + (uint)CARRY4(uVar6,uVar2) + ((uint)(iVar3 != 0) - 1),
                       *(int *)(param_1 + 0x20) * iVar5 * 1000,0);
  uVar4 = (undefined4)((ulonglong)uVar7 >> 0x20);
  FUN_0000c4dc(*(int **)(param_1 + 0x24),uVar4);
  uVar2 = 0;
  if (*(int *)(param_1 + 0x28) == 0) {
    return;
  }
  do {
    FUN_0000c4dc((int *)(*(int *)(param_1 + 0x2c) + uVar2 * 8),uVar4);
    uVar2 = uVar2 + 1;
  } while (uVar2 < *(uint *)(param_1 + 0x28));
  return;
}



void FUN_0001aa04(int param_1)

{
  undefined uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  uint local_38;
  uint uStack52;
  undefined4 auStack48 [2];
  uint local_28;
  undefined4 auStack36 [2];
  uint local_1c;
  
  FUN_00014a7c(DAT_000904cc,auStack48);
  FUN_00014a7c(DAT_000904d0,auStack36);
  FUN_00014ab4(DAT_000904cc,DAT_000904d0,&local_38,&uStack52);
  if ((param_1 == 0) && (uStack52 <= local_38 + 300000)) {
    bVar4 = local_1c <= uStack52;
    bVar3 = uStack52 == local_1c;
    uVar2 = local_1c;
    if (!bVar4 || bVar3) {
      uVar2 = local_28;
    }
    if (!bVar4 || bVar3) {
      bVar4 = uVar2 <= local_38;
      bVar3 = local_38 == uVar2;
    }
    if (bVar4 && !bVar3) {
                    // WARNING: Subroutine does not return
      FUN_00000060();
    }
    FUN_0000dc9c(uStack52,local_1c,local_38,uVar2);
    uVar2 = FUN_00014a48(DAT_000904cc,1);
    if (local_38 <= uVar2) {
      DAT_00095528 = 1;
      FUN_0001a6a0(0x20);
      uVar1 = 1;
      goto LAB_0001aa8e;
    }
  }
  else {
    FUN_0000dc9c(local_1c,local_1c,local_28,local_28);
  }
  DAT_00095528 = 0;
  FUN_0001a6a0(2);
  uVar1 = 0;
LAB_0001aa8e:
  thunk_FUN_00004958(uVar1);
  FUN_0001aae4();
  FUN_0000bd18();
  return;
}



void FUN_0001aaac(void)

{
  uint uVar1;
  
  FUN_0000bf44();
  if (DAT_00095528 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = 0x40;
  }
  FUN_0001a6a0(uVar1);
  uVar1 = FUN_0001a144();
  if (uVar1 != 0) {
    FUN_0001a32c(1,0);
    DAT_00090474 = 0;
    return;
  }
  return;
}



void FUN_0001aae4(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  iVar1 = FUN_0001a108();
  uVar2 = (uint)DAT_00091321;
  if (DAT_00091321 != 0) {
    uVar2 = 6;
  }
  lVar5 = FUN_0001674c(uVar2,iVar1);
  uVar6 = FUN_0000dc74();
  uVar2 = (uint)((ulonglong)uVar6 >> 0x20);
  DAT_00095520 = (uint)((ulonglong)lVar5 >> 0x20);
  DAT_00095524 = (int)lVar5;
  if (lVar5 == 0) {
    DAT_00095520 = 0xc000;
    DAT_00095524 = (int)uVar6 + (uint)(0xffff3fff < uVar2);
  }
  else {
    DAT_00095524 = DAT_00095524 + (int)uVar6 + (uint)CARRY4(DAT_00095520,uVar2);
  }
  DAT_00095520 = uVar2 + DAT_00095520;
  if (DAT_00091321 == 0) {
    iVar3 = 1;
  }
  else {
    iVar3 = 7;
  }
  lVar5 = FUN_0001674c(iVar3,iVar1);
  DAT_00091338 = (undefined4)((ulonglong)uVar6 >> 0x20);
  DAT_0009133c = (undefined4)uVar6;
  uVar7 = FUN_0000dc7e();
  DAT_00091338 = (undefined4)((ulonglong)uVar6 >> 0x20);
  DAT_0009133c = (undefined4)uVar6;
  DAT_00091340 = (uint)((ulonglong)uVar7 >> 0x20);
  DAT_00091344 = (int)uVar7;
  DAT_00095518 = (uint)((ulonglong)lVar5 >> 0x20);
  DAT_0009551c = (int)lVar5;
  if (lVar5 != 0) {
    bVar4 = CARRY4(DAT_00095518,DAT_00091340);
    DAT_00095518 = DAT_00095518 + DAT_00091340;
    DAT_0009551c = DAT_00091344 + DAT_0009551c + (uint)bVar4;
    return;
  }
  DAT_00095518 = DAT_00091340 + 0xc000;
  DAT_0009551c = DAT_00091344 + (uint)(0xffff3fff < DAT_00091340);
  return;
}



undefined4 FUN_0001ab70(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *param_1) {
    uVar1 = *(undefined4 *)(param_1[1] + param_2 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



void FUN_0001ab80(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00000154(8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_00000060();
}



void FUN_0001ab96(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00000182(param_1[1],param_2 << 2);
  param_1[1] = uVar1;
  uVar2 = *param_1;
  if (uVar2 < param_2) {
    FUN_00000610((undefined4 *)(uVar1 + uVar2 * 4),(param_2 - uVar2) * 4);
  }
  *param_1 = param_2;
  return;
}



void FUN_0001abc0(uint *param_1,uint param_2,undefined4 param_3)

{
  if (param_2 < *param_1) {
    *(undefined4 *)(param_1[1] + param_2 * 4) = param_3;
  }
  return;
}



undefined4 FUN_0001abce(undefined4 *param_1)

{
  return *param_1;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

void FUN_0001ac64(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte in_stack_ffffff80;
  uint auStack124 [2];
  uint uStack116;
  uint local_6c;
  undefined4 *puStack104;
  uint uStack96;
  undefined4 auStack92 [2];
  undefined4 *puStack84;
  uint uStack80;
  uint uStack76;
  uint uStack60;
  int local_38;
  int iStack52;
  byte abStack48 [8];
  uint uStack40;
  
  local_38 = 0;
  uVar3 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  if (uVar3 == 0x19) {
    iVar5 = 0;
  }
  else {
    if (uVar3 == 0x2b) {
      iVar5 = 1;
    }
    else {
      if (uVar3 == 0x31) {
        iVar5 = 2;
      }
      else {
        if (uVar3 != 0x49) {
                    // WARNING: Subroutine does not return
          FUN_00000060();
        }
        iVar5 = 4;
      }
    }
  }
  FUN_00005184(&local_6c);
  uVar3 = 0;
  if (local_6c == 0) {
    return;
  }
  puStack84 = &DAT_0009368c + iVar5 * 8;
  iStack52 = iVar5 * 9;
  iVar1 = iVar5 * 0x24;
  iVar4 = local_38;
  do {
    local_38 = iVar4;
    uStack116 = *(uint *)((&DAT_0001b380)[iStack52] + uVar3 * 4);
    uStack80 = puStack84[uVar3];
    uVar10 = *(uint *)((&DAT_0001b384)[iVar5 * 9] + uVar3 * 4);
    uVar11 = *(uint *)(*(int *)(&DAT_0001b388 + iVar1) + uVar3 * 4);
    puStack104 = puStack84 + uVar3;
    uVar12 = *(uint *)((&DAT_0001b38c)[iVar5 * 9] + uVar3 * 4);
    uStack76 = *(uint *)((&DAT_0001b390)[iVar5 * 9] + uVar3 * 4);
    uStack40 = uStack116 & ~uStack80;
    uVar6 = uStack40 | uVar10 ^ puStack104[2] | uVar11 ^ puStack104[4] | uVar12 ^ puStack104[6];
    while (uVar6 != 0) {
      iVar4 = count_leading_zeroes(uVar6);
      uVar8 = (0x1f - iVar4) + uVar3 * 0x20;
      uVar7 = 1 << (uVar8 & 0x1f);
      FUN_00005154(uVar7 & uVar10,uVar7 & uVar11,uVar7 & uVar12,uVar7,abStack48);
      uVar9 = (uint)abStack48[0];
      uVar8 = FUN_00005148(uVar8,(uint *)&stack0xffffff80);
      if ((uVar8 != 0) &&
         (uVar8 = FUN_0000524c((uint)&stack0xffffff00 | (uint)in_stack_ffffff80,&uStack60),
         uVar8 != 0)) {
        if (*(int *)(uStack60 * 0x1000 + 0x61000008) << 0x17 < 0) {
          iVar4 = FUN_0000d778(*(undefined4 *)(&DAT_0001b394 + iVar1),uStack60);
          if (iVar4 != 0) {
LAB_0001ad92:
            FUN_00005268((uint)&stack0xffffff00 | (uint)in_stack_ffffff80,uVar9);
          }
        }
        else {
          if (*(uint *)(&DAT_0001b394 + iVar1) ==
              (uint)(*(int *)(uStack60 * 0x1000 + 0x61000008) << 0x18) >> 0x1d) goto LAB_0001ad92;
        }
      }
      uVar6 = uVar6 & ~uVar7;
    }
    puStack104[2] = uVar10;
    puStack104[4] = uVar11;
    puStack104[6] = uVar12;
    uVar6 = uStack40;
    while (uVar6 != 0) {
      iVar4 = count_leading_zeroes(uVar6);
      uVar11 = (0x1f - iVar4) + uVar3 * 0x20;
      uVar10 = FUN_00005148(uVar11,auStack124);
      if (uVar10 != 0) {
        FUN_000050ec(auStack124[0]);
      }
      uVar6 = uVar6 & ~(1 << (uVar11 & 0x1f));
    }
    uVar6 = uStack80 & ~uStack116;
    iVar4 = local_38;
    while (local_38 = iVar4, uVar6 != 0) {
      iVar4 = count_leading_zeroes(uVar6);
      uVar11 = (0x1f - iVar4) + uVar3 * 0x20;
      uVar10 = FUN_00005148(uVar11,&uStack96);
      if (uVar10 != 0) {
        FUN_00005184(auStack92);
        uVar10 = uVar11 >> 5;
        uVar12 = 1 << (uVar11 & 0x1f);
        if (((((uVar12 & *(uint *)(&DAT_600601d8 + uVar10 * 4)) == 0) &&
             ((uVar12 & *(uint *)(uVar10 * 4 + 0x600611d8)) == 0)) &&
            ((uVar12 & *(uint *)(&DAT_600621d8 + uVar10 * 4)) == 0)) &&
           (((uVar12 & *(uint *)(uVar10 * 4 + 0x600631d8)) == 0 &&
            ((uVar12 & *(uint *)(uVar10 * 4 + 0x600641d8)) == 0)))) {
          FUN_00005094(uStack96);
        }
      }
      uVar6 = uVar6 & ~(1 << (uVar11 & 0x1f));
      iVar4 = local_38;
    }
    puStack84[uVar3] = uStack116;
    *(uint *)((&DAT_0001b390)[iVar5 * 9] + uVar3 * 4) = uStack76;
    if ((uStack76 & uStack116) != 0) {
      local_38 = 1;
    }
    uVar3 = uVar3 + 1;
    if (local_6c <= uVar3) {
      if (local_38 != 0) {
        local_38 = iVar4;
        (*(code *)(&DAT_0001b39c)[iVar5 * 9])();
      }
      return;
    }
  } while( true );
}



void FUN_0001aea4(void)

{
  FUN_00005084();
  FUN_000050ec(0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0001aeb4(void)

{
  uint uVar1;
  uint uVar2;
  uint local_20;
  uint local_1c [2];
  
  _DAT_e000e184 = 0x400;
  FUN_00005184(local_1c);
  uVar2 = 0;
  if (local_1c[0] != 0) {
    do {
      FUN_00004cd8(uVar2,&local_20);
      *(uint *)(&DAT_600601f8 + uVar2 * 4) = *(uint *)(&DAT_600601f8 + uVar2 * 4) | local_20;
      *(uint *)(&DAT_600611f8 + uVar2 * 4) = *(uint *)(&DAT_600611f8 + uVar2 * 4) | local_20;
      *(uint *)(&DAT_600621f8 + uVar2 * 4) = *(uint *)(&DAT_600621f8 + uVar2 * 4) | local_20;
      *(uint *)(&DAT_600631f8 + uVar2 * 4) = *(uint *)(&DAT_600631f8 + uVar2 * 4) | local_20;
      *(uint *)(&DAT_600641f8 + uVar2 * 4) = *(uint *)(&DAT_600641f8 + uVar2 * 4) | local_20;
      uVar2 = uVar2 + 1;
    } while (uVar2 < local_1c[0]);
  }
  uVar2 = 0;
  do {
    uVar1 = 0;
    if (local_1c[0] != 0) {
      do {
        if ((*(uint *)((&DAT_0001b380)[uVar2 * 9] + uVar1 * 4) &
            *(uint *)((&DAT_0001b390)[uVar2 * 9] + uVar1 * 4)) != 0) {
          (*(code *)(&DAT_0001b398)[uVar2 * 9])();
          (*(code *)(&DAT_0001b39c)[uVar2 * 9])();
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < local_1c[0]);
    }
    uVar2 = uVar2 + 1;
    if (4 < uVar2) {
      return;
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_0001af80(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *in_r3;
  uint uVar6;
  
  if (DAT_000904b4 == 0) {
    return;
  }
  puVar4 = (undefined4 *)FUN_0000a6f4(0x48);
  iVar3 = DAT_000904b4;
  DAT_000904b0 = (int *)FUN_00009338(puVar4,0,1);
  *(undefined **)DAT_000904b0 = &DAT_0001da38;
  *(undefined *)((int)DAT_000904b0 + 0x2e) = 0;
  DAT_000904b0[0x10] = iVar3;
  DAT_000904b0[0xe] = 0x2580;
  DAT_000904b0[0xf] = 0;
  uVar5 = 0;
  DAT_000904b0[0xc] = 480000;
  DAT_000904b0[0xd] = 0;
  FUN_0000d758();
  uVar1 = _DAT_00083000;
  uVar6 = _DAT_00083004 & 0xffffff;
  FUN_0001a7ec();
  piVar2 = DAT_000904b0;
  DAT_000904b8 = uVar1;
  if ((DAT_000904b0[0xd] | DAT_000904b0[0xc]) != 0) {
    DAT_000904bc = uVar6;
    *(undefined *)((int)DAT_000904b0 + 0x2e) = 1;
    FUN_0000d758();
    uVar1 = _DAT_00083000;
    uVar6 = _DAT_00083004 & 0xffffff;
    FUN_0001a7ec();
    *(undefined *)((int)piVar2 + 5) = 1;
    piVar2[2] = uVar1 + piVar2[0xc];
    piVar2[3] = piVar2[0xd] + uVar6 + (uint)CARRY4(uVar1,piVar2[0xc]);
    FUN_00009246(piVar2,0,uVar5,in_r3);
    return;
  }
  DAT_000904bc = uVar6;
  return;
}


