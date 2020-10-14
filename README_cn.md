# TTKMusicPlayer
[英文 English](./README.md) | [繁体中文 Chinese](./README_tc.md)

![TTKMusicplayer](https://img.shields.io/badge/Greedysky-TTKMusicPlayer-green.svg?style=flat-square)
![版本](https://img.shields.io/badge/Version-2.13.2.0-blue.svg?style=flat-square)
![许可](https://img.shields.io/badge/License-GPL%20V3-yellowgreen.svg?style=flat-square)

![徽标](https://github.com/Greedysky/Resource/blob/master/Screen/logo_pic.png?raw=true)

### **|[关于](https://github.com/Greedysky/TTKMusicplayer/blob/master/README_cn.md#使用方法)|[许可证](https://github.com/Greedysky/TTKMusicplayer/blob/master/README_cn.md#许可证)|[下载](https://github.com/Greedysky/TTKMusicplayer/blob/master/README_cn.md#下载)|[特性](https://github.com/Greedysky/TTKMusicplayer/blob/master/README_cn.md#特性)|[快照](https://github.com/Greedysky/TTKMusicplayer/blob/master/README_cn.md#快照)|[版权](https://github.com/Greedysky/TTKMusicplayer/blob/master/README_cn.md#版权)|[贡献](https://github.com/Greedysky/TTKMusicplayer/blob/master/README_cn.md#贡献)|**

使用方法
----
**音乐播放器基于qmmp和Qt库开发. 编译教程我已经写在wiki上了.(看这里<u>https://github.com/Greedysky/TTKMusicplayer/wiki</u> )**

### 本项目代码不用于商用，仅限研究和学习使用，资源版权归个音乐平台所有。
 
## 构建状态
 * 基于Qt4.8.7的windows-mingw 32bit版本测试通过
 * 基于Qt4.8.7的linux-gcc 64bit版本测试通过
 * 基于Qt5.x的windows-mingw 32bit版本测试通过
 * 基于Qt5.x的linux-gcc 64bit版本测试通过
 
| 平台 | Qt & 编译器       | 状态                                                                                      |
| :---:    | :---:               | :---:                                                                                       |
| Linux    | 4.8.7 GCC & 5.x GCC    | ![Linux](https://img.shields.io/badge/build-passing-brightgreen.svg)                            |
| Windows  | 4.8.7 GCC & 5.x GCC       | ![Windows](https://img.shields.io/badge/build-passing-brightgreen.svg) |
| Windows  | 5.x MSVC       | ![Windows](https://img.shields.io/badge/build-unknown-lightgrey.svg) |
| OS X     | 5.x Clang     | ![OSX](https://img.shields.io/badge/build-unknown-lightgrey.svg)                           |
 
# 开发者

许可证
---
TTKMusicPlayer是基于[license GPL v3](https://github.com/Greedysky/TTKMusicplayer/blob/master/LICENSE)条款授权的免费软件。如果您使用TTKMusicPlayer或者它的动态库，则务必添加相关许可证到项目中。

API 文档
---
文档请看这里: **<u>https://greedysky.github.io/ttkdocs/html/index.html</u>**

下载
---
OSChina: **<u>http://git.oschina.net/greedysky/Musicplayer</u>**

Qmmp原版下载地址: **<u>http://qmmp.ylsoftware.com</u>**

Qmmp原版镜像下载下载地址: **<u>https://github.com/Greedysky/qmmp</u>**

Qmmp修改版下载下载地址: **<u>https://github.com/Greedysky/TTKMusicplayer/tree/plugins</u>**

Qmmp修改版二进制库下载地址: **<u>http://pan.baidu.com/s/1bv4iSY</u>**

播放器及其他依赖下载地址: **<u>http://pan.baidu.com/s/1gdB5QLH</u>**

播放器皮肤下载地址: **<u>http://pan.baidu.com/s/1mh7AeG4</u>**

播放器二进制下载地址: **<u>http://download.csdn.net/album/detail/3094</u>**

播放器二进制备选下载地址: **<u>http://pan.baidu.com/s/1kVOHN0b</u>**

播放器移动版地址: **<u>https://github.com/Greedysky/TTKMusicplayer/tree/mobile</u>**

酷狗破解皮肤资源地址: **<u>https://github.com/Greedysky/KugouResource</u>**

特性
-------
TTKMusicPlayer的一些特性
 * 支持绝大多数的音频播放格式。
 * SID File(*.sid *.mus *.str *.prg *.P00)
 * MusePack File(*.mpc)
 * WavPack File(*.wv)
 * Ogg Vorbis File(*.ogg)
 * Ogg Opus File(*.opus)
 * ADTS AAC File(*.aac)
 * MIDI File(*.mid)
 * PCM File(*.wav *.au *.snd *.aif *.aiff *.8svx *.sph *.sf *.voc *.w64)
 * CUE File(*.cue)
 * MPEG File(*.mp1 *.mp2 *.mp3 *.wav)
 * Game Audio File(*.ay *.gms *.gym *.hes *.kss *.nsf *.nsfe *.sap *.spc *.vgm *.vgz)
 * FLAC File(*.flac *.oga)
 * Monkey's Audio File(*.ape)
 * FFmpeg File(*.wma *.ape *.tta *.m4a *.ra *.shn *.vqf *.ac3 *.tak *.dsf *.dsdiff)
 * ModPlug File(*.mod *.s3m *.xm *.it *.669 *.amf *.ams *.dbm *.dmf *.dsm *.far,mdl *.med *.mtm *.okt *.ptm *.stm *.ult *.umx *.mt2 *.psm *.mdz *.s3z *.xmz *.itz *.mdr *.s3r *.xmr *.itr *.dgz *.s3gz *.xmgz *.itgz)
 * AdLib Sound File(*.adl *.hsc *.ksm *.lds)
 * Apple Lossless Audio File(*.alac)
 * Another Slight Atari File(*.sap *.cm3 *.cmc *.cmr *.cms *.dmc *.dlt *.mpd *.mpt *.rmt *.tm2 *.tm8 *.tmc *.fc)
 * DTS Coherent Acoustics File(*.wav *.dts *.cpt)
 * Dynamic Universal File(*.mod *.mdz *.stk *.m15 *.fst *.oct *.nt *.s3m *.s3z *.stm *.stz *.it *.itz *.xm *.xmz *ptm *.ptz *mtm *.mtz *669 *psm *umx *am *.j2b *dsm *amf *okt *.okta *mo3)
 * Future Composer File(*.fc *.fc13 *.fc14 *.smod)
 * OptimFrog File(*.ofr *.ofs)
 * Audio Overload File(*.psf *.psf2 *.spu *.ssf *.qsf *.dsf *.minipsf *.minipsf2 *.minissf *.miniqsf *.minidsf)
 * Atari ST(E) And Amiga File(*.sndh *.snd *.sc68)
 * Speex Audio File(*.spx)
 * V2 Module Audio File(*.v2m)
 * AY/YM Audio File(*.vtx *.asc *.sqt *psg *.stc *.stp *.pt1 *.pt2 *.pt3 *.psc *.ay *.ym)
 * ST-Sound File(*.ym)
 * 支持的播放列表格式(tkpl, m3u, m3u8, pls, wpl, xspf, asx, kwl, kgl, fpl, csv, txt, nfn)
 * 华丽流星炫酷的界面设计，跨平台有良好的性能表现。
 * 搜索和高速下载。歌曲搜索精度优化，智能节省带宽，可以禁用网络功能，支持8个国内音乐平台曲库。
 * 支持本地播放，兼容所有音频文件，超级完美的声音，音乐和更吸引人。
 * 友好的用户设计。注重细节设计，个性化，操作简单，发现音乐更方便。
 * 个性化手机铃声。铃声DIY，让你拥有个性化的铃声。
 * 个性化皮肤。DIY你自己的个性化皮肤，创造属于你的专属皮肤。
 * 音乐立方体模型。进入迷你模式后，它会在你的桌面上保留一个“三叶草”形状的图标，你可以自由拖动桌面，你想控制播放器，剪切歌曲，播放，控制歌词，控制音量。
 * 彩色定制皮肤。您可以选择肤色，设置自由的透明度，并支持透明磨砂玻璃（Windows Aero效果）。
 * 搜索下载管理器。搜索结果标签合并-所有的搜索结果标签集中在一个标签下，使操作更容易。
 * 本地音乐搜索，云音乐库和互动。
 * 支持不同音乐格式的转换，可以像汤姆猫一样改变声音，也可以增强声音。
 * 本地音乐传输到云或移动设备。
 * 本地音乐和人声哼唱识别。
 * 支持音乐歌曲、艺术家、专辑、播放列表、热门列表和电影搜索。
 * 支持音乐数字信号处理效果和视觉效果。
 * 音乐歌曲谱（projectm，goom，sonique，florid，wavebar）支持。
 * 支持音乐重放扫描和写入。
 * 支持音乐屏幕保护程序。
 

快照
----
### 首页
![首页](https://github.com/Greedysky/Resource/blob/master/Screen/1.jpg?raw=true)

### 搜索
![搜索](https://github.com/Greedysky/Resource/blob/master/Screen/2.jpg?raw=true)

### 歌词
![歌词](https://github.com/Greedysky/Resource/blob/master/Screen/3.jpg?raw=true)

### 桌面歌词
![桌面歌词](https://github.com/Greedysky/Resource/blob/master/Screen/4.jpg?raw=true)

### 遥控器
![遥控器](https://github.com/Greedysky/Resource/blob/master/Screen/5.jpg?raw=true)

### 歌词拓展显示
![歌词拓展显示](https://github.com/Greedysky/Resource/blob/master/Screen/6.jpg?raw=true)

### MV
![MV](https://github.com/Greedysky/Resource/blob/master/Screen/7.jpg?raw=true)

### 视频弹幕
![视频弹幕](https://github.com/Greedysky/Resource/blob/master/Screen/8.jpg?raw=true)

### 音效
![音效](https://github.com/Greedysky/Resource/blob/master/Screen/9.jpg?raw=true)

### 工具
![工具](https://github.com/Greedysky/Resource/blob/master/Screen/10.jpg?raw=true)

### 音乐频谱
![音乐频谱](https://github.com/Greedysky/Resource/blob/master/Screen/11.jpg?raw=true)

### 其他功能
![其他功能](https://github.com/Greedysky/Resource/blob/master/Screen/12.jpg?raw=true)

版权
-------
 * This file is part of the TTK Music Player project.
 * Copyright (c) 2015 - 2020 Greedysky Studio.
 * Mail: greedysky@163.com.
 
贡献
-------
 * Fork this project on github and make a branch. Commit in that branch, and push, then create a pull request to be reviewed and merged.
 * Create an issue if you have any problem when using project or you find a bug, etc.
 * What you can do: translation, write document, wiki, find or fix bugs, give your idea for this project etc.
 * If you want to join the project developed together, please send e-mail to me.
