/*
    TS2017 - не изменять
    Запустите плагин, посмотрите на выводимую дату, сравните со временем на этом сайте:
    http://доновогогода.рф/
    Скорректируйте TSOFFS на нужное кол-во часов.

    Полезные символы для оформления:
    ❄  ❆  ❅ ★ ✫ ✬ ✭ ✮ ✯ ✰ ✱ ✲ ✳ ✴ ✵ ✶ ✷ ✸ ✹ ✺ ✻ ✼ ✽ ✾ ✿ ❀ ❁ ❂ ❃ ❇ ❈ ❉ ❊ ❋
    Список цветов в чате:
    https://forums.alliedmods.net/showpost.php?p=2271367&postcount=3
    За основу взят код Danyas: http://hlmod.ru/threads/new-year-seconds.13953/page-3#post-226292
*/

#define TS2020 1483228800
#define TSOFFS -3

public Plugin myinfo = {
    name = "New Year Timeleft"
};

public void OnPluginStart() {
    CreateTimer(1.0, StartTimer_CallBack);
}

public Action StartTimer_CallBack(Handle timer) {
    PrintTimer();
    CreateTimer(GetRandomFloat(300.0, 600.0), StartTimer_CallBack);
}

stock void PrintTimer(int offset = TSOFFS) {
    int sec = 1483228800 - GetTime()+TSOFFS*3600;
    if (sec > 0) {
        PrintToChatAll(" \x0B❄❅❄ \x01До Нового Года осталось: \x0B%d\x08д. \x0B%d\x08ч. \x0B%d\x08м. \x0B%02d\x08сек.", sec/3600/24, sec/3600%24, sec/60%60, sec%60);
    }
    else {
        switch (GetRandomInt(1,3)) {
            case 2: {
                PrintToChatAll(" \x0B❅❅❅ \x01С Новым Годом! \x0B❅❅❅");
            }
            case 3: {
                PrintToChatAll(" \x06❅❅❅ \x01С Новым Годом! \x06❅❅❅");
            }
            default: {
                PrintToChatAll(" \x0F❅❅❅ \x01С Новым Годом! \x0F❅❅❅");
            }
        }
    }
}