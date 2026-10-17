# Batch log

The builder appends one line after every function. A quiet log means the run is stuck. A line every few seconds means it is moving.

Rows dated before 2026-10-14T16:00:00Z have a hand-entered seconds column. Later rows come from `scripts/batch_log.py`, which records wall-clock from `start` to `finish`. A `BATCH` row carries the measured reseed and score times for that batch.

`status` is `matched`, `hard-tail`, or `skipped`. `attempts` counts compile attempts, maximum 6. `seconds` is wall-clock for that function.

| utc | function | bytes | status | attempts | seconds |
| --- | --- | --- | --- | --- | --- |
| 2026-10-14T10:53:05Z | func_001746B0 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_001754B0 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_00179C60 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_0017A9E0 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_0017D2E0 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_001824E8 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_00187658 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_0018BFA0 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_0018CDA8 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_0018DB60 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_0018E918 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_001900C8 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_00199CC8 | 144 | matched | 6 | 4 |
| 2026-10-14T10:53:05Z | func_0019FDB0 | 144 | matched | 6 | 4 |
| 2026-10-14T11:20:00Z | func_0018EAF8 | 300 | hard-tail | 3 | 20 |
| 2026-10-14T11:20:00Z | func_00191B98 | 300 | hard-tail | 3 | 20 |
| 2026-10-14T11:20:00Z | func_00192A98 | 300 | hard-tail | 3 | 20 |
| 2026-10-14T11:20:00Z | func_00193050 | 300 | hard-tail | 3 | 20 |
| 2026-10-14T11:20:00Z | func_00193A80 | 300 | hard-tail | 3 | 20 |
| 2026-10-14T11:20:00Z | func_00193D08 | 300 | hard-tail | 3 | 20 |
| 2026-10-14T11:20:00Z | func_0019DAA8 | 300 | hard-tail | 3 | 20 |
| 2026-10-14T11:20:00Z | func_0019E2A8 | 300 | hard-tail | 3 | 20 |
| 2026-10-14T11:19:07Z | func_00312F70 | 192 | matched | 5 | 8 |
| 2026-10-14T11:19:07Z | func_00313150 | 192 | matched | 5 | 8 |
| 2026-10-14T11:19:07Z | func_00313210 | 192 | matched | 5 | 8 |
| 2026-10-14T11:19:07Z | func_003132D0 | 192 | matched | 5 | 8 |
| 2026-10-14T11:19:07Z | func_00313390 | 192 | matched | 5 | 8 |
| 2026-10-14T11:19:07Z | func_00313450 | 192 | matched | 5 | 8 |
| 2026-10-14T12:10:00Z | func_001932D8 | 288 | hard-tail | 1 | 8 |
| 2026-10-14T12:10:00Z | func_0019BF10 | 288 | hard-tail | 1 | 8 |
| 2026-10-14T12:10:00Z | func_0019E7A8 | 288 | hard-tail | 1 | 8 |
| 2026-10-14T12:10:00Z | func_0019EF18 | 288 | hard-tail | 1 | 8 |
| 2026-10-14T12:20:00Z | func_002ABCE8 | 68 | hard-tail | 1 | 8 |
| 2026-10-14T12:20:00Z | func_002ABD30 | 68 | hard-tail | 1 | 8 |
| 2026-10-14T12:20:00Z | func_002ABD78 | 68 | hard-tail | 1 | 8 |
| 2026-10-14T11:39:46Z | func_00171A08 | 100 | matched | 1 | 9 |
| 2026-10-14T11:39:46Z | func_0017C3A0 | 100 | matched | 1 | 9 |
| 2026-10-14T11:39:46Z | func_00183240 | 100 | matched | 1 | 9 |
| 2026-10-14T11:48:12Z | func_001E3DD0 | 112 | matched | 1 | 8 |
| 2026-10-14T11:48:12Z | func_001E6DA0 | 112 | matched | 1 | 8 |
| 2026-10-14T11:48:12Z | func_001E6E68 | 112 | matched | 1 | 8 |
| 2026-10-14T11:59:00Z | func_003258B8 | 204 | hard-tail | 1 | 75 |
| 2026-10-14T11:59:00Z | func_00325988 | 204 | hard-tail | 1 | 75 |
| 2026-10-14T11:59:00Z | func_00325B90 | 204 | hard-tail | 1 | 75 |
| 2026-10-14T12:08:50Z | func_001FC988 | 176 | matched | 2 | 12 |
| 2026-10-14T12:08:50Z | func_001FCA38 | 176 | matched | 2 | 12 |
| 2026-10-14T12:08:50Z | func_001FCAE8 | 176 | matched | 2 | 12 |
| 2026-10-14T12:18:04Z | func_001B0290 | 56 | matched | 1 | 8 |
| 2026-10-14T12:18:04Z | func_001B24E8 | 56 | matched | 1 | 8 |
| 2026-10-14T12:35:09Z | func_00373F38 | 60 | matched | 1 | 8 |
| 2026-10-14T12:35:09Z | func_00374508 | 60 | matched | 1 | 8 |
| 2026-10-14T12:43:13Z | func_002AE740 | 68 | matched | 1 | 9 |
| 2026-10-14T12:43:13Z | func_002AE7F0 | 68 | matched | 1 | 9 |
| 2026-10-14T12:51:07Z | func_0035FFB0 | 40 | matched | 1 | 8 |
| 2026-10-14T12:51:07Z | func_0036CB98 | 40 | matched | 1 | 8 |
| 2026-10-14T12:57:58Z | func_0036CC08 | 56 | matched | 1 | 8 |
| 2026-10-14T12:57:58Z | func_0036CC40 | 56 | matched | 1 | 8 |
| 2026-10-14T13:10:00Z | func_00382850 | 68 | hard-tail | 6 | 40 |
| 2026-10-14T13:10:00Z | func_00383280 | 68 | hard-tail | 6 | 40 |
| 2026-10-14T13:24:00Z | func_003827F0 | 92 | matched | 3 | 11 |
| 2026-10-14T13:24:00Z | func_00384138 | 92 | matched | 3 | 11 |
| 2026-10-14T13:40:00Z | func_001551E0 | 100 | hard-tail | 6 | 120 |
| 2026-10-14T13:40:00Z | func_001552F0 | 100 | hard-tail | 6 | 120 |
| 2026-10-14T13:44:52Z | func_00149488 | 112 | matched | 1 | 8 |
| 2026-10-14T13:44:52Z | func_00150538 | 112 | matched | 1 | 8 |
| 2026-10-14T13:53:32Z | func_00380F10 | 112 | matched | 1 | 8 |
| 2026-10-14T13:53:32Z | func_00381DC0 | 112 | matched | 1 | 8 |
| 2026-10-14T14:05:26Z | func_00376EA0 | 120 | matched | 2 | 12 |
| 2026-10-14T14:05:26Z | func_0037BE98 | 120 | matched | 2 | 12 |
| 2026-10-14T14:19:10Z | func_001C2B80 | 124 | matched | 2 | 10 |
| 2026-10-14T14:19:10Z | func_001C2CE0 | 124 | matched | 2 | 10 |
| 2026-10-14T15:44:53Z | func_003A9620 | 156 | matched | 1 | 41.4 |
| 2026-10-14T15:50:40Z | func_001169D8 | 172 | hard-tail | 6 | 261.9 |
| 2026-10-14T15:50:40Z | func_001DF890 | 172 | hard-tail | 5 | 261.9 |
| 2026-10-14T15:54:17Z | __do_global_ctors | 176 | hard-tail | 3 | 66.4 |
| 2026-10-14T15:57:01Z | __sjthrow | 728 | hard-tail | 1 | 0.0 |
| 2026-10-14T15:57:01Z | __class_type_info_dcast | 472 | hard-tail | 1 | 0.0 |
| 2026-10-14T15:57:01Z | func_00359080 | 228 | hard-tail | 2 | 87.0 |
| 2026-10-14T15:57:47Z | ESLib_ESCatMullRom | 300 | hard-tail | 2 | 133.0 |
| 2026-10-14T15:59:10Z | func_003363F8 | 156 | hard-tail | 3 | 78.5 |
| 2026-10-14T16:00:47Z | func_00300E30 | 196 | matched | 3 | 91.8 |
| 2026-10-14T16:03:12Z | func_00349480 | 248 | hard-tail | 2 | 72.0 |
| 2026-10-14T16:03:41Z | func_002B1F80 | 212 | hard-tail | 1 | 20.1 |
| 2026-10-14T16:05:09Z | func_003BB058 | 272 | hard-tail | 2 | 50.8 |
| 2026-10-14T16:07:02Z | func_003BA708 | 244 | hard-tail | 2 | 79.0 |
| 2026-10-14T16:08:28Z | func_00343C18 | 332 | hard-tail | 2 | 77.1 |
| 2026-10-14T16:09:45Z | func_00331900 | 460 | hard-tail | 1 | 37.0 |
| 2026-10-14T16:10:30Z | func_003BA148 | 548 | hard-tail | 2 | 18.2 |
| 2026-10-14T16:12:21Z | func_00357AA0 | 380 | hard-tail | 3 | 81.1 |
| 2026-10-14T16:14:53Z | func_00100CE0 | 504 | hard-tail | 1 | 63.2 |
| 2026-10-14T16:15:17Z | func_002495E0 | 396 | hard-tail | 1 | 23.5 |
| 2026-10-14T16:15:28Z | func_003BA5A0 | 284 | hard-tail | 1 | 11.1 |
| 2026-10-14T16:16:44Z | func_003ACE90 | 556 | hard-tail | 1 | 15.2 |
| 2026-10-14T16:17:42Z | func_00165EB8 | 740 | hard-tail | 1 | 26.4 |
| 2026-10-14T16:18:27Z | func_0036EC78 | 536 | hard-tail | 1 | 45.2 |
| 2026-10-14T16:18:49Z | func_00337DE0 | 976 | hard-tail | 1 | 22.3 |
| 2026-10-14T16:19:17Z | func_001F6758 | 708 | hard-tail | 1 | 28.1 |
| 2026-10-14T16:19:53Z | func_00100530 | 828 | hard-tail | 2 | 35.4 |
| 2026-10-14T16:20:01Z | func_002BC470 | 592 | hard-tail | 1 | 8.2 |
| 2026-10-14T16:20:19Z | func_00353928 | 684 | hard-tail | 1 | 17.7 |
| 2026-10-14T16:21:14Z | func_0019ECA0 | 288 | hard-tail | 1 | 59.9 |
| 2026-10-14T16:23:16Z | BATCH | - | batch | - | reseed 44.0; score 45.9 |
| 2026-10-14T16:25:01Z | func_003ACE90 | 556 | hard-tail | 2 | 30.2 |
| 2026-10-14T17:28:55Z | func_00149400 | 136 | matched | 1 | 20.4 |
| 2026-10-14T17:28:55Z | func_001504B0 | 136 | matched | 1 | 0.0 |
| 2026-10-14T17:31:13Z | func_0018F110 | 140 | matched | 2 | 55.3 |
| 2026-10-14T17:42:06Z | func_001A5100 | 0 | matched | 2 | 653.6 |
| 2026-10-14T17:42:07Z | func_001A5100 | 140 | matched | 2 | 0.0 |
| 2026-10-14T17:42:07Z | func_001B2708 | 156 | matched | 2 | 0.1 |
| 2026-10-14T17:42:07Z | func_001C9A50 | 156 | matched | 2 | 0.0 |
| 2026-10-14T17:42:07Z | func_002F6258 | 156 | matched | 2 | 0.0 |
| 2026-10-14T17:42:07Z | func_002F71A0 | 156 | matched | 2 | 0.0 |
| 2026-10-14T17:42:07Z | func_00383EB0 | 160 | matched | 2 | 0.0 |
| 2026-10-14T17:42:07Z | func_00385410 | 160 | matched | 2 | 0.0 |
| 2026-10-14T17:42:07Z | func_001E3928 | 168 | matched | 2 | 0.0 |
| 2026-10-14T17:42:07Z | func_001E3A98 | 168 | matched | 2 | 0.0 |
| 2026-10-14T17:42:07Z | func_002E3500 | 188 | matched | 2 | 0.0 |
| 2026-10-14T17:42:07Z | func_002EBC50 | 188 | matched | 2 | 0.0 |
| 2026-10-14T17:46:14Z | BATCH | - | batch | - | reseed 59.0; score 22.0 |
| 2026-10-14T18:05:00Z | func_001E39D0 | 196 | matched | 1 | 0.0 |
| 2026-10-14T18:05:00Z | func_001E3CB0 | 196 | matched | 1 | 0.0 |
| 2026-10-14T18:05:00Z | func_001DE428 | 204 | matched | 1 | 0.0 |
| 2026-10-14T18:05:00Z | func_001DF358 | 204 | matched | 1 | 0.0 |
| 2026-10-14T18:05:01Z | func_001BC538 | 212 | matched | 2 | 0.0 |
| 2026-10-14T18:05:01Z | func_001BC610 | 212 | matched | 2 | 0.0 |
| 2026-10-14T18:05:01Z | func_0017D488 | 212 | matched | 3 | 0.0 |
| 2026-10-14T18:05:01Z | func_001A8200 | 212 | matched | 3 | 0.0 |
| 2026-10-14T18:05:01Z | func_001D4720 | 200 | hard-tail | 6 | 0.0 |
| 2026-10-14T18:05:01Z | func_001D47E8 | 200 | hard-tail | 6 | 0.1 |
| 2026-10-14T18:06:40Z | BATCH | - | batch | - | reseed 56.0; score 26.0 |
| 2026-10-14T18:07:45Z | func_00359080 | 228 | matched | 1 | 36.9 |
| 2026-10-14T18:11:43Z | BATCH | - | batch | - | reseed 41.0; score 26.0 |
| 2026-10-14T18:11:59Z | func_00359080 | 228 | matched | 1 | 0.0 |
| 2026-10-14T18:26:48Z | func_001D5F50 | 220 | matched | 1 | 0.0 |
| 2026-10-14T18:26:48Z | func_001DF278 | 220 | matched | 1 | 0.1 |
| 2026-10-14T18:26:48Z | func_00279678 | 216 | matched | 1 | 0.0 |
| 2026-10-14T18:26:48Z | func_00280A10 | 216 | matched | 1 | 0.0 |
| 2026-10-14T18:26:48Z | func_001C8E50 | 216 | matched | 1 | 0.0 |
| 2026-10-14T18:26:48Z | func_001D0B38 | 216 | matched | 1 | 0.0 |
| 2026-10-14T18:26:48Z | func_00374CB8 | 220 | hard-tail | 6 | 0.0 |
| 2026-10-14T18:26:48Z | func_00375AB0 | 220 | hard-tail | 6 | 0.0 |
| 2026-10-14T18:26:48Z | func_00170050 | 224 | hard-tail | 6 | 0.0 |
| 2026-10-14T18:26:49Z | func_00170338 | 224 | hard-tail | 6 | 0.0 |
| 2026-10-14T18:31:01Z | BATCH | - | batch | - | reseed 62.0; score 32.0 |
| 2026-10-14T18:40:11Z | func_001855A8 | 232 | matched | 1 | 0.0 |
| 2026-10-14T18:40:11Z | func_00185F50 | 232 | matched | 1 | 0.0 |
| 2026-10-14T18:40:11Z | func_002E2C50 | 236 | matched | 1 | 0.0 |
| 2026-10-14T18:40:11Z | func_002E6EE8 | 236 | matched | 1 | 0.0 |
| 2026-10-14T18:40:12Z | KillEventEmitter | 244 | matched | 1 | 0.0 |
| 2026-10-14T18:40:12Z | KillEventEsp | 244 | matched | 1 | 0.0 |
| 2026-10-14T18:40:12Z | func_00166638 | 248 | matched | 1 | 0.0 |
| 2026-10-14T18:40:12Z | func_001673D0 | 248 | matched | 1 | 0.0 |
| 2026-10-14T18:40:12Z | func_002FB898 | 252 | matched | 1 | 0.0 |
| 2026-10-14T18:40:12Z | func_00300D20 | 252 | matched | 1 | 0.0 |
| 2026-10-14T18:44:26Z | BATCH | - | batch | - | reseed 188.0; score 30.0 |
| 2026-10-14T19:15:52Z | func_00317D50 | 300 | matched | 4 | 130.9 |
| 2026-10-14T19:15:53Z | func_003181A8 | 300 | matched | 1 | 1.0 |
| 2026-10-14T19:19:33Z | func_00195850 | 304 | hard-tail | 6 | 220.0 |
| 2026-10-14T19:19:34Z | func_001AA058 | 304 | hard-tail | 6 | 0.3 |
| 2026-10-14T19:22:02Z | func_0017E8D8 | 332 | hard-tail | 4 | 148.2 |
| 2026-10-14T19:22:02Z | func_0017F320 | 332 | hard-tail | 4 | 0.4 |
| 2026-10-14T19:22:49Z | func_0018EF58 | 324 | hard-tail | 1 | 46.5 |
| 2026-10-14T19:22:49Z | func_0019C3D0 | 324 | hard-tail | 1 | 0.3 |
| 2026-10-14T19:24:08Z | func_0030A538 | 16 | matched | 1 | 48.6 |
| 2026-10-14T19:24:09Z | func_003A7B48 | 16 | hard-tail | 1 | 0.4 |
| 2026-10-14T19:27:03Z | func_0031A320 | 24 | hard-tail | 5 | 173.8 |
| 2026-10-14T19:27:04Z | func_0031A300 | 28 | hard-tail | 5 | 1.1 |
| 2026-10-14T19:27:04Z | func_0030A548 | 40 | matched | 1 | 0.4 |
| 2026-10-14T19:27:05Z | func_0037E8D8 | 44 | matched | 1 | 0.5 |
| 2026-10-14T19:30:51Z | BATCH | - | batch | - | reseed 124.0; score 34.0 |
| 2026-10-14T19:35:28Z | func_001B8030 | 32 | hard-tail | 6 | 94.1 |
| 2026-10-14T19:36:17Z | func_00307118 | 36 | hard-tail | 6 | 48.9 |
| 2026-10-14T19:37:26Z | cSceAtUnit_AreaSet | 40 | hard-tail | 6 | 68.9 |
| 2026-10-14T19:38:17Z | func_00123908 | 48 | hard-tail | 6 | 50.8 |
| 2026-10-14T19:39:14Z | func_001346C8 | 48 | hard-tail | 6 | 56.9 |
| 2026-10-14T19:40:20Z | func_0027DB20 | 48 | hard-tail | 6 | 66.5 |
| 2026-10-14T19:40:32Z | func_0037B768 | 48 | matched | 1 | 12.3 |
| 2026-10-14T19:40:34Z | func_0012C708 | 60 | matched | 1 | 1.1 |
| 2026-10-14T19:40:35Z | func_001451A0 | 60 | matched | 1 | 1.0 |
| 2026-10-14T19:41:33Z | func_0030F518 | 52 | hard-tail | 6 | 58.7 |
| 2026-10-14T19:42:26Z | func_003077B0 | 52 | hard-tail | 6 | 52.8 |
| 2026-10-14T19:42:31Z | func_00307840 | 52 | hard-tail | 6 | 5.1 |
| 2026-10-14T19:43:02Z | batch27_verify_matches | 0 | matched | 1 | 1.0 |
| 2026-10-14T19:46:04Z | BATCH | - | batch | - | reseed 125.0; score 34.0 |
| 2026-10-14T19:48:51Z | func_001BF478 | 60 | matched | 1 | 4.9 |
| 2026-10-14T19:49:29Z | func_002BDB78 | 68 | matched | 1 | 1.5 |
| 2026-10-14T19:52:13Z | batch28_verify | 0 | matched | 1 | 1.4 |
| 2026-10-14T19:52:18Z | func_001BF478 | 60 | matched | 1 | 1.4 |
| 2026-10-14T19:52:19Z | func_00306A08 | 64 | matched | 4 | 1.4 |
| 2026-10-14T19:52:21Z | func_002BDB78 | 68 | matched | 1 | 1.2 |
| 2026-10-14T19:52:22Z | func_0037D298 | 60 | hard-tail | 6 | 1.2 |
| 2026-10-14T19:52:23Z | func_00201250 | 64 | hard-tail | 6 | 1.3 |
| 2026-10-14T19:52:25Z | func_002B4F38 | 64 | hard-tail | 6 | 1.2 |
| 2026-10-14T19:52:26Z | func_0031D2B8 | 64 | hard-tail | 6 | 1.4 |
| 2026-10-14T19:52:27Z | func_00156508 | 68 | hard-tail | 6 | 1.2 |
| 2026-10-14T19:52:29Z | func_001C2328 | 68 | hard-tail | 6 | 1.3 |
| 2026-10-14T19:52:30Z | func_002FEBE8 | 68 | hard-tail | 6 | 1.2 |
| 2026-10-14T19:52:31Z | func_0012BAF0 | 72 | hard-tail | 6 | 1.3 |
| 2026-10-14T19:52:33Z | cCoreSave_ckFightingRingClear | 72 | hard-tail | 6 | 1.2 |
| 2026-10-14T19:57:54Z | func_0030A2E0 | 72 | hard-tail | 6 | 2.6 |
| 2026-10-14T19:57:57Z | func_002736F8 | 76 | hard-tail | 6 | 2.3 |
| 2026-10-14T19:57:59Z | func_002BDF30 | 76 | hard-tail | 6 | 2.7 |
| 2026-10-14T19:58:02Z | func_002C5338 | 76 | hard-tail | 6 | 2.6 |
| 2026-10-14T19:58:04Z | func_001522C0 | 80 | hard-tail | 6 | 2.4 |
| 2026-10-14T19:58:07Z | func_00156550 | 80 | hard-tail | 6 | 2.3 |
| 2026-10-14T19:58:09Z | func_001DF7D0 | 80 | hard-tail | 6 | 2.4 |
| 2026-10-14T19:58:12Z | func_001EA1A8 | 80 | hard-tail | 6 | 2.3 |
| 2026-10-14T19:58:14Z | func_0030FB20 | 80 | hard-tail | 6 | 2.4 |
| 2026-10-14T19:58:16Z | func_00376A90 | 80 | hard-tail | 6 | 2.3 |
| 2026-10-14T19:58:19Z | RoundFloat | 84 | hard-tail | 6 | 2.5 |
| 2026-10-14T19:58:22Z | Adjust_theta | 84 | hard-tail | 6 | 2.5 |
| 2026-10-14T20:02:01Z | func_002C1270 | 84 | matched | 1 | 1.2 |
| 2026-10-14T20:02:02Z | Adjust_theta_vec | 84 | hard-tail | 6 | 1.1 |
| 2026-10-14T20:02:04Z | func_002A4BA0 | 84 | hard-tail | 6 | 1.3 |
| 2026-10-14T20:02:05Z | func_002BEAA8 | 84 | hard-tail | 6 | 1.2 |
| 2026-10-14T20:02:06Z | func_002BECB0 | 84 | hard-tail | 6 | 1.2 |
| 2026-10-14T20:02:08Z | func_001CD7A8 | 88 | hard-tail | 6 | 1.4 |
| 2026-10-14T20:02:09Z | func_001E7368 | 88 | hard-tail | 6 | 1.2 |
| 2026-10-14T20:02:10Z | func_002BF420 | 88 | hard-tail | 6 | 1.1 |
| 2026-10-14T20:02:11Z | func_002D5AD8 | 88 | hard-tail | 6 | 1.2 |
| 2026-10-14T20:02:12Z | func_003077E8 | 88 | hard-tail | 6 | 1.2 |
| 2026-10-14T20:02:14Z | func_00377FA0 | 88 | hard-tail | 6 | 1.4 |
| 2026-10-14T20:02:15Z | func_0037C330 | 88 | hard-tail | 6 | 1.2 |
| 2026-10-14T20:05:41Z | func_001C0068 | 96 | matched | 1 | 16.1 |
| 2026-10-14T20:08:13Z | BATCH | - | batch | - | reseed 257.0; score 49.0 |
| 2026-10-14T20:09:35Z | func_001C0068 | 96 | matched | 2 | 1.5 |
| 2026-10-14T20:09:37Z | func_003182D8 | 96 | matched | 4 | 1.5 |
| 2026-10-14T20:09:38Z | func_001E7368 | 88 | matched | 6 | 1.3 |
| 2026-10-14T20:09:40Z | func_002BF420 | 88 | matched | 5 | 1.3 |
| 2026-10-14T20:09:41Z | func_001D6A70 | 336 | hard-tail | 6 | 1.4 |
| 2026-10-14T20:09:42Z | func_001E7660 | 336 | hard-tail | 6 | 1.4 |
| 2026-10-14T20:09:44Z | func_002D51F0 | 96 | hard-tail | 6 | 1.2 |
| 2026-10-14T20:09:45Z | func_002D56A8 | 96 | hard-tail | 6 | 1.4 |
| 2026-10-14T20:09:47Z | func_0017FC58 | 92 | hard-tail | 6 | 1.5 |
| 2026-10-14T20:09:48Z | func_00289728 | 96 | hard-tail | 6 | 1.5 |
| 2026-10-14T20:09:50Z | func_00394D00 | 88 | hard-tail | 6 | 1.3 |
| 2026-10-14T20:09:51Z | func_002C5338 | 76 | hard-tail | 6 | 1.3 |
| 2026-10-14T20:11:35Z | BATCH | - | batch | - | reseed 349.0; score 46.0 |
| 2026-10-14T20:12:19Z | func_00284A28 | 100 | matched | 1 | 1.4 |
| 2026-10-14T20:12:20Z | func_0013E908 | 100 | matched | 4 | 1.2 |
| 2026-10-14T20:12:22Z | func_002831C8 | 116 | hard-tail | 6 | 1.3 |
| 2026-10-14T20:12:23Z | func_0015FCB8 | 96 | hard-tail | 6 | 1.2 |
| 2026-10-14T20:13:28Z | func_00289728 | 96 | matched | 1 | 1.3 |
| 2026-10-14T20:13:29Z | func_00281638 | 84 | matched | 1 | 1.2 |
| 2026-10-14T20:13:30Z | func_00377530 | 104 | hard-tail | 6 | 1.3 |
| 2026-10-14T20:15:16Z | BATCH | - | batch | - | reseed 2.0; score 49.0 |
| 2026-10-14T20:19:16Z | BATCH | - | batch | - | reseed 184.0; score 47.0 |
| 2026-10-14T20:27:52Z | BATCH | - | batch | - | reseed 230.0; score 48.0 |
| 2026-10-14T20:31:31Z | func_001ED7E0 | 100 | matched | 2 | 121.0 |
| 2026-10-14T20:31:59Z | func_00305358 | 100 | matched | 1 | 1.3 |
| 2026-10-14T20:32:08Z | func_0017EC98 | 100 | matched | 3 | 4.0 |
| 2026-10-14T20:33:42Z | func_00375318 | 100 | matched | 6 | 76.8 |
| 2026-10-14T20:34:56Z | func_002AE838 | 100 | matched | 1 | 11.5 |
| 2026-10-14T20:36:28Z | func_002A4E58 | 100 | hard-tail | 4 | 66.4 |
| 2026-10-14T20:36:29Z | func_00140BF0 | 104 | hard-tail | 4 | 0.6 |
| 2026-10-14T20:37:38Z | func_001DBEB0 | 100 | hard-tail | 3 | 55.6 |
| 2026-10-14T20:37:39Z | func_001F5E90 | 100 | hard-tail | 3 | 0.5 |
| 2026-10-14T20:37:40Z | func_00200B20 | 100 | hard-tail | 2 | 0.5 |
| 2026-10-14T20:37:55Z | func_001B8140 | 104 | matched | 1 | 5.9 |
| 2026-10-14T20:38:39Z | func_001ECFE8 | 104 | hard-tail | 4 | 43.7 |
| 2026-10-14T20:45:10Z | BATCH | - | batch | - | reseed 299.0; score 55.0 |
| 2026-10-14T20:54:42Z | func_002B3190 | 104 | hard-tail | 1 | 8.5 |
| 2026-10-14T20:54:45Z | func_0037CC78 | 104 | matched | 1 | 2.3 |
| 2026-10-14T20:56:39Z | func_001B1A80 | 104 | hard-tail | 2 | 63.1 |
| 2026-10-14T20:59:06Z | func_0037CC78 | 104 | matched | 1 | 1.6 |
| 2026-10-14T20:59:08Z | func_002B4188 | 104 | matched | 1 | 1.9 |
| 2026-10-14T20:59:10Z | func_003A9538 | 108 | matched | 1 | 1.7 |
| 2026-10-14T20:59:12Z | func_001E4438 | 112 | matched | 1 | 1.7 |
| 2026-10-14T20:59:13Z | func_002B3190 | 104 | hard-tail | 6 | 1.5 |
| 2026-10-14T20:59:15Z | func_001B1A80 | 104 | hard-tail | 6 | 1.7 |
| 2026-10-14T20:59:17Z | func_002D4248 | 104 | hard-tail | 6 | 1.8 |
| 2026-10-14T20:59:19Z | func_00383DD0 | 108 | hard-tail | 4 | 1.7 |
| 2026-10-14T21:06:26Z | func_001F2CF0 | 112 | matched | 1 | 7.1 |
| 2026-10-14T21:06:55Z | func_001E44A8 | 116 | matched | 1 | 1.6 |
| 2026-10-14T21:07:49Z | func_002CB208 | 112 | matched | 1 | 16.8 |
| 2026-10-14T21:08:16Z | func_0013F150 | 112 | matched | 2 | 1.7 |
| 2026-10-14T21:08:17Z | func_002B46F0 | 112 | matched | 3 | 1.4 |
| 2026-10-14T21:08:17Z | func_002BEB00 | 112 | hard-tail | 6 | 0.0 |
| 2026-10-14T21:08:17Z | func_002B2C98 | 112 | hard-tail | 6 | 0.0 |
| 2026-10-14T21:09:08Z | func_00143B70 | 116 | matched | 1 | 22.3 |
| 2026-10-14T21:09:08Z | func_001496C0 | 116 | matched | 1 | 0.6 |
| 2026-10-14T21:09:09Z | func_00312E88 | 116 | matched | 1 | 0.5 |
| 2026-10-14T21:09:09Z | func_002B43B0 | 116 | matched | 1 | 0.5 |
| 2026-10-14T21:09:27Z | func_00377688 | 116 | hard-tail | 6 | 17.2 |
| 2026-10-14T21:09:28Z | func_00143B70 | 116 | matched | 1 | 1.6 |
| 2026-10-14T21:10:13Z | JukeBox_Release | 120 | hard-tail | 1 | 24.6 |
| 2026-10-14T21:10:13Z | func_0019C050 | 120 | matched | 1 | 0.5 |
| 2026-10-14T21:10:14Z | func_002A4C38 | 120 | matched | 1 | 0.5 |
| 2026-10-14T21:10:14Z | func_002AEF10 | 120 | matched | 1 | 0.5 |
| 2026-10-14T21:10:59Z | JukeBox_Release | 120 | hard-tail | 6 | 44.3 |
| 2026-10-14T21:11:03Z | func_0019C050 | 120 | matched | 1 | 4.4 |
| 2026-10-14T21:12:20Z | BATCH | - | batch | - | reseed 447.0; score 32.0 |
| 2026-10-14T21:14:02Z | BATCH | - | batch | - | reseed 64.0; score 28.0 |
| 2026-10-14T21:15:06Z | Quaternion_SetRotationAxis | 120 | matched | 1 | 48.4 |
| 2026-10-14T21:15:07Z | func_001A4218 | 120 | matched | 1 | 0.3 |
| 2026-10-14T21:15:07Z | func_001E6B70 | 120 | matched | 1 | 0.3 |
| 2026-10-14T21:15:07Z | func_0013C298 | 124 | matched | 1 | 0.3 |
| 2026-10-14T21:15:08Z | func_002BF708 | 120 | matched | 1 | 0.3 |
| 2026-10-14T21:17:31Z | func_0028EA38 | 120 | matched | 2 | 136.7 |
| 2026-10-14T21:17:32Z | func_0028EA38 | 120 | matched | 2 | 0.9 |
| 2026-10-14T21:17:36Z | func_001B81A8 | 124 | hard-tail | 6 | 3.6 |
| 2026-10-14T21:18:31Z | func_00133AA8 | 128 | hard-tail | 1 | 12.4 |
| 2026-10-14T21:19:47Z | func_0013BCC0 | 128 | matched | 2 | 62.3 |
| 2026-10-14T21:19:47Z | func_001C6C30 | 136 | matched | 1 | 0.3 |
| 2026-10-14T21:19:47Z | func_001C2630 | 136 | matched | 1 | 0.3 |
| 2026-10-14T21:19:48Z | func_00166540 | 136 | matched | 1 | 0.3 |
| 2026-10-14T21:19:53Z | func_00133AA8 | 128 | hard-tail | 6 | 5.4 |
| 2026-10-14T21:19:55Z | cEmSetParam_updateSetDataPos | 128 | hard-tail | 6 | 1.8 |
| 2026-10-14T21:30:33Z | func_0013BC28 | 148 | matched | 2 | 1.1 |
| 2026-10-14T21:30:34Z | func_001E6BE8 | 148 | matched | 1 | 0.4 |
| 2026-10-14T21:30:39Z | func_001482C0 | 148 | hard-tail | 6 | 5.6 |
| 2026-10-14T21:30:42Z | func_001F7228 | 148 | hard-tail | 6 | 2.2 |
| 2026-10-14T21:30:42Z | BATCH | - | batch | - | reseed 0.0; score 0.0 |
| 2026-10-14T21:35:13Z | func_002983D0 | 144 | matched | 2 | 121.8 |
| 2026-10-14T21:35:13Z | func_0013DF70 | 156 | hard-tail | 5 | 121.8 |
| 2026-10-14T21:35:13Z | func_001B19E0 | 160 | hard-tail | 1 | 121.8 |
| 2026-10-14T21:35:14Z | func_00139910 | 144 | hard-tail | 1 | 121.8 |
| 2026-10-14T21:35:14Z | BATCH | - | batch | - | reseed 0.0; score 0.0 |
| 2026-10-14T21:48:01Z | BATCH | - | batch | - | reseed 90.0; score 30.0 |
| 2026-10-14T21:59:30Z | func_00273F98 | 124 | matched | 2 | 257.6 |
| 2026-10-14T21:59:30Z | func_003870E0 | 124 | matched | 1 | 69.3 |
| 2026-10-14T21:59:31Z | func_002949E8 | 124 | hard-tail | 6 | 257.7 |
| 2026-10-14T21:59:31Z | func_001641B8 | 124 | hard-tail | 6 | 257.7 |
| 2026-10-14T21:59:31Z | Motion_seq_readEffectData | 124 | hard-tail | 5 | 257.7 |
| 2026-10-14T21:59:31Z | func_00306030 | 124 | hard-tail | 2 | 257.7 |
| 2026-10-14T22:01:11Z | func_0037C228 | 128 | matched | 1 | 89.0 |
| 2026-10-14T22:01:11Z | arrayAlloc | 132 | matched | 2 | 89.0 |
| 2026-10-14T22:01:11Z | func_00305858 | 128 | hard-tail | 4 | 89.0 |
| 2026-10-14T22:01:11Z | MoveEffect | 128 | hard-tail | 2 | 89.0 |
| 2026-10-14T22:01:11Z | func_002AE990 | 136 | hard-tail | 4 | 89.1 |
| 2026-10-14T22:01:11Z | func_003057D0 | 136 | hard-tail | 3 | 169.6 |
| 2026-10-14T22:01:11Z | func_00382520 | 132 | skipped | 0 | 89.1 |
| 2026-10-14T22:04:04Z | func_00273F08 | 144 | matched | 3 | 39.7 |
| 2026-10-14T22:04:04Z | func_00377CB8 | 160 | matched | 4 | 128.9 |
| 2026-10-14T22:04:04Z | func_0028E7C8 | 140 | hard-tail | 3 | 129.0 |
| 2026-10-14T22:04:04Z | func_002B2158 | 148 | hard-tail | 5 | 129.0 |
| 2026-10-14T22:04:04Z | func_002CCB58 | 160 | hard-tail | 2 | 39.8 |
| 2026-10-14T22:04:04Z | func_002FA350 | 140 | skipped | 0 | 149.1 |
| 2026-10-14T22:04:05Z | func_002FA3E0 | 140 | skipped | 0 | 149.1 |
| 2026-10-14T22:04:05Z | func_00380F80 | 140 | skipped | 0 | 149.1 |
| 2026-10-14T22:04:05Z | cGameObj | 140 | skipped | 0 | 149.1 |
| 2026-10-14T22:04:05Z | func_002B45F8 | 140 | skipped | 0 | 149.1 |
| 2026-10-14T22:04:05Z | MtxGetScaleVec | 140 | skipped | 0 | 149.1 |
| 2026-10-14T22:04:05Z | func_00384BC8 | 140 | skipped | 0 | 129.3 |
| 2026-10-14T22:04:05Z | BATCH | - | batch | - | reseed 0.0; score 0.0 |
| 2026-10-14T22:04:05Z | BATCH | - | batch | - | reseed 0.0; score 0.0 |
| 2026-10-14T22:04:05Z | BATCH | - | batch | - | reseed 0.0; score 0.0 |
| 2026-10-14T22:36:08Z | func_0031CC48 | 156 | matched | 2 | 116.3 |
| 2026-10-14T22:37:21Z | func_001508F8 | 168 | matched | 3 | 60.6 |
| 2026-10-14T22:37:21Z | func_001F4FF0 | 168 | matched | 4 | 390.8 |
| 2026-10-14T22:37:21Z | func_002AEA18 | 180 | matched | 3 | 592.2 |
| 2026-10-14T22:48:48Z | func_0020F310 | 172 | matched | 2 | 52.3 |
| 2026-10-14T22:50:50Z | func_002E1468 | 184 | matched | 4 | 122.3 |
| 2026-10-14T22:51:20Z | objScroll_Set_test | 156 | hard-tail | 6 | 1028.4 |
| 2026-10-14T22:51:20Z | func_00319CC0 | 160 | hard-tail | 6 | 765.5 |
| 2026-10-14T22:51:20Z | func_0031C438 | 164 | hard-tail | 6 | 1028.5 |
| 2026-10-14T22:51:20Z | SetEffectParts | 168 | hard-tail | 6 | 823.8 |
| 2026-10-14T22:51:20Z | cIDParam_initialize | 192 | hard-tail | 6 | 272.8 |
| 2026-10-14T22:51:20Z | func_002009E8 | 168 | hard-tail | 3 | 806.9 |
| 2026-10-14T22:51:20Z | func_0031A538 | 196 | hard-tail | 3 | 615.1 |
| 2026-10-14T22:51:20Z | func_002AE3F0 | 184 | hard-tail | 3 | 615.1 |
| 2026-10-14T22:51:20Z | func_00375630 | 192 | hard-tail | 3 | 373.8 |
| 2026-10-14T22:55:58Z | BATCH | - | batch | - | reseed 180.0; score 40.0 |
| 2026-10-14T23:05:34Z | func_0037FAC8 | 164 | matched | 2 | 138.8 |
| 2026-10-14T23:05:34Z | func_001F4B98 | 168 | matched | 4 | 442.0 |
| 2026-10-14T23:05:34Z | func_0037FF98 | 172 | matched | 2 | 352.5 |
| 2026-10-14T23:05:34Z | func_0037B338 | 180 | matched | 1 | 135.4 |
| 2026-10-14T23:05:34Z | func_00144B50 | 184 | matched | 6 | 442.1 |
| 2026-10-14T23:05:34Z | func_002E8318 | 192 | matched | 1 | 110.7 |
| 2026-10-14T23:05:35Z | func_001ED3C0 | 200 | matched | 4 | 92.4 |
| 2026-10-14T23:05:35Z | VanishEffect | 164 | hard-tail | 6 | 659.1 |
| 2026-10-14T23:05:35Z | func_003757A0 | 160 | hard-tail | 6 | 659.1 |
| 2026-10-14T23:05:35Z | func_001FF3A0 | 164 | hard-tail | 4 | 659.2 |
| 2026-10-14T23:05:35Z | func_001FF180 | 180 | hard-tail | 6 | 139.2 |
| 2026-10-14T23:05:35Z | func_001ECF30 | 184 | hard-tail | 6 | 264.7 |
| 2026-10-14T23:05:35Z | cSndMemHeap_Alloc | 180 | hard-tail | 5 | 659.2 |
| 2026-10-14T23:05:35Z | func_00144FD8 | 196 | hard-tail | 6 | 111.0 |
| 2026-10-14T23:05:35Z | func_003778D8 | 188 | hard-tail | 6 | 659.2 |
| 2026-10-14T23:05:35Z | func_0037CE20 | 192 | hard-tail | 6 | 659.2 |
| 2026-10-14T23:05:35Z | func_00126918 | 200 | hard-tail | 4 | 92.9 |
| 2026-10-14T23:05:35Z | func_001A7940 | 200 | hard-tail | 3 | 398.1 |
| 2026-10-14T23:05:35Z | func_001C2C40 | 160 | hard-tail | 2 | 2946.0 |
| 2026-10-14T23:05:35Z | func_001F72C0 | 160 | hard-tail | 2 | 2547.6 |
| 2026-10-14T23:05:35Z | func_001ABBE8 | 164 | hard-tail | 2 | 2867.6 |
| 2026-10-14T23:05:35Z | func_002AD108 | 168 | hard-tail | 2 | 659.7 |
| 2026-10-14T23:05:35Z | func_003129D0 | 176 | hard-tail | 2 | 398.3 |
| 2026-10-14T23:05:35Z | func_00387270 | 184 | hard-tail | 3 | 442.8 |
| 2026-10-14T23:05:35Z | func_0014E5D0 | 188 | hard-tail | 2 | 93.2 |
| 2026-10-14T23:05:35Z | func_00306BB0 | 196 | hard-tail | 1 | 659.5 |
| 2026-10-14T23:05:35Z | func_0037FC28 | 160 | hard-tail | 1 | 353.4 |
| 2026-10-14T23:05:35Z | func_001F4530 | 168 | hard-tail | 1 | 443.0 |
| 2026-10-14T23:07:57Z | BATCH | - | batch | - | reseed 180.0; score 40.0 |
| 2026-10-14T23:24:39Z | func_0037FC28 | 160 | matched | 1 | 447.8 |
| 2026-10-14T23:24:41Z | func_00313030 | 176 | matched | 4 | 1.1 |
| 2026-10-14T23:24:41Z | func_001B1BD0 | 164 | hard-tail | 6 | 449.0 |
| 2026-10-14T23:24:41Z | func_001B0BD0 | 164 | hard-tail | 6 | 448.9 |
| 2026-10-14T23:24:41Z | func_002009E8 | 168 | hard-tail | 6 | 257.6 |
| 2026-10-14T23:24:41Z | func_001DEA50 | 184 | hard-tail | 1 | 175.4 |
| 2026-10-14T23:24:41Z | func_001FCD00 | 180 | hard-tail | 3 | 175.4 |
| 2026-10-14T23:25:11Z | func_00313030 | 176 | matched | 4 | 1.0 |
| 2026-10-14T23:25:22Z | func_001B5430 | 180 | matched | 1 | 11.6 |

