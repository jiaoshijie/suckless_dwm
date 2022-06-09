/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {"monospace:size=10", "WenQuanYi Micro Hei:pixelsize=10:antialias=true:autohint=true", "JoyPixels:pixelsize=10:antialias=true:autohint=true"};
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_magenta[]     = "#FF00FF";
static const char col_blue[]        = "#5587FF";
static const char col_light_bg[] = "#E8DFE2";
static const char col_light_fg[] = "#2C1E1D";
static const char col_dark_bg[]  = "#252525";
static const char col_dark_fg[]  = "#E5E5E5";
static const char *colors[][3]      = {
  /*               fg         bg         border   */
    [SchemeNorm] = {col_light_fg, col_light_bg, col_gray1},
    [SchemeSel] = {col_blue, col_light_bg, col_magenta},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
  /* xprop(1):
   *  WM_CLASS(STRING) = instance, class
   *  WM_NAME(STRING) = title
   */
  /* class, instance, title, tags mask, isfloating, monitor */
  // floating
  {"GIMP Startup", NULL, NULL, 0, 1, -1},
  {"shadowsocks-qt5", "ss-qt5", NULL, 0, 1, -1},
  {"VirtualBox Manager", "VirtualBox Manager", NULL, 0, 1, -1},
  // {"VirtualBox", NULL, NULL, 0, 0, -1},
  {"VirtualBox Machine", "VirtualBox Machine", NULL, 0, 0, -1},
  {"Gcolor2", NULL, NULL, 0, 1, -1},
  {"flameshot", NULL, NULL, 0, 1, -1},
  {"Nutstore", NULL, NULL, 0, 1, -1},
  {"Qemu-system-i386", NULL, NULL, 0, 1, -1},
  {"Pavucontrol", NULL, NULL, 0, 1, -1},
  {"GoldenDict", NULL, NULL, 0, 1, -1},
  {"copyq", NULL, NULL, 0, 1, -1},
  {"fcitx5-config-qt", NULL, NULL, 0, 1, -1},
  {"Webcamoid", "webcamoid", NULL, 0, 1, -1},
  {"Lxappearance", NULL, NULL, 0, 1, -1},
  {"qt5ct", NULL, NULL, 0, 1, -1},
  {"qt6ct", NULL, NULL, 0, 1, -1},
  {"smplayer", NULL, NULL, 0, 1, -1},
  {"Sxiv", "DingImage", NULL, 0, 1, -1},
  {"Pcmanfm", "pcmanfm", NULL, 0, 1, -1},
  {"eudic", NULL, NULL, 0, 1, -1},

  // conflict
  {"Alacritty", "Alacritty", "filemanager", 0, 1, -1},
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "[M]",      monocle },
  { "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
  /* modifier                     key        function        argument */
  { MODKEY|ShiftMask,             XK_e,      quit,           {0} },
  TAGKEYS(                        XK_1,                      0)
  TAGKEYS(                        XK_2,                      1)
  TAGKEYS(                        XK_3,                      2)
  TAGKEYS(                        XK_4,                      3)
  TAGKEYS(                        XK_5,                      4)
  TAGKEYS(                        XK_6,                      5)
  TAGKEYS(                        XK_7,                      6)
  TAGKEYS(                        XK_8,                      7)
  TAGKEYS(                        XK_9,                      8)
  { MODKEY,                       XK_Tab,    view,           {0} },  // 在最近的两个tag之间交换
  // { MODKEY,                       XK_0,      view,           {.ui = ~0 } },  // 在一个窗口显示所有标签中的内容
  // { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },  // 将当前选中的窗口放在所有标签中同步显示

  // { MODKEY,                       XK_minus,  togglescratch,  {.v = scratchpadcmd } },

  { MODKEY | ShiftMask , XK_f , togglebar     , {0} } ,
  { MODKEY             , XK_f , togglefullscr , {0} } ,

  { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY,                       XK_space, zoom,           {0} },
  { MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
  { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },

  // 修改 "[]=" 的布局方式
  // { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
  // { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },

  { MODKEY             , XK_0 , setlayout , {.v = &layouts[0]} } ,
  { MODKEY | ShiftMask , XK_0 , setlayout , {.v = &layouts[1]} } ,
  // { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[2]} },
  // { MODKEY,                       XK_space,  setlayout,      {0} },  // 在最近的两个layout之间交换

  { MODKEY | ShiftMask,    XK_j,      justFMove,     {.v = "0x 25y" } },  // move
  { MODKEY | ShiftMask,    XK_k,      justFMove,     {.v = "0x -25y" } },
  { MODKEY | ShiftMask,    XK_l,      justFMove,     {.v = "25x 0y" } },
  { MODKEY | ShiftMask,    XK_h,      justFMove,     {.v = "-25x 0y" } },

  {MODKEY, XK_s,      spawn,          SHCMD("~/dotfiles/my_script/tray_toggle.sh")},

  // NOTE: 多显示器(monitor)
  { MODKEY,                       XK_Left,  focusmon,       {.i = -1 } },
  { MODKEY,                       XK_Right, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_Left,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_Right, tagmon,         {.i = +1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
