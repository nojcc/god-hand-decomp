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
| 2026-10-18T13:46:24Z | __start_cp_handler | 56 | matched -> src/cod/sa_00321288.c (new unit; per-file: ee-2.9-991111 default; gcc 2.95 exception.cc, caught is an int word at 0x14, returns the info pointer) | 1 | 898.2 | hand | __start_cp_handler |
| 2026-10-18T13:46:24Z | func_003448B0 | 68 | matched -> src/cod/sa_003448b0.c (new unit; per-file: cygnus-2.96, -freorder-blocks dropped; MWSFSVM_Error declared noreturn, if/else-if) | 4 | 898.2 | hand | func_003448B0 |
| 2026-10-18T13:46:25Z | func_003257C8 | 80 | NM -> src/cod/sa_nm_003257c8.c (cygnus dr and sn; PARK, best 21; six long stores, %lo folded into sd) | 3 | 898.2 | hand | func_003257C8 |
| 2026-10-18T13:46:25Z | __deregister_frame_info | 120 | NM -> src/cod/sa_nm_003224f8.c (ee-2.9-991111; PARK, best 20; libgcc frame.c, prologue schedule and bnel vs bne) | 3 | 898.2 | hand | __deregister_frame_info |
| 2026-10-18T13:46:25Z | func_00341EC0 | 64 | NM -> src/cod/sa_nm_00341ec0.c (cygnus dr; NEAR-MISS, best 1; bne vs bnel on the kind==2 test) | 3 | 898.3 | hand | func_00341EC0 |
| 2026-10-18T13:46:25Z | cScenario_execUpCutData | 120 | NM -> src/cod/sa_nm_002c4150.c (sn; PARK, best 18; task id stays in v0, 0x58 scale adds into the base) | 3 | 898.2 | hand | cScenario_execUpCutData |
| 2026-10-18T13:46:25Z | func_00352258 | 60 | NM -> src/cod/sa_nm_00352258.c (cygnus dr; STOP near-miss, best 2; empty barrier blocks the tail call, mult and sd ra still swapped) | 6 | 898.4 | hand | func_00352258 |
| 2026-10-18T13:46:25Z | func_00353348 | 92 | NM -> src/cod/sa_nm_00353348.c (cygnus dr; PARK, best 28; ==3 test hoisted out of its block) | 3 | 439.3 | m2c + hand | func_00353348 |
| 2026-10-18T13:46:25Z | func_003769B0 | 96 | NM -> src/cod/sa_nm_003769b0.c (sn; PARK, best 16; key!=0 test is beq, retail bnel with the load in the delay) | 3 | 439.2 | m2c + hand | func_003769B0 |
| 2026-10-18T13:46:25Z | func_003B28FC | 4 | skipped: lone jr $ra, both cygnus and sn add the delay nop (2 words vs retail 1; the slot is the next function) | 2 | 47.9 | no | func_003B28FC |

BATCH 85: 2 matched, 7 NM, 1 skipped. Clocks overlap (one pass); do not sum the seconds column. Span is the 898s rows. 0 NM closer handoffs received, 0 registered, 0 rejected. Per-file settings (new units): ee-2.9-991111 default for src/cod/sa_00321288.c (compiler already used by src/cod/00321240.cc); cygnus-2.96 with -freorder-blocks dropped for src/cod/sa_003448b0.c. Reseed anchor func_003448B0: elf=OK overlay=OK (build/sa_reseed.log, link wall 46s). nm_prune: 0 stale. Not attempted, C cannot express them: func_00100250 (syscall 0x23), func_003B63A0 (mfc0/di).
| 2026-10-18T13:55:47Z | func_0030DA08 | 208 | matched -> src/cod/sa_0030da08.c (new unit; per-file: sn default; cMovie_Start/GetStatus/Stop, then the two boot tasks on D_00752C00) | 1 | 421.8 | m2c + hand | func_0030DA08 |
| 2026-10-18T13:55:48Z | func_003BBEC0 | 92 | NM -> src/cod/sa_nm_003bbec0.c (cygnus dr; PARK, best 23; char sign-extend and lui/ori of -1) | 3 | 422.0 | m2c + hand | func_003BBEC0 |
| 2026-10-18T13:55:48Z | func_003B9F60 | 84 | NM -> src/cod/sa_nm_003b9f60.c (sn; STOP, best 8; address in v0 and counter set before the load; dead tail is beql) | 6 | 422.0 | m2c + hand | func_003B9F60 |
| 2026-10-18T13:55:48Z | func_0031CDC0 | 120 | NM -> src/cod/sa_nm_0031cdc0.c (sn; PARK, best 26; null test is beq, retail bnel with the load in the delay) | 3 | 422.0 | m2c + hand | func_0031CDC0 |

BATCH 86: 1 matched, 3 NM, 0 skipped. Clocks overlap; do not sum the seconds column. 0 NM closer handoffs received, 0 registered, 0 rejected. Per-file settings (new units): sn default for src/cod/sa_0030da08.c. Reseed anchor func_0030DA08: elf=OK overlay=OK (build/sa_reseed.log, link wall 125s). nm_prune: 0 stale.

| 2026-10-18T14:23:57Z | func_00327418 | 332 | matched -> src/cod/sa_00327418.c (new unit; per-file: cygnus default; pending at 0xA0, probe id 0, clear then put on id 1) | 1 | 617.2 | near-clone | func_00327418 |
| 2026-10-18T14:23:57Z | func_00195D08 | 332 | matched -> src/cod/sa_00195d08.c (new unit; per-file: sn default; volume 5.2/0.8/2.4, m[1]=-0.4, damage-take flag or 1, kind 5) | 5 | 617.2 | near-clone | func_00195D08 |
| 2026-10-18T14:23:57Z | func_0032D868 | 332 | NM -> src/cod/sa_nm_0032d868.c (cygnus dr; STOP, best 66; beql vs beq on the null test, second message lui missing) | 6 | 397.9 | m2c + hand | func_0032D868 |

BATCH 87: 2 matched, 1 NM, 0 skipped, plus 1 NM closer handoff. Clocks overlap; do not sum the seconds column. Handoffs: 1 received (func_003780F8), 1 registered -> src/cod/sa_003780f8.c (sn default), 0 rejected. Per-file settings (new units): sn default for src/cod/sa_00195d08.c and src/cod/sa_003780f8.c; cygnus-2.96 default for src/cod/sa_00327418.c. Reseed anchor func_00195D08: elf=OK overlay=OK (build/sa_reseed.log, link wall 109s). nm_prune: 0 stale.
| 2026-10-18T14:32:09Z | func_00347498 | 332 | NM -> src/cod/sa_nm_00347498.c (cygnus dr; PARK, best 70; sj/rec saved in the other order, 0x188 pointer formed early) | 3 | 289.5 | m2c + hand | func_00347498 |
| 2026-10-18T14:32:09Z | func_00348670 | 332 | matched -> src/cod/sa_00348670.c (new unit; per-file: cygnus dr; snapshot unk3C before the slot pointer reuses the object reg) | 2 | 54.6 | m2c + hand | func_00348670 |

BATCH 88: 1 matched, 1 NM, 0 skipped. 0 NM closer handoffs received, 0 registered, 0 rejected. Per-file settings (new units): cygnus-2.96 with -freorder-blocks dropped for src/cod/sa_00348670.c. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, link wall 85s). nm_prune: 0 stale.
| 2026-10-18T14:36:10Z | func_0034C3A8 | 332 | NM -> src/cod/sa_nm_0034c3a8.c (cygnus dr; PARK, best 82; mode test is beq, retail bnel with the total load in the delay) | 3 | 136.0 | m2c + hand | func_0034C3A8 |
| 2026-10-18T14:36:10Z | func_0030B148 | 336 | skipped: ends in sync; ei, which C cannot express | 1 | 10.8 | no | func_0030B148 |

BATCH 89: 0 matched, 1 NM, 1 skipped. 0 NM closer handoffs received, 0 registered, 0 rejected. No new per-file settings. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, link wall 87s). nm_prune: 0 stale.

| 2026-10-18T14:39:52Z | func_0017AC90 | 336 | NM -> src/cod/sa_nm_0017ac90.c (sn; PARK, best 79; frame 0x30 and the radius is ofs[3], retail reloads 1.0 into f12) | 3 | 91.1 | hand | func_0017AC90 |

BATCH 90: 0 matched, 1 NM, 0 skipped. 0 NM closer handoffs received, 0 registered, 0 rejected. No new per-file settings. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, link wall 92s). nm_prune: 0 stale.
| 2026-10-18T14:46:03Z | func_0028A780 | 336 | NM -> src/cod/sa_nm_0028a780.c (sn; PARK, best 78; prologue matches, state test is bnel, retail beqz then beql) | 3 | 208.1 | hand | func_0028A780 |

BATCH 91: 0 matched, 1 NM, 0 skipped. 0 NM closer handoffs received, 0 registered, 0 rejected. No new per-file settings. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, link wall 105s). nm_prune: 0 stale.
| 2026-10-18T15:57:47Z | func_0028A780 | 336 | NM retry -> src/cod/sa_nm_0028a780.c (sn; STOP, best 71 from 78; switch fallthrough gives retail's beqz/beql dispatch, the dead andi after the first Rnd() is still deleted) | 6 | 61.9 | hand | func_0028A780 |
| 2026-10-18T15:59:20Z | func_0034C3A8 | 332 | NM retry -> src/cod/sa_nm_0034c3a8.c (cygnus dr; STOP, best 60 from 82; separate early returns give retail's prologue, only the three exit tests differ, rest shifted 4 words) | 6 | 154.7 | hand | func_0034C3A8 |
| 2026-10-18T16:00:27Z | func_00347498 | 332 | NM retry -> src/cod/sa_nm_00347498.c (cygnus dr; STOP, best 47 from 70; record stores before GetChunk and the 0x188 pointer formed after the search fix the registers; failure block placement differs) | 6 | 221.7 | hand | func_00347498 |
| 2026-10-18T16:01:51Z | func_0017AC90 | 336 | NM retry -> src/cod/sa_nm_0017ac90.c (sn; STOP, NEAR-MISS 3 from 79; inline getter with an int[3] local gives the dead sw of 0x2B4 and the 0x40 frame; only the 0x54A/0x250/0x548 store order differs) | 6 | 305.5 | hand | func_0017AC90 |
| 2026-10-18T16:03:03Z | func_0012F600 | 336 | matched -> src/cod/sa_0012f600.c (new unit; sn default; unsigned counters and per-block loop variables) | 3 | 59.6 | hand | func_0012F600 |
| 2026-10-18T16:06:03Z | func_0016F790 | 336 | NM -> src/cod/sa_nm_0016f790.c (sn; STOP, NEAR-MISS 2; clone of sa_0019daa8.c, sw 0x5EC / sh 0x548 swapped; two order sweeps) | 6 | 180.0 | near-clone + hand | func_0016F790 |
| 2026-10-18T16:10:52Z | func_0033A730 | 336 | NM -> src/cod/sa_nm_0033a730.c (cygnus dr; STOP, NEAR-MISS 1; used test bnel vs retail bnez, the reverse of func_0033ABD0) | 6 | 154.1 | hand | func_0033A730 |
CHECKPOINT (batches 85-91, due at 90) run before batch 92: header_merge not needed (no shared types), cold build PASSED (build/cold_cp90.log, ELF and overlay OK), PROGRESS.md entry appended.

BATCH 92: 1 matched, 2 NM, 0 skipped, plus a retry pass on four batch 88-91 parks (func_0028A780 78->71, func_0034C3A8 82->60, func_00347498 70->47, func_0017AC90 79->3); all four are now at 6 attempts, none closed. func_0032D868 was already at 6 and was not retried. The four retry clocks started together and overlap; do not sum them. 0 NM closer handoffs received, 0 registered, 0 rejected. Per-file settings (new units): sn default for src/cod/sa_0012f600.c. First reseed attempt was killed with its shell and never ran; rerun with anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 37s). nm_prune: 0 stale. Near-misses for the NM closer: func_0017AC90 (3), func_0016F790 (2), func_0033A730 (1).

| 2026-10-18T16:17:06Z | func_0016FA80 | 340 | NM -> src/cod/sa_nm_0016fa80.c (sn; PARK, NEAR-MISS 2; twin of func_0016F790, same 0x5EC/0x548 swap; 720-order and 144-order sweeps flat) | 3 | 129.7 | no | func_0016FA80 |
| 2026-10-18T16:19:39Z | func_00173258 | 340 | matched -> src/cod/sa_00173258.c (new unit; sn default; g++ vtable entries at 0x214+0x70/0x80, per-branch locals, inline vector setter for the right-to-left argument loads) | 6 | 130.5 | no | func_00173258 |
| 2026-10-18T16:20:30Z | func_0016FA80 | 340 | matched -> src/cod/sa_0016fa80.c (new unit; sn default; reopened after the park: an inline setter storing COL_A, COL_B, 0x5EC from one argument fixes the store order; NM file removed) | 6 | 38.2 | no | func_0016FA80 |
| 2026-10-18T16:21:18Z | func_00193550 | 340 | matched -> src/cod/sa_00193550.c (new unit; sn default; clone of 0019dd30.c with the damage-take active bit and count 5) | 1 | 33.6 | no | func_00193550 |
| 2026-10-18T16:22:05Z | func_001DCEF0 | 340 | matched -> src/cod/sa_001dcef0.c (new unit; sn default; static initializer in the sa_001ec928.c shape, the two rows walked with a stepping pointer) | 1 | 47.1 | no | func_001DCEF0 |
| 2026-10-18T16:23:39Z | func_001FE748 | 340 | NM -> src/cod/sa_nm_001fe748.c (sn; PARK, best 70; cDataManager slot release; retail does not share the outer 0x5C constant, saved registers shift) | 3 | 87.4 | no | func_001FE748 |
BATCH 93: 4 matched (func_00173258, func_0016FA80, func_00193550, func_001DCEF0), 1 NM (func_001FE748), 0 skipped, plus 1 NM closer handoff. func_0016FA80 was parked at attempt 3 and reopened when the inline-argument idea from func_00173258 came up; it matched at attempt 6 and its NM file was removed (both rows are above). Handoffs: 1 received (func_0017AC90, parked in batch 92 as a 3-insn near-miss), 1 registered -> src/cod/sa_0017ac90.c, 0 rejected. Per-file settings (new units): sn default for sa_00173258.c, sa_0016fa80.c, sa_00193550.c, sa_001dcef0.c. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 123s). nm_prune: 0 stale. Note for the NM closer: sa_nm_0016f790.c is the twin of func_0016FA80 and should close with the same inline setter.

| 2026-10-18T16:27:08Z | func_0034AC60 | 340 | NM -> src/cod/sa_nm_0034ac60.c (cygnus dr; STOP, best 10; ADXT open with a callback table; adxt->id load placement and cb address scheduling) | 6 | 187.2 | no | func_0034AC60 |
| 2026-10-18T16:29:06Z | func_00348E18 | 332 | matched -> src/cod/sa_00348e18.c (new unit; cygnus-2.96, -freorder-blocks dropped; one slot pointer reused for both slots, one byte local for stopped/concat) | 3 | 67.9 | no | func_00348E18 |
| 2026-10-18T16:31:41Z | func_0033D720 | 336 | NM -> src/cod/sa_nm_0033d720.c (cygnus dr; STOP, NEAR-MISS 2; ADX decode step, header callback loads fn before obj) | 6 | 154.6 | no | func_0033D720 |
| 2026-10-18T16:33:42Z | sfmpv_SearchDelim | 340 | NM -> src/cod/sa_nm_003511f8.c (cygnus dr; PARK 79 at attempt 3; regalloc + block placement, logic complete) | 3 | 115.9 | no | sfmpv_SearchDelim |
| 2026-10-18T16:34:40Z | func_00360950 | 340 | matched -> src/cod/sa_00360950.c (new unit; cygnus-2.96 --drop-reorder; test the stored global, not a temp) | 2 | 57.3 | no | func_00360950 |

BATCH 94: 2 matched (func_00348E18, func_00360950), 3 NM (func_0034AC60 STOP 10, func_0033D720 STOP near-miss 2, sfmpv_SearchDelim PARK 79), 0 skipped, 0 NM closer handoffs (received 0, registered 0, rejected 0). This closes the 336-340 B band. Per-file settings (new units): cygnus-2.96 with -freorder-blocks dropped for sa_00348e18.c and sa_00360950.c. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 42s). nm_prune: 0 stale. For the NM closer: func_0033D720 only needs the header callback's obj load (0x7C) scheduled before the fn load (0x78).

| 2026-10-18T16:36:00Z | func_001AEF40 | 344 | matched -> src/cod/sa_001aef40.c (new unit; sn default; clone of func_00173258 with the jitter on z) | 1 | 50.1 | no | func_001AEF40 |
| 2026-10-18T16:36:30Z | func_001D4DF0 | 344 | matched -> src/cod/sa_001d4df0.c (new unit; sn default; ID loader in the func_001E71B8 family) | 1 | 30.0 | no | func_001D4DF0 |
| 2026-10-18T16:38:22Z | func_001DC980 | 344 | matched -> src/cod/sa_001dc980.c (new unit; sn default; int flags for the -5 mask, indexed clear loop so i+1 is computed first) | 6 | 111.3 | no | func_001DC980 |
| 2026-10-18T16:39:38Z | func_001DCAD8 | 344 | matched -> src/cod/sa_001dcad8.c (new unit; sn default; do-while inner search stops first-iteration peeling, own counter for the mark loop) | 4 | 76.0 | no | func_001DCAD8 |
| 2026-10-18T16:42:31Z | func_00288DA8 | 344 | matched -> src/cod/sa_00288da8.c (new unit; sn default; three-subtype inner switches with `case low: default: n = 0` give retail's case tree; int add offset+pack) | 6 | 173.6 | no | func_00288DA8 |
| 2026-10-18T16:45:35Z | func_002B3D70 | 344 | NM -> src/cod/sa_nm_002b3d70.c (sn; STOP 11; counter-reset store scheduled below the flags load) | 6 | 183.5 | no | func_002B3D70 |
| 2026-10-18T16:46:51Z | func_00386DE0 | 344 | NM -> src/cod/sa_nm_00386de0.c (sn; PARK 65 at attempt 3; register pairs swapped around the 0x60 block move) | 3 | 75.8 | no | func_00386DE0 |

BATCH 95: 5 matched (func_001AEF40, func_001D4DF0, func_001DC980, func_001DCAD8, func_00288DA8), 2 NM (func_002B3D70 STOP 11, func_00386DE0 PARK 65), 0 skipped, 0 NM closer handoffs (received 0, registered 0, rejected 0). This closes the 344 B band. Per-file settings (new units): sn default for sa_001aef40.c, sa_001d4df0.c, sa_001dc980.c, sa_001dcad8.c, sa_00288da8.c. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 43s). nm_prune: 0 stale.

| 2026-10-18T16:49:09Z | func_001FF858 | 348 | NM -> src/cod/sa_nm_001ff858.c (sn; PARK at attempt 3; lowercase loop keeps index + pointer in retail, tail matches) | 3 | 70.9 | no | func_001FF858 |
| 2026-10-18T16:50:02Z | func_00354478 | 348 | matched -> src/cod/sa_00354478.c (new unit; cygnus-2.96 --drop-reorder; the ring view is 0x18 bytes, which puts `found` at sp+0x20) | 2 | 52.7 | no | func_00354478 |
| 2026-10-18T16:51:58Z | func_00354650 | 348 | NM -> src/cod/sa_nm_00354650.c (cygnus dr; STOP, NEAR-MISS 2; argument move order in the second parameter call) | 6 | 116.0 | no | func_00354650 |
| 2026-10-18T16:53:08Z | func_003B9998 | 348 | matched -> src/cod/sa_003b9998.c (new unit; cygnus-2.96 --drop-reorder; &adxt->sfreq held in its own local) | 3 | 70.6 | no | func_003B9998 |

BATCH 96: 2 matched (func_00354478, func_003B9998), 2 NM (func_001FF858 PARK at attempt 3, func_00354650 STOP near-miss 2), 0 skipped, 0 NM closer handoffs (received 0, registered 0, rejected 0). This closes the 348 B band. Per-file settings (new units): cygnus-2.96 with -freorder-blocks dropped for sa_00354478.c and sa_003b9998.c (0x3B9998 is in the cygnus ADX block next to sa_003b9b20.c / sa_003b9bf0.c). Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 43s). nm_prune: 0 stale.

| 2026-10-18T16:54:21Z | func_00334F90 | 352 | matched -> src/cod/sa_00334f90.c (new unit; cygnus-2.96 --drop-reorder; seek returns long, clamp after the rewind check) | 2 | 30.1 | no | func_00334F90 |
| 2026-10-18T16:55:58Z | func_00150C10 | 352 | NM -> src/cod/sa_nm_00150c10.c (sn; PARK 17 at attempt 3; result register t0 vs a3) | 3 | 97.1 | no | func_00150C10 |
| 2026-10-18T16:58:28Z | func_0035F418 | 352 | NM -> src/cod/sa_nm_0035f418.c (cygnus dr; STOP 39; case-3 schedule and address temp registers) | 6 | 149.5 | no | func_0035F418 |
| 2026-10-18T17:00:40Z | func_0037CF00 | 352 | NM -> src/cod/sa_nm_0037cf00.c (sn; STOP near-miss 3; loop-2 prio base folding) | 6 | 131.7 | no | func_0037CF00 |

BATCH 97: 1 matched (func_00334F90), 3 NM (func_00150C10 PARK at attempt 3, func_0035F418 STOP 39, func_0037CF00 STOP near-miss 3), 0 skipped, 1 NM closer handoff (received 1, registered 1: func_00354650 -> src/cod/sa_00354650.c replacing sa_nm_00354650.c; rejected 0). This closes the 352 B band. Per-file settings (new units): cygnus-2.96 with -freorder-blocks dropped for sa_00334f90.c. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 148s). nm_prune: 0 stale.

| 2026-10-18T17:05:10Z | func_0037C930 | 356 | matched -> src/cod/sa_0037c930.c (new unit; sn; indexed node/ctl access keeps i count-up, duplicated call pair crossjumped) | 4 | 77.0 | no | func_0037C930 |
| 2026-10-18T17:06:16Z | func_003431D8 | 356 | NM -> src/cod/sa_nm_003431d8.c (cygnus dr; PARK 74 at attempt 3, best 71; pool loop not strength-reduced in retail) | 3 | 66.5 | no | func_003431D8 |
| 2026-10-18T17:08:17Z | func_00359848 | 356 | NM -> src/cod/sa_nm_00359848.c (cygnus dr; PARK 20 at attempt 4; rate/ch register swap) | 4 | 120.9 | no | func_00359848 |
| 2026-10-18T17:09:20Z | sfmpv_BsearchDelim | 356 | NM -> src/cod/sa_nm_00351350.c (cygnus dr; PARK 78 at attempt 2; same layout/regalloc gap as sfmpv_SearchDelim) | 2 | 62.7 | no | sfmpv_BsearchDelim |
| 2026-10-18T17:09:52Z | func_0037E200 | 360 | matched -> src/cod/sa_0037e200.c (new unit; sn; signed char loop index, (short)(i+5) row) | 1 | 32.3 | no | func_0037E200 |
| 2026-10-18T17:11:03Z | func_003066D0 | 360 | NM -> src/cod/sa_nm_003066d0.c (sn; PARK 36 at attempt 3; 0xFFFFFFFF loop sentinel) | 3 | 70.6 | no | func_003066D0 |

BATCH 98: 2 matched (func_0037C930, func_0037E200), 4 NM (func_003431D8 PARK at attempt 3, func_00359848 PARK at attempt 4, sfmpv_BsearchDelim PARK at attempt 2, func_003066D0 PARK at attempt 3), 0 skipped, 0 NM closer handoffs (received 0, registered 0, rejected 0). This closes the 356 B band and the 360 B band. Per-file settings (new units): none (both sn-2.95.3-136 defaults). Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 127s). nm_prune: 0 stale.

| 2026-10-18T17:15:12Z | func_002F40C0 | 364 | matched -> src/cod/sa_002f40c0.c (new unit; sn; float stores via char* arithmetic so D_005CAFF0 is reloaded, first latch as `changed = g->b != 1`) | 5 | 103.8 | no | func_002F40C0 |
| 2026-10-18T17:16:14Z | func_003ACD20 | 364 | matched -> src/cod/sa_003acd20.c (new unit; sn; newlib _malloc_trim_r, sbrked_mem as current_mallinfo.arena struct member) | 2 | 61.8 | no | func_003ACD20 |
| 2026-10-18T17:17:27Z | func_0036DE80 | 364 | NM -> src/cod/sa_nm_0036de80.c (cygnus dr; PARK 83 at attempt 3; base registers swapped, load hoisting) | 3 | 73.5 | no | func_0036DE80 |
| 2026-10-18T17:19:46Z | cOmDoor_setOpen | 364 | matched -> src/cod/sa_001bcfb0.c (new unit; sn, "as": "sn"; `long one = 1` shared by flag tests and `long kind` switch, Adjust_theta per case crossjumped) | 5 | 138.1 | no | cOmDoor_setOpen |

BATCH 99: 3 matched (func_002F40C0, func_003ACD20, cOmDoor_setOpen), 1 NM (func_0036DE80 PARK at attempt 3), 0 skipped, 0 NM closer handoffs (received 0, registered 0, rejected 0). This closes the 364 B band. Per-file settings (new units): "as": "sn" for sa_001bcfb0.c (cOmDoor_setOpen; ps2eeas keeps the mtc1/nop hazard pairs, as in the queue note); sa_002f40c0.c and sa_003acd20.c use sn-2.95.3-136 defaults. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 114s). nm_prune: 0 stale.

| 2026-10-18T17:22:18Z | func_00332398 | 368 | matched -> src/cod/sa_00332398.c (new unit; cygnus-2.96 --drop-reorder; size + buf - 1 operand order, count before state) | 2 | 143.1 | no | func_00332398 |
| 2026-10-18T17:22:54Z | func_0036EE90 | 372 | matched -> src/cod/sa_0036ee90.c (new unit; cygnus-2.96 --drop-reorder; SJ GetChunk/PutChunk via vtable) | 1 | 35.4 | no | func_0036EE90 |
| 2026-10-18T17:24:40Z | func_0034EB98 | 368 | matched -> src/cod/sa_0034eb98.c (new unit; cygnus-2.96 --drop-reorder; shared mark store via `cond ? a : b`, long pts with ternary mins, ch assigned after the guard) | 4 | 106.2 | no | func_0034EB98 |
| 2026-10-18T17:26:00Z | func_00324950 | 368 | matched -> src/cod/sa_00324950.c (new unit; cygnus-2.96 --drop-reorder; version pointer D_00755C1C and D_003C7418 volatile) | 4 | 79.4 | no | func_00324950 |
| 2026-10-18T17:27:23Z | func_002B4A50 | 368 | NM -> src/cod/sa_nm_002b4a50.c (sn; PARK 86 at attempt 3; bool byte materialisation and mask hoisting) | 3 | 83.4 | no | func_002B4A50 |

BATCH 100: 4 matched (func_00332398, func_0036EE90, func_0034EB98, func_00324950), 1 NM (func_002B4A50 PARK at attempt 3), 0 skipped, 0 NM closer handoffs (received 0, registered 0, rejected 0). Per-file settings (new units): cygnus-2.96 with -freorder-blocks dropped for sa_00332398.c, sa_0036ee90.c, sa_0034eb98.c and sa_00324950.c. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 112s). nm_prune: 0 stale. Checkpoint follows (header_merge, cold build, PROGRESS.md).

| 2026-10-18T17:39:25Z | func_001DCC30 | 372 | non-matching -> src/cod/sa_nm_001dcc30.c (near-miss 2: final two mark index adds have swapped addu operands; guarded do-while inner search stops first-iteration peeling, search via self->slot and marks via a tbl local) | 6 | 118.4 | no | slot one-pair mark (sn) |
| 2026-10-18T17:42:48Z | func_001FC810 | 372 | non-matching -> src/cod/sa_nm_001fc810.c (STOP 82: retail copies the reloaded child count into a second register for the outer bound; cnt local, inline sort, unsigned cnt, comma reload tried) | 6 | 210.2 | no | owner child sort/collect (sn) |
| 2026-10-18T17:45:30Z | cDoor_setDoorJump | 376 | non-matching -> src/cod/sa_nm_001fff80.c (near-miss 9: register choice in the lock-word block only; game-work words addressed from &D_00747A84, macros rematerialise the base after calls) | 6 | 162.4 | no | cDoor jump start (sn) |
| 2026-10-18T17:48:09Z | func_0028E858 | 376 | non-matching -> src/cod/sa_nm_0028e858.c (near-miss 8: jump vector float regs f0/f1/f2 vs f2/f0/f1 and f12 load before a0; parked at 5, no lead left) | 5 | 158.3 | no | room event end (sn) |
| 2026-10-18T17:48:55Z | func_00332C00 | 376 | matched -> src/cod/sa_00332c00.c (new unit; cygnus-2.96, -freorder-blocks dropped; first attempt) | 1 | 45.6 | no | CRI file open (cygnus dr) |
| 2026-10-18T17:49:52Z | func_00334520 | 376 | matched -> src/cod/sa_00334520.c (new unit; cygnus-2.96, -freorder-blocks dropped; info struct zeroed through a long union member gives the single sd, an initializer calls memset) | 2 | 53.5 | no | CRI file open, host device (cygnus dr) |
| 2026-10-18T17:52:37Z | func_0034E9B0 | 376 | non-matching -> src/cod/sa_nm_0034e9b0.c (near-miss 18: self/in callee-saved registers swapped only; local 8-aligned chunk type gives the by-value t0 pass) | 6 | 164.5 | no | SFD chunk header dispatch (cygnus dr) |
| 2026-10-18T17:54:37Z | func_00353630 | 376 | non-matching -> src/cod/sa_nm_00353630.c (PARK 82: register-allocation cascade only, t/rate/cnt s-regs and a0 base temp) | 4 | 119.7 | no | SFD frame due test (cygnus dr) |
| 2026-10-18T17:56:33Z | func_00376B80 | 376 | matched -> src/cod/sa_00376b80.c (new unit; sn default; -1/0x17 held in early locals across the call, fields in offset order except 41/40/43/42, tone pointer loaded then advanced in two steps) | 5 | 110.6 | no | seq note-on voice fill (sn) |
| 2026-10-18T17:57:10Z | func_003B0BA8 | 376 | skipped (libkernel thread start: context clear is inline asm, every temp in $t0 and sll $t0,$s2,0 re-sign-extension; not reachable in plain C) | 0 | 36.5 | no | libkernel thread start (inline asm) |

BATCH 101: 3 matched (func_00332C00, func_00334520, func_00376B80), 6 NM (func_001DCC30 near-miss 2, func_001FC810 STOP 82, cDoor_setDoorJump near-miss 9, func_0028E858 near-miss 8, func_0034E9B0 near-miss 18, func_00353630 PARK 82), 1 skipped (func_003B0BA8, libkernel inline asm), 0 NM closer handoffs (received 0, registered 0, rejected 0). Closes the 372 B band and most of the 376 B band. Per-file settings (new units): cygnus-2.96 with -freorder-blocks dropped for sa_00332c00.c and sa_00334520.c; sn default for sa_00376b80.c. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 46s). nm_prune: 0 stale. Near-misses 2/8/9/18 queued for the NM closer.
| 2026-10-18T18:00:27Z | func_00333CE0 | 380 | non-matching -> src/cod/sa_nm_00333ce0.c (near-miss 3: v0/v1 swap at the D_003D9DC0.unk0 test only; size/per written twice for the second div trap) | 6 | 125.5 | no | CRI file sector table (cygnus dr) |
| 2026-10-18T18:01:21Z | func_0032CA10 | 380 | matched -> src/cod/sa_0032ca10.c (new unit; cygnus-2.96, -freorder-blocks dropped; first attempt, volatile D_003C7418, SJ getChunk/putChunk loop) | 1 | 54.0 | no | ADX server end/pad (cygnus dr) |
| 2026-10-18T18:03:02Z | func_00339AE8 | 380 | non-matching -> src/cod/sa_nm_00339ae8.c (PARK 69: id/len register allocation cascade; &buf[...] address forms match) | 4 | 101.1 | no | SJ ring buffer put chunk (cygnus dr) |
| 2026-10-18T18:04:28Z | func_003520D8 | 380 | non-matching -> src/cod/sa_nm_003520d8.c (PARK 90: register allocation, &tc->last hoisted to entry here) | 3 | 85.2 | no | SFD audio time stamp (cygnus dr) |
| 2026-10-18T18:06:29Z | func_00300458 | 380 | PARK 97 -> src/cod/sa_nm_00300458.c (sn; loop-invariant hoist of switch consts differs; --as sn no effect) | 3 | 121.3 | no | obj pool alloc |
| 2026-10-18T18:09:50Z | cSnd_BgmControl | 384 | near-miss 1 nop -> src/cod/sa_nm_002d0938.c (sn + call_loop_pad; retail short-loop pad on multi-block call-free loop that ee-as won't emit; split || / nested ifs to stop bit-mask folding) | 4 | 193.6 | no | cSnd bgm |
| 2026-10-18T18:12:13Z | func_002D4C20 | 384 | PARK 18 -> src/cod/sa_nm_002d4c20.c (sn; i*step givs give retail's reversed loop; pre-call schedule differs; D_70000040 is a splitter false hi/lo pair) | 3 | 139.1 | no | dma spr |
| 2026-10-18T18:14:29Z | func_00148420 | 384 | matched -> src/cod/sa_00148420.c (sn; int temp keeps lhu un-narrowed; bool var gives sltiu/xori; two Ensure arms cross-jump so buf reloads; &d address-taken local) | 6 | 131.2 | no | obj buffer setup |
| 2026-10-18T18:17:19Z | func_0015ADA0 | 388 | PARK 62 -> src/cod/sa_nm_0015ada0.c (sn; inline QuatMul x2 + fieldwise copies; returns out; FP regalloc of q fields only) | 3 | 163.7 | no | quat rotate vec |
| 2026-10-18T18:19:17Z | func_00178618 | 388 | matched -> src/cod/sa_00178618.c (sn; clone of sa_0016fa80 pattern; separate ofs pointer for the give sphere so it isn't tied to a3) | 4 | 114.5 | no | enemy dmg setup |

BATCH 102: 3 matched (func_0032CA10, func_00148420, func_00178618), 7 NM (func_00333CE0 near-miss 3, func_00339AE8 PARK 69, func_003520D8 PARK 90, func_00300458 PARK 97, cSnd_BgmControl near-miss 1 nop, func_002D4C20 PARK 18, func_0015ADA0 PARK 62), 2 NM closer handoffs (received 2, registered 2: func_001DCC30, func_0028E858; rejected 0). Closes the 380/384 B bands and opens 388 B. Per-file settings (new units): cygnus-2.96 with -freorder-blocks dropped for sa_0032ca10.c; sn default for sa_00148420.c and sa_00178618.c. cSnd_BgmControl's NM file needs call_loop_pad if it is ever closed; its last nop is the retail short-loop pad on a multi-block call-free loop, which ee-as does not emit. func_002D4C20: retail's listing tags the scratchpad pointer as %hi/%lo(D_70000040), a splitter false pair. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 136s). nm_prune: 0 stale.
| 2026-10-18T18:22:37Z | func_00183650 | 388 | matched -> src/cod/sa_00183650.c (sn; near clone of sa_00178618 with func_001FD9D8 box and 0x5B8 |= 2) | 1 | 28.6 | no | enemy dmg setup |
| 2026-10-18T18:23:16Z | func_001DA4E8 | 388 | matched -> src/cod/sa_001da4e8.c (sn; DecCount inline from 001da2a8.c, switch on 0x3025) | 1 | 38.5 | no | poker ui |
| 2026-10-18T18:24:53Z | func_001FFA68 | 388 | matched -> src/cod/sa_001ffa68.c (sn; int d = c + 0x20; if (!isupper(c)) d = c; gives movz; strtok/strcmp node walk) | 3 | 96.8 | no | path lookup |
| 2026-10-18T18:28:21Z | func_0030B298 | 388 | near-miss 4 -> src/cod/sa_nm_0030b298.c (sn; local g = &D_007474A0, sys = &D_00747A2C - 0x58C after the flag test, int-returning PAL inlines give xori; final v0/v1 swap) | 4 | 204.1 | no | sys reset |
| 2026-10-18T18:31:25Z | func_00377150 | 388 | PARK 19 -> src/cod/sa_nm_00377150.c (sn; sibling of sa_00376b80; s1/s2 swap and tail temp regs) | 4 | 184.0 | no | seq se voice |
| 2026-10-18T18:32:59Z | func_00194558 | 392 | matched -> src/cod/sa_00194558.c (sn; SetDown inline x2, GetPart(p,1) with int on[3] spill, part computed before the SE call, cSnd_SeCall_2CBA48 returns int) | 3 | 85.3 | no | breakable obj |
| 2026-10-18T18:34:40Z | func_002A5BB8 | 392 | matched -> src/cod/sa_002a5bb8.c (sn; struct D_00752C00.task keeps base in a reg; int res for offset+base addu order; int-returning callees keep v0 out of the following temps) | 3 | 101.0 | no | system init |
| 2026-10-18T18:35:38Z | func_003336F8 | 392 | matched -> src/cod/sa_003336f8.c (cygnus dr; 5-byte struct copy gives lwl/lwr+lb; sceCdlFILE 0x24 with flag fixes the frame) | 2 | 58.2 | no | cri cd read |
| 2026-10-18T18:36:37Z | func_003367F8 | 392 | matched -> src/cod/sa_003367f8.c (cygnus dr; memory twin of 334808; `n = d; if (nsct < d) n = nsct;` gives movn) | 2 | 58.7 | no | cri mem read |
| 2026-10-18T18:37:03Z | func_00178368 | 396 | matched -> src/cod/sa_00178368.c (sn; clone of 183650 with 0.6/1.5 extents, radius one, SUB_KIND 6) | 1 | 26.4 | no | enemy setup |
| 2026-10-18T18:40:43Z | func_002C21A0 | 396 | PARK 47 -> src/cod/sa_nm_002c21a0.c (sn; SET/CLR_FLAG macros + `int n` match global path; stage-path set/clear bit regs v1/a1 unreachable) | 4 | 220.1 | no | event flags |
| 2026-10-18T18:41:30Z | func_002F3F30 | 396 | matched -> src/cod/sa_002f3f30.c (sn; sibling of 2F40C0; `*(float *)((char *)D_005CAFF0 + off)` stores force the per-store global reload) | 2 | 46.6 | no | reach obj |

BATCH 103: 9 matched (func_00183650, func_001DA4E8, func_001FFA68, func_00194558, func_002A5BB8, func_003336F8, func_003367F8, func_00178368, func_002F3F30), 3 NM (func_0030B298 near-miss 4, func_00377150 PARK 19, func_002C21A0 PARK 47), 0 NM closer handoffs (nm_solved was empty). Closes the 388/392 B bands and the first part of 396 B. Per-file settings (new units): cygnus-2.96 with -freorder-blocks dropped for sa_003336f8.c and sa_003367f8.c (CRI band); sn default for the rest. func_003336F8: the stack frame only matches when the local sceCdlFILE copy includes `flag` (0x24 bytes). func_002C21A0: the SET/CLR_FLAG macros with an `int n` local match the whole global-flag path; in the stage path retail gives the set and clear arms different bit registers, and no local split I tried reproduced it. Reseed anchor func_00348670: elf=OK overlay=OK (build/sa_reseed.log, 136s). nm_prune: 0 stale.
| 2026-10-18T18:44:41Z | func_00323CF0 | 396 | matched -> src/cod/sa_00323cf0.c (cygnus dr; sj joint vtable destroy at 0x0C) | 1 | 33.0 | no | cri stream read |
| 2026-10-18T18:45:29Z | func_00324640 | 396 | matched -> src/cod/sa_00324640.c (cygnus dr; explicit tbl32 / tbl16 base pointers at 0x11C / 0x11A) | 2 | 48.2 | no | adxf range |
| 2026-10-18T18:46:12Z | func_00354BD8 | 396 | matched -> src/cod/sa_00354bd8.c (cygnus dr; int-aligned struct assigns give the ldl/sdl copies; func_003567E0 takes p, which keeps a0 live) | 2 | 42.7 | no | request apply |
| 2026-10-18T18:49:43Z | func_00159300 | 400 | PARK 107 -> src/cod/sa_nm_00159300.c (sn + as sn for the mtc1 nops; two-search-loop form; second loop induction vars differ) | 3 | 210.9 | yes | anim curve |
| 2026-10-18T18:54:00Z | func_0017E4C8 | 400 | matched -> src/cod/sa_0017e4c8.c (sn; mode-byte stores in 2F4..2F7 order; a literal 0.0f f13 arg is what gives retail's lwc1 from the zeroed ang slot and the f1/f0 split) | 2 | 257.4 | no | gimmick state |
| 2026-10-18T18:55:29Z | func_001BF8C8 | 400 | matched -> src/cod/sa_001bf8c8.c (sn; GameWork struct `.pad` read lets loop.c hoist the full base; `long` not `unsigned long long` (SN cc1 rejects the wide op); scenario local for the slot clear) | 3 | 88.7 | no | tutorial task |
| 2026-10-18T18:59:29Z | func_00325638 | 400 | near-miss 4 -> src/cod/sa_nm_00325638.c (cygnus dr; volatile A0/FC/8148, TPrm main at 0x10; only the pair-store order is left) | 2 | 240.5 | no | cri init |
| 2026-10-18T19:02:27Z | func_00333880 | 400 | near-miss 7 -> src/cod/sa_nm_00333880.c (cygnus dr; separate `off` statement fixes the name address; ng spill only reproduced with volatile) | 3 | 177.5 | no | cd table |
| 2026-10-18T19:05:17Z | func_0037D3C8 | 400 | PARK 27 -> src/cod/sa_nm_0037d3c8.c (sn; case 9 listed before case 1; case-4 selection temp vs r/g register swap) | 2 | 169.5 | no | snd volume |
| 2026-10-18T19:08:10Z | func_00382660 | 400 | PARK 51 -> src/cod/sa_nm_00382660.c (sn; s-reg rotation of the three base pointers) | 3 | 173.8 | no | snd mixer |
| 2026-10-18T19:12:45Z | SetNextComp | 400 | matched -> src/cod/sa_003b6c28.c (ee-2.9-991111; ee-2.9 gives sibcall j only for `jal; return;` tails, head read before handling check fills bgez slot) | 2 | 274.3 | no | libkernel timer |
| 2026-10-18T19:13:23Z | func_0019DFB8 | 404 | matched -> src/cod/sa_0019dfb8.c (sn; clone of 00178368 with 1.0 height, 0x32 give id, give flags |= 1) | 1 | 31.5 | no | enemy setup |
| 2026-10-18T19:19:55Z | func_002AC6E0 | 404 | matched -> src/cod/sa_002ac6e0.c (sn + c_flags_add -ffast-math + fp_hazard_rules fdiv; one inline `__asm__ volatile("")` barrier after sqrt.s keeps dist[i-1] load late; `i*8 + (int)pts` ties i to s0; nested n>=4 block gives bnez. Same barrier likely closes NM sibling 002AC878 - NM closer note) | 4 | 392.6 | no | Catmull-Rom path |
| 2026-10-18T19:24:04Z | func_002BF568 | 404 | matched -> src/cod/sa_002bf568.c (sn; w=&gw.flags5E4 anchor, flags via (char*)w-0x5E4 keeps -0x60(s2), late gw=&D for effId, `one` var for s0 compare, 0xB0 before 0xAC store) | 2 | 249.1 | no | obj event reset |
| 2026-10-18T19:27:50Z | MoveObj | 404 | matched -> src/cod/sa_0030f090.c (sn; only first D_00747A78 read volatile-cast: orders it after T0 and forces later reloads while the loop-exit reload still fills the delay slot; `cur = it++` + continue; inline ternary count arg; `x = x - T0`) | 2 | 225.9 | no | object update |
| 2026-10-18T19:28:34Z | func_0032E488 | 404 | matched -> src/cod/sa_0032e488.c (cygnus dr; switch on kind gives compare chain then out-of-line bodies) | 2 | 44.1 | no | CRI stream frame step |
| 2026-10-18T19:32:42Z | func_00333560 | 404 | matched -> src/cod/sa_00333560.c (cygnus dr; index loop + p=&buf[i] after optional i++, separate q/r strip pointers, int-cast `nmax*8 + (int)out` and `width + (int)dst + 1` for addu operand order, table stores width/out/nmax/count) | 2 | 247.1 | yes | text line splitter |
| 2026-10-18T19:33:50Z | func_0037CAE0 | 404 | matched -> src/cod/sa_0037cae0.c (sn; st=&D_0076A790 local for s7 base; switch on sequence result with case 6 falling into case 0) | 2 | 68.4 | no | sound voice scan |

BATCH 104: 13 matched (func_00323CF0, func_00324640, func_00354BD8, func_0017E4C8, func_001BF8C8, SetNextComp, func_0019DFB8, func_002AC6E0, func_002BF568, MoveObj, func_0032E488, func_00333560, func_0037CAE0), 5 NM (func_00159300 PARK 107, func_00325638 near-miss 4, func_00333880 near-miss 7, func_0037D3C8 PARK 27, func_00382660 PARK 51). Handoffs: 3 registered from nm_solved (func_0030B298, func_00325638, func_00333CE0). Reseed OK, 136s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: cygnus-2.96 drop-reorder for sa_00323cf0/sa_00324640/sa_00354bd8/sa_0032e488/sa_00333560 and NM sa_nm_00333880; sn-2.95.3-136 default for sa_0017e4c8/sa_001bf8c8/sa_0019dfb8/sa_002bf568/sa_0030f090/sa_0037cae0 and NM sa_nm_0037d3c8/sa_nm_00382660; NM sa_nm_00159300 uses "as": "sn"; sa_002ac6e0 uses c_flags_add -f=-ffast-math plus fp_hazard_rules fdiv (both already used by 002c0cb0.c) and carries one inline `__asm__ volatile("")` scheduling barrier (the allowed single barrier); sa_003b6c28 uses ee-2.9-991111 (the libkernel timer units' compiler). New tricks: ee-2.9 emits the `j` sibcall only for a call directly followed by `return;`; a volatile cast on just the first read of a global keeps later reloads stealable into delay slots; `i*8 + (int)ptr` sets the addu operand order and the register tie.
| 2026-10-18T19:37:38Z | func_00135040 | 408 | matched -> src/cod/sa_00135040.c (sn + c_flags_add -ffast-math + fp_hazard_rules fdiv; one inline `__asm__ volatile("")` barrier after sqrt.s, same pattern as 002AC6E0) | 2 | 41.5 | no | collision push-out |
| 2026-10-18T19:43:10Z | func_00181118 | 408 | matched -> src/cod/sa_00181118.c (sn; PMF dispatch idiom from 0027e0b0.c with void fn-ptr type; lwu flag test via separate unsigned long t = flags; t &= 1; separate locals per clamp; m = s54A; m -= damage order) | 3 | 332.6 | no | enemy phase/guard regen |
| 2026-10-18T19:44:09Z | func_001AF098 | 408 | matched -> src/cod/sa_001af098.c (sn; first try, clone of sa_00181118 PMF dispatch + checkDamage tail) | 1 | 50.3 | no | enemy damage phase |
| 2026-10-18T19:45:57Z | func_001B67D0 | 408 | matched -> src/cod/sa_001b67d0.c (sn; one reused vec pointer t with a = t / b = t copies (the daddu s3,s2 pattern), copy source &f[12] for sp-relative reads, signed int mask for addiu -2) | 1 | 107.9 | no | enemy damage-give setup |
| 2026-10-18T19:48:57Z | func_00332178 | 408 | NM -> src/cod/sa_nm_00332178.c (cygnus dr; near-miss 27; id kept in t0 in retail vs a1, missing delay-slot fill of the bufsize andi into the arg2-check beqz) | 3 | 179.7 | no | DTX remote open |
| 2026-10-18T20:08:21Z | func_0033B218 | 408 | matched -> src/cod/sa_0033b218.c (cygnus dr; first try, DTX init with while(1){} hangs as in sa_00332508) | 1 | 45.6 | no | DTX init |
| 2026-10-18T20:09:32Z | func_00178B20 | 412 | matched -> src/cod/sa_00178b20.c (sn; 16fa80 take-box head + 183650 give-sphere and work-default store order) | 1 | 64.7 | no | enemy damage volumes setup |
| 2026-10-18T20:13:19Z | func_0030FCC0 | 412 | matched -> src/cod/sa_0030fcc0.c (sn; nested inline Room(l) = Size(l) < Cap(l) gives the this-pointer reload; Cap loads begin/cap into locals for the cap-first load order; early returns per branch let the final add-call cross-jump) | 2 | 227.0 | no | cScrArray room check + add |
| 2026-10-18T20:15:20Z | func_003398F8 | 412 | matched -> src/cod/sa_003398f8.c (cygnus dr; CRI SJRBF GetChunk; len computed straight into ck->len as MIN(MIN(n, bsize - pos + xsize), nbyte) with one `<` MIN macro, no local) | 1 | 115.7 | no | SJ ring buffer GetChunk |
| 2026-10-18T20:16:58Z | func_0034A818 | 412 | matched -> src/cod/sa_0034a818.c (cygnus dr; first try; switch on err gives the compare tree, sub = hn + 0x1020 local initialised at declaration for the prologue s5) | 1 | 90.6 | yes | MPV handle update |
| 2026-10-18T20:21:13Z | func_00373BA8 | 412 | NM -> src/cod/sa_nm_00373ba8.c (sn; 1 extra word: freq copied to t1 at entry, retail hoists li v0,1 into the first delay slot; per-arm size stores fixed the reload) | 3 | 254.9 | no | stream buffer alloc |
| 2026-10-18T20:22:45Z | func_003356B0 | 408 | NM -> src/cod/sa_nm_003356b0.c (cygnus dr; near-miss 2; error call passing name avoids cross-jump, prev-index local; entry store order 0x0C/0x1C swap unreachable by source order) | 3 | 2027.9 | no | LSC request push |
| 2026-10-18T20:27:38Z | func_00150DC8 | 416 | NM -> src/cod/sa_nm_00150dc8.c (sn; 103 vs 104 words; p-before-count-store fixes entry regs; xori parity test only appears with forms that move p out of a3) | 3 | 293.8 | yes | DMA packet append |
| 2026-10-18T20:27:59Z | func_00187A78 | 416 | matched -> src/cod/sa_00187a78.c (sn; clone of sa_00178b20 with 2.62/1.1/1.4 box, radius 3, kind 10) | 1 | 21.0 | no | enemy damage volumes setup |
| 2026-10-18T20:28:44Z | func_001617C8 | 420 | matched -> src/cod/sa_001617c8.c (sn; unsigned loop counter keeps the up-counting sltiu loop instead of the reversed one) | 1 | 44.7 | no | part visibility |
| 2026-10-18T20:33:02Z | func_0032B888 | 420 | NM -> src/cod/sa_nm_0032b888.c (cygnus dr; 39 diffs, s-reg assignment and an nch copy) | 6 | 258.1 | no | CRI ADX silence fill |
| 2026-10-18T20:35:20Z | func_00332EA0 | 420 | matched -> src/cod/sa_00332ea0.c (cygnus dr; a ret local set in both arms shares the return copy; storing buf before the MIN clamp fixes the a2/a3 tie) | 3 | 137.8 | no | CRI CD file read request |
| 2026-10-18T20:36:57Z | func_00381F18 | 420 | matched -> src/cod/sa_00381f18.c (sn; >= tests and goto block order give the retail layout; short step gives addu step,x operand order) | 4 | 96.8 | no | sound option menu input |
| 2026-10-18T20:37:18Z | func_00383878 | 420 | matched -> src/cod/sa_00383878.c (sn; clone of 381F18 with block at 0x370) | 1 | 20.6 | no | sound option menu input |

BATCH 105: 14 matched (func_00135040, func_00181118, func_001AF098, func_001B67D0, func_0033B218, func_00178B20, func_0030FCC0, func_003398F8, func_0034A818, func_00187A78, func_001617C8, func_00332EA0, func_00381F18, func_00383878), 5 NM (func_00332178 near-miss 27, func_003356B0 near-miss 2, func_00373BA8 near-miss 1 word, func_00150DC8 near-miss 1 word, func_0032B888 PARK 39). Handoffs: none (nm_solved empty). Reseed OK, 75s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: cygnus-2.96 drop-reorder for sa_0033b218/sa_003398f8/sa_0034a818/sa_00332ea0 and NM sa_nm_00332178/sa_nm_003356b0/sa_nm_0032b888; sn-2.95.3-136 default for sa_00181118/sa_001af098/sa_001b67d0/sa_00178b20/sa_0030fcc0/sa_00187a78/sa_001617c8/sa_00381f18/sa_00383878 and NM sa_nm_00373ba8/sa_nm_00150dc8; sa_00135040 uses c_flags_add -ffast-math plus fp_hazard_rules fdiv (both already used by 002c0cb0.c) and carries the single allowed inline `__asm__ volatile("")` barrier. New tricks: a separate `unsigned long t = flags; t &= 1;` gives lwu; PMF dispatch wants a `void (*)(int)` fn-ptr type; `m = x; m -= y;` sets subu operand order; reusing one pointer through `a = t; b = t;` copies gives the daddu s-reg copy; passing `&f[12]` gives sp-relative reads; a nested inline Room = Size < Cap keeps the this reload; CRI code wants MIN written straight into the struct field; passing an already-live extra arg to an error call stops cross-jumping; an unsigned loop counter keeps the up-counting sltiu loop; a ret local assigned in both arms shares one return copy; statement order before a MIN clamp breaks a2/a3 ties; a short step variable gives `addu step,x` operand order in sn.
| 2026-10-18T20:41:27Z | Quaternion_GetEulerXYZ | 424 | matched -> src/cod/sa_0015a3e8.c (sn + "as": "sn" for the mtc1/nop hazard pairs; asin result in a local, yy2 local, products in order wz2/zz2/xx2/xy2) | 3 | 144.9 | no | quaternion to euler |
| 2026-10-18T20:44:10Z | cCoreSave_spawnItems | 424 | NM -> src/cod/sa_nm_001fb330.c (sn + as sn; PARK 104 vs 106 words: hi-only D_007474A0 base in s4 with per-iteration %lo add, shift-first index add) | 5 | 162.9 | no | save item respawn |
| 2026-10-18T20:44:47Z | func_002988A8 | 424 | matched -> src/cod/sa_002988a8.c (sn; first try, plain switch, compiler cross-jumps the shared mesh tails) | 1 | 36.9 | no | model mesh set by level |
| 2026-10-18T20:45:23Z | Move | 424 | matched -> src/cod/sa_0030eee8.c (sn; first try, volatile T0_COUNT reads around the first step and the frame) | 1 | 35.9 | no | main frame update |
| 2026-10-18T20:47:26Z | func_002A4970 | 428 | matched -> src/cod/sa_002a4970.c (sn; switch with case 1..6 gives the bltz/slti range test; SearchData calls written directly as the call args give the per-branch s-reg assignment) | 4 | 123.3 | no | font texture bind |
| 2026-10-18T20:49:53Z | func_0013E0B0 | 432 | NM -> src/cod/sa_nm_0013e0b0.c (sn + as sn + fp_hazard_rules fdiv; PARK 27: interpolation load scheduling; j shared by both inner loops fixed the s0 counter) | 5 | 142.1 | no | sub-object timer curve |
| 2026-10-18T20:50:54Z | func_001A47F8 | 432 | matched -> src/cod/sa_001a47f8.c (sn; adapted from sa_0017e4c8 gimmick step, case-2 store order 0x760/0x2F6/0x2F7 in source gives the retail schedule) | 2 | 60.1 | no | slide gimmick step |
| 2026-10-18T20:56:11Z | func_001AA510 | 432 | NM -> src/cod/sa_nm_001aa510.c (sn; near-miss 13: hit-sound arg setup; local phase-table struct copy gives the ldl/ldr block, ternary inside the call args gives the explicit b) | 6 | 317.5 | no | enemy damage phase |
| 2026-10-18T20:58:41Z | TransEsp | 432 | NM -> src/cod/sa_nm_002fb310.c (sn; PARK 55: D_00747A84[] with [-1]/[-22] gives the shared base, t = x & m; p = t != 0 keeps and/sltu; loop global and parent flag still differ) | 6 | 149.9 | no | object transform pass |
| 2026-10-18T21:01:17Z | func_0037E4C0 | 432 | NM -> src/cod/sa_nm_0037e4c0.c (sn; PARK 106 vs 108 words: duplicated count register, page-up branch form) | 4 | 155.5 | no | list menu input |
| 2026-10-18T21:02:24Z | cSubScr_SubScrOn | 436 | skipped: jump table D_0041F0B0 needs extern_jtbl, which sa_register cannot set (draft in build/sa/b106_160020.c) | 0 | 67.6 | no | sub-screen open |
| 2026-10-18T21:02:56Z | func_0033C548 | 436 | matched -> src/cod/sa_0033c548.c (cygnus dr; first try, three log/exp table hash loops with signed % 1024) | 1 | 31.7 | no | CRI key string hash |
| 2026-10-18T21:03:52Z | func_0036CF30 | 436 | matched -> src/cod/sa_0036cf30.c (cygnus dr; 21 fn-pointer global stores, the initialised flag store last) | 2 | 55.9 | no | M2V interface table init |

BATCH 106: 7 matched (Quaternion_GetEulerXYZ, func_002988A8, Move, func_002A4970, func_001A47F8, func_0033C548, func_0036CF30), 5 NM (cCoreSave_spawnItems PARK 104 vs 106 words, func_0013E0B0 PARK 27, func_001AA510 near-miss 13, TransEsp PARK 55, func_0037E4C0 PARK 106 vs 108 words), 1 skipped (cSubScr_SubScrOn: jump table needs extern_jtbl). Handoffs: 1 registered from nm_solved (func_00373BA8 -> src/cod/sa_00373ba8.c, parked in batch 105). Reseed OK, 46s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: sa_0015a3e8 sn-2.95.3-136 with "as": "sn" (NM sa_nm_001fb330 likewise; NM sa_nm_0013e0b0 "as": "sn" plus fp_hazard_rules fdiv, both already used elsewhere); cygnus-2.96 drop-reorder for sa_0033c548/sa_0036cf30; sn-2.95.3-136 default for sa_002988a8/sa_0030eee8/sa_002a4970/sa_001a47f8 and NM sa_nm_001aa510/sa_nm_002fb310/sa_nm_0037e4c0. New tricks: the asin result kept in a local plus the product order wz2/zz2/xx2/xy2 fixes the float register schedule; a switch with `case 1..6` gives the bltz + slti range test; SearchData calls written straight into the call args give the per-branch s-register order; the initialised flag written after a long run of global stores matches the scheduled position; local struct copy of a 2-aligned table gives the ldl/ldr block; `D_00747A84[-1]` style negative indexing gives the shared game-work base.
| 2026-10-18T21:06:15Z | func_0028AC58 | 440 | matched -> src/cod/sa_0028ac58.c (pack offset written `*(int*)(pack+off) + (int)pack`; `tex != 0` call first) | 3 | 69.8 | no | enemy model setup |
| 2026-10-18T21:10:20Z | cEmManage_SetEmAnger | 440 | NM -> src/cod/sa_nm_00291b90.c (fabs copy/negate shape) | 6 | 245.0 | no | enemy anger target scan |
| 2026-10-18T21:14:00Z | func_002A6FF8 | 440 | NM -> src/cod/sa_nm_002a6ff8.c (mask hoisting / reg split) | 6 | 207.7 | no | link-table visibility check |
| 2026-10-18T21:16:13Z | func_00334310 | 440 | NM -> src/cod/sa_nm_00334310.c (near-miss 2: info.size reload) | 6 | 133.5 | no | CD file size lookup |
| 2026-10-18T21:17:11Z | func_0034ADB8 | 440 | matched -> src/cod/sa_0034adb8.c (cygnus dr; struct copy before the field stores) | 2 | 57.6 | no | SFD request fill |
| 2026-10-18T21:19:55Z | func_00353098 | 440 | matched -> src/cod/sa_00353098.c (cygnus dr; second size check as `goto ok` per arm; frame ptr as buf + i*size; empty else loop) | 6 | 163.6 | no | M2V frame buffer split |
| 2026-10-18T21:20:52Z | func_00338478 | 444 | matched -> src/cod/sa_00338478.c (cygnus dr; first putChunk written fully inline for the a3 load) | 2 | 57.4 | no | ADX channel block drain |
| 2026-10-18T21:23:14Z | func_00350F48 | 444 | NM -> src/cod/sa_nm_00350f48.c (reg choice / return shape) | 6 | 142.3 | no | SFD delimiter peek |

BATCH 107: 4 matched (func_0028AC58, func_0034ADB8, func_00353098, func_00338478), 4 NM (cEmManage_SetEmAnger PARK 108 vs 110 words, func_002A6FF8 PARK 102 vs 110 words, func_00334310 near-miss 2, func_00350F48 PARK 50). Handoffs: nm_solved was empty. Reseed OK, 138s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: sn-2.95.3-136 default for sa_0028ac58 (and NM sa_nm_00291b90/sa_nm_002a6ff8); cygnus-2.96 drop-reorder for sa_0034adb8/sa_00353098/sa_00338478 (and NM sa_nm_00334310/sa_nm_00350f48). New tricks: `*(int *)(pack + off) + (int)pack` as an int add gives the `addu a2,t0,a2` operand order a char-pointer add won't; copying a struct before the scalar stores around it matches the cygnus store schedule; a `goto ok` per arm (with the error return falling through after the if/else) reproduces cygnus's duplicated compare-and-branch tails; writing each frame pointer as `buf + i * size` instead of a running pointer fixes the loop's register choice; repeating a vtable call's full `o->ch[i]->sj` expression in the call moves the reload into a3.
| 2026-10-18T21:27:25Z | Turn_dest | 448 | NM -> src/cod/sa_nm_002da038.c (near-miss 2: final abs neg.s) | 6 | 84.8 | no | yaw turn step |
| 2026-10-18T21:28:09Z | func_00394668 | 448 | matched -> src/cod/sa_00394668.c (first try; modelled on sa_00393fd8) | 1 | 43.5 | no | symbol table resolve |
| 2026-10-18T21:34:09Z | func_0039B960 | 448 | NM -> src/cod/sa_nm_0039b960.c (near-miss 6: DMA reg value/addr regs; ch.total stored first) | 5 | 360.6 | no | libmpeg CSC DMA |
| 2026-10-18T21:36:29Z | func_00145FC8 | 452 | matched -> src/cod/sa_00145fc8.c (table value in a local updated with `*=` before the second store; separate local in case 2) | 6 | 139.9 | no | effect fade/scale steps |
| 2026-10-18T21:37:30Z | func_001A49A8 | 452 | matched -> src/cod/sa_001a49a8.c (adapted from sa_001a47f8; ang[1] held in a local for both float args; zero stores rotated) | 4 | 60.4 | no | slide gimmick step (reverse) |
| 2026-10-18T21:40:26Z | cSceAtManager_findJumpPoint | 456 | skipped: HAND VU0 (lqc2/sqc2 vector copy; draft build/sa/b108_findjump.c) | 1 | 114.5 | no | scene jump point lookup |
| 2026-10-18T21:41:11Z | func_001AB730 | 456 | matched -> src/cod/sa_001ab730.c (per-case block locals for the pack base) | 2 | 44.6 | no | gimmick open/close step |
| 2026-10-18T21:41:21Z | func_00304F80 | 456 | skipped: HAND VU0 | 0 | 10.3 | no | VU0 vector math |
| 2026-10-18T21:42:13Z | func_0036B888 | 456 | matched -> src/cod/sa_0036b888.c (adapted from sa_0036ee90; if/return for movz select) | 2 | 51.5 | no | SFD stream-joint write to delim |
| 2026-10-18T21:42:23Z | func_003A5BD8 | 456 | skipped: HAND MMI asm (newlib strncmp, lq/psubb/pcpyud) | 0 | 10.5 | no | newlib MMI strncmp |
| 2026-10-18T21:46:37Z | func_003A5DA0 | 456 | skipped: HAND MMI asm (newlib strncpy, lq/psubb/pcpyud) | 0 | 245.4 | no | newlib MMI strncpy |
BATCH 108: 5 matched (func_00394668, func_00145FC8, func_001A49A8, func_001AB730, func_0036B888), 2 NM (Turn_dest near-miss 2, func_0039B960 near-miss 6), 4 skipped (cSceAtManager_findJumpPoint and func_00304F80 HAND VU0; func_003A5BD8 / func_003A5DA0 are newlib's hand-written MMI strncmp/strncpy). Handoffs: nm_solved was empty. Reseed OK, 149s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: sn-2.95.3-136 default for sa_00394668/sa_00145fc8/sa_001a49a8/sa_001ab730; cygnus-2.96 drop-reorder for sa_0036b888; NM sa_nm_002da038 uses "as": "sn" with fp_hazard_rules fdiv, NM sa_nm_0039b960 uses ee-2.9-991111. New tricks: per-case block locals for a reloaded pack base (instead of one function-scope local) fix the v0/a0 picks; cygnus turns `return r != 0 ? r : err` into the wrong movn, but `if (r != 0) return r; return err;` gives retail's movz; holding a float table value in a local updated with `*=` before the second store fixes FP register order.
| 2026-10-18T21:46:49Z | func_00148D30 | 460 | NM -> src/cod/sa_nm_00148d30.c (PARK 41: D_007474A0 base in saved reg, not a2 + s7 copy) | 6 | 2.2 | no | model texture rebind |
| 2026-10-18T21:48:33Z | func_001680D8 | 460 | matched -> src/cod/sa_001680d8.c (v < 0 arm first gives bgezl) | 2 | 104.3 | no | menu panel fade + arrow highlight |
| 2026-10-18T21:49:08Z | func_0017E2F8 | 460 | matched -> src/cod/sa_0017e2f8.c (first try; adapted from sa_0017e4c8) | 1 | 34.2 | no | reverse quarter-turn gimmick step |
| 2026-10-18T21:49:19Z | func_001A3860 | 460 | skipped: HAND VU0 (lqc2/sqc2 + vmulx; clone sa 001736a8 family) | 0 | 11.4 | no | gimmick layer open (VU0) |
| 2026-10-18T21:49:51Z | func_0030F348 | 460 | matched -> src/cod/sa_0030f348.c (first try; reference MT19937 genrand_int32) | 1 | 31.7 | no | Mersenne Twister genrand_int32 |
| 2026-10-18T21:51:46Z | cCoreSave_addItem | 464 | skipped: cvt.w.s (retail in-FPR float->short x4; draft build/sa/b109_additem.c has layout right) | 2 | 115.4 | no | save item table add |
| 2026-10-18T21:54:27Z | func_00141B18 | 464 | NM -> src/cod/sa_nm_00141b18.c (PARK 10: loop-3 base copy daddu s2,s4 propagated away) | 6 | 145.2 | no | HUD panel ID base init |
| 2026-10-18T21:55:21Z | func_001AC980 | 464 | matched -> src/cod/sa_001ac980.c (adapted from sa_00181118; damage in its own block local) | 3 | 53.8 | no | breakable gimmick phase update |
| 2026-10-18T21:55:22Z | func_001F0A28 | 464 | skipped: jump table | 0 | 0.8 | no | precheck |
| 2026-10-18T21:55:22Z | func_0024BF20 | 464 | skipped: HAND VU0 (precheck; also a jump table) | 0 | 0.8 | no | precheck |
| 2026-10-18T21:58:04Z | func_0029FDE0 | 464 | NM -> src/cod/sa_nm_0029fde0.c (PARK 7: pre-header order of the 0x1F giv init) | 6 | 161.9 | no | GS frame clear strips |
| 2026-10-18T21:58:46Z | func_00382D30 | 464 | matched -> src/cod/sa_00382d30.c (first try; adapted from func_00381940 in 001e4010.c) | 1 | 41.5 | no | menu page update |
| 2026-10-18T22:05:24Z | func_001C7138 | 468 | skipped: HAND VU0 (precheck) | 0 | 0.8 | no | precheck |
| 2026-10-18T22:05:25Z | func_00270160 | 468 | skipped: HAND VU0 (precheck) | 0 | 0.8 | no | precheck |
| 2026-10-18T22:05:26Z | func_002FCB88 | 468 | skipped: HAND VU0 (precheck) | 0 | 0.8 | no | precheck |
BATCH 109: 5 matched (func_001680D8, func_0017E2F8, func_0030F348, func_001AC980, func_00382D30), 3 NM (func_00148D30 PARK 41, func_00141B18 PARK 10, func_0029FDE0 PARK 7), 4 skipped (func_001A3860 / func_0024BF20 HAND VU0, cCoreSave_addItem cvt.w.s, func_001F0A28 jump table). Handoffs: nm_solved was empty. First reseed failed (rc=1) because I had registered the three NM files with sa_register add; NM files must stay unregistered like the other sa_nm_ files. I removed them with `sa_register.py remove`. The second try then failed at link because three asm fragments (000000.L79120/L87658/L509471) kept stub .o files that were older than their regenerated .s. I deleted those three build objects, and the third reseed was OK: 124s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: sn-2.95.3-136 default for all five matches; NM files unregistered (sn). New tricks: in sn, putting the `v < 0` arm first gives retail's bgezl; libc/MT code (genrand_int32) matched straight from the reference source; a damage value used twice needs its own block local, not a reused temp.
| 2026-10-18T22:08:30Z | func_003298F0 | 468 | matched -> src/cod/sa_003298f0.c (cygnus-2.96 --drop-reorder; block-local temp before zeroing each field) | 3 | 417.3 | no | ADXT handle destroy (cygnus) |
| 2026-10-18T22:08:30Z | __frame_state_for | 472 | matched -> src/cod/sa_00322570.c (ee-2.9-991111; aligned(8) state struct gives ld/sd copies; memset called as func_003A52F0) | 3 | 164.2 | no | libgcc frame state (ee-2.9) |
| 2026-10-18T22:08:30Z | func_0038F200 | 468 | NM -> src/cod/sa_nm_0038f200.c (ee-2.9-991111; PARK 98) | 4 | 187.0 | no | libio file op (ee-2.9) |
| 2026-10-18T22:17:17Z | func_00192D20 | 472 | matched -> src/cod/sa_00192d20.c (element copies for the box sizes; mtx local; header int prototype of func_001C28A0 fixed the tail; elapsed under-logged, start was late) | 5 | 1.8 | no | enemy twin damage-take setup |
| 2026-10-18T22:18:45Z | func_00281968 | 472 | matched -> src/cod/sa_00281968.c (phase dispatch from sa_001af098; scroll factor as compound assignments on one local) | 2 | 80.8 | no | enemy per-frame update + texture scroll |
| 2026-10-18T22:20:39Z | func_0035CC80 | 472 | NM -> src/cod/sa_nm_0035cc80.c (cygnus dr; PARK 88: 25-arg debug sprintf, spill/regalloc of the argument setup) | 3 | 114.7 | no | debug stream-timing log line |
| 2026-10-18T22:25:05Z | func_003B0EF8 | 472 | NM -> src/cod/sa_nm_003b0ef8.c (ee-2.9; PARK 45: needs unapproved extern_double for the rodata doubles, then branch-likely in the two loops) | 3 | 260.5 | no | sce snprintf %e-style double |
| 2026-10-18T22:25:47Z | sceDmaPutEnv | 472 | matched -> src/cod/sa_00397208.c (first try; SDK libdma layout, ee-2.9) | 1 | 42.1 | no | libdma put environment |
| 2026-10-18T22:29:04Z | Draw_Line_sc | 476 | NM -> src/cod/sa_nm_0015f0b8.c (sn, as sn; PARK 3: pre-header hoist order of %hi(D_00586B80)) | 6 | 197.0 | no | screen-space polyline draw |
| 2026-10-18T22:29:56Z | func_00278390 | 476 | matched -> src/cod/sa_00278390.c (adapted from sa_00281968; part pointers re-read per test, no shared local) | 2 | 46.3 | no | enemy per-frame update + part swap |
| 2026-10-18T22:31:15Z | func_002DB0D0 | 476 | matched -> src/cod/sa_002db0d0.c (as sn; found as a block local per range branch, best = -1 before the block) | 3 | 73.6 | no | enemy find by id / nearest |
| 2026-10-18T22:33:26Z | func_003090F8 | 476 | NM -> src/cod/sa_nm_003090f8.c (sn; PARK 29: regalloc of ch/start, rate switch branch form, record store schedule) | 5 | 125.8 | no | sound bank channel setup |
| 2026-10-18T22:33:39Z | func_0012A108 | 472 | skipped: HAND VU0 (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T22:33:40Z | func_00133BC8 | 472 | skipped: HAND VU0 (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T22:33:40Z | func_002BD828 | 476 | skipped: HAND VU0 (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T22:33:40Z | func_00339CB8 | 476 | skipped: HAND MMI asm (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T22:33:41Z | func_00341F00 | 476 | skipped: HAND MMI asm (precheck) | 0 | 0.3 | no | precheck |
BATCH 110: 7 matched (func_003298F0 cygnus-2.96 --drop-reorder; __frame_state_for ee-2.9-991111; func_00192D20, func_00281968, func_00278390 sn; func_002DB0D0 sn with "as": "sn"; sceDmaPutEnv ee-2.9-991111), 5 NM (func_0038F200 PARK 98, func_0035CC80 PARK 88, func_003B0EF8 PARK 45, Draw_Line_sc PARK 3, func_003090F8 PARK 29), 8 skipped (6 HAND VU0: func_001C7138, func_00270160, func_002FCB88, func_0012A108, func_00133BC8, func_002BD828; 2 HAND MMI: func_00339CB8, func_00341F00). Handoff: func_0039B960 (ee-2.9, SCE libmpeg CSC transfer) came in from nm_solved and was registered. Reseed OK on the first try: 51s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: compiler choice per the address bands above; "as": "sn" on sa_002db0d0.c (mtc1+nop hazard pairs). Notes: func_00192D20 only matched after declaring func_001C28A0 as returning int (the emDamageVol.h prototype), which fixed the order of the last two stores. func_003B0EF8 would need the per-file extern_double setting (li.d slots D_0045FE78,-,D_0045FE80,-,-,-,D_0045FE88). That setting is not on the standing-approval list, so I did not use it; even with it, 45 diffs remain (branch-likely in the two loops). Elapsed time for func_00192D20 is under-logged because its batch_log start ran late.
| 2026-10-18T22:44:54Z | func_001A6AF8 | 480 | skipped: HAND VU0 (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T22:44:55Z | func_001F4248 | 480 | skipped: cvt.w.s (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T22:44:55Z | scePadPortOpen | 484 | skipped: HAND MMI asm (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T22:44:55Z | func_00129CC8 | 488 | skipped: HAND VU0 (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T22:44:56Z | func_001501D0 | 488 | skipped: HAND VU0 (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T22:44:56Z | func_0026A018 | 488 | skipped: HAND VU0 (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T22:44:57Z | func_00331718 | 488 | skipped: jump table (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T22:46:24Z | func_00274FE8 | 480 | NM -> src/cod/sa_nm_00274fe8.c (sn, as sn; PARK 103: cross-jump layout of the phase-set tails) | 3 | 83.0 | no | enemy think / phase select |
| 2026-10-18T22:48:45Z | func_00344948 | 480 | NM -> src/cod/sa_nm_00344948.c (cygnus dr; PARK 71: serialized word copies through v0) | 3 | 140.5 | no | MWSFSVM work setup |
| 2026-10-18T22:50:24Z | func_002C1AE0 | 484 | NM -> src/cod/sa_nm_002c1ae0.c (sn, as sn; PARK 39: pi constant hoisted above sub/abs; duplicated call gave the area branch) | 5 | 99.3 | no | area hit check with facing arc |
| 2026-10-18T22:51:46Z | func_0030F8B0 | 484 | NM -> src/cod/sa_nm_0030f8b0.c (77 diffs, erase regalloc + crossjump) | 4 | 81.7 | no | object list sweep |
| 2026-10-18T22:53:19Z | func_00327048 | 484 | matched -> src/cod/sa_00327048.c (cygnus dr; i=0 before first ACA0 call) | 2 | 77.9 | no | ADX SJ decoder block |
| 2026-10-18T22:55:46Z | func_001643F8 | 488 | matched -> src/cod/sa_001643f8.c (sn, as sn; clone of 164238; unsigned long t ==1 gives dsrl) | 4 | 140.9 | no | menu cursor |
| 2026-10-18T22:58:00Z | func_00283C70 | 488 | NM -> src/cod/sa_nm_00283c70.c (108 diffs, extra $s2 constant copy) | 5 | 129.9 | no | light entry setup |
| 2026-10-18T23:02:23Z | func_00383F50 | 488 | NM -> src/cod/sa_nm_00383f50.c (56 diffs, s0/s1/s2 rotation like 382660) | 6 | 258.2 | no | mixer mute toggle |
BATCH 111: 2 matched (func_00327048 cygnus-2.96 --drop-reorder; func_001643F8 sn with "as": "sn"), 6 NM (func_00274FE8 PARK 103, func_00344948 PARK 71, func_002C1AE0 PARK 39, func_0030F8B0 PARK 77, func_00283C70 PARK 108, func_00383F50 PARK 56), 7 skipped (4 HAND VU0: func_001A6AF8, func_00129CC8, func_001501D0, func_0026A018; 1 cvt.w.s: func_001F4248; 1 HAND MMI: scePadPortOpen; 1 jump table: func_00331718). Handoff: Draw_Line_sc came in from nm_solved and was registered to src/cod/sa_0015f0b8.c. The first reseed failed (elf=BAD) with a duplicate definition of Draw_Line_sc, because src/cod/0015f0.c still carried INCLUDE_ASM("permanent", Draw_Line_sc). I removed that block (Draw_Poly_sc stays in 0015f0.c) and the second reseed was OK: 41s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: compiler choice per the address bands; "as": "sn" on sa_001643f8.c (ps2eeas dli chains). Notes: func_00327048 matched once i = 0 sat before the first func_0033ACA0 call. func_001643F8 needed the flag word read into an unsigned long local and tested == 1, as in func_00163F00, to get lw + dsrl. func_00383F50 is the two-mixer sibling of func_00382660 and parks on the same s0/s1/s2 rotation.
| 2026-10-18T23:05:08Z | cCoreSave_translateSaveItem | 492 | skipped: cvt.w.s (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T23:05:08Z | func_002BD4B0 | 496 | skipped: HAND VU0 (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T23:05:09Z | func_002FBFB0 | 496 | skipped: cvt.w.s (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T23:05:09Z | ColiseumBattle_ApplyRingRules | 500 | skipped: cvt.w.s (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T23:05:09Z | SetActionJumpDown | 504 | skipped: HAND VU0 (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T23:07:47Z | func_0013C318 | 492 | NM -> src/cod/sa_nm_0013c318.c (sn; PARK 90: else-if re-test not threaded in retail) | 5 | 153.3 | no | sub-part show/hide |
| 2026-10-18T23:08:55Z | func_001C9860 | 492 | matched -> src/cod/sa_001c9860.c (sn; phase dispatch as 281968; dst before src in the 0x5D0 copy) | 2 | 63.2 | no | gimmick per-frame update |
| 2026-10-18T23:09:38Z | func_0027F1B0 | 492 | matched -> src/cod/sa_0027f1b0.c (sn; clone of 281968; unsigned 0xFFFFFFFC mask gives lui/ori) | 2 | 38.3 | no | enemy per-frame update |
| 2026-10-18T23:10:17Z | func_001DA910 | 496 | matched -> src/cod/sa_001da910.c (sn, as sn; first draft) | 1 | 33.8 | no | two-choice panel step |
| 2026-10-18T23:12:24Z | func_00114AC0 | 500 | matched -> src/cod/sa_00114ac0.c (sn, as sn; address expressions in the distance call, pointer locals only for the copy) | 5 | 122.4 | no | walk-to-target step |
| 2026-10-18T23:14:37Z | func_00277348 | 500 | NM -> src/cod/sa_nm_00277348.c (sn; PARK 78: constant 1 kept in $s0 across calls, fresh 1 in the compare) | 6 | 127.2 | no | enemy init |
| 2026-10-18T23:14:52Z | func_003B7C58 | 500 | skipped: HAND asm (mtc0 $6 + sync.p TLB setup) | 0 | 10.2 | no | TLB setup |
| 2026-10-18T23:15:01Z | func_0015E510 | 504 | skipped: jump table (psm switch at D_0041EEA0) | 0 | 9.1 | no | GS load-image packet |
BATCH 112: 4 matched (func_001C9860, func_0027F1B0 sn; func_001DA910, func_00114AC0 sn with "as": "sn"), 2 NM (func_0013C318 PARK 90, func_00277348 PARK 78), 7 skipped (3 cvt.w.s: cCoreSave_translateSaveItem, func_002FBFB0, ColiseumBattle_ApplyRingRules; 2 HAND VU0: func_002BD4B0, SetActionJumpDown; 1 hand asm: func_003B7C58, mtc0/sync.p TLB setup; 1 jump table: func_0015E510). Handoff: nm_solved was empty. Reseed OK on the first try: 125s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: sn-2.95.3-136 for all; "as": "sn" on sa_001da910.c (ps2eeas dli chain) and sa_00114ac0.c (mtc1+nop hazard pairs). Notes: func_0027F1B0 is a clone of func_00281968; the 0x1560 mask had to be written as unsigned 0xFFFFFFFC to get lui/ori. func_001C9860 uses the same phase dispatch and needed dst assigned before src in the 0x5D0 copy. func_00114AC0 needed the distance call written with address expressions (so self lands in $s2), with pointer locals only for the copy. func_0013C318 parks on an else-if re-test that retail does not jump-thread. func_00277348 parks on a constant 1 that retail keeps in $s0 across calls.
| 2026-10-18T23:17:41Z | func_001BF5E0 | 504 | skipped: HAND VU0 (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T23:17:42Z | func_002F1B60 | 504 | skipped: HAND VU0 (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T23:17:42Z | cWorldLight_Light_curent_set2 | 508 | skipped: HAND VU0 (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T23:17:42Z | func_00186398 | 508 | skipped: HAND VU0 (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T23:17:43Z | func_0026A638 | 508 | skipped: HAND VU0 (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T23:17:43Z | func_0026BBD0 | 508 | skipped: HAND VU0 (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T23:17:44Z | func_0026E258 | 508 | skipped: HAND VU0 (precheck) | 0 | 0.3 | no | precheck |
| 2026-10-18T23:17:44Z | Quaternion_SetCoordinateRotationZ | 512 | skipped: HAND VU0 (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T23:17:44Z | func_0015ABA0 | 512 | skipped: HAND VU0 (precheck) | 0 | 0.4 | no | precheck |
| 2026-10-18T23:19:06Z | func_003547B0 | 504 | matched -> src/cod/sa_003547b0.c (cygnus dr; struct copies give ldl/sdl; 16 slots of 0xF0 at 0x180) | 3 | 76.6 | no | MWSFD handle init |
| 2026-10-18T23:21:51Z | func_0012D1A8 | 508 | NM -> src/cod/sa_nm_0012d1a8.c (sn; PARK 62: self/min/max register assignment and addressing) | 6 | 159.9 | no | square corners + bbox |
| 2026-10-18T23:22:56Z | func_00151168 | 508 | matched -> src/cod/sa_00151168.c (sn; sibling of NM 150DC8; width/height divided in place gives the param copies) | 2 | 59.5 | no | GS image upload packet |
| 2026-10-18T23:26:03Z | func_00150F68 | 512 | NM -> src/cod/sa_nm_00150f68.c (85 diffs, src in s0) | 4 | 182.6 | no | gs upload packet |
| 2026-10-18T23:26:53Z | func_001F1918 | 512 | matched -> src/cod/sa_001f1918.c (clone of ColiseumBattle_spawnWaitingEnemies, 6 slots) | 1 | 39.8 | no | coliseum wave spawn |

BATCH 113: 3 matched (func_003547B0 cygnus-2.96 --drop-reorder; func_00151168, func_001F1918 sn), 2 NM (func_0012D1A8 PARK 62, func_00150F68 PARK 85), 9 skipped (all HAND VU0 by precheck: func_001BF5E0, func_002F1B60, cWorldLight_Light_curent_set2, func_00186398, func_0026A638, func_0026BBD0, func_0026E258, Quaternion_SetCoordinateRotationZ, func_0015ABA0). Handoff: nm_solved was empty. Reseed OK on the first try: 46s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: cygnus-2.96 with --drop-reorder on sa_003547b0.c (address band); sn-2.95.3-136 on sa_00151168.c and sa_001f1918.c; no "as" overrides. Notes: func_00150F68 (sibling of 151168 with an explicit buffer width/format) keeps a dead divide-by-zero trap on bytes-per-row that no dead-division spelling reproduced, and the src parameter lands in s0; func_001F1918 is a six-slot clone of ColiseumBattle_spawnWaitingEnemies.
| 2026-10-18T23:42:18Z | func_003B3650 | 452 | NM -> src/cod/sa_nm_003b3650.c (ee-2.9; PARK 40: req/pkt s1/s0 swap) | 5 | 254.3 | no | sdk sif rpc |
| 2026-10-18T23:44:49Z | func_002006B8 | 512 | matched -> src/cod/sa_002006b8.c (sn; D_00747A2C as int[] with [-2]/[3]; (unsigned int) cast on the first bit test picks v1) | 4 | 150.0 | no | stage point save/restore |
| 2026-10-18T23:45:51Z | func_0017B0D8 | 516 | matched -> src/cod/sa_0017b0d8.c (sn; template sa_001a49a8.c; both moves called before the test) | 3 | 62.6 | no | gimmick swing step |
| 2026-10-18T23:48:30Z | MoveEmitter | 516 | NM -> src/cod/sa_nm_00300628.c (sn; PARK 118: loop invariant hoisting set differs) | 4 | 158.8 | no | emitter update |
| 2026-10-18T23:49:32Z | func_0032CC90 | 516 | matched -> src/cod/sa_0032cc90.c (cygnus dr; SJ vtable 0x18/0x1C/0x20/0x24) | 2 | 61.9 | no | adx sj flush |
| 2026-10-18T23:52:24Z | func_00354EC8 | 520 | NM -> src/cod/sa_nm_00354ec8.c (cygnus dr; PARK 124: load hoisting over record stores) | 4 | 172.1 | no | adx stream info |
| 2026-10-18T23:53:49Z | func_0037BC90 | 520 | NM -> src/cod/sa_nm_0037bc90.c (sn; PARK 124: colour kept as value<<16 in s2) | 3 | 84.2 | no | debug page |
| 2026-10-18T23:55:25Z | func_003B3F50 | 520 | NM -> src/cod/sa_nm_003b3f50.c (ee-2.9; PARK 19: s0/s1 swap + D_FFFFF delay-loop reloc artifact) | 3 | 96.5 | no | sdk fileio init |
| 2026-10-18T23:57:27Z | func_0012DCB8 | 524 | NM -> src/cod/sa_nm_0012dcb8.c (sn; PARK 117: min/max loop induction pointers) | 5 | 121.9 | no | bounding box |
| 2026-10-18T23:58:42Z | func_0036A3E8 | 524 | matched -> src/cod/sa_0036a3e8.c (cygnus dr; signed delimiter switch, case bodies 0x40/8/4/0x10/0x20, chunk copied by field) | 4 | 74.6 | no | mpeg header decode |
| 2026-10-19T00:01:45Z | func_0036DFF0 | 524 | NM -> src/cod/sa_nm_0036dff0.c (cygnus dr; PARK 7: loop entry threading + call arg order) | 6 | 183.5 | no | mpeg header scan |

BATCH 114: 4 matched (func_002006B8, func_0017B0D8 sn; func_0032CC90, func_0036A3E8 cygnus-2.96 --drop-reorder), 7 NM (func_003B3650 PARK 40, func_003B3F50 PARK 19 (both ee-2.9), MoveEmitter PARK 118, func_0037BC90 PARK 124, func_0012DCB8 PARK 117 (all three sn), func_00354EC8 PARK 124, func_0036DFF0 PARK 7 (both cygnus dr)), 0 skipped. Handoff: nm_solved was empty. Reseed OK on the first try: 49s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: sn-2.95.3-136 on sa_002006b8.c and sa_0017b0d8.c; cygnus-2.96 with --drop-reorder on sa_0032cc90.c and sa_0036a3e8.c (address band); no "as" or c_flags overrides. Notes: func_002006B8 needs D_00747A2C as int[] with [-2]/[3] (the base symbol carries the field offsets) and an (unsigned int) cast on the first bit test. func_0017B0D8 is a two-mover clone of sa_001a49a8.c. The SDK delay loop (for i = 0x100000 down to -1, retail's four-nop padding is automatic) appears in func_003B3650 and func_003B3F50; the split asm labels its lui 0x10 / addiu -1 as %hi/%lo of the auto symbol D_FFFFF (config/undefined_syms_auto.txt), so those two relocations cannot come from C. Maintainer: 32 lines in asm/cod/000000.s use D_FFFFF this way; dropping that auto symbol so the splitter emits plain immediates would unblock those SDK delay loops. func_00354EC8 needs -fno-strict-aliasing-style ordering plus first-pass scheduling; no per-file flag in the approved vocabulary provides that.
| 2026-10-19T00:09:32Z | Trans_Clipmatrix_set | 528 | matched -> src/cod/sa_001538f0.c (sn, fp_hazard_rules fdiv; constants 0.5/1/0.1/2048 as float locals, nd = -d after the first call) | 4 | 175.2 | no | clip matrix |
| 2026-10-19T00:11:51Z | func_001C3988 | 528 | NM -> src/cod/sa_nm_001c3988.c (sn -fno-gcse, 79 diffs; never-read stack copy of part count) | 5 | 139.0 | no | part flags |
| 2026-10-19T00:12:49Z | func_003A9018 | 528 | matched -> src/cod/sa_003a9018.c (sn; newlib _strtoul_r verbatim, 64-bit long, ctype D_0045F039) | 1 | 54.1 | no | libc strtoul |
| 2026-10-19T00:13:46Z | func_0013EE58 | 532 | matched -> src/cod/sa_0013ee58.c (sn; index p->ch[i].f directly, no local pointer; idx unsigned short compared as (short)) | 3 | 56.2 | no | uv scroll idwork |
| 2026-10-19T00:17:36Z | func_002BE240 | 532 | matched -> src/cod/sa_002be240.c (sn, call_loop_pad; index-based tolower loops via static inline ctype_tolower, && basename chain, while (SifDmaStat(id) < 0)) | 5 | 230.4 | no | pack file load |
| 2026-10-19T00:27:25Z | func_003563B8 | 532 | NM -> src/cod/sa_nm_003563b8.c (cygnus dr, 7 diffs; final store scheduling only) | 6 | 570.5 | no | movie decoder setup |
| 2026-10-19T00:29:15Z | func_00356C68 | 532 | NM -> src/cod/sa_nm_00356c68.c (cygnus dr, 1 diff; final bnel vs bnez reorg choice) | 6 | 109.0 | no | mpeg delim scan |
| 2026-10-19T00:31:47Z | func_0033EE30 | 540 | NM -> src/cod/sa_nm_0033ee30.c (cygnus dr, 51 diffs; address scheduling around 16-byte copy) | 5 | 152.3 | no | adx ainf |
| 2026-10-19T00:34:21Z | func_0035A2B0 | 540 | NM -> src/cod/sa_nm_0035a2b0.c (cygnus dr, 46 diffs; final store-block scheduling, 0x2A8 reload) | 5 | 153.6 | no | sftim init |
| 2026-10-19T00:35:23Z | func_001B90D0 | 544 | matched -> src/cod/sa_001b90d0.c (sn; part-count stack store via *(int*)&f[0] = n; h[1] before h[3]; local for the -1/0 tail stores) | 2 | 62.2 | no | enemy damage-give setup |

BATCH 115: 5 matched (Trans_Clipmatrix_set, func_003A9018, func_0013EE58, func_002BE240, func_001B90D0, all sn-2.95.3-136), 5 NM (func_001C3988 PARK 79 (sn -fno-gcse), func_003563B8 PARK 7, func_00356C68 PARK 1, func_0033EE30 PARK 51, func_0035A2B0 PARK 46 (all four cygnus dr)), 0 skipped. Handoff: nm_solved was empty. Reseed OK on the first try: 48s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: sn-2.95.3-136 on all five; fp_hazard_rules "fdiv" on sa_001538f0.c; call_loop_pad on sa_002be240.c; no "as" or c_flags overrides. Notes: Trans_Clipmatrix_set needed its constants as float locals plus nd = -d placed after the first call, so -d gets its own saved FPR. func_003A9018 is newlib _strtoul_r verbatim (64-bit long, so __udivdi3/__umoddi3/__muldi3), and it matched on the first try. func_002BE240 needed index-based tolower loops (loop strength reduction makes the pointer + counter pair) through a static inline ctype helper, which gives the movz form. func_001B90D0 reuses the "*(int*)&f[0] = count" stack store from 00173ad8.c, but the same idiom did not fit func_001C3988, where retail copies the count between two registers. All four cygnus parks are scheduling or reorg-only: func_00356C68 is one bnel-vs-bnez delay-slot choice, and func_003563B8 is the order of the final state-reset stores (hill-climbed to 7).
| 2026-10-19T00:36:58Z | func_00399508 | 544 | skipped: D_FFFFF delay-loop relocs (splitter auto symbol; not expressible in C) | 0 | 17.3 | no | sdk cd init |
| 2026-10-19T00:40:24Z | func_00159DA0 | 548 | NM -> src/cod/sa_nm_00159da0.c (sn as sn, 8 diffs; v0/v1 alternation in struct fill) | 6 | 206.1 | no | sprite uv rect |
| 2026-10-19T00:42:56Z | func_0019AF80 | 548 | NM -> src/cod/sa_nm_0019af80.c (sn -fno-gcse, 50 diffs; outer range loop shape) | 5 | 152.0 | no | damage vol + part ranges |
| 2026-10-19T00:44:28Z | MoveEsp | 548 | NM -> src/cod/sa_nm_002fb0e8.c (sn, 61 diffs; loop-invariant hoist choice, same as MoveEmitter) | 3 | 91.8 | no | effect slot mover |
| 2026-10-19T00:45:06Z | func_00384CA0 | 548 | matched -> src/cod/sa_00384ca0.c (clone of func_00382D30) | 1 | 38.1 | no | menu page update |
| 2026-10-19T00:51:46Z | func_001C0450 | 552 | matched -> src/cod/sa_001c0450.c (flag tests as separate long tmp statements; vec4_eq early-return || body wrapped by eq ^ 1; registration call as inline helper) | 6 | 399.7 | no | lock-on entry refresh |
| 2026-10-19T00:56:38Z | func_002CABE8 | 552 | NM -> src/cod/sa_nm_002cabe8.c (sn, 5 diffs; s0/s4 swap between hit-array pointer and hoisted %hi(D_0044CE38); retail fallback lui lacks reloc) | 6 | 287.3 | no | sound init |
| 2026-10-19T01:00:50Z | func_0017EF98 | 556 | matched -> src/cod/sa_0017ef98.c (per-case byte store order chosen so only the 0x2F6 store cross-jumps; angle read into t before lim) | 5 | 251.7 | no | tip-over state machine |
| 2026-10-19T01:01:59Z | func_001B76D8 | 556 | matched -> src/cod/sa_001b76d8.c (same vec4_eq/vec4_ne idiom as func_001C0450; flag tests as long temps) | 3 | 68.4 | no | model per-frame update |
| 2026-10-19T01:04:38Z | func_002AC9B8 | 556 | NM -> src/cod/sa_nm_002ac9b8.c (sn; loop-invariant mask hoist choice, frame 0x10 short) | 5 | 159.1 | no | ID entry step |
BATCH 116: 4 matched (func_00384CA0, func_001C0450, func_0017EF98, func_001B76D8, all sn-2.95.3-136), 5 NM (func_00159DA0 PARK 8 (sn, as sn), func_0019AF80 PARK 50 (sn -fno-gcse), MoveEsp PARK 61, func_002CABE8 PARK 5, func_002AC9B8 PARK 136 (all sn)), 1 skipped (func_00399508: D_FFFFF delay-loop relocs). Handoff: nm_solved was empty. Reseed OK on the first try: 120s, elf=OK overlay=OK; nm_prune found 0 stale. Per-file settings on new files: sn-2.95.3-136 on all four matched files; no "as", c_flags, fp_hazard_rules or call_loop_pad overrides on registered files. "as": "sn" and -fno-gcse appear only in the NM headers. Notes: func_001C0450 and func_001B76D8 share a 4-float compare idiom. It only matches as the early-return `||` body `if (a[0] != b[0] || ...) return 0; return 1;` wrapped by `vec4_eq(a, b) ^ 1`, which gives the materialized 0/1 plus xori; the `&&` or `!` forms fold the xori away. Their lwu+dsra flag tests need the separate long-temp statements from the NM closer log (BlackJack_UpdateNewRound), each test with its own temp. In func_001C0450 the registration call had to be a static inline helper to get the s0/s3 assignment. func_0017EF98 needed per-case byte-store orders chosen so cross-jumping merges only the final 0x2F6 store (cases 1/2/3 brute-forced). func_00384CA0 is a straight clone of func_00382D30. MoveEsp and func_002AC9B8 are both loop-invariant hoist choices: retail hoists a different subset of the bitmap bases or masks than sn picks for this source. MoveEsp is the same problem as MoveEmitter. func_002CABE8 is down to an s0/s4 swap, and retail's fallback-path `lui` for %hi(D_0044CE38) has no relocation in the split asm, so it may never reloc-match.
| 2026-10-19T01:18:15Z | func_0033DD78 | 560 | NM -> src/cod/sa_nm_0033dd78.c (cygnus dr, 2 diffs; spilled-pointer reload order) | 5 | 157.9 | no | wav header parse |
| 2026-10-19T01:19:57Z | func_00358368 | 560 | NM -> src/cod/sa_nm_00358368.c (cygnus dr, 11 diffs; align-mask schedule before the cprm copy) | 5 | 101.6 | no | sofdec create |
| 2026-10-19T01:21:58Z | func_00158FC8 | 564 | NM -> src/cod/sa_nm_00158fc8.c (sn, 137 diffs; search-loop layout, parked at attempt 3) | 3 | 121.1 | no | hermite curve eval |
| 2026-10-19T01:22:22Z | func_002B8B50 | 568 | matched -> src/cod/sa_002b8b50.c (straight-line calls) | 1 | 24.3 | no | pair table init |
| 2026-10-19T01:23:00Z | func_00276228 | 572 | matched -> src/cod/sa_00276228.c (vec3_copy self-check helper; per-part update calls) | 1 | 37.4 | no | model warp |
| 2026-10-19T01:23:44Z | func_00294F70 | 572 | matched -> src/cod/sa_00294f70.c (load_se inline helper; game() accessor for the unfolded %lo base; case 0x801 placed first) | 2 | 44.0 | no | SE bank select |
| 2026-10-19T01:24:00Z | func_003B4628 | 572 | skipped: split asm drops the HI16 relocs on the two cross-jumped lui copies of %hi(D_007816C0) / %hi(D_00780C00) (raw 0x780000 >> 16); not reloc-matchable from C until the splitter labels them | 0 | 16.4 | no | sdk io rpc |
| 2026-10-19T01:24:14Z | func_003B56A0 | 572 | skipped: same splitter artifact as func_003B4628 (raw 0x780000 >> 16 on the cross-jumped lui copies, no HI16 relocs) | 0 | 13.4 | no | sdk io rpc 64 |
| 2026-10-19T01:28:21Z | func_002D34A8 | 576 | NM -> src/cod/sa_nm_002d34a8.c (99 diffs; p + i*4 combined into one s-reg, slots base placed early; same loop-giv family as MoveEsp) | 3 | 247.1 | no | stream buffer sd remote |
| 2026-10-19T01:33:37Z | func_00350D08 | 576 | NM -> src/cod/sa_nm_00350d08.c (66 diffs; phantom case 0x40 restores 8-pivot switch tree; dead delay-slot residue + prologue copy order remain) | 3 | 316.5 | no | sofdec mpv delim |
BATCH 117: 3 matched (func_002B8B50, func_00276228, func_00294F70, all sn-2.95.3-136), 5 NM (func_0033DD78 PARK 2 (cygnus dr), func_00358368 PARK 11 (cygnus dr), func_00158FC8 PARK 137 (sn), func_002D34A8 PARK 99 (sn), func_00350D08 PARK 66 (cygnus dr)), 2 skipped (func_003B4628, func_003B56A0: the split asm has raw `0x780000 >> 16` lui copies with no HI16 relocs, so they cannot match relocs from C until the splitter labels those cross-jumped copies; the maintainer may want to look at that). nm_handoff: nothing to apply; reseed rc=0 47s, elf=OK overlay=OK; nm_prune: 0 stale. No special per-file settings. New idiom: GCC 2.96 balances a 2-case switch on the low value, so a retail tree pivoting on the high value means a third case that jump-opt deleted (an empty `case 0x40:` in func_00350D08, visible as a dead `addiu v0, 0x40` in a delay slot).
| 2026-10-19T01:35:38Z | func_003808A0 | 584 | matched -> src/cod/sa_003808a0.c (near clone of sa_00384ca0.c; page = base + (idx * 0x48 + 0x48)) | 2 | 46.3 | no | menu page update |
| 2026-10-19T01:39:07Z | func_001AD5C8 | 588 | NM -> src/cod/sa_nm_001ad5c8.c (2 diffs; sb 0x60D vs lui D_005FEE00 schedule; v[4] in its own inline so it shares the GetPart on[] slot; z = v[0] and one = 1.0f held in f21/f20) | 3 | 209.3 | no | gimmick move state |
| 2026-10-19T01:41:13Z | func_0037BF10 | 588 | matched -> src/cod/sa_0037bf10.c (SETTING: "as": "sn" for the mtc1+nop pairs; slot search counts i separately from the loop index j; fail block inside the || failure branch) | 3 | 125.6 | no | sound voice pair start |
| 2026-10-19T01:44:36Z | func_00140E58 | 592 | NM -> src/cod/sa_nm_00140e58.c (120 diffs, 1-word shift; pause-bit lui/and/sltu vs sra/andi; flag tail lines up with if/return bool inlines + pointer-arg setters) | 3 | 202.9 | no | stage obj update |
| 2026-10-19T01:56:43Z | func_002A6DA8 | 592 | NM -> src/cod/sa_nm_002a6da8.c (10 diffs; sd attr+0x30 placement and lui order; float stores solved: scheduler puts each value\'s last store first) | 4 | 727.5 | no | pause screen loop |
| 2026-10-19T01:58:23Z | func_0039CCC0 | 592 | NM -> src/cod/sa_nm_0039ccc0.c (ee-2.9, 147 diffs; retail holds four field bases in s1-s4 and spills flags & 1; source shape unknown) | 2 | 100.0 | no | libmpeg mb setup |
| 2026-10-19T02:04:53Z | func_0030CF10 | 600 | NM -> src/cod/sa_nm_0030cf10.c (72 diffs, same length; constant s-reg assignment; GS_SET_TEX0 must be a macro so constant fields fold) | 3 | 390.3 | no | gs tex0 init |
| 2026-10-19T02:06:15Z | func_0037B0E0 | 600 | NM -> src/cod/sa_nm_0037b0e0.c (139 diffs; print column constant 3 held in s0 in retail, folded to an immediate in ours) | 2 | 81.1 | no | sound debug print |
| 2026-10-19T02:08:20Z | func_0027BB78 | 608 | NM -> src/cod/sa_nm_0027bb78.c (2 diffs: Turn_dest arg load order) | 3 | 125.8 | no | em phase update / Turn_dest |
| 2026-10-19T02:08:59Z | func_00285C58 | 608 | skipped: jump table | 0 | 28.0 | no | jump table |
| 2026-10-19T02:18:04Z | ObjTrans | 608 | NM -> src/cod/sa_nm_0030f650.c (7 diffs: reorg delay-slot/dead addiu; raw-offset vec end defeats scalar/struct alias hoist) | 6 | 573.4 | no | object list update / STL vector erase |

BATCH 118: 2 matched (func_003808A0 sn; func_0037BF10 sn with SETTING `"as": "sn"` on src/cod/sa_0037bf10.c for the mtc1+nop hazard pairs), 8 NM (func_001AD5C8 PARK 2, func_00140E58 PARK 120, func_002A6DA8 PARK 10, func_0039CCC0 PARK 147 (ee-2.9), func_0030CF10 PARK 72, func_0037B0E0 PARK 139, func_0027BB78 PARK 2, ObjTrans PARK 7; all others sn), 1 skipped (func_00285C58, jump table). nm_handoff: func_001AD5C8 solved by the NM closer and registered -> src/cod/sa_001ad5c8.c; reseed rc=0 47s, elf=OK overlay=OK; nm_prune: 0 stale. Learned on ObjTrans: SGI-STL vector erase must keep the find() call nested in the erase argument, and the vector end field accessed through a raw offset (struct member stores let the scalar global load hoist above them).
| 2026-10-19T02:22:09Z | func_0033EBD0 | 608 | NM -> src/cod/sa_nm_0033ebd0.c (42 diffs; regalloc of byte-swap temps) | 3 | 169.9 | no | ADX loop info decode |
| 2026-10-19T02:26:59Z | func_001A5208 | 612 | matched -> src/cod/sa_001a5208.c (raw char buf[0x20] stack area like 0027ef10.c; separate part temps per block; collision mgr pointer held in a local) | 3 | 289.8 | no | gimmick init collision |
| 2026-10-19T02:28:47Z | func_00321AD0 | 612 | NM -> src/cod/sa_nm_00321ad0.c (ee-2.9 in cygnus range: 16-byte sd stride frame; 135 diffs, sift loop regalloc) | 3 | 108.2 | no | heap sort by key |
| 2026-10-19T02:29:48Z | func_0017B2E0 | 616 | matched -> src/cod/sa_0017b2e0.c (near clone of sa_0017b0d8.c; reset stores reordered for the scheduler) | 2 | 60.3 | no | gimmick swing step |
| 2026-10-19T02:37:30Z | func_001A5540 | 616 | NM -> src/cod/sa_nm_001a5540.c (7 diffs: case 3 float constant regs and v[1] store slot) | 5 | 462.5 | no | gimmick swing state |
| 2026-10-19T02:39:56Z | func_0034A0F0 | 616 | NM -> src/cod/sa_nm_0034a0f0.c (4 diffs: delta register a0 vs v1; min as c = c < n ? c : n gives the movz form) | 6 | 145.5 | no | Sofdec ADX-T discard step |
| 2026-10-19T02:43:13Z | func_001B57E8 | 620 | matched -> src/cod/sa_001b57e8.c (SETTING: c_flags_add -f=-fno-gcse, same as the clone TU 0018a680.c; vcall fn typed int-returning) | 4 | 196.6 | no | spawn helper objs + damage volume |
| 2026-10-19T02:45:05Z | func_002D4340 | 620 | NM -> src/cod/sa_nm_002d4340.c (97 diffs, as sn; regalloc; SN cc1 rejects unsigned long long shifts, use unsigned long) | 3 | 112.3 | no | sprite DMA packet build |
| 2026-10-19T02:45:17Z | func_003B4868 | 620 | skipped: split asm has a raw `lui (0x780000 >> 16)` with no HI16 reloc (same splitter artifact as func_003B4628/func_003B56A0) | 0 | 11.9 | no | iob semaphore io (splitter artifact) |

BATCH 119: 3 matched (func_001A5208 sn; func_0017B2E0 sn; func_001B57E8 sn with SETTING c_flags_add -f=-fno-gcse on src/cod/sa_001b57e8.c, the same flag its clone TU 0018a680.c uses), 5 NM (func_0033EBD0 PARK 42 (cygnus dr), func_00321AD0 PARK 135 (ee-2.9: this heap sort sits in the cygnus range but has the ee 16-byte sd-stride frame), func_001A5540 PARK 7, func_0034A0F0 PARK 4 (cygnus dr), func_002D4340 PARK 97 (as sn)), 1 skipped (func_003B4868: same raw `lui (0x780000 >> 16)` splitter artifact as func_003B4628/func_003B56A0; the maintainer may want the splitter to label these). nm_handoff: func_0027BB78 (batch 118 NM) solved by the NM closer and registered -> src/cod/sa_0027bb78.c; reseed rc=0 131s, elf=OK overlay=OK; nm_prune: 0 stale. Learned: GetPart-style inits that put the first sphere vector at sp+0x10 match with one raw `char buf[0x20]` (as in 0027ef10.c) and a separate part temp per block; a no-arg vcall whose fn/vtable regs come out swapped matches once the fn pointer is typed int-returning; for cygnus min(), `c = (c < n) ? c : n` gives the movz form.
| 2026-10-19T02:48:04Z | func_001F3DF0 | 628 | skipped: jump table | 0 | 0.0 | no | jump table |
| 2026-10-19T02:53:33Z | func_00291D48 | 628 | NM -> src/cod/sa_nm_00291d48.c (multi-block short-loop pad gap) | 6 | 328.3 | no | stage light/effect toggle (list scan) |
| 2026-10-19T02:58:20Z | func_0030B420 | 628 | NM -> src/cod/sa_nm_0030b420.c (anchor rebase in tail) | 6 | 271.6 | no | game reset/teardown sequence |
| 2026-10-19T03:00:58Z | func_001034E0 | 636 | NM -> src/cod/sa_nm_001034e0.c (branch layout / cross-jump) | 4 | 148.5 | no | player motion request select |
| 2026-10-19T03:03:24Z | func_002F48A8 | 636 | NM -> src/cod/sa_nm_002f48a8.c (as sn; 13 diffs, frame-count regalloc) | 5 | 145.8 | no | motion/scale update |
| 2026-10-19T03:06:30Z | func_0036AE70 | 636 | NM -> src/cod/sa_nm_0036ae70.c (movn folded to sllv) | 4 | 186.0 | no | MPV GOP header parse (bit reader) |
| 2026-10-19T03:10:23Z | func_003B21D0 | 640 | NM -> src/cod/sa_nm_003b21d0.c (13 diffs, sched/regswap) | 5 | 233.2 | no | SDK sceSifInitCmd |
| 2026-10-19T03:11:45Z | func_003092E0 | 644 | matched -> src/cod/sa_003092e0.c (TEX0 bitfields, mip ptr) | 2 | 81.5 | no | GS texture TEX0/MIPTBP setup |
| 2026-10-19T03:14:35Z | func_00352298 | 644 | NM -> src/cod/sa_nm_00352298.c (short-loop pad gap) | 4 | 163.5 | no | ring table update (cygnus) |
| 2026-10-19T03:18:46Z | func_002E6868 | 652 | matched -> src/cod/sa_002e6868.c (as sn; notGround/linkOn inlines) | 4 | 250.4 | no | object ground step + node sync |

BATCH 120: 2 matched (func_003092E0 sn: GS TEX0 as an `unsigned long` bitfield struct, MIPTBP written through `unsigned long *mip = &t->mip1`; func_002E6868 sn with SETTING "as": "sn" on src/cod/sa_002e6868.c), 7 NM (func_00291D48 PARK 147 (multi-block short-loop pad that ee-as/call_loop_pad do not reproduce), func_0030B420 PARK 27 (retail keeps s0 as the D_007474A0 anchor and rebases into a2), func_001034E0 PARK 141 (branch layout/cross-jump), func_002F48A8 PARK 13 (as sn; frame-count block regalloc only), func_0036AE70 PARK 120 (cygnus dr; retail keeps an unfolded xori/movn that ours folds to sllv), func_003B21D0 PARK 13 (ee-2.9 sceSifInitCmd; sched/regswap, good permuter candidate), func_00352298 PARK 106 (cygnus dr; 3-nop loop pad)), 1 skipped (func_001F3DF0: jump table). nm_handoff: func_001A5540 (batch 119 NM), func_0033D720 and func_0036DFF0 solved by the NM closer and registered; reseed rc=0 142s, elf=OK overlay=OK; nm_prune: 0 stale. Learned: retail's `lbu; xori 1; andi 1; beqz` flag test comes from an inline returning `!bits->b0` used as the if condition (a direct `if (!b0)` folds to andi/bnel); the branchy `v1=1; bnel` flag pattern comes from an inline with an early `return 1` tested as `== 1`; anchored game-work fields (symbol+0x584) match with a `*(int *)((char *)&D_007474A0 + 0x584)` macro, and separate `&= ~X` statements give retail's unfolded and-chain; a volatile global store stays out of the delay slot; an unsigned switch index gives the 1,0,2 compare order.
| 2026-10-19T03:43:16Z | func_003B4220 | 656 | matched -> src/cod/sa_003b4220.c (varargs via __builtin_next_arg - 0x30; implicit func_003B3EC8; r reused for the uncached read) | 3 | 284.5 | no | SDK sceOpen (iob/SIF rpc) |
| 2026-10-19T03:45:31Z | func_00160FF0 | 664 | matched -> src/cod/sa_00160ff0.c (game-flag anchor macros, separate |= / &= statements; `int *hp = &D_00566E40` at case top gives the hoisted lui in s3) | 3 | 135.8 | no | event movie play step |
| 2026-10-19T03:48:44Z | func_00345848 | 664 | NM -> src/cod/sa_nm_00345848.c (cygnus dr; s-reg assignment) | 4 | 192.0 | no | Sofdec MWSFD error report |
| 2026-10-19T03:51:37Z | func_00322C68 | 684 | matched -> src/cod/sa_00322c68.c (cygnus dr; AdxfLd struct, unsigned int handle table, separate error calls cross-jumped, memset-like callee returns void *) | 5 | 167.8 | no | CRI ADXF load start |
| 2026-10-19T03:53:42Z | func_00379910 | 684 | NM -> src/cod/sa_nm_00379910.c (column var regalloc a1 vs v0) | 5 | 125.7 | no | debug menu entry print |
| 2026-10-19T03:56:26Z | func_00312B00 | 692 | matched -> src/cod/sa_00312b00.c (null-object case group first; two full loadWait tails cross-jumped; separate result vars; validId inline gives xori) | 5 | 163.5 | no | object factory by id |
| 2026-10-19T03:56:38Z | cbTimerHandler | 692 | skipped: HAND asm (sync/ei and a $gp load before the callback jalr) | 0 | 11.7 | no | SDK timer interrupt handler (asm) |
| 2026-10-19T03:56:38Z | cOmWeapon_SetBreak | 696 | skipped: jump table | 0 | 0.0 | no | jump table |
| 2026-10-19T03:56:47Z | __check_eh_spec | 696 | skipped: C++ exception regions (try/catch eh labels), not expressible in C | 0 | 9.3 | no | libgcc C++ EH runtime |
| 2026-10-19T04:01:05Z | func_0032D430 | 704 | NM -> src/cod/sa_nm_0032d430.c (cygnus dr; 44 diffs, init-store scheduling) | 5 | 258.1 | no | CRI handle create (buffer carve) |

BATCH 121: 4 matched (func_003B4220 ee-2.9 sceOpen-style open: varargs read as `*(int *)((char *)__builtin_next_arg(flags) - 0x30)`, implicit func_003B3EC8, `r` reused for the uncached ack read; func_00160FF0 sn: separate `|=`/`&=` statements on game-flag anchor macros, and `int *hp = &D_00566E40` at the top of case 0 gives retail's hoisted lui in s3; func_00322C68 cygnus dr: AdxfLd struct, `unsigned int` handle table, error paths as separate calls that cross-jump, memset-like callee declared `void *`; func_00312B00 sn: null-object case group first in the switch, two full loadWait tails cross-jumped, separate result variables, `validId` inline for retail's xori compare), 3 NM (func_00345848 PARK 158 (cygnus dr; obj/err s-reg swap), func_00379910 PARK 150 (sn; column var in a1 instead of v0), func_0032D430 PARK 44 (cygnus dr; init-store scheduling, search-loop pad matched)), 3 skipped (cbTimerHandler: HAND asm sync/ei and $gp; cOmWeapon_SetBreak: jump table; __check_eh_spec: C++ exception regions). nm_handoff: func_0016F790, func_00188B50, func_0019A0B8, func_0019A328, func_0019A590, func_0019AA80, func_0019AD00, func_00345BE0, func_003B9F60 solved by the NM closer and registered; reseed rc=0 125s, elf=OK overlay=OK; nm_prune: 0 stale. Learned: a constant pointer local assigned at the top of a block hoists the global's lui into an s-reg across calls; statement order of stores to an int handle table vs an int field decides whether sched keeps them in order (char* table reorders); inline boolean helpers reproduce xori/beqz compares.
| 2026-10-19T04:06:22Z | func_003B4AD8 | 704 | NM -> src/cod/sa_nm_003b4ad8.c (27 diffs, s4-s7 rotation) | 5 | 141.5 | no | SDK sceWrite (iob/SIF rpc) |
| 2026-10-19T04:12:45Z | func_003514B8 | 712 | matched -> src/cod/sa_003514b8.c (single goto tail; int-typed load orders prologue) | 4 | 382.2 | no | CRI Sofdec decode step |
| 2026-10-19T04:16:04Z | func_0010B2E8 | 716 | NM -> src/cod/sa_nm_0010b2e8.c (159 diffs, last-slot regalloc/return-block placement) | 4 | 199.5 | no | player slot busy check |
| 2026-10-19T04:19:32Z | cOl21_createShapes | 716 | matched -> src/cod/sa_0017dcb8.c (SETTING: fp_hazard_rules mtc1 on the new file; vset inline gives the pointer-copy regs) | 3 | 208.0 | no | cOl21 shape setup |
| 2026-10-19T04:20:22Z | func_00337728 | 716 | matched -> src/cod/sa_00337728.c (first try; `for (;;);` hangs pick up ee-as loop pad) | 1 | 49.7 | no | CRI DTX init |
| 2026-10-19T04:20:29Z | func_00129718 | 716 | skipped: jump table (jr $a0) | 0 | 7.0 | no | jump table |
| 2026-10-19T04:23:39Z | func_002C0F90 | 732 | matched -> src/cod/sa_002c0f90.c (inline worldPack(char *g) keeps the anchor+0x5AC unfolded; separate loop counter) | 4 | 176.5 | no | cSceAtManager init |
| 2026-10-19T04:26:15Z | func_0034E4B0 | 736 | NM -> src/cod/sa_nm_0034e4b0.c (88 diffs, s-reg ranking + movz clamp) | 4 | 155.5 | no | CRI Sofdec MPS demux |
| 2026-10-19T04:28:41Z | func_00158CD0 | 740 | NM -> src/cod/sa_nm_00158cd0.c (155 diffs, loop giv + FP tail) | 4 | 145.8 | no | Hermite key curve eval |
| 2026-10-19T04:29:49Z | func_00275DA8 | 744 | matched -> src/cod/sa_00275da8.c (`(x ^ 0x265) != 0` gives xori/bnez; `int k = 2; if (k < n)` from clone 0027ef10.c) | 2 | 67.7 | no | enemy 0x265 collision setup |

BATCH 122: 5 matched (func_003514B8 cygnus dr: Sofdec decode step, single `*out = 1; goto end` tail and an int-typed load to order the prologue; cOl21_createShapes sn with SETTING fp_hazard_rules mtc1 on src/cod/sa_0017dcb8.c; func_00337728 cygnus dr first try; func_002C0F90 sn; func_00275DA8 sn), 4 NM (func_003B4AD8 PARK 27 (ee-2.9 sceWrite; s4-s7 rotation only, good permuter candidate), func_0010B2E8 PARK 159 (sn; last slot of the 5-way check gets different regs and owns the shared returns), func_0034E4B0 PARK 88 (cygnus dr; s-reg ranking + movz clamp), func_00158CD0 PARK 155 (sn fdiv,mtc1; loop giv + Hermite FP tail)), 1 skipped (func_00129718: jump table). nm_handoff: func_0016F4A8 and func_00182690 solved by the NM closer and registered; reseed rc=0 50s, elf=OK overlay=OK; nm_prune: 0 stale. Learned: retail's unfolded `addiu base,%lo(D_007474A0); lw 0x5AC(base)` comes from an inline taking the anchor as `char *g` (each call gets its own base pseudo, so the hi part stays in an s-reg and the lo is rematerialized per call); a constant table copied into a two-vector stack array with per-loop pointer copies matches through a `vset(float *v, x, y, z, w)` inline; when a pointer-typed load hoists above an int store, loading it as `(T *)*(int *)p` keeps it behind the store; cygnus shared `*out = 1; return err;` tails need one exit with gotos (separate returns get their own copies); a 0xBFECCCCC-style constant is just the literal written one ULP low (-1.8499999046325684f).
| 2026-10-19T04:40:57Z | func_00399008 | 744 | skipped: splitter artifact (delay-loop constant 0xFFFFF labelled D_FFFFF with hi/lo relocs, like func_003B4628) | 0 | 15.4 | no | libcdvd sceCdInit |
| 2026-10-19T04:43:03Z | func_00140860 | 756 | NM -> src/cod/sa_nm_00140860.c (134 diffs, type-range/flag inline shape) | 4 | 126.0 | no | enemy list compaction |
| 2026-10-19T04:45:10Z | func_002B1C80 | 756 | matched -> src/cod/sa_002b1c80.c (SETTING: fp_hazard_rules mtc1 on the new file; real `while` loop hoists 0xFFFF, `== 1UL` bit test avoids the sign-extend) | 4 | 127.4 | no | message draw / ruby scan |
| 2026-10-19T04:48:30Z | func_00180CD8 | 760 | NM -> src/cod/sa_nm_00180cd8.c (155 diffs, cross-jump of disp branches + FP tail regalloc) | 3 | 174.2 | no | HP-ratio mesh layer color |
| 2026-10-19T04:50:08Z | func_001E1D10 | 760 | matched -> src/cod/sa_001e1d10.c (struct-copied 9-entry table, fall-through switch; per-block store order picks which fC stores cross-jump) | 3 | 90.9 | no | combo table lookup |
| 2026-10-19T04:50:15Z | Fil_clut_set | 760 | skipped: jump table | 0 | 0.1 | no | jump table |
| 2026-10-19T04:55:54Z | func_001EC088 | 764 | matched -> src/cod/sa_001ec088.c (`if (n >= 32) return 0;` getter, float step/half locals, split u8 counters, a/b then na/nb statement order picks s4/s5) | 6 | 338.6 | no | part swing by flag bits |
| 2026-10-19T05:01:50Z | func_0031AFE0 | 764 | NM -> src/cod/sa_nm_0031afe0.c (163 diffs, cygnus dr as=sn like its callees; char sign-test reloads + arg reg shift) | 6 | 351.4 | no | pad state update |
| 2026-10-19T05:04:05Z | func_00326890 | 776 | NM -> src/cod/sa_nm_00326890.c (174 diffs, retail assembler pads the two-block loop; ours cannot, rest is a 3-word shift) | 2 | 129.8 | no | CRI stream header parse |
| 2026-10-19T05:04:14Z | func_001DAB00 | 788 | skipped: jump table | 0 | 0.1 | no | jump table |

BATCH 123: 3 matched (func_002B1C80 sn with SETTING fp_hazard_rules mtc1 on src/cod/sa_002b1c80.c: message draw with ruby scan; func_001E1D10 sn: combo table lookup; func_001EC088 sn: paired part swing), 4 NM (func_00140860 PARK 134 (sn; type-range/flag inline shape), func_00180CD8 PARK 155 (sn mtc1; retail cross-jumps only the final jal of the three disp branches, FP tail regalloc), func_0031AFE0 PARK 163 (cygnus dr as=sn like its callees 0031b410.c; char sign-test reloads become lbu+sll, arg regs shifted), func_00326890 PARK 174 (cygnus dr; retail assembler padded a two-block loop with 3 nops, ours never pads multi-block loops)), 3 skipped (func_00399008 splitter artifact; Fil_clut_set and func_001DAB00 jump tables). nm_handoff: func_003769B0 and func_003A93F8 solved by the NM closer and registered; reseed rc=0 122s, elf=OK overlay=OK; nm_prune: 0 stale. Learned: a goto-built scan loop stops sn hoisting its constants, and a real `while` whose arms each store the cursor matches; `if (n >= 32) return 0; return ((long)w >> n) & 1;` gives the bnez-to-load getter shape where `if (n < 32)` gives the reverse; explicit bit-index locals let gcse keep `(i+1) < 32` live, and the statement order of the index locals decides which s-reg each gets; split u8 counters per branch match retail's distinct regs; per-block store order decides which shared `fC = 0` tails cross-jump; functions in the 0x31A–0x31B pad module are cygnus even below the CRI band (check the callees' compile_units), and union-typed u64 masks make cygnus reload u32 loads in the loop like retail.
| 2026-10-19T05:13:59Z | func_00355F88 | 788 | matched -> src/cod/sa_00355f88.c (modulo written twice in the condition keeps retail second break check; field reads instead of base/n locals; per-branch id var with `id2 = 3` just before the compare; ifc then fp temps) | 5 | 427.5 | yes | CRI IPU FIFO DMA restart |
| 2026-10-19T05:19:21Z | _initSeq | 788 | NM -> src/cod/sa_nm_003a0018.c (12 diffs, size mult operand order + b2 store pairing; good permuter candidate) | 6 | 315.0 | no | libmpeg sequence init |
| 2026-10-19T05:23:54Z | classCFILTER_TAG_Filter_main | 796 | NM -> src/cod/sa_nm_002a0940.c (182 diffs, 0xE00 constant held in s2 vs rematerialized) | 6 | 267.3 | no | GS filter tag main |
| 2026-10-19T05:27:09Z | LightData_Load | 892 | NM -> src/cod/sa_nm_002d6a60.c (165 diffs, no-SR inner mult + s-reg ranking) | 6 | 182.6 | no | light data loader |
| 2026-10-19T05:30:14Z | func_00276F18 | 784 | NM -> src/cod/sa_nm_00276f18.c (10 diffs, v0/v1 swap in entry 5) | 6 | 185.0 | no | 8-entry light/effect table init |
| 2026-10-19T05:33:15Z | func_001F20F8 | 800 | NM -> src/cod/sa_nm_001f20f8.c (2 diffs, v0/v1 temp in wave 3) | 6 | 181.1 | no | coliseum wave spawner |
| 2026-10-19T05:37:25Z | func_00337400 | 808 | NM -> src/cod/sa_nm_00337400.c (13 diffs, global-alloc priority base vs const 1) | 6 | 250.3 | no | CRI pad event queue |
| 2026-10-19T05:40:23Z | func_00320AE8 | 816 | NM -> src/cod/sa_nm_00320ae8.c (191 diffs, ee-2.9 spill choice + dead tail) | 5 | 177.8 | no | SDK tree walk (ee-2.9) |
| 2026-10-19T05:44:41Z | func_002BF948 | 820 | NM -> src/cod/sa_nm_002bf948.c (176 diffs, cont vs &skill callee-saved choice) | 6 | 258.0 | no | checkpoint retry save snapshot/restore |
| 2026-10-19T05:48:46Z | func_0028E0E0 | 824 | NM -> src/cod/sa_nm_0028e0e0.c (16 diffs, switch reg + bit-6 dsrl) | 6 | 244.4 | no | obj init / stage lock switch |
| 2026-10-19T05:49:10Z | func_0013DB50 | 776 | skipped | 0 | 0.1 | no | jump table |
| 2026-10-19T05:49:10Z | func_003A7D08 | 604 | skipped | 0 | 0.0 | no | jump table |

BATCH 124: 1 matched (func_00355F88 cygnus dr: IPU FIFO DMA restart), 9 NM (_initSeq PARK 12 (sn; size mult operand order + b2 store pairing, good permuter candidate), classCFILTER_TAG_Filter_main PARK 182 (sn; retail keeps 0xE00 in s2), LightData_Load PARK 165 (sn -fno-gcse; inner mult not strength-reduced, s-reg ranking), func_00276F18 PARK 10 (sn; v0/v1 swap in entry 5), func_001F20F8 PARK 2 (sn; wave-3 temp v0/v1), func_00337400 PARK 13 (cygnus dr; base vs const 1 allocation), func_00320AE8 PARK 191 (ee-2.9; spill choice + dead tail), func_002BF948 PARK 176 (sn; cont vs &skill callee-saved choice), func_0028E0E0 PARK 16 (sn; switch value v1 vs retail a0, bit-6 test srl vs retail dsrl)), 2 skipped (func_0013DB50 and func_003A7D08 jump tables). nm_handoff: func_0031CDC0 and func_0034A5E0 solved by the NM closer and registered; reseed rc=0 52s, elf=OK overlay=OK; nm_prune: 0 stale. Learned: `typedef struct {...} T __attribute__((aligned(16)))` gives lq/sq struct copies without rounding the size; an inline `ckFlag(f, m)` hides power-of-2 masks from fold (and+sltu); `((unsigned char *)&flags)[1] & 1` gives lbu+andi for bit 8 and `(flags >> 7) & 1` gives lbu+dsrl; a pack-relative pointer written as `pack[N] + (int)pack` (int pointer, integer sum) gives retail's addu operand order where both char* orders reverse it; store order of same-constant float stores is scheduled, so permute source order; cygnus strict aliasing lets void* id fields reorder around int stores.
| 2026-10-19T05:53:43Z | Turn_dest_Y | 832 | NM -> src/cod/sa_nm_002da468.c (60 diffs, f12/f14 angle vs step split) | 6 | 174.6 | no | yaw/pitch turn toward target |
| 2026-10-19T05:54:36Z | func_00379190 | 832 | matched -> src/cod/sa_00379190.c (clone of func_003794D0, first try) | 1 | 48.0 | no | status page text draw |
| 2026-10-19T05:58:13Z | func_001F4CA8 | 836 | NM -> src/cod/sa_nm_001f4ca8.c (20 diffs, address add order/s-reg reuse; permuter candidate) | 6 | 212.4 | no | custom ID widget color by mode |
| 2026-10-19T11:42:11Z | func_00144C90 | 840 | matched -> src/cod/sa_00144c90.c (SETTING as=sn; elementwise vec copy inline, separate final loop counter, global scale loaded before the int stores, direct tbl[i][0] reloads for x) | 6 | 20632.5 | no | ID work table setup |
| 2026-10-19T11:44:38Z | func_001846D8 | 840 | NM -> src/cod/sa_nm_001846d8.c (121 diffs, s-reg count + load reuse) | 6 | 143.0 | no | enemy part damage timers/effects |
| 2026-10-19T11:46:29Z | func_00319970 | 844 | NM -> src/cod/sa_nm_00319970.c (168 diffs, hoisted global base + bool andi + speed reuse) | 5 | 106.5 | no | mesh UV scroll |
| 2026-10-19T11:49:16Z | func_002B1890 | 852 | NM -> src/cod/sa_nm_002b1890.c (2 diffs, x1/wm schedule swap; permuter candidate) | 6 | 163.7 | no | 9-slice window frame draw |
| 2026-10-19T11:51:15Z | func_001F2D60 | 856 | NM -> src/cod/sa_nm_001f2d60.c (214 diffs, stack colour locals + phantom-param registers; family of 001F3118) | 3 | 114.1 | no | CustomID panel colour anim states |
| 2026-10-19T11:53:31Z | func_00351CB0 | 856 | matched -> src/cod/sa_00351cb0.c (block-scoped callback/obj locals, hdr[6] and p->0x70 in locals, separate delimiter pointer) | 4 | 131.4 | no | Sofdec MPV header step |
| 2026-10-19T11:59:05Z | func_0033FDC0 | 868 | matched -> src/cod/sa_0033fdc0.c (cygnus-2.96 dr; Buf.addr as char* for strict-aliasing sched) | 3 | 327.6 | no | CRI stream DMA kick |

BATCH 125: 4 matched (func_00379190 sn: clone of func_003794D0; func_00144C90 sn, SETTING "as": "sn" on src/cod/sa_00144c90.c; func_00351CB0 cygnus dr: Sofdec MPV header step; func_0033FDC0 cygnus dr: CRI stream DMA kick), 6 NM (Turn_dest_Y PARK 60 (sn as=sn fdiv hazard; f12/f14 angle vs step split), func_001F4CA8 PARK 20 (sn; address add order + s-reg reuse), func_001846D8 PARK 121 (sn as=sn; s-reg count + load reuse), func_00319970 PARK 168 (sn; hoisted global base, bool andi, speed reuse), func_002B1890 PARK 2 (sn as=sn; x1/wm schedule swap, permuter candidate), func_001F2D60 PARK 214 (sn; CidColor family of 001F3118, phantom by-value param registers)). nm_handoff: 8 solved by the NM closer and registered (func_0015AF30, func_001F20F8, func_001F4CA8, func_00276F18, func_003315D8, func_00337400, func_0034A0F0, func_0034F4C0); reseed rc=0 136s, elf=OK overlay=OK; nm_prune: 0 stale. Learned: under cygnus strict aliasing, declaring a buffer `addr` field as `char *` instead of int lets loads of int fields schedule past stores to it (fixed a 7-diff store/load order in 0033FDC0); a dummy `case 1: default:` group moves the switch pivot and putting the default body first matches the layout; an inline wrapping repeated call groups collapses scheduling diffs; an elementwise vec-copy inline gives lwc1/swc1 instead of ldl/sdl; base pointers assigned after the early-return test reproduce retail's base-register access; `(unsigned long)t >> N & 1UL` on a long copy gives lwu+andi.
| 2026-10-19T12:10:12Z | func_002D3D88 | 876 | matched -> src/cod/sa_002d3d88.c (cparam order, out-of-line goto tail, (long) casts on int shift operands, memset declared void* return) | 6 | 472.4 | no | movie player work setup |
| 2026-10-19T12:15:01Z | func_0037B918 | 884 | NM -> src/cod/sa_nm_0037b918.c (61 diffs, -fno-gcse; hoisted %hi choice into fp differs) | 6 | 281.2 | no | debug entry status page |
| 2026-10-19T12:17:44Z | func_00141CE8 | 888 | matched -> src/cod/sa_00141ce8.c (sub-base locals, block-scoped second p+0x190, (idx + 12) << 2 offset to stop fold) | 5 | 154.6 | no | HUD panel reset |
| 2026-10-19T12:20:44Z | func_003B4D98 | 904 | NM -> src/cod/sa_nm_003b4d98.c (46 diffs, case-1 constant held in s5 from prologue) | 5 | 173.6 | no | SDK fileio ioctl |
| 2026-10-19T12:22:59Z | func_00326CB8 | 908 | matched -> src/cod/sa_00326cb8.c (cygnus dr; while(get, n) rotated loop, zero-skip bound reads hn->ck.f4 directly) | 3 | 129.5 | no | ADX SJ header step |
| 2026-10-19T12:29:39Z | cModel_setupModel | 920 | NM -> src/cod/sa_nm_00149738.c (82 diffs, dead sp+0x20 data copy + error-tail cross-jump) | 6 | 391.8 | no | model mesh setup from script |
| 2026-10-19T12:29:47Z | func_00322138 | 920 | skipped (jump table) | 0 | 0.1 | no | jump table (skip rule) |
| 2026-10-19T12:29:47Z | func_00268068 | 924 | skipped (jump table) | 0 | 0.0 | no | jump table (skip rule) |
| 2026-10-19T12:29:47Z | func_00167518 | 928 | skipped (jump table) | 0 | 0.0 | no | jump table (skip rule) |
| 2026-10-19T12:34:06Z | func_00343E28 | 932 | NM -> src/cod/sa_nm_00343e28.c (56 diffs, retail cross-jumped Error tails + loop iterator) | 6 | 243.5 | no | Sofdec player create |
BATCH 126: 3 matched (func_002D3D88 sn: movie player work setup; func_00141CE8 sn: HUD panel reset; func_00326CB8 cygnus dr: CRI handle chunk scan), 4 NM (func_0037B918 PARK 61 (sn -fno-gcse; hoisted %hi into fp picks a different global), func_003B4D98 PARK 46 (ee-2.9; retail keeps the case-1 constant in s5), cModel_setupModel PARK 82 (sn; dead sp+0x20 store and different error-tail cross-jumping), func_00343E28 PARK 56 (cygnus dr; retail cross-jumps Error tails with the message built in a0, plus slot loop iterator regs)), 3 skipped jump tables (func_00322138, func_00268068, func_00167518). nm_handoff: 0 registered, func_002B1890 rejected by re-verify (211 vs 213 words; left with the NM closer); reseed rc=0 48s, elf=OK overlay=OK; nm_prune: 0 stale. Learned: declaring a callee as returning `long` makes its `== -1` compare DImode so CSE stops reusing an SImode -1 register (98 -> 56 in 00343E28); separate block-local node variables per scan loop and integer pointer sums (`ofs + (int)base`) give retail's addu operand order; a `while (get(...), (n = f4) != 0)` loop gives the rotated layout; -fno-gcse keeps constants in s-regs.
| 2026-10-19T12:35:32Z | _sceFs_Rcv_Intr | 948 | skipped (jump table) | 0 | 0.0 | no | IOP fs rpc interrupt |
| 2026-10-21T01:11:51Z | func_0010CD38 | 936 | NM -> src/cod/0010cd38.c (3 diffs; matches only with func_002A8578 declared void, its C definition in 00134880.c returns int: REPORTED, not changed) | 6 | 2100.0 (split across two sessions) | no | subsystem cEm00 (0x10xxxx enemy steps): thrown-down step |
| 2026-10-21T01:15:02Z | func_00137670 | 372 | NM -> src/cod/00137670.c (75 diffs; retail has an extra axis pointer copy and a spilled scaled-vector pointer, 0x100 frame) | 4 | 169.7 | no | subsystem collision (0x130700-0x137FFF): closest point on oriented box |
| 2026-10-21T01:17:27Z | SphereTriangle | 564 | NM -> src/cod/00135b18.c (85 diffs; BLOCKED: retail VU0 copies store straight to the stack slot, needs a vu0.h copy macro with a memory-operand destination) | 1 | 139.2 | no | subsystem collision (0x130700-0x137FFF): sphere vs triangle |
| 2026-10-21T01:17:33Z | func_00100250 | 8 | skipped (hand-written syscall stub) | 0 | 0.0 | no | crt (0x100000): syscall 0x23 stub, hand-written |
| 2026-10-21T01:18:59Z | SphereSquare | 368 | matched -> src/cod/00135d50.c (cVec pt[3] so the zero-inits take the macro offset; plain-expression squared distance) | 4 | 85.1 | no | subsystem collision (0x130700-0x137FFF): sphere vs quad |
| 2026-10-21T01:22:36Z | func_001334A8 | 452 | non-matching | 6 | 207.4 | no | subsystem collision (0x130700-0x137FFF): debug draw of a triangle or quad; NM -> src/cod/001334a8.c (6 diffs, color and %hi(D_005CAFF0) swap s4/s5; needs fp_hazard_rules fdiv) |
| 2026-10-21T01:27:13Z | func_001346C8 | 48 | non-matching | 6 | 262.4 | no | subsystem collision (0x130700-0x137FFF): find collision unit by key; NM -> src/cod/001346c8.c (6 diffs, one missing R5900 short-loop pad in a loop with an inner branch; no assembler route pads it) |
| 2026-10-21T01:30:51Z | func_00137E70 | 196 | matched | 5 | 479.8 | no | subsystem collision (0x130700-0x137FFF): path cone factor; matched -> src/cod/00137e70.c (inline unit+rotate matrix helper; per-file fp_hazard_rules div1) |
| 2026-10-21T01:31:08Z | func_00137BB8 | 252 | skipped | 0 | 10.3 |
| 2026-10-21T01:35:05Z | func_00134CB0 | 360 | non-matching | 6 | 166.5 | no | subsystem collision (0x130700-0x137FFF): sphere push-out in XZ; NM -> src/cod/00134cb0.c (69 diffs, &f.b register and first-return block order; needs -ffast-math + fp_hazard_rules sqrt) |
| 2026-10-21T01:38:49Z | func_00136458 | 348 | non-matching | 6 | 203.2 | no | subsystem collision (0x130700-0x137FFF): segment vs triangle front; NM -> src/cod/00136458.c (5 diffs, address scheduling of &tri[1]/&tri[2]) |
| 2026-10-21T01:40:35Z | func_00136030 | 368 | non-matching | 6 | 101.4 | no | subsystem collision (0x130700-0x137FFF): point in triangle; NM -> src/cod/00136030.c (5 diffs, first bc1t filled as bc1tl) |

BATCH 127 (subsystem collision, 0x130700-0x137FFF): 2 matched (SphereSquare sn: sphere vs quad; func_00137E70 sn, SETTING "fp_hazard_rules": "div1" on src/cod/00137e70.c: path cone factor), 8 NM (func_0010CD38 PARK (sn; matches only with func_002A8578 declared void, its definition returns int; REPORTED), func_00137670 PARK 75 (sn; extra axis pointer copy, 0x100 frame), SphereTriangle PARK 85 (sn; folded VU0 copies), func_001334A8 PARK 6 (sn fdiv; color and %hi(D_005CAFF0) swap s4/s5), func_001346C8 PARK 6 (sn; R5900 short-loop pad in a loop with an inner branch, no assembler route pads it), func_00134CB0 PARK 69 (sn -ffast-math sqrt; &f.b register and first-return block order), func_00136458 PARK 5 (sn; &tri[1]/&tri[2] address scheduling, permuter candidate), func_00136030 PARK 5 (sn; first bc1t filled as bc1tl, permuter candidate)), 3 skipped (_sceFs_Rcv_Intr jump table, func_00100250 hand-written syscall stub, func_00137BB8 existing NM draft). nm_handoff: func_00150C10 and func_002B1890 solved by the NM closer and registered; reseed rc=0 47s, elf=OK overlay=OK; nm_prune: 0 stale. Learned: an inline `RotMatrixOf(m, ang)` wrapping UnitMatrix+RotMatrix keeps the matrix address out of a saved register (50 -> 0 with div1); a pointer local to a frame-struct member set right after the zeroing store reproduces retail's early address in a saved register; `if (!(fabsf(d) < eps)) return 0; return 1;` gives retail's fallthrough layout where `if (...) return 1; return 0;` does not; `__builtin_sqrtf` needs -ffast-math to drop the sqrtf fallback call.
| 2026-10-21T01:43:39Z | func_00135040 | 408 | non-matching | 4 | 87.8 | no | subsystem collision (0x130700-0x137FFF): push-out vs solid point; NM -> src/cod/00135040.c (76 diffs, retail sqrt.s pad is a fixed template so nothing schedules into it; our cc1 schedules into it) |
| 2026-10-21T01:46:04Z | func_00133BC8 | 472 | non-matching | 6 | 139.8 | no | subsystem collision (0x130700-0x137FFF): box body world corners/bounds; NM -> src/cod/00133bc8.c (39 diffs, self s0 vs s1 and copy-base reuse) |
| 2026-10-21T01:47:13Z | func_00134E18 | 552 | non-matching | 3 | 64.4 | no | subsystem collision (0x130700-0x137FFF): sphere vs box push-out; NM -> src/cod/00134e18.c (114 diffs from one shift: retail sqrt.s pad is a fixed template, our cc1 schedules the radius load into it) |
| 2026-10-21T01:55:07Z | func_001321D8 | 964 | non-matching | 6 | 448.9 | no | collision grid |
| 2026-10-21T01:57:27Z | func_001399A0 | 452 | matched | 3 | 53.2 | no | camera |
| 2026-10-21T02:01:29Z | func_0013B5F0 | 968 | non-matching | 5 | 138.8 | no | camera |
| 2026-10-21T02:05:44Z | func_0013BD40 | 1064 | skipped | 3 | 165.4 | no | id set display (jump table; draft at 2 diffs = jump table relocs, needs signed cIDBaseEnt.flags) |

BATCH 128 (subsystems collision 0x130700-0x137FFF and camera 0x1399A0-0x13BFFF): 1 matched (func_001399A0 sn: follow camera placed from two objects through the view matrix), 5 NM (func_00135040 PARK 76 (sn; sqrt.s template pad), func_00133BC8 PARK 39 (sn; self s0 vs s1 in the corner loop), func_00134E18 PARK 114 (sn; sqrt.s template pad), func_001321D8 PARK 10 (sn; &result/y+1 spill slots swapped, list + count operand order, &pos load in the debug draw), func_0013B5F0 PARK (sn; swing step constant hoisted before the branch where retail loads it in each arm)), 1 skipped (func_0013BD40 jump table; draft is at 2 diffs, both the table relocation, with the flags word read as signed). nm_handoff: func_002C9950, func_00359848, func_00383170 registered; reseed rc=0, elf=OK overlay=OK; nm_prune: 0 stale. Learned: retail builds `x & ~8` as `addiu -9` only when the field is signed int; on an unsigned field sn emits lui/ori 0xFFFFFFF7. A `vecSet(&frame.member, ...)` inline stores x/y/z sp-relative and w through the member pointer, as retail does. `ld 0x2F0` masked with 0xFFFF<<32 is the mode/phase state word (`stateWord & 0xFFFF00000000L`).
| 2026-10-21T02:11:40Z | func_002998A0 | 56 | matched | 3 | 41.5 | no | GS packet builder (0x299xxx) |
| 2026-10-21T02:13:48Z | func_00276DC8 | 200 | non-matching | 4 | 83.8 | no | enemy link push (0x276xxx); NM -> src/cod/00276dc8.c (10 diffs, &f.v kept in s0 across the call) |
| 2026-10-21T02:14:11Z | func_001FEFA0 | 136 | skipped | 0 | 0.0 | no | splitter artifact (stack-adjust junk before the body) |
| 2026-10-21T02:14:11Z | func_00320270 | 16 | skipped | 0 | 0.0 | no | splitter artifact (fragment without return) |
| 2026-10-21T02:14:11Z | func_003327D8 | 48 | skipped | 0 | 0.0 | no | splitter artifact (dead load tail) |
| 2026-10-21T02:14:11Z | func_00336318 | 24 | skipped | 0 | 0.0 | no | splitter artifact (dead load tail) |
| 2026-10-21T02:14:11Z | func_002FDDA8 | 184 | skipped | 0 | 0.0 | no | cvt.w.s (skip rule) |
| 2026-10-21T02:14:59Z | func_002DAF68 | 156 | non-matching | 3 | 30.7 | no | sphere overlap (0x2DAxxx); NM -> src/cod/002daf68.c (10 diffs, sqrt template: radius add scheduled before the squares) |
| 2026-10-21T02:14:59Z | func_002DB008 | 188 | skipped | 0 | 0.1 | no | cylinder overlap (0x2DBxxx); same sqrt template blocker as func_002DAF68 (add after sqrt.s) |
| 2026-10-21T02:16:33Z | func_0012A578 | 148 | non-matching | 4 | 59.1 | no | player trail point (0x12Axxx); NM -> src/cod/0012a578.c (37 positional, one missing entry move of pl) |
| 2026-10-21T02:16:53Z | _rix_000 | 116 | skipped | 0 | 0.1 | no | HAND MMI (IPU image unpack, handwritten addi/qfsrv) |
| 2026-10-21T02:16:53Z | _ri0_000 | 148 | skipped | 0 | 0.0 | no | HAND MMI (IPU image unpack, handwritten addi/qfsrv) |
| 2026-10-21T02:16:53Z | _rix_100 | 156 | skipped | 0 | 0.1 | no | HAND MMI (IPU image unpack, handwritten addi/qfsrv) |
| 2026-10-21T02:16:53Z | _ri0_010 | 184 | skipped | 0 | 0.0 | no | HAND MMI (IPU image unpack, handwritten addi/qfsrv) |
| 2026-10-21T02:16:53Z | _rix_011 | 248 | skipped | 0 | 0.0 | no | HAND MMI (IPU image unpack, handwritten addi/qfsrv) |
| 2026-10-21T02:16:53Z | _ri0_011 | 252 | skipped | 0 | 0.0 | no | HAND MMI (IPU image unpack, handwritten addi/qfsrv) |
| 2026-10-21T02:16:53Z | _ri0_111 | 276 | skipped | 0 | 0.0 | no | HAND MMI (IPU image unpack, handwritten addi/qfsrv) |
| 2026-10-21T02:16:53Z | _rix_111 | 288 | skipped | 0 | 0.0 | no | HAND MMI (IPU image unpack, handwritten addi/qfsrv) |
| 2026-10-21T02:17:01Z | func_002D81A0 | 252 | skipped | 0 | 0.0 | no | cvt.w.s (skip rule) |
| 2026-10-21T02:19:05Z | func_00154DA0 | 244 | non-matching | 4 | 69.7 | no | model packet builder (0x154xxx); NM -> src/cod/00154da0.c (58, self kept in t2 vs a0; needs sn as for the dli GIF constant) |
| 2026-10-21T03:06:14Z | func_00192588 | 280 | non-matching | 6 | 2762.7 | no | object (cOmBase struck switch) |
| 2026-10-21T03:17:12Z | func_00304F80 | 456 | skipped | 0 | 0.0 | no | effect node (0x304xxx); vu0.h has no vmulx scale/copy macro (gap) |
| 2026-10-21T03:17:47Z | func_00305E88 | 204 | matched | 1 | 7.6 | no | effect starter (0x305xxx, cEffectParam) |
| 2026-10-21T03:19:22Z | cOmBase_setMeshAlphaFromLayer | 92 | non-matching | 2 | 35.6 | no | object (cOmBase mesh layer); NM -> src/cod/001b7220.c (only the short-loop pad nop differs) |
| 2026-10-21T03:19:30Z | func_0039EDB8 | 236 | skipped | 0 | 0.0 | no | HAND MMI (skip rule) |
| 2026-10-21T03:49:46Z | func_00279D88 | 228 | matched | 5 | 1572.4 | no | enemy setup (0x279xxx, cEm00) |
BATCH 129 (subsystems GS packet 0x299xxx, enemy 0x276xxx-0x279xxx, object 0x192xxx/0x1B7xxx, effect node 0x3033A8-0x305FFF and leftovers): 3 matched (func_002998A0 GS packet entry, func_00305E88 one-shot effect starter, func_00279D88 enemy 0x23F setup), 6 NM (func_00276DC8 10 diffs, func_002DAF68 sqrt template, func_0012A578, func_00154DA0, func_00192588 7 diffs (store order in the random-switch arm), cOmBase_setMeshAlphaFromLayer 1 nop (short-loop pad)), skipped: 4 splitter artifacts, 2 cvt.w.s, the 8 _rix/_ri0 HAND MMI routines plus func_0039EDB8 (HAND MMI), func_002DB008 (sqrt blocker), func_00304F80 (needs a vmulx scale macro vu0.h lacks). Held for the checkpoint, matching in build/scratch/003033a8_ckpt.c: func_003033A8, func_003034A8, func_00304830, func_00304940, func_00304A48 (they need VU0_SQC2_VF0_MEM in vu0.h and the two-argument func_002B6350; their timing rows are finished when they are registered). nm_handoff: func_0033D3D0 registered; reseed (anchor func_00279D88) main ELF and r207 match retail; nm_prune: 0 stale. Learned: a 32-bit flags word read into a `long` local and tested as `((flags >> n) & 1) == 1` gives retail's lwu/dsra/andi with no truncation; `!= 0` adds dsll32/dsra32. Retail places an early `return 0` inline when the source is `if (ok) { ...; return 1; } return 0;`. A chained `vital = vitalMax = 1` stores the high offset first. One work vector array can hold a copied matrix and then its rows as vectors; retail's frame for func_00304A48 is laid out that way.
| 2026-10-21T04:09:33Z | func_001EFED0 | 296 | non-matching | 4 | 41.0 | no | scenario hit set (0x1EFxxx); NM -> src/cod/001efed0.c (17, pos/unit-array s-reg swap) |
| 2026-10-21T04:11:43Z | func_002D8070 | 300 | skipped | 0 | 0.0 | no | cvt.w.s (skip rule) |
| 2026-10-21T04:13:10Z | func_0026EB20 | 320 | non-matching | 5 | 62.4 | no | enemy ground pitch (0x26Exxx, cEm00); NM -> src/cod/0026eb20.c (s-reg reuse for &back) |
| 2026-10-21T04:15:01Z | func_00283AA8 | 320 | non-matching | 4 | 72.1 | no | enemy link push (0x283xxx, cEmLinked); NM -> src/cod/00283aa8.c (&f.v kept in s0; retail rebuilds it from sp) |
| 2026-10-21T04:28:26Z | func_001EBA20 | 340 | non-matching | 6 | 805.4 | no | motion entry table (0x1EBxxx); NM -> src/cod/001eba20.c (4 regions: &pos built early, delay slots) |
BATCH 130 (subsystems effect node 0x2F6xxx, enemy 0x26Exxx/0x283xxx, scenario 0x1EBxxx-0x1EFxxx): 0 matched directly, 4 NM (func_001EFED0 17 diffs (pos and unit-array s-regs swapped), func_0026EB20 (&back kept in s0/s1), func_00283AA8 (&f.v kept in s0; cOmBase_childAt gives retail's li/slt and the dead child-count store), func_001EBA20 4 regions (&pos built at the loop top)), 1 skipped (func_002D8070 cvt.w.s). Held for the checkpoint: func_002F6CF8 at 9 diffs with the proposed VU0_SQC2_VF0_MEM/VU0_SQC2_MEM (retail does not hoist the seed load above the range stores); func_0017F6C0 and func_0017F828 need memory-operand LQC2/SQC2 copies. nm_handoff: __deregister_frame_info registered; reseed (anchor __deregister_frame_info) main ELF and r207 match retail; nm_prune: 0 stale. Learned: the proposed VU0_SQC2_VF0_MEM must not clobber "memory": retail tests a byte it just stored after the $vf0 store without reloading it. Recurring blocker: retail rebuilds a stack address (addiu reg, sp, N) at each use where ours keeps it in a saved register (00276DC8, 0026EB20, 00283AA8, 001EBA20); in 001EBA20 the memory-operand $vf0 store removes one such use.
| 2026-10-21T14:19:29Z | cOmSub_setVibration | 60 | non-matching | 5 | 144.3 | no | object/cOmSub (0x1C3F38-0x1C7D8C): set vibration; NM -> drafts/cod/001c7d50.c (12, flag RMW kept ahead of the int->float conversions) |
| 2026-10-21T14:22:25Z | cOmBase_calcParabolaVector | 412 | non-matching | 3 | 171.5 | yes | object/cOmBase (0x1B7xxx): parabola launch vector; NM -> drafts/cod/001b7c48.c (97, sqrt.s template ordering + sp-relative work vectors) |
| 2026-10-21T14:23:40Z | func_001D4980 | 96 | matched | 1 | 70.6 | no | blackjack (0x1D0EA8-0x1D4DF0): five-card check for hands A and B (func_001D4980 + func_001D49B0, 48 B each); matched -> src/cod/001d4980.c |
| 2026-10-21T14:26:39Z | func_001C8930 | 380 | non-matching | 5 | 169.5 | yes | object/thrown piece (0x1C8xxx): fly along velocity, spin child, die on timer; NM -> drafts/cod/001c8930.c (2, work pointer a0 vs v1; closer candidate) |
| 2026-10-21T14:28:21Z | func_001AAB10 | 384 | matched | 3 | 89.4 | no | object/breakable (0x1AAxxx): break: damage+collision off, scatter pieces, effect; matched -> src/cod/001aab10.c |
| 2026-10-21T14:30:39Z | func_001B1C78 | 388 | matched | 5 | 134.1 | no | object/gimmick (0x1B1xxx): per-mode handler + solid/wall/floor checks; matched -> src/cod/001b1c78.c (EmPhaseTable dispatch, long temp per flag test) |
| 2026-10-21T14:33:30Z | func_001C20D8 | 392 | non-matching | 6 | 168.5 | no | enemy sight check (0x1C2xxx, cEm00): player in range + line check; NM -> drafts/cod/001c20d8.c (43; needs memory-operand VU0_SQC2_MEM, proposed in pending_headers) |
| 2026-10-21T14:36:31Z | func_001A7F58 | 400 | matched | 3 | 164.7 | no | enemy spawner (0x1A7xxx): set queued room entries at the spawner; corrected cEmSetParam_updateSetDataAppPattern signature (self, no, pattern), still matches |
| 2026-10-21T14:38:43Z | func_00192700 | 428 | non-matching | 3 | 128.4 | no | breakable fade-out object (0x192xxx): NM -> drafts/cod/00192700.c (11; as=sn; short-loop nop pad missing on a multi-block child loop, empty loop body) |
| 2026-10-21T14:42:23Z | func_001A4650 | 420 | non-matching | 6 | 216.9 | no | cOm4f door prompt (0x1A4xxx): NM -> drafts/cod/001a4650.c (4 sched words; &d hoisted in retail) |
| 2026-10-21T14:44:53Z | func_001CE6C8 | 424 | non-matching | 6 | 143.3 | no | enemy sink/fade death (0x1CExxx): NM -> drafts/cod/001ce6c8.c (8 with VU0_SQC2_MEM; regalloc + 1 store order) |
| 2026-10-21T14:48:04Z | func_001BE498 | 676 | non-matching | 3 | 157.4 | no | enemy piece throw (0x1BExxx): NM -> drafts/cod/001be498.c (177; bool-byte child check not reproducible in C inline); fixed fRand0_1 definition to float (still matches) |
| 2026-10-21T15:12:36Z | func_0035FFB0 | 40 | skipped | 3 | 43.6 | no | CRI pool release (0x35Fxxx): skipped, CRI range closed again by maintainer; scratch only, nothing in tree |
| 2026-10-21T15:13:47Z | func_00273C38 | 236 | matched | 2 | 57.0 | no | enemy eye line check (0x273xxx): nested range test keeps both compares |
| 2026-10-21T15:15:18Z | func_00275888 | 240 | non-matching | 3 | 91.0 | no | enemy forward line check (0x275xxx): NM -> drafts/cod/00275888.c (62; &eye held from prologue in retail) |
| 2026-10-21T15:15:24Z | func_0026A838 | 256 | skipped | 0 | 6.6 | no | enemy throw release (0x26Axxx): skipped, raw cop1 word 'c1 0x4' after the 0x618 load has no C form |
| 2026-10-21T15:16:09Z | func_0026B4E8 | 280 | matched | 2 | 45.0 | no | enemy weapon throw (0x26Bxxx): named from/to locals order the pos load before Getplayer |
| 2026-10-21T15:16:42Z | func_0026BDD0 | 284 | matched | 2 | 32.3 | no | enemy weapon drop (0x26Bxxx): frame struct keeps cOmBase_childAt's count store |
| 2026-10-21T15:17:34Z | func_0026F328 | 332 | non-matching | 3 | 52.5 | no | enemy sees-player flag (0x26Fxxx): NM -> drafts/cod/0026f328.c (71; s1/s2 swap only, permuter candidate) |
| 2026-10-21T15:19:05Z | func_0026EF60 | 380 | non-matching | 6 | 90.7 | no | enemy camera-view activity check (0x26Exxx): NM -> drafts/cod/0026ef60.c (1 word, neg operand; permuter candidate) |
| 2026-10-21T15:19:09Z | func_00274D18 | 380 | skipped | 0 | 4.2 | no | enemy rotate toward player (0x274xxx): raw cop1 word c1 0xD0344 (sqrt), not expressible in C |
| 2026-10-21T15:20:50Z | func_00276478 | 412 | non-matching | 2 | 101.1 | no | screen-ghost enemy see-through (0x276xxx): NM -> drafts/cod/00276478.c (19; xori/dsrl/unsigned-mask types) |
| 2026-10-21T15:21:31Z | BATCH | - | batch | - | reseed 479.0; score 37.0 | - | BATCH 131 (object/enemy spawner 0x1A7xxx-0x1D4xxx, weapon 0x1C2xxx-0x1CExxx): 5 matched (func_001D4980, func_001D49B0, func_001AAB10, func_001B1C78, func_001A7F58 enemy spawner), 8 NM (cOmSub_setVibration draft retired as already matched, calcParabolaVector, func_001C8930, func_001C20D8 43 (memory-operand sqc2), func_00192700 11 (as=sn; short-loop nop), func_001A4650 4 scheduling words, func_001CE6C8 8 (with VU0_SQC2_MEM), func_001BE498 177 (bool-byte child check)), 1 skipped (func_0035FFB0, CRI range). Signature corrections that still match: cEmSetParam_updateSetDataAppPattern(cEmSetParam*, unsigned int, unsigned char); fRand0_1 returns func_0030F518(). nm_handoff: func_0010CD38, func_001B7568, func_00374210, func_003BBEC0 registered; reseed (anchor func_001AAB10) elf=OK overlay=OK; nm_prune: 1 stale. session_check (container): carve_allowlist repaired with --fix; compile_units_tracked waits on the maintainer committing the 4 handoff TUs; section_owner lists the batch-132 TUs awaiting registration. |
| 2026-10-21T15:22:31Z | func_003BA8C0 | 64 | matched | 1 | 17.3 | no | CRI-adjacent lib setter (0x3BA8C0, cygnus): pair setter next to its getters in 003ba830.c |
| 2026-10-21T15:22:59Z | func_0037CA98 | 68 | matched | 2 | 19.9 | no | sequence link ageing (0x37CA98): matched with SeqLink.age (unsigned) pending in seqNode.h; held as build/scratch/0037ca98_ckpt.c for checkpoint 140 |
| 2026-10-21T15:23:41Z | capVu0Sin | 196 | skipped | 0 | 8.8 | no | handwritten VU0 macro-mode trig (0x1F7EF0-0x1F8140): qmtc2/vsqrt, not C |
| 2026-10-21T15:23:41Z | capVu0Cos | 196 | skipped | 0 | 8.8 | no | handwritten VU0 macro-mode trig (0x1F7EF0-0x1F8140): qmtc2/vsqrt, not C |
| 2026-10-21T15:23:41Z | func_001F8080 | 196 | skipped | 0 | 8.7 | no | handwritten VU0 macro-mode trig (0x1F7EF0-0x1F8140): qmtc2/vsqrt, not C |
| 2026-10-21T15:23:41Z | _rix_101 | 220 | skipped | 0 | 8.7 | no | HAND MMI (0x39F830-0x39FAD0): handwritten, not C |
| 2026-10-21T15:23:41Z | _ri0_101 | 220 | skipped | 0 | 8.6 | no | HAND MMI (0x39F830-0x39FAD0): handwritten, not C |
| 2026-10-21T15:23:41Z | _rix_110 | 220 | skipped | 0 | 8.6 | no | HAND MMI (0x39F830-0x39FAD0): handwritten, not C |
| 2026-10-21T15:23:41Z | func_0030ABD8 | 96 | skipped | 0 | 0.0 | no | VIF/VU reset (0x30ABD8): cfc2/ctc2 vi28 + sync.p, no macro |
| 2026-10-21T15:24:51Z | func_001C2408 | 136 | non-matching | 2 | 40.1 | no | gold pickup payout (0x1C2408): NM -> drafts/cod/001c2408.c (2; v0/v1 for the global's hi after the lqc2/sqc2 copy) |
| 2026-10-21T15:25:09Z | func_00395058 | 100 | skipped | 0 | 0.0 | no | handwritten VU/COP0 (cfc2/ctc2, bc0f or VU0 macro trig): not C |
| 2026-10-21T15:25:09Z | func_002D4DA0 | 100 | skipped | 0 | 0.0 | no | handwritten VU/COP0 (cfc2/ctc2, bc0f or VU0 macro trig): not C |
| 2026-10-21T15:25:09Z | func_0030A5D0 | 100 | skipped | 0 | 0.0 | no | handwritten VU/COP0 (cfc2/ctc2, bc0f or VU0 macro trig): not C |
| 2026-10-21T15:25:48Z | func_0014E818 | 168 | non-matching | 2 | 38.5 | no | turn toward point with clamp (0x14E818): NM -> drafts/cod/0014e818.c (4; v0/v1 swap pos vs work address) |
| 2026-10-21T15:27:13Z | func_002951B0 | 284 | non-matching | 3 | 50.7 | no | room-file enemy entry -> EntryEm (0x2951B0): NM -> drafts/cod/002951b0.c (43; conversion schedule) |
| 2026-10-21T15:28:09Z | func_001569A0 | 288 | non-matching | 2 | 36.5 | no | triangle in-plane edge direction (0x1569A0): NM -> drafts/cod/001569a0.c (9; &f.n address scheduled late) |
| 2026-10-21T15:28:38Z | func_003B7E80 | 348 | skipped | 0 | 0.0 | no | kernel exception return (0x3B7E80): eret/mtc0 handwritten |
| 2026-10-21T15:29:39Z | func_00249770 | 312 | matched | 1 | 61.0 | no | arena orbit move (0x249770): matches with the proposed non-volatile VU0_ZERO_VSUB_XYZ_TO; held as build/scratch/00249770_ckpt.c for checkpoint 140 |
| 2026-10-21T15:29:44Z | func_002F5588 | 312 | skipped | 0 | 0.0 | no | effect midpoint between two parts (0x2F5588): byte-masked bool child check (andi 0xFF), same blocker as func_001BE498 |
| 2026-10-21T15:30:44Z | func_002BCF28 | 328 | non-matching | 2 | 27.3 | no | two-segment matrix test (0x2BCF28): NM -> drafts/cod/002bcf28.c (9; early address hoist + arg order) |
| 2026-10-21T15:41:33Z | BATCH | - | batch | - | reseed 568.0; score 37.0 | - | BATCH 132 (enemy core 0x26Bxxx-0x276xxx, plus leftovers 0x14E-0x3BA): 4 matched (func_00273C38 enemy line-of-sight, func_0026B4E8 carrier throws its weapon, func_0026BDD0 weapon drop at the hand child, func_003BA8C0 pair setter in 003ba830.c), 2 matched and held for checkpoint 140 (func_0037CA98 needs SeqLink.age in seqNode.h; func_00249770 needs the proposed non-volatile VU0_ZERO_VSUB_XYZ_TO), 9 NM (func_00275888 62, func_0026F328 71 (s1/s2 swap), func_0026EF60 1 word (neg operand), func_00276478 19 (xori/dsrl/unsigned mask), func_001C2408 2 (v0/v1), func_0014E818 4 (v0/v1), func_002951B0 43 (conversion schedule), func_001569A0 9, func_002BCF28 9), skipped: func_0026A838 and func_00274D18 (raw cop1 words), 12 handwritten VU/MMI/kernel routines, func_002F5588 (byte-bool child check), func_0035FFB0 (CRI range). nm_handoff: cSnd_GetStageBgmReq registered (with its cSnd.h change); reseed (anchor func_0026BDD0) elf=OK overlay=OK; nm_prune: 0 stale. Learned: retail's subtract-into-memory sequence behaves as a non-volatile asm, so independent address arithmetic is hoisted above it; with that form func_00249770 matches exactly. Several near misses (1569A0, 2BCF28, 14E818) share the symptom but need more than that one macro. |
| 2026-10-21T15:43:05Z | func_0024BDA0 | 380 | non-matching | 3 | 37.7 | no | enemy jump-point start (0x24BDA0): NM -> drafts/cod/0024bda0.c (89; folded range compare, abs neg operand) |
| 2026-10-21T15:44:06Z | func_0026E7D8 | 432 | non-matching | 2 | 31.0 | no | retreating enemy goto (0x26E7D8): NM -> drafts/cod/0026e7d8.c (79; s2/s3 swap and set4 store form) |
| 2026-10-21T15:44:44Z | func_001EDC28 | 356 | matched | 1 | 7.6 | no | CustomID panel item slide steps (0x1EDC28): CustomIDColor bitfield colours |
| 2026-10-21T15:45:02Z | func_00107C68 | 376 | skipped | 0 | 0.0 | no | child-matrix point transform loop (0x107C68): byte-masked bool child check (andi 0xFF), func_001BE498 blocker |
| 2026-10-21T15:45:08Z | func_001EBC58 | 424 | skipped | 0 | 0.0 | no | scenario trip check (0x1EBC58): flag bit read as lwu/dsra (long temporary), banned |
| 2026-10-21T15:46:23Z | func_001299F0 | 428 | non-matching | 2 | 50.6 | no | grab placement facing (0x1299F0): NM -> drafts/cod/001299f0.c (100; &work hoist needs an extra s-reg) |
| 2026-10-21T15:48:01Z | func_0012A3C0 | 436 | non-matching | 3 | 57.5 | no | put out fire in box ahead (0x12A3C0): NM -> drafts/cod/0012a3c0.c (101; 0.5 constant not hoisted). Also gave func_001B8720 a prototype in 0012a2e0.c (was implicit), still matches |
| 2026-10-21T15:48:11Z | func_001EC388 | 436 | skipped | 0 | 0.0 | no | scenario depth sort of 5 slots (0x1EC388): unrolled sqc2 loops with short-loop nop pads (known blocker) |
| 2026-10-21T15:48:17Z | func_0028A2E8 | 436 | skipped | 0 | 0.0 | no | enemy fire damage tick (0x28A2E8): flag test via lwu (long temporary idiom), banned |
| 2026-10-21T15:48:27Z | func_002D7E50 | 436 | skipped | 0 | 0.0 | no | light matrix setup (0x2D7E50): inline VU0 clamp block (qmtc2, vmaxx/vminiw broadcast) with no macros |
| 2026-10-21T15:49:26Z | func_001CD800 | 448 | matched | 2 | 31.3 | no | weapon drop and break (0x1CD800): matches with proposed VU0_SQC2_MEM and cOmWeapon life/fallVel; held as build/scratch/001cd800_ckpt.c for checkpoint 140 |
| 2026-10-21T15:52:11Z | func_002B2F80 | 36 | matched | 1 | 9.4 | no | cutscene command 0x2B28 (0xD300 handler) in existing src/cod/002b28.c; func_002B45E0 signature gains its unread id parameter; 0024a768.c gets the missing prototype |
| 2026-10-21T15:52:39Z | SetEv61HumanAlive | 60 | matched | 1 | 6.6 | no | event BGM 0x298xxx -> src/cod/00298d78.c |
| 2026-10-21T15:53:50Z | displayOmLayer | 156 | non-matching | 3 | 48.5 | no | om layer display 0x2DB478 -> drafts/cod/002db478.c (byte bool range + list reload) |
| 2026-10-21T15:55:57Z | cE3_menu | 256 | matched | 4 | 82.9 | no | E3 demo menu (cE3.c): matches with cE3.cursor as signed char; held as build/scratch/cE3_menu_ckpt.c for checkpoint 140 |
| 2026-10-21T15:57:08Z | func_002D8C60 | 376 | skipped | 2 | 28.2 | no | world light preset fade 0x2D8C60: cvt.w.s (retail float->int without trunc.w.s) |
| 2026-10-21T15:57:22Z | func_003781F8 | 416 | skipped | 0 | 0.0 | no | sound bank curve lookup 0x3781F8: cvt.w.s |
| 2026-10-21T15:57:33Z | _sceCd_cd_read_intr | 192 | skipped | 0 | 0.0 | no | libcdvd read interrupt 0x398578: odd entry (sp += 0x30, entered at +8) |
| 2026-10-21T15:58:30Z | func_003978C8 | 276 | non-matching | 1 | 14.0 | no | libpad command DMA 0x3978C8 -> drafts/cod/003978c8.c (0x100-byte local area unknown) |
| 2026-10-21T16:01:27Z | func_001682C8 | 528 | matched | 4 | 140.1 | no | ID menu three-way selection 0x1682C8 -> src/cod/001682c8.c (--as sn for the 64-bit pad masks) |
| 2026-10-21T17:04:20Z | BATCH | - | batch | - | reseed 605.0; score 35.0 | - | BATCH 133 (subsystems: custom ID panel 0x1EDxxx, cutscene command 0x2B28, event BGM 0x298xxx, E3 menu, ID menu 0x168xxx, weapon drop, libpad/libcdvd): 4 matched and registered (func_001EDC28, func_002B2F80 into the existing src/cod/002b28.c, SetEv61HumanAlive, func_001682C8); 2 held for checkpoint 140 (func_001CD800 needs VU0_SQC2_MEM and cOmWeapon life/fallVel; cE3_menu needs cE3.cursor as signed char); NM drafts: func_0024BDA0, func_0026E7D8, func_001299F0, func_0012A3C0, displayOmLayer, func_003978C8; 8 skipped (00107C68, 001EBC58, 001EC388, 0028A2E8, 002D7E50, func_002D8C60 and func_003781F8 cvt.w.s, _sceCd_cd_read_intr odd entry). Signature fix: func_002B45E0 gains its unread id parameter (its only caller passes it); 0024a768.c gets the func_002B2F80 prototype. Handoffs: 2 received, 2 registered (F32toF16, func_0026EB20 with its cEm00.h change), 0 rejected. Per-file settings (new units): src/cod/001682c8.c --as sn; src/cod/001edc28.c, src/cod/00298d78.c sn defaults. First reseed failed (rc=1): SetEv61HumanAlive was still an INCLUDE_ASM line in src/cod/000000.c (sa_register moves the carve but doesn't edit 000000.c); removed the line, second reseed rc=0 78s, elf OK, overlay OK. nm_prune bug fixed: it retired drafts whose carve TU is a registered unit that still holds the function as INCLUDE_ASM (000000.c); restored drafts/cod/002db478.c and drafts/cod/001c7d50.c from progress/retired_nm/. session_check: 18 pass, 7 skipped, 1 fail (dual_compiler_regress: 'Argument list too long', fails on upstream too). The batch-132 background session_check had died after metadata (background jobs end with the shell call); reran in the foreground this time. |
| 2026-10-21T17:08:28Z | cEmSetParam_getSetDataPos | 188 | non-matching | 6 | 112.0 | no | enemy placement 0x295510 -> drafts/cod/00295510.c (stack vector stores scheduled late in retail) |
| 2026-10-21T17:09:16Z | cScenario_beginCasinoBattle | 212 | skipped | 0 | 0.0 | no | cScenario casino battle 0x2C4940: needs cScenario fields 0x00 pos/0x10 rotY/0x16 and the player vtable entries 0x80/0x88, which cGameObj.h and cEm00.h name differently |
| 2026-10-21T17:11:21Z | func_002F6CF8 | 296 | non-matching | 5 | 79.0 | no | effect node camera jitter 0x2F6CF8 -> drafts/cod/002f6cf8.c (11 words: 0x220 load scheduling) |
| 2026-10-21T17:13:47Z | func_00302790 | 344 | matched | 5 | 98.8 | no | cDrawNode constructor 0x302790 -> src/cod/00302790.c (sn defaults; cNode base, embedded draw settings at 0x1A0) |
| 2026-10-21T17:15:35Z | func_003960D0 | 136 | skipped | 6 | 51.4 | no | libgraph half offset (context 2) 0x3960D0: clone of sceGsSetHalfOffset, same 22-26 word ee-gcc scheduling wall already logged by the NM closer |
| 2026-10-21T17:15:40Z | func_003A54D8 | 416 | skipped | 0 | 0.0 | no | strchr 0x3A54D8: hand-written MMI (pcpyld/psubb/pnor) |
| 2026-10-21T17:19:09Z | func_0017F6C0 | 356 | non-matching | 5 | 126.9 | no | map object slide 0x17F6C0 -> drafts/cod/0017f6c0.c (9 words: sp+0x30 work vector address computed after the VU0 block) |
| 2026-10-21T17:21:51Z | func_002F4290 | 344 | matched | 2 | 97.2 | no | slot model and effect setup (0x2F4290): matches with the cNodeDrawState type and init shared with src/cod/00302790.c; held as build/scratch/002f4290_ckpt.c for checkpoint 140 (the type goes in a header first) |
| 2026-10-21T17:22:00Z | func_0017F828 | 356 | skipped | 0 | 0.3 | no | map object slide twin 0x17F828: same shape as func_0017F6C0 (draft), same VU0 address-placement wall |
| 2026-10-21T17:22:06Z | cSnd_CalcListenerPanDist | 444 | skipped | 0 | 0.3 | no | listener pan/distance 0x2CF040: cvt.w.s |
| 2026-10-21T17:22:10Z | cWorldLight_loadPreset | 588 | skipped | 0 | 0.3 | no | world light preset 0x2D8A20: unaligned lwl/lwr struct copies and an lq/sq compaction loop; needs the light preset struct layout first |
| 2026-10-21T17:34:42Z | BATCH | - | batch | - | reseed 48.0; score 98.8 | - | BATCH 134 (subsystems: effect nodes 0x2F4xxx/0x302xxx, map object slide 0x17Fxxx, libgraph, sound listener, world light): 1 matched and registered (func_00302790, cDrawNode constructor, new src/cod/00302790.c, sn defaults); 1 held for checkpoint 140 (func_002F4290 needs cNodeDrawState and its init moved to a header; held as build/scratch/002f4290_ckpt.c); NM drafts: cEmSetParam_getSetDataPos, func_002F6CF8, func_0017F6C0; skipped: cScenario_beginCasinoBattle (header conflicts), func_003960D0 (sceGsSetHalfOffset clone, known scheduling wall), func_003A54D8 (hand-written MMI strchr), func_0017F828 (twin of the 0017F6C0 draft), cSnd_CalcListenerPanDist (cvt.w.s), cWorldLight_loadPreset. Handoffs: 5 received, 2 registered (MtxInitRotQuaternion, func_002A6CA8; removed the duplicated compiler line nm_handoff writes), 3 rejected by nm_handoff (func_001299F0, func_0026F328, func_00275888: header_changes.md format; they need header edits, revisit at checkpoint 140). func_002A6CA8 keeps retail's store of 0 to ctx.mode right before the memset (it is in the memset delay slot in retail). Reseed rc=0 48s, elf OK, overlay OK. nm_prune: nothing stale. session_check: 16 pass, 7 skipped, 3 fail: dual_compiler_regress (Argument list too long, upstream too) and carve_allowlist/compile_units_tracked for the two handoff units, which lacked .gitignore lines; fixed with carve_allowlist.py --fix and both checks rerun clean. |
| 2026-10-21T17:38:21Z | func_002769A8 | 736 | non-matching | 3 | 69.3 | no | held model follows its holder 0x2769A8 -> drafts/cod/002769a8.c (frame slot sharing between the two blocks and the andi 0xFF child-index bool; parked at attempt 3). Twins 0x27A320, 0x27AE10, 0x283688, 0x284068 have the same shape |
| 2026-10-21T17:38:48Z | func_002A4FD8 | 784 | skipped | 0 | 0.3 | no | VIF/GS packet builder 0x2A4FD8 (two DMA chains with 64-bit GIF tags) |
| 2026-10-21T17:38:49Z | func_00399E40 | 568 | skipped | 0 | 0.3 | no | library work-area init 0x399E40 (ee-gcc, about 60 fields of an unidentified struct, unaligned-base check prints) |
| 2026-10-21T17:39:01Z | func_0014C328 | 628 | skipped | 0 | 0.3 | no | model draw packet setup 0x14C328 (GIF/VIF tags per frame parity, known hard area) |
| 2026-10-21T17:40:22Z | func_00187D88 | 604 | skipped | 0 | 0.4 | no | enemy setup 0x187D88: retail stores a (0.6, 1.5, 0.6, 1) vector at sp+0x00 that nothing reads (the size is built again at sp+0x10); only a dead local or a placeholder array reproduces it |
| 2026-10-21T17:40:22Z | func_002E25B0 | 592 | skipped | 0 | 0.4 | no | effect slot setup 0x2E25B0: vmulx.xyz scale plus a cross-jumped ladder of six error prints; needs the slot type at 0x110 first |
| 2026-10-21T17:40:23Z | cObjSimple_SwingLimb | 592 | skipped | 0 | 0.4 | no | limb swing 0x2B80D0: holder child index tested as a byte-masked bool (andi 0xFF), same wall as func_002769A8 |
| 2026-10-21T17:53:25Z | BATCH | - | batch | - | reseed 40.0; score 0.0 | - | BATCH 135 (subsystems: held models 0x276xxx, packet builders, enemy setup, effect slots): 0 own matches. NM draft: func_002769A8 (held model follows its holder; twins 0x27A320/0x27AE10/0x283688/0x284068 share the shape). Skipped: func_002A4FD8 and func_0014C328 (VIF/GS packet builders), func_00399E40 (library work-area init, unidentified struct), func_00187D88 (dead (0.6,1.5,0.6,1) temp at sp+0x00), func_002E25B0 (needs the slot type), cObjSimple_SwingLimb (andi 0xFF child-index bool). Handoffs: 1 received, 1 registered (func_0027DB20; added its config/symbol_addrs.txt entry, which nm_handoff did not write, and removed the duplicated compiler line). Reseed rc=0 40s, elf OK, overlay OK (twice: before and after the handoff). nm_prune: nothing stale. session_check: 18 pass, 7 skipped, 1 fail (dual_compiler_regress: Argument list too long, fails upstream too). |
| 2026-10-21T17:56:55Z | func_0018F618 | 572 | matched | 5 | 123.2 | no | rocking object hit reaction 0x18F618 -> src/cod/0018f618.c (fp_hazard_rules fdiv; normalize inline cVec_unitOf; store orders follow the scheduler rotation) |
| 2026-10-21T17:57:12Z | func_001A6310 | 572 | matched | 1 | 10.1 | no | rocking object twin 0x1A6310 (fields 0x50 lower, sound 0x96): matches with the same body; held as build/scratch/001a6310_ckpt.c for checkpoint 140 because cVec_unitOf must move to a header first |
| 2026-10-21T17:57:50Z | func_002890A0 | 644 | skipped | 0 | 0.3 | no | head tilt toward a child body 0x2890A0 (twin 0x28AE18): five VU0 quadword copies through precomputed sp addresses (the address-hoist wall) plus MtxInverse; revisit with the checkpoint copy macro |
| 2026-10-21T18:25:18Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 136: 1 own registered (func_0018F618 rocker swing, fdiv), 1 held (func_001A6310 twin, needs cVec_unitOf in a header), 1 skip (func_002890A0 VU0 address wall); handoffs 1 received/1 registered (func_00304C48, duplicate compiler line removed, func_00302918 prototype fixed to void*); reseed elf/overlay OK; session_check 18 pass / 1 known fail (dual_compiler_regress) |
| 2026-10-21T18:28:03Z | func_00149C20 | 576 | non-matching | 2 | 128.0 | yes | cModel | retail homes hdr to sp+0 and reloads it for each part-table access; clean C keeps it in $s3 (139 diffs); drafted drafts/cod/00149c20.c |
| 2026-10-21T18:30:50Z | func_00305C20 | 612 | matched | 4 | 163.5 | yes | cAreaFx | zone/effect gate update; VU0 copy through a frame struct, separate counter for the second loop; registered src/cod/00305c20.c |
| 2026-10-21T18:31:53Z | func_001BCD70 | 576 | skipped | 0 | 59.1 | yes | cGameObj | child-body flag reset with cOmBase_childAt at a variable index (andi 0xFF bool, same wall as func_002769A8); skipped |
| 2026-10-21T18:32:02Z | func_001C3540 | 564 | skipped | 0 | 8.8 | yes | cGameObj | twin of func_001BCD70 (cOmBase_childAt at a variable index); skipped |
| 2026-10-21T18:34:43Z | func_00277568 | 572 | matched | 4 | 87.6 | yes | cEm00 | enemy per-frame update with gravity fall; pmf dispatch as in 0024c0f0, unsigned flags view over cEm00.unk1560, ChkHit declared with its real int return; registered src/cod/00277568.c |
| 2026-10-21T18:37:22Z | func_00198D40 | 516 | non-matching | 3 | 154.6 | yes | cOmHitVolume | sized damage-take box with model scale; switch compare tree (==1,<2,==2) and $s0/$s1 swap remain (104 diffs); drafted drafts/cod/00198d40.c |
| 2026-10-21T18:51:00Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 137: 2 own registered (func_00305C20 area zone/effect gate; func_00277568 enemy fall update, ChkHit declared int), 2 NM drafts (func_00149C20 hdr stack slot; func_00198D40 switch tree), 3 skips (func_001BCD70, func_001C3540 childAt variable index; func_002890A0 noted in 136); handoffs 0 new (3 rejected still waiting for header edits); reseed elf/overlay OK; session_check 18 pass / 1 known fail (dual_compiler_regress) |
| 2026-10-21T18:54:19Z | SetEffectPos | 200 | matched | 3 | 112.4 | yes | effect | effect at a position with default params; the param init must be an inline (cVec_zero via VU0_SQC2_VF0_MEM) so &unk20 is shared with the copy; registered src/cod/00306838.c |
| 2026-10-21T18:57:37Z | func_00137F38 | 368 | non-matching | 4 | 193.8 | yes | camera | camera path follow; duplicated easing in case 1 and the no-record branch gets 2 diffs ($v1 vs $v0 for &player->rot); an (f,pos,rot) inline copies sp and regresses to 55; drafted drafts/cod/00137f38.c, permuter candidate |
| 2026-10-21T18:57:55Z | func_00260438 | 536 | skipped | 0 | 12.9 | yes | enemy | enemy spawn at an offset (EntryEm); VU0 vsub into precomputed sp addresses (address-hoist wall); skipped |
| 2026-10-21T19:08:17Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 138: 1 own registered (SetEffectPos, effect param init as an inline), 1 NM draft (func_00137F38 camera path follow, 2 diffs), 1 skip (func_00260438 VU0 address wall); handoffs 0 new; reseed elf/overlay OK; session_check 18 pass / 1 known fail (dual_compiler_regress). Note: running scripts/gen_decomp_queue.py rewrote the untracked progress/decomp_queue.json with an empty queue (the script filters an old unit naming) |
| 2026-10-21T19:09:38Z | func_002A87E8 | 544 | non-matching | 1 | 76.6 | yes | cGameObj | camera-occlusion fade; bit 6 of D_00747A84 is tested with dsrl (needs a long temporary, banned); drafted drafts/cod/002a87e8.c |
| 2026-10-21T19:09:52Z | func_002FCD60 | 552 | skipped | 0 | 10.2 | yes | cNode | node local translation from a parent body; cOmBase_childAt at a variable index with the count slot reused as matrix space; skipped |
| 2026-10-21T19:18:56Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 139: 0 own matches, 1 NM draft (func_002A87E8 camera-occlusion fade, dsrl bit test needs a long temporary), 1 skip (func_002FCD60 childAt at a variable index); handoffs 0 new; reseed elf/overlay OK; session_check 18 pass / 1 known fail (dual_compiler_regress) |
| 2026-10-22T04:44:53Z | Draw_Line2 | 424 | non-matching | 3 | 114.7 | no | draw (0x15Exxx): world-space polyline; NM -> drafts/cod/0015ef10.c (106 vs 103 words: retail rebuilds &v from sp at each call) |
| 2026-10-22T04:44:53Z | Draw_Line_sc | 476 | non-matching | 6 | 114.7 | no | draw (0x15Fxxx): screen-space polyline; the batch-111 handoff (lost in the rebase) matched only with `int ofs = 0x800` (banned constant local); literal form is 3 words off (lui %hi(D_00586B80) placement); NM -> drafts/cod/0015ef10.c |
| 2026-10-22T04:48:39Z | func_00381478 | 1220 | matched | 3 | 50.5 | yes | menu/sound test (0x381xxx): sound test page printer; case -1 falls into case 0/5; src/cod/00381478.c |
| 2026-10-22T04:49:47Z | func_00382898 | 1172 | matched | 2 | 64.6 | yes | menu/sound test (0x382xxx): stream sound test page printer; slot record at 0x318 as a nested struct; src/cod/00382898.c |
| 2026-10-22T04:49:47Z | func_00385A68 | 1072 | skipped | 0 | 0.0 | yes | menu (0x385xxx): g++ C++ with inlined std::string / vector<string> (rep refcount, default-alloc free lists D_003C4030); no C form |
| 2026-10-22T04:49:47Z | func_00385E98 | 1312 | skipped | 0 | 0.0 | yes | menu (0x385xxx): inlined std::string / vector<string>; no C form |
| 2026-10-22T04:49:47Z | func_00386700 | 1604 | skipped | 0 | 0.0 | yes | menu (0x386xxx): inlined std::string / vector<string>; no C form |
| 2026-10-22T04:52:42Z | func_00372CB0 | 1128 | matched | 4 | 157.5 | yes | sound/sequence node (0x372xxx): per-frame fade update for one- and two-track nodes; SETTING as sn on src/cod/00372cb0.c (c.lt.s/bc1fl nop at a label); src/cod/00372cb0.c |
| 2026-10-22T04:53:09Z | func_00378D18 | 1144 | skipped | 0 | 26.8 | yes | sound/sequencer debug page (0x378xxx): retail holds the x position 0x1B in a short local (s2, sll/sra 16 at each later use); only a constant-holding local reproduces it (banned) |
| 2026-10-22T04:54:58Z | cSndSeVoice_Setup | 972 | skipped | 1 | 0.3 | yes | sound/cSnd voice (0x2CDxxx): D_00747A84 bit 6 tested as lw+dsrl; unsigned int, int bitfield and casts give srl, an unsigned long bitfield adds dsra32; the long-temporary form is banned |
| 2026-10-22T04:54:59Z | func_002D0EA0 | 1528 | skipped | 0 | 14.2 | yes | sound/cSnd BGM switch (0x2D0xxx): deferred, nested switch with cross-jumped fade-out arms; revisit |
| 2026-10-22T05:08:53Z | BATCH | - | batch | - | reseed 91.0; score 0.0 | - | BATCH 140 (sound debug pages, sequencer): 3 own registered (func_00381478 sound test page, func_00382898 stream test page, func_00372CB0 sequence node update; per-file setting: 00372cb0.c as sn), 2 NM drafts (Draw_Line2, Draw_Line_sc in drafts/cod/0015ef10.c), func_001A5208 moved to drafts/cod/001a5208.c (matched only through a placeholder buffer), 5 skips (3 STL C++, func_00378D18 constant local, cSndSeVoice_Setup dsrl) and func_002D0EA0 deferred; handoffs 0 new; reseed elf/overlay OK; nm_prune 0 stale; session_check 18 pass / 1 known fail (dual_compiler_regress) |
| 2026-10-22T05:10:06Z | func_001B22D0 | 420 | matched | 1 | 51.7 | no | enemy setup (cOmHitVolume family, 0x1B2xxx): take box, give sphere, work defaults |
| 2026-10-22T05:12:26Z | func_001A3E10 | 452 | matched | 4 | 137.1 | no | enemy setup (cOmHitVolume family, 0x1A3xxx): take cylinder, give sphere, 50 hp, flags2 0x180; tail order needed hp = hpMax = 50 first |
| 2026-10-22T05:14:19Z | func_00192D20 | 472 | matched | 3 | 52.5 | no | enemy setup (cOmHitVolume family, 0x192xxx): redone after the earlier carve was dropped; v[7] with pointers as the siblings, one mtx local |
| 2026-10-22T05:14:23Z | func_0018F218 | 680 | skipped | 0 | 4.3 | no | enemy setup (cOmHitVolume family, 0x18Fxxx): cvt.w.s for the give damage (player stat * 80) |
| 2026-10-22T05:14:31Z | func_00180A10 | 784 | skipped | 0 | 7.3 | no | enemy setup (cOmHitVolume family, 0x180xxx): VU0 vaddx on the offset plus an unaligned 0x60 struct copy into a 12-argument call; needs a vu0.h scalar-add macro |
| 2026-10-22T05:15:03Z | func_00194080 | 1020 | skipped | 0 | 32.3 | no | cOm1f setup (0x194xxx): cOmBase_childAt count stores land in three frame slots overlapping the vectors; only a placeholder frame array reproduces it |
| 2026-10-22T05:16:42Z | func_002ACF30 | 120 | non-matching | 6 | 74.8 | no | cIDManager (0x2ACxxx): give back the last buffer run; 5-insn register difference, draft drafts/cod/002acf30.c |
| 2026-10-22T05:17:26Z | cOl0e_setFake | 224 | skipped | 2 | 43.2 | no | cOl0e (0x173xxx): flags0 bit 1 tested as lwu+dsra (long-temporary pattern, banned); tail also schedules the flags2 store between the state bytes |
| 2026-10-22T05:18:59Z | cFont_setTextureAddr | 328 | non-matching | 5 | 71.3 | no | cFont texture slots (0x2A4xxx): slot address register choice differs (21 insns from a one-word shift); draft drafts/cod/002a4cb0.c |
| 2026-10-22T05:19:54Z | func_002FBB78 | 328 | matched | 2 | 15.9 | no | effect slots (0x2FBxxx): vtable entry 6 on live slots in or out of a group; slot pointer from the index inside the loop |
| 2026-10-22T05:21:08Z | func_00257E90 | 552 | matched | 1 | 61.1 | no | cEm00 step machines (0x257xxx): wait/end motion steps |
| 2026-10-22T05:21:14Z | func_001E33B0 | 640 | skipped | 0 | 5.8 | no | debug menu (0x1E3xxx): flag word bit 4 tested as lwu+dsra (long-temporary pattern) |
| 2026-10-22T05:22:43Z | func_0015E2E0 | 560 | matched | 2 | 88.8 | no | TIM2 texture load (0x15Exxx): first picture, TEX0 bitfields; SETTING as sn (64-bit constant expansion) |
| 2026-10-22T05:23:19Z | func_0015E0A0 | 576 | matched | 2 | 36.9 | no | TIM2 texture load (0x15Exxx): first picture at 0x10/0x80 by format byte; shares src/cod/0015e0a0.c (as sn) with func_0015E2E0 |
| 2026-10-22T05:23:26Z | func_0015DDF8 | 668 | skipped | 0 | 6.0 | no | TIM2 texture DMA packet (0x15Dxxx): quadword lq/sq packet copies with GIF tag constants; needs a u_long128 packet type |
| 2026-10-22T05:23:30Z | func_0015DB30 | 692 | skipped | 0 | 0.0 | no | TIM2 texture DMA packet (0x15Dxxx): same quadword packet build as func_0015DDF8 |
| 2026-10-22T05:25:38Z | func_0013D7B0 | 740 | non-matching | 3 | 127.3 | no | continue prompt (0x13Dxxx): matches with as sn but only through an (unsigned short) cast on cIDBaseEnt.jit[4]; held for the header merge as build/scratch/0013d7b0_ckpt.c |
| 2026-10-22T05:25:43Z | func_002E9808 | 740 | skipped | 0 | 5.8 | no | GS packet build (0x2E9xxx): dozens of 64-bit register constants scheduled across sd stores |
| 2026-10-22T05:25:49Z | func_0029F7D8 | 760 | skipped | 0 | 5.9 | no | GS register push list (0x29Fxxx): packed 64-bit register values with hoisted %hi bases |
| 2026-10-22T05:25:58Z | func_00208858 | 904 | skipped | 0 | 5.1 | no | enemy release (0x208xxx): short-loop pad nops in the slot-clear loop |
| 2026-10-22T05:26:06Z | func_00145460 | 944 | skipped | 0 | 7.5 | no | title/menu entries (0x145xxx): deferred, four-state machine over 0x14-byte entry records; revisit |
| 2026-10-22T06:13:07Z | BATCH | - | batch | - | reseed 558.0; score 0.0 | - | BATCH 141 (enemy setups, effect slots, enemy AI, TIM2 upload, path camera): 7 own registered (func_001B22D0, func_001A3E10, func_00192D20 enemy hit-volume setups; func_002FBB78 effect slot broadcast; func_00257E90 cEm00 wait-step; func_0015E0A0 and func_0015E2E0 TIM2 texture/CLUT upload in src/cod/0015e0a0.c; per-file setting: 0015e0a0.c as sn), 2 NM drafts (002acf30 cIDManager give-back, 002a4cb0 cFont_setTextureAddr), skips logged, func_00145460 deferred; handoffs 1 (func_00137F38 path camera; adds VU0_LQC2_SQC2_MEM to vu0.h and PathRec/PathHost fields to pathRec.h, 188 dependents unchanged); reseed elf/overlay OK; nm_prune retired 2 stale drafts (00257e90, 002fbb78); 0013d7b0 held for checkpoint |
| 2026-10-22T06:13:38Z | func_00171DE8 | 1004 | skipped | 0 | 6.9 | no | enemy setup (cOmHitVolume family, 0x171xxx): VU0 vaddx and cOmBase_childAt frame-slot stores |
| 2026-10-22T06:15:36Z | func_001B4528 | 948 | skipped | 1 | 97.4 | no | grow/shrink object (0x1B4xxx): cOmBase_childAt count store at 0(sp) only survives with a placeholder array; scalar local is purged |
| 2026-10-22T06:16:10Z | func_002E0F18 | 960 | skipped | 0 | 25.2 | no | debug text renderer (0x2E0xxx): needs one shared type for D_0061B280 (font state), which already has two conflicting local types; deferred to header merge |
| 2026-10-22T06:19:38Z | Slot2_Execute | 984 | non-matching | 3 | 208.0 | no | casino Slot2 task (0x1E4xxx): draft drafts/cod/001e4970.c; lwu endFlag read, second fade-wait loop shape, saved-register allocation |
| 2026-10-22T06:22:11Z | Slot2_JudgeLines | 1040 | matched | 4 | 152.4 | no | casino Slot2 line judge (0x1E5xxx): prize table copied as a typed struct from D_0042B9D8; one line-check macro whose cases each set state/step/phase and return |
| 2026-10-22T06:23:19Z | Slot2_PayoutJackpotLine | 548 | matched | 2 | 56.7 | no | casino Slot2 jackpot payout (0x1E6xxx): sibling of Slot2_payoutLine1/2; jackpot line read as an if/else chain |
| 2026-10-22T06:25:30Z | func_001EB7B8 | 576 | non-matching | 4 | 122.5 | no | casino scene camera depth ease (0x1EBxxx): draft drafts/cod/001eb7b8.c; prologue placement of &pos only |
| 2026-10-22T06:25:58Z | Slot2_StopReels | 1136 | skipped | 0 | 7.8 | no | casino Slot2 reel stop (0x1E5xxx): cvt.w.s and lwu+dsra bit tests (known blockers) |
| 2026-10-22T06:29:33Z | func_002000F8 | 972 | non-matching | 1 | 206.6 | no | cDoor room jump step (0x200xxx): draft drafts/cod/002000f8.c; retail anchors world fields on &flags5D8 (D_00747A78), only reproduced upstream with raw pointer arithmetic |
| 2026-10-22T06:32:48Z | func_001F5650 | 1028 | matched | 5 | 190.2 | no | casino-ui |
| 2026-10-22T06:33:02Z | func_001EC540 | 0 | skipped | 0 | 10.0 | no | casino |
| 2026-10-22T06:33:02Z | func_001EB030 | 0 | skipped | 0 | 4.7 | no | casino |
| 2026-10-22T06:33:07Z | func_001EA1F8 | 0 | skipped | 0 | 4.7 | no | casino |
| 2026-10-22T06:33:52Z | func_00217560 | 0 | skipped | 0 | 45.0 | no | enemy |
| 2026-10-22T06:36:49Z | func_00349C28 | 184 | non-matching | 4 | 0.0 | no | cri-mwsfd |
| 2026-10-22T06:38:51Z | func_00149220 | 160 | skipped | 3 | 0.0 | no | model |
| 2026-10-22T06:39:13Z | strncat | 0 | skipped | 0 | 0.0 | no | libc-mmi |
| 2026-10-22T06:39:13Z | func_003A53A8 | 0 | skipped | 0 | 0.0 | no | libc-mmi |
| 2026-10-22T06:39:13Z | func_003A5678 | 0 | skipped | 0 | 0.0 | no | libc-mmi |
| 2026-10-22T06:39:13Z | func_003A57C4 | 0 | skipped | 0 | 0.1 | no | libc-mmi |
| 2026-10-22T06:43:43Z | func_001A4010 | 516 | non-matching | 6 | 0.0 | no | cOm49 |
| 2026-10-22T06:43:54Z | func_001CFE88 | 520 | skipped | 0 | 0.0 | no | weapon |
| 2026-10-22T06:43:59Z | func_0015E8B8 | 528 | skipped | 0 | 0.0 | no | gs-packet |
| 2026-10-22T06:44:06Z | func_00275668 | 544 | skipped | 0 | 0.0 | no | enemy |
| 2026-10-22T06:47:22Z | func_0028E580 | 580 | non-matching | 7 | 0.0 | no | npc-action |
| 2026-10-22T06:49:50Z | func_00129EB0 | 600 | non-matching | 4 | 0.0 | no | knock |
| 2026-10-22T06:50:01Z | func_002DDAB0 | 616 | skipped | 0 | 0.0 | no | objlist |
| 2026-10-22T06:52:30Z | func_001F8DF8 | 628 | non-matching | 3 | 0.0 | no | render |
| 2026-10-22T07:05:32Z | BATCH | - | batch | - | reseed 36.0; score 0.0 | - | BATCH 142 (slot machine, casino UI, movie volume, object scripts, render tests): 3 own registered (Slot2_JudgeLines, Slot2_PayoutJackpotLine in src/cod/001e58f8.c / 001e6498.c; func_001F5650 status panel in src/cod/001f5650.c; per-file settings: 001f5650.c fp_hazard_rules fdiv,mtc1; 001e58f8.c and 001e6498.c have none), 7 NM drafts (Slot2_Execute, 001eb7b8, 002000f8, 001a4010 cOm49 effect step, 0028e580 action-button soft event, 00129eb0 knock-away scan, 001f8df8 bounding-box depth test), skips logged; handoffs 3 (func_003257C8 adds D_003C8168/D_003C81A8 to adxmThread.h; func_00353348 adds skipLevel to SfdWork in sftim.h; func_0035F970 gives func_0035FB78 its (ver,a1,a2) signature in 00297fb8.c), full build ELF/overlay OK; reseed elf/overlay OK; nm_prune 0 stale; 00349c28 held for checkpoint |
| 2026-10-22T07:07:15Z | func_00154E98 | 672 | skipped | 0 | 0.0 | no | render |
| 2026-10-22T07:07:24Z | func_0015EC60 | 636 | skipped | 0 | 0.0 | no | render |
| 2026-10-22T07:10:46Z | func_002AD2B8 | 724 | non-matching | 6 | 125.9 | no | spring-mesh |
| 2026-10-22T07:11:05Z | func_002A7CD0 | 868 | skipped | 0 | 0.0 | no | object-sort |
| 2026-10-22T07:13:40Z | func_0032AFB0 | 236 | matched | 3 | 87.8 | no | adx |
| 2026-10-22T07:15:59Z | func_003407A0 | 368 | non-matching | 5 | 92.0 | no | sound-pan |
| 2026-10-22T07:15:59Z | func_003A50B4 | 100 | skipped | 0 | 0.0 | no | libc |
| 2026-10-22T07:15:59Z | func_00333FD8 | 100 | skipped | 0 | 0.0 | no | libc |
| 2026-10-22T07:18:48Z | func_0033D598 | 392 | non-matching | 6 | 127.0 | no | adx |
| 2026-10-22T07:20:15Z | func_0032DD70 | 132 | non-matching | 3 | 0.0 | no | movie |
| 2026-10-22T07:20:56Z | func_0032AC48 | 176 | matched | 1 | 0.0 | no | adx |
| 2026-10-22T07:21:27Z | func_003452D8 | 436 | skipped | 0 | 0.0 | no | movie |
| 2026-10-22T07:21:35Z | func_001F8AD8 | 788 | skipped | 0 | 0.0 | no | render |
| 2026-10-22T07:54:38Z | BATCH | - | batch | - | reseed 36.0; score 0.0 | - | BATCH 143 (ADX/movie cygnus library, spring mesh, sound pan, render tests): 2 own registered (func_0032AFB0 ADXT server tick in src/cod/0032afb0.c, per-file setting c_flags_drop -freorder-blocks; D_003D140C declared volatile as the cross-thread server stage guard; func_0032AC48 ADX decode limit in src/cod/0032ac48.c, per-file setting c_flags_drop -freorder-blocks), signature correction: func_0032CFC8 and its ADXT_ExecHndl declaration in 00322f58.c now take signed char *adxt (still matches); 3 NM drafts (002ad2b8 spring mesh setup, 003407a0 pan delay, 0033d598 ADXB end-of-decode), 0032dd70 held for checkpoint (needs MwPly span/rate fields; matches with fp_hazard_rules cmpfull), skips logged (packet builders 00154e98/0015ec60, inlined std::sort 002a7cd0, nop delay 00333fd8, MMI memcmp 003a50b4, MWSFD init 003452d8 on callee signatures, corner pattern 001f8ad8); full build ELF/overlay OK; reseed elf/overlay OK; nm_prune 0 stale; strip_data_nonmatching run for the adxmThread.h externs added by the batch 142 handoff; session_check in container: all pass except dual_compiler_regress, which fails only inside the harness (argument list too long) and passes standalone |
| 2026-10-22T07:54:49Z | func_0012D970 | 788 | skipped | 0 | 0.0 | no | hit-volume |
| 2026-10-22T07:54:57Z | func_002BB868 | 820 | skipped | 0 | 0.0 | no | geometry |
| 2026-10-22T07:57:25Z | func_00273960 | 724 | non-matching | 5 | 96.8 | no | enemy-ai |
| 2026-10-22T07:57:42Z | func_001361A0 | 692 | skipped | 0 | 0.0 | no | geometry |
| 2026-10-22T07:59:23Z | func_002DACE8 | 636 | non-matching | 4 | 44.9 | no | hit-test |
| 2026-10-22T07:59:36Z | func_003420E0 | 1000 | skipped | 0 | 0.0 | no | adx-adpcm |
| 2026-10-22T07:59:37Z | func_0032F580 | 948 | skipped | 0 | 0.0 | no | adx-aix |
| 2026-10-22T08:00:47Z | func_002EBF98 | 636 | skipped | 0 | 0.0 | no | effect-packet |
| 2026-10-22T08:03:43Z | func_0012B328 | 660 | non-matching | 5 | 102.2 | no | player-carry |
| 2026-10-22T08:03:55Z | func_00154A90 | 780 | skipped | 0 | 0.0 | no | dma-packet |
| 2026-10-22T08:04:00Z | func_001661D8 | 872 | skipped | 0 | 0.0 | no | id-screen |
| 2026-10-22T08:04:04Z | func_002E8B38 | 944 | skipped | 0 | 0.0 | no | gs-packet |
| 2026-10-22T08:05:06Z | func_0010C5A8 | 904 | skipped | 0 | 0.0 | no | cEm00-state |
| 2026-10-22T08:05:13Z | func_001430E8 | 956 | skipped | 0 | 0.0 | no | id-screen |
| 2026-10-22T08:05:46Z | func_00115310 | 968 | skipped | 0 | 0.0 | no | pl00-state |
| 2026-10-22T08:06:02Z | func_0039EEA8 | 192 | skipped | 0 | 0.0 | no | libc-mmi |
| 2026-10-22T08:40:41Z | BATCH | - | batch | - | reseed 121.0; score 0.0 | - | BATCH 144 (hit tests, player/enemy states, ADX library, packet builders): 0 own registered; NM handoff func_0033D598 ADXB end-of-decode -> src/cod/0033d598.c (cygnus, no per-file settings; duplicate compiler line removed, .gitignore line added, symbol entry already present); 3 drafts (00273960 cEm00 three-ray check, 002dace8 segment box hit test (sn, fp_hazard_rules fdiv, needs -ffast-math), 0012b328 player carry target (sn, fp fdiv,mtc1; blocked on cOmBase_canCarry being defined long long)); skips logged (packet builders 00154a90/002e8b38/002ebf98 (002ebf98 also forwards an a1 its callee never reads), sqc2-vf0 array loops 001661d8/001430e8, MMI 003420e0/0039eea8, AIX parser 0032f580, header blockers 0010c5a8 (cEm00 0x5D8 read as int inside posB) and 00115310 (cGameObj 0x580), plus 0012d970/002bb868/001361a0); pending_headers updated; full build ELF/overlay OK; reseed elf/overlay OK; nm_prune 0 stale; session_check in container: all pass except dual_compiler_regress, which fails only inside the harness (argument list too long) and passes standalone |
| 2026-10-22T08:45:26Z | sceGsSetDefDispEnv | 884 | non-matching | 5 | 140.4 | no | libgraph |
| 2026-10-22T08:49:05Z | func_00323050 | 1060 | non-matching | 6 | 145.0 | no | adxf |
| 2026-10-22T08:49:36Z | func_00358AA8 | 972 | skipped | 0 | 0.0 | no | mwsfd |
| 2026-10-22T08:55:51Z | func_003AD348 | 1092 | non-matching | 6 | 295.9 | no | libm |
| 2026-10-22T08:57:24Z | func_003284B8 | 1060 | skipped | 0 | 0.0 | no | adx |
| 2026-10-22T08:58:17Z | func_002FA620 | 1008 | skipped | 0 | 0.0 | no | gs-packet |
| 2026-10-22T09:00:04Z | func_00201290 | 1156 | non-matching | 4 | 56.5 | no | cdvd |
| 2026-10-22T09:04:33Z | func_00161D08 | 1388 | non-matching | 4 | 108.5 | no | godreel-menu |
| 2026-10-22T09:06:17Z | func_0012F750 | 1228 | skipped | 0 | 0.0 | no | hit-probe |
| 2026-10-22T09:10:24Z | cCamera_update | 1072 | non-matching | 2 | 164.1 | no | camera |
| 2026-10-22T09:10:40Z | func_003BB4F0 | 1164 | skipped | 0 | 0.0 | no | stl |
| 2026-10-22T09:10:40Z | func_003BBA10 | 1164 | skipped | 0 | 0.0 | no | stl |
| 2026-10-22T09:11:07Z | func_002CCD80 | 1100 | skipped | 0 | 0.0 | no | sound-bgm |
| 2026-10-22T09:14:51Z | BATCH | - | batch | - | reseed 36.0; score 0.0 | - | BATCH 145 (libm, libgraph, ADX/ADXF library, DVD queue, God Reel menu, camera, STL): 0 own registered. NM drafts: sceGsSetDefDispEnv (drafts/cod/00396570.c), func_00323050 ADXF partition load server, func_003AD348 fmod (3 insns off: retail's assembler expands dli 0xffffffff as addiu/dsrl32 and pads call-free short loops; neither assembler route does both), func_00201290 DVD queue pack and sort (cDvdJob.arg6C is an unsigned priority), func_00161D08 God Reel equip screen (344/347 words; cCoreSave_getReelSlot takes an unsigned char slot), cCamera_update (identical through the screen and view matrices; retail's div.s pad depth varies 0/1/2 by site, which no fp_hazard_rules set models). Skips: func_00358AA8, func_003284B8 (ADX stream callees declared three ways), func_002FA620 (GS packet builder), func_0012F750 (sqc2-vf0 loop), func_003BB4F0/func_003BBA10 (inlined STL vector<string>), func_002CCD80 (sound sequencer types clash). pending_headers updated (cDvd priority and cDvd_startJobHeap, ADX stream forwarders, cCoreSave_getReelSlot, cIDBase_move, matrix helpers, sound sequencer). Handoffs 0. Reseed elf/overlay OK (first try used a draft as anchor and failed before compiling; rerun with func_0033D598). nm_prune 0 stale. session_check in container: 18 pass, 7 skipped, 1 fail (dual_compiler_regress, harness-only argument list too long; standalone run started). |
| 2026-10-22T09:19:14Z | func_002BEDE8 | 288 | non-matching | 5 | 90.3 | no | roomsave |
| 2026-10-22T09:22:48Z | func_003780F8 | 132 | matched | 6 | 86.1 | no | sound |
| 2026-10-22T09:22:48Z | func_0037D558 | 292 | skipped | 4 | 155.6 | no | sound |
| 2026-10-22T09:25:27Z | func_001FB1C0 | 276 | non-matching | 3 | 57.6 | no | coresave |
| 2026-10-22T09:28:35Z | func_00365EC0 | 592 | non-matching | 6 | 128.9 | no | sfxlib |
| 2026-10-22T09:54:30Z | BATCH | - | batch | - | reseed 98.0; score 0.0 | - | batch 146: 1 matched+registered (func_003780F8), 1 matched held for checkpoint (func_0037D558, seqNode.h pan field + prototypes), drafts 002bede8/001fb1c0/00365ec0; session_check 18 pass + known dcr ARG_MAX fail; standalone dcr running |
| 2026-10-22T09:56:54Z | func_002FE8A0 | 628 | non-matching | 2 | 65.6 | no | sprite |
| 2026-10-22T09:59:35Z | func_00159AD0 | 716 | non-matching | 6 | 102.2 | no | recdecode |
| 2026-10-22T10:03:06Z | func_0013E970 | 556 | non-matching | 3 | 86.8 | no | hud |
| 2026-10-22T10:03:54Z | func_0012F288 | 576 | skipped | 1 | 12.7 | no | collision |
| 2026-10-22T10:07:14Z | func_002956F0 | 368 | non-matching | 4 | 111.8 | no | cEmSetParam |
| 2026-10-22T10:08:10Z | cSescr_At_ck | 352 | skipped | 0 | 0.0 | no | cvtws |
| 2026-10-22T10:14:32Z | func_00366110 | 596 | non-matching | 6 | 260.0 | no | sfxCsc |
| 2026-10-22T10:14:32Z | func_00366368 | 596 | non-matching | 2 | 18.0 | no | sfxCsc |
| 2026-10-22T10:14:33Z | cSnd_UpdateListener | 608 | skipped | 0 | 0.2 | no | vu0-inline |
| 2026-10-22T10:14:33Z | func_002C0038 | 676 | skipped | 0 | 0.2 | no | coresave-align |
| 2026-10-22T10:14:33Z | func_002DAA40 | 680 | skipped | 0 | 0.2 | no | vu0-inline |
| 2026-10-22T10:14:33Z | cOmSetParam_setOmData | 636 | skipped | 0 | 0.2 | no | cvtws |
| 2026-10-22T10:14:33Z | func_00378398 | 416 | skipped | 0 | 0.2 | no | cvtws |
| 2026-10-22T10:14:33Z | func_0037C720 | 524 | skipped | 0 | 0.2 | no | cvtws |
| 2026-10-22T11:00:55Z | BATCH | - | batch | - | reseed 51.0; score 0.0 | - | batch 147: 0 registered; drafts 002FE8A0 00159AD0 0013E970 002956F0 00366110 00366368; held 0012F288; skips cvt.w.s x5, vu0-inline x2, coresave-align; both hashes OK; session_check OK except known dcr ARG_MAX, standalone dcr PASS |
| 2026-10-22T11:04:13Z | func_002C45A8 | 704 | non-matching | 5 | 101.6 | no | cScenario |
| 2026-10-22T11:05:23Z | func_001BC300 | 568 | skipped | 0 | 0.0 | no | lwu-bittest |
| 2026-10-22T11:05:23Z | func_002C02E8 | 708 | skipped | 0 | 0.0 | no | lwu-bittest |
| 2026-10-22T11:05:23Z | func_00123160 | 760 | skipped | 0 | 0.0 | no | lwu-bittest |
| 2026-10-22T11:06:19Z | func_002BFC80 | 952 | skipped | 0 | 0.0 | no | coresave-align |
| 2026-10-22T11:06:19Z | func_0030CB30 | 988 | skipped | 0 | 0.0 | no | gs-bitfield-sched |
| 2026-10-22T11:06:19Z | Gp_draw_line | 916 | skipped | 0 | 0.0 | no | gif-packet |
| 2026-10-22T11:06:19Z | Gp_draw_poly3 | 936 | skipped | 0 | 0.0 | no | gif-packet |
| 2026-10-22T11:06:19Z | func_0016DC18 | 796 | skipped | 0 | 0.0 | no | cvtws |
| 2026-10-22T11:06:19Z | func_00143670 | 804 | skipped | 0 | 0.0 | no | cvtws |
| 2026-10-22T11:06:19Z | func_002F1758 | 824 | skipped | 0 | 0.0 | no | cvtws |
| 2026-10-22T11:06:19Z | func_003187D8 | 896 | skipped | 0 | 0.0 | no | cvtws |
| 2026-10-22T11:09:48Z | func_00329490 | 792 | non-matching | 5 | 109.4 | no | adxt |
| 2026-10-22T11:57:01Z | BATCH | - | batch | - | reseed 37.0; score 0.0 | - | batch 148: 0 registered; drafts 002C45A8 (s0/s1 swap only) 00329490 (ADXT_Create); skips lwu-bittest x3, cvt.w.s x4, coresave-align, gif-packet x2, gs-bitfield-sched; both hashes OK; session_check OK except known dcr ARG_MAX, standalone dcr PASS |
| 2026-10-22T11:59:27Z | func_0032A1B0 | 756 | non-matching | 4 | 95.9 | no | adxt |
| 2026-10-22T12:01:03Z | cSnd_UpdateListener | 608 | non-matching | 1 | 34.4 | no | cSnd |
| 2026-10-22T12:15:15Z | BATCH | - | batch | - | reseed 36.0; score 0.0 | - | batch 149 (cri adxt / snd): 0 registered; drafts 0032A1B0 (ADXT_GetTime, 3 diffs) and 002CC150 (cSnd_UpdateListener, 161 vs 152 words); full build both hashes OK; session_check 18 pass, known dcr rc=126 only; standalone dcr folded into the post-checkpoint run |
| 2026-10-22T13:41:28Z | func_0037D558 | 292 | matched | 1 | 0.0 | no | seq |
| 2026-10-22T13:41:28Z | func_0012F288 | 576 | matched | 1 | 0.0 | no | grid |
| 2026-10-22T13:41:28Z | func_00349C28 | 184 | matched | 1 | 0.0 | no | cri-mwsfd |
| 2026-10-22T13:41:28Z | func_0032DD70 | 132 | matched | 1 | 0.0 | no | movie |
| 2026-10-22T13:41:28Z | BATCH | - | batch | - | reseed 36.0; score 0.0 | - | checkpoint after 149 (stopped for upstream sync): header_merge seqNode.h pan + prototypes, new cGrid.h, mwPly.h span/rate + func_00328C80, mwsfd.h + func_0032B488 real signature (12 units identical); registered func_0037D558 (mtc1), func_0012F288 (fdiv), func_00349C28 (drop-reorder), func_0032DD70 (cmpfull); func_0013D7B0 still held; nm_solved handoff not applied (interrupted, header edits reverted); full + cold builds both hashes OK |
| 2026-10-22T19:26:54Z | func_0012C000 | 212 | matched | 5 | 250.0 | no | player combo (0x12Cxxx): combo set used-up check; extern_jtbl D_0041D1A0; each case a full `set == N && slot >= getComboMax` test that cross-jumping merges (shared-tail forms are 1-3 words off); local ComboHolder view (same fields as ComboObj in 00126918.c, pending header); src/cod/0012c000.c |
| 2026-10-22T19:29:00Z | func_002BF420 | 88 | non-matching | 3 | 120.0 | no | scenario cursor (0x2BFxxx): still 2 insns (retail puts the 4 for keep in the beqz delay slot); store orders, self[3] form and as sn all leave it; draft drafts/cod/002bf420.c unchanged |
| 2026-10-22T19:30:00Z | cOl0e_setFake | 224 | non-matching | 3 | 60.0 | no | cOl0e (0x173xxx): body matches; retail compares fake in DImode so the gone-test constant 1 is shared; only a long parameter or an int gone (both banned) reproduce it; draft drafts/cod/00173820.c unchanged |
| 2026-10-22T19:32:25Z | func_001EBB78 | 220 | non-matching | 6 | 145.0 | no | delayed motions (0x1EBxxx): 19 -> 2 insns (loop index form `m = base + i`, delayDone with two returns); last gap is f12/a0 load order for SetMotionStep, closed only by a block-scoped float temporary (steering); draft drafts/cod/001ebb78.c updated |
| 2026-10-22T19:33:30Z | func_001F7680 | 280 | non-matching | 2 | 65.0 | no | game view request (0x1F7xxx): retail keeps cases 0-3 as separate arms (no cross-jump) and the view record address in a register; view pointer forms still 11 words short; draft unchanged |
| 2026-10-22T19:37:50Z | func_0030E660 | 1688 | non-matching | 6 | 260.0 | no | libgraph SN copy of sceGsExecStoreImage (0x30Exxx): as sn + extern_jtbl D_004508F0, switch on the u_long SPSM, (u_long) RRW, no qword temp at the tail; 420/422 words: entry RRW/RRH scheduling, IMR mask li 0x200+or+andi 0x7E00, one short-loop pad nop; Tramp_GsGetIMR_3964A0 definition is void but returns GsGetIMR (pending); draft drafts/cod/0030e660.c |
| 2026-10-22T19:41:15Z | func_002B42F0 | 156 | non-matching | 5 | 195.0 | no | message window (0x2B4xxx): lw+dsrl idiom (`int flags` read once, `unsigned long f = flags`) fixes the prefix; retail keeps the bit-6 arm and case 0x8000 as two state-7 copies where ours cross-jumps; 35/39 words; draft drafts/cod/002b4228.c updated (section attributes added) |
| 2026-10-22T19:45:34Z | cSubScr_SubScrOn | 436 | non-matching | 8 | 217.5 | no | sub screen (0x160xxx): GameWork anchors traced: retail forms constant D_007474A0+off addresses (anchor +0x5E4, +0x5D8 after Getplayer) and a base pointer for the 0x5D8/0x5E0 copies; 110/109 words, entry register choice left; needs flags5D8/flags5E0 in gameWork.h; draft drafts/cod/00160020.c |
| 2026-10-22T19:48:17Z | func_001F0A28 | 464 | non-matching | 6 | 159.0 | no | ColiseumBattle (objects) |
| 2026-10-22T19:54:48Z | func_00285C58 | 608 | non-matching | 6 | 362.1 | yes | cEm00 enemies (hit reaction) |
| 2026-10-22T19:55:27Z | func_001F3DF0 | 628 | skipped | 0 | 35.3 | yes | ColiseumEmSelect (casino) |
| 2026-10-22T19:58:34Z | cOmWeapon_SetBreak | 696 | non-matching | 6 | 186.5 | yes | cOmWeapon (objects) |
| 2026-10-22T20:17:07Z | BATCH | - | batch | - | reseed 88.0; score 0.0 | - | BATCH 150 (near-miss re-sweep: combos, coliseum, enemies, weapons, libgraph): 1 own registered (func_0012C000 combo set used-up test in src/cod/0012c000.c; per-file setting: extern_jtbl D_0041D1A0); drafts rewritten or new: 001ebb78 (2 insns), 002b4228 (func_002B42F0 35/39), 00160020 (cSubScr_SubScrOn), 001f0a28 (14, store order), 00285c58 (7, actor range test), 001d0818 (cOmWeapon_SetBreak, bool-style child lookup); 002bf420, 00173820, 001f7680 still parked; func_001F3DF0 skipped (cScenario_beginRoomJump_2C4548 definition drops the float angle). Handoffs: 2 received, 1 registered (func_0030E660 -> src/cod/0030e660.c, as sn + extern_jtbl D_004508F0; GsGetIMR/Tramp_GsGetIMR_3964A0/func_00396008 corrected to u_long in 00150078.c and 00396008.c; duplicate compiler line removed), 1 held for the checkpoint (cSubScr_SubScrOn, needs gameWork.h flags5D8/flags5E0). Full build in the handoff and reseed: elf/overlay OK. nm_prune 0 stale. session_check 18 pass, 7 skipped, known dual_compiler_regress rc=126 only |
| 2026-10-22T20:20:31Z | func_00129718 | 724 | non-matching | 4 | 188.3 | yes | pl00 player (caught by enemy) |
| 2026-10-22T20:21:08Z | Fil_clut_set | 760 | skipped | 0 | 31.6 | yes | filter CLUT (render) |
| 2026-10-22T20:21:53Z | func_001DAB00 | 788 | skipped | 0 | 44.5 | yes | Poker (casino) - needs Poker.h byte at 0x3044 (header off limits) |
| 2026-10-22T20:22:07Z | func_00268068 | 924 | skipped | 0 | 14.2 | yes | enemy AI attack pick (deferred: nested control flow, 118-case table) |
| 2026-10-22T20:25:29Z | func_00262750 | 560 | non-matching | 5 | 176.2 | no | enemies: attack volume setup |
| 2026-10-22T20:28:51Z | func_00245538 | 664 | non-matching | 6 | 198.9 | yes | enemies: walk to goal point |
| 2026-10-22T20:29:23Z | func_00270338 | 668 | skipped | 0 | 27.8 | yes | enemies: head/neck aim (VU0-heavy, deferred) |
| 2026-10-22T20:31:09Z | func_0026B240 | 676 | non-matching | 2 | 105.9 | yes | enemies: throw weapon at player |
| 2026-10-22T20:33:16Z | func_00271518 | 696 | non-matching | 2 | 123.4 | yes | enemies: grab aim point |
| 2026-10-22T20:36:05Z | func_003099D8 | 596 | non-matching | 2 | 133.1 | yes | GS: image upload through scratchpad |
| 2026-10-22T20:58:30Z | BATCH | - | batch | - | reseed 85.0; score 0.0 | - | BATCH 151: 0 own registered. Drafts: func_00129718, func_00262750 (4 diffs), func_00245538 (18 diffs), func_0026B240, func_00271518, func_003099D8. Skipped: Fil_clut_set, func_001DAB00, func_00268068, func_00270338 (VU0-heavy). Definition fixes, both verified by the full build: cGameObj_SetTgtTurn now takes (self, target, rate) (001351d8.c); func_00397550 takes an unread timeout (00397550.c). Handoffs: 1 new received (func_001F0A28), 0 registered, 2 held for the checkpoint (cSubScr_SubScrOn, func_001F0A28; both need include/ changes). elf/overlay OK; nm_prune 0; session_check 18 pass, 7 skipped, known dual_compiler_regress rc=126. |
| 2026-10-22T21:01:42Z | func_0030D358 | 620 | non-matching | 2 | 168.0 | yes | boot: system and language data load |
| 2026-10-22T21:02:17Z | func_0020DA18 | 724 | skipped | 0 | 23.2 | yes | enemies: guard check (irregular nested switch, 5 unnamed cEm00 fields; deferred) |
| 2026-10-22T21:04:35Z | func_00241908 | 784 | non-matching | 4 | 138.2 | yes | enemies: wait for partners (phase 0x75 setup) |
| 2026-10-22T21:07:59Z | func_0013DB50 | 828 | non-matching | 4 | 194.4 | yes | HUD: icon screen intro flash |
| 2026-10-22T21:08:13Z | func_00167518 | 928 | skipped | 0 | 9.6 | yes | HUD: id screen fade (nested irregular switches; deferred) |
| 2026-10-22T21:09:55Z | cEm00_setGoto | 156 | matched | 2 | 81.6 | yes | enemy: cEm00 goto start |
| 2026-10-22T21:14:34Z | Set_bg_mode | 156 | non-matching | 2 | 2.9 | yes | render: background mode (matches; held for gameWork.h fields; timer started late, ~6 min real) |
| 2026-10-22T21:15:59Z | SearchData | 204 | non-matching | 3 | 82.0 | yes | data pack: entry search by name |
| 2026-10-22T21:19:47Z | cSaveLoad_openSave | 196 | non-matching | 4 | 225.7 | yes | system: save request open |
| 2026-10-22T21:24:18Z | cMovie_Start | 316 | non-matching | 5 | 263.2 | yes | movie: start clip (matches; held for D_00747A80 header type at checkpoint) |
| 2026-10-22T21:26:38Z | cModel_calcParts | 384 | non-matching | 3 | 127.6 | yes | model: per-frame part matrices |
| 2026-10-22T21:27:09Z | cSceAtUnit_AtInit | 140 | non-matching | 4 | 1034.1 | yes | scenario: attack unit init |
| 2026-10-22T21:41:29Z | BATCH | - | batch | - | reseed 56.0; score 32.0 | - | BATCH 152 (HUD, enemies, render, system, model): 1 own registered (cEm00_setGoto in new src/cod/0026e988.c, SN; its INCLUDE_ASM line removed from src/cod/enemy/cEm00.c, which builds with Cygnus). Held for checkpoint (match, need include changes): Set_bg_mode (gameWork.h fields, build/scratch/0030e5c0_ckpt.c), cMovie_Start (record type for D_00747A80, build/scratch/002b4be8_ckpt.c), NM handoff func_001A4010 (vu0.h). Drafts: func_0030D358, func_00241908, func_0013DB50 (206/207 words), SearchData (6), cSaveLoad_openSave (10), cModel_calcParts (34, one bc1f vs bc1fl), cSceAtUnit_AtInit (4, register swap). Skipped: func_0020DA18, func_00167518 (nested irregular switches). nm_handoff: 3 verified, all held (include frozen). nm_prune: nothing stale. session_check: all pass except the known dual_compiler_regress rc=126. Hashes OK. |
| 2026-10-22T21:41:55Z | func_0022E6A0 | 836 | skipped | 0 | 15.7 | yes | enemy: VU0 approach phase (needs cEm00 0x590/0x5F0/0x1724/0x1864 fields; include frozen) |
| 2026-10-22T21:45:30Z | func_001377E8 | 600 | non-matching | 4 | 189.3 | yes | collision: segment vs sphere |
| 2026-10-22T21:48:53Z | Dest_ck | 404 | matched | 4 | 174.7 | no | enemy-util |
| 2026-10-22T21:49:58Z | cObjSimple_UpdateHandMesh | 584 | skipped | 0 | 8.4 |
| 2026-10-22T21:50:43Z | func_0027A320 | 736 | skipped | 0 | 30.5 |
| 2026-10-22T21:50:43Z | func_0027AE10 | 744 | skipped | 0 | 0.0 |
| 2026-10-22T21:50:44Z | func_00283688 | 736 | skipped | 0 | 0.0 |
| 2026-10-22T21:50:44Z | func_00284068 | 744 | skipped | 0 | 0.0 |
| 2026-10-22T21:50:44Z | func_001F1148 | 576 | skipped | 0 | 0.0 |
| 2026-10-22T21:52:53Z | SetEffect | 424 | matched | 5 | 128.8 | no | effects |
| 2026-10-22T21:55:51Z | func_0028D138 | 672 | matched | 5 | 174.0 | no | enemy |
| 2026-10-22T21:56:54Z | func_0026AB20 | 728 | matched | 2 | 58.7 | no | enemy |
| 2026-10-22T22:00:16Z | func_0027CB58 | 792 | matched | 5 | 197.1 | no | enemy |
| 2026-10-22T22:05:25Z | func_0028CB90 | 576 | non-matching | 6 | 301.7 | no | enemy |
| 2026-10-22T22:06:05Z | cEmSetParam_setEmAll | 720 | skipped | 0 | 34.6 |
| 2026-10-22T22:06:29Z | func_002C1D68 | 776 | skipped | 0 | 24.7 |
| 2026-10-22T22:09:58Z | func_0012A610 | 712 | non-matching | 6 | 208.6 | no | player |
| 2026-10-22T22:31:22Z | BATCH | - | batch | - | reseed 1.0; score 5.0 | - | BATCH 153 (effects, enemies, weapons): 1 own registered (Dest_ck in new src/cod/002da2d0.c; per-file setting: fp_hazard_rules div, as sn; INCLUDE_ASM removed from src/cod/000000.c; Dest_ck prototype in 001b7ee0.c corrected to float* args, func_001B7EE0 still matches). Held for checkpoint (match, need include changes): SetEffect (build/scratch/00306528_ckpt.c), func_0028D138 (extern_jtbl D_0044A120), func_0026AB20 (extern_jtbl D_00445440 D_004455A0), func_0027CB58 (extern_jtbl D_00448150). Drafts: func_0028CB90 (39 diffs), func_0012A610 (171 diffs, frame 0x10 smaller). Reseed elf/overlay OK; nm_prune 0 stale; session_check (container) 18 pass, 7 skipped, known dual_compiler_regress rc=126 only. |
| 2026-10-22T22:37:15Z | func_0012B618 | 780 | non-matching | 5 | 151.0 |
| 2026-10-22T22:43:54Z | func_0012BC00 | 848 | matched | 6 | 268.4 | no | player |
| 2026-10-22T22:44:22Z | func_00110B20 | 888 | skipped | 0 | 17.9 |
| 2026-10-22T22:46:09Z | func_0014BFE0 | 836 | skipped | 0 | 106.3 |
| 2026-10-22T22:46:27Z | func_00133DA0 | 1232 | matched | 1 | 18.8 | no | collision |
| 2026-10-22T22:46:44Z | func_0012D3C8 | 1448 | skipped | 0 | 11.9 |
| 2026-10-22T22:46:54Z | func_00166780 | 992 | skipped | 0 | 9.5 |
| 2026-10-22T22:48:08Z | func_0037FAC8 | 164 | skipped | 0 | 0.0 |
| 2026-10-22T22:52:59Z | func_00269B50 | 1220 | non-matching | 5 | 283.8 |
| 2026-10-22T22:55:48Z | func_00275978 | 1008 | non-matching | 4 | 153.5 |
| 2026-10-22T23:06:10Z | BATCH | - | batch | - | reseed 0.0; score 2.0 | - | BATCH 154 (player, collision, enemies, menu): nothing registered, no reseed. Held for checkpoint (match, need include changes): func_0012BC00 (player.h cObjInitVt.init returns int, shared prototype; build/scratch/0012bc00_ckpt.c, extern_jtbl D_0041D180), func_00133DA0 (cCollisionSolidBox into cCollisionSolid.h, shared Draw_Line2 prototype; build/scratch/00133da0_ckpt.c), NM handoff cModel_calcParts (as sn; needs shared Adjust_theta_vec/func_001501D0/func_00156D70 prototypes in cModel.h). Drafts: func_0012B618 (95, by-value vector temporaries), func_00269B50 (child lookups copy into a0 in retail, 0x30 short), func_00275978 (one branch target with cmppad; needs a label-pad wrapper rule and cEm00.h 0x744/0x1680). Skipped: func_00110B20, func_0014BFE0, func_0012D3C8, func_00166780, func_0037FAC8 (func_00380EB0 definition vs menuCtl.h prototype). nm_handoff: 4 verified, all held (include frozen). nm_prune: nothing stale. session_check: all pass except the known dual_compiler_regress rc=126. |
| 2026-10-22T23:08:54Z | func_002A0C60 | 1160 | non-matching | 1 | 156.9 |
| 2026-10-22T23:13:05Z | func_0027D400 | 624 | non-matching | 6 | 230.8 |
| 2026-10-22T23:13:08Z | func_0028AE18 | 648 | skipped | 0 | 3.2 |
| 2026-10-22T23:16:17Z | func_0012AFE8 | 760 | non-matching | 6 | 182.7 |
| 2026-10-22T23:17:58Z | func_002812A8 | 116 | skipped | 3 | 55.8 |
| 2026-10-22T23:18:39Z | KeyStop | 60 | matched | 1 | 9.1 |
| 2026-10-22T23:20:21Z | cIDBase_getIDWork | 112 | non-matching | 4 | 57.1 |
| 2026-10-22T23:24:48Z | func_001C86E8 | 580 | non-matching | 5 | 120.3 |
| 2026-10-22T23:25:22Z | func_002BC950 | 560 | skipped | 0 | 20.7 |
| 2026-10-22T23:25:22Z | func_002FDE60 | 628 | skipped | 0 | 0.0 |
| 2026-10-22T23:25:22Z | func_001646C0 | 692 | skipped | 0 | 0.0 |
| 2026-10-22T23:28:37Z | func_00244398 | 632 | matched | 5 | 125.4 |
| 2026-10-22T23:30:14Z | func_00248D00 | 732 | matched | 4 | 48.0 |
| 2026-10-22T23:33:09Z | func_0024BB68 | 564 | non-matching | 6 | 126.0 |
| 2026-10-22T23:43:57Z | BATCH | - | batch | - | reseed 42.0; score 2.0 | - | BATCH 155 (enemies, system, UI, objects): 2 own registered: func_00244398 (enemy down step, new src/cod/00244398.c) and func_00248D00 (enemy attack step with forward wall probe, new src/cod/00248d00.c), both SN with no per-file settings. Held for checkpoint (match, needs include changes): KeyStop (GameWork 0x178 key record and 0x5D8 lock word, shared D_005E8140; build/scratch/0031afa0_ckpt.c). Drafts: func_002A0C60, func_0027D400 (6), func_0012AFE8 (6), cIDBase_getIDWork (25/28 words, two loop pointers in retail), func_001C86E8 (10 diffs, &step register), func_0024BB68 (3 diffs: neg.s source register, vadd addressing). Skipped: func_0028AE18, func_002812A8 (retail's linear 1/0/2/3 compare chain only reproduced by goto ladders), cvt.w.s (waiting on maintainer): func_002BC950, func_002FDE60, func_001646C0. nm_handoff: 6 verified, none applied: 5 need include changes; func_0012B618 left for Jon (the solved C overlaps the child count and a cVec through a union in a stack-frame struct to reproduce retail's slot sharing). ChkLine a3 corrected to a pointer in both new units (still match). Reseed elf/overlay OK; nm_prune retired 2 stale NM drafts (00244398, 00248d00); session_check (container) 18 pass, 7 skipped, known dual_compiler_regress rc=126 only. |
| 2026-10-23T00:19:57Z | func_001B0540 | 756 | non-matching | 2 | 39.8 |
| 2026-10-23T00:22:07Z | func_001B51B0 | 636 | non-matching | 5 | 81.3 |
| 2026-10-23T00:22:24Z | func_001F00E8 | 628 | skipped | 0 | 0.0 |
| 2026-10-23T00:26:03Z | cCollisionSolidManage_ChkHit | 968 | matched | 6 | 152.1 |
| 2026-10-23T00:29:19Z | func_0016AE38 | 956 | matched | 4 | 104.7 |
| 2026-10-23T00:31:09Z | func_00146A18 | 1032 | matched | 2 | 30.3 |
| 2026-10-23T00:31:17Z | func_00176D60 | 1148 | skipped | 0 | 0.0 |
| 2026-10-23T00:33:24Z | func_00162298 | 1160 | non-matching | 5 | 78.9 |
| 2026-10-23T00:37:07Z | func_001D7560 | 1140 | non-matching | 6 | 110.5 |
| 2026-10-23T00:37:20Z | func_00148690 | 1352 | skipped | 0 | 0.0 |
| 2026-10-23T00:39:39Z | func_00167908 | 1448 | matched | 2 | 74.2 |
| 2026-10-23T00:41:23Z | func_00166BB8 | 1844 | matched | 1 | 55.2 |
| 2026-10-23T00:44:39Z | func_00169DF8 | 1760 | non-matching | 3 | 53.0 |
| 2026-10-23T00:54:31Z | BATCH | - | batch | - | reseed 44.0; score 3.0 | - | BATCH 156 (menu panels, collision, ID banners, minigames): 3 own registered, all SN with per-file settings as: sn plus extern_jtbl: func_0016AE38 (menu panel input step, src/cod/0016ae38.c, D_0041FD90), func_00167908 (options panel step, src/cod/00167908.c, D_0041FBD0), func_00166BB8 (pause options panel step, src/cod/00166bb8.c, D_0041FAE0 D_0041FB00). Definition changes, still matching: func_00167EB0 and func_001672F0 now take (void *self), marked not read. Held for checkpoint (match, need include changes): cCollisionSolidManage_ChkHit (cCollisionSolid.h; build/scratch/001348e8_ckpt.c), func_00146A18 (IdPair/cIDBase header, D_003C23A4; build/scratch/00146a18_ckpt.c, extern_jtbl D_0041E8A0). Drafts: func_001B0540, func_001B51B0, func_00162298 (2, one register), func_001D7560 (11, movz payouts; callee definition fixes pending), func_00169DF8 (324, reel shop row loop). Skipped: func_001F00E8, func_00176D60, func_00148690. nm_handoff: 5 verified, all held (include frozen). nm_prune: nothing stale. session_check: all pass except the known dual_compiler_regress rc=126. Hashes OK. |
| 2026-10-23T03:26:32Z | func_002FA350 | 140 | non-matching | 5 | 0.0 |
| 2026-10-23T03:26:33Z | func_002FA3E0 | 140 | non-matching | 5 | 0.0 |
| 2026-10-23T03:27:36Z | func_002FDE60 | 628 | skipped | 0 | 42.2 |
| 2026-10-23T03:28:23Z | func_002BC950 | 560 | skipped | 0 | 47.2 |
| 2026-10-23T03:28:32Z | func_001646C0 | 692 | skipped | 0 | 8.8 |
| 2026-10-23T03:30:47Z | ColiseumBattle_ApplyRingRules | 500 | non-matching | 4 | 134.5 |
| 2026-10-23T03:32:33Z | func_001F4248 | 480 | non-matching | 3 | 106.5 |
| 2026-10-23T03:32:57Z | cCoreSave_addItem | 464 | skipped | 1 | 23.2 |
| 2026-10-23T03:35:36Z | func_002FDDA8 | 184 | non-matching | 6 | 128.9 |
| 2026-10-23T03:37:12Z | func_003781F8 | 416 | non-matching | 3 | 95.2 |
| 2026-10-23T03:38:50Z | cSnd_CalcListenerPanDist | 444 | non-matching | 4 | 98.4 |
| 2026-10-23T03:41:10Z | func_002D8C60 | 376 | matched | 2 | 140.1 |
| 2026-10-23T03:44:01Z | func_002FBFB0 | 496 | non-matching | 6 | 170.3 |
| 2026-10-23T03:47:22Z | func_0018F218 | 620 | non-matching | 6 | 201.9 |
| 2026-10-23T03:50:11Z | cSescr_At_ck | 352 | non-matching | 6 | 127.9 |
| 2026-10-23T03:51:00Z | func_00378398 | 416 | non-matching | 2 | 44.8 |
| 2026-10-23T03:53:04Z | func_0037C720 | 524 | non-matching | 3 | 119.2 |
| 2026-10-23T03:53:30Z | cOmSetParam_setOmData | 636 | skipped | 0 | 20.6 |
| 2026-10-23T03:53:37Z | func_0016DC18 | 796 | skipped | 0 | 6.7 |
| 2026-10-23T03:56:07Z | func_00143670 | 804 | non-matching | 5 | 150.7 |
| 2026-10-23T04:12:06Z | BATCH | - | batch | - | reseed 45.0; score 3.0 | - | BATCH 157 (cvt.w.s re-sweep after the maintainer ruling: world light, effects, sound, HUD): 1 own registered: func_002D8C60 (world light preset fade, new src/cod/002d8c60.c, fp_hazard_rules mtc1; preset table reached as D_00604700.preset, linked bytes identical). NM closer handoffs registered (no header change): func_002FDDA8 (src/cod/002fdda8.c), cSnd_CalcListenerPanDist (src/cod/002cf058.c, fp_hazard_rules mtc1); folders moved to nm_solved/done, drafts removed. Held (header change): func_002FBFB0 (espSys.h, gameWork.h), func_00275978, cModel_calcParts, func_001A4010, func_001F0A28, cSubScr_SubScrOn. Drafts: ColiseumBattle_ApplyRingRules, func_001F4248, func_003781F8, func_00378398 (block order), func_002FBFB0 (solved by NM), func_0018F218 (child loop), cSescr_At_ck (belongs in 002c8b68.c unit), func_00143670 (byte clear of the 0x1C0 bits); func_0037C720 held in build/scratch/0037c720_ckpt.c until sndTiming.h/seqNode.h splits. Skipped: func_002BC950, func_002FDE60, func_001646C0, func_0016DC18 (SN C++ VU0 vector class), cOmSetParam_setOmData (CreateObj definition vs player.h), cCoreSave_addItem/func_002FA350/func_002FA3E0 (in-place cvt.w.s, decisions_needed). Waiting for fpu.h (value kept in a float register): RoundFloat, Adjust_theta, cEmSetParam_updateSetDataPos (in-place). Reseeds elf=OK overlay=OK; nm_prune 0 stale; session_check 18 pass, 7 skipped, known dual_compiler_regress rc=126. |
| 2026-10-23T04:13:00Z | STEP0 | - | step0 | - | - | - | BATCH 158 STEP 0: container /proc scan found only pid 1 (sleep infinity), no leftover permuter/compile.py/cc1/qemu, nothing killed. Normal build (compile.py) 37 s, rc=0: ELF 1742f95bef65bdb2 matches retail, r207 overlay ea59932301345e48 matches retail. |
| 2026-10-23T04:20:16Z | func_002F1758 | 824 | non-matching | 5 | 405.4 |
| 2026-10-23T04:24:25Z | func_003187D8 | 896 | non-matching | 3 | 245.2 |
| 2026-10-23T04:26:07Z | func_001B4A18 | 752 | skipped | 0 | 0.2 |
| 2026-10-23T04:26:07Z | func_001BE198 | 736 | skipped | 0 | 0.2 |
| 2026-10-23T04:26:07Z | func_001C2DA0 | 720 | skipped | 0 | 0.2 |
| 2026-10-23T04:26:07Z | func_001F85D0 | 572 | skipped | 0 | 0.2 |
| 2026-10-23T04:26:07Z | func_00279390 | 732 | skipped | 0 | 0.2 |
| 2026-10-23T04:26:07Z | func_002ADC70 | 736 | skipped | 0 | 0.2 |
| 2026-10-23T04:26:07Z | func_002F5020 | 772 | skipped | 0 | 0.2 |
| 2026-10-23T04:30:20Z | func_0026B600 | 996 | matched | 3 | 242.4 |
| 2026-10-23T04:30:48Z | func_0011E1E0 | 1380 | skipped | 0 | 16.9 |
| 2026-10-23T04:30:48Z | func_0011E748 | 1380 | skipped | 0 | 0.0 |
| 2026-10-23T04:31:57Z | cModel_Trans | 1316 | skipped | 0 | 30.2 |
| 2026-10-23T04:38:47Z | func_0010F720 | 1780 | matched | 4 | 398.5 |
| 2026-10-23T04:40:57Z | func_00112CB8 | 1392 | matched | 2 | 115.1 |
| 2026-10-23T04:41:29Z | func_002D3750 | 1108 | skipped | 0 | 12.4 |
| 2026-10-23T04:41:39Z | func_002A53A8 | 1272 | skipped | 0 | 9.8 |
| 2026-10-23T04:46:07Z | func_002FD078 | 1204 | matched | 4 | 267.9 |
| 2026-10-23T04:46:20Z | func_0015D6E8 | 1092 | skipped | 0 | 9.4 |
| 2026-10-23T04:52:58Z | func_003029C0 | 1160 | matched | 2 | 388.7 |
| 2026-10-23T04:53:15Z | func_003035D0 | 1048 | skipped | 0 | 9.4 |
| 2026-10-23T04:57:49Z | func_001AC370 | 1220 | non-matching | 4 | 274.8 |
| 2026-10-23T05:01:47Z | func_002B34D8 | 1240 | non-matching | 3 | 207.1 |
| 2026-10-23T05:03:33Z | func_002C78F0 | 1012 | non-matching | 3 | 102.9 |
| 2026-10-23T05:03:51Z | func_0025FE30 | 1092 | skipped | 0 | 0.0 |
| 2026-10-23T05:03:51Z | func_00268788 | 1600 | skipped | 0 | 0.0 |
| 2026-10-23T05:03:51Z | func_0026DB00 | 1880 | skipped | 0 | 0.0 |
| 2026-10-23T05:03:51Z | func_00270DB0 | 916 | skipped | 0 | 0.0 |
| 2026-10-23T05:03:52Z | func_00271810 | 1692 | skipped | 0 | 0.0 |
| 2026-10-23T05:03:52Z | func_00271EB0 | 1724 | skipped | 0 | 0.0 |
| 2026-10-23T05:03:52Z | func_00272DD8 | 1112 | skipped | 0 | 0.0 |
| 2026-10-23T05:03:52Z | func_0027D670 | 1144 | skipped | 0 | 0.0 |
| 2026-10-23T05:04:27Z | func_0011F810 | 1280 | skipped | 0 | 16.0 |
| 2026-10-23T05:04:35Z | func_00144368 | 1896 | skipped | 0 | 7.5 |
| 2026-10-23T05:04:44Z | func_001325A0 | 1052 | skipped | 0 | 7.9 |
| 2026-10-23T05:06:43Z | func_001AE928 | 1156 | non-matching | 1 | 113.4 |
| 2026-10-23T05:25:09Z | BATCH | - | batch | - | reseed 43.0; score 1.0 | - | BATCH 158 (SN 1000-1900 B by subsystem: enemies, player, effects, objects, HUD): 1 own registered: func_003029C0 (effect emitter frame, new src/cod/003029c0.c, fp_hazard_rules mtc1; cVec_set4 for the anchor translation, separate bit tests through an inline helper). Held for the checkpoint (header change): func_0026B600, func_0010F720, func_00112CB8, func_002FD078. NM closer handoffs still held (header changes): cModel_calcParts, cSubScr_SubScrOn, func_001A4010, func_001F0A28, func_00275978, func_002FBFB0. Drafts: func_002F1758, func_003187D8, func_001AC370 (guard shell colour tail registers; retail pads div.s inconsistently), func_002C78F0 (rotated screen quad, 254 diffs). Not drafted: func_002B34D8 (dispatcher switch tree, 200 diffs), func_001AE928 (retail computes 2.2-0.5 at run time from a 0.5 held in f20; an inline helper parameter is constant-folded, so only a constant held in a variable reproduces it). Skipped (VU0): func_0025FE30, func_00268788, func_0026DB00, func_00270DB0, func_00271810, func_00271EB0, func_00272DD8, func_0027D670, func_0011F810, func_001325A0, func_0011E1E0, func_0011E748, cModel_Trans, plus 7 earlier; skipped other: func_003035D0, func_00144368, func_002D3750, func_002A53A8, func_0015D6E8. Reseed elf=OK overlay=OK; nm_prune 0 stale; session_check 18 pass, 7 skipped, known dual_compiler_regress rc=126. |
| 2026-10-23T05:28:39Z | func_0030AC40 | 1104 | non-matching | 2 | 202.5 |
| 2026-10-23T05:29:11Z | func_002A67D0 | 1096 | skipped | 0 | 31.7 |
| 2026-10-23T05:31:10Z | func_002F3090 | 1056 | skipped | 0 | 101.3 |
| 2026-10-23T05:34:57Z | func_002F7E30 | 1856 | non-matching | 3 | 226.2 |
| 2026-10-23T05:35:26Z | func_00145810 | 1976 | skipped | 0 | 26.0 |
| 2026-10-23T05:38:59Z | func_00309568 | 1132 | non-matching | 4 | 134.0 |
| 2026-10-23T05:39:38Z | func_00309D88 | 1144 | skipped | 0 | 0.0 |
| 2026-10-23T05:39:49Z | func_002F43E8 | 1212 | skipped | 0 | 11.3 |
| 2026-10-23T05:40:26Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 159 (large SN functions: system, effects, graphics, ID menu): 0 matches. Drafts: func_002F7E30 (esp ring setup; 12 of 20 div.s padded, owner equality and range flag materialised differently), func_00309568 (TIM2 palette upload; two register choices left: the 256-colour step copied v0->s5, i&0xF held in s0 across the call). Not drafted: func_0030AC40 (game main loop; retail's restart is a backward goto, banned; scratch build/scratch/0030ac40_t.c). Skipped: func_002A67D0 (stage unload, ~40 callees), func_002F3090 (SN C++ VU0 vector class), func_00145810 (ID carousel, stack-spilled slot pointers), func_00309D88 (TIM2 DMA chain, t-register spills), func_002F43E8 (shares the motion frame-count block of drafts/cod/002f48a8.c). No registrations, so no reseed; nm_prune 0 stale; nm_handoff: 6 verified, all held for header changes at this checkpoint. |
| 2026-10-23T07:36:43Z | Set_bg_mode | 156 | matched | 1 | 0.0 |
| 2026-10-23T07:41:06Z | func_0012AC98 | 848 | skipped | 2 | 58.2 |
| 2026-10-23T07:43:48Z | func_002F2250 | 1284 | matched | 4 | 155.5 |
| 2026-10-23T07:47:25Z | func_002F5788 | 1132 | non-matching | 3 | 211.3 |
| 2026-10-23T07:47:38Z | func_00141678 | 1104 | skipped | 0 | 7.8 |
| 2026-10-23T07:47:45Z | func_003041B8 | 1656 | skipped | 0 | 7.5 |
| 2026-10-23T07:49:21Z | func_00302F68 | 1084 | matched | 2 | 53.4 |
| 2026-10-23T07:49:49Z | func_0010BE18 | 1256 | skipped | 0 | 23.6 |
| 2026-10-23T07:49:57Z | func_00146328 | 1052 | skipped | 0 | 8.4 |
| 2026-10-23T07:50:06Z | func_0013AD90 | 1516 | skipped | 0 | 9.1 |
| 2026-10-23T07:51:32Z | func_001067B8 | 1084 | non-matching | 1 | 85.3 |
| 2026-10-23T07:57:38Z | func_001329C0 | 988 | non-matching | 6 | 362.5 |
| 2026-10-23T08:03:43Z | ChkLine | 964 | non-matching | 8 | 347.6 |
| 2026-10-23T08:04:10Z | func_00136640 | 1088 | skipped | 0 | 9.6 |
| 2026-10-23T08:04:39Z | func_0012ED60 | 1316 | skipped | 0 | 29.8 |
| 2026-10-23T08:05:50Z | func_00139180 | 1688 | skipped | 0 | 60.2 |
| 2026-10-23T08:06:07Z | func_00106BF8 | 1892 | skipped | 0 | 17.7 |
| 2026-10-23T08:06:53Z | func_002F2A00 | 1440 | skipped | 0 | 27.5 |
| 2026-10-23T08:13:01Z | BATCH | - | batch | - | reseed 334.0; score 2.0 | - | BATCH 160 (large SN functions: player/camera 0x100000-0x14FFFF, effects 0x2F0000-0x30FFFF): 2 registered: func_002F2250 (esp model effect update, new src/cod/002f2250.c, as sn), func_00302F68 (esp particle move, new src/cod/00302f68.c, as sn). Drafts: func_002F5788 (ribbon setup; constant placement and a data-pointer reload), func_001067B8 (camera sphere push-out; needs a bare sqrt.s), func_001329C0 (ground line test, 13 diffs: entry v0/v1 swap and the to->from copy folded to stack offsets), ChkLine (stepped line test; layout and calls match, register pressure and the piece clamp branch differ). Skipped: func_0012AC98, func_00141678, func_003041B8, func_0010BE18, func_00146328, func_0013AD90, func_00136640 (clamp helper takes 1.0 by reference: stack temporaries), func_0012ED60 (collision grid line probe; stack slot shared between a cVec temporary and the cell-row ints), func_00139180 (decision logged: D_003BD910 handlers take a float t), func_00106BF8 (bare sqrt.s, waits for fpu.h), func_002F2A00 (temporaries shared across switch arms). Reseed elf=OK overlay=OK (also verifies the gameWork.h bgA/bgB unsigned long long bitfields); nm_handoff nothing pending; nm_prune 0 stale. |
| 2026-10-23T08:14:38Z | func_002F62F8 | 1092 | skipped | 0 | 25.4 |
| 2026-10-23T08:15:18Z | func_00303A30 | 1928 | skipped | 0 | 40.3 |
| 2026-10-23T08:15:28Z | func_00149220 | 160 | skipped | 0 | 9.5 |
| 2026-10-23T08:17:42Z | cObjSimple_UpdateHandMesh | 584 | skipped | 1 | 124.4 |
| 2026-10-23T08:28:12Z | func_001F1148 | 576 | matched | 3 | 626.4 |
| 2026-10-23T08:28:42Z | func_002D3750 | 1108 | skipped | 0 | 12.0 |
| 2026-10-23T08:28:58Z | func_002A53A8 | 1272 | skipped | 0 | 15.7 |
| 2026-10-23T08:29:04Z | func_0015D6E8 | 1092 | skipped | 0 | 5.3 |
| 2026-10-23T08:30:32Z | EmClothMove | 216 | matched | 2 | 9.2 |
| 2026-10-23T08:30:49Z | MtxInverse | 356 | skipped | 0 | 7.7 |
| 2026-10-23T08:36:01Z | func_001DFDE0 | 1072 | non-matching | 4 | 304.2 |
| 2026-10-23T08:44:22Z | func_002D6F40 | 1180 | matched | 6 | 496.4 |
| 2026-10-23T08:50:22Z | func_003B63A0 | 0 | skipped | 0 | 0.0 |
| 2026-10-23T08:50:22Z | func_003A4FC8 | 0 | skipped | 0 | 0.0 |
| 2026-10-23T08:50:22Z | func_003A52F0 | 0 | skipped | 0 | 0.0 |
| 2026-10-23T08:50:49Z | func_002993A0 | 1216 | skipped | 0 | 0.0 |
| 2026-10-23T08:56:41Z | Gp_draw_polyG4 | 1096 | non-matching | 5 | 0.0 |
| 2026-10-23T08:56:53Z | func_0031F508 | 1224 | skipped | 0 | 0.0 |
| 2026-10-23T09:04:20Z | cMessDrawFont_draw | 1248 | non-matching | 6 | 0.0 |
| 2026-10-23T09:10:23Z | BATCH | - | batch | - | reseed 331.0; score 3.0 | - | BATCH 161 (coliseum/enemy wrap, cloth, world light, slot machine, Gp_draw, message drawer): 3 registered: func_001F1148 (coliseum devil wave, new src/cod/001f1148.c, fp_hazard_rules mtc1), EmClothMove (new src/cod/002df860.c), func_002D6F40 (world light reset, new src/cod/002d6f40.c, fp_hazard_rules mtc1; retail .s symbolizes two immediates as D_10080/D_16171, words identical, full ELF matches). Drafts: func_001DFDE0 (slot 1 task), Gp_draw_polyG4 (G4 quad packet; loop indexing and call sharing differ), cMessDrawFont_draw (4 insns: one store/lui schedule). Skipped: func_002F62F8, func_00303A30, func_00149220, cObjSimple_UpdateHandMesh (decision filed: cOmBase_childAt count store), func_002D3750, func_002A53A8, func_0015D6E8, MtxInverse, func_003B63A0/func_003A4FC8/func_003A52F0 (handwritten COP0/MMI), func_002993A0 (unmapped 0x140A0 record init), func_0031F508 (libgcc C++ RTTI). Header changes in pending_headers.md Batch 161. Reseed elf=OK overlay=OK. |
| 2026-10-23T09:10:43Z | func_002D45B0 | 1364 | skipped | 0 | 1.1 |
| 2026-10-23T09:10:59Z | func_001B3AB8 | 1452 | skipped | 0 | 1.1 |
| 2026-10-23T09:11:37Z | func_00155DC8 | 1532 | skipped | 0 | 1.1 |
| 2026-10-23T09:13:04Z | func_0031A6B0 | 120 | non-matching | 4 | 1.1 |
| 2026-10-23T09:14:49Z | func_0037C720 | 620 | matched | 3 | 1.1 |
| 2026-10-23T09:15:17Z | cOmSetParam_setOmData | 740 | skipped | 0 | 1.1 |
| 2026-10-23T09:15:25Z | func_0016DC18 | 836 | skipped | 0 | 1.1 |
| 2026-10-23T09:24:42Z | Slot2_StopReels | 1136 | non-matching | 6 | 1.1 |
| 2026-10-23T09:25:42Z | func_00164F30 | 1700 | skipped | 0 | 1.1 |
| 2026-10-23T09:25:44Z | func_00372028 | 1384 | skipped | 0 | 1.1 |
| 2026-10-23T09:26:00Z | func_001E8830 | 1396 | skipped | 0 | 1.1 |
| 2026-10-23T09:26:08Z | func_0039BB20 | 1240 | skipped | 0 | 1.1 |
| 2026-10-23T09:31:35Z | BATCH | - | batch | - | reseed 304.0; score 1.1 | - | batch 162: 1 registered (func_0037C720); drafts func_0031A6B0 (in-place cvt.w.s), Slot2_StopReels (12 diffs); remaining pool is large graphics/libmpeg/IPU code |
| 2026-10-23T09:32:03Z | func_001EBC58 | 424 | skipped | 0 | 1.1 |
| 2026-10-23T09:32:12Z | func_0028A2E8 | 436 | skipped | 0 | 1.1 |
| 2026-10-23T09:36:27Z | func_001E33B0 | 640 | non-matching | 6 | 1.1 |
| 2026-10-23T09:36:38Z | func_001BC300 | 568 | skipped | 0 | 1.1 |
| 2026-10-23T09:36:48Z | func_002C02E8 | 708 | skipped | 0 | 1.1 |
| 2026-10-23T09:36:49Z | func_00123160 | 760 | skipped | 0 | 1.1 |
| 2026-10-23T09:46:47Z | func_0015E510 | 504 | non-matching | 6 | 2.1 |
| 2026-10-23T09:46:48Z | func_0015E8B8 | 528 | non-matching | 6 | 1.1 |
| 2026-10-23T09:49:51Z | func_003A7D08 | 828 | matched | 1 | 1.1 |
| 2026-10-23T09:51:01Z | cSndSeVoice_Setup | 972 | skipped | 0 | 1.1 |
| 2026-10-23T09:57:23Z | func_0013BD40 | 1064 | matched | 4 | 1.1 |
| 2026-10-23T09:59:17Z | func_00276478 | 412 | non-matching | 4 | 1.1 |
| 2026-10-23T10:06:26Z | BATCH | - | batch | - | reseed 305.0; score 1.1 | - | batch 163: 2 registered (func_003A7D08 newlib mbtowc, func_0013BD40 id set display); drafts func_001E33B0, func_0015E510, func_0015E8B8; func_00276478 matches but waits on decisions_needed (unsigned flag macro); cIDBase flags now int, idSet.h and gsLoadImage.h added |
| 2026-10-23T10:08:02Z | func_002A1640 | 1460 | skipped | 0 | 1.1 |
| 2026-10-23T10:08:03Z | func_0029E2C0 | 1568 | skipped | 0 | 1.1 |
| 2026-10-23T10:13:12Z | func_002C90A0 | 1832 | non-matching | 5 | 1.1 |
| 2026-10-23T10:17:37Z | CustomIDWork_Main | 1712 | non-matching | 6 | 1.1 |
| 2026-10-23T10:19:08Z | cOmbe_SetSpeed | 1324 | skipped | 0 | 1.1 |
| 2026-10-23T10:19:25Z | func_001DAEC0 | 1408 | skipped | 0 | 1.1 |
| 2026-10-23T10:21:55Z | func_00149400 | 136 | matched | 2 | 1.1 |
| 2026-10-23T10:21:57Z | func_001504B0 | 136 | matched | 2 | 1.1 |
| 2026-10-23T10:23:12Z | func_00152340 | 184 | non-matching | 3 | 1.1 |
| 2026-10-23T10:24:26Z | func_00158198 | 240 | non-matching | 1 | 1.1 |
| 2026-10-23T10:26:58Z | func_0012CAE0 | 288 | non-matching | 5 | 1.1 |
| 2026-10-23T10:28:19Z | func_001643F8 | 488 | matched | 4 | 1.1 |
| 2026-10-23T10:29:27Z | func_001B48E0 | 312 | non-matching | 2 | 1.1 |
| 2026-10-23T10:31:26Z | func_001B76D8 | 556 | matched | 7 | 1.1 |
| 2026-10-23T10:32:40Z | func_001D4720 | 200 | non-matching | 8 | 1.1 |
| 2026-10-23T10:32:41Z | func_001D47E8 | 200 | non-matching | 8 | 1.1 |
| 2026-10-23T10:35:13Z | func_00148420 | 384 | non-matching | 5 | 1.1 |
| 2026-10-23T10:37:05Z | func_00312E88 | 116 | matched | 1 | 1.1 |
| 2026-10-23T10:38:18Z | func_00313030 | 192 | skipped | 1 | 1.1 |
| 2026-10-23T10:38:19Z | func_00312F70 | 192 | skipped | 1 | 1.1 |
| 2026-10-23T10:38:20Z | func_00313150 | 192 | skipped | 1 | 1.1 |
| 2026-10-23T10:38:21Z | func_00313210 | 192 | skipped | 1 | 1.1 |
| 2026-10-23T10:38:22Z | func_003132D0 | 192 | skipped | 1 | 1.1 |
| 2026-10-23T10:38:23Z | func_00313390 | 192 | skipped | 1 | 1.1 |
| 2026-10-23T10:38:24Z | func_00313450 | 192 | skipped | 1 | 1.1 |
| 2026-10-23T10:38:25Z | func_003077B0 | 52 | skipped | 0 | 1.1 |
| 2026-10-23T10:38:26Z | func_00307840 | 52 | skipped | 0 | 1.1 |
| 2026-10-23T10:38:27Z | func_003077E8 | 52 | skipped | 0 | 1.1 |
| 2026-10-23T10:38:29Z | func_003182D8 | 96 | skipped | 0 | 1.1 |
| 2026-10-23T10:39:35Z | func_002B2E80 | 184 | non-matching | 3 | 1.1 |
| 2026-10-23T10:39:48Z | func_002BF568 | 404 | skipped | 0 | 1.1 |
BATCH 164: 5 registered (func_00149400 and func_001504B0 list reinit into their existing TUs; func_001643F8 menu cursor, new src/cod/001643f8.c, as sn, one forward goto with its label comment; func_001B76D8 cOmBase model upkeep, new src/cod/001b76d8.c; func_00312E88 actor factory, new src/cod/00312e88.c). Drafts: func_00276478 (0x10u flag question), func_002C90A0, CustomIDWork_Main, func_00152340 (alignment held in a variable), func_00158198, func_0012CAE0 (one word, return-1 register reuse), func_001B48E0 (childAt count slot, decision pending), func_001D4720/func_001D47E8 (register assignment), func_00148420, func_002B2E80 (dead owner reload). Skipped: C++ new-expression factories 0x312F70-0x313450, -O0 helpers 0x3077B0-0x307840, static init func_003182D8, func_002BF568, GS filter family, off-limits. Headers: cModel.h trans, cEm00.h hitWait/hitPos, cSceAtManager.h D_005FEA60 + FindNodeByHit, cRecordIndex.h. Prototype fixes in 00149378.c/00150418.c (func_002A9860, EnsureInitThenForward as defined). Reseed anchor func_00312E88: elf=OK overlay=OK (303s). nm_prune: 1 stale draft retired (00312e88.c).
| 2026-10-23T10:47:00Z | func_002FEBE8 | 68 | non-matching | 5 | 1.1 |
| 2026-10-23T10:47:51Z | func_002BECB0 | 84 | non-matching | 4 | 1.1 |
| 2026-10-23T10:50:08Z | func_002BEAA8 | 84 | non-matching | 6 | 1.1 |
| 2026-10-23T10:52:40Z | func_001DF7D0 | 80 | non-matching | 6 | 1.1 |
| 2026-10-23T10:54:15Z | func_002A4BA0 | 84 | non-matching | 6 | 1.1 |
| 2026-10-23T11:06:55Z | func_002831C8 | 116 | matched | 5 | 1.1 |
| 2026-10-23T11:08:17Z | func_00305858 | 128 | matched | 4 | 1.1 |
| 2026-10-23T11:09:41Z | func_0037BE98 | 120 | matched | 2 | 1.1 |
| 2026-10-23T11:10:04Z | func_00376EA0 | 120 | skipped | 0 | 1.1 |
| 2026-10-23T11:10:54Z | func_00377CB8 | 160 | matched | 1 | 1.1 |
| 2026-10-23T11:12:24Z | func_0037FC28 | 160 | matched | 1 | 1.1 |
| 2026-10-23T11:13:43Z | func_0037FF98 | 172 | matched | 1 | 1.1 |
BATCH 165: 6 registered (func_002831C8 cGameObj phase-3 start, new src/cod/002831c8.c, switch on unsigned kind with an inline state setter; func_00305858 effect data slot release, new src/cod/00305858.c; func_0037BE98 sound request queue flush, new src/cod/0037be98.c; func_00377CB8 SPU2 core reset, new src/cod/00377cb8.c; func_0037FC28 file-select open/read, new src/cod/0037fc28.c; func_0037FF98 menu stream format read, into src/cod/00385078.c). Drafts: func_002BEAA8 (typed in 001f7da0.c, 2 words long), func_001DF7D0 (new drafts/cod/001df7d0.c, 3 insns; moved out of 00156550.c), func_002A4BA0 and func_002BECB0/func_002FEBE8 (non-matching). Skipped: func_00376EA0 (channel request has three local types). Headers: cDoor.h jump-table group/table types, seqNode.h SeqCmd 0x50 record + SndCore + prototypes (00377ed0.c SfxPoolA merged into SeqCmd), menuCtl.h MenuDir, cGameObj.h/espSys.h prototypes; callers updated (0037e368.c, 0022af90.c, 0012cc00.c, 001dd218.c, 00193050.c). First reseed rc=1 (00377ed0.c conflicted with the new D_0076B9C0 type; hashes still OK from the cached object), fixed by merging the type; second reseed anchor func_0037FF98: rc=0 elf=OK overlay=OK (302s). nm_handoff: nothing pending. nm_prune: 0 stale.
| 2026-10-23T11:29:25Z | cSnd_IsEnemyAlive | 188 | non-matching | 3 | 1.1 |
| 2026-10-23T11:34:03Z | func_001DC4C0 | 312 | skipped | 1 | 1.1 |
| 2026-10-23T11:35:21Z | func_002BEBC8 | 232 | non-matching | 2 | 1.1 |
| 2026-10-23T11:44:24Z | func_00375318 | 100 | skipped | 0 | 1.1 |
| 2026-10-23T11:49:38Z | func_001C7138 | 468 | non-matching | 5 | 1.1 |
| 2026-10-23T11:50:45Z | func_00394828 | 1004 | skipped | 0 | 1.1 |
| 2026-10-23T11:57:55Z | func_0020EF08 | 1028 | non-matching | 5 | 1.1 |
| 2026-10-23T12:00:19Z | Draw_Poly_sc | 40 | matched | 2 | 1.1 |
| 2026-10-23T12:00:52Z | classFADE_kill | 56 | skipped | 0 | 1.1 |
| 2026-10-23T12:00:53Z | classFADE_status | 68 | skipped | 0 | 1.1 |
| 2026-10-23T12:00:54Z | classFADE_setOt | 76 | skipped | 0 | 1.1 |
| 2026-10-23T12:01:01Z | cOmSub_setEndPos | 1224 | skipped | 0 | 1.1 |
| 2026-10-23T12:01:08Z | Cloth_AddWind | 432 | skipped | 0 | 1.1 |
| 2026-10-23T12:02:41Z | cSceAtUnit_AreaSet | 40 | non-matching | 3 | 1.0 |
| 2026-10-23T12:03:28Z | func_0030F518 | 52 | non-matching | 2 | 1.1 |
| 2026-10-23T12:09:16Z | BATCH | - | batch | - | reseed 310.0; score 1.1 | - | BATCH 166 (cut short for upstream sync; 16 processed): 1 registered (Draw_Poly_sc flat quad wrapper, in src/cod/0015f0.c, which now compiles with sn-2.95.3-136; new drawPrim.h shares Gp_draw_poly4 with 001de7c8.c). Drafts: func_002BEBC8 (new drafts/cod/002bebc8.c, short-loop pad), func_001C7138 (new drafts/cod/001c7138.c, VU0 temporary hoist), func_0020EF08 (new drafts/cod/0020ef08.c, two jump tables, 242 vs 257 words), cSnd_IsEnemyAlive, cSceAtUnit_AreaSet (2 insns, delay-slot order), func_0030F518 (4 insns, conversion order). Skipped: func_001DC4C0, func_00375318 (RPC buffer type), func_00394828 (short-loop pad), classFADE_kill/status/setOt (-O0 g++ this-in-register), cOmSub_setEndPos and Cloth_AddWind (C++ vector temporaries, waiting on decisions_needed). Headers: cOmSub.h vectors 0x70..0xE0, drawPrim.h. Reseed anchor Draw_Poly_sc: rc=0 elf=OK overlay=OK (310s), no compile failures. nm_handoff: nothing pending. nm_prune: 0 stale. |
STEP 0 (2026-10-23T20:17Z, session start): godhand-nix had only its `sleep infinity` init (no permuter, compile.py, cc1 or qemu). Normal build (container_run.sh .venv/bin/python compile.py): ELF 1742f95b…f3cd and overlay ea599323…53c1, both retail. build/scratch had been emptied by the upstream sync, so the held *_ckpt.c files listed in earlier entries are gone; held matches now live in progress/held/.
| 2026-10-23T20:20:00Z | func_00276478 | 412 | matched (held for checkpoint) | 1 | 300.0 | no | enemies (0x276xxx): screen-ghost see-through; decision answered (OBJFLAG_SEE_THROUGH 0x10u); GhostFrame struct replaced by `cVec target; int frame[3];`, D_00747A84 by D_007474A0.flags5E4; held because capVu0MagnitudeSqXZ needs one shared prototype (46 files declare it locally); progress/held/00276478.c |
| 2026-10-23T20:21:00Z | func_001B48E0 | 312 | matched | 1 | 60.0 | no | objects (0x1B4xxx): spinner speed step; decision answered (`int frame[3]`); new src/cod/001b48e0.c, no per-file settings |
| 2026-10-23T20:23:53Z | cObjSimple_UpdateHandMesh | 584 | non-matching | 4 | 169.1 | no | objects (0x2B6xxx): hand mesh select; scratch draft was lost, redone with `int frame[3]`; with case 1 / case 0+default / case 2 and fp_hazard_rules fdiv it is the same length; retail keeps the 10-degree step in $f22 across the calls (only a constant held in a local gives that); draft drafts/cod/002b6da0.c |
| 2026-10-23T20:25:07Z | func_00139180 | 1688 | skipped | 0 | 48.8 | yes | player/camera (0x139xxx): MotionGetParam leaves $f12 untouched (checked), so MotionParamFn and MotionGetParam gain float t (pending_headers); body has the SN C++ VU0 vector temporaries (lqc2/sqc2 through a 0x80(sp) temp around vadd.xyz): skipped until issue #20 is answered |
| 2026-10-23T20:35:04Z | func_0020CD00 | 1080 | non-matching | 3 | 516.2 | yes | enemies (0x20Cxxx): counter-attack decision after a hit; extern_jtbl D_00431EB0 D_00432010; outer and emNo switches match, counterReady roll switch dispatch and the shared constant-1 register differ (184 words); needs cEm00 counterVital/unk17C4/unk17C8, rand.h, cHeatSys D_005CB000 extern, player.h prototype; parked in progress/held/0020cd00_nm.c until the header merge |
| 2026-10-23T20:41:13Z | func_00216760 | 1016 | non-matching | 6 | 359.8 | no | enemies (0x216xxx): grab-attack phase machine, 1 insn off (abs neg source reg); held, needs void func_002A8578 + overlay headers |
| 2026-10-23T20:44:22Z | capVu0Acos | 60 | non-matching | 6 | 108.5 | no | math (0x1F8xxx): acos via atan2(sqrt(1-x*x), x); x register placement differs on sn/ee/cygnus, cygnus tail-calls; held draft |
| 2026-10-23T20:52:58Z | func_00259548 | 1340 | non-matching | 6 | 511.6 | yes | enemies (0x259xxx): knockdown phase machine, extern_jtbl D_00442E30; 4 insns (second stay-down copy store order vs cross-jump); held draft |
| 2026-10-23T21:06:07Z | BATCH | - | batch | - | reseed 61.0; score 1.1 | - | BATCH 167: 3 registered (func_001B48E0 spinner child step, new src/cod/001b48e0.c with int frame[3]; func_001D4720 and func_001D47E8 BlackJack hand totals from nm_handoff, symbol entries added, duplicate compiler line removed). Held (progress/held/, wait on the checkpoint header merge): func_00276478 (matches), drafts func_0020CD00 (184 words), func_00216760 (1 insn, abs negate source), func_00259548 (4 insns, stay-down store order), capVu0Acos (7 insns, x register). Draft cObjSimple_UpdateHandMesh (drafts/cod/002b6da0.c). Skipped func_00139180 (C++ VU0 temporaries; MotionGetParam gains float t). func_002A8578 definition fix held (unsigned short sel/keep, void; MATCH). Reseed anchor func_001D47E8: rc=0 elf=OK overlay=OK (61s). nm_handoff: 2 registered, cMessDrawFont_draw rejected (no compiler meta). nm_prune: 0 stale. session_check: 18 passed, dual_compiler_regress rc=126 (known). |
| 2026-10-23T21:10:32Z | func_0023F028 | 1440 | matched | 3 | 246.6 | yes | enemies (0x23Fxxx): guard phase machine, extern_jtbl D_0043B930; held for overlay headers (cEm00 unk510, cEmManage near-checks, cGameObj func_002A74E0/func_002A7CA0, motion.h, rand.h) |
| 2026-10-23T21:13:09Z | func_00243408 | 1432 | non-matching | 6 | 150.5 | yes | enemies (0x243xxx): enemy 0x211 weapon-throw phase machine, extern_jtbl D_0043C8B0; 2 insns (step 0 float arg copy scheduling); held draft |
| 2026-10-23T21:15:40Z | func_00229D08 | 1360 | matched | 2 | 147.4 | yes | enemies (0x229xxx): rush attack phase machine, extern_jtbl D_004387F0 D_00438820; held for overlay headers (cEm00 ForwardAnimParamPairByIndex_27EA50, cGameObj func_00275888, motion.h) |
| 2026-10-23T21:22:54Z | func_00253DE8 | 1636 | matched | 3 | 428.2 | yes | enemy flinch (cEm00) |
| 2026-10-23T21:23:38Z | func_0020D398 | 1660 | skipped | 0 | 30.1 | yes | enemies (0x20Dxxx): counter decision sibling of func_0020CD00 (parked NM); same switch-tree shape, deferred |
| 2026-10-23T21:31:13Z | func_00231300 | 1984 | non-matching | 2 | 454.7 | yes | enemies (0x231xxx): approach-and-strike phase machine; 2 insns (abs of Turn_dest angle, same as func_00216760); needs fp_hazard_rules cmppad; held |
| 2026-10-23T21:32:37Z | func_0025F1F0 | 2088 | skipped | 0 | 62.0 | yes | enemies (0x25Fxxx): death phase machine; needs cEm00.fx5 (0x704) retyped as a weapon pointer, asked in decisions_needed.md |
| 2026-10-23T21:33:09Z | func_001AB168 | 1480 | skipped | 0 | 26.3 | yes | objects (0x1ABxxx): attack phase machine; builds a 6-row table of 12-byte motion triples through by-value temporaries (ldl/sdl copies), likely SN C++ struct returns; deferred |
| 2026-10-23T21:35:08Z | func_00233DD8 | 1424 | skipped | 0 | 77.6 | yes | enemies (0x233xxx): attack phase machine; uses cEm00.fx0 (0x6F0) as an object pointer, asked in decisions_needed.md |
| 2026-10-23T21:40:32Z | func_00224A28 | 1764 | matched | 2 | 324.0 | yes | enemies (0x224xxx): grab rush phase machine, extern_jtbl D_004384A0 D_004384C0 D_004384E0, per-file as: sn (retail's hazard nop after a threaded label); one float local holds the Turn_dest angle and then the turn rate, as retail's f20; held |
| 2026-10-23T21:41:24Z | func_0020DCF0 | 1936 | skipped | 0 | 16.1 | yes | enemies (0x20Dxxx): hit-reaction dispatcher over cDamageTake.kind; heavy cross-jumped tails and calls the unmatched func_0020CD00/func_0020D398; deferred until those match |
| 2026-10-23T21:46:54Z | func_00216078 | 1764 | non-matching | 1 | 321.3 | yes | enemies (0x216xxx): jump phase machine; draft progress/held/00216078_nm.c, 2 insns in step 2 plus step 7's merged identical-arm gravity update (decision filed) |
| 2026-10-23T21:46:58Z | func_002294E0 | 0 | skipped | 0 | 3.9 | no | enemies (0x229xxx): SN C++ VU0 vector temporaries (qmtc2/vmulx on stack copies), waiting on issue #20 |
| 2026-10-23T22:17:07Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 168 (enemies 0x20D000-0x25FFFF): 0 registered (no reseed: nothing new in src/). Held matches (progress/held/, register at the checkpoint): func_00253DE8 flinch, func_00224A28 grab rush (as: sn). Held drafts: func_00231300 (2 insns, abs negate source; as: sn), func_00216078 (2 insns in step 2 plus step 7's identical-arm gravity update, decision filed). Skipped: func_0020D398 (counter sibling of 0020CD00), func_0025F1F0 and func_00233DD8 (fx0/fx5 retype decision), func_001AB168 and func_002294E0 (SN C++ VU0 temporaries, issue #20), func_0020DCF0 (dispatcher over unmatched 0020CD00/0020D398). Overlay header additions listed under Batch 168 in pending_headers.md. nm_handoff: func_00276478 verified (held). nm_prune: 0 stale. session_check (container): 18 passed, 7 skipped, dual_compiler_regress rc=126 (known, as in batch 167); host session_check needs the container (no mipsel-linux-gnu-as on the host). |
| 2026-10-23T22:17:45Z | func_0027A320 | 0 | skipped | 0 | 0.0 | no | enemies: SN C++ VU0 vector temporaries (operator result copied through a stack temporary, self-assignment check), waiting on issue #20 |
| 2026-10-23T22:17:45Z | func_0027AE10 | 0 | skipped | 0 | 0.0 | no | enemies: SN C++ VU0 vector temporaries (operator result copied through a stack temporary, self-assignment check), waiting on issue #20 |
| 2026-10-23T22:17:45Z | func_002299C0 | 0 | skipped | 0 | 0.0 | no | enemies: SN C++ VU0 vector temporaries (operator result copied through a stack temporary, self-assignment check), waiting on issue #20 |
| 2026-10-23T22:18:24Z | func_00107F58 | 2904 | skipped | 0 | 21.6 | yes | player (0x107xxx): player init; needs a player object header (fields 0x548..0x1620, mesh pointers 0x1550..0x1574, damage units 0x5B0..0x5D4) and the full cDamageUnit_AddDamageCollSphere/Cylinder signatures (retail passes 8 and 10 arguments, cOmHitVolumeSetup.h declares 4); deferred to a header pass |
| 2026-10-23T22:30:34Z | BlackJack_UpdateOpeningDeal | 2392 | non-matching | 5 | 721.9 | yes | casino (0x1D1xxx): blackjack opening deal; draft progress/held/001d1f30_nm.c (fp_hazard_rules fdiv,mtc1). Hand B loop register allocation, layout store order and a movn differ; vec4_set_point and the inline slide fraction fixed the slide steps |
| 2026-10-23T22:30:57Z | Gp_draw_poly4 | 1136 | skipped | 0 | 17.5 | yes | draw (0x15Bxxx): GS poly packet builder; 64-bit GIF tag packing, retail spills three arguments to the frame, frustum checks on the RotTransPers results; deferred with the other GS packet builders |
| 2026-10-23T22:39:16Z | func_001B4528 | 948 | matched | 1 | 449.9 | yes | gimmick (0x1B4xxx): path mover blade grow/shrink; held progress/held/001b4528.c (as: sn, cOmBase_childAt frame[3]); clamp written as default 0 then take the roll when non-negative |
| 2026-10-23T22:39:16Z | func_0015C410 | 0 | skipped | 0 | 0.0 | no | draw (0x15Cxxx): GS packet builder with 12 arguments; deferred with the other GS packet builders |
| 2026-10-23T22:39:41Z | func_001B5B30 | 876 | skipped | 0 | 0.0 | no | gimmick (0x1B5xxx): SN C++ VU0 vector temporaries (vector sum through a stack temporary before the vcall), waiting on issue #20 |
| 2026-10-23T22:39:51Z | func_001A9210 | 884 | skipped | 0 | 0.0 | no | gimmick (0x1A9xxx): SN C++ VU0 vector temporaries (vmulx/vadd through stack temporaries), waiting on issue #20 |
| 2026-10-23T22:40:39Z | func_00176D60 | 1148 | skipped | 1 | 0.0 | yes | objects (0x176xxx): damage volume setup; the cOmBase_childAt count stores land in different frame slots (0x20, 0x60) that later hold vectors, and the range check is the andi 0xFF bool form; same wall as func_00194080 and func_001BCD70 |
| 2026-10-23T22:45:25Z | func_00147C88 | 1240 | non-matching | 3 | 190.6 | yes | math (0x147xxx): matrix to Euler angles for six axis orders; draft progress/held/00147c88_nm.c (as: sn). Only the divide pad nops differ: retail pads each run of div.s once (two nops), one nop where the divide reads a neg.s; fdiv pads every div.s (346 words vs 310) |
| 2026-10-23T22:46:58Z | MtxGetScaleVec | 160 | non-matching | 3 | 74.0 | no | math (0x148xxx): matrix axis lengths; draft progress/held/00148160_nm.c (sqrt rule, -ffast-math to drop the errno call). Retail does not interleave the three row sums; no supported flag stops the scheduler |
| 2026-10-23T22:47:18Z | func_001ABE80 | 1260 | skipped | 0 | 0.0 | yes | gimmick cOm5a (0x1ABxxx): setup adds a float to a vector with qmtc2 + vaddx (SN C++ VU0 operator), waiting on issue #20 |
| 2026-10-23T22:47:26Z | func_001C9AF0 | 1356 | skipped | 0 | 0.0 | yes | gimmick (0x1C9xxx): falling object; vector copies go through the SN C++ operator= self-assignment check, waiting on issue #20 |
| 2026-10-23T22:47:35Z | func_002C1618 | 1220 | skipped | 0 | 0.0 | yes | scene action units (0x2C1xxx): player probe vector goes through the SN C++ operator= self-assignment check, waiting on issue #20 |
| 2026-10-23T23:32:24Z | cScrSpriteDraw_drawRectLine | 1280 | non-matching | 6 | 2535.0 | yes | screen draw (0x2C6xxx): rotated rectangle outline; draft progress/held/002c6840_nm.c. Same length, 44 insns differ (h*cos/h*sin registers, vertex store schedule); ordering the case 4 vertices v0 v1 v3 v2 lets the shared tail stay in case 2 as retail |
| 2026-10-23T23:33:04Z | cCoreSave_translateSaveItem | 492 | skipped | 0 | 0.0 | yes | save (0x2xxxxx): item position transform goes through SN C++ vector temporaries (lqc2/sqc2 copies, self-assignment check), waiting on issue #20 |
| 2026-10-23T23:35:49Z | func_002D81A0 | 252 | non-matching | 4 | 110.1 | yes | world light (0x2D8xxx): fog colour and range; draft progress/held/002d81a0_nm.c. cvt.w.s is plain (int); retail forms self + 0x10000 again per channel, ours once (no supported flag or spelling changes it) |
| 2026-10-23T23:35:58Z | func_002D8070 | 300 | skipped | 0 | 0.0 | yes | world light (0x2D8xxx): fog colour and fog level for a depth; same per-channel self + 0x10000 addressing as the func_002D81A0 draft, left with it |
| 2026-10-23T23:36:39Z | cEmSetParam_updateSetDataPos | 128 | skipped | 0 | 0.0 | yes | enemy set table: the NM closer holds drafts/cod/00295380.c, and the entry record is blocked on the cEmSetEntry/cRoomSaveEm merge (pending_headers) |
| 2026-10-23T23:42:49Z | func_00245A18 | 1644 | non-matching | 5 | 0.0 | yes | enemies (0x245xxx): spinning attack phase machine; draft progress/held/00245a18_nm.c is byte-identical under NON_MATCHING but needs identical if/else arms in step 4, per-level switch cases and the fx5 pointer (decisions_needed) |
| 2026-10-23T23:48:52Z | func_0025DE58 | 1008 | matched | 3 | 0.0 | yes | enemies (0x25Dxxx): held by the player; progress/held/0025de58.c (extern_jtbl D_00443A80), register at the checkpoint. Matched with func_002A8578's float as the fifth parameter |
| 2026-10-23T23:48:52Z | func_00243408 | 1432 | matched | 1 | 0.1 | yes | enemies (0x243xxx): weapon throw; the 2-instruction draft matches once func_002A8578 takes the float fifth; progress/held/00243408.c (extern_jtbl D_0043C8B0) |
| 2026-10-23T23:49:43Z | func_0025B158 | 1100 | skipped | 0 | 0.0 | yes | enemies (0x25Bxxx): knocked-back phase machine; step 3 is an SN C++ VU0 vector temporary (sqc2 tmp, qmtc2, vmulx, stack copy), waiting on issue #20 |
| 2026-10-23T23:49:53Z | func_0025D0B8 | 0 | skipped | 0 | 0.0 | no | enemies: SN C++ VU0 vector temporaries (qmtc2/vmul on stack copies), waiting on issue #20 |
| 2026-10-23T23:49:53Z | func_0022F698 | 0 | skipped | 0 | 0.0 | no | enemies: SN C++ VU0 vector temporaries (qmtc2/vmul on stack copies), waiting on issue #20 |
| 2026-10-23T23:49:53Z | func_0024A0B0 | 0 | skipped | 0 | 0.0 | no | enemies: SN C++ VU0 vector temporaries (qmtc2/vmul on stack copies), waiting on issue #20 |
| 2026-10-23T23:49:53Z | func_00248738 | 0 | skipped | 0 | 0.0 | no | enemies: SN C++ VU0 vector temporaries (qmtc2/vmul on stack copies), waiting on issue #20 |
| 2026-10-23T23:49:53Z | func_00248058 | 0 | skipped | 0 | 0.0 | no | enemies: SN C++ VU0 vector temporaries (qmtc2/vmul on stack copies), waiting on issue #20 |
| 2026-10-23T23:49:53Z | func_0022D938 | 0 | skipped | 0 | 0.0 | no | enemies: SN C++ VU0 vector temporaries (qmtc2/vmul on stack copies), waiting on issue #20 |
| 2026-10-23T23:49:54Z | func_0022DFF0 | 0 | skipped | 0 | 0.0 | no | enemies: SN C++ VU0 vector temporaries (qmtc2/vmul on stack copies), waiting on issue #20 |
| 2026-10-23T23:50:29Z | func_0012DEF0 | 1752 | skipped | 0 | 0.0 | yes | collision debug draw (0x12Dxxx): box edges from rodata vertex tables copied with ldl/sdr into stack arrays plus a pointer table, two 10-case switches; deferred |
| 2026-10-23T23:50:57Z | func_002F7240 | 1752 | skipped | 0 | 0.0 | yes | effects (0x2F7xxx): ribbon vertex setup; SN C++ vector operator= self-check copies (if (&dst != &tmp)), waiting on issue #20 |
| 2026-10-23T23:51:35Z | func_002FE0D8 | 1992 | skipped | 0 | 0.0 | yes | effects (0x2FExxx): billboard corner projection and screen clip test, sibling of func_002FDE60 (issue #20 temporaries); about 2000 bytes with MtxCopy chains, deferred |
| 2026-10-24T00:04:12Z | func_001A9A30 | 1572 | skipped | 0 | 0.0 | yes | object setup (0x1A9xxx): damage/collision volumes; cOmBase_childAt count stores share the stack slot of a later cVec (childAt slot wall, as func_00176D60) and a 0x60-byte rodata table copied to the stack |
| 2026-10-24T00:04:37Z | func_001BEBA0 | 1856 | skipped | 0 | 0.0 | yes | reward chest (0x1BExxx): random prize from a 9-entry rodata table copied to the stack, nested save-data availability checks, god reel/skill grant; deferred (table initializer placement unverified) |
| 2026-10-24T00:13:19Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 169 (cvt.w.s re-gate leftovers, enemies over 800 B, player/effects screen): 0 registered (no reseed: nothing new in src/). Held matches (progress/held/, register at the checkpoint): func_001B4528 path blade (as: sn), func_0025DE58 enemy held by the player (extern_jtbl D_00443A80), func_00243408 weapon throw (extern_jtbl D_0043C8B0; the old 2-insn draft closes once func_002A8578 takes its float fifth, which every held user and the held definition now use). Held drafts: func_00147C88 (div pad tooling gap), MtxGetScaleVec, cScrSpriteDraw_drawRectLine, func_002D81A0 (per-channel self + 0x10000 addressing), func_00245A18 (byte-identical but needs identical if/else arms and per-level cases; decision filed), BlackJack_UpdateOpeningDeal. Skipped: SN C++ VU0 temporaries (issue #20) x10, childAt slot wall x3, GS packet builders, the 0x2D8070 fog sibling, the NM closer's cEmSetParam_updateSetDataPos draft, large debug/reward/billboard functions. Overlay header additions under Batch 169 in pending_headers.md. nm_handoff: func_00276478 verified (held). nm_prune: 0 stale. session_check (container): 18 passed, 7 skipped, dual_compiler_regress rc=126 (known). |
| 2026-10-24T00:26:06Z | func_001E0840 | 1128 | non-matching | 5 | 4.6 | yes | slot machine (0x1E0xxx): Slot1 spin stage (bonus draw, board and reel start); draft progress/held/001e0840_nm.c differs only in which s-registers hold the 8/1 compares and the D_005E8140 address (fp vs s6); needs Slot1.h overlay (reel/panel records), SlotUi.h Slot_tick, padWork.h, scrollLayer.h |
| 2026-10-24T00:29:36Z | func_001D8480 | 1812 | matched | 2 | 204.7 | no | casino poker (0x1D8xxx): deal stage (draw the hand, fly the five cards in, turn them over); held progress/held/001d8480.c (extern_jtbl D_0042B280, fp_hazard_rules fdiv); needs the Poker.h overlay (callee prototypes, D_00568160/D_00568170) and cSnd.h cSnd_SeCall_2CBA48 |
| 2026-10-24T00:31:03Z | func_001D94D0 | 2000 | matched | 2 | 81.1 | no | casino poker (0x1D9xxx): draw stage (slide the thrown cards off, draw and fly in the replacements, turn all five over); held progress/held/001d94d0.c (extern_jtbl D_0042B2B0, fp_hazard_rules fdiv); shares Poker_placeCard/Poker_moveCard with func_001D8480 in the Poker.h overlay |
| 2026-10-24T00:31:30Z | func_00168AB8 | 1952 | skipped | 0 | 27.5 | no | casino screen (0x168xxx): per-frame update of the casino entrance screen (panel flags, stage-unlock count over the D_0042AD58 records, mode jump table D_0041FCE0); needs the screen record (child panels at 0x88..0x1B4) typed first, too large for this batch |
| 2026-10-24T00:31:52Z | func_001410A8 | 1516 | skipped | 0 | 21.9 | no | stage manager (0x141xxx): DispMgr per-frame state machine (21-entry table D_0041E5B0, fades, pad stop, SE fades); DispMgr is only a local view in 00140c88.c, needs a shared header first, too large for this batch |
| 2026-10-24T00:32:00Z | func_002A10E8 | 1376 | skipped | 0 | 7.9 | no | GS packets (0x2A1xxx): builds a GIF register packet with 64-bit field packing (PushEntryAtField10000_299868); GS packet builder, left with the others of its kind |
| 2026-10-24T00:32:51Z | func_001D8B98 | 2360 | skipped | 0 | 43.4 | no | casino poker (0x1D8xxx): hold-select stage; blocked on callee definitions SetBlendField4BCColor_1DDC60 and func_001DEB08 taking more arguments than retail passes (decisions_needed) |
| 2026-10-24T00:36:16Z | func_001DAB00 | 788 | non-matching | 4 | 204.7 | no | casino poker (0x1DAxxx): double-up draw (rigged or random second card, fly it in, turn it over); draft progress/held/001dab00_nm.c differs only in the out-of-deck bit clear (addiu -2 needs a signed BlackJackCard.flags; decisions_needed) |
| 2026-10-24T00:40:18Z | func_001DAEC0 | 1408 | matched | 1 | 235.6 | no | casino/poker |
| 2026-10-24T00:42:29Z | func_0015E708 | 432 | matched | 1 | 56.1 | no | GS image upload (0x15Exxx) |
| 2026-10-24T00:44:34Z | func_00155678 | 392 | matched | 2 | 111.3 | no | model packet builder (0x155xxx) |
| 2026-10-24T00:44:44Z | func_00155358 | 796 | skipped | 0 | 9.8 | no | model packet builder (0x155xxx): whole-model packet; retail keeps the 0x0FFFFFFF DMA address mask in a stack word (4(sp), beside the PackRef base at 0(sp)) and reloads it; no plain C form keeps a constant in memory |
| 2026-10-24T00:57:19Z | func_00151CC0 | 736 | non-matching | 3 | 755.0 | no | texture bank (0x151xxx): load a one-picture TIM2 into the bank; draft progress/held/00151cc0_nm.c (36 insns: w/type s5/fp swap, CSA clear placement) |
| 2026-10-24T00:57:33Z | func_00151FA0 | 796 | skipped | 0 | 0.0 | no | texture bank (0x151xxx): multi-picture bank file (shared 4-bit image at +0x10, per-picture TIM2 headers through an offset table); the file record is untyped and its sibling 00151CC0 already stalls on s-register choice with the same TEX0 build |
| 2026-10-24T01:02:39Z | func_00294488 | 1040 | matched | 4 | 0.0 | no | enemy manager (0x294xxx): line the special enemies up |
| 2026-10-24T01:03:27Z | cEmManage_GetTargetNear | 1540 | skipped | 0 | 41.5 | no | enemy manager (0x290xxx): target search over the enemy list and the object list; deferred for size (two search loops, six fabs/compare forms), retry after the smaller enemy-manager functions |
| 2026-10-24T01:03:55Z | func_001A26C0 | 996 | skipped | 0 | 0.0 | no | object init (0x1A2xxx): child offsets built through a zeroed vector temporary (sqc2 vf0, vsub into a temp, copy out) like the SN C++ vector temporaries waiting on issue #20; siblings func_00196188 and func_001977B0 have the same shape |
| 2026-10-24T01:11:03Z | func_002EFD20 | 512 | non-matching | 6 | 0.0 | no | effect emitter (0x2EFxxx): start the emitter effect at the node; 7 diffs, a v0/v1 swap for effArg/effFlags; parked as progress/held/002efd20_nm.c (start row lost; time not recorded) |
| 2026-10-24T01:11:26Z | func_002F7918 | 880 | skipped | 0 | 1.1 | no | effect trail (0x2F7xxx): trail point shift with vsub/vmulx/vadd through stack vector temporaries (SN C++ VU0 temporaries, issue #20) |
| 2026-10-24T01:18:08Z | func_002E64B0 | 952 | non-matching | 6 | 205.2 | no | ground effect object esp04 (0x2E6xxx): set-up and EST checks; one delay slot (beql vs beq around cObj_setMeshValue); parked as progress/held/002e64b0_nm.c |
| 2026-10-24T01:19:21Z | func_002EAAA8 | 1224 | skipped | 0 | 0.0 | no | sprite screen projection (0x2EAxxx): four matrix set-ups with block-scoped matrices sharing the 0x40 slot with the corner vector, reached through a pointer in some paths and directly in others; deferred until the slot sharing is understood |
| 2026-10-24T01:20:02Z | cWorldLight_Light_curent_set | 1032 | skipped | 0 | 0.0 | no | world light (0x2D8xxx): preset apply plus light-list compaction through a record temporary whose three vectors are zeroed with sqc2 vf0 (SN C++ constructor of the vector members, issue #20) |
| 2026-10-24T01:51:30Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 170 (poker/GS upload/model packets/enemy manager/effect objects): 0 registered (no reseed: nothing new in src/). Held matches (progress/held/, register at the checkpoint): func_001DAEC0 poker win stage (extern_jtbl D_0042B3A0, fdiv, as sn), func_0015E708 GS 4/8-bit image upload (as sn), func_00155678 model record packet (as sn), func_00294488 special-enemy line-up (extern_jtbl D_0044A830), plus func_001D8480/func_001D94D0 from earlier in the batch. Held drafts: func_00151CC0 TIM2 bank load (36 insns, s5/fp swap), func_002EFD20 effect emitter (7 insns, v0/v1 swap), func_002E64B0 ground effect set-up (one delay slot), func_001E0840, func_001DAB00. Skipped: func_00155358 (mask kept in a stack word), func_00151FA0 (untyped record), cEmManage_GetTargetNear (size), func_001A26C0 and func_002F7918 and cWorldLight_Light_curent_set (SN C++ VU0 temporaries, issue #20), func_002EAAA8 (stack slot sharing). The game range below 0x322000 has no untried function under 700 bytes left. Overlay header additions under Batch 170 in pending_headers.md. nm_handoff: func_00276478 verified (held). nm_prune: 0 stale. session_check (container): 18 passed, 7 skipped, dual_compiler_regress rc=126 (known; passes when run alone). ELF hash 1742f95b... OK. |
| 2026-10-24T01:57:00Z | func_002C5548 | 1672 | matched | 5 | 103.1 | no | screen sprite draw (0x2C5xxx): rotated sprite from the sprite table, five anchors, scaled about the centre line (extern_jtbl D_0044C2E0, fp_hazard_rules mtc1) |
| 2026-10-24T02:02:10Z | func_002C5EA8 | 1704 | non-matching | 6 | 234.6 | yes | screen sprite draw (0x2C5xxx): textured rotated quad; 8 insns differ (retail converts each colour channel in place, cvt.w.s $f0,$f0; ours into $f1) |
| 2026-10-24T02:18:51Z | func_002C70A8 | 1960 | non-matching | 6 | 789.3 | no | screen sprite draw (0x2C7xxx): decimal number from digit glyphs; 5 insns differ (last ladder step folded to movn, minus-flag reload in v1); needs fp_hazard_rules mtc1 and as_flags -g |
| 2026-10-24T02:23:17Z | cOmSetParam_setOmData | 640 | skipped | 0 | 7.8 | no | object set (0x1C3xxx): blocked on callee definitions that disagree with this caller: CreateObj (00306200.c takes one int, player.h two), cOmItem_setFixPos (takes one arg, called with the set entry too), D_005E8658 typed both cEmSetTable and cRoomSave |
| 2026-10-24T02:23:27Z | func_0016DC18 | 800 | skipped | 0 | 0.4 | no | results screen (0x16Dxxx): SN C++ VU0 vector temporaries (array of four zero-constructed vectors, issue #20) |
| 2026-10-24T02:27:51Z | cScrSpriteDraw_drawRectLine | 1280 | non-matching | 6 | 6.8 | yes | screen draw (0x2C6xxx): retry with the func_002C5548 lessons, 44 -> 2 insns (v[3] before v[2] in cases 1-3, h*s halved first); only the closing-copy loop setup order differs; draft progress/held/002c6840_nm.c |
| 2026-10-24T02:39:06Z | Gp_draw_polyFT4 | 1820 | non-matching | 6 | 1.1 | no | draw (0x15Bxxx): textured quad GS packet; draft progress/held/0015bcf0_nm.c, 3 insns short; blockers: vu0-call vertex address not strength-reduced in retail (same as the NM closer's Gp_draw_polyG4 draft), 64-bit TBP0 add |
| 2026-10-24T02:39:49Z | func_0015D168 | 1408 | skipped | 0 | 0.6 | no | draw (0x15Dxxx): textured sprite GS packet (two-vertex sibling of Gp_draw_polyFT4); retail keeps two identical func_0031A650 calls for screen and world sprites, an identical-arms form (see the func_00245A18 question) |
| 2026-10-24T02:47:28Z | func_001A2E88 | 1556 | non-matching | 3 | 1.0 | yes | gimmick break sequence; childAt byte-flag range check not reproducible with cOmBase_childAt |
| 2026-10-24T02:56:47Z | func_001AF230 | 1024 | non-matching | 5 | 1.0 | yes | rising floor trap; 1 insn: abs.s scheduling vs mtc1 slot |
| 2026-10-24T02:58:31Z | cObjSimple_MoveBust | 860 | skipped | 0 | 0.4 | yes | simple object (0x2B6xxx): bust sway; SN C++ VU0 vector temporaries (vf0-constructed locals copied through lqc2/sqc2), waiting on issue #20 |
| 2026-10-24T03:20:12Z | iGetTimerSystemTime | 76 | skipped | 2 | 0.0 | no | libkernel timer (0x3B7xxx): retail is hand-scheduled assembly (t0-t2 in a leaf, the same block inlined verbatim into GetTimerSystemTime, lwu reads); no plain C form, ee/sn/cygnus all tried |
| 2026-10-24T03:20:12Z | GetTimerSystemTime | 124 | skipped | 2 | 0.0 | no | libkernel timer (0x3B7xxx): retail is hand-scheduled assembly (t0-t2 in a leaf, the same block inlined verbatim into GetTimerSystemTime, lwu reads); no plain C form, ee/sn/cygnus all tried |
| 2026-10-24T03:22:53Z | sceSifInitRpc | 412 | matched | 3 | 1.2 | yes | SIF RPC (0x3B2xxx): RPC init; held progress/held/003b2900.c until sif.h/eeKernel.h land at the checkpoint |
| 2026-10-24T03:24:24Z | _doMC | 540 | matched | 1 | 1.2 | yes | libmpeg (0x39Dxxx): motion compensation dispatch; registered src/cod/0039d398.c |
| 2026-10-24T03:29:59Z | _getRef0 | 1160 | non-matching | 6 | 1.3 | yes | libmpeg (0x39Cxxx): queue luma/chroma prediction; 285/290 words, spill choice differs; held progress/held/0039cf10_nm.c |
| 2026-10-24T03:30:31Z | iAllocTimerCounter | 112 | non-matching | 5 | 7.2 | yes | libkernel timer (0x3B7xxx): allocate a timer counter; 18 store-order diffs after a 720-order search; held progress/held/003b7130.c |
| 2026-10-24T03:30:32Z | _sceSifSendCmd | 308 | non-matching | 5 | 1.2 | yes | SIF cmd (0x3B2xxx): send a SIF command; 21 store-order diffs, no order of the six header stores closes it; held progress/held/003b2550.c |
| 2026-10-24T03:32:37Z | func_00148690 | 1352 | skipped | 0 | 0.0 | yes | model texture bind (0x148xxx): four loops patch each mesh's TEX0 (CBP + node offset, TFX); the first and last arms of the flag chain are identical in retail, which the identical-branch ruling rules out |
| 2026-10-24T03:32:46Z | func_001B3AB8 | 1452 | skipped | 0 | 0.0 | yes | object setup (0x1B3xxx): three damage volumes built through the cOmBase_childAt count-store idiom (count saved to the frame), same block as 001A2E88 |
| 2026-10-24T03:49:46Z | BATCH | - | batch | - | reseed 42.0; score 3.0 | - | BATCH 171 (scrsprite/draw, gimmicks, SIF RPC, libkernel timer, libmpeg MC): 1 registered: _doMC (libmpeg motion compensation dispatch, new src/cod/0039d398.c, ee-2.9-991111). Held matches: func_002C5548 (extern_jtbl D_0044C2E0, mtc1), sceSifInitRpc (needs sif.h/eeKernel.h). Held drafts: _getRef0 (285/290, spill choice), func_001AF230 (1 insn, abs.s placement), func_001A2E88 (22 insns, childAt byte flag), _sceSifSendCmd (21, store order), iAllocTimerCounter (18, store order), func_002C5EA8, func_002C70A8, cScrSpriteDraw_drawRectLine, Gp_draw_polyFT4. Skipped: iGetTimerSystemTime/GetTimerSystemTime (hand-written asm), func_00148690 (identical arms in retail), func_001B3AB8 (childAt count stores), cObjSimple_MoveBust, cOmSetParam_setOmData, func_0016DC18, func_0015D168. Overlay additions under Batch 171 in pending_headers.md. reseed anchor _doMC rc=0 elf=OK overlay=OK. nm_handoff: func_00276478 verified (held). nm_prune: 0 stale. session_check (container): 18 passed, 7 skipped, dual_compiler_regress rc=126 (known). |
| 2026-10-24T03:51:35Z | func_00375318 | 100 | matched | 2 | 1.1 | no | sound driver (0x375xxx): RPC start-up; held progress/held/00375318.c until the SndRpc record (sndBank.h) and SeqOwnerCtl (seqNode.h) land at the checkpoint |
| 2026-10-24T03:52:42Z | func_00376EA0 | 120 | matched | 2 | 19.6 | no | sound driver (0x376xxx): run the queued channel requests; held progress/held/00376ea0.c until SndChReq (seqNode.h) lands at the checkpoint |
| 2026-10-24T03:53:10Z | func_0037FAC8 | 164 | skipped | 0 | 0.0 | no | menu (0x37Fxxx): stream entry open; the entry it passes to func_00380EB0 isn't a MenuList (decisions_needed.md) |
| 2026-10-24T03:54:29Z | func_00380F80 | 140 | matched | 3 | 54.3 | no | menu stream (0x380xxx): stream error check and list rebuild; held progress/held/00380f80.c until the menuCtl.h prototypes land |
| 2026-10-24T03:55:56Z | func_00384BC8 | 144 | matched | 1 | 12.6 | no | sound debug page (0x384xxx): print a track's mute state; held progress/held/00384bc8.c until the menuCtl.h fields and dbgText.h land |
| 2026-10-24T03:56:49Z | func_00382520 | 132 | matched | 1 | 7.9 | no | sound mixer page (0x382xxx): all tracks at the picked volume?; held progress/held/00382520.c until SndMixer (menuCtl.h) lands |
| 2026-10-24T04:01:01Z | func_00376438 | 208 | non-matching | 8 | 187.9 | yes | sound script stepper (0x376xxx): 42 diffs, retail duplicates the wait test after each command load; held progress/held/00376438_nm.c (SndScript record, handlers in 003766f8.c/00376708.c/00366918.c use raw offsets) |
| 2026-10-24T04:03:00Z | func_003182D8 | 96 | matched | 1 | 8.4 | no | static initialiser (0x318xxx): two arenas, the side counter, the object list; held progress/held/003182d8.c until the heapArena.h/sideCounter.h/cMc.h additions land |
| 2026-10-24T04:05:57Z | func_001DC4C0 | 312 | non-matching | 5 | 133.3 | yes | poker four-of-a-kind marker; 5 prologue insns differ (argument address order); held progress/held/001dc4c0_nm.c, needs Poker.h func_001DBFB8 prototype |
| 2026-10-24T04:09:34Z | func_002BF568 | 404 | skipped | 3 | 80.1 | yes | scenario step reset (0x2BFxxx): retail anchors GameWork at +0x5E4 and keeps 1 in s0; typed D_007474A0 fields anchor at the base (97 diffs); the old match needed pointer arithmetic from &flags5E4 and a 'one' local, both banned. Needs func_001FFF30 a1 as unsigned short (callers pass lhu unmasked) |
| 2026-10-24T04:13:51Z | func_001F3DF0 | 480 | non-matching | 4 | 86.2 | yes | coliseum enemy pick (0x1F3xxx): extern_jtbl D_0042BF70; 2 diffs (lh vs lhu on the emA/emB copy); held progress/held/001f3df0_nm.c; decision filed; needs ColiseumEmSelect.h (step, entry, emA/emB, ColiseumPick D_00568240, close prototype) and cScenario.h cScenario_beginRoomJump_2C4548 prototype overlays |
| 2026-10-24T04:13:55Z | Fil_clut_set | 760 | skipped | 0 | 0.0 | yes | filter CLUT (render 0x2A3xxx): retail keeps a dead 'lw tbl[i]; srl 25' at the top of the case-3 loop (result overwritten by alpha = 0); plain C drops it, and only dead code reproduces it |
| 2026-10-24T04:21:40Z | func_00394828 | 1004 | matched | 6 | 354.8 | yes | module loader (0x394xxx): relocate a loaded table (pointer fix-ups, entry resolve, packed HI16/LO16 relocations, symbol relocations, list link); extern_jtbl D_0045DBC0; held progress/held/00394828.c until the regTbl.h overlay lands |
| 2026-10-24T04:22:11Z | cOmbe_SetSpeed | 1324 | skipped | 0 | 0.0 | yes | cOmbe launch setup (0x1BBxxx): retail keeps cases 12/13 and 3/19 as separate blocks with identical bodies (separate jump-table targets); waits on the identical-case question (func_00245A18 (2) / func_0020EF08) |
| 2026-10-24T04:25:48Z | func_0039BB20 | 1240 | matched | 4 | 124.5 | yes | libmpeg (0x39Bxxx): send the decoded picture to the IPU (chained through the channel 4 handler past 0xFFFF qw) and colour-convert it; ee-2.9; held progress/held/0039bb20.c until the sceMpeg.h/eeKernel.h overlays land |
| 2026-10-24T04:30:19Z | func_0039B960 | 448 | non-matching | 6 | 231.1 | no | libmpeg CSC |
| 2026-10-24T04:33:18Z | func_001B8030 | 32 | hard-tail | 6 | 73.3 | no | item id range test: best form slti+xori+beq vs retail slti+bnez, 4 insns |
| 2026-10-24T04:33:29Z | func_00123908 | 48 | skipped | 0 | 10.7 | no | drafts/cod/00123908.c belongs to the NM closer |
| 2026-10-24T04:35:05Z | func_001C2328 | 68 | non-matching | 6 | 77.5 | no | step switch: one missing nop between slti and bnez |
| 2026-10-24T04:37:21Z | func_002AD108 | 168 | matched | 4 | 136.3 | no | cIDManager job queue trim (held) |
| 2026-10-24T04:39:54Z | func_001F4530 | 168 | non-matching | 6 | 145.8 | no | coliseum enemy pick check: 3-insn reg swap |
| 2026-10-24T04:42:40Z | func_003129D0 | 176 | matched | 1 | 160.5 | no | pointer list push_back (held for PR #18 ptrVec.h) |
| 2026-10-24T04:44:31Z | func_00306A48 | 64 | skipped | 1 | 14.2 | no | already carved (002f9dc8.c); typed rewrite held in 00306a48.c |
| 2026-10-24T04:45:11Z | func_00306BB0 | 196 | matched | 3 | 40.5 | no | effect file unload (held) |
| 2026-10-24T04:47:46Z | func_00306A88 | 28 | skipped | 1 | 137.4 | no | already carved (001b5160.c); typed rewrite held in 00306a48.c |
| 2026-10-24T04:47:46Z | func_00306AA8 | 72 | skipped | 2 | 137.4 | no | already carved (002f9dc8.c); typed rewrite held in 00306a48.c |
| 2026-10-24T04:47:46Z | func_00306AF0 | 192 | skipped | 4 | 137.4 | no | already carved (001212d0.c); typed rewrite held in 00306a48.c |
| 2026-10-24T04:50:45Z | cSndMemHeap_Alloc | 180 | non-matching | 6 | 158.0 | no | sound heap alloc: s1/s2 swap |
| 2026-10-24T21:50:40Z | STEP0 | - | step0 | - | build 39.2 | - | Session start (batch 172 resumes): godhand-nix /proc shows only its sleep infinity init, no permuter/compile.py/cc1/qemu leftovers. Normal build (container_run.sh .venv/bin/python compile.py, 0 rebuilt) ELF 1742f95b... and overlay ea599323... both match retail. Log build/scratch/step0_b172.log. |
| 2026-10-24T22:01:52Z | func_0027A320 | 736 | non-matching | 5 | 584.7 | no | enemies linked (0x27Axxx): follow the link (parts moved by the link part's offset through CVEC_SET_SUB, position/pose/flags copied); held progress/held/0027a320_nm.c, 2 insns: v0/v1 swap between the second vsub operand and the temporary's address; needs overlay cEmLinked.h (new), cEm00.h vt slot 0x58/parts 0x144/unk2F0, cOmBase.h cOmBase_childAtIdx (0xFF-masked range flag as cGameObj_idInRange), cModel.h cModel_calcParts prototype |
| 2026-10-24T22:01:52Z | func_0027AE10 | 740 | non-matching | 4 | 101.9 | no | enemies linked (0x27Axxx): twin of func_0027A320 (copies the link's rotation, skips the position copy without a link part); held progress/held/0027ae10_nm.c, same 2-insn v0/v1 swap; same overlays |
| 2026-10-24T22:08:32Z | func_002294E0 | 1244 | non-matching | 5 | 393.6 | no | enemies (0x229xxx): lunge attack phase machine (extern_jtbl D_004387D0); held progress/held/002294e0_nm.c, 4 insns: the stepVec = home * speedRate copy-out (retail ld x, ld y, st x, st y, ld z, st z; ours loads all three first; main's matches of this copy use a do/while(0) fence). Needs new cVec.h CVEC_SET_MUL (overlay), cEm00.h unk1865/unk17D4 and CheckSlotsShort2FEAndSetByte1864_262A10 prototype |
| 2026-10-24T22:10:39Z | func_001F85D0 | 572 | non-matching | 2 | 115.9 | no | area (0x1F8xxx): scaled quad area hit test (twin of cArea_HitCheckQuad); waiting: function-level cVec temporaries (c = (q0+q1+q2+q3)*0.25 has four return slots and one shared temporary); held draft progress/held/001f85d0_nm.c, 103 insns off |
| 2026-10-24T22:21:49Z | func_00268DC8 | 3320 | non-matching | 10 | 384.7 | yes | enemy (0x268xxx): per-type mesh show/hide, texture swap effect for 0x256/0x27E, hand pose meshes; held draft progress/held/00268dc8_nm.c at 827/830 words (guard bit-test fold, s0/s1 swap, two %hi CSE choices); needs cEm00 overlay texSet 0x284, hand[6] 0x1774, unk1869, cModel.h cTexTable + getMeshPtr/setTextureExchange prototypes |
| 2026-10-24T22:27:49Z | cCoreSave_translateSaveItem | 492 | non-matching | 6 | 211.3 | no | save (0x1FB4D8): stage move of remembered objects through a matrix; CVEC_SET_APPLY (new overlay operator, one per function) and fpu.h FPU_CVT_W_S/FPU_MFC1 give the in-place conversions; held draft progress/held/001fb4d8_nm.c at 115/123 words (retail reloads self->data before each position read and keeps 1.0f in f22; -fno-gcse no change) |
| 2026-10-24T22:28:21Z | func_001A26C0 | 996 | skipped | 0 | 22.2 | no | object init (0x1A26C0): re-swept for CVEC_SET_SUB; the vector temporary is approved now, but the cOmBase_childAt counts are stored at sp+0x0/0x10, the slots the zeroed vectors use later (childAt slot wall), so the frame can't be written without a placeholder |
| 2026-10-24T22:29:06Z | func_0028EDD0 | 820 | skipped | 0 | 11.1 | no | enemy shadow/lag point (0x28EDD0): pos += (target - pos) * 0.3f chain (three operators sharing return slots) plus a childAt count store; waiting: function-level cVec temporaries |
| 2026-10-24T22:38:34Z | func_001FCF20 | 924 | non-matching | 13 | 532.6 | no | damage manager (0x1FCF20): hand a give record's hit to each touching volume's take record (line-of-sight check, take fields, hit stop). progress/held/001fcf20_nm.c; 171 rows still differ: retail hoists &self->hitVec (spilled) and the vsub temporary address (fp) into the hit loop pre-header and stores dir.y from the 0.0 float register. New in the overlays: keySlot.h, cDamageGive owner/lastHit/ignore/nodes, cDamageTake opts/hitPos/victim/unk40/unk44, cDamageNode pos, cDamageData keys, cGameObjVt getCenter (0x90), CVEC_COPY; operator= through cVec_copy3. lwu flag tests use the long/(unsigned int) idiom with no shift (bit 0) |
| 2026-10-24T22:41:10Z | func_00289E38 | 1196 | skipped | 0 | 74.6 | no | enemy update (0x289E38, vtable 0x448E..): 0x15A0..0x15AC are flags/gravity/fall speed/timer in this class but cEm00.h names 0x15A0 gotoPos (cVec); decision filed in decisions_needed.md |
| 2026-10-24T22:47:59Z | func_001CA238 | 912 | matched | 9 | 404.0 | no | enemy shot (0x1CA238): aim, fly with line check, damage volume, burst. Held progress/held/001ca238.c (needs overlays). Config: c_flags_add -f=-ffast-math (else __builtin_sqrtf becomes a sqrtf call behind a NaN check), fp_hazard_rules sqrt (else the two nops before sqrt.s are missing). Uses cVec_copy3 for operator=, new CVEC_COPY/CVEC_INIT_MUL in the cVec.h overlay |
| 2026-10-24T22:50:29Z | func_001CCDE0 | 960 | skipped | 1 | 135.0 | no | cOmWeapon thrown weapon step |
| 2026-10-24T22:56:55Z | func_001CC668 | 924 | non-matching | 8 | 361.7 | no | cOmWeapon broken weapon fade step |
| 2026-10-24T22:57:08Z | func_001CCA08 | 980 | skipped | 1 | 8.7 | no | cOmWeapon homing throw step; waiting: function-level cVec temporaries (sub, copy, scale, add in step 3) |
| 2026-10-24T22:57:16Z | func_001CE870 | 1000 | skipped | 1 | 8.0 | no | cOmWeapon homing launch step; waiting: function-level cVec temporaries (copy, sub, normalize chain) |
| 2026-10-24T23:04:27Z | func_002E83D8 | 1888 | non-matching | 4 | 334.2 | no | GS packet: 25 shaded strips across or down (DMA/VIF DIRECT, FRAME/ZBUF/TEST/ALPHA, TEX0 strips). Scratch build/scratch/2e83d8.c is 472 of 472 words with fpu.h CVT/MFC1 under as sn, but the register assignment differs throughout: retail keeps 256.0f in f20 from before the null check (only a constant local reproduces it, which the rules forbid) and spills prio to 0(sp). Not parked as a draft |
| 2026-10-24T23:09:58Z | func_002B5028 | 2752 | non-matching | 5 | 330.5 | no | cMovie unit static initializer (movie manager, 2x6 clip tables, 3 tracks); held progress/held/002b5028_nm.c, 679/687 words, constant register sharing differs |
| 2026-10-24T23:16:50Z | _dispRefImageField | 1056 | non-matching | 6 | 397.7 |
| 2026-10-24T23:21:37Z | func_0039C5B8 | 1796 | non-matching | 6 | 281.6 |
| 2026-10-24T23:30:18Z | func_003A96C0 | 1472 | non-matching | 7 | 456.3 |
| 2026-10-24T23:37:14Z | func_002A2ED0 | 1816 | non-matching | 6 | 402.9 |
| 2026-10-24T23:37:34Z | func_002FC1A0 | 2056 | skipped | 0 | 9.2 |
| 2026-10-24T23:38:09Z | func_0029DA70 | 2128 | skipped | 0 | 34.9 |
| 2026-10-24T23:38:48Z | cModel_Tag_set_rate | 2016 | skipped | 0 | 9.9 |
| 2026-10-24T23:38:57Z | func_002A1BF8 | 1888 | skipped | 0 | 9.9 |
| 2026-10-24T23:39:09Z | func_0016A4D8 | 2040 | skipped | 0 | 21.6 |
| 2026-10-24T23:46:42Z | func_002A5EC0 | 2000 | non-matching | 2 | 452.6 |
| 2026-10-24T23:48:50Z | cMessDrawFont_draw | 1248 | matched | 1 | 0.0 |
| 2026-10-25T00:05:37Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 172 (sound driver/menu stream, module loader, libmpeg, enemy shot, cOmWeapon, GS strips, cMovie init, libc cvt, palette gradient, screen filters, stage set-up): 0 registered (no reseed: nothing new in src/). Held matches (progress/held/, register at the checkpoint): func_00375318, func_00376EA0, func_00380F80, func_00384BC8, func_00382520, func_003182D8, func_00394828 (extern_jtbl D_0045DBC0), func_0039BB20 (ee-2.9), func_002AD108, func_003129D0, func_00306BB0, func_001CA238 (-ffast-math, fp_hazard_rules sqrt), cMessDrawFont_draw (NM closer handoff; prototypes and D_003C2380's type to consolidate first). Held drafts include _dispRefImageField (262/264), func_0039C5B8 (447/449), func_003A96C0 (364/367), func_002A2ED0 (cvt.w.s, short-loop pad), func_002A5EC0 (GameWork anchor addressing). Skipped: the 0xE00 filter family (answered: leave), multi-operator cVec temporaries, cModel_Tag_set_rate (fpu.h + identical arms), func_0016A4D8. fpu.h overlay deleted (no byte-for-byte match with it; README notes 001fb4d8_nm.c needs it recreated). Overlay additions under Batch 172 in pending_headers.md. nm_handoff: cMessDrawFont_draw and func_00276478 verified (held). nm_prune: 0 stale. session_check (container): 18 passed, 7 skipped, dual_compiler_regress rc=126 (known). |
| 2026-10-25T00:17:02Z | GetEm00CharIndex | 2784 | matched | 5 | 671.1 |
| 2026-10-25T00:17:34Z | func_002E8EE8 | 2336 | skipped | 0 | 19.9 |
| 2026-10-25T00:19:51Z | func_00158328 | 2464 | skipped | 0 | 136.9 |
| 2026-10-25T00:20:02Z | func_002E9D48 | 2640 | skipped | 0 | 11.6 |
| 2026-10-25T00:20:25Z | func_0030DAD8 | 2656 | skipped | 0 | 11.7 |
| 2026-10-25T00:22:36Z | Motion_seq_ctr | 2824 | skipped | 0 | 131.0 |
| 2026-10-25T00:45:54Z | func_00109928 | 2464 | non-matching | 6 | 1398.2 |
| 2026-10-25T00:52:27Z | func_001101A8 | 2424 | matched | 4 | 1.8 |
| 2026-10-25T01:15:05Z | func_0010D3A8 | 2760 | non-matching | 6 | 0.9 |
| 2026-10-25T01:26:19Z | func_00165638 | 2124 | non-matching | 6 | 1.0 |
| 2026-10-25T01:29:27Z | func_001E7EA0 | 2292 | skipped | 0 | 0.4 |
| 2026-10-25T01:53:29Z | DogRace_Load | 1680 | matched | 6 | 27.7 |
| 2026-10-25T02:06:42Z | func_002CEA00 | 1624 | non-matching | 6 | 234.1 |
| 2026-10-25T02:08:12Z | func_002E7750 | 1696 | skipped | 0 | 85.3 |
| 2026-10-25T02:11:35Z | cSndSeVoice_Play | 1144 | matched | 3 | 110.7 |
| 2026-10-25T02:20:17Z | func_001601D8 | 2488 | non-matching | 8 | 511.6 |
| 2026-10-25T02:30:30Z | BATCH | - | batch | - | reseed 39.0; score 0.0 | - | BATCH 173 (em00 char index, sound voice start/update, DogRace load, sub screen manager, weapon swing, light gimmick): 1 registered earlier in the batch: GetEm00CharIndex (src/cod/002ddea0.c; its .gitignore allowlist line was missing and is added now). Definition corrections in src/: 0012b2e0.c WeaponCarrier_damageHeldWeapon takes and forwards int damage; 001e7848.c func_001E7848..E8 and func_001ED490 take (self, int n) for CustomIDWork_SetNumber (CustomIDPanel.h prototype replaces the K&R extern); dependents re-verified. Held matches (register at the checkpoint): DogRace_Load (fp_hazard_rules mtc1: nop between mtc1 and cvt.s.w, 419/420 words without; as_flags -g: the jal irand delay slot stays a nop), cSndSeVoice_Play (fp_hazard_rules mtc1: 276/286 words without), func_001101A8 (sn, extern_jtbl D_0041BDE0 D_0041BF40). Held drafts: func_002CEA00 (4 insns, left-volume easing register), func_001601D8 (2 words, constant 1 in s2; extern_jtbl D_0041F0E0), func_00109928, func_0010D3A8, func_00165638 (as sn, fp_hazard_rules fdiv, extern_jtbl D_0041F6B0). Skipped: func_002E7750 (decision: cWorldLightRec 0x4C int[2]), func_002E8EE8, func_00158328, func_002E9D48, func_0030DAD8, Motion_seq_ctr, func_001E7EA0. cSndSeVoice made aligned(16) in the held cSnd.h (7 held matches re-verified). Decisions filed: CVEC_TEMP_COPY, CVEC_ARG_COPY, cWorldLightRec array, flags5D8 int. No fpu.h overlay. reseed anchor func_001E7848 rc=0 elf=OK overlay=OK. nm_handoff: cMessDrawFont_draw and func_00276478 verified (held). nm_prune: 0 stale. session_check (container): 16 passed, 7 skipped, 3 failed: dual_compiler_regress rc=126 (known); carve_allowlist (fixed after the run with --fix, now OK); compile_units_tracked (src/cod/002ddea0.c is untracked until the maintainer commits it). |
| 2026-10-25T02:33:17Z | func_00196188 | 1136 | skipped | 2 | 4.0 |
| 2026-10-25T02:33:17Z | func_001977B0 | 1136 | skipped | 0 | 0.0 |
| 2026-10-25T02:40:17Z | func_00153B00 | 1856 | non-matching | 5 | 398.9 |
| 2026-10-25T02:40:51Z | func_001969D8 | 1968 | skipped | 1 | 33.4 |
| 2026-10-25T02:40:51Z | func_00198000 | 1968 | skipped | 0 | 0.0 |
| 2026-10-25T02:41:14Z | func_001ADDF8 | 1976 | skipped | 0 | 23.2 |
| 2026-10-25T02:41:37Z | cWorldLight_Move | 2288 | skipped | 0 | 22.6 |
| 2026-10-25T02:43:32Z | func_002A8038 | 1136 | skipped | 1 | 96.5 |
| 2026-10-25T02:52:00Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 174 (enemy set-ups and AI, model node draw/fog, world light move, collision lines): 0 registered (no reseed: nothing new in src/). Held draft: func_00153B00 mesh node draw record and fog (progress/held/00153b00_nm.c; fp_hazard_rules div1,mtc1; the camera target 12-byte copy is 8-byte aligned in retail, the first div.s is unpadded, the fog arms load the packet pointer later). Skipped: func_00196188, func_001977B0, func_001969D8, func_00198000, func_002A8038, func_001ADDF8, cWorldLight_Move (the bool range lookup slti/bnez/andi 0xFF that neither C nor C++ reproduces; decision filed; cWorldLight_Move also needs member-wise copy of a light record and the in-place cvt.w.s). The game range has no untried function under 800 bytes; what remains is VU0-heavy or C++ idioms. Overlay additions under func_00153B00 in pending_headers.md (cModelNodeDraw, fogMode, memcpy prototype, cVecQuad home). nm_handoff: cMessDrawFont_draw and func_00276478 verified (held). nm_prune: 0 stale. session_check (container): 18 passed, 7 skipped, dual_compiler_regress rc=126 (known). |
| 2026-10-25T02:52:22Z | func_0017C028 | 888 | skipped | 0 | 15.4 |
| 2026-10-25T02:52:22Z | func_002BC0F8 | 888 | skipped | 0 | 0.0 |
| 2026-10-25T02:56:42Z | func_001947C8 | 1256 | non-matching | 6 | 252.2 |
| 2026-10-25T03:03:45Z | func_0031B560 | 1448 | non-matching | 6 | 423.4 |
| 2026-10-25T03:15:01Z | cEmManage_CreateItem | 1800 | non-matching | 6 | 658.3 |
| 2026-10-25T03:21:36Z | func_0028D7E8 | 2016 | non-matching | 6 | 390.7 |
| 2026-10-25T03:22:24Z | func_00183980 | 2152 | skipped | 0 | 47.9 |
| 2026-10-25T03:30:38Z | func_0023E6B0 | 2424 | non-matching | 6 | 494.1 |
| 2026-10-25T03:38:03Z | func_00224090 | 2452 | non-matching | 6 | 437.1 |
| 2026-10-25T03:44:07Z | func_00231AC0 | 2620 | non-matching | 5 | 338.4 |
| 2026-10-25T03:45:03Z | func_0016B1F8 | 2688 | skipped | 0 | 51.8 |
| 2026-10-25T03:52:12Z | func_002873B8 | 2708 | matched | 3 | 429.3 |
| 2026-10-25T03:55:59Z | func_002269F0 | 2736 | matched | 3 | 221.9 |
| 2026-10-25T04:05:35Z | func_00284AF8 | 2944 | non-matching | 6 | 576.2 |
| 2026-10-25T04:11:39Z | func_00232500 | 3400 | matched | 4 | 325.2 |
| 2026-10-25T04:19:20Z | func_0028B190 | 3352 | matched | 4 | 387.4 |
| 2026-10-25T04:29:06Z | func_00214DE0 | 3936 | non-matching | 6 | 574.7 |
| 2026-10-25T04:35:15Z | func_00299DE0 | 3632 | non-matching | 3 | 359.6 |
| 2026-10-25T04:35:57Z | func_0029AC10 | 3752 | skipped | 0 | 24.8 |
| 2026-10-25T04:36:06Z | func_0029E8E0 | 3832 | skipped | 0 | 4.8 |
| 2026-10-25T04:36:06Z | func_002A39A8 | 3840 | skipped | 0 | 0.0 |
| 2026-10-25T04:36:06Z | func_0029CE70 | 3072 | skipped | 0 | 0.0 |
| 2026-10-25T04:36:51Z | func_002E35C0 | 3264 | skipped | 0 | 36.3 |
| 2026-10-25T04:43:21Z | func_00175F38 | 2048 | non-matching | 4 | 363.9 |
| 2026-10-25T04:43:21Z | func_001775C0 | 2048 | skipped | 0 | 0.0 |
| 2026-10-25T04:44:44Z | func_00190D28 | 2192 | skipped | 0 | 77.8 |
| 2026-10-25T04:44:44Z | func_001A17C8 | 2272 | skipped | 0 | 0.0 |
| 2026-10-25T04:54:59Z | func_00169358 | 2720 | non-matching | 6 | 602.0 |
| 2026-10-25T04:55:44Z | func_0016DF38 | 3752 | skipped | 0 | 38.1 |
| 2026-10-25T04:57:35Z | func_0016C260 | 1048 | skipped | 0 | 0.0 |
| 2026-10-25T04:57:45Z | func_00168560 | 1160 | skipped | 0 | 9.6 |
| 2026-10-25T04:58:06Z | func_001890B0 | 1320 | skipped | 0 | 10.6 |
| 2026-10-25T04:58:06Z | func_001A0E98 | 1360 | skipped | 0 | 0.0 |
| 2026-10-25T05:02:21Z | func_001C3090 | 1200 | non-matching | 3 | 250.8 |
| 2026-10-25T05:02:35Z | func_001712C8 | 1240 | skipped | 0 | 8.7 |
| 2026-10-25T05:02:40Z | func_0017BAF0 | 1304 | skipped | 0 | 0.0 |
| 2026-10-25T05:02:40Z | func_00182AE0 | 1272 | skipped | 0 | 0.0 |
| 2026-10-25T05:02:55Z | func_0028F108 | 1192 | skipped | 0 | 9.4 |
| 2026-10-25T05:02:55Z | func_0028F5B0 | 1368 | skipped | 0 | 0.0 |
| 2026-10-25T05:03:08Z | func_002856C0 | 1664 | skipped | 0 | 0.0 |
| 2026-10-25T05:03:08Z | func_002937C0 | 1240 | skipped | 0 | 0.0 |
| 2026-10-25T05:16:41Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 175 (shop and combo menus, technique shop draw, gimmick pieces and part matrices, enemy gauges, events): 0 registered (no reseed: nothing new in src/). Held matches (register at the checkpoint): func_002873B8, func_002269F0, func_00232500, func_0028B190. Held drafts: func_00214DE0, func_00299DE0, func_00175F38, func_00169358 (technique shop draw, 667/679 words, extern_jtbl D_0041FD00: the two row loops differ in register and stack-slot use), func_001C3090 (shatter piece throw, 297/299: retail shares one C++ temporary slot between the lock-on copy and the (1,1,1) scale, self in s3, -0.02 loaded early); others in this batch: func_001947C8, func_0031B560, cEmManage_CreateItem, func_0028D7E8, func_0023E6B0, func_00224090, func_00231AC0, func_00284AF8. Skipped: child lookups whose count store shares a stack word with a temporary (func_001775C0, 00190D28, 001A17C8, 001890B0, 001A0E98, 001712C8, 0017BAF0, 00182AE0; decision filed); function-level cVec temporaries (func_0016C260, 00168560, 0028F108, 0028F5B0, 002856C0, 002937C0; decision filed); func_0016DF38, func_0017C028, func_002BC0F8, func_00183980, func_0016B1F8, func_0029AC10, func_0029E8E0, func_002A39A8, func_0029CE70, func_002E35C0. Overlay additions in pending_headers.md: cShopPanel.h (new), cRecordIndex.h entry fields and prototypes with definition corrections, cCoreSave_ckClearStage(unsigned short) correction, pl00 subscreen prototypes, CVEC_SET_XYZ (cVec.h), cIDPanelHead step byte, cOmShatter view and the cGameObj lockOn slot returning cVec *. nm_handoff: cMessDrawFont_draw and func_00276478 verified (held). nm_prune: 0 stale. session_check (container): 18 passed, 7 skipped, dual_compiler_regress rc=126 (known). |
| 2026-10-25T05:17:31Z | setMotionInfo | 1712 | skipped | 0 | 11.0 |
| 2026-10-25T05:19:04Z | capVu0Atan2 | 464 | skipped | 0 | 14.7 |
| 2026-10-25T05:27:48Z | func_00291010 | 2024 | non-matching | 4 | 520.4 |
| 2026-10-25T05:37:16Z | func_00100FB8 | 3696 | matched | 6 | 0.0 |
| 2026-10-25T05:42:50Z | func_002DF950 | 4452 | non-matching | 3 | 304.5 |
| 2026-10-25T05:43:05Z | func_002F34B0 | 2308 | skipped | 1 | 907.5 |
| 2026-10-25T05:50:39Z | EmClothInit | 3804 | non-matching | 6 | 442.2 |
| 2026-10-25T06:12:35Z | func_002D22F0 | 2340 | non-matching | 6 | 1310.9 |
| 2026-10-25T06:14:15Z | func_002FEC38 | 3216 | skipped | 1 | 90.5 |
| 2026-10-25T06:14:24Z | func_002E1A08 | 3252 | skipped | 1 | 9.5 |
| 2026-10-25T06:15:23Z | func_002B8F48 | 3612 | skipped | 1 | 58.8 |
| 2026-10-25T06:16:04Z | func_00125048 | 4480 | skipped | 1 | 40.6 |
| 2026-10-25T06:16:30Z | func_002EAF70 | 3680 | skipped | 1 | 26.0 |
| 2026-10-25T06:17:37Z | func_001902F8 | 1616 | skipped | 1 | 25.3 |
| 2026-10-25T06:18:04Z | func_00195068 | 864 | skipped | 1 | 27.4 |
| 2026-10-25T06:26:34Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 176 (cloth sphere tables and enemy cloth set-up, BGM hit areas, effect sprite/mesh draws, collision pair dispatch, player command list, enemy set-ups): 0 registered (no reseed: nothing new in src/). Held match (register at the checkpoint): func_00100FB8 (costume cloth sphere tables, new held cloth.h). Held drafts: func_002DF950 (enemy cloth sphere tables, 1087/1113: g++ array-initialiser counters reused by CSE), EmClothInit (873/951, extern_jtbl D_0044DDE0: waiting on function-level cVec temporaries), func_002D22F0 (BGM hit areas, 586/585, extern_jtbl D_0044D130, -ffast-math, fp_hazard_rules sqrt: C++ bool lbu/xori tests of the IN bit, decision filed; constructor argument order). Skipped: func_002F34B0, func_002FEC38, func_002E1A08, func_002B8F48 (return-slot reuse, D-021); func_00125048, func_001902F8 (bool range check slti/bnez/andi 0xFF, added to the open decision); func_00195068 (function-level cVec temporaries, added to that decision); func_002EAF70 (grid mesh packet with 128-bit temporaries, low odds). Overlay additions in pending_headers.md: cloth.h (new: ClothSphere, EmCloth, enemy tables), cBgmData.h cBgmHitEnt, cSnd.h fields, prototypes and definition corrections (SetBgmAttr/SetBgmDefAttr float time, FindBgmNode typed, cSndBgmNode.flags int), criStm.h strcmp, seqNode.h prototypes, cVec.h CVEC_ASSIGN. The untried pool outside drafts is down to about 100 functions, nearly all VU0-heavy or behind open decisions. nm_handoff: cMessDrawFont_draw and func_00276478 verified (held). nm_prune: 0 stale. session_check (container): 18 passed, 7 skipped, dual_compiler_regress rc=126 (known). |
| 2026-10-25T07:50:00Z | CHECKPOINT | - | checkpoint | - | reseed 37s elf=OK overlay=OK; score 55.5297% | - | CHECKPOINT after batch 176: held overlays merged into include/ (22 new headers with .gitignore lines; 51 overlays now identical to include/ and removed, 27 keep pending edits). 15 held matches registered: func_00100FB8, func_00276478, func_002AD108, func_003182D8, func_00375318, func_00376EA0, func_00382520, func_00384BC8, func_003129D0 (sn, default flags); func_00155678, func_0015E708 (sn, as sn); func_00294488 (extern_jtbl D_0044A830); func_002C5548 (extern_jtbl D_0044C2E0, fp_hazard_rules mtc1); func_0039BB20, sceSifInitRpc (ee-2.9-991111). 25 drafts moved to drafts/cod/ (each compiles with -DNON_MATCHING, cygnus-2.96 -Wall clean). Full and cold builds: both retail hashes. session_check 18 pass, 7 skip, known dual_compiler_regress rc=126. tools/strip_data_nonmatching.py rewrote 2 asm/data files for the new header externs (data_decls check). |

Config reasons for the checkpoint registrations (for the PR text):
- 00155678.c `"as": "sn"`: retail's 64-bit constants are the SN assembler's dli expansion (ori/dsll 18/ori/dsll 1); the GNU assembler expands them as lui/dsll32 and 17 instructions differ.
- 0015e708.c `"as": "sn"`: same cause; retail loads 0x1000_0000_0000_0000-style GS constants as `ori 0x8000; dsll32 13`, the GNU assembler gives `lui 0x1000; dsll32 0` (4 instructions differ).
- 002c5548.c `fp_hazard_rules mtc1`: retail keeps a nop between each `mtc1` and the `cvt.s.w` that reads it; without the rule the nops are missing and every later instruction shifts.
- 00294488.c and 002c5548.c `extern_jtbl`: the switch tables are retail's D_0044A830 / D_0044C2E0 (jtbl_syms.py), as for the other 351 units.
- 0039bb20.c and 003b2900.c compile with ee-2.9-991111 like the rest of the libmpeg / SIF code in that range; no per-unit flags.
- drawPrim.h: Gp_draw_polyFT4 now takes `struct cScrVtx *` (its callers pass cScrVtx[4]); 002c5548 types its texture as `struct Tim2FileHdr *`. Only 002c5548 calls it through the header.
| 2026-10-25T07:52:26Z | func_0015DDF8 | 668 | matched | 3 | 600.0 | no | texture upload file to two GS upload packets (0x15Dxxx; as sn): held on the gsLoadImage.h quadword-view decision and the tim2.h overlay |
| 2026-10-25T07:55:42Z | func_0015DB30 | 692 | non-matching | 5 | 700.0 | no | flat sprite packet (0x15Dxxx): drafts/cod/0015db30.c, 64 insns (vertex loop count-down form and packet store order); the 1.0f Q word needs the float-bits union |
| 2026-10-25T07:56:47Z | func_001842B0 | 1064 | skipped | 0 | 60.0 | no | cOl40 enemy step (0x184xxx): the part loop chains two C++ vector operators (rot += rotVel * rate) per part; waiting: function-level cVec temporaries |
| 2026-10-25T07:58:38Z | func_002C1618 | 1220 | skipped | 0 | 120.0 | no | scene action unit sweep (0x2C1xxx): needs one cSceAtUnit (cSceAtUnit.h and cSceAtManager.h define the tag differently; pending_headers) with the 0x50 flag bits typed; vector part is two CVEC_ASSIGNs |
| 2026-10-25T08:01:21Z | func_00387270 | 184 | matched | 2 | 120.0 | no | sound voice-parameter command for one channel or both (0x387xxx): held on the new sndCmd.h header |
| 2026-10-25T08:02:26Z | func_00377688 | 116 | matched | 2 | 150.0 | no | sound object ramp step (0x377xxx): held on the new sndRamp.h header (func_00378070 retyped to SndRamp *) |
| 2026-10-25T08:02:44Z | func_003A4FC8 | 236 | skipped | 0 | 10.0 | no | libc memchr (0x3A4xxx): hand-written MMI (pcpyh/pcpyld/psubb/pnor) word scan; no C form |
| 2026-10-25T08:05:22Z | func_002B45F8 | 152 | non-matching | 6 | 300.0 | no | message text control-code search (0x2B4xxx): drafts/cod/002b45f8.c, one word short (code word copy into $a0); func_002AF218 is declared locally in 002afed0.c too (needs a cMess header prototype) |
| 2026-10-25T08:05:48Z | func_002B1F80 | 216 | skipped | 0 | 60.0 | no | sprite draw from a 0x14-byte entry table (0x2B1xxx): D_007479F4 has two types on main (int in 001c8f30.c, VibHead * in 001710f0.c; pending_headers) and func_0015D168 needs a drawPrim.h prototype |
| 2026-10-25T08:06:15Z | func_003BA708 | 248 | skipped | 0 | 20.0 | no | libstdc++ stream buffer flush through the streambuf vtable (0x3BAxxx): C++ class code, needs the class layouts and a .cc unit |
| 2026-10-25T08:06:15Z | func_003BA5A0 | 288 | skipped | 0 | 5.0 | no | libstdc++ stream buffer fill, twin of func_003BA708 |
| 2026-10-25T08:06:15Z | func_003BB058 | 288 | skipped | 0 | 5.0 | no | libstdc++ basic_string rep allocation (power-of-two capacity, small-block free lists at D_003C4030) |
| 2026-10-25T08:06:15Z | BATCH | - | batch | - | reseed -; score - | - | BATCH 177 (texture upload packets, sprite packet, sound command queue and ramps, message text scan, libc/libstdc++ leftovers): 0 registered. Held matches (register at the next checkpoint): func_0015DDF8 (tim2.h overlay + gsLoadImage.h decision), func_00387270 (new sndCmd.h), func_00377688 (new sndRamp.h; func_00378070 definition retyped). Drafts: drafts/cod/0015db30.c (64 insns), drafts/cod/002b45f8.c (1 word). cVec.h: CVEC_TEMP_COPY and CVEC_ARG_COPY moved back to the held overlay (undecided); 002cea00 back to held. |
| 2026-10-25T08:06:41Z | func_0030AC40 | 1104 | skipped | 0 | 60.0 | no | the game main loop (0x30Axxx): frame pacing on the GameWork 0x569/0x5E4 words, vsync and DMA kicks, then every subsystem's update; needs about 30 callee prototypes and named GameWork 0x560..0x580 fields first |
| 2026-10-25T08:06:41Z | func_0031F508 | 1224 | skipped | 0 | 5.0 | no | C++ RTTI (__dynamic_cast / type_info::operator==) helper |
| 2026-10-25T08:07:26Z | cSndSeVoice_Setup | 976 | skipped | 0 | 60.0 | no | SE voice set-up (0x2CDxxx): the D_00747A84 bit test now has the approved lw + dsrl idiom, but 8 callees (cSnd_SeCheckParam, func_002CBD10, cSnd_SeRecentPush, func_002CBF78, capVu0LengthAB, cSndSeVoice_Link/Unlink, func_00377FF8) and the SE parameter record need cSnd.h entries first |
| 2026-10-25T08:11:16Z | func_00165EB8 | 744 | held MATCH (progress/held/00165eb8.c; sn, as sn) | 7 | 900 | m2c + hand | sub-screen menu input step; as sn because the menu key masks are SN dli expansions (the GNU as builds lui/dsll 16 instead); needs menuKey.h page keys (overlay); OK-lock test decision filed |
| 2026-10-25T08:12:48Z | func_00164F30 | 1700 | skipped | 0 | 10.0 | no | idsubscrmenu set-up (cIDBase entries, heat/vital gauges): 9 callees have no header prototype (cIDBase methods declared locally in 26+ files); waits on the cIDBase.h prototype move (pending_headers) |
| 2026-10-25T08:13:25Z | func_0015D6E8 | 1096 | skipped | 0 | 5.0 | no | GS sprite packet (0x15Dxxx), same family as drafts/cod/0015db30.c (64 insns off): 64-bit GS register words built from FTOI4 vertices; revisit after 0015db30 closes |
| 2026-10-25T08:13:54Z | func_00372028 | 1384 | skipped | 0 | 5.0 | no | MPV sequence header parser (sibling of 00372590.c): CRI MPV code just past 0x36FFFF; decision filed on whether it is BrunoVgs's |
| 2026-10-25T08:16:06Z | func_00155DC8 | 1544 | NM draft (drafts/cod/00155dc8.c) | 1 | 20.0 | m2c + generated | model packet table fill: retail reloads every blob address (separate end symbols in the original, one empty blob); one symbol per address lets cc1 keep them in saved regs (373 insns); decision filed on end-label aliases |
| 2026-10-25T08:16:36Z | func_00309D88 | 1144 | skipped | 0 | 5.0 | no | texture upload set-up (0x309xxx): relocates a texture file into D_00747BA0's 0xB0 packets and repacks 64-bit TEX0 fields (TBP/CBP via func_0030A298, mode bits 63/61); same 64-bit field scheduling that stalled func_0030CB30 |
| 2026-10-25T08:16:51Z | func_002D45B0 | 1368 | skipped | 0 | 5.0 | no | movie frame upload packet (cMovieTrack, 0x2D4xxx): GS BITBLTBUF/TRXPOS/TRXREG/TRXDIR quadword strips with 64-bit field packing; gs-packet family |
| 2026-10-25T08:16:59Z | BATCH | - | batch | - | reseed -; score - | - | BATCH 178 (sub-screen menu, model packet table, texture/movie packets, MPV, C++ runtime): 0 registered. Held match: func_00165EB8 (menuKey.h page keys overlay; as sn; OK-lock test decision). Draft: func_00155DC8 (end-symbol decision). Skipped with reasons: func_0030AC40, func_0031F508, cSndSeVoice_Setup, func_00164F30 (cIDBase.h prototypes), func_0015D6E8, func_00372028 (MPV ownership decision), func_00309D88, func_002D45B0. Pool filter fixed: the earlier fully-prototyped list counted names in comments. Next: checkpoint 178 merges the held overlays and registers the 4 held matches. |
| 2026-10-25T08:39:46Z | CHECKPOINT | - | checkpoint | - | reseed 36s elf=OK overlay=OK; score 55.5638% | - | CHECKPOINT after batch 178: sndCmd.h and sndRamp.h added, tim2.h TexUp records merged; registered func_0015DDF8 (as sn: the TexUp GIF tag 0x1000000000008004 and the dbp masks are SN dli expansions; GNU as builds a different lui/dsll sequence), func_00377688, func_00387270 (default flags); func_00378070 definition takes SndRamp *. Full + cold builds match both hashes; session_check 18 pass / 7 skip / dual rc=126; -Wall clean. |
| 2026-10-25T08:46:34Z | create | 236 | NM draft (drafts/cod/002ba300.c) | 9 | 25.0 | hand | pool take (0x2BA300): with as sn the goto-to-shared-return form is 1 word short (retail's short-loop pad nop in the search loop, which neither assembler nor call_loop_pad emits for a loop with a forward exit); clean while form 6 insns off; decision filed |
| 2026-10-25T08:47:31Z | func_001565A0 | 288 | skipped | 0 | 5.0 | no | normal of three points (0x1565A0): two cVec subtractions, an operator= with its self-check, a cross product; several operators, waiting: function-level cVec temporaries |
| 2026-10-25T08:48:20Z | cOl21_createShapes | 716 | skipped | 0 | 5.0 | no | cOl21 shapes (0x17DCB8): retail computes 4.2 - 0.25, 4.2 + 1.2, 4.2 - 0.5 at run time from one register-held 4.2; only a constant held in a variable (banned) reproduces it |
| 2026-10-25T08:50:58Z | func_00149220 | 160 | NM draft (progress/held/00149220_nm.c) | 4 | 20.0 | m2c + hand | node uv scroll: plain (float)(int) goes through a GPR (trunc+mfc1/mtc1); fpu.h CVT_W_S/CVT_S_W match the conversions but retail reloads both scroll words after them (24 insns either way); fpu.h created and deleted again (no byte match) |
| 2026-10-25T08:54:04Z | func_002B45F8 | 152 | held MATCH (progress/held/002b45f8.c; sn) | 5 | 15.0 | hand | message code scan: passing *text to cMessCommon_getCodeSize (not the cached code) gives retail's register copy; needs cMessDrawFontCode.h prototypes (overlay) and typed calls in 3 main callers at the merge |
| 2026-10-25T08:55:47Z | func_001B57E8 | 620 | skipped | 0 | 5.0 | no | spawn helper objects + damage volume: its main clone 0018a680.c is written with float f[16] placeholders and constants in locals; retail builds C++ vector temporaries for several operators (waiting: function-level cVec temporaries) |
| 2026-10-25T09:10:00Z | cMotCamera_setMotion | 192 | NM draft (drafts/cod/001390b8.c) | 9 | 25.0 | hand | camera motion start: frameNum is an int parameter stored with sh; the pos operator= schedules loads x,y,z then stores x,z,y in retail; every copy form tried (CVEC_ASSIGN, this-pointer d_, by-name reads, bind orders) leaves 4-5 insns; also needs cCamera.h splits at 0x27A/0x2B4 and the cCamera_setMode(void) definition fixed to (self, mode) |
| 2026-10-25T09:40:00Z | func_00270160 | 468 | NM draft (drafts/cod/00270160.c) | 9 | 30.0 | m2c + hand | enemy sway joint push (child part by index via cOmBase_childAtIdx, local cEmSway view of 0x1920/0x1940): the cVec(x,y,z)-then-operator= temporary matches only when its three arguments are bound before the stores (proposal in decisions_needed); the two sway pushes still differ by 21 insns (retail re-forms &sway[no] and multiplies first) |
| 2026-10-25T10:20:00Z | func_0026A018 | 488 | NM draft (drafts/cod/0026a018.c) | 14 | 35.0 | m2c + hand | enemy 0x264 head turn toward the player: needs -f=-ffast-math (bare sqrt.s) and fdiv hazard; emNo test as main's (x ^ C) == 0; retail's target-minus-pos copy has no self-check (CVEC_SET_SUB keeps it: 70 off), the no-check form reaches 27 off (constant loads scheduled after the first atan2 call in retail); cParts 0x150 angle needs a cModel.h field |
| 2026-10-25T10:22:00Z | func_002BD828 | 520 | skipped | 0 | 3.0 | no | several vector operators (two ApplyMatrix temporaries, scaled copies, operator= chains): waiting: function-level cVec temporaries |
| 2026-10-25T10:23:00Z | func_002BD4B0 | 460 | skipped | 0 | 3.0 | no | two ApplyMatrix temporaries plus copies feeding func_002BB868 calls: several operators, waiting: function-level cVec temporaries |
| 2026-10-25T10:50:00Z | func_00274D18 | 380 | NM draft (drafts/cod/00274d18.c) | 10 | 30.0 | m2c + hand | enemy 0x20D neck tilt toward the player (earlier skip as "raw cop1 word" was wrong: c1 0xD0344 is the bare sqrt.s, reached with -f=-ffast-math + fdiv): Turn_dest_dir/Adjust_theta per arm (retail cross-jumps them), Adjust_theta takes the += value; dir = target - *pos copies with no self-check (unapproved shape); 10 insns left in the length's load order |
| 2026-10-25T10:55:00Z | BATCH | - | batch | - | reseed 0.0; score 0.0 | - | BATCH 179 (message code scan, sub-screen menu, camera motion, enemy sway/head/neck turns, uv scroll, pool take): 1 held match (func_002B45F8 sn, waits for the cMessDrawFontCode.h prototypes at the next checkpoint), 6 NM drafts (create 6 off, func_00149220 24, cMotCamera_setMotion 4, func_00270160 21, func_0026A018 27, func_00274D18 10), skips: func_001565A0, func_001B57E8, func_002BD828, func_002BD4B0 (waiting: function-level cVec temporaries), cOl21_createShapes (constant held in a register). fpu.h created for func_00149220 and deleted (no byte match). New decisions: cVec(x,y,z) argument-bound temporary; operator- with no self-check. Config needed by the drafts (not applied): -f=-ffast-math + fp_hazard_rules fdiv for func_0026A018/func_00274D18, because without -ffast-math cc1 wraps sqrt.s in the errno check and a jal sqrtf. |
| 2026-10-25T11:40:00Z | CHECKPOINT | - | checkpoint 179 | - | score +140 B | - | CHECKPOINT 179: registered src/cod/002b45f8.c (func_002B45F8, sn, default flags; no config edits). cMessDrawFontCode.h gains the func_002AF218 and func_002B45F8 prototypes (the definition includes it); 002afed0.c drops its duplicate func_002AF218 declaration. Full and cold builds both match retail (ELF 1742f95b..., overlay ea599323...); reseed func_002B45F8 OK (76 s); -Wall clean on both changed files; session_check 18 passed / 7 skipped / dual_compiler_regress rc=126 (baseline); score 55.5688 % (1576144 B, +140 B). Implicit-call callers listed in pending_headers.md. |
| 2026-10-25T12:05:00Z | func_00216760 | 1016 | NM (held, unchanged) | 8 | 15.0 | hand | grab-attack phase machine, 1 insn: retail negates the Turn_dest result (neg.s f1,f0) where every C form negates the copy (neg.s f1,f1): if/else both orders, 0 > turn, off = turn then negate, one variable negated in place, ternary in a local or in the condition (worse) |
| 2026-10-25T12:30:00Z | func_0026A838 | 256 | NM draft (drafts/cod/0026a838.c) | 9 | 25.0 | m2c + hand | enemy throw release (earlier skip "raw cop1 word c1 0x4" was wrong: it is sqrt.s $f0,$f0): typed EmThrower view as 001a6098.c's sibling, side/up locals as EmThrower_throwHeld; clean __builtin_sqrtf form (-ffast-math, fdiv) 13 off around the sqrt.s; matches byte for byte with a volatile sqrt.s (scratch diagnostic only): FPU_SQRT_S proposal filed |
| 2026-10-25T12:35:00Z | sqrt.s survey | - | diagnostic | 1 | 10.0 | script | build/scratch/sqrtdiag.py rebuilds drafts with a volatile sqrt.s (scratch only): func_002DAF68 MATCH, func_00135040 MATCH, func_0026A838 MATCH, func_00274D18 2 off, func_002AC878 13, cOmBase_calcParabolaVector 96, func_00134E18 107, func_0026A018 71 (no change: other blockers). Evidence filed with the FPU_SQRT_S decision |
| 2026-10-25T13:00:00Z | func_002DB008 | 188 | NM draft (drafts/cod/002db008.c) | 8 | 20.0 | m2c + hand | cylinder overlap: d = *a - *b is CVEC_INIT_SUB (added to the held cVec.h overlay); with a volatile sqrt.s (diagnostic) the scheduling matches and only the two early returns differ (retail bc1tl + v0 = 0 delay slots, ours bc1t): if/return, || and nested forms tried |
| 2026-10-25T13:20:00Z | func_002C0C28 | 132 | NM draft (drafts/cod/002c0c28.c) | 2 | 10.0 | hand | cylinder point test, written as its matched sibling func_002C0CB0 (-ffast-math, fdiv): 1 insn (retail v0 = 0 in the root test's delay slot, ours nop). Counterexample for FPU_SQRT_S: the volatile form is 8 off here (retail loads the radius before the root); noted in the decision |
| 2026-10-25T13:22:00Z | sqrt.s survey | - | diagnostic | 1 | 5.0 | script | non-volatile asm sqrt.s behaves like __builtin_sqrtf: no match in any of 7 drafts; only the volatile form reproduces the 4 matches |
| 2026-10-25T13:25:00Z | func_002C0C28 | 132 | NM (draft unchanged) | 3 | 4.0 | hand | delay slot: || height test (14 off), return !(r < root) (9), root <= r return 1 (28): plain form stays 1 off |
| 2026-10-25T13:40:00Z | func_001F8810 | 140 | NM (draft rewritten, clean cArea form) | 4 | 15.0 | hand | builtin sqrt 13 off (radius load before sqrt.s); volatile sqrt.s MATCH (fdiv and sqrt hazards); old goto draft replaced; FPU_SQRT_S evidence #5 |
| 2026-10-25T14:05:00Z | func_002D8070 | 300 | NM -> drafts/cod/002d8070.c (new draft, cWorldLight) | 1 | 10.0 | hand | 65 vs 75 words: same shape as func_002D81A0; retail forms self + 0x10000 (lui/addu) and mtc1 zero again in every block, ours once (a3 = base). -f=-fno-gcse no change |
| 2026-10-25T14:05:00Z | func_002D81A0 | 252 | NM (draft unchanged) | 2 | 4.0 | hand | fpu.h overlay (FPU_CVT_W_S + FPU_MFC1) and -f=-fno-gcse, with and without as=sn: no change; objdump shows R5900 cvt.w.s as trunc.w.s, so the conversions are not the gap; per-block base re-forming is |
| 2026-10-25T14:20:00Z | func_002A4FD8 | 784 | skipped | 0 | 6.0 | no | GS packet builder: two VIF/GIF chains copied with lq/sq from model data plus a 64-bit TEX0-style bitfield edit (tbp0 += 0x3B00, mask and set); no header covers the packet, needs a GS register record first |
| 2026-10-25T15:10:00Z | func_0037A818 | 220 | held MATCH -> progress/held/0037a818.c (sn default; waits on the MenuRowEnt decision) | 2 | 40.0 | hand | option value row: step the char/short value, then the page hook; hooks gain the row parameter retail passes; 6 sibling definitions retyped and checked (menuact/) |
| 2026-10-25T15:30:00Z | func_00376080 | 332 | skipped | 0 | 8.0 | no | sound slot setup from a pending entry: needs typed records for D_0076F050 (0x40-byte pending entries), D_00770850 (0xE0-byte slots) and SndBank tbl3 entries, plus prototypes for FindSlotEntry_376A10/func_003761D0/func_003780B0 (00375ef8.c, the caller and FindSlotEntry's file, is raw offsets with implicit calls); see pending_headers "SndEntry records" |
| 2026-10-25T15:30:00Z | func_00317D50 | 300 | skipped | 0 | 3.0 | no | object constructor (0x30E0 bytes): nested cVec member-array zeroing loops from inlined C++ constructors (sqc2 vf0 runs); twin func_003181A8; needs a cVec array-constructor shape, not on work |
| 2026-10-25T17:40:00Z | __svfscanf | 2832 | held MATCH -> progress/held/newlib/003a6ee8.c (sn default, extern_jtbl x4; waits on the verbatim-goto decision) | 6 | 120.0 | hand | newlib vfscanf.c (2000 snapshot) with the 4.4BSD float block (digits to atof); still matches without `register`, with ANSI definitions and a typed ConvFn |
| 2026-10-25T17:40:00Z | func_003A79F8 | 240 | NM draft -> progress/held/newlib/003a79f8_nm.c | 6 | 30.0 | hand | __sccl: newlib's goto form is 60/60 words with one branch target off (cc1 emits the beql label before `.p2align 3`; SN as moves it like retail but drops retail's two short-loop pads; SN 2.95.3-114/107 and 2.95.2-273a/274 not installed; -g/-O1/-O3 and loop reshapes don't move it); the clean form without the backward goto is 62 vs 60 |
| 2026-10-25T17:40:00Z | func_003ACE90 | 556 | held MATCH -> progress/held/newlib/003ace90.c (sn, as sn) | 2 | 10.0 | hand | newlib _strtol_r verbatim; as sn for the LONG_MIN dli expansion |
| 2026-10-25T17:40:00Z | newlib stdio header | - | held (newlib/) | - | 180.0 | hand | newlibStdio.h + newlibStdlib.h; 17 stdio units migrated, findfp/lflush/atof/strtod/strtoul/strtol/sscanf moved to newlib TUs with real signatures; every touched unit matches, -Wall adds no warnings |
BATCH 180: 2 held matches (func_0037A818 waits on the MenuRowEnt decision; __svfscanf waits on the verbatim-goto decision), 1 match registered (func_003ACE90, newlib _strtol_r, sn with as sn), drafts func_001F8810 (FPU_SQRT_S evidence), func_002D8070, func_003A79F8 (__sccl), skips func_002A4FD8, func_00376080, func_00317D50. The newlib stdio header batch went in at checkpoint 181. fpu.h overlay deleted (no byte-for-byte match with it this batch).
| 2026-10-25T20:30:00Z | CHECKPOINT | - | checkpoint 181 | - | score 55.5884% (+556 B) | - | CHECKPOINT 181 (newlib stdio): include/godhand/newlibStdio.h (FILE, struct _reent with verified offsets, struct stat, stdio flags, CHECK_INIT, stdio prototypes with their definitions' types) and newlibStdlib.h (conversions, _mbtowc_r, _ctype_ + 1, __mb_cur_max), with .gitignore lines. 17 stdio units drop their local FILE/_reent/CHECK_INIT copies and `void *` prototypes; 003a6ec8.c (__sclose on FILE, _close_r declared as defined), 003a7d08.c (_mbtowc_r takes struct _reent *), 00394290.c (regTbl.h types, sscanf moved out), 003a6cd8.c (eofread takes the read hook's three parameters, not read). New units, all sn: 003a6188.c (findfp std/__sinit/_cleanup_r/_cleanup, moved from 000000.c, 0014ea28.c, 00150048.c, now typed), 003a6a88.c (lflush), 003a7c28.c (atof, returns double), 003a8fe0.c (strtod), 003a6ce0.c (sscanf), 003ace90.c (NEW func_003ACE90 _strtol_r + strtol; config edit `as: sn`: with GNU as the LONG_MIN constant is built as ori 0x8000; dsll32 16, retail and ps2eeas build addiu -1; dsll32 31); 003a9018.c gains strtoul. Old thunk definitions removed from 000000.c, 0014ea28.c, 00150048.c, 00150078.c, 0014e598.c. tools/strip_data_nonmatching.py rewrote 2 asm/data files for the new header externs. Full and cold builds match both hashes (ELF 1742f95b..., overlay ea599323...); reseed func_003ACE90 OK (37 s); session_check 18 passed / 7 skipped / dual_compiler_regress rc=126 (baseline); -Wall: no new warnings in any changed file, new files clean. Follow-ups in pending_headers.md. |
| 2026-10-25T12:10:00Z | func_003A79F8 | 240 | still NM (toolchain) | 1 | 5.0 | hand | __sccl: ps2eeas `-sn` ("SN Systems' extensions") assembles identical .text to plain ps2eeas; the short-loop pad and label placement stay. ps2eeas has no short-loop option in its strings. Same blocker for func_003A9498 and func_003B6290 |
| 2026-10-25T12:10:00Z | func_00145460 | 944 | matched -> src/cod/00145460.c (sn, no flags) | 4 | 20.0 | hand | cIDBaseScreen opening phase; matches once D_0041E880/D_0041E840 are const (rodata; cc1 then loads the four colour floats before the stores and hoists the first) and cases 1/3 read D_0041E880[i] directly |
| 2026-10-25T12:10:00Z | cIDBaseScreen header | - | merged | - | 60.0 | hand | one header type for the ID screen; 14 units migrated off six local views plus raw offsets, every unit rechecked (unitchk OK) |
| 2026-10-25T12:10:00Z | func_00146328 | 1052 | skipped | 0 | 2.0 | no | cIDBaseScreen draw: VU0 vector temporaries (vadd through stack slots), 0x20-quad sqc2 clear loop; waits on function-level cVec temporaries |
| 2026-10-25T12:10:00Z | BATCH | - | batch | - | 181 | - | BATCH 181 (ID screen): 1 match (func_00145460). New header cIDBaseScreen.h replaces six local views of the 0x4D2-byte ID screen across 14 units (00100508, 00126820, 00126918, 0012bf50, 00133900, 00144b50, 00144c90, 001450a0, 001451a0, 00145238, 00145410, 00145fc8, 00146190, 001f50a0). cIDBase_move prototype merged into cIDBase.h (9 includers drop local copies), memcpy prototype into criStm.h. Definition fixes: func_001451A0 3 params (num not read), SetFlagAfterCopy_145160 dead result local dropped. Config edits: none besides registering src/cod/00145460.c (sn default). tools/strip_data_nonmatching.py rerun for the three new data externs. __sccl: ps2eeas -sn tried, no change. Searched the newlib/SCE range 0x3A0000-0x3B8000: every remaining function is vectorized libc, CRI, inline asm, or already logged. |
| 2026-10-25T12:10:00Z | CHECKPOINT | - | checkpoint 182 | - | score 55.6217% (+944 B) | - | CHECKPOINT 182: full build and cold build both ELF 1742f95b.. and r207 ea599323.. match; reseed (anchor func_00145460) rc=0 36s elf=OK overlay=OK; session_check 18 passed / 7 skipped / dual_compiler_regress rc=126 (baseline) after strip_data_nonmatching; -Wall: no new warnings in the changed files (memcpy implicit-declaration warnings gone in 0012bf50.c and 00133900.c). Backups in build/scratch/ck182/. |
| 2026-10-25T14:00:00Z | func_00145810 | 1976 | NM draft -> progress/held/00145810_nm.c | 14 | 490/494 | hand | cIDBaseScreen main phase (scroll, ease, confirm). Shapes that moved it closer: `scrolling` flag set by an if (GCC folds `i == (f > 1) + 1` into two compares), the alpha select as if/else (retail cross-jumps the tails), `i != 0 && i != 4` tested twice (retail hoists the 4), language ternary over the whole masked read. Left: loop 1 does not hoist 0x303030/0x808080 and so does not spill the tex/attr/&tbl[0][1] bases; &D_007474A0 high half kept across the function; `1` of `i == 1` not hoisted in loop 2; xori/andi attr test (`~attr & 1` gives nor). Tried: int/unsigned n and i, ternary colour forms, -fno-gcse (worse: retail runs gcse), drop-reorder (no change) |
| 2026-10-25T16:30:00Z | BATCH | - | batch 182 | - | - | - | BATCH 182 (cIDBase method prototypes, cIDManager globals): 0 new matches, 2 NM drafts (func_00145810 490/494 in progress/held/00145810_nm.c; func_002ACF30, 5 register diffs, progress/held/002acf30_nm.c). Held cIDBase.h gains IDBASE_RES_MAGIC, cIDBaseRes and the prototypes of the 27 cIDBase methods plus func_002AB9A8/func_002AC9B8, typed as their definitions. Held cIDManager.h gains `cIDManager **D_003C2384` / `cIDManager *D_003C2388` and the cIDManager_allocBufRun/func_002ACF30 prototypes. Definitions retyped: cIDBase_initIDWork (00126770.c), cIDBase_release (001ee1c0.c), cIDBase_setWorkFromData (0012cc70.c; raw IDBASE_OFFSET store and a forward goto to the failure exit, the early-return form is 11 off). 31 files drop their local cIDBase declarations and pass `&x->base`; typed members instead of padding: IDSlotScreen.base (00143998.c), `cIDBaseObj sub` (00166638.c, 001673d0.c), new local view IDDualDisp for vtable D_0041E8C0's draw (00146748.c); 001450a0.c's IdObj_resetAndReleaseIds4 takes `char *` and declares func_00161590 as defined; 002aa1e0.c uses cIDManager.h. unitchk OK on every changed unit; -Wall: no new warnings, one fewer (cIDManager_allocBufRun). Old warnings left in the changed files are listed in pending_headers.md for batch 183. |
| 2026-10-25T17:10:00Z | CHECKPOINT | - | checkpoint 183 | - | score 55.6217% (+0 B) | - | CHECKPOINT 183 (cIDBase prototypes, cIDManager globals): include/godhand/cIDBase.h, cIDManager.h and cIDBaseScreen.h take the held batch 182 copies (no new headers, so no .gitignore lines; no config edits). The 31 batch 182 source files are listed in build/scratch/changed183.txt; header backups are in build/scratch/ck183/include_old/. tools/strip_data_nonmatching.py stripped 2 lines in 1 asm/data file for the new D_003C2384/D_003C2388/D_0041E840 header externs. Full and cold builds match both hashes (ELF 1742f95b..., overlay ea599323...); reseed cIDBase_setWorkFromData rc=0 35 s elf=OK overlay=OK; session_check 18 passed / 7 skipped / dual_compiler_regress rc=126 (baseline); -Wall: no new warnings (old ones listed for batch 183). Held overlays for the three headers removed (identical to include/). |
| 2026-10-25T19:00:00Z | BATCH | - | batch 183 | - | - | - | BATCH 183 (id object head, arena and disc-read prototypes; clears the func_00161500 warnings in the batch 182 files): 0 new matches. New cIDObj.h: the 0x70-byte head of the id display objects (cIDBaseObj, resHandle 0x50, readId 0x54, b5A..b5D, state 0x60, variant 0x64, the kept GameWork flags5D8/flags5E0 at 0x68/0x6C) and its five methods. The methods move into one unit, src/cod/001614d0.c (sn): ClearFields_1614D0 (was 00138528.c, cygnus), func_00161500 (0014ea28.c), func_00161590 (00126770.c), the two GameWork flag copies (000000.c, cygnus; its two private D_007474A0 types are gone, gameWork.h's flags5D8/flags5E0 are used). All five match under sn. Derived objects embed cIDObj: IdDispObjKind6 (0015a040.c), IdDispObjKind9 (001616a8.c), IdDispObjKind8 (00166638.c), IdDispObjKind1B (001673d0.c), IdDispObj16 (00167fa8.c; its variantCopy is the head's b5A), plus IdObjSlot4 (001450a0.c; manager slot 4 cleared through cIDManager.pair[4]). The four files that defined different structs under the one tag IdDispObj now use distinct tags. heapArena.h: typed HeapBlock and HeapArena (block, size, user), Arena_init and func_002A94F0 prototypes; definitions retyped in 0017e058.c (drops its local Arena) and 002919c0.c; 00297fb8.c and 0030ecf8.c follow. cDvd.h: the cDvd_ReadAlloc prototype as its definition (system/cDvd.c) now reads it: `void **out`, `struct HeapArena *heap`, `size`; cDvd_ReadAllocSized (00200df8.c) takes the heap too, and cDvdJob 0x7C (`align`) is typed `struct HeapArena *` (it holds the heap; name question filed). sceVu0.h: func_0030A548 and func_0030A2E0 prototypes; 001b5160.c's MtxCopy/MtxMultiply and the five ClearFields/cIDBase_trans trampolines take and pass the arguments their callees read (they were `void (void)`), and it includes mtx.h. Stale overlay progress/held/inc/godhand/sideCounter.h removed (older than include/). -Wall: five func_00161500 implicit declarations gone, no new warnings. No config edits besides the unit and the five carve moves. |
| 2026-10-25T19:40:00Z | CHECKPOINT | - | checkpoint 184 | - | score 55.6217% (+0 B) | - | CHECKPOINT 184: include/godhand/cIDObj.h (new, .gitignore line), heapArena.h, cDvd.h, sceVu0.h from the held overlays (overlays removed). New unit src/cod/001614d0.c (sn-2.95.3-136, compile_units entry and .gitignore line; config edit: the five carved_funcs entries ClearFields_1614D0, func_00161500, func_00161590, Obj0000_Set_Fields_68_6C_From_D_007474A0_1615D0, Obj0000_Set_D_007474A0_Fields_5D8_5E0 move their tu to it, because the class's methods were spread over 000000.c, 00138528.c, 00126770.c and 0014ea28.c; no flags). First full build failed: system/cDvd.c defines cDvd_ReadAlloc with a different signature than the held prototype (it had never been through a full build); fixed by retyping the definition (above). Full and cold builds then match both hashes (ELF 1742f95b..., overlay ea599323...); strip_data_nonmatching: no change; reseed func_00161500 rc=0 35 s elf=OK overlay=OK; session_check 18 passed / 7 skipped / dual_compiler_regress rc=126 (baseline). Backups: build/scratch/ck184/. |
| 2026-10-25T20:10:00Z | cIDObj.h (held) | - | header fix | - | 20.0 | hand | batch 184 start: cIDObj's field names now follow the two older views of the same head on main, MenuScreen (cSubScr.h: busy 0x58, sel 0x64, vtable 0x70) and cIDPanelHead (cIDMenuPanel.h: state 0x5A, step 0x5B, result 0x60); adds `struct cVtEnt *vtable` at 0x70 (head now 0x74). The users in 001614d0.c, 0015a040.c, 001616a8.c, 00166638.c, 001673d0.c, 00167fa8.c, 001450a0.c follow; unitchk OK on all, and on 001b5160.c. Held overlay progress/held/inc/godhand/cIDObj.h, merges at the next checkpoint. |
| 2026-10-25T21:10:00Z | func_00164EF8 | 56 | held MATCH -> progress/held/00164ef8.c (replaces src/cod/00164ef8.c; sn, no flags) | 1 | 5.0 | hand | menu clear typed on the held cSubScrMenu.h/cIDObj.h instead of raw offsets |
| 2026-10-25T21:10:00Z | func_00164F30 | 1700 | NM draft -> progress/held/00164f30_nm.c (sn, as sn) | 9 | 60.0 | m2c + hand | sub-screen menu open: 424 vs 425 words, only the divide pad differs (retail pads the second div.s, not the first after its cvt.s.w; fdiv pads both, default neither); decision filed with a retail census (cvt.s.w feeding a div.s: 61/65 bare). The status/level stores through the display pointer need the inline cIDBase_play (restart + playing = 1), added to the held cIDBase.h; 00143be8 and cCockTutorial match with it too (held replacements) |
| 2026-10-25T21:10:00Z | cHeatSys.h (held) | - | header | - | 2.0 | hand | cHeatSys_GetHeatRatio prototype (its definition 002a9c98.c includes the header); at the checkpoint drop the local externs in 002a9ad0.c and 00141ce8.c |
| 2026-10-25T21:50:00Z | BATCH | - | batch 184 | - | - | - | BATCH 184 (sub-screen menu): 0 new matches. func_00164F30 is byte-identical apart from the divide pad (NM draft, decision filed with a retail census). Held: cSubScrMenu.h merges three views of the 11cSubScrMenu status screen (the 00165eb8 local, IdObjSlot4 in 001450a0, FileHolder in 00166540 and fileHolder.h, StatusScreen in the 00165638 draft); cIDBase.h cIDBase_play; cHeatSys.h prototypes. Held replacements: 00164ef8, 00166540, 001661a0, 001450a0, 00143be8, cCockTutorial, 002a9ad0, 00141ce8, 002a9bf0, battle/cHeatSys (all MATCH, -Wall clean). No config edits. Zero-match batches in a row: 3 (182, 183, 184). |
| 2026-10-25T22:40:00Z | CHECKPOINT | - | checkpoint 185 | - | score 55.6217% (+0 B) | - | CHECKPOINT 185 (sub-screen menu): include/godhand/cSubScrMenu.h (new, .gitignore line), cIDObj.h (field names follow MenuScreen/cIDPanelHead), cIDBase.h (cIDBase_play), cHeatSys.h (GetHeatRatio/UpdateHeatLv prototypes) from the held overlays; include/godhand/fileHolder.h deleted with its .gitignore line (nothing included it; cSubScrMenu.h is the type). Held replacements moved to src: 00164ef8, 00166540, 001661a0, 001450a0, 00143be8, casino/cCockTutorial, 002a9ad0, 00141ce8, 002a9bf0, battle/cHeatSys. Draft drafts/cod/00164f30.c. No config edits. Full and cold builds both ELF 1742f95b.. and r207 ea599323.. match; reseed (anchor func_00164EF8) rc=0 37s elf=OK overlay=OK; session_check 18 passed / 7 skipped / dual_compiler_regress rc=126 (baseline). |
| 2026-10-25T23:50:00Z | func_00166780 | 0x3E0 | NM draft -> progress/held/00166780_nm.c (sn, extern_jtbl D_0041FAA0) | many | 90.0 | m2c + hand | cSubScrOption per-frame update: 248 words, 4 differ. In both fade-out calls retail loads t1 (0xFF000000) before t0 (0) and the branch delay slot takes the zero; ours loads in argument order. Tried an inline fade wrapper, a parameterised inline, case reorders, ee-2.9 and cygnus-2.96 (much worse); no shape moves the two loads |
| 2026-10-25T23:50:00Z | func_00167518 | 0x3A0 | NM draft -> progress/held/00167518_nm.c (sn, extern_jtbl D_0041FBB0) | 8 | 50.0 | m2c + hand | cSubScrOptionT per-frame update: 4 insns, the same fade-out load order as func_00166780. The outer state switch needs `case 0: case 2: break;` for retail's ==1/<2/==2/==3 tree. Retail addresses its fade step as a separate byte (%hi/%lo(D_003BD9E8 + 1)); an array element or struct field keeps the base address in a register, a scalar `D_003BD9E9` matches, but there's no symbol at 0x3BD9E9 yet (pending_headers.md) |
| 2026-10-25T23:50:00Z | BATCH | - | batch 185 | - | - | - | BATCH 185 (options panels): 0 new matches. Held: cSubScrOption.h (new; cSubScrOption, cSubScrOptionT, D_003BD9E8 fade step), padWork.h (D_005E8140 unsigned char[], PAD_WORK_VIBRATION). Held replacements typed on them, all MATCH with -Wall unchanged: 00166638, 001673d0, 00166730, 00166b60, 001678b8, 00166bb8, 00167908, 001672f0, 00167eb0, 00161b30, 001004c8. Two NM drafts (00166780, 00167518, 4 insns each). The SetGlobalToggle prototype was reverted: 00137aa0.c's implicit callees must be fixed first (pending_headers.md). No config edits. Zero-match batches in a row: 4 (182-185). |
| 2026-10-26T01:10:00Z | CHECKPOINT | - | checkpoint 186 | - | score 55.6217% (+0 B) | - | CHECKPOINT 186 (options panels): include/godhand/cSubScrOption.h (new, .gitignore line after cSubScrMenu.h) and padWork.h (D_005E8140 unsigned char[], PAD_WORK_VIBRATION; nothing else reads the array through the header) from the held overlays. Held replacements moved to src: 00166638, 001673d0, 00166730, 00166b60, 001678b8, 00166bb8, 00167908, 001672f0, 00167eb0, 00161b30, 001004c8. Drafts drafts/cod/00166780.c and drafts/cod/00167518.c. No config edits. Full and cold builds both ELF 1742f95b.. and r207 ea599323.. match; reseed (anchor func_00166B60) rc=0 36s elf=OK overlay=OK; session_check (in the container) 18 passed / 7 skipped / dual_compiler_regress rc=126 (baseline). |
| 2026-10-26T02:30:00Z | func_001B8030 | 0x20 | MATCH -> progress/held/001b8030.c (sn) | 0 | 100 | hand | Item test: `return cGameObj_idInRange(obj, 0x3C0, 0x400);` with a `long` return (an `int` return adds the dsll32/dsra32 sign extension retail doesn't have). Prototype `long func_001B8030(cGameObj *obj)` added to held cGameObj.h; held 0013cf20.c (getItemNumInRoom) drops its local `int (void *)` extern, includes cGameObj.h and casts `(cGameObj *)*p` at the call; all 6 of its functions still match. Merges at the next checkpoint (needs the held cGameObj.h). |
| 2026-10-26T02:30:00Z | func_0016C730 | 0x14E4 | skip (decision) -> build/scratch/t16c730.c | ~118 blocks | - | hand | cSubScrWaza draw: full C written (1338 vs 1337 words). Same mixed divide pad as func_00164F30: two nops before `8.0f / limit` (after an unrelated mtc1), none before the second divide (after the sub.s writing its operand). Also callee retypes needed first: func_002C9060 (int -> cRecordIndexEntry *), DebugPrintfWrapper (const char *fmt, shared header), func_0016EE10 (cSubScrWaza *), D_003BC7D0 into comboObj.h. Added to the func_00164F30 decision row. |
| 2026-10-26T02:30:00Z | func_003A80E8, func_003A9E58, func_003AB188 | - | skip | - | - | - | _dtoa_r and printf internals: Sony's rewrite, not newlib 1.9.0 (compared against the fetched newlib source). No source to start from. |
| 2026-10-26T02:30:00Z | func_002BBDB8 | - | skip | - | - | - | several cVec operators in one function: waiting: function-level cVec temporaries. |
| 2026-10-26T02:50:00Z | cSnd_IsEnemyAlive | 0xBC | MATCH -> progress/held/002d0c10.c (sn) | 0 | 100 | hand | Two `cGameObj_idInRange(...) & 0xFF` flags (enemy kind, then boss kind), as the helper's comment prescribes; replaces drafts/cod/002d0c10.c. Prototype `int cSnd_IsEnemyAlive(cSnd *self, int kind)` added to held cSnd.h (self is not read); its caller 002cf310.c called it undeclared and needs no edit. -Wall: no new warnings. |
| 2026-10-26T03:30:00Z | func_001BD430 | 0xDC | NM draft rewritten -> drafts/cod/001bd430.c (sn) | 30 | 45 | hand | Door contact check: typed against held cOmDoor.h (touchedNum 0x630, toucher 0x634, collision now cObjCollision *, contact list at 0x34/0x54) instead of the local RangeOwner view; cGameObj_idInRange(...) == 1 for the player and enemy ranges; inline cObjCollision_clearTouch for the end. Same length as retail; left: register allocation (collision pointer a1 vs v1, retail re-reads *touch for the toucher store). Index loop and count-local forms are worse. |
| 2026-10-26T04:00:00Z | func_002956F0 | 0x170 | NM (draft unchanged, drafts/cod/002956f0.c) | 33 | - | hand | fpu.h attempt (held, deleted again): FPU_CVT_W_S + FPU_MFC1 in an inline give retail's in-place cvt.w.s/mfc1 for the three position conversions (byte-identical; this objdump decodes 0x46000024 as trunc.w.s, so the draft's "trunc vs cvt" note is a display artefact: plain casts differ because they convert into a new register). The heading conversion still differs (retail cvt.w.s $f1,$f0 into the dead constant register; ours in place). cGameObj_idInRange(...) & 0xFF fixes the enemy-kind test. Still blocked by the narrowed objNo/seBank loads (lbu vs retail lhu/lw), as the closer logged; `- EMSET_OBJ_BASE` folds away. |
| 2026-10-26T04:20:00Z | cEmManage_SetEmAnger | 0x1B8 | NM (draft unchanged, drafts/cod/00291b90.c) | 78+ | - | hand | The kind test matches with cGameObj_idInRange(...) & 0xFF. Clean loop forms (continue instead of the draft's gotos; ternary, early-return and copy-then-negate abs inlines; flat and nested tests) are all 3-4 words short with the fabs blocks laid out differently; the draft's goto form stays closest (108 vs 110). |
| 2026-10-25T16:08:00Z | BATCH | - | batch 186 | - | - | - | BATCH 186 (id-range helper sweep): 2 matches (func_001B8030, cSnd_IsEnemyAlive), both written with cGameObj_idInRange; the zero-match streak ends at 4. Drafts: func_001BD430 rewritten against held cOmDoor.h (30 insns, register allocation). Skipped/NM: func_0016C730 (mixed divide pad, decision row updated with a full-retail census), func_002956F0 (narrowed loads; fpu.h tried and deleted), cEmManage_SetEmAnger (fabs layout), displayOmLayer (global reload), func_00140860, printf internals, func_002BBDB8. Stopped mid-look at func_00129CC8 (CVEC_SET_APPLY candidate; needs MtxInverse, SetActionKickBomb and cOm60_ckParent header prototypes first). |
| 2026-10-25T16:08:00Z | CHECKPOINT | - | checkpoint 187 | - | score 55.6294% (+220 B) | - | CHECKPOINT 187: cGameObj.h gains `long func_001B8030(cGameObj *obj)`, cSnd.h gains `int cSnd_IsEnemyAlive(cSnd *self, int kind)` (only these lines; the rest of both held overlays stays held). Registered src/cod/001b8030.c and src/cod/002d0c10.c (sn, default flags, no config keys), .gitignore lines, symbol entry func_001B8030; 0013cf20.c drops its local `int (void *)` extern; drafts/cod/002d0c10.c deleted. nm_solved: func_00276478 and func_002B45F8 stale (already in src); cMessDrawFont_draw verifies but left (about 20 local callee externs, int casts of pointers). Full and cold builds both retail; reseeds rc=0; session_check baseline. |