## Single-agent run (from 2026-10-16)

Rows below add an `m2c` column (whether `scripts/m2c_draft.py` produced the first draft) and the `area` being worked. Matches are verified by `scripts/match_check.py` (instruction words and relocation targets) before the batch reseed.

| utc | function | size | status | attempts | seconds | m2c | area |
| --- | --- | ---: | --- | ---: | ---: | --- | --- |
| 2026-10-16T14:26:01Z | func_00192458 | 300 | matched | 1 | 17.2 | no | clones |
| 2026-10-16T14:26:19Z | func_0026ADF8 | 292 | matched | 1 | 12.6 | no | clones |
| 2026-10-16T14:26:19Z | func_002E2D40 | 188 | matched | 1 | 10.5 | no | clones |
| 2026-10-16T14:26:19Z | func_0028AB48 | 164 | matched | 1 | 9.4 | no | clones |
| 2026-10-16T14:26:19Z | objScroll_Set_test | 156 | matched | 1 | 8.4 | no | clones |
| 2026-10-16T14:27:21Z | func_001F16D8 | 244 | matched | 2 | 73.5 | no | clones |
| 2026-10-16T14:27:21Z | func_00328F30 | 56 | matched | 2 | 67.7 | no | clones |
| 2026-10-16T14:28:40Z | BATCH | - | batch | - | reseed 36.0; score 0.0 | - | batch 1: 8/8 matched, hashes OK |
| 2026-10-16T14:29:12Z | terminate | 24 | matched | 3 | 32.9 | no | clones |
| 2026-10-16T14:29:13Z | unexpected | 24 | matched | 3 | 0.4 | no | clones |
| 2026-10-16T14:29:33Z | func_00382850 | 68 | matched | 1 | 53.0 | yes | clones |
| 2026-10-16T14:29:33Z | func_00383280 | 68 | matched | 1 | 1.2 | yes | clones |
| 2026-10-16T14:31:19Z | func_003258B8 | 204 | non-matching | 6 | 91.1 | no | clones |
| 2026-10-16T14:34:09Z | func_001A0208 | 276 | non-matching | 6 | 128.4 | no | clones |
| 2026-10-16T14:35:17Z | func_001565A0 | 288 | hard-tail | 0 | 25.9 | yes | clones |
| 2026-10-16T14:38:02Z | func_003258B8 | 204 | matched | 7 | 0.3 | no | clones |
| 2026-10-16T14:38:02Z | func_00325988 | 204 | matched | 1 | 1.7 | no | clones |
| 2026-10-16T14:38:02Z | func_00325B90 | 204 | matched | 1 | 1.7 | no | clones |
| 2026-10-16T14:38:16Z | func_0018EF58 | 324 | non-matching | 7 | 172.5 | yes | clones |
| 2026-10-16T14:39:10Z | BATCH | - | batch | - | reseed 38.0; score 0.0 | - | batch 2: 7 matched (terminate, unexpected, func_00382850, func_00383280, func_003258B8, func_00325988, func_00325B90), hashes OK |
| 2026-10-16T14:39:49Z | func_0017E8D8 | 332 | non-matching | 5 | 32.8 | no | clones |
| 2026-10-16T14:41:14Z | func_002B0A58 | 388 | matched | 6 | 85.3 | yes | clones |
| 2026-10-16T14:41:24Z | func_002B0BE0 | 388 | matched | 1 | 10.4 | no | clones |
| 2026-10-16T14:43:04Z | func_001C3778 | 528 | non-matching | 6 | 84.1 | yes | clones |
| 2026-10-16T14:45:04Z | sceGsSetHalfOffset | 136 | non-matching | 6 | 119.6 | no | clones |
| 2026-10-16T14:45:11Z | func_001756D8 | 1148 | hard-tail | 0 | 7.5 | yes | clones |
| 2026-10-16T14:45:46Z | BATCH | - | batch | - | reseed 37.0; score 0.0 | - | batch 3: 2 matched (func_002B0A58, func_002B0BE0), hashes OK |
| 2026-10-16T14:48:27Z | func_0035EDA8 | 32 | matched | 1 | group 162s/9 fns | no | 0035e8.c |
| 2026-10-16T14:48:27Z | func_0035EDC8 | 24 | matched | 1 | group 162s/9 fns | no | 0035e8.c |
| 2026-10-16T14:48:27Z | func_0035EE98 | 32 | matched | 1 | group 162s/9 fns | no | 0035e8.c |
| 2026-10-16T14:48:27Z | func_0035EEB8 | 32 | matched | 1 | group 162s/9 fns | no | 0035e8.c |
| 2026-10-16T14:48:27Z | func_0035EED8 | 32 | matched | 1 | group 162s/9 fns | no | 0035e8.c |
| 2026-10-16T14:48:27Z | func_0035EEF8 | 40 | matched | 2 | group 162s/9 fns | no | 0035e8.c |
| 2026-10-16T14:48:27Z | func_0035EB98 | 20 | matched | 1 | group 162s/9 fns | no | 0035e8.c |
| 2026-10-16T14:48:27Z | func_0035EA30 | 44 | matched | 1 | group 162s/9 fns | no | 0035e8.c |
| 2026-10-16T14:48:27Z | func_0035EB60 | 56 | non-matching | 6 | group 162s/9 fns | no | 0035e8.c |
| 2026-10-16T14:50:04Z | func_0035ED08 | 160 | non-matching | 4 | 83.8 | no | 0035e8.c |
| 2026-10-16T14:50:22Z | func_0035EDE0 | 180 | matched | 1 | 17.6 | no | 0035e8.c |
| 2026-10-16T14:50:48Z | func_0035EA88 | 216 | matched | 1 | 21.2 | yes | 0035e8.c |
| 2026-10-16T14:52:18Z | func_0035EF78 | 600 | matched | 2 | 90.8 | yes | 0035e8.c |
| 2026-10-16T14:52:50Z | BATCH | - | batch | - | reseed 36.0; score 0.0 | - | batch 4: 11 matched in 0035e8.c (EA30 EA88 EB98 EDA8 EDC8 EDE0 EE98 EEB8 EED8 EEF8 EF78), hashes OK |
| 2026-10-16T14:53:41Z | classFADE_start | 380 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | func_00307388 | 856 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | classFADE_kill | 56 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | classFADE_status | 68 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | classFADE_setOt | 76 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | func_003077B0 | 52 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | func_003077E8 | 88 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | func_00307840 | 52 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | func_00307878 | 100 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | func_0031BE88 | 840 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | func_0031CA88 | 244 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | __sjthrow | 728 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | __throw | 476 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | __rethrow | 484 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:53:41Z | func_00322748 | 372 | hard-tail | 0 | - (-O0 frame-pointer code; c_flags_drop of -O2 is closed by compile.py, issue 58) | no | o0 |
| 2026-10-16T14:57:18Z | func_001DE7C8 | 1004 | matched | 1 | 210.6 | yes | 001DE4F8 |
| 2026-10-16T14:57:26Z | func_001DE4F8 | 252 | matched | 1 | (in func_001DE7C8 group timing) | yes | 001DE4F8 |
| 2026-10-16T14:57:26Z | func_001DEA50 | 184 | matched | 1 | (in func_001DE7C8 group timing) | yes | 001DE4F8 |
| 2026-10-16T14:57:26Z | func_001DEB08 | 224 | non-matching | 6 | (in func_001DE7C8 group timing) | yes | 001DE4F8 |
| 2026-10-16T14:59:36Z | func_001DE858 | 504 | matched | 4 | 130.5 | yes | 001DE4F8 |
| 2026-10-16T15:01:27Z | BATCH | - | batch | - | reseed 40.0; score 0.0 | - | batch 5: 5 matched (func_001DE4F8 5F8 7C8 858 A50) in sa_001de4f8.c, hashes OK |
| 2026-10-16T15:03:11Z | func_001ECE30 | 252 | matched | 1 | group 105s/5 fns | no (template SetCustomIDDispOneOrAll_1DD258) | 001ECE30 |
| 2026-10-16T15:03:11Z | func_001ECF30 | 184 | matched | 1 | group 105s/5 fns | yes | 001ECE30 |
| 2026-10-16T15:03:11Z | func_001ECFE8 | 104 | matched | 1 | group 105s/5 fns | yes | 001ECE30 |
| 2026-10-16T15:03:11Z | func_001ED050 | 292 | matched | 2 | group 105s/5 fns | yes | 001ECE30 |
| 2026-10-16T15:03:11Z | func_001ED178 | 584 | matched | 2 | group 105s/5 fns | yes | 001ECE30 |
| 2026-10-16T15:04:34Z | BATCH | - | batch | - | reseed 40.0; score 0.0 | - | batch 6: 5 matched (func_001ECE30 ECF30 ECFE8 ED050 ED178) in sa_001ece30.c, hashes OK |
| 2026-10-16T15:08:34Z | func_002ABCE8 | 68 | matched | 5 | group 240s/4 fns | no | 002ABCE8 |
| 2026-10-16T15:08:34Z | func_002ABD30 | 68 | matched | 1 | group 240s/4 fns | no | 002ABCE8 |
| 2026-10-16T15:08:34Z | func_002ABD78 | 68 | matched | 1 | group 240s/4 fns | no | 002ABCE8 |
| 2026-10-16T15:08:34Z | func_002ABDC0 | 648 | non-matching | 5 | group 240s/4 fns | no | 002ABCE8 |
| 2026-10-16T15:10:19Z | func_0030D190 | 100 | hard-tail | 0 | - (sync + ei: two inline-asm instructions) | yes | 0030D190 |
| 2026-10-16T15:10:19Z | func_0030D1F8 | 92 | non-matching | 4 | (group with D258, ~300s) | yes | 0030D190 |
| 2026-10-16T15:10:19Z | func_0030D258 | 256 | non-matching | 1 | (group with D1F8) | yes | 0030D190 |
| 2026-10-16T15:11:44Z | BATCH | - | batch | - | reseed 40.0; score 0.0 | - | batch 7: 3 matched (func_002ABCE8 ABD30 ABD78) in sa_002abce8.c, hashes OK |
| 2026-10-16T15:15:48Z | func_0031A300 | 28 | matched | 1 | group ~600s/4 fns | yes | 0031A300 |
| 2026-10-16T15:15:48Z | func_0031A320 | 24 | matched | 1 | group ~600s/4 fns | yes | 0031A300 |
| 2026-10-16T15:15:48Z | func_0031A338 | 508 | matched | 4 | group ~600s/4 fns | yes | 0031A300 |
| 2026-10-16T15:15:48Z | func_0031A538 | 196 | non-matching | 6 | group ~600s/4 fns | yes | 0031A300 |
| 2026-10-16T15:20:31Z | func_0031C350 | 232 | matched | 2 | group ~900s/5 fns | yes | 0031C350 |
| 2026-10-16T15:20:31Z | func_0031C438 | 164 | matched | 2 | group ~900s/5 fns | yes | 0031C350 |
| 2026-10-16T15:20:31Z | setPlayerPos | 176 | matched | 6 | group ~900s/5 fns | yes | 0031C350 |
| 2026-10-16T15:20:31Z | func_0031C5C0 | 540 | non-matching (VU0 lqc2/sqc2 copy macro) | 1 | group ~900s/5 fns | no (VU0) | 0031C350 |
| 2026-10-16T15:20:31Z | func_0031C4E0 | 216 | matched | 1 | group ~900s/5 fns | yes | 0031C350 |
| 2026-10-16T15:21:59Z | BATCH | - | batch | - | reseed 90.0; score 0.0 | - | batch 8: 7 matched (func_0031A300 A320 A338, func_0031C350 C438 setPlayerPos C4E0), hashes OK |
| 2026-10-16T15:24:29Z | func_00324C90 | 132 | matched | 2 | group ~420s/3 fns | yes | 00324C90 |
| 2026-10-16T15:24:29Z | func_00324D18 | 112 | non-matching (1 reg) | 6 | group ~420s/3 fns | yes | 00324C90 |
| 2026-10-16T15:24:29Z | func_00324D88 | 228 | matched | 2 | group ~420s/3 fns | yes | 00324C90 |
| 2026-10-16T15:24:29Z | func_001DEB08 | - | permuter ended | - | best score 290 (not 0), run stopped | - | permuter |
| 2026-10-16T15:29:09Z | func_00347008 | 116 | matched | 4 | group ~600s/4 fns | no (hand, from listing; m2c skipped for switches) | 00347008 |
| 2026-10-16T15:29:09Z | func_00347080 | 108 | matched | 2 | group ~600s/4 fns | no (hand, from listing; m2c skipped for switches) | 00347008 |
| 2026-10-16T15:29:09Z | func_003470F0 | 108 | matched | 4 | group ~600s/4 fns | no (hand, from listing; m2c skipped for switches) | 00347008 |
| 2026-10-16T15:29:09Z | func_00347160 | 76 | matched | 2 | group ~600s/4 fns | no (hand, from listing; m2c skipped for switches) | 00347008 |
| 2026-10-16T15:29:45Z | BATCH | - | batch | - | reseed 85.0; score 0.0 | - | batch 9: 6 matched (func_00324C90 D88, func_00347008 7080 70F0 7160), hashes OK |
| 2026-10-16T15:30:48Z | func_0031A538 | 196 | matched | 7 | permuter ~8 min found it; real fix is `int func_003950F8(int, int)` prototype | yes | 0031A300 |
| 2026-10-16T15:31:53Z | func_00324D18 | 112 | matched | 7 | permuter hinted (its score-0 used a self-assignment, rejected); real fix is `int func_00325360(int)` | yes | 00324C90 |
| 2026-10-16T15:33:27Z | func_0034F7A0 | 144 | matched | 1 | group ~420s/3 fns | no (hand, from listing) | 0034F7A0 |
| 2026-10-16T15:33:27Z | func_0034F830 | 156 | matched | 1 | group ~420s/3 fns | no (hand, from listing) | 0034F7A0 |
| 2026-10-16T15:33:27Z | func_0034F8D0 | 96 | non-matching (regalloc, permuter queued) | 6 | group ~420s/3 fns | no (hand, from listing) | 0034F7A0 |
| 2026-10-16T15:34:00Z | BATCH | - | batch | - | reseed 60.0; score 0.0 | - | batch 10: 4 matched (func_0031A538, func_00324D18 via prototype fixes; func_0034F7A0 F830), hashes OK |
| 2026-10-16T15:50:46Z | func_00352AA0 | 248 | non-matching (sched/regalloc of div chain) | 6 | group ~1500s/4 fns | no (hand, from listing) | 003525F0 |
| 2026-10-16T15:50:46Z | func_00352B98 | 224 | matched | 5 | group ~1500s/4 fns | no (hand, from listing) | 003525F0 |
| 2026-10-16T15:50:46Z | func_00352C78 | 324 | non-matching (rec[0] base reg) | 6 | group ~1500s/4 fns | no (hand, from listing) | 003525F0 |
| 2026-10-16T15:50:46Z | func_003526D0 | 192 | non-matching (ret in a3 vs v0) | 6 | group ~1500s/4 fns | no (hand, from listing) | 003525F0 |
| 2026-10-16T15:50:46Z | func_0034F8D0 | - | permuter stopped early | - | best score 370 after ~5 min; to be rerun | - | permuter |
| 2026-10-16T15:56:00Z | func_00352888 | 532 | non-matching (parity/shift order + non-drop regalloc, 12 insns) | 6 | ~420s | yes (draft, then hand cleanup) | 003525F0 |
| 2026-10-16T15:56:00Z | func_00352790 | 236 | non-matching (rate reg v1 vs a1, 8 insns) | 6 | ~300s | yes (draft, then hand cleanup) | 003525F0 |
| 2026-10-16T15:56:00Z | func_003525F0 | 220 | matched | 2 | ~120s | no (hand, from listing) | 003525F0 |
| 2026-10-16T15:57:44Z | BATCH | - | batch | - | reseed 60.0; score 0.0 | - | batch 11: 2 matched (func_003525F0 B98) in sa_003525f0.c, hashes OK; area 3525F0 exhausted (5 NM in sa_nm_003525f0.c) |
| 2026-10-16T16:11:08Z | func_00353EE0 | 132 | matched | 5 | group ~1800s/8 fns | yes (draft) | 00353928 |
| 2026-10-16T16:11:08Z | func_00354080 | 164 | matched | 1 | group ~1800s/8 fns | yes (draft; ldl/sdl copy by hand) | 00353928 |
| 2026-10-16T16:11:08Z | func_00354128 | 232 | matched | 2 | group ~1800s/8 fns | yes (draft) | 00353928 |
| 2026-10-16T16:11:08Z | func_003542B8 | 372 | non-matching (64-bit dsrl extract, 1 word) | 6 | group ~1800s/8 fns | yes (draft) | 00353928 |
| 2026-10-16T16:11:08Z | func_00353F68 | 280 | matched | 1 | group ~1800s/8 fns | yes (draft; ldl/sdl copy by hand) | 00353928 |
| 2026-10-16T16:11:08Z | func_00354210 | 168 | matched | 1 | group ~1800s/8 fns | yes (draft) | 00353928 |
| 2026-10-16T16:11:08Z | func_00353BD8 | 776 | non-matching (epilogue sched, 6 insns) | 6 | group ~1800s/8 fns | yes (draft; copies by hand) | 00353928 |
| 2026-10-16T16:11:08Z | func_00353928 | 684 | non-matching (regalloc/frame size) | 6 | group ~1800s/8 fns | no (hand, from listing) | 00353928 |
| 2026-10-16T16:11:08Z | BATCH | - | batch | - | reseed 81.0; score 0.0 | - | batch 12: 5 matched (func_00353EE0 3F68 4080 4128 4210) in sa_00353928.c, hashes OK; area 353928 exhausted |
| 2026-10-16T16:15:20Z | func_0030D358 | 620 | non-matching (CSE anchor; needs extern_jtbl D_00450550, not settable via sa_register) | 6 | ~600s | no (hand, from listing; jump table) | 0030D190 |
| 2026-10-16T16:21:29Z | pl00_CkSubScreen | 52 | non-matching (5 insns: retail slti/nop/beqz/nop/bltz range tail to shared return 0) -> src/cod/sa_nm_0012bab8.c | 6 | ~300s | yes (m2c draft) | 0012BAB8 |
| 2026-10-16T16:21:29Z | func_0012BAF0 | 72 | non-matching (same 5-insn range tail); moved out of batch28_nm.c | 4 | ~200s | yes (m2c draft) | 0012BAB8 |
| 2026-10-16T16:21:29Z | func_0014E5D0 | 188 | matched (47 insns, 11 relocs) -> src/cod/sa_0014e5d0.c | 1 | ~120s | yes (m2c draft, cObj.h types) | 0014E5D0 |
| 2026-10-16T16:21:29Z | cObj_setId | 216 | non-matching (missing andi 0xFF per id range flag) -> src/cod/sa_nm_0014e5d0.c | 6 | ~420s | no (hand, from listing) | 0014E5D0 |

BATCH 13: 1 matched (func_0014E5D0), reseed hashes OK, 2026-10-16T16:21:29Z.
| 2026-10-16T16:33:22Z | func_001522C0 | 80 | non-matching (1 insn: retail bne, ours bnel) -> src/cod/sa_nm_001522c0.c; moved out of batch29_nm.c | 6 | ~420s | yes (m2c draft via prior NM) | 00151688 |
| 2026-10-16T16:33:22Z | func_00152340 | 184 | matched (46 insns, 1 reloc; three separate 8 divisors) -> src/cod/sa_00152340.c | 4 | ~360s | yes (m2c draft) | 00151688 |
| 2026-10-16T16:33:22Z | func_00151688 | 772 | non-matching (165 insns reg-alloc only; also needs TU "as": "sn" for dli masks, not settable via sa_register) -> src/cod/sa_nm_00151688.c | 6 | ~1500s | yes (m2c draft) | 00151688 |
| 2026-10-16T16:33:22Z | func_00151990 | 812 | non-matching (needs TU "as": "sn"; with it 85 insns scheduling) -> src/cod/sa_nm_00151990.c | 6 | ~1200s | yes (m2c draft) | 00151688 |
| 2026-10-16T16:33:22Z | func_00151CC0 | 736 | hard-tail: blocked, same 64-bit dli masks need TU "as": "sn" (sa_register cannot set) | 0 | ~60s | no | 00151688 |
| 2026-10-16T16:33:22Z | func_00151FA0 | 796 | hard-tail: blocked, same 64-bit dli masks need TU "as": "sn" (sa_register cannot set) | 0 | ~60s | no | 00151688 |

BATCH 14: 1 matched (func_00152340), reseed hashes OK, 2026-10-16T16:34:52Z.
| 2026-10-16T16:36:52Z | func_003526D0 | 192 | permuter 30 min: best 150 was junk (ret=unit;unit=ret; ^0), rejected; stays NM | - | 1800s | no | 003525F0 |
| 2026-10-16T16:36:52Z | func_00353BD8 | 776 | matched (194 insns, 2 relocs): permuter hinted moving out->f28=0 after out->pic; final store order buf, pic, f28, f2C -> src/cod/sa_00353928.c | 7 (6 + permuter hint) | ~420s + 900s permuter | no (hand, earlier) | 00353928 |

BATCH 15: 1 matched (func_00353BD8), reseed hashes OK, 2026-10-16T16:36:52Z.
| 2026-10-16T16:43:35Z | func_001552F0 | 100 | non-matching (13 insns v0/v1 swap) -> src/cod/sa_nm_001552f0.c; removed __asm__ inbox draft | 6 | ~600s | yes (m2c draft via prior NM) | 001552F0 |
| 2026-10-16T16:43:35Z | func_00155AE8 | 252 | non-matching (62 vs 63 words: retail copies id to t3 first) -> src/cod/sa_nm_00155ae8.c | 6 | ~600s | no (hand, from listing) | 001552F0 |
| 2026-10-16T16:43:35Z | func_00155800 | 668 | non-matching (loop-invariant hoisting set differs, 156 vs 167 words) -> src/cod/sa_nm_00155800.c | 2 | ~900s | no (hand, from listing) | 001552F0 |
| 2026-10-16T16:43:35Z | func_00155678 | 392 | hard-tail: blocked, SN-assembler-only dli expansions (ori/dsll 18/ori/dsll 1); needs TU "as": "sn" (sa_register cannot set) | 0 | ~300s | no | 001552F0 |
| 2026-10-16T16:43:35Z | func_00155358 | 796 | hard-tail: blocked, same SN-assembler dli expansions (ori 0x8000; dsll32 13 / dsll 24) | 0 | ~60s | no | 001552F0 |

BATCH 16: 0 matched (no registered changes, no reseed needed), 2026-10-16T16:43:35Z.
| 2026-10-16T16:47:36Z | func_001573C8 | 196 | non-matching (13 insns: bz/dz FP regs f7/f8 swapped) -> src/cod/sa_nm_001573c8.c | 6 | ~600s | yes (m2c draft via prior NM) | 001573C8 |
| 2026-10-16T16:47:36Z | RoundFloat | 84 | non-matching (retail cvt.w.s in FPR twice; ours trunc.w.s+mfc1/mtc1) -> src/cod/sa_nm_001573c8.c; moved out of batch29_nm.c | 4 | ~420s | no (hand) | 001573C8 |
| 2026-10-16T16:47:51Z | func_001522C0 | 80 | permuter ~25 min: score-0 result is junk (pack && pack, empty if), rejected; stays NM | - | 1500s | no | 00151688 |
| 2026-10-16T16:53:43Z | MotionIsHaveParam | 108 | matched -> src/cod/sa_001594a0.c (MotionParam bitfield word: kind:8, sub:4, func:4) | 1 | ~240s | no (hand, from listing) | 001594A0 |
| 2026-10-16T16:53:43Z | MotionGetParam | 180 | matched -> src/cod/sa_001594a0.c (do/while with prm,i set before nParam check; switch 6..8 -> 1.0f) | 7 | ~600s | no (hand, from listing) | 001594A0 |
| 2026-10-16T16:53:43Z | func_00155AE8 | 252 | permuter best 335 (from 680) needs junk const local (new_var=1); legit operand swap alone regresses; still running | - | ~800s | no | 00155AE8 |

BATCH 17: 2 matched (MotionIsHaveParam, MotionGetParam), reseed 78s elf=OK overlay=OK, 2026-10-16T16:53:43Z.
| 2026-10-16T17:00:25Z | func_001ABB58 | 140 | matched -> src/cod/sa_001abb58.c (RndRateTbl struct copy of D_00427CD8, Rnd() % rate[level] == 0) | 1 | ~300s | no (hand, from listing) | 001ABB58 |
| 2026-10-16T17:00:25Z | func_001ABBE8 | 164 | matched -> src/cod/sa_001abb58.c (ActObj flags @0x9D0) | 1 | ~120s | no (hand, from listing) | 001ABB58 |

BATCH 18: 2 matched (func_001ABB58, func_001ABBE8), reseed 71s elf=OK overlay=OK, 2026-10-16T17:00:25Z.
| 2026-10-16T17:03:34Z | func_001B19E0 | 160 | matched -> src/cod/sa_001b19e0.c (reflection matrix I-2nn^T, column-major store order, off-diagonals in locals); dropped NM note from batch42_nm.c | 2 | ~420s | no (hand, from listing) | 001B19E0 |
| 2026-10-16T17:03:34Z | func_001B1A80 | 104 | matched -> src/cod/sa_001b19e0.c (EmTimerObj timer @0x630); removed NM copy from batch36_nm.c | 1 | ~120s | no (hand, prior NM draft) | 001B19E0 |
| 2026-10-16T17:03:34Z | func_00155AE8 | 252 | permuter stopped after ~30 min: best 335 (from 680) only with junk const local; rejected, stays NM | - | 1800s | no | 00155AE8 |

BATCH 19: 2 matched (func_001B19E0, func_001B1A80), reseed 87s elf=OK overlay=OK, 2026-10-16T17:03:34Z.
| 2026-10-16T17:15:34Z | func_001D4720 | 200 | matched -> src/cod/sa_001d4720.c (blackjack hand total; permuter hint: score++ wrapped in do { } while (0), flagged) ; deleted unregistered 001d4720_nm.c (had asm barrier) | 5+perm | ~1500s | no (hand, from listing) | 001D4720 |
| 2026-10-16T17:15:34Z | func_001D47E8 | 200 | matched -> src/cod/sa_001d4720.c (hand B twin of 1D4720, same do/while(0) wrapper, flagged) | 1 | ~60s | no | 001D4720 |
| 2026-10-16T17:15:34Z | func_001DBEB0 | 104 | non-matching (retail loops un-optimized: goto-loop reproduces regs, +4 anchor and loop pad differ) -> src/cod/sa_nm_001dbeb0.c | 6 | ~900s | yes (m2c draft) | 001DBEB0 |
| 2026-10-16T17:15:34Z | func_001DBF18 | 156 | matched -> src/cod/sa_001dbf18.c (suit counter; switch needs explicit case 0 sharing default) | 2 | ~300s | no (hand) | 001DBEB0 |
| 2026-10-16T17:15:34Z | func_001DBFB8 | 496 | non-matching (5 insns: lhu vs lw rank loads; volatile rank matches but contradicts DC4C0, not adopted) -> src/cod/sa_nm_001dbeb0.c | 6 | ~1200s | no (hand) | 001DBEB0 |
| 2026-10-16T17:15:34Z | func_001DC1A8 | 272 | matched -> src/cod/sa_001dbf18.c (royal flush check) | 1 | ~240s | no (hand) | 001DBEB0 |
| 2026-10-16T17:15:34Z | func_001DC2B8 | 516 | matched -> src/cod/sa_001dbf18.c (straight flush, PkStraightTbl struct copy of D_0042B418) | 1 | ~300s | no (hand) | 001DBEB0 |
| 2026-10-16T17:15:34Z | func_001DC4C0 | 312 | non-matching (2 insns: back-edge i copy/compare order) -> src/cod/sa_nm_001dbeb0.c | 6 | ~600s | no (hand) | 001DBEB0 |

BATCH 20: 5 matched (func_001D4720, func_001D47E8, func_001DBF18, func_001DC1A8, func_001DC2B8), reseed 34s elf=OK overlay=OK, 2026-10-16T17:15:34Z.
CHECKPOINT (batches 11-20): headers moved, cold build PASSED 260s, ELF+overlay OK, 2026-10-16T17:27:07Z.
| 2026-10-16T17:30:44Z | func_001E8EB8 | 188 | matched -> src/cod/sa_001e8eb8.c (direction slot from angle; TU fp_hazard_rules mtc1,fpfence) | 2 | ~420s | no (hand, from listing) | 001E8EB8 |
| 2026-10-16T17:30:44Z | func_001E8F78 | 172 | matched -> src/cod/sa_001e8eb8.c (cVec_copy3 from cOmBase.h, spin vec @0x340) | 1 | ~180s | no (hand) | 001E8EB8 |

BATCH 21: 2 matched (func_001E8EB8, func_001E8F78), reseed elf=OK overlay=OK (reseed rc=0 83s elf=OK overlay=OK), 2026-10-16T17:30:44Z.
| 2026-10-16T17:32:16Z | func_001F08B8 | - | matched -> src/cod/sa_001f08b8.c (ColiseumBattle unkC64 phase) | 1 | ~240s | no (hand) | 001F08B8 |
| 2026-10-16T17:32:16Z | func_001F0978 | - | matched -> src/cod/sa_001f08b8.c (phase switch) | 1 | ~240s | no (hand) | 001F08B8 |

BATCH 22: 2 matched (func_001F08B8, func_001F0978), reseed elf=OK overlay=OK, 2026-10-16T17:32:16Z.
| 2026-10-16T17:37:57Z | func_001F33F8 | 144 | matched -> src/cod/sa_001f33f8.c (five disp ids + SetNumber @0x728) | 1 | ~120s | no (hand) | 001F32A0 |
| 2026-10-16T17:37:57Z | func_001F32A0 | 344 | non-matching (38 insns, colour regalloc only; flag via long local, by-value bitfield colours, case 2 no-op) -> src/cod/sa_nm_001f32a0.c | 6 | ~900s | no (hand) | 001F32A0 |
| 2026-10-16T17:37:57Z | func_001F3488 | 244 | non-matching (3 insns: case-3 beql delay slot lui a1 vs daddu a0) -> src/cod/sa_nm_001f32a0.c | 6 | ~600s | no (hand) | 001F32A0 |

BATCH 23: 1 matched (func_001F33F8), reseed 79s elf=OK overlay=OK, 2026-10-16T17:37:57Z.
| 2026-10-16T17:46:47Z | func_001F7228 | 148 | matched -> src/cod/sa_001f70c8.c (entry reset; store order flags,C,10..) | 3 | ~240s | yes | 001F70C8 |
| 2026-10-16T17:46:47Z | func_001F72C0 | 160 | matched -> src/cod/sa_001f70c8.c (8-entry reset loop @0x104) | 1 | ~120s | yes | 001F70C8 |
| 2026-10-16T17:46:47Z | func_001F70C8 | 352 | matched -> src/cod/sa_001f70c8.c (unk32 short, <=0 path first, stores 2C/36/32) | 4 | ~600s | yes | 001F70C8 |
| 2026-10-16T17:46:47Z | func_001F7360 | 588 | non-matching (D_00747A80 anchor + case tree match; 0x2000000 hoist, next temp, loop-top nop needs call_loop_pad) -> src/cod/sa_nm_001f7360.c | 6 | ~900s | yes | 001F70C8 |

