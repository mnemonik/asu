FILENAME = app.json
#
windows: QUOTES=\"
else: QUOTES=\\\"
#
write("{", >)
write(" $${QUOTES}tmpl$${QUOTES}:$${QUOTES}$${TEMPLATE}$${QUOTES},", >>)
write(" $${QUOTES}id$${QUOTES}:$${QUOTES}$${APP_ID}$${QUOTES},", >>)
write(" $${QUOTES}name$${QUOTES}:$${QUOTES}$${APP_NAME}$${QUOTES},", >>)
write(" $${QUOTES}description$${QUOTES}:$${QUOTES}$${APP_DESC}$${QUOTES},", >>)
write(" $${QUOTES}version$${QUOTES}:$${QUOTES}$${APP_VERSION}$${QUOTES},", >>)
write(" $${QUOTES}site$${QUOTES}:$${QUOTES}$${APP_SITE}$${QUOTES},", >>)
write(" $${QUOTES}author$${QUOTES}:$${QUOTES}$${APP_AUTHOR}$${QUOTES},", >>)
write(" $${QUOTES}license$${QUOTES}:$${QUOTES}$${APP_LICENSE}$${QUOTES},", >>)
#
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
    write("  { $${QUOTES}name$${QUOTES}:$${QUOTES}$${FILE}$${QUOTES}, $${QUOTES}version$${QUOTES}:$${QUOTES}$${QT_VERSION}$${QUOTES} },", >>)
}
for(FILE, BUILDS.files){
    FILE ~= s,/,\\,g
    #FILE = $$replace(FILE, $${PWD}, "")
    FILE = $$replace(FILE, "D:\\\\projects\\\\asu\\\\updater\\\\", "")
    write("  { $${QUOTES}name$${QUOTES}:$${QUOTES}$${FILE}$${QUOTES}, $${QUOTES}version$${QUOTES}:$${QUOTES}$${APP_VERSION}$${QUOTES} },", >>)
}
write("}", >>)
#
#$$relative_path
#$$clean_path
#write_file
#$$system_quote
#$$system_path
#$$DIR_SEPARATOR
