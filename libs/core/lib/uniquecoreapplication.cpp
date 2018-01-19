#include "uniquecoreapplication.h"
#include "localpeer.h"

ASU_USE_NAMESPACE

/*!
    \class UniqueCoreApplication uniquecoreapplication.h
    \brief A variant of the QtSingleApplication class for non-GUI applications.

    This class is a variant of QtSingleApplication suited for use in
    console (non-GUI) applications. It is an extension of
    QCoreApplication (instead of QApplication). It does not require
    the QtGui library.

    The API and usage is identical to QtSingleApplication, except that
    functions relating to the "activation window" are not present, for
    obvious reasons. Please refer to the QtSingleApplication
    documentation for explanation of the usage.

    A UniqueCoreApplication instance can communicate to a
    QtSingleApplication instance if they share the same application
    id. Hence, this class can be used to create a light-weight
    command-line tool that sends commands to a GUI application.

    \sa UniqueCoreApplication
*/

/*!
    Creates a UniqueCoreApplication object. The application identifier
    will be QCoreApplication::applicationFilePath(). \a argc and \a
    argv are passed on to the QCoreAppliation constructor.
*/

UniqueCoreApplication::UniqueCoreApplication(int &argc, char **argv)
    : QCoreApplication(argc, argv)
{
    peer = new LocalPeer(this);
    connect(peer, SIGNAL(messageReceived(const QString&)), SIGNAL(messageReceived(const QString&)));
}


/*!
    Creates a UniqueCoreApplication object with the application
    identifier \a appId. \a argc and \a argv are passed on to the
    QCoreAppliation constructor.
*/
UniqueCoreApplication::UniqueCoreApplication(const QString &appId, int &argc, char **argv)
    : QCoreApplication(argc, argv)
{
    peer = new LocalPeer(this, appId);
    connect(peer, SIGNAL(messageReceived(const QString&)), SIGNAL(messageReceived(const QString&)));
}


/*!
    Returns true if another instance of this application is running;
    otherwise false.

    This function does not find instances of this application that are
    being run by a different user (on Windows: that are running in
    another session).

    \sa sendMessage()
*/

bool UniqueCoreApplication::isRunning()
{
    return peer->isClient();
}


/*!
    Tries to send the text \a message to the currently running
    instance. The UniqueCoreApplication object in the running instance
    will emit the messageReceived() signal when it receives the
    message.

    This function returns true if the message has been sent to, and
    processed by, the current instance. If there is no instance
    currently running, or if the running instance fails to process the
    message within \a timeout milliseconds, this function return false.

    \sa isRunning(), messageReceived()
*/

bool UniqueCoreApplication::sendMessage(const QString &message, int timeout)
{
    return peer->sendMessage(message, timeout);
}


/*!
    Returns the application identifier. Two processes with the same
    identifier will be regarded as instances of the same application.
*/

QString UniqueCoreApplication::id() const
{
    return peer->applicationId();
}


/*!
    \fn void UniqueCoreApplication::messageReceived(const QString& message)

    This signal is emitted when the current instance receives a \a
    message from another instance of this application.

    \sa sendMessage()
*/