BATCH 24: 3 matched (func_001F7228, func_001F72C0, func_001F70C8), reseed 69s elf=OK overlay=OK, 2026-10-16T17:46:47Z.
| 2026-10-16T17:53:07Z | func_002B2A30 | 40 | matched -> src/cod/002b28.c (replaced INCLUDE_ASM) | 1 | ~60s | yes | 002B2A30 |
| 2026-10-16T17:53:07Z | func_002B2A58 | 44 | matched -> src/cod/002b28.c (replaced INCLUDE_ASM) | 1 | ~60s | yes | 002B2A30 |
| 2026-10-16T17:53:07Z | func_002AEE40 | 204 | matched -> src/cod/sa_002aee40.c (free-list pop + prio insert, serial @0xBD8) | 1 | ~240s | yes | 002AEE40 |
| 2026-10-16T17:53:07Z | func_002AEF10 | 120 | matched -> src/cod/sa_002aee40.c (unlink + push free) | 1 | ~60s | yes | 002AEE40 |
| 2026-10-16T17:53:07Z | func_002B1090 | 216 | matched -> src/cod/sa_002b1090.c (goto-entered do/while keeps loop align, no loop.c hoist; fp mtc1) | 5 | ~720s | yes | 002B1090 |
| 2026-10-16T17:53:07Z | func_002B1168 | 252 | matched -> src/cod/sa_002b1090.c (same loop shape) | 5 | ~120s | yes | 002B1090 |

BATCH 25: 6 matched (func_002B2A30, func_002B2A58, func_002AEE40, func_002AEF10, func_002B1090, func_002B1168), reseed 81s elf=OK overlay=OK, 2026-10-16T17:53:07Z.
| 2026-10-16T18:05:53Z | func_002B4228 | 200 | non-matching (fdiv,mtc1: first div.s missing its mtc1 nop) -> src/cod/sa_nm_002b4228.c | 6 | ~600s | yes | 002B4228 |
| 2026-10-16T18:05:53Z | func_002B42F0 | 156 | non-matching (7 insns: 64-bit flags test sign-extension) -> src/cod/sa_nm_002b4228.c | 6 | ~480s | yes | 002B4228 |
| 2026-10-16T18:05:53Z | func_002C0B38 | 240 | non-matching (27 insns: FP regalloc, last test own return block) -> src/cod/sa_nm_002c0b38.c | 6 | ~600s | yes | 002C0B38 |
| 2026-10-16T18:05:53Z | func_002C0C28 | 132 | non-matching (1 insn under -ffast-math+fdiv like 002c0cb0.c: redundant v0=0 delay slot) -> src/cod/sa_nm_002c0b38.c | 6 | ~480s | yes (hand for sqrt.s) | 002C0B38 |
| 2026-10-16T18:05:53Z | func_002CA558 | 124 | matched -> src/cod/sa_002ca558.c | 1 | ~60s | yes | 002CA558 |
| 2026-10-16T18:05:53Z | func_002CA5D8 | 184 | non-matching (1 insn: voice flag lw/dsrl vs our sra; needs call_loop_pad) -> src/cod/sa_nm_002ca5d8.c | 6 | ~600s | yes | 002CA558 |
| 2026-10-16T18:05:53Z | func_002CA910 | 236 | matched -> src/cod/sa_002ca910.c (bgm resume loop, !0x100 first) | 2 | ~240s | yes | 002CA910 |
| 2026-10-16T18:05:53Z | func_002CAA00 | 344 | matched -> src/cod/sa_002ca910.c (short key loop, interleaved flag ops) | 1 | ~240s | yes | 002CA910 |
| 2026-10-16T18:05:53Z | func_002CAB58 | 132 | matched -> src/cod/sa_002ca910.c | 1 | ~120s | yes | 002CA910 |

BATCH 26: 4 matched (func_002CA558, func_002CA910, func_002CAA00, func_002CAB58), reseed 86s elf=OK overlay=OK, 2026-10-16T18:05:53Z.
| 2026-10-16T18:09:24Z | func_002D0B88 | 136 | non-matching (22 insns: found ptr a0 / table end a1 vs our a2/a0, fallback store order) -> src/cod/sa_nm_002d0b88.c | 6 | ~600s | yes | 002D0B88 |
| 2026-10-16T18:09:24Z | cSnd_IsEnemyAlive | 188 | non-matching (36 insns: kind range tests fold to unsigned compare or movz; retail two slti + branch) -> src/cod/sa_nm_002d0b88.c | 6 | ~420s | yes | 002D0B88 |

BATCH 27: 0 matched (2 non-matching), no registry change so no reseed, 2026-10-16T18:09:24Z.
| 2026-10-16T18:15:23Z | func_002FA350 | 140 | non-matching (29 insns: retail cvt.w.s kept in FPR; all compilers emit trunc.w.s for (int) casts, same as RoundFloat) -> src/cod/sa_nm_002fa350.c | 3 | ~360s | yes | 002FA350 |
| 2026-10-16T18:15:23Z | func_002FA3E0 | 140 | non-matching (same cvt.w.s limitation as func_002FA350) -> src/cod/sa_nm_002fa350.c | 3 | ~60s | yes | 002FA350 |
| 2026-10-16T18:15:23Z | func_00306030 | 124 | matched -> src/cod/sa_00306030.c (separate early returns, int-add for tbl+off order) | 3 | ~300s | no (hand) | 00306030 |
| 2026-10-16T18:15:23Z | espSys_getEffT32Addr | 132 | matched -> src/cod/sa_00306030.c | 3 | ~120s | no (hand) | 00306030 |
| 2026-10-16T18:15:23Z | func_00307060 | 160 | non-matching (5 insns: adjacency-compare register allocation) -> src/cod/sa_nm_00307060.c | 6 | ~480s | no (hand) | 00307060 |
| 2026-10-16T18:15:23Z | func_00307118 | 36 | non-matching, already in batch27_nm.c (xor+sltiu vs retail bne dual return; int/u8/short/long returns tried) | 4 | ~180s | no (hand) | 00307060 |

BATCH 28: 2 matched (func_00306030, espSys_getEffT32Addr), reseed 92s elf=OK overlay=OK, 2026-10-16T18:15:23Z.
| 2026-10-16T18:22:57Z | func_0031D2B8 | 64 | matched -> src/cod/sa_0031d2b8.c (re-indexes by the counter byte per store; replaces batch28_nm volatile attempt) | 1 | ~120s | no (hand) | 0031D2B8 |
| 2026-10-16T18:22:57Z | func_0031D6E8 | 144 | matched -> src/cod/sa_0031d6e8.c (_S_oom_malloc; noreturn exit, inline manipulator call for endl) | 2 | ~240s | no (hand) | 0031D2B8 |
| 2026-10-16T18:22:57Z | func_0031D2F8 | 216 | non-matching (2 insns: cBoundingBox delay-slot pick) -> src/cod/sa_nm_0031d2f8.c | 6 | ~420s | no (hand) | 0031D2B8 |
| 2026-10-16T18:22:57Z | func_0031D3D0 | 644 | non-matching (81 insns: post-GetActiveState copies and vector copy schedule) -> src/cod/sa_nm_0031d2f8.c | 6 | ~1200s | yes | 0031D2B8 |
| 2026-10-16T18:22:57Z | func_0031D658 | 136 | matched -> src/cod/sa_0031d2b8.c (returns count; int add for offset order) | 4 | ~300s | no (hand) | 0031D2B8 |

BATCH 29: 3 matched (func_0031D2B8, func_0031D6E8, func_0031D658), reseed 89s elf=OK overlay=OK, 2026-10-16T18:22:57Z.
| 2026-10-16T18:28:23Z | __do_global_dtors | 84 | matched -> src/cod/sa_0031da48.c (ee-2.9-991111, libgcc2 verbatim) | 1 | ~120s | no (hand) | 0031DA48 |
| 2026-10-16T18:28:23Z | __do_global_ctors | 176 | matched -> src/cod/sa_0031da48.c (DO_GLOBAL_CTORS_BODY do/while(0) block) | 3 | ~240s | no (hand) | 0031DA48 |
| 2026-10-16T18:28:23Z | __cplus_type_matcher | 108 | matched -> src/cod/00321240.cc (ee-2.9-991111 C++, exception.cc) | 1 | ~180s | no (hand) | 00321308 |
| 2026-10-16T18:28:23Z | __cp_push_exception | 144 | matched -> src/cod/00321240.cc (C++ only; C build swaps epilogue store) | 2 | ~240s | no (hand) | 00321308 |
| 2026-10-16T18:28:23Z | __cp_pop_exception | 196 | matched -> src/cod/00321240.cc (C++ only: C build tail-calls __eh_free; noreturn terminate) | 3 | ~300s | no (hand) | 00321308 |

BATCH 30: 5 matched (__do_global_dtors, __do_global_ctors, __cplus_type_matcher, __cp_push_exception, __cp_pop_exception), reseed 95s elf=OK overlay=OK, 2026-10-16T18:28:23Z.
| 2026-10-16T18:47:18Z | func_00324EB0 | 88 | matched -> src/cod/sa_00324eb0.c (cygnus-2.96, drop-reorder; volatile thread flags) | 5 | ~420s | no (hand) | 00324EB0 |
| 2026-10-16T18:47:18Z | func_00324F08 | 260 | matched -> src/cod/sa_00324eb0.c (func_00325360 returns int) | 2 | ~240s | no (hand) | 00324EB0 |
| 2026-10-16T18:47:18Z | func_00325010 | 240 | matched -> src/cod/sa_00324eb0.c (D_003C81C4 non-volatile, GS BGCOLOR writes) | 6 | ~360s | no (hand) | 00324EB0 |
| 2026-10-16T18:47:18Z | func_00325100 | 312 | matched -> src/cod/sa_00324eb0.c | 1 | ~180s | no (hand) | 00324EB0 |
| 2026-10-16T18:47:18Z | func_00325DF0 | 136 | matched -> src/cod/sa_00324eb0.c (replaces retired inbox stub) | 1 | ~90s | no (hand) | 00325DF0 |
| 2026-10-16T18:47:18Z | func_00325E78 | 124 | matched -> src/cod/sa_00324eb0.c (ThreadParam status 4/0xC wake) | 1 | ~90s | no (hand) | 00325DF0 |

BATCH 31: 6 matched (func_00324EB0, func_00324F08, func_00325010, func_00325100, func_00325DF0, func_00325E78), reseed 37s elf=OK overlay=OK, 2026-10-16T18:47:18Z.
| 2026-10-16T18:57:02Z | func_0031D2F8 | 216 | matched -> src/cod/sa_0031d2f8.c (permuter hint: cBoundingBox returns BoundingBox*, ctor returns this) | 7 | ~600s | no (hand) | 0031D2B8 |
| 2026-10-16T18:57:02Z | func_0032BF90 | 184 | matched -> src/cod/sa_0032bf90.c (cygnus-2.96, drop-reorder) | 1 | ~240s | no (hand) | 0032BE10 |
| 2026-10-16T18:57:02Z | func_0032C048 | 408 | matched -> src/cod/sa_0032bf90.c (SJ vtable GetChunk/PutChunk/Reset; needs drop-reorder) | 3 | ~420s | yes (draft) | 0032BE10 |
| 2026-10-16T18:57:02Z | func_0032C1E0 | 200 | non-matching (block order; attempts spent before drop-reorder found) -> src/cod/sa_nm_0032be10.c | 6 | ~600s | no (hand) | 0032BE10 |
| 2026-10-16T18:57:02Z | func_0032BE10 | 368 | non-matching (1 insn: beql vs beq on 2nd NULL test) -> src/cod/sa_nm_0032be10.c; permuter candidate | 6 | ~540s | yes (draft) | 0032BE10 |

BATCH 32: 3 matched (func_0031D2F8, func_0032BF90, func_0032C048), reseed 91s elf=OK overlay=OK, 2026-10-16T18:57:02Z.
| 2026-10-16T19:05:39Z | func_00346DD0 | 80 | matched -> src/cod/sa_00346dd0.c (cygnus-2.96 drop-reorder; early return) | 4 | ~300s | no (hand) | 00346DD0 |
| 2026-10-16T19:05:39Z | func_00346E20 | 76 | matched -> src/cod/sa_00346dd0.c | 4 | ~60s | no (hand) | 00346DD0 |
| 2026-10-16T19:05:39Z | func_003568B8 | 112 | matched -> src/cod/sa_003568b8.c (work+0x1198 ViBuf) | 1 | ~180s | no (hand) | 003568B8 |
| 2026-10-16T19:05:39Z | func_00356928 | 92 | matched -> src/cod/sa_003568b8.c | 1 | ~30s | no (hand) | 003568B8 |
| 2026-10-16T19:05:39Z | func_00335248 | 128 | matched -> src/cod/sa_00335248.c (memcpy from extern "/" keeps reloc) | 2 | ~300s | no (hand) | 00335248 |
| 2026-10-16T19:05:39Z | func_003352D0 | 100 | matched -> src/cod/sa_00335248.c (memcpy "host:" 6 bytes) | 1 | ~60s | no (hand) | 00335248 |
| 2026-10-16T19:05:39Z | func_00355508 | 160 | matched -> src/cod/sa_00355508.c (frame pool count) | 1 | ~240s | no (hand) | 00355508 |
| 2026-10-16T19:05:39Z | func_003555A8 | 136 | matched -> src/cod/sa_00355508.c (64-bit long view of state word -> ld; loop nops are as short-loop pad) | 3 | ~360s | no (hand) | 00355508 |

BATCH 33: 8 matched (func_00346DD0, func_00346E20, func_003568B8, func_00356928, func_00335248, func_003352D0, func_00355508, func_003555A8), reseed 89s elf=OK overlay=OK, 2026-10-16T19:05:39Z.
| 2026-10-16T19:15:15Z | func_00385078 | 192 | matched -> src/cod/sa_00385078.c (sn-2.95.3-136; MenuInfo nested in MenuList @0x4C) | 4 | ~600s | no (hand) | 00385078 |
| 2026-10-16T19:15:15Z | func_00385138 | 132 | matched -> src/cod/sa_00385078.c | 1 | ~60s | no (hand) | 00385078 |
| 2026-10-16T19:15:15Z | func_00331070 | 160 | non-matching (delay slot: lui of warning string not hoisted into 3rd stat test) -> src/cod/sa_nm_00331070.c | 6 | ~600s | no (hand) | 00331070 |
| 2026-10-16T19:15:15Z | func_00331110 | 236 | non-matching (3 insns: stat/devtype store order) -> src/cod/sa_nm_00331070.c; permuter candidate | 6 | ~600s | no (hand) | 00331070 |
| 2026-10-16T19:15:15Z | func_0035F5F0 | 168 | non-matching (same length; entry base/index regs swapped) -> src/cod/sa_nm_0035f5f0.c | 6 | ~540s | no (hand) | 0035F5F0 |
| 2026-10-16T19:15:15Z | func_0035F698 | 240 | matched -> src/cod/sa_0035f698.c (cygnus-2.96 drop-reorder; if-form decoder callback) | 2 | ~240s | no (hand) | 0035F5F0 |

BATCH 34: 3 matched (func_00385078, func_00385138, func_0035F698), reseed 37s elf=OK overlay=OK, 2026-10-16T19:15:15Z.
| 2026-10-16T19:24:11Z | func_003A5148 | 172 | non-matching (memcpy; sn closest, 1 word short: dst0->t0 reg choice) -> src/cod/sa_nm_003a5148.c | 3 | ~600s | no (hand) | 003A4FC8 |
| 2026-10-16T19:24:11Z | func_003A51F4 | 252 | non-matching (memmove; 4 words long) -> src/cod/sa_nm_003a5148.c | 2 | ~240s | no (hand) | 003A4FC8 |
| 2026-10-16T19:24:11Z | func_002B2D88 | 244 | matched -> src/cod/sa_002b2d88.c (sn; explicit returns, call before float convert) | 3 | ~420s | no (hand) | 002B2D88 |
| 2026-10-16T19:24:11Z | func_002B2E80 | 184 | matched -> src/cod/sa_002b2d88.c (dead owner reload = cross-jumped identical if/else) | 5 | ~480s | no (hand) | 002B2D88 |

BATCH 35: 2 matched (func_002B2D88, func_002B2E80), reseed 91s elf=OK overlay=OK, 2026-10-16T19:24:11Z.
| 2026-10-16T19:28:49Z | func_00346848 | 112 | matched -> src/cod/sa_00346848.c (cygnus-2.96 drop-reorder; MwsfHn stat) | 1 | ~180s | no (hand) | 00346848 |
| 2026-10-16T19:28:49Z | func_003468B8 | 176 | matched -> src/cod/sa_00346848.c | 2 | ~240s | no (hand) | 00346848 |
| 2026-10-16T19:28:49Z | func_00346968 | 204 | matched -> src/cod/sa_00346848.c | 2 | ~300s | no (hand) | 00346848 |
| 2026-10-16T19:28:49Z | func_003835A0 | 236 | matched -> src/cod/sa_003835a0.c (sn; if/else stat assignments) | 2 | ~300s | no (hand) | 003835A0 |
| 2026-10-16T19:28:49Z | func_00383690 | 116 | matched -> src/cod/sa_003835a0.c (switch) | 1 | ~120s | no (hand) | 003835A0 |
| 2026-10-16T19:28:49Z | func_00383708 | 220 | matched -> src/cod/sa_003835a0.c (unprototyped tail callees -> v1 for const 1) | 3 | ~420s | no (hand) | 003835A0 |
| 2026-10-16T19:28:49Z | func_003837E8 | 96 | matched -> src/cod/sa_003835a0.c | 1 | ~90s | no (hand) | 003835A0 |

BATCH 36: 7 matched (func_00346848, func_003468B8, func_00346968, func_003835A0, func_00383690, func_00383708, func_003837E8), reseed 87s elf=OK overlay=OK, 2026-10-16T19:28:49Z.
| 2026-10-16T19:37:07Z | func_00347F20 | 188 | matched -> src/cod/sa_00347f20.c (cygnus-2.96 drop-reorder; early returns for sibcall) | 2 | ~240s | no (hand) | 00347E58 |
| 2026-10-16T19:37:07Z | func_00348098 | 188 | matched -> src/cod/sa_00347f20.c (t=q*1000 then t*3>>1 keeps shift synth) | 4 | ~480s | no (hand) | 00347E58 |
| 2026-10-16T19:37:07Z | func_00347E58 | 192 | non-matching (5 insns: concat reload/lbu copy, sfd load hoist) -> src/cod/sa_nm_00347e58.c | 6 | ~600s | m2c (draft read) | 00347E58 |
| 2026-10-16T19:37:07Z | func_00347FE0 | 184 | non-matching (1 insn: case-1 reuses const a2 vs a0) -> src/cod/sa_nm_00347e58.c; permuter candidate | 6 | ~420s | m2c (draft read) | 00347E58 |
| 2026-10-16T19:37:07Z | func_0034F200 | 400 | matched -> src/cod/sa_0034f200.c (span fields copied to locals; 64-bit pts in t0) | 3 | ~480s | no (m2c draft unusable: t0 5th arg) | 0034F200 |
| 2026-10-16T19:37:07Z | func_0034F390 | 136 | matched -> src/cod/sa_0034f200.c | 1 | ~120s | no (hand) | 0034F200 |
| 2026-10-16T19:37:07Z | func_0034F418 | 144 | matched -> src/cod/sa_0034f200.c | 1 | ~60s | no (hand) | 0034F200 |
| 2026-10-16T19:37:07Z | func_0037D760 | 192 | matched -> src/cod/sa_0037d760.c (sn; join-point add; decl order = load order) | 3 | ~300s | no (hand) | 0037D760 |
| 2026-10-16T19:37:07Z | func_0037D820 | 152 | matched -> src/cod/sa_0037d760.c | 1 | ~120s | no (hand) | 0037D760 |
| 2026-10-16T19:37:07Z | func_0037D8B8 | 248 | matched -> src/cod/sa_0037d760.c | 1 | ~180s | no (hand) | 0037D760 |
| 2026-10-16T19:37:07Z | func_0037D9B0 | 120 | matched -> src/cod/sa_0037d760.c (index loop -> signed slt; switch on mode) | 2 | ~180s | no (hand) | 0037D760 |

BATCH 37: 9 matched (func_00347F20, func_00348098, func_0034F200, func_0034F390, func_0034F418, func_0037D760, func_0037D820, func_0037D8B8, func_0037D9B0), reseed 88s elf=OK overlay=OK, 2026-10-16T19:37:07Z.
| 2026-10-16T19:46:50Z | func_00336E88 | 188 | matched -> src/cod/sa_00336e88.c (cygnus-2.96 drop-reorder; global store order) | 2 | ~240s | no (hand) | 00336E88 |
| 2026-10-16T19:46:50Z | func_00336F48 | 760 | matched -> src/cod/sa_00336e88.c (for(;;) traps = as short-loop pad; printf-like logger) | 2 | ~600s | no (hand) | 00336E88 |
| 2026-10-16T19:46:50Z | func_00337320 | 116 | matched -> src/cod/sa_00336e88.c | 1 | ~120s | no (hand) | 00336E88 |
| 2026-10-16T19:46:50Z | func_00337240 | 224 | non-matching (3 insns: loop count reload v1 vs v0) -> src/cod/sa_nm_00337240.c; permuter candidate | 6 | ~540s | no (hand) | 00336E88 |
| 2026-10-16T19:46:50Z | func_0032FA68 | 112 | matched -> src/cod/sa_0032fa68.c (switch on AIX tag) | 2 | ~180s | no (hand) | 0032F988 |
| 2026-10-16T19:46:50Z | func_0032FAD8 | 352 | matched -> src/cod/sa_0032fa68.c | 2 | ~360s | no (hand) | 0032F988 |
| 2026-10-16T19:46:50Z | func_00330080 | 256 | matched -> src/cod/sa_0032fa68.c | 1 | ~240s | no (hand) | 0032F988 |
| 2026-10-16T19:46:50Z | func_0032F988 | 224 | non-matching (retail keeps ra frame with inlined BE32 helpers) -> src/cod/sa_nm_0032f988.c | 3 | ~360s | no (hand) | 0032F988 |
| 2026-10-16T19:46:50Z | func_0032FC38 | 1096 | non-matching (control flow matches; regalloc: out/n/i/ret spilled in retail) -> src/cod/sa_nm_0032f988.c | 4 | ~900s | no (hand) | 0032F988 |

BATCH 38: 6 matched (func_00336E88, func_00336F48, func_00337320, func_0032FA68, func_0032FAD8, func_00330080), reseed 47s elf=OK overlay=OK, 2026-10-16T19:46:50Z.
| 2026-10-16T19:53:35Z | func_0037C330 | 88 | matched -> src/cod/sa_0037c330.c (sn) | 1 | ~60s | no (hand) | 0037C330 |
| 2026-10-16T19:53:35Z | func_0037C388 | 152 | matched -> src/cod/sa_0037c330.c (do-while index loop) | 3 | ~240s | no (hand) | 0037C330 |
| 2026-10-16T19:53:35Z | func_0037C420 | 156 | matched -> src/cod/sa_0037c330.c (do-while, separate i/ptr) | 2 | ~120s | no (hand) | 0037C330 |
| 2026-10-16T19:53:35Z | func_00354D80 | 48 | matched -> src/cod/sa_00354d80.c (cygnus; early return 0) | 3 | ~180s | no (hand) | 00354D80 |
| 2026-10-16T19:53:35Z | func_0036C080 | 36 | matched -> src/cod/sa_0036c080.c (cygnus; store order reversed by sched) | 2 | ~90s | no (hand) | 0036C080 |
| 2026-10-16T19:53:35Z | func_0034CCB0 | 52 | matched -> src/cod/sa_0034ccb0.c (cygnus; 64-bit hi + zext carry) | 4 | ~240s | no (hand) | 0034CCB0 |
| 2026-10-16T19:53:35Z | func_0035A7A0 | 36 | non-matching (3 insns: v1/a2 swap) -> src/cod/sa_nm_0035a7a0.c | 6 | ~240s | no (hand) | 0035A7A0 |
| 2026-10-16T19:53:35Z | func_00342E50 | 44 | non-matching (4 insns: const schedule order) -> src/cod/sa_nm_0035a7a0.c | 6 | ~240s | no (hand) | 00342E50 |
| 2026-10-16T19:53:35Z | func_003BAFD0 | 12 | hard-tail: C matches (ee-2.9-991111) but carving drops relocs of trailing data D_003BAFE4 -> reseed BAD; bisected out, blocklisted | 1 | ~300s | no (hand) | 003BAFD0 |
| 2026-10-16T19:53:35Z | func_0033C768 | 56 | hard-tail: symbol starts with previous function's epilogue (addiu sp; nop) | 0 | ~30s | no | 0033C768 |

BATCH 39: 6 matched (func_0037C330, func_0037C388, func_0037C420, func_00354D80, func_0036C080, func_0034CCB0), first reseed elf=BAD (func_003BAFD0 trailing-data relocs) -> removed, reseed 35s elf=OK overlay=OK, 2026-10-16T19:53:35Z.
| 2026-10-16T20:00:36Z | func_00338788 | 64 | matched -> src/cod/sa_00338788.c (cygnus-2.96 drop-reorder; clamp after cfg check) | 2 | ~150s | no (hand) | 00338788 |
| 2026-10-16T20:00:36Z | func_00327D48 | 68 | matched -> src/cod/sa_00338788.c (dead long result local blocks sibcall) | 5 | ~420s | no (hand) | 00327D48 |
| 2026-10-16T20:00:36Z | func_00337B80 | 72 | matched -> src/cod/sa_00338788.c | 1 | ~90s | no (hand) | 00337B80 |
| 2026-10-16T20:00:36Z | func_00355490 | 72 | matched -> src/cod/sa_00338788.c (i + pointer walk) | 3 | ~240s | no (hand) | 00355490 |
| 2026-10-16T20:00:36Z | func_0033CE98 | 80 | matched -> src/cod/sa_00338788.c | 1 | ~90s | no (hand) | 0033CE98 |
| 2026-10-16T20:00:36Z | func_0036E2B8 | 80 | matched -> src/cod/sa_00338788.c | 1 | ~90s | no (hand) | 0036E2B8 |
| 2026-10-16T20:00:36Z | func_00347908 | 96 | matched -> src/cod/sa_00347908.c | 1 | ~60s | no (hand) | 00347908 |
| 2026-10-16T20:00:36Z | func_002BA7B8 | 92 | matched -> src/cod/sa_002ba7b8.c (sn; vtable delta thunks) | 1 | ~120s | no (hand) | 002BA7B8 |
| 2026-10-16T20:00:36Z | func_00345250 | 84 | non-matching (regalloc) -> src/cod/sa_nm_00345250.c | 4 | ~300s | no (hand) | 00345250 |
| 2026-10-16T20:00:36Z | func_00354B40 | 84 | non-matching (2 insns: loop store order) -> src/cod/sa_nm_00345250.c | 2 | ~180s | no (hand) | 00354B40 |
| 2026-10-16T20:00:36Z | func_0033E5C0 | 88 | non-matching (1 insn: bne vs bnel) -> src/cod/sa_nm_00345250.c | 2 | ~150s | no (hand) | 0033E5C0 |
| 2026-10-16T20:00:36Z | func_00356E98 | 88 | non-matching (1 insn: sltiu vs xori) -> src/cod/sa_nm_00345250.c | 4 | ~240s | no (hand) | 00356E98 |

BATCH 40: 8 matched (func_00338788, func_00327D48, func_00337B80, func_00355490, func_0033CE98, func_0036E2B8, func_00347908, func_002BA7B8), reseed 37s elf=OK overlay=OK, 2026-10-16T20:00:36Z.
| 2026-10-16T20:02:10Z | func_00337240 | 224 | matched -> src/cod/sa_00336e88.c (permuter: memset-like callee must return void*, i.e. real memset prototype) | 6+perm | ~600s+perm | no (hand) | 00336E88 |

BATCH 40 addendum: permuter result func_00337240 integrated, reseed 35s elf=OK overlay=OK, 2026-10-16T20:02:10Z.
| 2026-10-16T20:48:14Z | func_0036DCE8 | 44 | non-matching (loop folded; retail keeps it) -> src/cod/sa_nm_0036dce8.c | 3 (parked) | 178s | clone func_003312B8 | 0036DCE8 |
| 2026-10-16T20:48:14Z | func_001DEFC8 | 128 | matched -> src/cod/sa_001defc8.c | 1 | 18s | clone PanelObj_setCursorMode | 001DEFC8 |
| 2026-10-16T20:48:14Z | func_002981D8 | 156 | matched -> src/cod/sa_002981d8.c | 1 | 22s | clone CostumeObj_applyPartMeshes | 002981D8 |
| 2026-10-16T20:48:14Z | func_00164140 | 116 | matched -> src/cod/sa_00164140.c (hand from listing) | 1 | 17s | clone func_00383690 (shape only) | 00164140 |
| 2026-10-16T20:48:14Z | func_003B9E10 | 76 | non-matching (counter in a0 vs v0) -> src/cod/sa_nm_003b9e10.c | 3 (parked) | 27s | clone ResetBufferOnFirstEnterA | 003B9E10 |
| 2026-10-16T20:48:14Z | func_0036CA68 | 60 | matched -> src/cod/sa_0036ca68.c | 1 | 17s | clone func_0035FEA8 | 0036CA68 |
| 2026-10-16T20:48:14Z | func_001F5478 | 152 | matched -> src/cod/sa_001f5478.c | 1 | 19s | clone SetUiIdWorkDispRange | 001F5478 |
| 2026-10-16T20:48:14Z | func_00328BB0 | 124 | non-matching (final clear address rebuilt) -> src/cod/sa_nm_00328bb0.c | 3 (parked) | 50s | clone func_00332958 | 00328BB0 |
| 2026-10-16T20:48:14Z | func_001F8810 | 140 | non-matching (.p2align 3 pad nop; needs -ffast-math TU) -> src/cod/sa_nm_001f8810.c | 3 (parked) | 168s | clone func_001F8550 | 001F8810 |
| 2026-10-16T20:48:14Z | func_00279838 | 148 | matched -> src/cod/sa_00279838.c (case 0 step+1 so cse reuses the compare constant) | 5 | 92s | clone cEm00_stepFadeOutAndRelease | 00279838 |

BATCH 41: 6 matched (func_001DEFC8, func_002981D8, func_00164140, func_0036CA68, func_001F5478, func_00279838), 4 parked NM, reseed 35s elf=OK overlay=OK, 2026-10-16T20:48:14Z. Times are wall-clock from sa_try attempt logs.
| 2026-10-16T20:57:41Z | func_002F7D88 | 168 | matched -> src/cod/sa_002f7d88.c | 1 | 15s | clone func_002E3500 | 002F7D88 |
| 2026-10-16T20:57:41Z | func_003813C8 | 176 | matched -> src/cod/sa_003813c8.c (index*size + self, then items offset) | 2 | 29s | clone func_00383EB0 | 003813C8 |
| 2026-10-16T20:57:41Z | func_001F3D38 | 184 | matched -> src/cod/sa_001f3d38.c | 2 | 37s | clone ColiseumBattle_StepEnter | 001F3D38 |
| 2026-10-16T20:57:41Z | func_00285EB8 | 192 | matched -> src/cod/sa_00285eb8.c (char/short accesses; struct types change alias sets) | 5 | 68s | clone UpdateActionTable | 00285EB8 |
| 2026-10-16T20:57:41Z | func_001D6030 | 196 | matched -> src/cod/sa_001d6030.c | 1 | 25s | clone BlackJack_slidePanel | 001D6030 |
| 2026-10-16T20:57:41Z | EmitterAllKill | 204 | matched -> src/cod/sa_emitterallkill.c | 1 | 19s | clone Esp_killByGroup | EmitterAllKill |
| 2026-10-16T20:57:41Z | func_003395F8 | 204 | matched -> src/cod/sa_003395f8.c (single return of e) | 2 | 34s | clone SJMEM_Create | 003395F8 |
| 2026-10-16T20:57:41Z | func_001616A8 | 212 | matched -> src/cod/sa_001616a8.c | 1 | 20s | clone IdDispObj_construct | 001616A8 |
| 2026-10-16T20:57:41Z | func_001816E8 | 220 | non-matching (4 insns, tail schedule) -> src/cod/sa_nm_001816e8.c; permuter running | 6 | 98s | clone func_0017D488 (barriers removed) | 001816E8 |
| 2026-10-16T20:57:41Z | func_001F4840 | 228 | matched -> src/cod/sa_001f4840.c | 1 | 18s | clone BlackJackId_SetDefaultDisp | 001F4840 |

BATCH 42: 9 matched (func_002F7D88, func_003813C8, func_001F3D38, func_00285EB8, func_001D6030, EmitterAllKill, func_003395F8, func_001616A8, func_001F4840), 1 NM near-miss (func_001816E8, permuter), reseed 37s elf=OK overlay=OK, 2026-10-16T20:57:41Z.
| 2026-10-16T20:58:37Z | func_001816E8 | 220 | matched -> src/cod/sa_001816e8.c (permuter hint; real fix: func_001BBF68 returns int; volatile copy source instead of asm barriers) | 8 | 229s+perm 2min | clone func_0017D488 | 001816E8 |

BATCH 42 addendum: func_001816E8 matched after permuter, registered; reseeded with batch 43.
| 2026-10-16T21:05:31Z | func_002FB6C8 | 228 | matched -> src/cod/sa_002fb6c8.c | 1 | 14s | clone Esp_killByGroup | 002FB6C8 |
| 2026-10-16T21:05:31Z | func_0017D6B0 | 232 | matched -> src/cod/sa_0017d6b0.c | 1 | 24s | clone UpdatePhaseWithHitCheckB | 0017D6B0 |
| 2026-10-16T21:05:31Z | func_001946E0 | 232 | matched -> src/cod/sa_001946e0.c | 1 | 19s | clone func_001895D8 | 001946E0 |
| 2026-10-16T21:05:31Z | func_00288570 | 236 | matched -> src/cod/sa_00288570.c | 1 | 17s | clone cEm00_tickPhaseTable+func_001895D8 | 00288570 |
| 2026-10-16T21:05:31Z | func_003009F8 | 236 | matched -> src/cod/sa_003009f8.c | 1 | 13s | clone ForEachSlotRunHandler | 003009F8 |
| 2026-10-16T21:05:31Z | func_001F1810 | 264 | matched -> src/cod/sa_001f1810.c (fp_hazard_rules mtc1) | 2 | 27s | clone Ring_spawnPieces | 001F1810 |
| 2026-10-16T21:05:31Z | func_0018A870 | 276 | matched -> src/cod/sa_0018a870.c | 1 | 13s | clone func_001895D8 | 0018A870 |
| 2026-10-16T21:05:31Z | func_001E6A48 | 292 | matched -> src/cod/sa_001e6a48.c | 1 | 21s | clone Slot2_showLayersForMode | 001E6A48 |
| 2026-10-16T21:05:31Z | func_0019DD30 | 304 | near-miss 4 insns (tail store schedule); permuter running | 6 | 91s | clone SpawnDamageTakeVolumeE | 0019DD30 |
| 2026-10-16T21:05:31Z | func_001E4308 | 304 | matched -> src/cod/sa_001e4308.c | 1 | 15s | clone Slot2_blinkMarkSet | 001E4308 |

