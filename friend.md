# friendX.dat research

- Every player has their own friendX.dat, therefore there exist 4 different ones. Each are numbered (friend1.dat for the first player as an example).
- Each friends data is 0x14B0 bytes long.
- If PID/TID is missing, friend will not appear in the list.
- The friendX.dat files are never loaded all at the same time in the game, only the one for the current loaded player.
- Added friends seem to have a version in which version of ACNL they were added. If the version is not the newest (3) the Dream Address will be replaced with X's.

## Data Structure
| Offset    | Description                    | Size (in bytes)       |
| --------- | ------------------------------ | --------------------- |
| 0x0       | Save Checksum                  | 4                     |
| 0x8       | Has TPC Picture                | 0.5 (bool)            |
| 0x8       | Has TPC Picture                | 0.5 (bool)            |
| 0xC       | TPC Data (.jpeg)               | 0x1400                | 
|           |                                |                       | 
| 0x1418    | Sixth Byte for Dream Address   | 1                     | 
| 0x1419    | Fifth Byte for Dream Address   | 1                     | 
| 0x141A    | Fourth Byte for Dream Address  | 1                     | 
| 0x141B    | Third Byte for Dream Address   | 1                     | 
| 0x141C    | Second Byte for Dream Address  | 1                     | 
| 0x1420    | Has Dream Address              | 0.5 (bool)            | 
| 0x1421    | First Byte for Dream Address   | 1                     | 
|           |                                |                       | 
| 0x1428    | Player ID                      | 2                     | 
| 0x142A    | Player Name (UTF16 Encoding)   | 0x10 (8 Characters)   | 
| 0x143C    | Player Gender                  | 0.5 (bool)            | 
|           |                                |                       | 
| 0x143E    | Town ID                        | 2                     | 
| 0x1440    | Town Name (UTF16 Encoding)     | 0x10 (8 Characters)   | 
|           |                                |                       | 
| 0x1454    | Country ID                     | 1                     | 
| 0x1455    | Country Region ID              | 1                     | 
|           |                                |                       | 
| 0x1456    | Badge Fishes                   | 1                     | 
| 0x1457    | Badge Bugs                     | 1                     | 
| 0x1458    | Badge Marine                   | 1                     | 
| 0x1459    | Badge FishColl                 | 1                     | 
| 0x145A    | Badge BugColl                  | 1                     | 
| 0x145B    | Badge MarineColl               | 1                     | 
| 0x145C    | Badge Balloons                 | 1                     | 
| 0x145D    | Badge Visiting                 | 1                     | 
| 0x145E    | Badge Hosting                  | 1                     | 
| 0x145F    | Badge Gardening                | 1                     | 
| 0x1460    | Badge Bank                     | 1                     | 
| 0x1461    | Badge Turnips                  | 1                     | 
| 0x1462    | Badge Medals                   | 1                     | 
| 0x1463    | Badge Streetpass               | 1                     | 
| 0x1464    | Badge Weeding                  | 1                     | 
| 0x1465    | Badge Shopping                 | 1                     | 
| 0x1466    | Badge LetterWriter             | 1                     | 
| 0x1467    | Badge Refurbish                | 1                     | 
| 0x1468    | Badge Catalog                  | 1                     | 
| 0x1469    | Badge KK                       | 1                     | 
| 0x146A    | Badge HHAScore                 | 1                     | 
| 0x146B    | Badge PlayTime                 | 1                     |
| 0x146C    | Badge Helper                   | 1                     | 
| 0x146D    | Badge Dream                    | 1                     | 
|           |                                |                       | 
| 0x146E    | Birthday Month                 | 1                     | 
| 0x146F    | Birthday Day                   | 1                     | 
|           |                                |                       | 
| 0x1470    | Registered Year                | 2                     | 
| 0x1472    | Registered Month               | 1                     | 
| 0x1473    | Registered Day                 | 1                     | 
|           |                                |                       | 
| 0x1474    | TPC Comment (UTF16 Encoding)   | 0x40 (32 Characters)  | 
| 0x14B6    | Version Check(?) 3 is WA       | 1                     | 
