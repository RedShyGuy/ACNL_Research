Researched Function Headers for Animal Crossing New Leaf Version 1.5 - Region USA (TID: 0004000000086300)

| Function Offset  | Function Header | Info |
| ------------- | ------------- | ------------- |
| 0x100000 | void entry(void) |  |
| 0x100024 |  |  |
| 0x100048 |  | DLLHeap |
| 0x100088 |  | NetHeap |
| 0x1000c4 |  | UgcHeap |
| 0x100104 |  | FontHeap |
| 0x100148 |  | SaveHeap |
| 0x10018c |  | WorkHeap |
| 0x1001d0 |  | FaderHeap |
| 0x100214 |  | FieldHeap |
| 0x100260 |  | PhotoHeap |
| 0x1002a4 |  | SoundHeap |
| 0x1002e8 |  | StageHeap |
| 0x10032c |  | ScriptHeap |
| 0x100378 |  | NetGameHeap |
| 0x1003bc |  | WeatherHeap |
| 0x100400 |  | RealEstateHeap |
| 0x100448 |  | ModelEffectUnitHeap |
| 0x100490 |  | SeadParticleHeap |
| 0x1004dc |  | HumanAnimBankHeap |
| 0x100528 |  | ModelEffectResHeap |
| 0x100574 |  | ParticleHandleHeap |
| 0x1005c0 |  |  |
| 0x100608 |  |  |
| 0x100684 |  |  |
| 0x100794 |  |  |
| 0x1007c0 |  |  |
| 0x1007dc |  |  |
| 0x10082c | int wcslen_16(short *str) | thunk of 0x100834 |
| 0x100834 | int wcslen_16(short *str) |  |
| 0x100f5c | int swprintf_16(short *dest, uint max_len, short *fmt,...) | thunk of 0x100f64 |
| 0x100f64 | int swprintf_16(short *dest, uint max_len, short *fmt,...) |  |
| 0x1017d8 | short * wcscpy_16(short *dest, short *src) | thunk of 0x1017e0 |
| 0x1017e0 | short * wcscpy_16(short *dest, short *src) |  |
| 0x1017f4 | short * wcsncpy_16(short *dest, short *src, int n) | thunk of 0x1017fc |
| 0x1017fc | short * wcsncpy_16(short *dest, short *src, int n) |  |
| 0x12a21c | void ConvertDateTimeToMilliseconds(uint64_t *result, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second, uint16_t millisecond) |  |
| 0x12ec68 | void* memcopy_unaligned(void *dst, const void *src, size_t length) |  |
| 0x12f3d8 | Result GetProcessId(u32* processId, Handle process) |  |
| 0x130ed4 | int CalculateDaysSince2000_01_01(uint16_t year, uint8_t month, uint8_t day) |  |
| 0x13a354 | Result GetThreadId(u32* threadId, Handle thread) |  |
| 0x151148 | void * memset(void *dest, uint8_t value, size_t count) |  |
| 0x2f85e4 | void memcpy(void *dest, void *src, size_t n) |  |
| 0x2fb344 | uint32_t * GetGardenPlusSaveData(void) |  |
| 0x2fba60 | uint32_t * GetSpecificPlayerSaveData(uint8_t playerIndex) |  |
| 0x2fcb84 | bool IsItemEmpty(uint32_t *item) |  |
| 0x2feb2c | uint32_t * GetLoadedPlayerSaveData(uint8_t playerIndex) |  |
| 0x350ae8 | u8 GetCurrentCountryID(void) |  |
| 0x56C908 | uint64_t ConvertDateTimeToNanoseconds(ACNL_DateTime *dateTime) |  |
| 0x5c37b0 | float * GetPlayerCoordinates(uint8_t playerIndex, uint8_t u0) |  |
| 0x5c3ddc | uint32_t * GetLoadedPlayerRoom(uint8_t playerIndex) |  |
| 0x5c3ea0 | uint32_t * GetPlayerInstance(uint8_t playerIndex, uint8_t u0) |  |
| 0x77a51c | void malloc(size_t size) |  |
|  |  |

```cpp
struct ACNL_DateTime {
  u16 Year;
  u16 Unk0; //Maybe padding
  u8 Month;
  u8 Day;
  u8 Unk1; //some sort of flag probably
  u8 Hour;
  u8 Minute;
  u8 Second;
  u16 Millisecond;
};

typedef u32 Handle;                 ///< Resource handle.
typedef s32 Result;                 ///< Function result.
```