BATCH 43: 9 matched (func_002FB6C8, func_0017D6B0, func_001946E0, func_00288570, func_003009F8, func_001F1810, func_0018A870, func_001E6A48, func_001E4308) + func_001816E8 (batch 42 addendum), func_0019DD30 on permuter, reseed 80s elf=OK overlay=OK, 2026-10-16T21:05:31Z.
| 2026-10-16T21:06:38Z | func_0019DD30 | 304 | non-matching (tail a1-a3 materialization, phase_a_sn_288 family) -> src/cod/sa_nm_0019dd30.c | 7+perm | 241s+perm | clone SpawnDamageTakeVolumeE | 0019DD30 |
| 2026-10-16T21:08:24Z | func_0019DD30 | 304 | matched -> src/cod/sa_0019dd30.c (func_001C28A0 takes only self, returns int; the 4-arg prototypes were wrong) | 8 | 360s | clone SpawnDamageTakeVolumeE | 0019DD30 |
| 2026-10-16T21:48:31Z | func_001932D8 | 288 | matched -> src/cod/sa_001932d8.c (order_search over 7 volume stores) | 2 | 190s | template sa_0019dd30 + order_search, no m2c | 001932D8 |
| 2026-10-16T21:48:31Z | func_0019BF10 | 288 | matched -> src/cod/sa_0019bf10.c | 1 | 4s | fam_gen from sa_001932d8, no m2c | 0019BF10 |
| 2026-10-16T21:48:31Z | func_0019E7A8 | 288 | matched -> src/cod/sa_0019e7a8.c | 1 | 4s | fam_gen from sa_001932d8, no m2c | 0019E7A8 |
| 2026-10-16T21:48:31Z | func_0019EF18 | 288 | matched -> src/cod/sa_0019ef18.c | 1 | 4s | fam_gen from sa_001932d8, no m2c | 0019EF18 |
| 2026-10-16T21:48:31Z | func_001A3B80 | 284 | matched -> src/cod/sa_001a3b80.c | 1 | 2s | fam_gen from sa_001932d8, no m2c | 001A3B80 |
| 2026-10-16T21:48:31Z | func_0019ECA0 | 288 | matched -> src/cod/sa_0019eca0.c (two tail order searches) | 3 | 78s | fam_gen + order_search, no m2c | 0019ECA0 |
| 2026-10-16T21:48:31Z | func_001A0478 | 288 | matched -> src/cod/sa_001a0478.c | 1 | 52s | fam_tail order_search, no m2c | 001A0478 |
| 2026-10-16T21:48:31Z | func_0018EAF8 | 300 | matched -> src/cod/sa_0018eaf8.c (3 constants) | 1 | 182s | fam_build (body+tail order_search), no m2c | 0018EAF8 |
| 2026-10-16T21:48:31Z | func_00187838 | 288 | matched -> src/cod/sa_00187838.c | 1 | ~200s | fam_build, no m2c | 00187838 |
| 2026-10-16T21:48:31Z | func_00188DE0 | 300 | matched -> src/cod/sa_00188de0.c | 1 | ~200s | fam_build, no m2c | 00188DE0 |
| 2026-10-16T21:48:31Z | func_00191B98 | 300 | matched -> src/cod/sa_00191b98.c | 1 | ~200s | fam_build, no m2c | 00191B98 |
| 2026-10-16T21:48:31Z | func_00192A98 | 300 | matched -> src/cod/sa_00192a98.c | 1 | ~200s | fam_build, no m2c | 00192A98 |
| 2026-10-16T21:48:31Z | func_00193050 | 300 | matched -> src/cod/sa_00193050.c | 1 | ~200s | fam_build, no m2c | 00193050 |
| 2026-10-16T21:48:31Z | func_0016FD68 | 224 | matched -> src/cod/sa_0016fd68.c (cylinder volume, tail order_search) | 3 | 182s | hand from listing + template, no m2c | 0016FD68 |
| 2026-10-16T21:48:31Z | func_00170050 | 224 | matched -> src/cod/sa_00170050.c | 1 | 135s | from sa_0016fd68 + order_search, no m2c | 00170050 |
| 2026-10-16T21:48:31Z | func_00170338 | 224 | matched -> src/cod/sa_00170338.c (exact clone of 00170050) | 1 | 1s | copy, no m2c | 00170338 |
| 2026-10-16T21:48:31Z | func_00178E18 | 316 | non-matching (0x5F4/0x5F6 store order, 2 insns) -> src/cod/sa_nm_00178e18.c | 3 | 393s | fam_build + 2 order searches, parked | 00178E18 |
| 2026-10-16T21:48:31Z | func_00182690 | 392 | non-matching (slot kept in v0 vs a0, 25 insns) -> src/cod/sa_nm_00182690.c; CreateDamageGive group parked | 3 | 38s+probes | hand from listing, parked | 00182690 |
| 2026-10-16T21:48:31Z | func_003BAFD0 | 12 | C matches, but carving drops relocs of following D_003BAFE4 table (reseed 44 ELF BAD) -> src/cod/sa_nm_003bafd0.c, unregistered | 2 | 12s | clone func_003A09F0 | 003BAFD0 |
| 2026-10-16T21:48:31Z | func_00381EA0 | 116 | matched -> src/cod/sa_00381ea0.c | 1 | 17s | clone func_00383690 | 00381EA0 |
| 2026-10-16T21:48:31Z | func_003397C8 | 124 | matched -> src/cod/sa_003397c8.c | 2 | 26s | clone func_00338EC8 | 003397C8 |
| 2026-10-16T21:48:31Z | func_00347C80 | 136 | near-miss 4 insns (arg setup schedule); permuter running | 3 | 46s | clone func_003504A0 | 00347C80 |
| 2026-10-16T21:48:31Z | func_00349988 | 164 | matched -> src/cod/sa_00349988.c | 1 | 16s | clone func_003245B0 | 00349988 |
| 2026-10-16T21:48:31Z | func_00393FD8 | 172 | matched -> src/cod/sa_00393fd8.c | 1 | 23s | clone func_003945C0 | 00393FD8 |
| 2026-10-16T21:48:31Z | func_003944E8 | 212 | matched -> src/cod/sa_003944e8.c | 1 | ~90s | clone func_003945C0 | 003944E8 |
| 2026-10-16T21:48:31Z | func_001F07C0 | 176 | matched -> src/cod/sa_001f07c0.c | 1 | ~60s | clone ArenaEm_stepWave | 001F07C0 |
| 2026-10-16T21:48:31Z | func_001F1C50 | 176 | matched -> src/cod/sa_001f07c0.c | 1 | ~10s | clone ArenaEm_stepWave | 001F1C50 |
| 2026-10-16T21:48:31Z | func_0013CF20 | 144 | matched -> src/cod/sa_0013cf20.c | 1 | 17s | clone func_0013EBA0 | 0013CF20 |
| 2026-10-16T21:48:31Z | VanishEffect | 164 | matched -> src/cod/sa_vanisheffect.c | 1 | 15s | clone KillEffect_306168 | VanishEffect |
| 2026-10-16T21:48:31Z | func_00122C48 | 208 | matched -> src/cod/sa_00122c48.c | 1 | 19s | clone func_00285EB8 | 00122C48 |
| 2026-10-16T21:48:31Z | func_0011A820 | 216 | matched -> src/cod/sa_0011a820.c | 1 | ~40s | clone func_00285EB8 | 0011A820 |

BATCH 44: 27 matched + func_0019DD30 (batch 43 match) linked; func_003BAFD0 unregistered after reseed 44a ELF BAD (bisected to the D_003BAFE4 pointer table after it); 2 NM (func_00178E18, func_00182690); func_00347C80 on permuter. Reseed 44b 109s elf=OK overlay=OK, 2026-10-16T21:48:31Z. New tools: build/sa/order_search.py, fam_gen.py, fam_tail.py, fam_build.py.

| 2026-10-16T22:02:44Z | func_00193800 | 312 | matched -> src/cod/sa_00193800.c | 1 | 1s | fam_build, no m2c | 00193800 |
| 2026-10-16T22:02:44Z | func_00193A80 | 316 | matched -> src/cod/sa_00193a80.c | 1 | 1s | fam_build, no m2c | 00193A80 |
| 2026-10-16T22:02:44Z | func_00193D08 | 316 | matched -> src/cod/sa_00193d08.c | 1 | 0s | fam_build, no m2c | 00193D08 |
| 2026-10-16T22:02:44Z | func_001ADC38 | 280 | matched -> src/cod/sa_001adc38.c | 1 | 25s | clone ModeDispatch, no m2c | 001ADC38 |
| 2026-10-16T22:02:44Z | func_001B92F0 | 312 | matched -> src/cod/sa_001b92f0.c | 1 | 21s | clone ModeDispatch, no m2c | 001B92F0 |
| 2026-10-16T22:02:44Z | func_001867E8 | 344 | matched -> src/cod/sa_001867e8.c | 1 | 36s | door clone, no m2c | 001867E8 |
| 2026-10-16T22:02:44Z | func_0018EF58 | 348 | matched -> src/cod/sa_0018ef58.c | 1 | 1s | door clone, no m2c | 0018EF58 |
| 2026-10-16T22:02:44Z | func_0019C3D0 | 348 | matched -> src/cod/sa_0019c3d0.c | 1 | 1s | door clone, no m2c | 0019C3D0 |
| 2026-10-16T22:02:44Z | func_0019D3F0 | 348 | matched -> src/cod/sa_0019d3f0.c | 1 | 1s | door clone, no m2c | 0019D3F0 |
| 2026-10-16T22:02:44Z | func_0017E8D8 | 356 | matched -> src/cod/sa_0017e8d8.c | 1 | 1s | clone DoorBoxObj, no m2c | 0017E8D8 |
| 2026-10-16T22:02:44Z | func_0017F320 | 356 | matched -> src/cod/sa_0017f320.c | 1 | 1s | clone DoorBoxObj, no m2c | 0017F320 |
| 2026-10-16T22:02:44Z | func_003820C0 | 340 | matched (permuter p++;p--; reg priority) -> src/cod/sa_003820c0.c | 7 | 301s | clone + permuter, no m2c | 003820C0 |
| 2026-10-16T22:02:44Z | func_001790B0 | 456 | matched -> src/cod/00179e40.c (-fno-gcse TU) | 1 | 93s | clone, no m2c | 001790B0 |
| 2026-10-16T22:02:44Z | func_002C3500 | 444 | matched -> src/cod/sa_002c3500.c | 2 | 38s | clone cScenario_move, no m2c | 002C3500 |
| 2026-10-16T22:02:44Z | func_001DC798 | 564 | matched -> src/cod/sa_001dc798.c | 1 | 25s | clone poker tbl, no m2c | 001DC798 |
| 2026-10-16T22:02:44Z | func_00347C80 | 152 | non-matching 4 insns, permuter 30m no win -> src/cod/sa_nm_00347c80.c | 3 | 46s | clone, parked | 00347C80 |
| 2026-10-16T22:02:44Z | func_00298F88 | 332 | non-matching 65 insns (hi-half hoisting) -> src/cod/sa_nm_00298f88.c | 2 | 220s | clone, parked | 00298F88 |
| 2026-10-16T22:02:44Z | func_00192270 | 568 | non-matching 54 insns (cb*half folded) -> src/cod/sa_nm_00192270.c | 2 | 92s | clone, parked | 00192270 |
| 2026-10-16T22:02:44Z | func_00182690 | 392 | retry with -fno-gcse: still 25 insns; CreateDamageGive group (incl. func_00187D88) stays parked | 4 | probes | hand, parked | 00182690 |
| 2026-10-16T22:02:44Z | func_0030E660 | 1688 | deferred: clone sceGsExecStoreImage built by different compiler (sq vs sd), large | 0 | 0s | none | 0030E660 |

BATCH 45: 15 matched; 3 NM (func_00347C80, func_00298F88, func_00192270). Reseed 45 125s elf=OK overlay=OK, 2026-10-16T22:02:44Z.

| 2026-10-16T22:36:22Z | func_0019A808 | 300 | matched -> src/cod/sa_0019a808.c | 1 | 1s | fam_build, no m2c | 0019A808 |
| 2026-10-16T22:36:22Z | func_002C9B10 | 124 | matched -> src/cod/sa_002c9b10.c | 1 | 12s | m2c | 002C9B10 |
| 2026-10-16T22:36:22Z | func_00124FD8 | 148 | matched -> src/cod/sa_00124fd8.c (InRange inline from 00124c30.c) | 1 | 20s | m2c + existing helper | 00124FD8 |
| 2026-10-16T22:36:22Z | func_0013E6E0 | 140 | matched -> src/cod/sa_0013e6e0.c (long widening for lw+dsrl, recipe from 0013c950.c) | 1 | 48s | m2c | 0013E6E0 |
| 2026-10-16T22:36:22Z | func_002CA6B0 | 132 | matched -> src/cod/sa_002ca6b0.c (same long widening) | 2 | 416s | m2c | 002CA6B0 |
| 2026-10-16T22:36:22Z | func_0032ECD8 | 132 | matched -> src/cod/sa_0032ecd8.c (cygnus --drop-reorder) | 3 | 98s | m2c | 0032ECD8 |
| 2026-10-16T22:36:22Z | func_0034C930 | 112 | matched -> src/cod/sa_0034c930.c (drop-reorder, two-step base pointer) | 4 | 735s | hand | 0034C930 |
| 2026-10-16T22:36:22Z | func_003482C8 | 132 | matched -> src/cod/sa_003482c8.c (drop-reorder) | 2 | 46s | m2c | 003482C8 |
| 2026-10-16T22:36:22Z | func_001FCEB0 | 152 | matched -> src/cod/sa_001fceb0.c (inline Copy3) | 1 | 14s | m2c | 001FCEB0 |
| 2026-10-16T22:36:22Z | func_003427F0 | 128 | matched -> src/cod/sa_003427f0.c (drop-reorder, 11 args); stale inbox_nm stub retired | 2 | 43s | m2c | 003427F0 |
| 2026-10-16T22:36:22Z | func_0017B568 | 132 | matched -> src/cod/sa_0017b568.c (vtable call + Copy3) | 1 | 37s | m2c | 0017B568 |
| 2026-10-16T22:36:22Z | func_001BFF68 | 132 | matched -> src/cod/sa_001bff68.c | 1 | 38s | m2c | 001BFF68 |
| 2026-10-16T22:36:22Z | func_002AF380 | 140 | matched -> src/cod/sa_002af380.c (while(1) form) | 3 | 116s | m2c | 002AF380 |
| 2026-10-16T22:36:22Z | func_0019A0B8 | 296 | non-matching 2 insns (shared-7 store order) -> src/cod/sa_nm_0019a0b8.c | 5 | ~330s (7-stmt order search 208s + variants) | fam_build + order search, parked | 0019A0B8 |
| 2026-10-16T22:36:22Z | func_0019A328 | 288 | non-matching 2 insns (same as 0019A0B8) -> src/cod/sa_nm_0019a328.c | 0 | 0s | fam_build transplant | 0019A328 |
| 2026-10-16T22:36:22Z | func_0019A590 | 288 | non-matching 2 insns (same as 0019A0B8) -> src/cod/sa_nm_0019a590.c | 0 | 0s | fam_build transplant | 0019A590 |
| 2026-10-16T22:36:22Z | func_001C3C58 | 136 | non-matching (nop pair, likely assembler) -> src/cod/sa_nm_001c3c58.c | 3 | 60s | hand, parked | 001C3C58 |
| 2026-10-16T22:36:22Z | func_0034C890 | 112 | non-matching after 6 attempts -> src/cod/sa_nm_0034c890.c | 6 | 794s | hand, parked | 0034C890 |
| 2026-10-16T22:36:22Z | func_0035A968 | 112 | non-matching 2 insns -> src/cod/sa_nm_0035a968.c; permuter running | 2 | 47s | m2c, parked | 0035A968 |
| 2026-10-16T22:36:22Z | func_003278E8 | 124 | non-matching 9 insns (epilogue split) -> src/cod/sa_nm_003278e8.c | 1 | 20s | clone 00327890, parked | 003278E8 |
| 2026-10-16T22:36:22Z | func_0031A6B0 | 120 | skip: cvt.w.s (precheck now flags SKIP cvtws) | 1 | 14s | m2c, skipped | 0031A6B0 |
| 2026-10-16T22:36:22Z | func_00350BE8 | 132 | non-matching 20 insns -> src/cod/sa_nm_00350be8.c | 4 | 52s | m2c, parked | 00350BE8 |

BATCH 46: 13 matched; 8 NM; 1 cvtws skip. Reseed 46 123s elf=OK overlay=OK, 2026-10-16T22:36:22Z. sa_precheck.py: SKIP cvtws verdict + lw+dsrl recipe note. Permuter func_00178E18: no valid win (best changed an offset).
| 2026-10-16T22:59:19Z | func_00327E88 | 116 | matched -> src/cod/sa_00327e88.c | 3 | 63s | m2c | 00327E88 |
| 2026-10-16T22:59:19Z | func_003BA900 | 116 | matched -> src/cod/sa_003ba900.c (cygnus --drop-reorder) | 4 | 41s | m2c | 003BA900 |
| 2026-10-16T22:59:19Z | func_0015EAC8 | 408 | matched -> src/cod/sa_0015eac8.c (as=sn for dli chains; regs[14] header) | 4 | 126s | m2c + hand | 0015EAC8 |
| 2026-10-16T22:59:19Z | func_0019BCA0 | 280 | matched -> src/cod/sa_0019bca0.c | 0 | shared fam_build run (~90 min wall, background) | fam_build | 0019BCA0 |
| 2026-10-16T22:59:19Z | func_0019DAA8 | 300 | matched -> src/cod/sa_0019daa8.c | 0 | shared fam_build run | fam_build | 0019DAA8 |
| 2026-10-16T22:59:19Z | func_0019E2A8 | 300 | matched -> src/cod/sa_0019e2a8.c | 0 | shared fam_build run | fam_build | 0019E2A8 |
| 2026-10-16T22:59:19Z | func_0019E530 | 284 | matched -> src/cod/sa_0019e530.c | 0 | shared fam_build run | fam_build | 0019E530 |
| 2026-10-16T22:59:19Z | func_0019FF90 | 288 | matched -> src/cod/sa_0019ff90.c | 0 | shared fam_build run | fam_build | 0019FF90 |
| 2026-10-16T22:59:19Z | func_001A0208 | 276 | matched -> src/cod/sa_001a0208.c | 0 | shared fam_build run | fam_build | 001A0208 |
| 2026-10-16T22:59:19Z | func_001A06F0 | 288 | matched -> src/cod/sa_001a06f0.c | 0 | shared fam_build run | fam_build | 001A06F0 |
| 2026-10-16T22:59:19Z | func_001A0968 | 276 | matched -> src/cod/sa_001a0968.c | 0 | shared fam_build run | fam_build | 001A0968 |
| 2026-10-16T22:59:19Z | func_00161990 | 416 | matched -> src/cod/sa_00161990.c (as=sn; PadState struct global; signed/unsigned ternary clamp) | 3 | 79s | m2c + hand | 00161990 |
| 2026-10-16T22:59:19Z | func_002B4028 | 348 | non-matching 41 insns (movz vs branch) -> src/cod/sa_nm_002b4028.c (as=sn) | 7 | 456s | m2c + hand, parked | 002B4028 |
| 2026-10-16T22:59:19Z | func_001F6A80 | 120 | non-matching 17 insns (cursor reload in backward scan) -> src/cod/sa_nm_001f6a80.c | 2 | 41s | m2c, parked | 001F6A80 |
| 2026-10-16T22:59:19Z | func_00164238 | 448 | non-matching 11 insns (0xFFFF const CSEs with -1 or emits 2-word dli) -> src/cod/sa_nm_00164238.c (as=sn) | 4 | 83s + 4 constant variants | m2c + hand, parked | 00164238 |
| 2026-10-16T22:59:19Z | func_0015E708 | 432 | deferred (dli; larger sibling of 00161990, retry with the PadState recipe) | 0 | 0s | none | 0015E708 |
| 2026-10-16T22:59:19Z | classFADE_start | 380 | skip: -O0 TU (needs per-TU -O0 flags, not approved) | 0 | 0s | precheck | classFADE_start |
| 2026-10-16T22:59:19Z | strlen | 324 | skip: MMI library code | 0 | 0s | precheck | strlen |
| 2026-10-16T22:59:19Z | memchr | - | skip: MMI library code | 0 | 0s | precheck | memchr |

BATCH 47: 12 matched (2 via the new as=sn route); 3 NM; 1 deferred; 3 skips. Reseed 47a (as=sn) and 47b (2026-10-16T22:59:19Z, 40s) elf=OK overlay=OK. Permuter func_0019A0B8: best 120, no win; permuter now retired from this agent (NM closer owns it), none left in godhand-nix. NM handoff: scripts/sa/nm_handoff.py + progress/nm_solved/README.md; 0 handoffs this batch. NM queue cleanup (scripts/sa/nm_prune.py): 41 stale or duplicate unregistered NM files moved to progress/retired_nm/; matched blocks trimmed from batch26_nm.c and batch30_nm.c.
| 2026-10-16T23:01:00Z | func_001A0BD8 | 288 | matched -> src/cod/sa_001a0bd8.c | 0 | shared fam_build run (ended 22:55Z, 93 min wall) | fam_build | 001A0BD8 |
| 2026-10-16T23:01:00Z | func_001A3E10 | - | skip: fam_build has no template for its damage-give/collision call set | 0 | 0s | fam_build | 001A3E10 |
| 2026-10-16T23:01:00Z | func_001B22D0 | - | skip: same call-set gap as 001A3E10 | 0 | 0s | fam_build | 001B22D0 |

BATCH 47 addendum: +1 match (001A0BD8), now 13. Reseed 47c 2026-10-16T23:01:00Z elf=OK overlay=OK. Temporary build/sa symlinks removed; no tools left under build/sa.
| 2026-10-16T23:45:35Z | cOmBase_setMeshAlphaFromLayer | 92 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_setmeshalphafromlayer.c) | 0 | - | NM closer | cOmBase_setMeshAlphaFromLayer |
| 2026-10-16T23:45:35Z | func_00143B70 | 116 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/batch38_nm.c -> src/cod/sa_00143b70.c) | 0 | - | NM closer | func_00143B70 |
| 2026-10-16T23:45:35Z | func_001522C0 | 80 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001522c0.c) | 0 | - | NM closer | func_001522C0 |
| 2026-10-16T23:45:35Z | func_001582A0 | 124 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001582a0.c) | 0 | - | NM closer | func_001582A0 |
| 2026-10-16T23:45:35Z | func_001AA478 | 136 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001aa478.c) | 0 | - | NM closer | func_001AA478 |
| 2026-10-16T23:45:35Z | func_001BEB28 | 116 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001beb28.c) | 0 | - | NM closer | func_001BEB28 |
| 2026-10-16T23:45:35Z | func_001DC710 | 136 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001dc710.c) | 0 | - | NM closer | func_001DC710 |
| 2026-10-16T23:45:35Z | func_001DD6D8 | 148 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001dd6d8.c) | 0 | - | NM closer | func_001DD6D8 |
| 2026-10-16T23:45:35Z | func_001EC8A8 | 128 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001ec8a8.c) | 0 | - | NM closer | func_001EC8A8 |
| 2026-10-16T23:45:35Z | func_001F0360 | 132 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001f0360.c) | 0 | - | NM closer | func_001F0360 |
| 2026-10-16T23:45:35Z | func_001F5E90 | 100 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001f5e90.c) | 0 | - | NM closer | func_001F5E90 |
| 2026-10-16T23:45:35Z | func_00200B20 | 100 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_00200b20.c) | 0 | - | NM closer | func_00200B20 |
| 2026-10-16T23:45:35Z | func_002A4C38 | 120 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_002a4c38.c) | 0 | - | NM closer | func_002A4C38 |
| 2026-10-16T23:45:35Z | func_0032BE10 | 368 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/sa_nm_0032be10.c -> src/cod/sa_0032be10.c) | 0 | - | NM closer | func_0032BE10 |
| 2026-10-16T23:45:35Z | func_00347FE0 | 184 | matched -> NM closer handoff, re-verified and registered (header change include/godhand/mwsfHn.h (func_00347968); 0 other units rebuilt and unchanged; cut from src/cod/sa_nm_00347e58.c -> src/cod/sa_00347fe0.c) | 0 | - | NM closer | func_00347FE0 |
| 2026-10-16T23:45:35Z | func_00356E98 | 88 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/sa_nm_00345250.c -> src/cod/sa_00356e98.c) | 0 | - | NM closer | func_00356E98 |
| 2026-10-16T23:45:35Z | func_003A7B48 | 16 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_003a7b48.c) | 0 | - | NM closer | func_003A7B48 |
| 2026-10-16T23:45:47Z | classFADE_start | 380 | matched -> src/cod/sa_classfade_start.c (per-file: c_flags_add -O0, as sn; int params + register self; second return for retail's extra epilogue jump) | 5 | 3064s on the timer, which also covered the handoff-tool work; about 15 min active | m2c listing + hand | classFADE_start |
| 2026-10-16T23:45:47Z | classFADE_kill | 56 | matched -> src/cod/classFADE.c (new unit; per-file: c_flags_add -O0, as sn) | 1 | 2s | hand | classFADE_kill |
| 2026-10-16T23:45:47Z | classFADE_status | 68 | matched -> src/cod/classFADE.c (same unit) | 2 | 16s | hand | classFADE_status |
| 2026-10-16T23:45:47Z | classFADE_setOt | 76 | matched -> src/cod/classFADE.c (same unit) | 1 | 4s | hand | classFADE_setOt |

BATCH 48 (part 1): 17 NM closer handoffs received, 17 registered, 0 rejected; one carried a header change (include/godhand/mwsfHn.h: func_00347968 drops its unused third param; no other unit uses the declaration). 4 classFADE -O0 matches. Per-file settings this batch: src/cod/sa_classfade_start.c and src/cod/classFADE.c get c_flags_add ["-O0"] + as "sn" (both new units). compile.py: "-O0" added to SUPPORTED_C_FLAG_ADDS (per-file list only; no global flag changed). match_check.py: accepts trailing ps2eeas pad words only when retail has the same nop pad before the next .align 3. Reseeds 48a (handoffs, 526s) and 48b (classFADE, 405s) elf=OK overlay=OK. Tools: nm_handoff.py handles header_changes.md (each affected unit rebuilt before and after, objects must be identical via scripts/sa/objcmp.py), meta c_flags_add/c_flags_drop, and cutting a function out of a shared NM file; sa_register.py --c-flags-add/--c-flags-drop (new units only); sa_precheck.py O0 verdict. progress/asm_fix_later.md created (8 legacy asm files; mfc0 exempt).
| 2026-10-16T23:53:25Z | func_003077B0 | 52 | matched -> src/cod/sa_003077b0.c (new unit; per-file: c_flags_add -O0, as sn; classFADE -O0 neighbour) | 1 | 32s | hand | 003077B0 |
| 2026-10-16T23:53:25Z | func_003077E8 | 88 | matched -> src/cod/sa_003077b0.c (same unit); old copy cut from batch30_nm.c | 1 | 33s | hand | 003077E8 |
| 2026-10-16T23:53:25Z | func_00307840 | 52 | matched -> src/cod/sa_003077b0.c (same unit); old copy cut from batch27_nm.c | 1 | 34s | hand | 00307840 |
| 2026-10-16T23:53:25Z | func_00307878 | 100 | non-matching 6 insns (-O0 return temp: retail keeps it in v0, plain local spills, register local reallocates) -> src/cod/sa_nm_00307878.c | 3 | 115s + 5 variants | hand, parked | 00307878 |
| 2026-10-16T23:53:25Z | func_0031CA88 | 244 | matched -> src/cod/sa_0031ca88.c (per-file: as sn for mtc1 hazard nops; VLA float[n][4]) | 2 | 42s | hand | 0031CA88 |
| 2026-10-16T23:53:15Z | func_00144B50 | 184 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_00144b50.c) | 0 | - | NM closer | func_00144B50 |
| 2026-10-16T23:53:15Z | func_001D9CA0 | 132 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001d9ca0.c) | 0 | - | NM closer | func_001D9CA0 |
| 2026-10-16T23:53:15Z | func_001DD340 | 604 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001dd340.c) | 0 | - | NM closer | func_001DD340 |
| 2026-10-16T23:53:15Z | func_001F2A88 | 156 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001f2a88.c) | 0 | - | NM closer | func_001F2A88 |
| 2026-10-16T23:53:15Z | func_001F3488 | 244 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/sa_nm_001f32a0.c -> src/cod/sa_001f3488.c) | 0 | - | NM closer | func_001F3488 |
| 2026-10-16T23:53:15Z | func_00201840 | 144 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_00201840.c) | 0 | - | NM closer | func_00201840 |
| 2026-10-16T23:53:15Z | func_0028E068 | 116 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_0028e068.c) | 0 | - | NM closer | func_0028E068 |
| 2026-10-16T23:53:15Z | func_00331110 | 236 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/sa_nm_00331070.c -> src/cod/sa_00331110.c) | 0 | - | NM closer | func_00331110 |

BATCH 48 (part 2): 4 matched, 1 NM; 8 more NM closer handoffs received, 8 registered, 0 rejected (batch 48 total: 25 received, 25 registered, 0 rejected). Per-file settings: src/cod/sa_003077b0.c c_flags_add ["-O0"] + as "sn"; src/cod/sa_0031ca88.c as "sn" (new units). Reseeds 48c (86s) and 48d (87s) elf=OK overlay=OK. sa_precheck.py: O0 verdict skips dynamic-alloca frame pointers (subu $sp, reg); new note for mtc1+nop hazard pairs (812 retail functions, 470 not yet in C). nm_handoff.py reads -O0 from an NM header.
| 2026-10-17T00:08:00Z | func_002F6B40 | 120 | matched -> src/cod/sa_002f6b40.c (new unit; per-file: as sn for mtc1 hazard nops; Copy3 inline helper) | 1 | 38s | m2c + hand | func_002F6B40 |
| 2026-10-17T00:08:00Z | func_002EC310 | 132 | matched -> src/cod/sa_002ec310.c (new unit; default as) | 1 | 43s | m2c + hand | func_002EC310 |
| 2026-10-17T00:08:00Z | func_0013DF70 | 156 | non-matching 17 insns (element pointer built in v0 and copied to s0 in retail; ours allocates s0 directly) -> src/cod/sa_nm_0013df70.c | 3 | 57s | m2c + hand, parked | func_0013DF70 |
| 2026-10-17T00:08:00Z | func_00373A78 | 164 | matched -> src/cod/sa_00373a78.c (new unit; indexed float array puts the pointer init after the guard) | 2 | 63s | m2c + hand | func_00373A78 |
| 2026-10-17T00:08:00Z | func_003735E0 | 172 | matched -> src/cod/sa_003735e0.c (new unit; callee prototype param order fixes the argument setup) | 2 | 40s | m2c + hand | func_003735E0 |
| 2026-10-17T00:08:00Z | func_002C31D0 | 176 | non-matching 24 insns, 40 words vs 44 (retail loops have three nops between the compare and bc1tl) -> src/cod/sa_nm_002c31d0.c | 1 | 19s | hand, parked early: not a C-level difference | func_002C31D0 |
| 2026-10-17T00:08:00Z | func_00270D00 | 176 | non-matching 7 insns, FP register naming only (inline Absf helper gives retail's separate abs temp) -> src/cod/sa_nm_00270d00.c | 6 | 103s | m2c + hand, parked | func_00270D00 |
| 2026-10-17T00:08:00Z | func_001573C8 | 196 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/sa_nm_001573c8.c -> src/cod/sa_001573c8.c) | 0 | - | NM closer | func_001573C8 |
| 2026-10-17T00:08:00Z | func_001A2630 | 144 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_001a2630.c) | 0 | - | NM closer | func_001A2630 |
| 2026-10-17T00:08:00Z | func_001CD7A8 | 88 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/batch30_nm.c -> src/cod/sa_001cd7a8.c); its solved.c also defined func_003077E8 (already registered in sa_003077b0.c), which broke the 48f link; duplicate removed by hand, function re-verified, reseed re-run OK | 0 | - | NM closer | func_001CD7A8 |
| 2026-10-17T00:08:00Z | func_001EA1A8 | 80 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/batch29_nm.c -> src/cod/sa_001ea1a8.c) | 0 | - | NM closer | func_001EA1A8 |
| 2026-10-17T00:08:00Z | func_003278E8 | 100 | matched -> NM closer handoff, re-verified and registered (cygnus-2.96, drop-reorder; -> src/cod/sa_003278e8.c) | 0 | - | NM closer | func_003278E8 |
| 2026-10-17T00:08:00Z | func_003526D0 | 192 | matched -> NM closer handoff, re-verified and registered (cygnus-2.96; cut from src/cod/sa_nm_003525f0.c -> src/cod/sa_003526d0.c) | 0 | - | NM closer | func_003526D0 |
| 2026-10-17T00:08:00Z | BlackJack_UpdateNewRound | 132 | matched -> NM closer handoff, re-verified and registered (-> src/cod/sa_updatenewround.c) | 0 | - | NM closer | BlackJack_UpdateNewRound |

BATCH 48 (part 3): 4 matched, 3 NM; 7 NM closer handoffs received, 7 registered, 0 rejected (batch 48 total: 32 received, 32 registered, 0 rejected). Per-file settings: src/cod/sa_002f6b40.c as "sn" (new unit). Reseed 48e (own matches, 79s) OK. Reseed 48f first failed to link (ELF missing): duplicate func_003077E8 from the func_001CD7A8 handoff. The duplicate was removed and the rerun was elf=OK overlay=OK (69s). 48g (BlackJack_UpdateNewRound, 133s) elf=OK overlay=OK. nm_handoff.py now rejects a solved file that defines any non-static function besides its target; README updated to match.
| 2026-10-17T00:25:25Z | func_002EA9F0 | 180 | matched -> src/cod/sa_002ea9f0.c (new unit; default as; first sum kept in a local for the first compare) | 1 | 53s | m2c + hand | func_002EA9F0 |
| 2026-10-17T00:25:25Z | func_0030B090 | 184 | non-matching 39 insns (retail keeps &D_00747A2C and that minus 0x58C as two live bases; ours anchors negative offsets at -0x8000) -> src/cod/sa_nm_0030b090.c | 3 | 139s | m2c + hand, parked | func_0030B090 |
| 2026-10-17T00:25:25Z | func_0031CB80 | 188 | matched -> src/cod/sa_0031cb80.c (new unit; per-file: as sn for mtc1 hazard nops; float[4][4] quad, z + 65528) | 1 | 41s | m2c + hand (0031CA88 neighbour) | func_0031CB80 |
| 2026-10-17T00:25:25Z | func_002EFB68 | 192 | matched -> src/cod/sa_002efb68.c (new unit; D_005CAFF0 is a pointer variable) | 2 | 73s | m2c + hand | func_002EFB68 |
| 2026-10-17T00:25:25Z | func_001B4460 | 200 | matched -> src/cod/sa_001b4460.c (new unit; per-file: as sn; unsigned timer for the u32->float pattern) | 1 | 109s | m2c + hand | func_001B4460 |
| 2026-10-17T00:25:25Z | Turn_dest_dir | 216 | non-matching 1 insn (final neg.s reads d instead of the copied spd) -> src/cod/sa_nm_turn_dest_dir.c | 6 | 79s | m2c + hand, parked | Turn_dest_dir |
| 2026-10-17T00:25:25Z | func_001C26B8 | 216 | non-matching 15 insns (copy-then-abs FP register pattern, yaw arg load order) -> src/cod/sa_nm_001c26b8.c | 3 | 79s | m2c + hand, parked | func_001C26B8 |
| 2026-10-17T00:25:25Z | func_002DB7E0 | 216 | non-matching 24 insns (same copy-then-abs pattern as 00270D00/001C26B8) -> src/cod/sa_nm_002db7e0.c | 3 | 101s | m2c + hand, parked | func_002DB7E0 |
| 2026-10-17T00:25:25Z | func_002C9E78 | 220 | non-matching 34 insns (stack struct matches; retail loads fields straight into arg regs) -> src/cod/sa_nm_002c9e78.c | 3 | 79s | m2c + hand, parked | func_002C9E78 |
| 2026-10-17T00:25:25Z | func_00274150 | 228 | non-matching 14 insns (switch decision-tree halves laid out in the opposite order) -> src/cod/sa_nm_00274150.c | 3 | 150s | m2c + hand, parked | func_00274150 |
| 2026-10-17T00:25:25Z | func_001EFFF8 | 232 | matched -> src/cod/sa_001efff8.c (new unit; default as) | 1 | 91s | m2c + hand | func_001EFFF8 |
| 2026-10-17T00:25:25Z | func_002E8210 | 232 | matched -> src/cod/sa_002e8210.c (new unit; default as) | 1 | 52s | m2c + hand | func_002E8210 |
| 2026-10-17T00:25:25Z | func_0026E6B0 | 240 | matched -> src/cod/sa_0026e6b0.c (new unit; default as; byte stores in field order) | 2 | 72s | m2c + hand | func_0026E6B0 |
| 2026-10-17T00:25:25Z | func_00374720 | 252 | non-matching 59 insns, 52 words vs 63 (retail copies self to a2, empty delay slot, recomputes &tgt per branch) -> src/cod/sa_nm_00374720.c | 3 | 122s | m2c + hand, parked | func_00374720 |
| 2026-10-17T00:25:25Z | cCoreSave_ckFightingRingClear | 72 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/batch28_nm.c -> src/cod/sa_ckfightingringclear.c) | 0 | - | NM closer | cCoreSave_ckFightingRingClear |
| 2026-10-17T00:25:25Z | func_00201250 | 64 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/batch28_nm.c -> src/cod/sa_00201250.c) | 0 | - | NM closer | func_00201250 |
| 2026-10-17T00:25:25Z | func_002B4F38 | 64 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/batch28_nm.c -> src/cod/sa_002b4f38.c) | 0 | - | NM closer | func_002B4F38 |
| 2026-10-17T00:25:25Z | func_002BDF30 | 76 | matched -> NM closer handoff, re-verified and registered (meta as sn; cut from src/cod/batch29_nm.c -> src/cod/sa_002bdf30.c) | 0 | - | NM closer | func_002BDF30 |
| 2026-10-17T00:25:25Z | func_002D5AD8 | 88 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/batch30_nm.c -> src/cod/sa_002d5ad8.c) | 0 | - | NM closer | func_002D5AD8 |

BATCH 49: 7 matched, 7 NM; 5 NM closer handoffs received, 5 registered, 0 rejected. Per-file settings: src/cod/sa_0031cb80.c and src/cod/sa_001b4460.c as "sn"; src/cod/sa_002bdf30.c as "sn" from the handoff meta (all new units). Reseed 49a (73s) elf=OK overlay=OK. Recurring blocker noted in three NM headers: retail copies an FP result to a fresh register before building its absolute value (00270D00, 001C26B8, 002DB7E0). VU0 functions 0030A650/0030A700/0030A7B8 skipped (VU0 macro instructions).
| 2026-10-17T00:36:24Z | func_0031C950 | 264 | matched -> src/cod/sa_0031c950.c (new unit; per-file: as sn; both line ends from (x0, y0)) | 1 | 11s | hand (0031CA88 neighbour) | func_0031C950 |
| 2026-10-17T00:36:24Z | func_0031B2E0 | 304 | matched -> src/cod/sa_0031b2e0.c (new unit; default as) | 1 | 27s | m2c + hand | func_0031B2E0 |
| 2026-10-17T00:36:24Z | func_0037CCE0 | 316 | matched -> src/cod/sa_0037cce0.c (new unit; per-file: as sn) | 1 | 50s | m2c + hand | func_0037CCE0 |
| 2026-10-17T00:36:24Z | func_00271148 | 332 | non-matching 8 insns (copy-then-abs FP register pattern, 4th function with it) -> src/cod/sa_nm_00271148.c | 3 | 86s | m2c + hand, parked | func_00271148 |
| 2026-10-17T00:36:24Z | func_002B0908 | 332 | matched -> src/cod/sa_002b0908.c (new unit; per-file: fp_hazard_rules mtc1, as on its twin sa_002b0a58.c; plain-code branch order flipped) | 2 | 117s | near-clone of func_002B0A58 | func_002B0908 |
| 2026-10-17T00:36:24Z | func_002AFED0 | 344 | non-matching 29 insns (goto layout + float-first callee prototype; count/n register swap left) -> src/cod/sa_nm_002afed0.c | 6 | 174s | m2c + hand, parked | func_002AFED0 |
| 2026-10-17T00:36:24Z | func_002736F8 | 76 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/batch29_nm.c -> src/cod/sa_002736f8.c) | 0 | - | NM closer | func_002736F8 |
| 2026-10-17T00:36:24Z | func_0030FB20 | 80 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/batch29_nm.c -> src/cod/sa_0030fb20.c) | 0 | - | NM closer | func_0030FB20 |
| 2026-10-17T00:36:24Z | func_00345250 | 84 | matched -> NM closer handoff, re-verified and registered (cygnus-2.96, drop-reorder; cut from src/cod/sa_nm_00345250.c -> src/cod/sa_00345250.c) | 0 | - | NM closer | func_00345250 |
| 2026-10-17T00:36:24Z | func_00350BE8 | 108 | matched -> NM closer handoff, re-verified and registered (cygnus-2.96, drop-reorder; -> src/cod/sa_00350be8.c) | 0 | - | NM closer | func_00350BE8 |

