#
ORG.name = asutp
ORG.site = http://172.16.3.40/
#
APP.version = 1.0.0.0
APP.major_version = 1
APP.minor_version = 0
APP.patch_version = 0
APP.build_version = 0
APP.id = 3
APP.name = wpm
APP.file = $${APP.name}
APP.dir = $${APP.name}
APP.desc = Служба менеджера приложений
APP.site = $${ORG.site}app/$${APP.name}
APP.company = ОАО "Синтез-Каучук"
APP.copyright = Copyright (c) цех АСУТП
APP.trade = trade
APP.pict = res/app.ico
#
FILEDEF = app_gen.h
#
windows: QUOTES=\"
else: QUOTES=\\\"
#
system(chcp 1251)
write("$${LITERAL_HASH}ifndef APP_GEN_H", >, $${FILEDEF})
write("$${LITERAL_HASH}define APP_GEN_H", >>, $${FILEDEF})
write("//", >>, $${FILEDEF})
write("$${LITERAL_HASH}define ORG_NAME $${QUOTES}$${ORG.name}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define ORG_SITE $${QUOTES}$${ORG.site}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_ID $${APP.id}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_DIR $${QUOTES}$${APP.dir}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_FILE $${QUOTES}$${APP.file}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_NAME $${QUOTES}$${APP.name}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_DESC $${QUOTES}$${APP.desc}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_SITE $${QUOTES}$${APP.site}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_COPYRIGHT $${QUOTES}$${APP.copyright}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_VERSION $${QUOTES}$${APP.version}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_MAJOR_VERSION $${APP.major_version}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_MINOR_VERSION $${APP.minor_version}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_PATCH_VERSION $${APP.patch_version}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_BUILD_VERSION $${APP.build_version}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_TRADE $${QUOTES}$${APP.trade}$${QUOTES}", >>, $${FILEDEF})
write("$${LITERAL_HASH}define APP_PICT $${QUOTES}$${APP.pict}$${QUOTES}", >>, $${FILEDEF})
write("//", >>, $${FILEDEF})
write("$${LITERAL_HASH}endif // APP_GEN_H", >>, $${FILEDEF})
#
