#include "config.h"

namespace config {
    QUrl apiUrl {"https://ditalk.xyz"};
    QHash<QString, QString> endPoints(  {{"login", "/login.php"}, {"logout", "/logout.php"},
                                        {"chat", "/chat.php"}, {"usersConnect", "/usersConnect.php"}});
    QString jsonClientInfoPath { "./client_info.json" };
    qint64 chatPollFreqMilliSecs = 1000;
}