BATCH 50: 4 matched, 2 NM; 4 NM closer handoffs received, 4 registered, 0 rejected. Per-file settings (all new units): src/cod/sa_0031c950.c and src/cod/sa_0037cce0.c as "sn"; src/cod/sa_002b0908.c fp_hazard_rules "mtc1". Reseed 50a (114s) elf=OK overlay=OK. nm_handoff.py: standalone handoffs now carry fp_hazard_rules (meta.json key or "fp_hazard_rules X" in the NM header) through to registration; README updated.
| 2026-10-17T01:14:33Z | func_00306D18 | 288 | non-matching 64 insns, 70 words vs 72 (loop shapes match; retail keeps w in s1/tail in s0, reloads t.x for the z copy) -> src/cod/sa_nm_00306d18.c | 3 | 115s | m2c + hand, parked | func_00306D18 |
| 2026-10-17T01:14:33Z | func_00129430 | 328 | matched -> src/cod/sa_00129430.c (new unit; per-file: as sn) | 1 | 22s | m2c + hand | func_00129430 |
| 2026-10-17T01:14:33Z | func_002F4EB8 | 356 | matched -> src/cod/sa_002f4eb8.c (new unit; per-file: as sn; signed char divisor gives the copied break-check register; tmpl re-read through self) | 4 | 94s | m2c + hand | func_002F4EB8 |
| 2026-10-17T01:14:33Z | func_002B00A0 | 360 | non-matching 66 insns, same size (vertex/uv store schedule and FP register naming) -> src/cod/sa_nm_002b00a0.c | 3 | 87s | m2c + hand (002B1300 sibling), parked | func_002B00A0 |
| 2026-10-17T01:14:33Z | cDoor_getJumpData | 364 | matched -> src/cod/sa_cdoor_getjumpdata.c (new unit; per-file: as sn; uses include/godhand/cDoor.h; ternary for the 0xFFFF id; unk3A stored last) | 4 | 97s | m2c + hand | cDoor_getJumpData |
| 2026-10-17T01:14:33Z | func_00298A78 | 376 | matched -> src/cod/sa_00298a78.c (new unit; per-file: as sn; twin of sa_002981d8.c) | 1 | 50s | m2c + hand (002981D8 sibling) | func_00298A78 |
| 2026-10-17T01:14:33Z | func_0026A3D8 | 380 | non-matching (motion range test folded to one range check; sway reload before abs) -> src/cod/sa_nm_0026a3d8.c | 3 | 83s | m2c + hand (cOl1b_setCloseFix hold idiom), parked | func_0026A3D8 |
| 2026-10-17T01:14:33Z | func_002BDC00 | 396 | matched -> src/cod/sa_002bdc00.c (new unit; per-file: as sn) | 1 | 26s | m2c + hand | func_002BDC00 |
| 2026-10-17T01:14:33Z | func_00164238 | 448 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_00164238.c (cut from src/cod/sa_nm_00164238.c; uses padState.h)) | 0 | - | NM closer | func_00164238 |
| 2026-10-17T01:14:33Z | func_001C2280 | 132 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_001c2280.c) | 0 | - | NM closer | func_001C2280 |
| 2026-10-17T01:14:33Z | func_001FFEB8 | 116 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_001ffeb8.c) | 0 | - | NM closer | func_001FFEB8 |
| 2026-10-17T01:14:33Z | func_002AC538 | 120 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_002ac538.c) | 0 | - | NM closer | func_002AC538 |
| 2026-10-17T01:14:33Z | func_0035EB60 | 56 | matched -> NM closer handoff, re-verified and registered (src/cod/0035e8.c (NON_MATCHING block replaced in place; unit already drops reorder)) | 0 | - | NM closer | func_0035EB60 |

BATCH 51: 5 matched, 3 NM; 5 NM closer handoffs received, 5 registered, 0 rejected. Per-file settings (all new units): as "sn" on src/cod/sa_00129430.c, sa_002f4eb8.c, sa_cdoor_getjumpdata.c, sa_00298a78.c, sa_002bdc00.c. nm_handoff.py fix: meta drop_reorder is now compared with the unit's c_flags_drop (it wrongly rejected func_0035EB60 on the first pass). Reseed 51a: elf=OK overlay=OK (90 s).
| 2026-10-17T01:30:39Z | func_0037ACA0 | 100 | matched -> src/cod/sa_0037aca0.c (new unit; default as) | 1 | 21s | hand | func_0037ACA0 |
| 2026-10-17T01:30:39Z | func_002C3058 | 104 | non-matching 24 words vs 26 (retail reloads the link word and copies it in the loop-back delay slot) -> src/cod/sa_nm_002c3058.c | 3 | 103s | m2c + hand, parked | func_002C3058 |
| 2026-10-17T01:30:39Z | func_003BA370 | 104 | non-matching 25 words vs 26 (goto loop shape; retail rematerialises 0xB per iteration) -> src/cod/sa_nm_003ba370.c | 3 | 73s | m2c + hand, parked | func_003BA370 |
| 2026-10-17T01:30:39Z | func_00360AA8 | 112 | matched -> src/cod/sa_00360aa8.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; volatile countdown global) | 1 | 29s | m2c + hand | func_00360AA8 |
| 2026-10-17T01:30:39Z | func_00368A28 | 112 | non-matching 18 insns, same size (switch tail-merge matches; result register and movn differ) -> src/cod/sa_nm_00368a28.c | 3 | 118s | m2c + hand, parked | func_00368A28 |
| 2026-10-17T01:30:39Z | func_00383E40 | 112 | matched -> src/cod/sa_00383e40.c (new unit; default as; sub-struct pointer at 0x370) | 2 | 28s | m2c + hand | func_00383E40 |
| 2026-10-17T01:30:39Z | func_00140DE0 | 116 | matched -> src/cod/sa_00140de0.c (new unit; default as; vtable slot 3 call) | 1 | 30s | m2c + hand | func_00140DE0 |
| 2026-10-17T01:30:39Z | func_003498E8 | 116 | matched -> src/cod/sa_003498e8.c (new unit; cygnus-2.96; twin of sa_00349988.c) | 1 | 41s | near-clone of func_00349988 | func_003498E8 |
| 2026-10-17T01:30:39Z | func_00365D18 | 116 | non-matching 15 insns, same size (load schedule only) -> src/cod/sa_nm_00365d18.c | 6 | 150s | m2c + hand, parked | func_00365D18 |
| 2026-10-17T01:30:39Z | func_00378AE0 | 120 | matched -> src/cod/sa_00378ae0.c (new unit; default as; twin of func_0037ACA0) | 1 | 29s | near-clone of func_0037ACA0 | func_00378AE0 |
| 2026-10-17T01:30:39Z | SetT2 | 112 | skip: privileged (mfc0/mtc0/di/eret), added to build/sa/handwritten.txt | 0 | - | - | SetT2 |
| 2026-10-17T01:30:39Z | cObjBaseArray_SearchOM | 108 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_searchom.c) | 0 | - | NM closer | cObjBaseArray_SearchOM |
| 2026-10-17T01:30:39Z | func_00150418 | 152 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_00150418.c) | 0 | - | NM closer | func_00150418 |
| 2026-10-17T01:30:39Z | func_002D0B88 | 136 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_002d0b88.c (cut from src/cod/sa_nm_002d0b88.c)) | 0 | - | NM closer | func_002D0B88 |

BATCH 52: 6 matched, 4 NM, 1 skip; 3 NM closer handoffs received, 3 registered, 0 rejected. Per-file settings (new unit): src/cod/sa_00360aa8.c -freorder-blocks dropped. Candidate source switched to never-carved functions (the decomp queue generator now finds nothing: progress/report.json no longer lists functions). Reseed 52a: elf=OK overlay=OK.
| 2026-10-17T01:39:08Z | func_003461B0 | 120 | matched -> src/cod/sa_003461b0.c (new unit; cygnus-2.96; &D_00458147[1] address form) | 1 | 28s | m2c + hand | func_003461B0 |
| 2026-10-17T01:39:08Z | func_00306F10 | 120 | matched -> src/cod/sa_00306f10.c (new unit; sn, default as; base local assigned after the range check) | 3 | 63s | m2c + hand | func_00306F10 |
| 2026-10-17T01:39:08Z | func_00357280 | 120 | matched -> src/cod/sa_00357280.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 1 | 76s | m2c + hand | func_00357280 |
| 2026-10-17T01:39:08Z | func_00358688 | 120 | matched -> src/cod/sa_00358688.c (new unit; cygnus-2.96; stores in field order c0, c8, d0, d8, dc) | 2 | 67s | m2c + hand | func_00358688 |
| 2026-10-17T01:39:08Z | func_00368CE8 | 120 | non-matching 25 insns, same size (state-byte load order, lui/addiu address, hang-loop alignment nops) -> src/cod/sa_nm_00368ce8.c | 3 | 101s | m2c + hand, parked | func_00368CE8 |
| 2026-10-17T01:39:08Z | func_003774A8 | 120 | matched -> src/cod/sa_003774a8.c (new unit; per-file: as sn; int index loop gives the signed slt compare) | 2 | 79s | m2c + hand | func_003774A8 |
| 2026-10-17T01:39:08Z | func_0037D1A8 | 120 | non-matching 28 words vs 30 (retail splits the id compare into its own block with hazard nops) -> src/cod/sa_nm_0037d1a8.c | 4 | 91s | m2c + hand, parked | func_0037D1A8 |
| 2026-10-17T01:39:08Z | func_0037D310 | 120 | matched -> src/cod/sa_0037d310.c (new unit; per-file: as sn; entry address computed from base + i inside the loop) | 3 | 112s | m2c + hand | func_0037D310 |
| 2026-10-17T01:39:08Z | func_00170F60 | 156 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_00170f60.c) | 0 | - | NM closer | func_00170F60 |
| 2026-10-17T01:39:08Z | func_001E3758 | 256 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_001e3758.c) | 0 | - | NM closer | func_001E3758 |

BATCH 53: 6 matched, 2 NM; 2 NM closer handoffs received, 2 registered, 0 rejected. Per-file settings (new units): src/cod/sa_00357280.c -freorder-blocks dropped; as "sn" on src/cod/sa_003774a8.c and sa_0037d310.c. func_003A93F8 (strstr) deferred to batch 54. Reseed 53a: elf=OK overlay=OK (105 s).
| 2026-10-17T01:55:38Z | func_003A93F8 | 116 | non-matching (strstr; every instruction matches except two retail nops at the outer loop head that no allowed compiler/as emits) -> src/cod/sa_nm_003a93f8.c | 5 | 698s | m2c + hand, parked | func_003A93F8 |
| 2026-10-17T01:55:38Z | func_00380E10 | 120 | matched -> src/cod/sa_00380e10.c (new unit; default as; obj/res read through a slot sub-struct at +0x10 gives the +0x58 base) | 3 | 52s | m2c + hand | func_00380E10 |
| 2026-10-17T01:55:38Z | func_00386640 | 120 | matched -> src/cod/sa_00386640.c (new unit; default as; signed char counter; clamp written as if (n < 0) n = 0) | 3 | 72s | m2c + hand | func_00386640 |
| 2026-10-17T01:55:38Z | func_00344D98 | 124 | matched -> src/cod/sa_00344d98.c (new unit; cygnus-2.96; int-typed out fields keep the store after the loads) | 3 | 70s | m2c + hand | func_00344D98 |
| 2026-10-17T01:55:38Z | func_002948E8 | 128 | non-matching 29 words vs 32 (retail keeps the id range test as a 0/1 flag with signed slti; C folds it) -> src/cod/sa_nm_002948e8.c | 3 | 67s | m2c + hand, parked | func_002948E8 |
| 2026-10-17T01:55:38Z | func_002D3110 | 128 | matched -> src/cod/sa_002d3110.c (new unit; per-file: as sn; single return with the head test around the loop) | 2 | 35s | m2c + hand | func_002D3110 |
| 2026-10-17T01:55:38Z | func_00324440 | 128 | matched -> src/cod/sa_00324440.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 2 | 54s | m2c + hand | func_00324440 |
| 2026-10-17T01:55:38Z | func_00342988 | 128 | matched -> src/cod/sa_00342988.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; hang loop) | 2 | 46s | m2c + hand | func_00342988 |
| 2026-10-17T01:55:38Z | func_00348D58 | 128 | matched -> src/cod/sa_00348d58.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 2 | 47s | m2c + hand | func_00348D58 |
| 2026-10-17T01:55:38Z | func_00360200 | 128 | non-matching 30 words vs 32 (layout matches; alignment nop, bnel delay-slot duplicate, prologue order) -> src/cod/sa_nm_00360200.c | 3 | 78s | m2c + hand, parked | func_00360200 |
| 2026-10-17T01:55:38Z | func_00149378 | 132 | matched -> src/cod/sa_00149378.c (new unit; per-file: as sn) | 1 | 17s | m2c + hand | func_00149378 |
| 2026-10-17T01:55:38Z | func_00279E78 | 132 | matched -> src/cod/sa_00279e78.c (new unit; default as; Copy3 inline from sa_002f6b40.c) | 1 | 41s | m2c + hand | func_00279E78 |
| 2026-10-17T01:55:38Z | func_00171B70 | 172 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_00171b70.c) | 0 | - | NM closer | func_00171B70 |
| 2026-10-17T01:55:38Z | func_0017C508 | 168 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_0017c508.c) | 0 | - | NM closer | func_0017C508 |
| 2026-10-17T01:55:38Z | func_001BD1A0 | 136 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_001bd1a0.c) | 0 | - | NM closer | func_001BD1A0 |
| 2026-10-17T01:55:38Z | func_0031D3D0 | 644 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_0031d3d0.c) | 0 | - | NM closer | func_0031D3D0 |
| 2026-10-17T01:55:38Z | func_002CA5D8 | 184 | rejected NM closer handoff: matches only with the wrapper arg --call-loop-pad (not a per-file setting); 44 words vs 46 with real options. Stays NM in src/cod/sa_nm_002ca5d8.c | 0 | - | NM closer | func_002CA5D8 |

BATCH 54: 9 matched, 3 NM (incl. func_003A93F8 carried from batch 53); 5 NM closer handoffs received, 4 registered, 1 rejected (func_002CA5D8, wrapper arg). Per-file settings (new units): as "sn" on src/cod/sa_002d3110.c and sa_00149378.c; -freorder-blocks dropped on src/cod/sa_00324440.c, sa_00342988.c, sa_00348d58.c. README: wrapper args are not accepted. Reseed 54a: elf=OK overlay=OK (89 s).
| 2026-10-17T02:09:50Z | func_002B33D8 | 132 | matched -> src/cod/sa_002b33d8.c (new unit; default as; both flag bits tested as (((unsigned long)t >> N) & 1UL) ==/!= 1UL) | 2 | 59s | m2c + hand | func_002B33D8 |
| 2026-10-17T02:09:50Z | func_002B47C8 | 132 | matched -> src/cod/sa_002b47c8.c (new unit; default as; cut frame fetched into a local before the int->float compare) | 2 | 46s | m2c + hand | func_002B47C8 |
| 2026-10-17T02:09:50Z | func_0032A900 | 132 | matched -> src/cod/sa_0032a900.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped, as sn; int pan; clamp tested < -15 then > 15) | 3 | 95s | m2c + hand | func_0032A900 |
| 2026-10-17T02:09:50Z | func_0035A620 | 132 | matched -> src/cod/sa_0035a620.c (new unit; per-file: cygnus-2.96, as sn) | 1 | 42s | m2c + hand | func_0035A620 |
| 2026-10-17T02:09:50Z | func_0036DD18 | 132 | matched -> src/cod/sa_0036dd18.c (new unit; cygnus-2.96; store order chosen so the scheduler output matches: the last store of each value register is hoisted) | 2 | 66s | m2c + hand | func_0036DD18 |
| 2026-10-17T02:09:50Z | func_003780F8 | 132 | non-matching 31 words vs 33 (store tails cross-jumped; retail keeps a jr ra per branch) -> src/cod/sa_nm_003780f8.c | 3 | 62s | m2c + hand, parked | func_003780F8 |
| 2026-10-17T02:09:50Z | func_00384B10 | 132 | matched -> src/cod/sa_00384b10.c (new unit; default as) | 1 | 19s | m2c + hand | func_00384B10 |
| 2026-10-17T02:09:50Z | func_001DCE68 | 136 | non-matching same size, 15 insns (hi - (lo - 1) folding and rotated s0-s2) -> src/cod/sa_nm_001dce68.c | 3 | 70s | m2c + hand, parked | func_001DCE68 |
| 2026-10-17T02:09:50Z | func_002DB978 | 136 | matched -> src/cod/sa_002db978.c (new unit; default as) | 1 | 15s | m2c + hand | func_002DB978 |
| 2026-10-17T02:09:50Z | func_0030A200 | 136 | matched -> src/cod/sa_0030a200.c (new unit; default as) | 1 | 42s | m2c + hand | func_0030A200 |
| 2026-10-17T02:09:50Z | func_00332A60 | 136 | non-matching same size, 3 insns (lui/lw/addiu schedule) -> src/cod/sa_nm_00332a60.c | 6 | 100s | m2c + hand, parked (tool suggested permuter; not used) | func_00332A60 |
| 2026-10-17T02:09:50Z | func_00312DB8 | 208 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_00312db8.c) | 0 | - | NM closer | func_00312DB8 |
| 2026-10-17T02:09:50Z | func_0032C1E0 | 200 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_0032c1e0.c) | 0 | - | NM closer | func_0032C1E0 |

BATCH 55: 8 matched, 3 NM; 2 NM closer handoffs received, 2 registered, 0 rejected. Per-file settings (new units): src/cod/sa_0032a900.c -freorder-blocks dropped + as "sn"; src/cod/sa_0035a620.c as "sn". Reseed 55a: elf=OK overlay=OK (114 s).
| 2026-10-17T02:20:32Z | func_002B8D88 | 136 | non-matching 32 words vs 34 (retail copies a/b into t1/t0 and rebuilds self + 0x1C per branch) -> src/cod/sa_nm_002b8d88.c | 3 | 56s | m2c + hand, parked | func_002B8D88 |
| 2026-10-17T02:20:32Z | func_00320948 | 136 | non-matching same size, 25 insns (loop and layout match; retail copies i into a2 at entry) -> src/cod/sa_nm_00320948.c | 3 | 42s | m2c + hand, parked | func_00320948 |
| 2026-10-17T02:20:32Z | func_00340A60 | 136 | non-matching same size, 24 insns (clamp shape matches; rate moved into a0 at entry, xori 0 test) -> src/cod/sa_nm_00340a60.c | 4 | 69s | m2c + hand, parked | func_00340A60 |
| 2026-10-17T02:20:32Z | func_00359F78 | 136 | matched -> src/cod/sa_00359f78.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped, as sn; handle array referenced as its own symbol D_003EE2C4) | 2 | 25s | near-clone of func_0035A620 | func_00359F78 |
| 2026-10-17T02:20:32Z | func_001FD580 | 140 | matched -> src/cod/sa_001fd580.c (new unit; per-file: as sn; head local for the entry test, re-read for the call and the loop test) | 3 | 61s | m2c + hand | func_001FD580 |
| 2026-10-17T02:20:32Z | func_00298EF8 | 140 | non-matching same size, 13 insns (a1/v1 swap between idx and the id variable) -> src/cod/sa_nm_00298ef8.c | 6 | 117s | m2c + hand, parked | func_00298EF8 |
| 2026-10-17T02:20:32Z | func_002A71F0 | 140 | matched -> src/cod/sa_002a71f0.c (new unit; default as; flag test written ((x & 0x201) ^ 1) == 0 so 1 is not hoisted) | 2 | 24s | m2c + hand | func_002A71F0 |
| 2026-10-17T02:20:32Z | func_002B6370 | 140 | matched -> src/cod/sa_002b6370.c (new unit; default as; unsigned 0xFFFFFFFE mask gives lui/ori) | 1 | 39s | m2c + hand | func_002B6370 |
| 2026-10-17T02:20:32Z | func_001D5E08 | 328 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_001d5e08.c) | 0 | - | NM closer | func_001D5E08 |

BATCH 56: 4 matched, 4 NM; 1 NM closer handoff received, 1 registered, 0 rejected. Per-file settings (new units): src/cod/sa_00359f78.c -freorder-blocks dropped + as "sn"; src/cod/sa_001fd580.c as "sn". func_001365B8 (HAND VU0) left for a VU0 pass. Reseed 56a: elf=OK overlay=OK (104 s).
| 2026-10-17T02:29:47Z | func_0033B5C8 | 140 | matched -> src/cod/sa_0033b5c8.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 2 | 53s | m2c + hand | func_0033B5C8 |
| 2026-10-17T02:29:47Z | func_00349EF0 | 140 | non-matching same size, 2 insns (a3 = &used / a0 = self delay-slot order after the first call) -> src/cod/sa_nm_00349ef0.c | 4 | 83s | m2c + hand, parked | func_00349EF0 |
| 2026-10-17T02:29:47Z | func_00350C78 | 140 | matched -> src/cod/sa_00350c78.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped, as sn) | 2 | 25s | m2c + hand | func_00350C78 |
| 2026-10-17T02:29:47Z | func_00356F48 | 140 | non-matching 38 words vs 35 (constant 1 CSE'd into s2 across the call; retail rematerialises it) -> src/cod/sa_nm_00356f48.c | 3 | 164s | m2c + hand, parked | func_00356F48 |
| 2026-10-17T02:29:47Z | func_00356FD8 | 140 | non-matching 38 words vs 35 (case bodies 2, 1, 0 into a shared call match; retail dispatches with a linear beq/beql/bne chain and copies hn/mode at entry) -> src/cod/sa_nm_00356fd8.c | 3 | 63s | m2c + hand, parked | func_00356FD8 |
| 2026-10-17T02:29:47Z | func_001DB440 | 280 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_001db440.c) | 0 | - | NM closer | func_001DB440 |
| 2026-10-17T02:29:47Z | func_0030B698 | 144 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_0030b698.c) | 0 | - | NM closer | func_0030B698 |
| 2026-10-17T02:29:47Z | func_00322F80 | 124 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_00322f80.c) | 0 | - | NM closer | func_00322F80 |

BATCH 57: 2 matched, 3 NM; 3 NM closer handoffs received, 3 registered, 0 rejected (none used header_changes or c_flags). Per-file settings (new units): src/cod/sa_0033b5c8.c -freorder-blocks dropped; src/cod/sa_00350c78.c -freorder-blocks dropped + as "sn". Reseed 57a: elf=OK overlay=OK (68 s).
| 2026-10-17T02:43:45Z | func_0013DE90 | 144 | non-matching same size, 30 insns (dtor array loop: allocation rotated, shared skip target, nop placement) -> src/cod/sa_nm_0013de90.c | 3 | 57s | m2c + hand, parked | func_0013DE90 |
| 2026-10-17T02:43:45Z | func_002AC650 | 144 | matched -> src/cod/sa_002ac650.c (new unit; default as; interpolation factor fetched before the key loads) | 1 | 13s | m2c + hand | func_002AC650 |
| 2026-10-17T02:43:45Z | func_002D3050 | 144 | matched -> src/cod/sa_002d3050.c (new unit; default as) | 1 | 12s | m2c + hand | func_002D3050 |
| 2026-10-17T02:43:45Z | func_0030CAA0 | 144 | matched -> src/cod/sa_0030caa0.c (new unit; default as; D_007476C0[-4] for the lw -0x10 off the materialised address) | 1 | 39s | m2c + hand | func_0030CAA0 |
| 2026-10-17T02:43:45Z | func_00358F68 | 144 | matched -> src/cod/sa_00358f68.c (new unit; cygnus-2.96; separate early "return 0" for the already-state-1 path fixes the v0/ld epilogue order) | 6 | 108s | m2c + hand | func_00358F68 |
| 2026-10-17T02:43:45Z | func_00360520 | 144 | non-matching 34 words vs 36 (error tail-call placed first; retail puts it after the loop epilogue) -> src/cod/sa_nm_00360520.c | 3 | 62s | m2c + hand, parked | func_00360520 |
| 2026-10-17T02:43:45Z | func_0036D1A8 | 144 | non-matching same size, 17 insns (flag load hoisted above the saves; retail reuses a0 = 4 and materialises the D_0076A588 address) -> src/cod/sa_nm_0036d1a8.c | 3 | 48s | m2c + hand, parked | func_0036D1A8 |
| 2026-10-17T02:43:45Z | func_00376370 | 144 | non-matching same size, 8 insns (a0 copy hoisted into the beq delay slot; beq vs beql) -> src/cod/sa_nm_00376370.c | 6 | 109s | m2c + hand, parked (tried -fno-gcse and ee-2.9-991111, neither kept) | func_00376370 |
| 2026-10-17T02:43:45Z | func_00376720 | 144 | non-matching same size, 19 insns (goto form gets the body exactly but inverts the loop exit) -> src/cod/sa_nm_00376720.c | 3 | 40s | m2c + hand, parked | func_00376720 |
| 2026-10-17T02:43:45Z | func_003807E0 | 144 | matched -> src/cod/sa_003807e0.c (new unit; default as; short index; table read signed for compares and unsigned for the midpoint arithmetic) | 2 | 28s | m2c + hand | func_003807E0 |
| 2026-10-17T02:43:45Z | func_0033BDD8 | 168 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_0033bdd8.c) | 0 | - | NM closer | func_0033BDD8 |
| 2026-10-17T02:43:45Z | func_0033F5B8 | 184 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_0033f5b8.c) | 0 | - | NM closer | func_0033F5B8 |

BATCH 58: 5 matched, 5 NM; 2 NM closer handoffs received, 2 registered, 0 rejected. Per-file settings (new units): none beyond the compiler choice (src/cod/sa_00358f68.c cygnus-2.96). Reseed 58a: elf=OK overlay=OK (109 s).
| 2026-10-17T02:56:03Z | func_00138CA8 | 148 | matched -> src/cod/sa_00138ca8.c (new unit; default as; self-checking vec3 assign inline + 16-byte-aligned 0x360-byte struct copy gives the lq/sq loop) | 1 | 39s | m2c + hand | func_00138CA8 |
| 2026-10-17T02:56:03Z | func_00306E38 | 148 | matched -> src/cod/sa_00306e38.c (new unit; per-file: as sn) | 1 | 38s | m2c + hand | func_00306E38 |
| 2026-10-17T02:56:03Z | __si_type_info_dcast | 148 | matched -> src/cod/sa_0031ef18.c (new unit; per-file compiler ee-2.9-991111, already used by src/cod/00376978.c; g++ 2.x vtable entry {delta, index, fn}) | 2 | 65s | m2c + hand | __si_type_info_dcast |
| 2026-10-17T02:56:03Z | func_003234D0 | 148 | non-matching same size, 10 insns (store order needs volatile; return copy scheduled early so 0x200 misses v0) -> src/cod/sa_nm_003234d0.c | 6 | 119s | m2c + hand, parked (-fno-gcse tried, not kept) | func_003234D0 |
| 2026-10-17T02:56:03Z | func_0033B978 | 148 | non-matching 36 words vs 37 (retail copies a0 at entry and builds the entry address three ways) -> src/cod/sa_nm_0033b978.c | 3 | 46s | m2c + hand, parked | func_0033B978 |
| 2026-10-17T02:56:03Z | func_00350718 | 148 | matched -> src/cod/sa_00350718.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; early returns, separate result local) | 2 | 27s | m2c + hand | func_00350718 |
| 2026-10-17T02:56:03Z | func_00351C18 | 148 | matched -> src/cod/sa_00351c18.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped, as sn; duplicated -2/-3 case bodies) | 2 | 52s | m2c + hand | func_00351C18 |
| 2026-10-17T02:56:03Z | func_00359480 | 148 | non-matching same size, 34 insns (register renames only; retail copies full into t1 at entry) -> src/cod/sa_nm_00359480.c | 3 | 77s | m2c + hand, parked | func_00359480 |
| 2026-10-17T02:56:03Z | func_00378C48 | 148 | matched -> src/cod/sa_00378c48.c (new unit; default as) | 1 | 16s | m2c + hand | func_00378C48 |
| 2026-10-17T02:56:03Z | func_003B9B20 | 148 | matched -> src/cod/sa_003b9b20.c (new unit; per-file: cygnus-2.96, as sn) | 1 | 43s | m2c + hand | func_003B9B20 |
| 2026-10-17T02:56:03Z | func_0024C0F0 | 724 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_0024c0f0.c) | 0 | - | NM closer | func_0024C0F0 |
| 2026-10-17T02:56:03Z | func_0033F4C8 | 196 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_0033f4c8.c) | 0 | - | NM closer | func_0033F4C8 |
| 2026-10-17T02:56:03Z | func_00345610 | 316 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_00345610.c) | 0 | - | NM closer | func_00345610 |

BATCH 59: 7 matched, 3 NM; 3 NM closer handoffs received, 3 registered, 0 rejected. Per-file settings (new units): src/cod/sa_00306e38.c as "sn"; src/cod/sa_0031ef18.c compiler ee-2.9-991111; src/cod/sa_00350718.c -freorder-blocks dropped; src/cod/sa_00351c18.c -freorder-blocks dropped + as "sn"; src/cod/sa_003b9b20.c as "sn". Reseed 59a: elf=OK overlay=OK (106 s).
| 2026-10-17T03:14:50Z | Motion_seq_readSpdData | 144 | non-matching 35 words vs 36 (byte-aligned ldl/sdl copy plus word-packed struct return; each form gets one half) -> src/cod/sa_nm_002c7d20.c | 3 | 67s | m2c + hand, parked | Motion_seq_readSpdData |
| 2026-10-17T03:14:50Z | func_0035DAA0 | 148 | non-matching same size, 17 insns (v0 = 1 placement before the unaligned 32-byte copy) -> src/cod/sa_nm_0035daa0.c | 3 | 46s | m2c + hand, parked | func_0035DAA0 |
| 2026-10-17T03:14:50Z | func_0012EC58 | 152 | non-matching 1 word short (identical stream except one nop retail has before the loop bnel) -> src/cod/sa_nm_0012ec58.c | 3 | 42s | m2c + hand, parked | func_0012EC58 |
| 2026-10-17T03:14:50Z | func_002017A8 | 152 | matched -> src/cod/sa_002017a8.c (new unit; per-file: as sn; both searches index-based, cDvd.h types) | 2 | 31s | m2c + hand | func_002017A8 |
| 2026-10-17T03:14:50Z | func_00260650 | 152 | matched -> src/cod/sa_00260650.c (new unit; default as; room test written (x ^ 0x211) != 0) | 1 | 30s | m2c + hand | func_00260650 |
| 2026-10-17T03:14:50Z | func_0026BAD8 | 152 | matched -> src/cod/sa_0026bad8.c (new unit; per-file: as sn; explicit max != 0 guard with the slot pointer set inside it, do-while body) | 5 | 73s | m2c + hand | func_0026BAD8 |
| 2026-10-17T03:14:50Z | func_002AE8A8 | 152 | matched -> src/cod/sa_002ae8a8.c (new unit; default as; stripped log hook func_0(cEvent_nullStr00) as in 0012bf50.c) | 1 | 50s | m2c + hand | func_002AE8A8 |
| 2026-10-17T03:14:50Z | func_003382A0 | 152 | matched -> src/cod/sa_003382a0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped, as sn; int request, positive guard form) | 3 | 46s | m2c + hand | func_003382A0 |
| 2026-10-17T03:14:50Z | func_00343D68 | 152 | matched -> src/cod/sa_00343d68.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped, as sn; two separate error calls, cross-jumped by the compiler) | 2 | 41s | m2c + hand | func_00343D68 |
| 2026-10-17T03:14:50Z | func_00358228 | 152 | matched -> src/cod/sa_00358228.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped, as sn; handle table pointer taken at entry) | 1 | 30s | m2c + hand | func_00358228 |

BATCH 60: 7 matched, 3 NM; 0 NM closer handoffs received. Per-file settings (new units): src/cod/sa_002017a8.c and sa_0026bad8.c as "sn"; src/cod/sa_003382a0.c, sa_00343d68.c, sa_00358228.c -freorder-blocks dropped + as "sn". Reseed 60a: elf=OK overlay=OK (36 s). Checkpoint cold build: PASSED (container, 273 s).
| 2026-10-17T03:23:40Z | func_00359590 | 152 | matched -> src/cod/sa_00359590.c (new unit; per-file: cygnus-2.96, default as; 16-byte item declared int[4] aligned(8) so the head/count stores may alias it and stay before the copy) | 4 | 56s | m2c + hand | func_00359590 |
| 2026-10-17T03:23:40Z | func_0035FC88 | 152 | matched -> src/cod/sa_0035fc88.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; SJCK copy on the stack for SJ_SearchTag) | 2 | 45s | m2c + hand | func_0035FC88 |
| 2026-10-17T03:23:40Z | func_00377A28 | 152 | matched -> src/cod/sa_00377a28.c (new unit; default as; seqNode.h, loop bound compared as (int) for slt) | 2 | 35s | m2c + hand | func_00377A28 |
| 2026-10-17T03:23:40Z | func_002A5B18 | 156 | matched -> src/cod/sa_002a5b18.c (new unit; default as) | 1 | 23s | m2c + hand | func_002A5B18 |
| 2026-10-17T03:23:40Z | func_002B3338 | 156 | matched -> src/cod/sa_002b3338.c (new unit; default as; while loop with break, condition written due <= now for load order) | 4 | 62s | m2c + hand | func_002B3338 |
| 2026-10-17T03:23:40Z | func_002B6420 | 156 | matched -> src/cod/sa_002b6420.c (new unit; default as) | 1 | 21s | m2c + hand | func_002B6420 |
| 2026-10-17T03:23:40Z | func_00339108 | 156 | matched -> src/cod/sa_00339108.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; len cleared before data) | 3 | 43s | m2c + hand | func_00339108 |
| 2026-10-17T03:23:40Z | func_00349590 | 156 | non-matching same size, 18 insns with -freorder-blocks dropped (retail shares the error-path return 0 with one exit and threads the other straight to the epilogue) -> src/cod/sa_nm_00349590.c | 3 | 50s | m2c + hand, parked | func_00349590 |
| 2026-10-17T03:23:40Z | func_00349E48 | 156 | matched -> src/cod/sa_00349e48.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; first exit returns the call result) | 2 | 21s | m2c + hand | func_00349E48 |
| 2026-10-17T03:23:40Z | func_003772D8 | 156 | matched -> src/cod/sa_003772d8.c (new unit; default as; switch with shared return 0, -1 when the channel is idle) | 1 | 27s | m2c + hand | func_003772D8 |

