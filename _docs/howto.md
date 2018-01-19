## Как работает

***
### Программа UPDATER

- Проверка где установлен WORKER
    через [!QSettings][http://doc.crossplatform.ru/qt/4.7.x/qsettings.html]
    работает как на Windows так на Linux и Mac OS, если указаны компания и продукт.
    два пути:
    > QSettings settings("My Company", "My Product");
    либо
    > QCoreApplication::setOrganizationName("My Company");
    > QCoreApplication::setOrganizationDomain("mycompany.com");
    > QCoreApplication::setApplicationName("My Product");
    > QSettings settings;
    Механизм альтернативы
    > QSettings obj1("MySoft", "Star Runner");
    > QSettings obj2("MySoft");
    > QSettings obj3(QSettings::SystemScope, "MySoft", "Star Runner");
    > QSettings obj4(QSettings::SystemScope, "MySoft");
    [!sample][http://doc.crossplatform.ru/qt/4.7.x/tools-settingseditor-mainwindow-cpp.html]
- Читаем из конфига url центрального хранилища (по умолчагию ...)
- Проверка обновления WORKER и обновляем

***
### Программа WORKER

- Проверка где установлен WORKER
иначе регистрируем текущий каталог
- Читаем из конфига url центрального хранилища (по умолчагию ...)
- Проверка обновления UPDATER и обновляем
- Проверка обновления WORKER и запускаем UPDATER
- Проверка обновления других


SingleApp
http://habrahabr.ru/post/173281/
