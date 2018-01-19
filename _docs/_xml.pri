FILENAME = app.xml
#
windows: QUOTES=\"
else: QUOTES=\\\"
#
write("<?xml version=$${QUOTES}1.0$${QUOTES} encoding=$${QUOTES}UTF-8$${QUOTES}?>", >)
write("<!DOCTYPE eApp>", >>)
write("<app id=$${QUOTES}$${QMAKE_TARGET_PRODUCT}$${QUOTES} name=$${QUOTES}$${QMAKE_PROJECT_NAME}$${QUOTES} version=$${QUOTES}$${QMAKE_TARGET_VERSION}$${QUOTES}>", >>)
for(FILE, COMMONS.files){
windows: {
    FILE ~= s,/,\\,g
}
unix: {
    FILE ~= s,\\\\,/,g
}
#    name = $$replace(entry, [/\\\\], _)
    #FILE = $$replace(FILE, $${QT_INSTALL_BINS}, "")
    FILE = $$replace(FILE, "D:\\\\etc\\\\qt\\\\5.4\\\\mingw491_32\\\\bin\\\\", "")
    write("  <file name=$${QUOTES}$${FILE}$${QUOTES} version=$${QUOTES}$${QT_VERSION}$${QUOTES} />", >>)
}
write("  <file name=$${QUOTES}$${TARGET}$${QUOTES} version=$${QUOTES}$${APP.version}$${QUOTES} />", >>)
for(FILE, BUILDS.files){
    FILE ~= s,/,\\,g
    #FILE = $$replace(FILE, $${PWD}, "")
    FILE = $$replace(FILE, "D:\\\\projects\\\\asu\\\\updater\\\\", "")
    write("  <file name=$${QUOTES}$${FILE}$${QUOTES} version=$${QUOTES}$${APP.version}$${QUOTES} />", >>)
}
write("</app>", >>)
#
#$$relative_path
#$$clean_path
#write_file
#$$system_quote
#$$system_path
#$$DIR_SEPARATOR