BATCH 61: 9 matched, 1 NM; 0 NM closer handoffs received. Per-file settings (new units): src/cod/sa_00359590.c compiler cygnus-2.96; src/cod/sa_0035fc88.c, sa_00339108.c, sa_00349e48.c compiler cygnus-2.96 with -freorder-blocks dropped. Reseed 61a: elf=OK overlay=OK (36 s).
| 2026-10-17T03:41:48Z | func_00378B58 | 156 | matched -> src/cod/sa_00378b58.c (new unit; default as; direct returns, both store pairs written in reverse of the emitted order) | 3 | 48s | m2c + hand | func_00378B58 |
| 2026-10-17T03:41:48Z | func_0037AB00 | 156 | matched -> src/cod/sa_0037ab00.c (new unit; default as) | 1 | 27s | m2c + hand | func_0037AB00 |
| 2026-10-17T03:41:48Z | func_003A9498 | 156 | non-matching same size, 10 insns (BSD strtok_r verbatim; one nop sits before the first delimiter-loop branch in retail and before the second loop label in ours) -> src/cod/sa_nm_003a9498.c | 3 | 72s | m2c + hand, parked (as sn and cygnus tried) | func_003A9498 |
| 2026-10-17T03:41:48Z | func_002C7850 | 160 | matched -> src/cod/sa_002c7850.c (new unit; default as) | 1 | 27s | m2c + hand | func_002C7850 |
| 2026-10-17T03:41:48Z | func_00329E08 | 160 | matched -> src/cod/sa_00329e08.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; final stores written rd, stat, eos) | 3 | 60s | m2c + hand | func_00329E08 |
| 2026-10-17T03:41:48Z | func_0032E150 | 160 | matched -> src/cod/sa_0032e150.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; stat widened to int, positive 1..3 guard; time includes a pause for the user's message) | 5 | 330s | m2c + hand | func_0032E150 |
| 2026-10-17T03:41:48Z | func_0032F178 | 160 | non-matching 39 words vs 40 (retail tail is beq i,n with v0=1/v0=0; ours always folded to xor+sltiu) -> src/cod/sa_nm_0032f178.c | 6 | 96s | m2c + hand, parked | func_0032F178 |
| 2026-10-17T03:41:48Z | func_0035FAD8 | 160 | non-matching same size, 15 insns (store scheduling only; -fno-gcse no effect) -> src/cod/sa_nm_0035fad8.c | 3 | 61s | m2c + hand, parked | func_0035FAD8 |
| 2026-10-17T03:41:48Z | func_0036D280 | 160 | matched -> src/cod/sa_0036d280.c (new unit; per-file: cygnus-2.96; work aligned in place, returns the memset result) | 4 | 59s | m2c + hand | func_0036D280 |
| 2026-10-17T03:41:48Z | func_003253C0 | 164 | non-matching same size, 3 insns (thread id test in v1 with beqz in retail, v0 with beql in ours; assert-style discarded volatile reads reproduce the extra loads) -> src/cod/sa_nm_003253c0.c | 6 | 132s | m2c + hand, parked (drop-reorder, -fno-gcse tried, not kept) | func_003253C0 |
| 2026-10-17T03:41:48Z | func_001C6A90 | 216 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_001c6a90.c) | 0 | - | NM closer | func_001C6A90 |
| 2026-10-17T03:41:48Z | func_001F50A0 | 368 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_001f50a0.c) | 0 | - | NM closer | func_001F50A0 |
| 2026-10-17T03:41:48Z | func_002CA5D8 | 184 | matched -> NM closer handoff reprocessed after the call_loop_pad clarification; re-verified with call_loop_pad and registered (src/cod/sa_002ca5d8.c, "call_loop_pad": true) | 0 | - | NM closer | func_002CA5D8 |
| 2026-10-17T03:41:48Z | func_00352888 | 532 | matched -> NM closer handoff, re-verified and registered (cut from src/cod/sa_nm_003525f0.c into src/cod/sa_00352888.c) | 0 | - | NM closer | func_00352888 |

BATCH 62: 6 matched, 4 NM; 4 NM closer handoffs received, 4 registered, 0 rejected (func_002CA5D8 was previously rejected; its rejection is superseded). Per-file settings (new units): src/cod/sa_00329e08.c, sa_0032e150.c compiler cygnus-2.96 with -freorder-blocks dropped; src/cod/sa_0036d280.c compiler cygnus-2.96; src/cod/sa_002ca5d8.c call_loop_pad (handoff). Tooling: nm_handoff.py and sa_register.py accept call_loop_pad, and both now refuse a compiler no existing unit uses or a compiler change on an existing unit. Reseed 62a (after the handoffs): elf=OK overlay=OK (114 s). Reseed 62b: elf=OK overlay=OK (78 s).

| 2026-10-17T03:43:27Z | func_00336B00 | 164 | non-matching (best 40, switch pivot (retail 0xCB, gcc 0xCD); cygnus) -> src/cod/sa_nm_00336b00.c | 3 | 70s | m2c + hand, parked | func_00336B00 |
| 2026-10-17T03:44:10Z | func_00349328 | 164 | non-matching (best 24, delay slot fill (bne vs bnel); cygnus dr) -> src/cod/sa_nm_00349328.c | 3 | 33s | m2c + hand, parked | func_00349328 |
| 2026-10-17T03:45:36Z | func_0034C2D0 | 164 | non-matching (best 9, address add/store order; cygnus dr) -> src/cod/sa_nm_0034c2d0.c | 6 | 78s | m2c + hand, parked | func_0034C2D0 |
| 2026-10-17T03:47:06Z | func_00351A08 | 164 | non-matching (best 14, s0/s1 swap and load order; cygnus dr) -> src/cod/sa_nm_00351a08.c | 6 | 78s | m2c + hand, parked | func_00351A08 |
| 2026-10-17T03:48:45Z | func_003566E8 | 164 | non-matching (best 5, v0/v1 and bnez vs bnel; cygnus dr) -> src/cod/sa_nm_003566e8.c | 6 | 83s | m2c + hand, parked | func_003566E8 |
| 2026-10-17T03:49:41Z | func_001DAE18 | 168 | non-matching (best 20, sn movz if-conversion vs branches) -> src/cod/sa_nm_001dae18.c | 3 | 44s | m2c + hand, parked | func_001DAE18 |
| 2026-10-17T03:50:32Z | func_002CA470 | 168 | matched -> src/cod/sa_002ca470.c (new unit; sn-2.95.3-136 default) | 3 | 43s | m2c + hand | func_002CA470 |
| 2026-10-17T03:50:39Z | func_003331D0 | 168 | skipped: multi-entry (alabel func_003331E0 inside) | 0 | 0s | no | func_003331D0 |
| 2026-10-17T03:51:52Z | func_00336D08 | 168 | matched -> src/cod/sa_00336d08.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 3 | 38s | m2c + hand | func_00336D08 |
| 2026-10-17T03:52:51Z | func_00344568 | 168 | matched -> src/cod/sa_00344568.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 2 | 53s | m2c + hand | func_00344568 |
| 2026-10-17T03:55:06Z | func_003454F0 | 168 | non-matching (best 7, else-path store order lets cross-jumping merge sw v0,8(a1) tails; cygnus dr) -> src/cod/sa_nm_003454f0.c | 6 | 126s | m2c + hand, parked | func_003454F0 |
| 2026-10-17T03:59:08Z | func_00155AE8 | 252 | matched -> NM closer handoff, re-verified and registered (src/cod/sa_00155ae8.c, sn-2.95.3-136) | 0 | - | NM closer | func_00155AE8 |

BATCH 63: 4 matched (3 builder + 1 handoff), 7 NM, 1 skipped (multi-entry); 1 NM closer handoff received, 1 registered, 0 rejected. Per-file settings (new units): src/cod/sa_00336d08.c, sa_00344568.c compiler cygnus-2.96 with -freorder-blocks dropped; src/cod/sa_002ca470.c sn default. Reseed 63a: rc=0 98s, elf OK, overlay OK (a first try anchored on the NM function func_003454F0 was refused by --reseed-expected with rc=1; hashes were still OK; re-run with matched anchor func_00155AE8).

| 2026-10-17T03:59:50Z | func_003475F0 | 168 | matched -> src/cod/sa_003475f0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; same tag-search shape as func_0035FC88) | 2 | 30s | m2c + hand | func_003475F0 |
| 2026-10-17T04:00:48Z | func_003490B0 | 168 | matched -> src/cod/sa_003490b0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; halfword busy test via unsigned short cast) | 2 | 51s | m2c + hand | func_003490B0 |
| 2026-10-17T04:02:49Z | func_00352008 | 168 | non-matching (best 7, cygnus dr + -fno-strict-aliasing tried, s4/s5 swap of out1 and a -> src/cod/sa_nm_00352008.c) | 6 | 114s | m2c + hand, parked | func_00352008 |
| 2026-10-17T04:03:32Z | func_0037A1F0 | 168 | matched -> src/cod/sa_0037a1f0.c (new unit; sn-2.95.3-136 default; x read before y) | 2 | 33s | m2c + hand | func_0037A1F0 |
| 2026-10-17T04:06:16Z | func_001F75D0 | 172 | non-matching (best 19 with -fno-strength-reduce tried, loop tail i++/ofs placement and s1-s3 order -> src/cod/sa_nm_001f75d0.c) | 6 | 158s | m2c + hand, parked | func_001F75D0 |
| 2026-10-17T04:08:01Z | func_002B2588 | 172 | non-matching (best 33, every insn matches except one retail pad nop before the 8-aligned loop head; call_loop_pad, as sn and ee-2.9 do not produce it -> src/cod/sa_nm_002b2588.c) | 6 | 98s | m2c + hand, parked | func_002B2588 |
| 2026-10-17T04:08:44Z | func_002D2E38 | 172 | matched -> src/cod/sa_002d2e38.c (new unit; sn-2.95.3-136 default; goto back to the step label, ++n in the loop test) | 2 | 36s | m2c + hand | func_002D2E38 |
| 2026-10-17T04:09:41Z | func_003487C0 | 172 | matched -> src/cod/sa_003487c0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; tail call) | 2 | 50s | m2c + hand | func_003487C0 |
| 2026-10-17T04:16:37Z | _rix_010 | 172 | skipped: HAND MMI | 0 | 0s | no | _rix_010 |
| 2026-10-17T04:16:37Z | _ri0_100 | 172 | skipped: HAND MMI | 0 | 0s | no | _ri0_100 |
| 2026-10-17T04:16:37Z | func_003B2850 | 172 | skipped: hand-written cache/sync loop (sceSifWriteBackDCache), not expressible in real C | 0 | 0s | no | func_003B2850 |
| 2026-10-17T04:11:56Z | func_0013D288 | 176 | non-matching (best 4, first drawPolyF argument setup order -> src/cod/sa_nm_0013d288.c) | 6 | 93s | m2c + hand, parked | func_0013D288 |
| 2026-10-17T04:13:04Z | func_002CBD10 | 176 | non-matching (best 22, branch layout (beql over b vs bnel to tail) and slot fill -> src/cod/sa_nm_002cbd10.c) | 3 | 55s | m2c + hand, parked | func_002CBD10 |
| 2026-10-17T04:16:37Z | func_0030A650 | 176 | skipped: HAND VU0 | 0 | 0s | no | func_0030A650 |
| 2026-10-17T04:13:45Z | func_0032D1A0 | 176 | matched -> src/cod/sa_0032d1a0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; discarded volatile read of D_003D1470) | 2 | 33s | m2c + hand | func_0032D1A0 |
| 2026-10-17T04:14:36Z | func_00340970 | 176 | matched -> src/cod/sa_00340970.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 2 | 44s | m2c + hand | func_00340970 |

BATCH 64: 7 matched, 5 NM, 4 skipped (2 HAND MMI, 1 HAND VU0, 1 hand-written cache asm); 0 NM closer handoffs received, 0 registered, 0 rejected. Per-file settings (new units): src/cod/sa_003475f0.c, sa_003490b0.c, sa_003487c0.c, sa_0032d1a0.c, sa_00340970.c compiler cygnus-2.96 with -freorder-blocks dropped; src/cod/sa_0037a1f0.c, sa_002d2e38.c sn default. Reseed 64a: rc=0 94s, elf OK, overlay OK.

| 2026-10-17T04:18:13Z | func_00346C58 | 176 | matched -> src/cod/sa_00346c58.c (new unit; cygnus-2.96 default; f88/f8C copied through locals). Note: an sa_register add was run by mistake after attempt 2 (score 6) and removed with sa_register remove before any build; the unit was registered again only after the attempt-3 MATCH | 3 | 91s | m2c + hand | func_00346C58 |
| 2026-10-17T04:19:45Z | func_0034E090 | 176 | non-matching (best 6, cygnus dr, table pointer in v1 instead of a0 -> src/cod/sa_nm_0034e090.c) | 6 | 149s | m2c + hand, parked | func_0034E090 |
| 2026-10-17T04:20:55Z | func_0034FB70 | 176 | non-matching (best 37, cygnus dr, obj+0x90C hoisted and split epilogue -> src/cod/sa_nm_0034fb70.c) | 3 | 59s | m2c + hand, parked | func_0034FB70 |
| 2026-10-17T04:21:54Z | func_00354A70 | 176 | matched -> src/cod/sa_00354a70.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 4 | 50s | m2c + hand | func_00354A70 |
| 2026-10-17T04:24:06Z | func_0036D0F8 | 176 | non-matching (best 1, cygnus dr, second MPV_SearchDelim takes a0 from p not buf; -fno-gcse no change -> src/cod/sa_nm_0036d0f8.c) | 6 | 125s | m2c + hand, parked | func_0036D0F8 |
| 2026-10-17T04:24:40Z | func_003B9EB0 | 176 | matched -> src/cod/sa_003b9eb0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 2 | 22s | m2c + hand | func_003B9EB0 |
| 2026-10-17T04:25:32Z | func_001DCDA8 | 180 | matched -> src/cod/sa_001dcda8.c (new unit; sn-2.95.3-136 default) | 1 | 42s | m2c + hand | func_001DCDA8 |
| 2026-10-17T04:31:07Z | func_00274E98 | 180 | skipped: HAND VU0 | 0 | 0s | no | func_00274E98 |
| 2026-10-17T04:31:07Z | func_002B5FC8 | 180 | skipped: HAND VU0 | 0 | 0s | no | func_002B5FC8 |
| 2026-10-17T04:31:07Z | func_0030A700 | 180 | skipped: HAND VU0 | 0 | 0s | no | func_0030A700 |
| 2026-10-17T04:31:07Z | func_0030A7B8 | 180 | skipped: HAND VU0 | 0 | 0s | no | func_0030A7B8 |
| 2026-10-17T04:26:26Z | func_00323AA0 | 180 | matched -> src/cod/sa_00323aa0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 2 | 46s | m2c + hand | func_00323AA0 |
| 2026-10-17T04:27:49Z | func_0032BC98 | 180 | matched -> src/cod/sa_0032bc98.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 4 | 69s | m2c + hand | func_0032BC98 |
| 2026-10-17T04:28:53Z | func_0032DBA0 | 180 | matched -> src/cod/sa_0032dba0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 3 | 56s | m2c + hand | func_0032DBA0 |

BATCH 65: 7 matched, 3 NM, 4 skipped (HAND VU0); 0 NM closer handoffs received, 0 registered, 0 rejected. Per-file settings (new units): src/cod/sa_00354a70.c, sa_003b9eb0.c, sa_00323aa0.c, sa_0032bc98.c, sa_0032dba0.c compiler cygnus-2.96 with -freorder-blocks dropped; src/cod/sa_00346c58.c cygnus default; src/cod/sa_001dcda8.c sn default. Reseed 65a: rc=0 107s, elf OK, overlay OK. Process: registration now goes through a guard that runs match_check first and refuses anything that is not MATCH (after the func_00346C58 slip above). Correction for batch 64: -fno-strict-aliasing (func_00352008) and -fno-strength-reduce (func_001F75D0) are not in compile.py SUPPORTED_C_FLAG_ADDS, so those probes could not have been registered even on a match; only -O0, -fno-align-jumps, -fno-gcse, -ffast-math, -fno-rtti, -ftrapv adds and the -freorder-blocks drop are usable.

| 2026-10-17T04:32:41Z | func_003301B0 | 180 | NM -> src/cod/sa_nm_003301b0.c (STOP at 6; best 25; cygnus dr; branch layout/sibcalls) | 6 | 89s | m2c + hand | func_003301B0 |
| 2026-10-17T04:34:14Z | func_0033A618 | 180 | NM -> src/cod/sa_nm_0033a618.c (STOP at 6; best 1; cygnus dr; retail bnel vs our bne) | 6 | 84s | m2c + hand | func_0033A618 |
| 2026-10-17T04:35:05Z | func_0034AB18 | 180 | matched -> src/cod/sa_0034ab18.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 4 | 43s | m2c + hand | func_0034AB18 |
| 2026-10-17T04:36:13Z | func_003517D0 | 180 | NM -> src/cod/sa_nm_003517d0.c (PARK at 3; best 41; cygnus dr; early index load) | 3 | 58s | m2c + hand | func_003517D0 |
| 2026-10-17T04:36:57Z | func_0035F1D0 | 180 | matched -> src/cod/sa_0035f1d0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; FrmTim padded to 0x20) | 3 | 34s | m2c + hand | func_0035F1D0 |
| 2026-10-17T04:37:50Z | func_003825A8 | 180 | matched -> src/cod/sa_003825a8.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 43s | m2c + hand | func_003825A8 |
| 2026-10-17T04:42:40Z | _rix_001 | 180 | skipped: HAND MMI | 0 | 0s | no | _rix_001 |
| 2026-10-17T04:39:05Z | func_001FE370 | 184 | NM -> src/cod/sa_nm_001fe370.c (PARK at 3; best 38; sn; likely-slot fill + loop pad) | 3 | 66s | m2c + hand | func_001FE370 |
| 2026-10-17T04:39:42Z | func_0026F200 | 184 | matched -> src/cod/sa_0026f200.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 23s | m2c + hand | func_0026F200 |
| 2026-10-17T04:40:53Z | func_002B8850 | 184 | matched -> src/cod/sa_002b8850.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 61s | m2c + hand | func_002B8850 |
| 2026-10-17T04:42:40Z | func_002BABD0 | 184 | skipped: HAND VU0 | 0 | 0s | no | func_002BABD0 |
| 2026-10-17T04:42:32Z | func_00331DB8 | 184 | NM -> src/cod/sa_nm_00331db8.c (PARK at 3; best 31; cygnus dr; const-prop of mode==1 into a3, arg hoist) | 3 | 90s | m2c + hand | func_00331DB8 |

BATCH 66: 5 matched, 5 NM, 2 skipped (1 HAND MMI, 1 HAND VU0); 5 NM closer handoffs received, 5 registered, 0 rejected (Turn_dest_dir, func_00270D00, func_00271148, func_002DB7E0, func_0030D1F8; func_0030D1F8 cut from sa_nm_0030d1f8.c). Per-file settings (new units): src/cod/sa_0034ab18.c, sa_0035f1d0.c compiler cygnus-2.96 with -freorder-blocks dropped; src/cod/sa_003825a8.c, sa_0026f200.c, sa_002b8850.c sn default. Reseed 66a (anchor func_002B8850): rc=0 248s, elf OK, overlay OK.

| 2026-10-17T04:49:31Z | func_00342E88 | 184 | NM -> src/cod/sa_nm_00342e88.c (PARK at 3; best 23; cygnus; constant reassociation of the two +0x40 terms) | 3 | 87s | m2c + hand | func_00342E88 |
| 2026-10-17T04:51:09Z | func_00344C98 | 184 | NM -> src/cod/sa_nm_00344c98.c (STOP at 6; best 7; cygnus dr; two branch polarities) | 6 | 86s | m2c + hand | func_00344C98 |
| 2026-10-17T04:52:19Z | func_00274018 | 188 | NM -> src/cod/sa_nm_00274018.c (PARK at 3; best 39; sn; movn if-conversion, loop rotation) | 3 | 62s | m2c + hand | func_00274018 |
| 2026-10-17T04:53:21Z | func_002C2078 | 188 | matched -> src/cod/sa_002c2078.c (new unit; per-file: sn-2.95.3-136 default) | 3 | 51s | m2c + hand | func_002C2078 |
| 2026-10-17T04:54:34Z | func_00330D58 | 188 | NM -> src/cod/sa_nm_00330d58.c (PARK at 4; best 39; cygnus dr; branch layout of error stubs) | 4 | 65s | m2c + hand | func_00330D58 |
| 2026-10-17T04:55:25Z | func_00340130 | 188 | matched -> src/cod/sa_00340130.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped and -fno-gcse added) | 5 | 44s | m2c + hand | func_00340130 |
| 2026-10-17T04:56:42Z | func_003556C8 | 188 | matched -> src/cod/sa_003556c8.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 4 | 44s | m2c + hand | func_003556C8 |
| 2026-10-17T04:58:16Z | func_0036C0B0 | 188 | NM -> src/cod/sa_nm_0036c0b0.c (STOP at 6, near-miss; best 2; cygnus; two scheduled insns swapped) | 6 | 87s | m2c + hand | func_0036C0B0 |
| 2026-10-17T04:58:16Z | cMotCamera_setMotion | 192 | skipped: HAND VU0 | 0 | 0s | no | cMotCamera_setMotion |
| 2026-10-17T04:59:39Z | func_00332AE8 | 192 | NM -> src/cod/sa_nm_00332ae8.c (STOP at 6, near-miss; best 3; cygnus dr; lw/lui scheduling) | 6 | 74s | m2c + hand | func_00332AE8 |
| 2026-10-17T05:02:50Z | func_0033B878 | 192 | NM -> src/cod/sa_nm_0033b878.c (PARK at 3; best 42; cygnus; second slot pointer, loop nops; ee-2.9 probe worse) | 3 | 45s | m2c + hand | func_0033B878 |
| 2026-10-17T05:00:14Z | func_003477A8 | 192 | matched -> src/cod/sa_003477a8.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 2 | 28s | m2c + hand | func_003477A8 |
| 2026-10-17T05:01:50Z | func_0034A400 | 192 | NM -> src/cod/sa_nm_0034a400.c (STOP at 6; best 16; cygnus dr; param copy order, v0/v1 swap) | 6 | 88s | m2c + hand | func_0034A400 |

BATCH 67: 4 matched, 8 NM, 1 skipped (HAND VU0); 4 NM closer handoffs received, 4 registered, 0 rejected (func_001DCE68, func_00328BB0, func_0035DAA0, func_00368A28). Per-file settings (new units): src/cod/sa_002c2078.c sn default; src/cod/sa_003556c8.c, sa_003477a8.c cygnus-2.96 with -freorder-blocks dropped; src/cod/sa_00340130.c cygnus-2.96 with -freorder-blocks dropped and -f=-fno-gcse added (both in the per-file vocabulary). func_0033B878 was also probed with ee-2.9-991111 (an existing unit compiler) but not registered. Near-misses func_0036C0B0 and func_00332AE8 were flagged by sa_try for the permuter; parked as NM instead (no permuter). Reseed 67a (anchor func_003477A8): rc=0 106s, elf OK, overlay OK.

| 2026-10-17T05:07:06Z | func_0034E3A0 | 192 | matched -> src/cod/sa_0034e3a0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 6 | 95s | m2c + hand | func_0034E3A0 |
| 2026-10-17T05:08:24Z | func_00354E08 | 192 | matched -> src/cod/sa_00354e08.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 3 | 70s | m2c + hand | func_00354E08 |
| 2026-10-17T05:09:18Z | func_0037B660 | 192 | matched -> src/cod/sa_0037b660.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 45s | m2c + hand | func_0037B660 |
| 2026-10-17T05:09:18Z | func_00137E70 | 196 | skipped: HAND VU0 | 0 | 0s | no | func_00137E70 |
| 2026-10-17T05:10:18Z | func_001468B0 | 196 | matched -> src/cod/sa_001468b0.c (new unit; per-file: sn-2.95.3-136 default) | 2 | 52s | m2c + hand | func_001468B0 |
| 2026-10-17T05:11:24Z | func_00268508 | 196 | matched -> src/cod/sa_00268508.c (new unit; per-file: sn-2.95.3-136 default) | 2 | 58s | m2c + hand | func_00268508 |
| 2026-10-17T05:13:07Z | cIDBase_transSprite | 196 | NM -> src/cod/sa_nm_002aaff0.c (parked at 2 by judgement; best 35; sn --as sn; stack-passed args that are neither float params nor by-value structs) | 2 | 17971s | m2c + hand | cIDBase_transSprite |
| 2026-10-17T05:15:41Z | func_002CB278 | 196 | NM -> src/cod/sa_nm_002cb278.c (STOP at 6; best 11; sn; cse folds the -1 constant into the find result) | 6 | 110s | m2c + hand | func_002CB278 |
| 2026-10-17T05:16:29Z | func_002D57C8 | 196 | matched -> src/cod/sa_002d57c8.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 30s | m2c + hand | func_002D57C8 |
| 2026-10-17T05:18:32Z | func_00347AF8 | 196 | NM -> src/cod/sa_nm_00347af8.c (STOP at 6; best 9; cygnus dr; s0/s1 swap) | 6 | 112s | m2c + hand | func_00347AF8 |
| 2026-10-17T05:19:46Z | func_003577A8 | 196 | matched -> src/cod/sa_003577a8.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 4 | 62s | m2c + hand | func_003577A8 |

BATCH 68: 7 matched, 3 NM, 1 skipped (HAND VU0); 2 NM closer handoffs received, 2 registered, 0 rejected (func_001DAE18, func_002CBD10; the latter replaces my batch-64 NM stub sa_nm_002cbd10.c, now removed). Per-file settings (new units): src/cod/sa_0034e3a0.c, sa_00354e08.c, sa_003577a8.c cygnus-2.96 with -freorder-blocks dropped; src/cod/sa_0037b660.c, sa_001468b0.c, sa_00268508.c, sa_002d57c8.c sn default. cIDBase_transSprite was parked after 2 attempts (sa_try said CONTINUE) because the call's stack-argument layout doesn't fit any C signature I could see. Reseed 68a (anchor func_003577A8): rc=0 111s, elf OK, overlay OK.
| 2026-10-17T05:23:36Z | func_003A92E0 | 196 | matched -> src/cod/sa_003a92e0.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 52s | m2c + hand | func_003A92E0 |
| 2026-10-17T05:26:14Z | func_002BE028 | 200 | NM -> src/cod/sa_nm_002be028.c (parked at 2 by judgement; best 28; sn + call_loop_pad; the pad nops appear in the stage-s asm but ee-as drops them when cc1 fills the jal slot itself; --as sn puts them after the branch) | 2 | 148s | m2c + hand | func_002BE028 |
| 2026-10-17T05:27:57Z | func_00337A00 | 200 | NM -> src/cod/sa_nm_00337a00.c (PARK at 3; best 40; cygnus dr; ifcvt turns the 0xBB80 select into movz, and the call-arg hoist differs) | 3 | 57s | m2c + hand | func_00337A00 |
| 2026-10-17T05:28:52Z | func_0033ABD0 | 200 | NM -> src/cod/sa_nm_0033abd0.c (PARK at 3; best 12; cygnus dr; near-miss: bne vs bnel at used!=0, plus the shared-sltiu tail) | 3 | 48s | m2c + hand | func_0033ABD0 |
| 2026-10-17T05:29:55Z | func_00359628 | 200 | NM -> src/cod/sa_nm_00359628.c (PARK at 3; best 48; cygnus dr; ring-queue span search, register allocation off by one) | 3 | 56s | m2c + hand | func_00359628 |
| 2026-10-17T05:30:20Z | func_00360878 | 200 | matched -> src/cod/sa_00360878.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 1 | 17s | m2c + hand | func_00360878 |
| 2026-10-17T05:31:35Z | func_0036C6C8 | 200 | matched -> src/cod/sa_0036c6c8.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 3 | 67s | m2c + hand | func_0036C6C8 |
| 2026-10-17T05:33:38Z | func_003B2080 | 200 | NM -> src/cod/sa_nm_003b2080.c (STOP at 6; best 2; ee-2.9-991111, as used by unit 003b2148.c; near-miss: two-insn lo/lw swap) | 6 | 115s | m2c + hand | func_003B2080 |
| 2026-10-17T05:34:11Z | func_001EB648 | 204 | matched -> src/cod/sa_001eb648.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 25s | m2c + hand | func_001EB648 |
| 2026-10-17T05:35:03Z | func_002B4960 | 204 | matched -> src/cod/sa_002b4960.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 45s | m2c + hand | func_002B4960 |

BATCH 69: 5 matched, 5 NM, 0 skipped; 4 NM closer handoffs received, 4 registered, 0 rejected (func_001F6A80, func_002B8D88, func_00360520, func_003BA370). Per-file settings (new units): src/cod/sa_003a92e0.c, sa_001eb648.c, sa_002b4960.c sn default; src/cod/sa_00360878.c, sa_0036c6c8.c cygnus-2.96 with -freorder-blocks dropped. func_003B2080 was tried with ee-2.9-991111, the compiler of the existing unit 003b2148.c, and is not registered. func_002BE028 was parked after 2 attempts (sa_try said CONTINUE) because the remaining difference is how call_loop_pad interacts with the assembler, which source changes can't fix. Reseed 69a (anchor func_002B4960): rc=0 109s, elf OK, overlay OK.
| 2026-10-17T05:39:51Z | func_002C7E30 | 204 | matched -> src/cod/sa_002c7e30.c (new unit; per-file: sn-2.95.3-136 with "as": "sn"; the 64-bit mask constants only expand the retail way under the sn assembler; returns a 4-halfword struct by value, and the memset helper is declared returning void * so the 1 lands in v1) | 5 | 109s | m2c + hand | func_002C7E30 |
| 2026-10-17T05:41:28Z | func_002D0658 | 204 | matched -> src/cod/sa_002d0658.c (new unit; per-file: sn-2.95.3-136 default) | 3 | 85s | m2c + hand | func_002D0658 |
| 2026-10-17T05:42:56Z | func_002D3BA8 | 204 | NM -> src/cod/sa_nm_002d3ba8.c (PARK at 3; best 50; sn; retail keeps an unfolded busy flag that every C form tried gets jump-threaded away) | 3 | 86s | m2c + hand | func_002D3BA8 |
| 2026-10-17T05:43:36Z | getEventObjPtr | 204 | matched -> src/cod/sa_002fa258.c (new unit; per-file: sn-2.95.3-136 default) | 2 | 32s | m2c + hand | getEventObjPtr |
| 2026-10-17T05:43:36Z | func_00305E88 | 204 | skipped: HAND VU0 | 0 | 0s | no | func_00305E88 |
| 2026-10-17T05:44:45Z | func_00331310 | 204 | matched -> src/cod/sa_00331310.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 3 | 61s | m2c + hand | func_00331310 |
| 2026-10-17T05:45:57Z | func_00346ED0 | 204 | matched -> src/cod/sa_00346ed0.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 4 | 67s | m2c + hand | func_00346ED0 |
| 2026-10-17T05:47:14Z | func_0035DB38 | 204 | matched -> src/cod/sa_0035db38.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 3 | 70s | m2c + hand | func_0035DB38 |
| 2026-10-17T05:49:21Z | func_0037A740 | 204 | matched -> src/cod/sa_0037a740.c (new unit; per-file: sn-2.95.3-136 default; the handler table takes (obj, entry)) | 4 | 119s | m2c + hand | func_0037A740 |
| 2026-10-17T05:49:21Z | _ri0_001 | 204 | skipped: HAND MMI | 0 | 0s | no | _ri0_001 |
| 2026-10-17T05:52:25Z | func_002E2800 | 208 | NM -> src/cod/sa_nm_002e2800.c (STOP at 6; best 7; sn; near-miss: the flag-word reload is scheduled ahead of the timer sb) | 6 | 171s | m2c + hand | func_002E2800 |

BATCH 70: 7 matched, 2 NM, 2 skipped (HAND VU0, HAND MMI); 3 NM closer handoffs received, 3 registered, 0 rejected (Motion_seq_readSpdData, func_00356FD8, func_00368CE8). Per-file settings (new units): src/cod/sa_002c7e30.c sn with "as": "sn"; src/cod/sa_002d0658.c, sa_002fa258.c, sa_0037a740.c sn default; src/cod/sa_00331310.c, sa_00346ed0.c, sa_0035db38.c cygnus-2.96 with -freorder-blocks dropped. The m2c list tagged func_0037A740 as cygnus, but it matched under sn. Reseed 70a (anchor func_0037A740): rc=0 117s, elf OK, overlay OK.
| 2026-10-17T06:06:01Z | func_00336218 | 208 | NM -> src/cod/sa_nm_00336218.c (STOP at 4 by judgement; best 2; cygnus dr; near-miss: retail uses bne with the speculative sll in the slot, ours bnel) | 4 | 87s | m2c + hand | func_00336218 |
| 2026-10-17T06:07:47Z | func_00342FF8 | 208 | NM -> src/cod/sa_nm_00342ff8.c (NEAR-MISS at 3; best 5; cygnus dr; kind2/c2 register swap in the third case) | 3 | 52s | m2c + hand | func_00342FF8 |
| 2026-10-17T06:08:46Z | func_00350528 | 208 | NM -> src/cod/sa_nm_00350528.c (NEAR-MISS at 3; best 2; cygnus dr; base registers swapped in the loop body) | 3 | 48s | m2c + hand | func_00350528 |
| 2026-10-17T06:10:18Z | func_00376438 | 208 | NM -> src/cod/sa_nm_00376438.c (PARK at 3; best 47; sn; the script-stepper loop layout differs) | 3 | 79s | m2c + hand | func_00376438 |
| 2026-10-17T06:11:15Z | func_00377ED0 | 208 | matched -> src/cod/sa_00377ed0.c (new unit; per-file: sn-2.95.3-136 default; indexed loops so the pool bases are rematerialised) | 3 | 48s | m2c + hand | func_00377ED0 |
| 2026-10-17T06:13:06Z | func_0037A020 | 208 | matched -> src/cod/sa_0037a020.c (new unit; per-file: sn-2.95.3-136 default; a sub-struct pointer gives the base-first addu) | 4 | 102s | m2c + hand | func_0037A020 |
| 2026-10-17T06:13:06Z | _ri0_110 | 208 | skipped: HAND MMI | 0 | 0s | no | _ri0_110 |
| 2026-10-17T06:13:06Z | func_0012C000 | 212 | skipped: jump table D_0041D1A0 needs extern_jtbl, which sa_register cannot set | 0 | 0s | no | func_0012C000 |
| 2026-10-17T06:14:39Z | func_001CEC68 | 212 | matched -> src/cod/sa_001cec68.c (new unit; per-file: sn-2.95.3-136 default) | 3 | 42s | m2c + hand | func_001CEC68 |
| 2026-10-17T06:16:04Z | func_002AC1C0 | 212 | matched -> src/cod/sa_002ac1c0.c (new unit; per-file: sn-2.95.3-136 default) | 2 | 78s | m2c + hand | func_002AC1C0 |
| 2026-10-17T06:17:17Z | func_002B0830 | 212 | matched -> src/cod/sa_002b0830.c (new unit; per-file: sn-2.95.3-136 default; goto walk like cMessDrawFont_measureText) | 1 | 64s | m2c + hand | func_002B0830 |
| 2026-10-17T06:18:34Z | func_00323840 | 212 | matched -> src/cod/sa_00323840.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped) | 3 | 69s | m2c + hand | func_00323840 |

BATCH 71: 6 matched, 4 NM, 2 skipped (HAND MMI, jump table); 7 NM closer handoffs received, 7 registered, 0 rejected (func_0026A3D8, func_002AFED0, func_002B2588, func_00344C98, func_0034E090, func_0036C0B0, func_0036D0F8; the 00344c98 and 0036c0b0 handoffs replace my NM stubs). Per-file settings (new units): src/cod/sa_00377ed0.c, sa_0037a020.c, sa_001cec68.c, sa_002ac1c0.c, sa_002b0830.c sn default; src/cod/sa_00323840.c cygnus-2.96 with -freorder-blocks dropped. func_00336218 was parked at 4 attempts (sa_try said CONTINUE) after unprototyped/int callees and -fno-gcse / -fno-align-jumps all left the bne/bnel difference. Reseed 71a (anchor func_00323840): rc=0 100s, elf OK, overlay OK.
| 2026-10-17T06:23:03Z | func_0032DA78 | 212 | matched -> src/cod/sa_0032da78.c (new unit; per-file: cygnus-2.96 with -freorder-blocks dropped; store order unk1E0, unk1B2, unk1 shares one constant) | 3 | 118s | m2c + hand | func_0032DA78 |
| 2026-10-17T06:24:48Z | MtxInitRotQuaternion | 216 | non-matching same size (FP schedule/regalloc; zeros via chained assign) -> src/cod/sa_nm_mtxinitrotquaternion.c | 3 | 100s | m2c + hand, parked | MtxInitRotQuaternion |
| 2026-10-17T06:25:12Z | func_001B0150 | 216 | matched -> src/cod/sa_001b0150.c (new unit; per-file: sn-2.95.3-136 default; struct-copied rate table) | 1 | 15s | m2c + hand | func_001B0150 |
| 2026-10-17T06:26:03Z | func_001EE5F0 | 216 | matched -> src/cod/sa_001ee5f0.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 46s | m2c + hand | func_001EE5F0 |
| 2026-10-17T06:29:05Z | func_001F6680 | 216 | non-matching (best 22 with -fno-gcse: on[] pointer increment hoisted into beq delay, bnel vs bnez) -> src/cod/sa_nm_001f6680.c | 5 | 177s | m2c + hand, parked (best variant needs -fno-gcse wrap-arg) | func_001F6680 |
| 2026-10-17T06:29:56Z | func_002B3C20 | 216 | matched -> src/cod/sa_002b3c20.c (new unit; per-file: sn-2.95.3-136 default) | 2 | 43s | m2c + hand | func_002B3C20 |
| 2026-10-17T06:30:55Z | func_002C1540 | 216 | matched -> src/cod/sa_002c1540.c (new unit; per-file: sn-2.95.3-136 default; separate &= statements) | 2 | 54s | m2c + hand | func_002C1540 |
| 2026-10-17T06:32:27Z | func_002CBF78 | 216 | non-matching (best 49: retail keeps constant 1 in a0 inside the loop for the (flags&1)==1 compare) -> src/cod/sa_nm_002cbf78.c | 3 | 87s | m2c + hand, parked | func_002CBF78 |
| 2026-10-17T06:33:35Z | func_002D50E8 | 216 | non-matching, 2 words short (retail copies count a1->v0 before the 0x10 arg; then loop-align nop) -> src/cod/sa_nm_002d50e8.c | 3 | 46s | m2c + hand, parked | func_002D50E8 |
| 2026-10-17T06:34:20Z | func_002E0C80 | 216 | matched -> src/cod/sa_002e0c80.c (new unit; per-file: sn-2.95.3-136 default; non-volatile *(int *)0x11111111 store) | 2 | 28s | m2c + hand | func_002E0C80 |
| 2026-10-17T06:35:07Z | func_00320728 | 216 | matched -> src/cod/sa_00320728.c (new unit; per-file: sn-2.95.3-136 default; single return 0 exit) | 2 | 41s | m2c + hand | func_00320728 |

BATCH 72: 7 matched, 4 NM, 3 skipped (_rix_110 HAND MMI, cScenario_endExtraGame and EmClothMove HAND VU0); 2 NM closer handoffs received, 2 registered, 0 rejected (func_003253C0, func_00349590). Per-file settings (new units): src/cod/sa_0032da78.c cygnus-2.96 with -freorder-blocks dropped; sa_001b0150.c, sa_001ee5f0.c, sa_002b3c20.c, sa_002c1540.c, sa_002e0c80.c, sa_00320728.c sn defaults. Reseed 72a: rc=0 88s, elf OK, overlay OK.
| 2026-10-17T06:40:59Z | func_0033A4F8 | 216 | matched -> src/cod/sa_0033a4f8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; strict aliasing: unk8 typed void *) | 3 | 212s | m2c + hand | func_0033A4F8 |
| 2026-10-17T06:44:11Z | func_0033F3F0 | 216 | NM -> src/cod/sa_nm_0033f3f0.c (cygnus dr; store-sched; volatile global fixes addiu+sw form) | 2 | 183s | m2c + hand | func_0033F3F0 |
| 2026-10-17T06:45:11Z | func_00345DF0 | 216 | matched -> src/cod/sa_00345df0.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; inverse store-order permutation) | 1 | 31s | m2c + hand | func_00345DF0 |
| 2026-10-17T06:46:11Z | func_0034B198 | 216 | matched -> src/cod/sa_0034b198.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped) | 1 | 52s | m2c + hand | func_0034B198 |
| 2026-10-17T06:47:10Z | func_0034E2C8 | 216 | matched -> src/cod/sa_0034e2c8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; long totals at 0x990/0x998) | 1 | 57s | m2c + hand | func_0034E2C8 |
| 2026-10-17T06:49:46Z | func_00366840 | 216 | NM -> src/cod/sa_nm_00366840.c (cygnus dr; loop-sched) | 2 | 154s | m2c + hand | func_00366840 |
| 2026-10-17T06:50:26Z | func_0036BE00 | 216 | matched -> src/cod/sa_0036be00.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; volatile D_00766CE0, for(;;){}) | 1 | 31s | m2c + hand | func_0036BE00 |
| 2026-10-17T06:51:45Z | func_00379838 | 216 | NM -> src/cod/sa_nm_00379838.c (sn; switch-crossjump) | 3 | 77s | m2c + hand | func_00379838 |
| 2026-10-17T06:52:25Z | func_00140638 | 220 | NM -> src/cod/sa_nm_00140638.c (sn; const-hoist) | 1 | 22s | m2c + hand | func_00140638 |
| 2026-10-17T06:55:18Z | func_001BD430 | 220 | NM -> src/cod/sa_nm_001bd430.c (sn; inline-range, movn) | 3 | 86s | m2c + hand | func_001BD430 |
| 2026-10-17T06:57:23Z | func_001EBB78 | 220 | NM -> src/cod/sa_nm_001ebb78.c (sn; loop-biv, inline-bool) | 3 | 117s | m2c + hand | func_001EBB78 |
| 2026-10-17T06:58:19Z | func_001F1DF8 | 220 | matched -> src/cod/sa_001f1df8.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 18s | m2c + hand | func_001F1DF8 |
| 2026-10-17T07:06:19Z | func_001FDEA8 | 220 | NM -> src/cod/sa_nm_001fdea8.c (sn; regalloc, 11 diffs) | 2 | 472s | m2c + hand | func_001FDEA8 |
| 2026-10-17T07:07:49Z | func_0026A558 | 220 | matched -> src/cod/sa_0026a558.c (new unit; per-file: sn-2.95.3-136 default; (x ^ 0x251) == 0 gives xori test) | 2 | 57s | m2c + hand | func_0026A558 |

BATCH 73: 7 matched, 7 NM, 0 skipped; 3 NM closer handoffs received, 3 registered, 0 rejected (func_00349328, func_0034FB70, func_003517D0). Note: cygnus-2.96 has strict aliasing on, so pointer vs int field types control which loads pass which stores (func_0033A4F8). Per-file settings (new units): src/cod/sa_0033a4f8.c, sa_00345df0.c, sa_0034b198.c, sa_0034e2c8.c, sa_0036be00.c cygnus-2.96 with -freorder-blocks dropped; sa_001f1df8.c, sa_0026a558.c sn defaults. Reseed 73a: rc=0 104s, elf OK, overlay OK.
| 2026-10-17T07:11:38Z | func_002AC298 | 220 | matched -> src/cod/sa_002ac298.c (new unit; per-file: sn-2.95.3-136 default; adapted from sibling func_002AC378) | 1 | 58s | m2c + hand | func_002AC298 |
| 2026-10-17T07:12:57Z | func_002B6688 | 220 | matched -> src/cod/sa_002b6688.c (new unit; per-file: sn-2.95.3-136 default; indexed loops, id == D[i] operand order) | 2 | 73s | m2c + hand | func_002B6688 |
| 2026-10-17T07:16:33Z | func_002FD530 | 220 | NM -> src/cod/sa_nm_002fd530.c (sn; inline-vec, 10 diffs) | 3 | 211s | m2c + hand | func_002FD530 |
| 2026-10-17T07:17:32Z | func_00333C00 | 220 | matched -> src/cod/sa_00333c00.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; int table field so the load stays after the stores) | 1 | 51s | m2c + hand | func_00333C00 |
| 2026-10-17T07:19:03Z | func_00338FD8 | 220 | matched -> src/cod/sa_00338fd8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; char * buffer fields for strict-aliasing order) | 1 | 85s | m2c + hand | func_00338FD8 |
| 2026-10-17T07:21:58Z | func_003505F8 | 220 | matched -> src/cod/sa_003505f8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; memset prototype returns void *) | 2 | 173s | m2c + hand | func_003505F8 |
| 2026-10-17T07:22:53Z | func_0037A818 | 220 | matched -> src/cod/sa_0037a818.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 43s | m2c + hand | func_0037A818 |
| 2026-10-17T07:24:15Z | func_00384EC8 | 220 | matched -> src/cod/sa_00384ec8.c (new unit; per-file: sn-2.95.3-136 default; local MenuList384EC8, see pending_headers) | 1 | 75s | m2c + hand | func_00384EC8 |
| 2026-10-17T07:25:46Z | func_002CA390 | 224 | matched -> src/cod/sa_002ca390.c (new unit; per-file: sn-2.95.3-136 default; 0x20-byte stack record) | 2 | 69s | m2c + hand | func_002CA390 |
| 2026-10-17T07:28:37Z | func_00353550 | 224 | NM -> src/cod/sa_nm_00353550.c (cygnus dr; branch-layout, regalloc) | 1 | 169s | m2c + hand | func_00353550 |
| 2026-10-17T07:29:34Z | func_00357C20 | 224 | matched -> src/cod/sa_00357c20.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; func_0035AB98 declared int) | 1 | 46s | m2c + hand | func_00357C20 |
| 2026-10-17T07:31:00Z | func_002C32F0 | 228 | matched -> src/cod/sa_002c32f0.c (new unit; per-file: sn-2.95.3-136 default; unsigned counter with (int)i >= 0, signed char flag) | 2 | 77s | m2c + hand | func_002C32F0 |
| 2026-10-17T07:35:11Z | func_00321F48 | 228 | NM -> src/cod/sa_nm_00321f48.c (ee-2.9-991111; libgcc find_fde; best 2 needs -fno-thread-jumps, not registered) | 1 | 249s | m2c + hand | func_00321F48 |

BATCH 74: 10 matched, 3 NM, 2 skipped (_rix_101 HAND MMI, func_00279D88 HAND VU0); 0 NM closer handoffs received, 0 registered, 0 rejected. Per-file settings (new units): src/cod/sa_00333c00.c, sa_00338fd8.c, sa_003505f8.c, sa_00357c20.c cygnus-2.96 with -freorder-blocks dropped; sa_002ac298.c, sa_002b6688.c, sa_0037a818.c, sa_00384ec8.c, sa_002ca390.c, sa_002c32f0.c sn defaults. Reseed 74a: rc=0 120s, elf OK, overlay OK.

| 2026-10-17T07:38:44Z | func_0032E3A0 | 228 | matched -> src/cod/sa_0032e3a0.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; positive nested if (range) {...return total;} return 0;) | 1 | 57s | m2c + hand | func_0032E3A0 |
| 2026-10-17T07:40:15Z | func_00333048 | 228 | matched -> src/cod/sa_00333048.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; unused call result declared int flips v0/v1) | 1 | 89s | m2c + hand | func_00333048 |
| 2026-10-17T07:43:11Z | func_002BEBC8 | 232 | NM -> src/cod/sa_nm_002bebc8.c (sn; PARK; only the loop-align padding nop differs, 57 vs 58 words) | 2 | 174s | m2c + hand | func_002BEBC8 |
| 2026-10-17T07:44:55Z | func_0033D870 | 232 | NM -> src/cod/sa_nm_0033d870.c (cygnus dr; NEAR-MISS; 1 diff bne vs bnel on first mode test) | 1 | 97s | m2c + hand | func_0033D870 |
| 2026-10-17T07:45:34Z | func_003832C8 | 232 | matched -> src/cod/sa_003832c8.c (new unit; per-file: sn-2.95.3-136 default) | 1 | 21s | m2c + hand | func_003832C8 |
| 2026-10-17T07:47:35Z | func_00394C18 | 232 | matched -> src/cod/sa_00394c18.c (new unit; per-file: sn-2.95.3-136 default; one variable i reused for both roles) | 1 | 114s | m2c + hand | func_00394C18 |
| 2026-10-17T07:51:51Z | func_0039EAA8 | 232 | matched -> src/cod/sa_0039eaa8.c (new unit; per-file: ee-2.9-991111 like neighbouring libmpeg units; _sceMpegGetBits; if-chain, bits computed before cmd/op) | 2 | 246s | m2c + hand | func_0039EAA8 |
| 2026-10-17T07:53:06Z | func_00155C68 | 236 | matched -> src/cod/sa_00155c68.c (new unit; per-file: sn-2.95.3-136 default; TAG64 sibling of func_00155AE8) | 1 | 67s | m2c + hand | func_00155C68 |
| 2026-10-17T07:55:05Z | func_001BF7D8 | 236 | matched -> src/cod/sa_001bf7d8.c (new unit; per-file: sn default; separate |= per flag; scenario pointer cached in a local after the call) | 1 | 118s | m2c + hand | func_001BF7D8 |
| 2026-10-17T07:56:19Z | func_001F14C8 | 236 | matched -> src/cod/sa_001f14c8.c (new unit; per-file: sn default; cRoomSave_clearEmDeadFlag declared int) | 1 | 73s | m2c + hand | func_001F14C8 |
| 2026-10-17T07:57:17Z | func_001F91D0 | 236 | matched -> src/cod/sa_001f91d0.c (new unit; per-file: sn default; grow box to enclose another, returns dst) | 1 | 56s | m2c + hand | func_001F91D0 |
| 2026-10-17T08:00:01Z | create | 236 | NM -> src/cod/sa_nm_002ba300.c (sn; parked after attempt 1 although sa_try said CONTINUE, because the only diff is one R5900 short-loop pad nop in a multi-block pointer-chase loop, which ee-as does not pad) | 1 | 163s | m2c + hand | create |
| 2026-10-17T08:03:20Z | func_0035BEF0 | 236 | matched -> src/cod/sa_0035bef0.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped like neighbours; stream fields typed as pointers so branch prediction fills from the else block) | 1 | 178s | m2c + hand | func_0035BEF0 |
| 2026-10-17T08:06:34Z | func_00377BC8 | 236 | matched -> src/cod/sa_00377bc8.c (new unit; per-file: sn default; 14-byte memcpy of "Version 1.100" from int-aligned D_0045A600; memset-like helper declared void *) | 2 | 192s | m2c + hand | func_00377BC8 |

BATCH 75: 11 matched, 3 NM, 2 skipped (_ri0_101 HAND MMI, func_002BB670 HAND VU0); 6 NM closer handoffs received, 6 registered, 0 rejected (func_002CBF78, func_002D50E8, func_00332A60, func_00332AE8, func_00340A60, func_00379838). Per-file settings (new units): src/cod/sa_0032e3a0.c, sa_00333048.c, sa_0035bef0.c cygnus-2.96 with -freorder-blocks dropped; sa_0039eaa8.c ee-2.9-991111 (existing compiler, matches neighbouring libmpeg units); sa_003832c8.c, sa_00394c18.c, sa_00155c68.c, sa_001bf7d8.c, sa_001f14c8.c, sa_001f91d0.c, sa_00377bc8.c sn defaults. Reseed 75a: rc=0 116s, elf OK, overlay OK.

| 2026-10-17T08:12:40Z | func_001485A0 | 240 | matched -> src/cod/sa_001485a0.c (new unit; per-file: sn default; u16 count kept in an unsigned short local, big = x >= 2 boolean) | 1 | 99s | m2c + hand | func_001485A0 |
| 2026-10-17T08:16:12Z | func_00158198 | 240 | matched -> src/cod/sa_00158198.c (new unit; per-file: sn default; chained a = b = c = 0.0f, int-arithmetic table pointer sums) | 1 | 210s | m2c + hand | func_00158198 |
| 2026-10-17T08:17:08Z | func_001E4520 | 240 | matched -> src/cod/sa_001e4520.c (new unit; per-file: sn default) | 1 | 54s | m2c + hand | func_001E4520 |
| 2026-10-17T08:18:14Z | func_001F0BF8 | 240 | matched -> src/cod/sa_001f0bf8.c (new unit; per-file: sn default) | 1 | 65s | m2c + hand | func_001F0BF8 |
| 2026-10-17T08:20:14Z | func_0026B9E8 | 240 | matched -> src/cod/sa_0026b9e8.c (new unit; per-file: sn default; SetVec3/ZeroVec3 inline helpers, vtable call through vt+0x44) | 1 | 118s | m2c + hand | func_0026B9E8 |
| 2026-10-17T08:21:29Z | func_002B4428 | 240 | matched -> src/cod/sa_002b4428.c (new unit; per-file: sn default; qword copies through int w[N]) | 1 | 73s | m2c + hand | func_002B4428 |
| 2026-10-17T08:22:55Z | func_002E63C0 | 240 | matched -> src/cod/sa_002e63c0.c (new unit; per-file: sn default; separate int out-params so the error tails cross-jump) | 1 | 84s | m2c + hand | func_002E63C0 |
| 2026-10-17T08:24:40Z | func_00332508 | 240 | NM -> src/cod/sa_nm_00332508.c (cygnus dr; 2 diffs, const load order in the RPC bind delay loop; later closed by an NM closer handoff, see BATCH line) | 1 | 104s | m2c + hand | func_00332508 |
| 2026-10-17T08:25:42Z | func_003537C0 | 240 | matched -> src/cod/sa_003537c0.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; sub = w + 0x8C placed before func_003538B0) | 1 | 39s | m2c + hand | func_003537C0 |
| 2026-10-17T08:27:14Z | func_0035AF68 | 240 | matched -> src/cod/sa_0035af68.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; per-branch store order) | 1 | 90s | m2c + hand | func_0035AF68 |
| 2026-10-17T08:28:51Z | func_0036B798 | 240 | matched -> src/cod/sa_0036b798.c (new unit; per-file: cygnus-2.96 default; mask set before the call, split base adjustments) | 1 | 95s | m2c + hand | func_0036B798 |
| 2026-10-17T08:34:21Z | func_00375988 | 240 | NM -> src/cod/sa_nm_00375988.c (sn; 7 diffs, tbl3 load order) | 1 | 328s | m2c + hand | func_00375988 |
| 2026-10-17T08:35:39Z | func_00380048 | 240 | matched -> src/cod/sa_00380048.c (new unit; per-file: sn default; kind == 0xA ? a : b for movz) | 1 | 56s | m2c + hand | func_00380048 |
| 2026-10-17T08:37:57Z | func_003A79F8 | 240 | NM -> src/cod/sa_nm_003a79f8.c (sn; newlib __sccl; 1 diff, beql into the range-fill loop lands before the loop-align nop instead of after) | 1 | 96s | m2c + hand | func_003A79F8 |
| 2026-10-17T08:39:27Z | func_00143998 | 244 | matched -> src/cod/sa_00143998.c (new unit; per-file: sn default; 16-slot redraw of the second ID base) | 1 | 43s | m2c + hand | func_00143998 |
| 2026-10-17T08:40:34Z | func_001A4430 | 244 | matched -> src/cod/sa_001a4430.c (new unit; per-file: sn default; Vec3 copy with self check as an inline helper; 0x548 stored before 0x54A) | 1 | 65s | m2c + hand | func_001A4430 |
| 2026-10-17T08:41:32Z | func_001A9938 | 244 | matched -> src/cod/sa_001a9938.c (new unit; per-file: sn default; indexed handle loop instead of pointer walk) | 1 | 56s | m2c + hand | func_001A9938 |
| 2026-10-17T08:49:51Z | func_002BB2D8 | 244 | NM -> src/cod/sa_nm_002bb2d8.c (sn; 1 diff, world-bit test gives dsrl where retail has dsra; long-t idiom only reproduces dsra from a u32 field) | 1 | 498s | m2c + hand | func_002BB2D8 |
| 2026-10-17T08:52:14Z | func_002EC218 | 244 | matched -> src/cod/sa_002ec218.c (new unit; per-file: sn default; trail shift with Vec3 copy helper) | 1 | 27s | m2c + hand | func_002EC218 |
| 2026-10-17T08:54:59Z | func_00334998 | 244 | matched -> src/cod/sa_00334998.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; func_00334A90 declared int; state cleared before pos) | 2 | 163s | m2c + hand | func_00334998 |
| 2026-10-17T08:56:40Z | func_0033FB78 | 244 | NM -> src/cod/sa_nm_0033fb78.c (cygnus dr; 1 diff, bnel with annulled li v0,3 where retail has bne) | 1 | 98s | m2c + hand | func_0033FB78 |
| 2026-10-17T09:00:43Z | func_003580E8 | 244 | matched -> src/cod/sa_003580e8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; mode != 4 jumps to the shared return-0 of the func_0035AAC8 failure) | 1 | 175s | m2c + hand | func_003580E8 |
| 2026-10-17T09:02:51Z | func_00363528 | 244 | NM -> src/cod/sa_nm_00363528.c (cygnus dr; 44 diffs, register swap of dst/outer bound and latch-loaded dst->data) | 1 | 118s | m2c + hand | func_00363528 |
| 2026-10-17T09:04:55Z | func_00375500 | 244 | matched -> src/cod/sa_00375500.c (new unit; per-file: sn default; buffer address through a local char * before each SyncDCache) | 1 | 75s | m2c + hand | func_00375500 |
| 2026-10-17T09:06:05Z | func_003821D8 | 244 | matched -> src/cod/sa_003821d8.c (new unit; per-file: sn default; 1-based vol/mute arrays, list header at +0x30) | 1 | 68s | m2c + hand | func_003821D8 |
| 2026-10-17T09:07:35Z | func_003977C8 | 244 | NM -> src/cod/sa_nm_003977c8.c (ee-2.9-991111; 3 diffs, scheduling of the rpc buffer word-4 zero store) | 1 | 88s | m2c + hand | func_003977C8 |

BATCH 76: 19 matched, 7 NM, 3 skipped (func_0039EDB8 HAND MMI, func_003A4FC8 HAND MMI, func_00275888 HAND VU0); 25 NM closer handoffs received, 24 registered, 1 rejected. Registered: JukeBox_Release, create, func_0012EC58, func_001346C8, func_001482C0, func_001641B8, func_001B81A8, func_002949E8, func_002A4E58, func_002B2158, func_002BEB00, func_002BEBC8, func_002D4248, func_002D51F0, func_002D56A8, func_00305858, func_0032F178, func_00332508, func_00337A00, func_0033F3F0, func_00376438, func_00376A90, func_00377530, func_003A9498. Rejected after the fact: func_001ECFE8 (stale NON_MATCHING block in batch35_nm.c for a function already matched in sa_001ece30.c since batch 6; nm_handoff registered it, the 76a reseed link failed on the duplicate symbol, so I deleted sa_001ecfe8.c and its unit and pointed the carved tu back to sa_001ece30.c). Script fixes: nm_handoff.py now rejects handoffs whose function is already defined in C in its registered tu, and names new files sa_<addr>.c from the NM file name or carved vaddr (it used the text after the first underscore, which made sa_release.c, sa_dest_dir.c, sa_seq_readspddata.c and crashed on an underscore-free name); those three were renamed to sa_001f5c48.c, sa_002da1f8.c, sa_002c7d18.c in compile_config.json. A scan found no other stale NM blocks. Per-file settings (new units): src/cod/sa_003537c0.c, sa_0035af68.c, sa_00334998.c, sa_003580e8.c cygnus-2.96 with -freorder-blocks dropped; sa_0036b798.c cygnus-2.96 default; sa_001485a0.c, sa_00158198.c, sa_001e4520.c, sa_001f0bf8.c, sa_0026b9e8.c, sa_002b4428.c, sa_002e63c0.c, sa_00380048.c, sa_00143998.c, sa_001a4430.c, sa_001a9938.c, sa_002ec218.c, sa_00375500.c, sa_003821d8.c sn defaults. Reseed 76a: first run rc=1 (duplicate func_001ECFE8, fixed as above), second run rc=0 101s, elf OK, overlay OK; sha256 1742f95b...a64f3cd / ea599323...8c653c1 verified.

| 2026-10-17T09:20:22Z | func_003B9BF0 | 244 | matched -> src/cod/sa_003b9bf0.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; if/else-if state machine instead of a switch) | 1 | 67s | m2c + hand | func_003B9BF0 |
| 2026-10-17T09:21:18Z | cBgmData_LoadNumbered | 248 | matched -> src/cod/sa_002d0128.c (new unit; per-file: sn default; cSnd.h/cBgmData.h, func_003A6C58(name, fmt, req)) | 1 | 53s | m2c + hand | cBgmData_LoadNumbered |
| 2026-10-17T09:23:01Z | func_0032BB98 | 248 | matched -> src/cod/sa_0032bb98.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; stat/unkAC/unk02 byte store order, dir stored before ofst) | 1 | 102s | m2c + hand | func_0032BB98 |
| 2026-10-17T09:24:12Z | func_0032F330 | 248 | matched -> src/cod/sa_0032f330.c (new unit; per-file: cygnus-2.96 default; int slot param avoids sll/sra) | 1 | 69s | m2c + hand | func_0032F330 |
| 2026-10-17T09:26:23Z | func_00339F00 | 248 | matched -> src/cod/sa_00339f00.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; second min as a ternary gives movz) | 1 | 129s | m2c + hand | func_00339F00 |
| 2026-10-17T09:29:42Z | func_003552D0 | 248 | NM -> src/cod/sa_nm_003552d0.c (cygnus dr; 18 diffs, s0/s1 swap of sfd/mpv only) | 1 | 196s | m2c + hand | func_003552D0 |
| 2026-10-17T09:31:30Z | func_0035AD20 | 248 | NM -> src/cod/sa_nm_0035ad20.c (cygnus dr; 46 diffs, retail reloads t->last after the -5 test and hoists the counter load) | 1 | 108s | m2c + hand | func_0035AD20 |
| 2026-10-17T09:33:34Z | func_00137BB8 | 252 | NM -> src/cod/sa_nm_00137bb8.c (sn; 28 diffs, s1..s6 assignment of list/found/pt/best only) | 1 | 124s | m2c + hand | func_00137BB8 |
| 2026-10-17T09:44:19Z | func_002A6CA8 | 252 | NM -> src/cod/sa_nm_002a6ca8.c (sn; 16 diffs, order of the 16 vertex float stores) | 1 | 645s | m2c + hand | func_002A6CA8 |
| 2026-10-17T09:46:23Z | func_002BAE98 | 252 | NM -> src/cod/sa_nm_002bae98.c (sn; one missing short-loop pad nop at the head of the call-free unlink loop) | 1 | 124s | m2c + hand | func_002BAE98 |
| 2026-10-17T09:48:47Z | func_002E0B78 | 252 | matched -> src/cod/sa_002e0b78.c (new unit; per-file: sn default; sibling of func_002E0C80 with Moji_size_set around it) | 2 | 144s | m2c + hand | func_002E0B78 |
| 2026-10-17T09:49:49Z | func_002F01B8 | 252 | matched -> src/cod/sa_002f01b8.c (new unit; per-file: sn default; three sin/cos wobble channels) | 1 | 60s | m2c + hand | func_002F01B8 |
| 2026-10-17T09:52:33Z | PullEsp | 252 | matched -> src/cod/sa_002faa88.c (new unit; per-file: sn default; work area as D_0061B7C0[i] of a [0x400][0x400] array, do-while) | 1 | 162s | m2c + hand | PullEsp |
| 2026-10-17T09:55:38Z | func_00304C48 | 252 | NM -> src/cod/sa_nm_00304c48.c (sn; 83 diffs, retail materialises each sel[0]==n bool with a branch and andi 0xFF) | 1 | 183s | m2c + hand | func_00304C48 |
| 2026-10-17T09:56:48Z | func_003219D0 | 252 | NM -> src/cod/sa_nm_003219d0.c (cygnus; 75 diffs, retail keeps three d[i-1] pointer givs and saves s0-s2) | 1 | 70s | m2c + hand | func_003219D0 |
| 2026-10-17T09:58:48Z | func_0032CB90 | 252 | matched -> src/cod/sa_0032cb90.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; indexed adx->sjo[i] through a local) | 1 | 120s | m2c + hand | func_0032CB90 |
| 2026-10-17T10:00:06Z | func_003391F8 | 252 | matched -> src/cod/sa_003391f8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; ternary clamps, goto into the shared error callback) | 1 | 76s | m2c + hand | func_003391F8 |
| 2026-10-17T10:01:54Z | cIDBase_transTex | 256 | NM -> src/cod/sa_nm_002aaef0.c (sn; 47 diffs, same stack-argument ABI wall as cIDBase_transSprite) | 1 | 106s | m2c + hand | cIDBase_transTex |
| 2026-10-17T10:05:57Z | func_003127B0 | 256 | matched -> src/cod/sa_003127b0.c (new unit; per-file: sn default; empty-allocator byte round-trip through a volatile local, end/begin/cap store order) | 1 | 243s | m2c + hand | func_003127B0 |
| 2026-10-17T10:06:49Z | func_0033BA80 | 256 | matched -> src/cod/sa_0033ba80.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; [8][6] callback table) | 1 | 50s | m2c + hand | func_0033BA80 |

BATCH 77: 12 matched, 8 NM, 0 skipped; 20 NM closer handoffs received, 20 registered, 0 rejected. First pass registered 6 (func_00133AA8, func_001D6A70, func_001E7660, func_002B2C98, func_00383DD0, func_00394D00) and rejected 14 on tool gaps, not on the code: older batch NM files that hold bare INCLUDE_ASM lines without a NON_MATCHING block (batch44/46/49/51/52_nm.c) were not found or could not be cut, and Motion_seq_readEffectData had no carved vaddr for its file name. nm_handoff.py now accepts *_nm*.c files, cuts a bare INCLUDE_ASM line, and falls back to config/symbol_addrs.txt for the address; all 14 re-verified and registered (Motion_seq_readEffectData, MoveEffect, func_00126918, func_00144FD8, func_001B0BD0, func_001B1BD0, func_001FF3A0, func_002009E8, func_002AE990, func_003057D0, func_00319CC0, func_003757A0, func_003778D8, func_0037CE20). Per-file settings (new units): cygnus-2.96 with -freorder-blocks dropped for sa_003b9bf0, sa_0032bb98, sa_00339f00, sa_0032cb90, sa_003391f8, sa_0033ba80; cygnus-2.96 default for sa_0032f330; sn default for sa_002d0128, sa_002e0b78, sa_002f01b8, sa_002faa88, sa_003127b0. No flag adds. Reseed 77a rc=0 in 98s, ELF and r207.rel hashes OK.

| 2026-10-17T10:15:46Z | func_0033D090 | 256 | NM -> src/cod/sa_nm_0033d090.c (cygnus dr; 7 diffs, v0/v1 swap in the default-code copy block only; short/char-array/temp forms tried) | 1 | 157s | m2c + hand | func_0033D090 |
| 2026-10-17T10:20:25Z | func_00340580 | 256 | NM -> src/cod/sa_nm_00340580.c (cygnus dr; 9 diffs, prologue param-copy order plus three beql in retail where we emit beq with the same delay insn) | 1 | 279s | m2c + hand | func_00340580 |
| 2026-10-17T10:22:19Z | func_00342D00 | 256 | NM -> src/cod/sa_nm_00342d00.c (cygnus dr; 37 diffs, register numbering of the buffer-size arithmetic; retail keeps an extra mb copy before the <<10) | 1 | 114s | m2c + hand | func_00342D00 |
| 2026-10-17T10:23:16Z | func_0037A0F0 | 256 | matched -> src/cod/sa_0037a0f0.c (new unit; per-file: sn default; (&tbl[idx])->on keeps the 0x14 offset off the symbol) | 1 | 57s | m2c + hand | func_0037A0F0 |
| 2026-10-17T10:24:36Z | func_0012C7D0 | 260 | matched -> src/cod/sa_0012c7d0.c (new unit; per-file: sn default; cfront vtable calls, separate local for the second GetJacket) | 1 | 78s | m2c + hand | func_0012C7D0 |
| 2026-10-17T10:25:38Z | func_001F52A0 | 260 | matched -> src/cod/sa_001f52a0.c (new unit; per-file: sn default; two 7-int row tables copied by struct assignment) | 1 | 60s | m2c + hand | func_001F52A0 |
| 2026-10-17T10:26:36Z | func_001F5F70 | 260 | matched -> src/cod/sa_001f5f70.c (new unit; per-file: sn default; state-handler table {delta, fn}, 64-bit pad word) | 1 | 56s | m2c + hand | func_001F5F70 |
| 2026-10-17T10:27:42Z | func_00322030 | 260 | matched -> src/cod/sa_00322030.c (new unit; per-file: ee-2.9-991111, already used by src/cod/0012c4f0.c; libgcc frame.c extract_cie_info) | 1 | 64s | m2c + hand | func_00322030 |
| 2026-10-17T10:30:39Z | func_00336110 | 260 | matched -> src/cod/sa_00336110.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local declaration and load order picked from a 24x24 order sweep) | 1 | 175s | m2c + hand | func_00336110 |
| 2026-10-17T10:35:34Z | func_0033D3D0 | 260 | NM -> src/cod/sa_nm_0033d3d0.c (cygnus dr; 40 diffs, structure and schedule right, register numbering of the block counters; load-order sweep did not help) | 1 | 288s | m2c + hand | func_0033D3D0 |
| 2026-10-17T10:37:36Z | func_00374210 | 260 | NM -> src/cod/sa_nm_00374210.c (sn; 56 diffs, retail saves an unused s0 and schedules the size math differently) | 1 | 122s | m2c + hand | func_00374210 |
| 2026-10-17T10:40:03Z | func_00377AC0 | 260 | NM -> src/cod/sa_nm_00377ac0.c (sn; 2 diffs, owner and track-id loads issue in the opposite order) | 1 | 147s | m2c + hand | func_00377AC0 |
| 2026-10-17T10:40:42Z | func_00385308 | 260 | matched -> src/cod/sa_00385308.c (new unit; per-file: sn default; >= -14 test before the off case) | 1 | 39s | m2c + hand | func_00385308 |
| 2026-10-17T10:43:20Z | func_0014B810 | 264 | NM -> src/cod/sa_nm_0014b810.c (sn; 63 diffs, our build cross-jumps the six queue calls, retail keeps all six blocks) | 1 | 156s | m2c + hand | func_0014B810 |
| 2026-10-17T10:43:52Z | func_001E4200 | 264 | matched -> src/cod/sa_001e4200.c (new unit; per-file: sn default; order table by struct copy, i set before p) | 1 | 32s | m2c + hand | func_001E4200 |
| 2026-10-17T10:45:08Z | func_00304830 | 264 | matched -> src/cod/sa_00304830.c (new unit; per-file: sn default; w component written through a pointer to the vector) | 1 | 75s | m2c + hand | func_00304830 |
| 2026-10-17T10:51:25Z | func_00327A50 | 264 | NM -> src/cod/sa_nm_00327a50.c (cygnus dr; 3 diffs, store order of stat/sj/size; greedy statement-order search bottoms out at 3) | 1 | 376s | m2c + hand | func_00327A50 |
| 2026-10-17T10:52:26Z | func_00331AD8 | 264 | matched -> src/cod/sa_00331ad8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local manager pointer, volatile flush flag) | 1 | 61s | m2c + hand | func_00331AD8 |
| 2026-10-17T10:53:17Z | func_003447A8 | 264 | matched -> src/cod/sa_003447a8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; Sofdec header analysis) | 1 | 50s | m2c + hand | func_003447A8 |
| 2026-10-17T10:55:13Z | func_003533A8 | 264 | NM -> src/cod/sa_nm_003533a8.c (cygnus dr; 2 diffs, the end-flag temp lands in v0 instead of v1) | 1 | 114s | m2c + hand | func_003533A8 |
| 2026-10-17T10:55:44Z | func_00366FE0 | 264 | matched -> src/cod/sa_00366fe0.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; start-code kind switch) | 1 | 31s | m2c + hand | func_00366FE0 |
| 2026-10-17T10:57:45Z | MPV_SearchDelim | 264 | NM -> src/cod/sa_nm_00369370.c (cygnus dr; 32 diffs from one delay slot: retail fills the case-3 beq from the target, we fill from the fall-through) | 1 | 119s | m2c + hand | MPV_SearchDelim |
| 2026-10-17T10:58:16Z | func_00387328 | 264 | matched -> src/cod/sa_00387328.c (new unit; per-file: sn default; voice-parameter command queue) | 1 | 30s | m2c + hand | func_00387328 |
| 2026-10-17T11:00:14Z | Quaternion_SetEulerXYZ | 268 | matched -> src/cod/sa_0015a590.c (new unit; per-file: sn default; no product temporaries, x/y/z/w store order) | 1 | 116s | m2c + hand | Quaternion_SetEulerXYZ |

BATCH 78: 14 matched, 10 NM, 0 skipped; 1 NM closer handoff received, 1 registered, 0 rejected (func_0028E7C8, cut from src/cod/batch45_nm.c to src/cod/sa_0028e7c8.c). Per-file settings (new units): sn default for sa_0037a0f0, sa_0012c7d0, sa_001f52a0, sa_001f5f70, sa_00385308, sa_001e4200, sa_00304830, sa_00387328, sa_0015a590; cygnus-2.96 with -freorder-blocks dropped for sa_00336110, sa_00331ad8, sa_003447a8, sa_00366fe0; ee-2.9-991111 for sa_00322030 (compiler already used by src/cod/0012c4f0.c). No flag adds. Order sweeps for func_00336110, func_0033D3D0, func_00327A50 and Quaternion_SetEulerXYZ were plain loops over hand-written statement orders, not the permuter. Reseed 78a rc=0 in 104s, ELF and r207.rel hashes OK.
| 2026-10-17T11:04:48Z | func_001B8228 | 268 | matched -> src/cod/sa_001b8228.c (new unit; per-file: sn default; pointer-to-member table dispatch, dst/src pointer locals for the two vector copies) | 2 | 74s | m2c + hand | func_001B8228 |
| 2026-10-17T11:06:44Z | func_001FDFD8 | 268 | matched -> src/cod/sa_001fdfd8.c (new unit; per-file: sn-2.95.3-136 with c_flags_add -f=-fno-gcse, in the closed vocabulary; do-while loops, end pointer recomputed per loop) | 3 | 107s | m2c + hand | func_001FDFD8 |
| 2026-10-17T11:13:51Z | func_002D3C78 | 268 | NM -> src/cod/sa_nm_002d3c78.c (sn; 7 diffs, tail store and constant scheduling; statement-order sweeps, temp, flag and compiler probes tried) | 3 | 421s | m2c + hand | func_002D3C78 |
| 2026-10-17T11:15:30Z | func_0031C238 | 268 | NM -> src/cod/sa_nm_0031c238.c (sn; 2 diffs, v1 instead of v0 for the count in the *12 multiply) | 2 | 93s | m2c + hand | func_0031C238 |
| 2026-10-17T11:16:35Z | func_00331458 | 268 | matched -> src/cod/sa_00331458.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; for loop with continue for the lock retry) | 3 | 57s | m2c + hand | func_00331458 |
| 2026-10-17T11:19:29Z | func_00366730 | 268 | NM -> src/cod/sa_nm_00366730.c (cygnus dr; structure close with a goto outer loop; p/d registers swapped and the p->data load lands after the multiply) | 3 | 169s | m2c + hand | func_00366730 |
| 2026-10-17T11:22:07Z | func_0037B808 | 268 | matched -> src/cod/sa_0037b808.c (new unit; per-file: sn default; e->val used directly instead of a pointer local) | 3 | 149s | m2c + hand | func_0037B808 |
| 2026-10-17T11:23:08Z | func_003B7400 | 268 | NM -> src/cod/sa_nm_003b7400.c (ee-2.9-991111; STOP: stores $gp, reachable only through the gp.h inline-asm accessor, which the real-C rule excludes) | 1 | 54s | m2c + hand | func_003B7400 |
| 2026-10-17T11:23:52Z | func_001E6ED8 | 272 | matched -> src/cod/sa_001e6ed8.c (new unit; per-file: sn default; order table by struct copy, separate loop variable for the first loop) | 2 | 35s | m2c + hand | func_001E6ED8 |
| 2026-10-17T11:24:49Z | func_002BE0F0 | 272 | matched -> src/cod/sa_002be0f0.c (new unit; per-file: sn default; FileLoader_readWholeFile takes the arg, (x ^ 1) == 0 test) | 2 | 56s | m2c + hand | func_002BE0F0 |
| 2026-10-17T11:26:26Z | func_002BE708 | 272 | matched -> src/cod/sa_002be708.c (new unit; per-file: sn default; goto keeps the two range compares unfolded) | 3 | 90s | m2c + hand | func_002BE708 |
| 2026-10-17T11:27:28Z | func_0030ECF8 | 272 | matched -> src/cod/sa_0030ecf8.c (new unit; per-file: sn default; global store order from a 6-way order sweep) | 2 | 60s | m2c + hand | func_0030ECF8 |
| 2026-10-17T11:28:41Z | func_0035CE60 | 272 | matched -> src/cod/sa_0035ce60.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; entry table pointer loaded with the state) | 2 | 72s | m2c + hand | func_0035CE60 |
| 2026-10-17T11:30:19Z | func_00383170 | 272 | NM -> src/cod/sa_nm_00383170.c (sn; 28 diffs, count-load delay slot and the n = i + 1 temp copy in the loop) | 3 | 97s | m2c + hand | func_00383170 |
| 2026-10-17T11:31:56Z | func_003B6290 | 272 | NM -> src/cod/sa_nm_003b6290.c (ee-2.9-991111; 52 diffs, retail strlen loop has the R5900 short-loop 3-nop pad our ee-as path omits) | 1 | 19s | m2c + hand | func_003B6290 |
| 2026-10-17T11:35:09Z | func_001B7568 | 276 | NM -> src/cod/sa_nm_001b7568.c (sn; 41 diffs from one copy: retail slti v0 then daddu a3, we emit slti a3) | 3 | 129s | m2c + hand | func_001B7568 |
| 2026-10-17T11:36:31Z | func_001BD8C8 | 276 | matched -> src/cod/sa_001bd8c8.c (new unit; per-file: sn default; switch with case 1 fall-through, store order from an order sweep) | 3 | 67s | m2c + hand | func_001BD8C8 |
| 2026-10-17T11:37:26Z | cScenario_upCutTask | 276 | matched -> src/cod/sa_002c41c8.c (new unit; per-file: sn default; uses include/godhand/cScenario.h) | 1 | 53s | m2c + hand | cScenario_upCutTask |
| 2026-10-17T11:39:50Z | func_00319848 | 276 | matched -> src/cod/sa_00319848.c (new unit; per-file: sn default; top-bit test as an unsigned int bitfield, body wrapped so return 1 is shared) | 2 | 137s | m2c + hand | func_00319848 |
| 2026-10-17T11:42:16Z | func_0032A720 | 276 | matched -> src/cod/sa_0032a720.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; ADX pan with if/else-if chain) | 3 | 138s | m2c + hand | func_0032A720 |

BATCH 79: 13 matched, 7 NM, 0 skipped; 0 NM closer handoffs received, 0 registered, 0 rejected. Per-file settings (new units): sn default for sa_001b8228, sa_0037b808, sa_001e6ed8, sa_002be0f0, sa_002be708, sa_0030ecf8, sa_001bd8c8, sa_002c41c8, sa_00319848; sn-2.95.3-136 with c_flags_add -f=-fno-gcse for sa_001fdfd8 (existing closed-vocabulary flag, file-local); cygnus-2.96 with -freorder-blocks dropped for sa_00331458, sa_0035ce60, sa_0032a720. Order sweeps for func_002D3C78, func_0030ECF8 and func_001BD8C8 were plain loops over hand-written statement orders, not the permuter. func_003B7400 parked as STOP: its sw $gp is only reachable through the gp.h inline-asm accessor, excluded by the real-C rule. Reseed 79a rc=0 in 42s, ELF and r207.rel hashes OK.
| 2026-10-17T11:44:05Z | func_001F7680 | 280 | skipped: jump table D_003BD6E8 needs extern_jtbl, which sa_register cannot set | 0 | 0s | no | func_001F7680 |
| 2026-10-17T11:48:32Z | func_00334D68 | 276 | NM -> src/cod/sa_nm_00334d68.c (cygnus dr; cc1 .s identical except the first bne slot is left unfilled, the loop .p2align nop follows from that shift) | 3 | 267s | m2c + hand | func_00334D68 |
| 2026-10-17T11:49:23Z | func_0034A5E0 | 276 | NM -> src/cod/sa_nm_0034a5e0.c (cygnus dr; 19 diffs, i=0 / s-reg save order and loop entry layout) | 3 | 46s | m2c + hand | func_0034A5E0 |
| 2026-10-17T11:50:15Z | func_0035F970 | 276 | NM -> src/cod/sa_nm_0035f970.c (cygnus dr; 37 diffs, second-half a3/t0 choice and hoisted error-arg setup) | 3 | 43s | m2c + hand | func_0035F970 |
| 2026-10-17T11:51:09Z | func_003600E8 | 276 | matched -> src/cod/sa_003600e8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; q = p copy, long long locals) | 3 | 45s | m2c + hand | func_003600E8 |
| 2026-10-17T11:53:26Z | func_003943D0 | 276 | matched -> src/cod/sa_003943d0.c (new unit; per-file: sn default; statement order node, id, val, name) | 2 | 131s | m2c + hand | func_003943D0 |
| 2026-10-17T11:57:21Z | func_001331B8 | 280 | NM -> src/cod/sa_nm_001331b8.c (sn; 7 diffs, name pointer setup kept in v1 and copied to a3 in retail) | 5 | 233s | m2c + hand | func_001331B8 |
| 2026-10-17T11:57:46Z | func_00298DB8 | 280 | matched -> src/cod/sa_00298db8.c (new unit; per-file: sn default) | 1 | 19s | m2c + hand | func_00298DB8 |
| 2026-10-17T12:01:10Z | func_002D40F8 | 280 | NM -> src/cod/sa_nm_002d40f8.c (sn; 5 diffs, v0/v1 swap for the -1 and 0x1F tail constants) | 2 | 197s | m2c + hand | func_002D40F8 |
| 2026-10-17T12:01:30Z | func_0031BB80 | 280 | matched -> src/cod/sa_0031bb80.c (new unit; per-file: sn default; local pad vibration types) | 1 | 20s | m2c + hand | func_0031BB80 |
| 2026-10-17T12:02:43Z | func_0032ED70 | 280 | matched -> src/cod/sa_0032ed70.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; d->buf[i] indexed in each branch) | 4 | 67s | m2c + hand | func_0032ED70 |
| 2026-10-17T12:03:58Z | func_0037FD28 | 280 | matched -> src/cod/sa_0037fd28.c (new unit; per-file: sn default; uses include/godhand/menuCtl.h, failure block via goto at the end) | 3 | 69s | m2c + hand | func_0037FD28 |
| 2026-10-17T12:04:52Z | func_003812B0 | 280 | matched -> src/cod/sa_003812b0.c (new unit; per-file: sn default; uses MenuInfo from menuCtl.h) | 2 | 48s | m2c + hand | func_003812B0 |
| 2026-10-17T12:06:41Z | func_00381BC8 | 280 | matched -> src/cod/sa_00381bc8.c (new unit; per-file: sn default; long for the 8-byte name field, destination pointer local) | 3 | 103s | m2c + hand | func_00381BC8 |
| 2026-10-17T12:08:06Z | cCoreSave_loadStageState | 284 | matched -> src/cod/sa_001f9cb0.c (new unit; per-file: sn default; uses cCoreSave.h and player.h; file named for the first instruction 0x1F9CB0) | 5 | 83s | m2c + hand | cCoreSave_loadStageState |
| 2026-10-17T12:10:44Z | func_001FCBA0 | 284 | NM -> src/cod/sa_nm_001fcba0.c (sn; unlink loop, retail reloads p->next in the bnel slot with a nop-led loop head) | 2 | 151s | m2c + hand | func_001FCBA0 |
| 2026-10-17T12:11:36Z | func_002C9950 | 284 | NM -> src/cod/sa_nm_002c9950.c (sn; 24 diffs, register roles in both sort passes) | 3 | 52s | m2c + hand | func_002C9950 |
| 2026-10-17T12:13:56Z | func_003315D8 | 284 | NM -> src/cod/sa_nm_003315d8.c (cygnus dr; 18 diffs, ret pseudo in a0 plus a final move where retail uses v0) | 4 | 126s | m2c + hand | func_003315D8 |
| 2026-10-17T12:16:47Z | func_0033C7F8 | 284 | matched -> src/cod/sa_0033c7f8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; memset declared returning void *) | 3 | 171s | m2c + hand | func_0033C7F8 |
| 2026-10-17T12:18:55Z | func_00352F40 | 284 | NM -> src/cod/sa_nm_00352f40.c (cygnus dr; 8 diffs, v0/v1 swap between rate*50 and 0x3FFFF) | 3 | 127s | m2c + hand | func_00352F40 |
| 2026-10-17T12:20:46Z | func_00365D90 | 284 | NM -> src/cod/sa_nm_00365d90.c (cygnus dr; 63 diffs, retail spills arg/ny to the stack and keeps dst in fp; outer-loop entry layout differs) | 2 | 57s | m2c + hand | func_00365D90 |
| 2026-10-17T12:22:34Z | func_00366EC0 | 284 | matched -> src/cod/sa_00366ec0.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; loop accumulators through locals, cur set inside the flag test) | 2 | 108s | m2c + hand | func_00366EC0 |
| 2026-10-17T12:24:06Z | func_0036BA50 | 284 | matched -> src/cod/sa_0036ba50.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; for loop with p = base + i at the top, r = v == 8 ? -1 : 0 then v == 9 override) | 2 | 91s | m2c + hand | func_0036BA50 |
| 2026-10-17T12:26:23Z | func_00379F00 | 284 | NM -> src/cod/sa_nm_00379f00.c (sn; 10 diffs, &pos[page] address fold and pos/pp/step register shift) | 2 | 135s | m2c + hand | func_00379F00 |
| 2026-10-17T12:30:29Z | func_003BA3D8 | 284 | NM -> src/cod/sa_nm_003ba3d8.c (cygnus dr; 2 diffs, delay-slot pass picks likely/non-likely the other way on two branches; flag probes tried) | 2 | 246s | m2c + hand | func_003BA3D8 |
| 2026-10-17T12:35:24Z | func_00103760 | 288 | NM -> src/cod/sa_nm_00103760.c (sn; 2 diffs, case-1 timer/phase store order trades off against the 300/7 registers; full order sweep) | 2 | 295s | m2c + hand | func_00103760 |
| 2026-10-17T12:40:33Z | func_0012CAE0 | 288 | matched -> src/cod/sa_0012cae0.c (new unit; per-file: sn default; unsigned long flag shift for dsrl, int one shared by mode store and return) | 2 | 309s | m2c + hand | func_0012CAE0 |
| 2026-10-17T12:50:53Z | func_001495A0 | 288 | matched -> src/cod/sa_001495a0.c (new unit; per-file: sn default; uses cModel.h; tint pointer local, [i - 1] countdown loop, tail store order from a 720-order sweep) | 2 | 619s | m2c + hand | func_001495A0 |
| 2026-10-17T12:51:35Z | func_002C9D58 | 288 | matched -> src/cod/sa_002c9d58.c (new unit; per-file: sn default; five retry while loops) | 1 | 41s | m2c + hand | func_002C9D58 |
| 2026-10-17T12:54:36Z | func_0033AA48 | 288 | NM -> src/cod/sa_nm_0033aa48.c (cygnus dr; 1 diff, init-test bnez slot filled as likely; ok-local variant fixes it but moves the compare to a0) | 2 | 180s | m2c + hand | func_0033AA48 |

BATCH 80: 15 matched, 14 NM, 1 skipped; 0 NM closer handoffs received, 0 registered, 0 rejected. Per-file settings (new units): sn default for sa_003943d0, sa_00298db8, sa_0031bb80, sa_0037fd28, sa_003812b0, sa_00381bc8, sa_001f9cb0, sa_0012cae0, sa_001495a0, sa_002c9d58; cygnus-2.96 with -freorder-blocks dropped for sa_003600e8, sa_0032ed70, sa_0033c7f8, sa_00366ec0, sa_0036ba50. Order sweeps for func_00103760 and func_001495A0 were plain loops over hand-written statement orders, not the permuter. Reseed 80a rc=0 in 38s (anchor func_002C9D58; a first run anchored on the parked func_0033AA48 exited rc=1 because that anchor is not carved, hashes were unaffected), ELF and r207.rel hashes OK.
| 2026-10-17T13:06:18Z | func_0035BDD0 | 288 | matched -> src/cod/sa_0035bdd0.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local Sfd35BDD0/Cond35BDD0) | 2 | 62s | m2c + hand | func_0035BDD0 |
| 2026-10-17T13:07:47Z | func_0036EB58 | 288 | NM -> src/cod/sa_nm_0036eb58.c (cygnus dr; 58 diffs, extra temp pseudo in the byte-read chain shifts registers) | 2 | 87s | m2c + hand | func_0036EB58 |
| 2026-10-17T13:09:41Z | func_0037FE78 | 288 | matched -> src/cod/sa_0037fe78.c (new unit; per-file: sn default; local Slot37FE78) | 2 | 114s | m2c + hand | func_0037FE78 |
| 2026-10-17T13:11:56Z | func_00394F20 | 288 | NM -> src/cod/sa_nm_00394f20.c (sn; 5 diffs, list-walk tail bnel+lw vs nop+bne+lw, hi reg v0/v1) | 2 | 134s | m2c + hand | func_00394F20 |
| 2026-10-17T13:13:11Z | func_001B8868 | 292 | matched -> src/cod/sa_001b8868.c (new unit; per-file: sn default; local Dmg1B8868/Obj1B8868) | 2 | 75s | m2c + hand | func_001B8868 |
| 2026-10-17T13:13:58Z | func_001F0CE8 | 292 | matched -> src/cod/sa_001f0ce8.c (new unit; per-file: sn default; uses ColiseumBattle.h, local EmWrap1F0CE8) | 1 | 46s | m2c + hand | func_001F0CE8 |
| 2026-10-17T13:17:10Z | func_001A6FB0 | 292 | NM -> src/cod/sa_nm_001a6fb0.c (sn; inlined range-check C++ bool idiom, retail branchy andi 0xFF vs movn/movz) | 2 | 183s | m2c + hand | func_001A6FB0 |
| 2026-10-17T13:18:18Z | func_00305A68 | 292 | matched -> src/cod/sa_00305a68.c (new unit; per-file: sn default; local Res305A68/GW305A68/Esp305A68) | 3 | 60s | m2c + hand | func_00305A68 |
| 2026-10-17T13:18:52Z | func_00355130 | 292 | matched -> src/cod/sa_00355130.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local Sub355130/Ctx355130) | 1 | 33s | m2c + hand | func_00355130 |
| 2026-10-17T13:20:47Z | func_00360B18 | 292 | matched -> src/cod/sa_00360b18.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local Tm360B18) | 2 | 108s | m2c + hand | func_00360B18 |
| 2026-10-17T13:24:57Z | func_0037A4C8 | 292 | matched -> src/cod/sa_0037a4c8.c (new unit; per-file: sn default; local Snd37A4C8) | 2 | 244s | m2c + hand | func_0037A4C8 |
| 2026-10-17T13:25:39Z | func_00133670 | 296 | matched -> src/cod/sa_00133670.c (new unit; per-file: sn default; local Vec133670, SETV macro) | 1 | 41s | m2c + hand | func_00133670 |
| 2026-10-17T13:35:00Z | func_0019AA80 | 296 | NM -> src/cod/sa_nm_0019aa80.c (sn; emDamageVol tail store schedule, 400+ orders tried) | 2 | 554s | m2c + hand | func_0019AA80 |
| 2026-10-17T13:43:03Z | func_0019AD00 | 296 | NM -> src/cod/sa_nm_0019ad00.c (sn; sibling of 0019AA80, two tail stores swapped after hill climb) | 2 | 449s | m2c + hand | func_0019AD00 |
| 2026-10-17T13:44:14Z | func_0019EA20 | 296 | matched -> src/cod/sa_0019ea20.c (new unit; per-file: sn default; uses emDamageVol.h) | 3 | 71s | m2c + hand | func_0019EA20 |
| 2026-10-17T13:45:20Z | func_00200B88 | 296 | matched -> src/cod/sa_00200b88.c (new unit; per-file: sn default; uses cDvd.h) | 1 | 46s | m2c + hand | func_00200B88 |
| 2026-10-17T13:48:01Z | func_0028EBF0 | 296 | NM -> src/cod/sa_nm_0028ebf0.c (sn; same range-check bool idiom as 001A6FB0, best 32 diffs) | 2 | 152s | m2c + hand | func_0028EBF0 |
| 2026-10-17T13:50:15Z | func_00335F20 | 296 | NM -> src/cod/sa_nm_00335f20.c (cygnus dr; 4 diffs, v0/v1 constant swap on final two = 1 stores) | 2 | 120s | m2c + hand | func_00335F20 |
| 2026-10-17T13:53:13Z | func_0033A8D0 | 296 | NM -> src/cod/sa_nm_0033a8d0.c (cygnus dr; 1 diff, bnel vs bnez + sltiu delay slot) | 3 | 177s | m2c + hand | func_0033A8D0 |
| 2026-10-17T13:53:43Z | func_003443E0 | 296 | matched -> src/cod/sa_003443e0.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local Vt3443E0/Obj3443E0/Mwsf3443E0) | 1 | 23s | m2c + hand | func_003443E0 |
| 2026-10-17T13:56:31Z | func_00375380 | 296 | NM -> src/cod/sa_nm_00375380.c (sn; 2 diffs, T0_COUNT load scheduled before frame addiu in retail) | 2 | 162s | m2c + hand | func_00375380 |
| 2026-10-17T13:59:37Z | func_00139C88 | 300 | matched -> src/cod/sa_00139c88.c (new unit; per-file: sn default; old-g++ PMF call emulated via copied table, local Pmf139C88/PmfTbl139C88/VtEnt139C88/Cam139C88) | 3 | 159s | m2c + hand | func_00139C88 |
| 2026-10-17T14:03:36Z | func_001C28A0 | 300 | NM -> src/cod/sa_nm_001c28a0.c (sn; range-check bool idiom, InRange pointer-param variant adds movz) | 2 | 229s | m2c + hand | func_001C28A0 |
| 2026-10-17T14:04:39Z | cSnd_GetStageBgmReq | 300 | NM -> src/cod/sa_nm_csnd_getstagebgmreq.c (sn; PARK, C++ bool helper v0=0/bnez/v0=1/andi 0xFF folded to a direct branch by C) | 2 | 63s | m2c + hand | cSnd_GetStageBgmReq |

BATCH 81: 13 matched, 11 NM, 0 skipped; 0 NM closer handoffs received, 0 registered, 0 rejected. Per-file settings (new units): sn default for sa_0037fe78, sa_001b8868, sa_001f0ce8, sa_00305a68, sa_0037a4c8, sa_00133670, sa_0019ea20, sa_00200b88, sa_00139c88; cygnus-2.96 with -freorder-blocks dropped for sa_0035bdd0, sa_00355130, sa_00360b18, sa_003443e0. Reseed anchor func_00139C88: elf=OK overlay=OK (build/sa/reseed81a.log). func_0037E368 carried to batch 82.
| 2026-10-17T14:08:58Z | func_0032A018 | 300 | matched -> src/cod/sa_0032a018.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local Adxt32A018) | 1 | 73s | m2c + hand | func_0032A018 |
| 2026-10-17T14:10:39Z | func_0032B1C8 | 300 | matched -> src/cod/sa_0032b1c8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local Adxt32B1C8/Sj32B1C8/SjIf32B1C8) | 1 | 100s | m2c + hand | func_0032B1C8 |
| 2026-10-17T14:11:37Z | func_0013ED28 | 304 | matched -> src/cod/sa_0013ed28.c (new unit; per-file: sn default; local IDWork13ED28/Ent13ED28/Scr13ED28) | 1 | 56s | m2c + hand | func_0013ED28 |
| 2026-10-17T14:13:06Z | func_001F60D8 | 304 | matched -> src/cod/sa_001f60d8.c (new unit; per-file: sn default; local Menu1F60D8) | 1 | 88s | m2c + hand | func_001F60D8 |
| 2026-10-17T14:21:24Z | func_002CA798 | 304 | matched -> src/cod/sa_002ca798.c (new unit; per-file: sn default; cBgmData_LoadNumbered declared returning int) | 1 | 45s | m2c + hand | func_002CA798 |
| 2026-10-17T14:24:18Z | func_002E0DE8 | 304 | NM -> src/cod/sa_nm_002e0de8.c (sn; 14 diffs, div-trap constant placement) | 1 | 168s | m2c + hand | func_002E0DE8 |
| 2026-10-17T14:27:52Z | func_00325A58 | 304 | matched -> src/cod/sa_00325a58.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; volatile globals) | 1 | 195s | m2c + hand | func_00325A58 |
| 2026-10-17T14:30:27Z | func_00345BE0 | 304 | NM -> src/cod/sa_nm_00345be0.c (cygnus dr; interblock-sched hoist not reproduced) | 1 | 122s | m2c + hand | func_00345BE0 |
| 2026-10-17T14:33:02Z | func_00345F48 | 304 | NM -> src/cod/sa_nm_00345f48.c (cygnus dr; 4 diffs, v0/v1 swap; MWSFSVM_Error is variadic but mwsfHn.h declares 1 param) | 1 | 147s | m2c + hand | func_00345F48 |
| 2026-10-17T14:34:23Z | func_00143BE8 | 308 | matched -> src/cod/sa_00143be8.c (new unit; per-file: sn default; local IDBase143BE8/IDObj143BE8) | 1 | 41s | m2c + hand | func_00143BE8 |
| 2026-10-17T14:36:07Z | func_001EC928 | 308 | matched -> src/cod/sa_001ec928.c (new unit; per-file: sn default; local Vec1EC928) | 1 | 103s | m2c + hand | func_001EC928 |
| 2026-10-17T14:39:22Z | func_0032D720 | 308 | NM -> src/cod/sa_nm_0032d720.c (cygnus dr; 7 diffs) | 1 | 192s | m2c + hand | func_0032D720 |
| 2026-10-17T14:40:03Z | func_00336BA8 | 308 | matched -> src/cod/sa_00336ba8.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local Ps2Work336BA8/Ps2Obj336BA8/Adxt336BA8) | 1 | 32s | m2c + hand | func_00336BA8 |
| 2026-10-17T14:45:30Z | func_00188B50 | 312 | NM -> src/cod/sa_nm_00188b50.c (sn; emDamageVol tail store schedule) | 1 | 325s | m2c + hand | func_00188B50 |
| 2026-10-17T14:45:39Z | func_002AF218 | 304 | NM -> src/cod/sa_nm_002af218.c (sn; 27 diffs, switch block placement) | 3 | 1952s | m2c + hand | func_002AF218 |
| 2026-10-17T14:46:33Z | func_001B48E0 | 312 | matched -> src/cod/sa_001b48e0.c (new unit; per-file: sn default; local Pad1B48E0/Mdl1B48E0/Em1B48E0) | 1 | 48s | m2c + hand | func_001B48E0 |
| 2026-10-17T14:48:04Z | func_001BC1C8 | 312 | matched -> src/cod/sa_001bc1c8.c (new unit; per-file: sn default; old-g++ PMF table copy, local Pmf1BC1C8/PmfTbl1BC1C8/VtEnt1BC1C8/Em1BC1C8) | 1 | 90s | m2c + hand | func_001BC1C8 |
| 2026-10-17T14:48:53Z | func_0034BA88 | 312 | matched -> src/cod/sa_0034ba88.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local Rng34BA88/Hdr34BA88/BufPtr34BA88) | 1 | 48s | m2c + hand | func_0034BA88 |
| 2026-10-17T14:51:59Z | func_0037AD88 | 312 | matched -> src/cod/sa_0037ad88.c (new unit; per-file: sn default; local Slider37AD88/Menu37AD88) | 1 | 183s | m2c + hand | func_0037AD88 |
| 2026-10-17T14:53:24Z | func_0013D400 | 316 | matched -> src/cod/sa_0013d400.c (new unit; per-file: sn default + call_loop_pad; local IDWork13D400/CustomIDWork13D400/Obj13D400) | 1 | 83s | m2c + hand | func_0013D400 |
| 2026-10-17T14:56:18Z | func_0037E368 | 288 | skipped: jump table D_0045C1D0 needs extern_jtbl, which sa_register cannot set | 0 | 0s | no | func_0037E368 |
| 2026-10-17T14:56:18Z | func_00325C90 | 304 | skipped: symbol starts with 2 foreign words before alabel func_00325C98; split boundary issue | 0 | 0s | no | func_00325C90 |

BATCH 82: 14 matched, 6 NM, 2 skipped; 3 NM closer handoffs received (func_002D40F8, func_0031C238, func_00379F00), 3 registered, 0 rejected. Per-file settings (new units): sn default for sa_0013ed28, sa_001f60d8, sa_002ca798, sa_00143be8, sa_001ec928, sa_001bc1c8, sa_0037ad88, sa_001b48e0; sn default + call_loop_pad for sa_0013d400; cygnus-2.96 with -freorder-blocks dropped for sa_0032a018, sa_0032b1c8, sa_00325a58, sa_00336ba8, sa_0034ba88. Reseed anchor func_0013D400 (after handoffs applied): elf=OK overlay=OK (build/sa/reseed82a.log). MWSFSVM_Error variadic vs 1-param mwsfHn.h prototype queued for checkpoint 90.
| 2026-10-17T15:05:23Z | func_00308DA8 | 316 | matched -> src/cod/sa_00308da8.c (new unit; per-file: sn default; incoming a1/a2 passed through to func_0012ED60 as extra params; inner loop indexes base[j]; local Rec308DA8/Ent308DA8) | 2 | 204s | m2c + hand | func_00308DA8 |
| 2026-10-17T15:08:23Z | func_00321E08 | 316 | matched -> src/cod/sa_00321e08.c (new unit; per-file: ee-2.9-991111 default; libgcc frame.c frame_init with inline start_fde_sort; local Object321E08/FdeVector321E08/FdeAccu321E08) | 1 | 75s | m2c + hand | func_00321E08 |
| 2026-10-17T15:09:51Z | func_00327568 | 316 | matched -> src/cod/sa_00327568.c (new unit; per-file: cygnus-2.96 default; local SjCk327568/SjIf327568/Sj327568/Dec327568) | 1 | 66s | m2c + hand | func_00327568 |
| 2026-10-17T15:12:13Z | func_0035F288 | 316 | matched -> src/cod/sa_0035f288.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; void* plane pointers let loads hoist above stores; local Src35F288/Inf35F288) | 2 | 127s | m2c + hand | func_0035F288 |
| 2026-10-17T15:13:54Z | func_00360298 | 316 | matched -> src/cod/sa_00360298.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; threshold table) | 2 | 80s | m2c + hand | func_00360298 |
| 2026-10-17T15:17:16Z | func_00386FA0 | 316 | matched -> src/cod/sa_00386fa0.c (new unit; per-file: sn default; local Req386FA0/Node386FA0) | 2 | 192s | m2c + hand | func_00386FA0 |
| 2026-10-17T15:18:32Z | func_0016F4A8 | 316 | NM -> src/cod/sa_nm_0016f4a8.c (sn; 2 diffs, store order 0x5EC/0x548) | 2 | 1309s | m2c + hand | func_0016F4A8 |
| 2026-10-17T15:19:50Z | func_002A5D80 | 320 | matched -> src/cod/sa_002a5d80.c (new unit; per-file: sn default; local Cfg2A5D80) | 1 | 71s | m2c + hand | func_002A5D80 |
| 2026-10-17T15:25:34Z | func_002AC878 | 320 | NM -> src/cod/sa_nm_002ac878.c (sn + -ffast-math + fp_hazard_rules sqrt,fdiv probed; 18 diffs, sqrt.s scheduling barrier not reproduced) | 2 | 335s | m2c + hand | func_002AC878 |
| 2026-10-17T15:27:19Z | func_0036C790 | 320 | matched -> src/cod/sa_0036c790.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; local DevStat36C790/DevObj36C790) | 2 | 96s | m2c + hand | func_0036C790 |
| 2026-10-17T15:35:44Z | func_00140718 | 324 | matched -> src/cod/sa_00140718.c (new unit; per-file: sn default; local Menu140718/Item140718/IDWork140718) | 2 | 55s | m2c + hand | func_00140718 |
| 2026-10-17T15:38:18Z | func_0015AF30 | 324 | NM -> src/cod/sa_nm_0015af30.c (sn + -ffast-math + fp_hazard_rules probed; 17 diffs, &local CSE vs rematerialisation) | 1 | 153s | m2c + hand | func_0015AF30 |
| 2026-10-17T15:41:28Z | func_001BD780 | 324 | matched -> src/cod/sa_001bd780.c (new unit; per-file: sn default; cSnd_SeCall_2CB8A0 declared returning int; local Om1BD780) | 2 | 181s | m2c + hand | func_001BD780 |
| 2026-10-17T15:47:16Z | func_001F3118 | 324 | NM -> src/cod/sa_nm_001f3118.c (sn; 69 diffs; switch tree fixed by empty case 2; lw vs lwu flag test, colour mask fold, uninitialised CidColor locals in a3 vs t0) | 2 | 231s | m2c + hand | func_001F3118 |
| 2026-10-17T15:52:27Z | func_002CAF28 | 324 | NM -> src/cod/sa_nm_002caf28.c (cygnus dr closest, 65 diffs; C++-style bool materialisation; 0.1f rounding points at sn C++, which match_check cannot compile) | 3 | 219s | m2c + hand | func_002CAF28 |
| 2026-10-17T15:55:23Z | func_002F2898 | 324 | matched -> src/cod/sa_002f2898.c (new unit; per-file: sn default; int count via if/else store, inline Vec4 setter taking three floats, inline guarded Vec3 copy; local Vec2F2898/Vec4F2898/Prm2F2898/Act2F2898) | 3 | 171s | m2c + hand | func_002F2898 |
| 2026-10-17T15:56:33Z | func_00320800 | 324 | matched -> src/cod/sa_00320800.c (new unit; per-file: ee-2.9-991111 default; libgcc2 find_exception_handler verbatim; local __eh_info/exception_table/exception_descriptor) | 1 | 63s | m2c + hand | func_00320800 |
| 2026-10-17T15:59:50Z | func_00330920 | 324 | NM -> src/cod/sa_nm_00330920.c (cygnus dr; 29 diffs, second-loop guard delay slot filled from target vs retail fall-through) | 3 | 188s | m2c + hand | func_00330920 |
| 2026-10-17T16:03:19Z | func_001B0838 | 316 | matched (NM upgrade) -> src/cod/sa_001b0838.c (sn default; cSnd_SeCall_2CBA48 declared returning int; sa_nm_001b0838.c deleted; local Pmf1B0838/VtEnt1B0838/Om1B0838) | 1 | ~240s | no (existing body + return-type fix) | func_001B0838 |
| 2026-10-17T16:03:19Z | func_00345F48 | 304 | matched (NM upgrade, void->int sweep) -> src/cod/sa_00345f48.c (cygnus-2.96, -freorder-blocks dropped; GetField0OrZero_346828, MWSFD_GetPauseBdr, SFD_GetCond, func_00356F48, func_00345750 declared returning int; sa_nm_00345f48.c deleted) | 1 | 14s | no (existing body + return-type fix) | func_00345F48 |
| 2026-10-17T16:03:19Z | func_00352F40 | 284 | matched (NM upgrade, void->int sweep) -> src/cod/sa_00352f40.c (cygnus-2.96, -freorder-blocks dropped; func_00366960 declared returning int; sa_nm_00352f40.c deleted) | 1 | 5s | no (existing body + return-type fix) | func_00352F40 |
| 2026-10-17T16:03:19Z | func_003533A8 | 264 | matched (NM upgrade, void->int sweep) -> src/cod/sa_003533a8.c (cygnus-2.96, -freorder-blocks dropped; func_0036A300, GetArrayElemA0C_35A1C8 declared returning int; sa_nm_003533a8.c deleted) | 1 | 5s | no (existing body + return-type fix) | func_003533A8 |
| 2026-10-17T16:03:19Z | func_003566E8 | 164 | NM improved 5 -> 1 diff (void->int sweep: func_0039AA38, viBufAddDMA, sfmpvp_PutVibuf declared returning int); bnel vs bne remains -> src/cod/sa_nm_003566e8.c | 1 | 5s | no (existing body + return-type fix) | func_003566E8 |
| 2026-10-17T16:03:19Z | func_00374B70 | 320 | matched (NM upgrade) -> src/cod/sa_00374b70.c (sn default; func_003758E8 declared returning int; NM file deleted; local BankHdr374B70/Bank374B70/Ext374B70/Cmd374B70) | 1 | ~180s | no (existing body + return-type fix) | func_00374B70 |
| 2026-10-17T16:03:19Z | func_00375988 | 240 | matched (NM upgrade of batch row at line 1367) -> src/cod/sa_00375988.c (sn default; func_003758E8 declared returning int; sa_nm_00375988.c deleted; local BankHdr375988) | 1 | ~60s | no (existing body + return-type fix) | func_00375988 |

BATCH 83: 18 matched (12 new units + 6 NM upgrades: func_001B0838, func_00374B70, func_00375988 via int-returning callees; func_00345F48, func_00352F40, func_003533A8 via the void->int callee sweep over all sa_nm files), 6 NM, 0 skipped; func_003566E8 NM improved 5 -> 1. 5 NM closer handoffs received (func_002BB2D8, func_002E2800, func_00335F20, func_00375380, func_00375988), 3 registered (func_002BB2D8, func_00335F20, func_00375380), 2 rejected (func_002E2800: inline asm/.word; func_00375988: already matched this batch, no NM source). Per-file settings (new units): sn default for sa_00308da8, sa_00386fa0, sa_002a5d80, sa_00140718, sa_001bd780, sa_002f2898; ee-2.9-991111 default for sa_00321e08, sa_00320800 (libgcc); cygnus-2.96 default for sa_00327568; cygnus-2.96 with -freorder-blocks dropped for sa_0035f288, sa_00360298, sa_0036c790. Reseed anchor func_00320800 (after handoffs applied): elf=OK overlay=OK (build/sa/reseed83.log).
| 2026-10-17T17:37:03Z | func_00317FF0 | 328 | NM -> src/cod/sa_nm_00317ff0.c (sn; PARK, best 76; beql vs beq on the end!=0 copy, frame 128 vs 112) | 3 | 1803s | m2c + hand | func_00317FF0 |
| 2026-10-17T17:37:03Z | func_00356B10 | 328 | NM -> src/cod/sa_nm_00356b10.c (cygnus dr; STOP at 6, best 23; work coalesced into s0 instead of s2, -fno-gcse did not move it) | 6 | 1801s | m2c + hand | func_00356B10 |
| 2026-10-17T17:37:03Z | func_003B2708 | 328 | NM -> src/cod/sa_nm_003b2708.c (cygnus dr; STOP; $gp save/restore around jalr then sync; ei, real-C rule excludes gp.h/eesyscall asm; real score 91) | 2 | 1798s | m2c + hand | func_003B2708 |
| 2026-10-17T17:37:03Z | func_002D8EB0 | 328 | NM -> src/cod/sa_nm_002d8eb0.c (sn; PARK, score 79; 0x16100 table search, lq/sq are the SN spill) | 2 | 1823s | m2c + hand | func_002D8EB0 |
| 2026-10-17T17:37:03Z | func_0030FB70 | 332 | NM -> src/cod/sa_nm_0030fb70.c (sn; STOP at 6, best 68; &global gives the addiu, count stays in a1 not a0) | 6 | 1226s | m2c + hand | func_0030FB70 |
| 2026-10-17T17:37:03Z | func_00376080 | 332 | NM -> src/cod/sa_nm_00376080.c (sn; 1 attempt, 63 diffs; zero halfword stores scheduled early) | 1 | 1226s | m2c + hand | func_00376080 |

BATCH 84: 0 matched, 6 NM, 0 skipped. The six function clocks overlap (one drafting pass), so the seconds column must not be summed; span is 17:06Z to 17:37Z. 2 NM closer handoffs received (func_002E2800 resubmitted after the union member was renamed flags, func_0032D720), 2 registered, 0 rejected. Per-file settings (new units): sn default for sa_002e2800; cygnus-2.96 with -freorder-blocks dropped for sa_0032d720. Reseed anchor func_0032D720: elf=OK overlay=OK (build/sa/reseed84.log, link wall 43s). nm_prune: 0 stale.
| 2026-10-17T17:46:59Z | func_00103760 | 288 | matched (NM closer handoff) -> src/cod/sa_00103760.c (new unit; per-file: sn default; local Obj103760) | 0 | 2s | no (handoff) | func_00103760 |

HALT after this handoff. Reseed anchor func_00103760: elf=OK overlay=OK (build/sa/reseed85.log, link wall 24s). Inbox empty. No further matching.

REBASE 2026-10-17: tree moved to /Users/joncaceres/god-hand-decomp (branch work) on top of upstream. Rows above use pre-rebase names and files; 419 of the functions logged here were also matched upstream and now live in upstream's TUs under upstream's names. Batch 84's NM files and the func_00103760 handoff are not on this branch. Linked: 1440536 / 2836384 (50.7878%), 9113 functions. Cold build elf=OK overlay=OK.
