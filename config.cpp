#include "config.h"

namespace config {
    QUrl apiUrl {"https://ditalk.xyz"};
    QHash<QString, QString> endPoints(  {{"login", "/login.php"}, {"logout", "/logout.php"},
                                        {"chat", "/chat.php"}, {"usersConnect", "/usersConnect.php"}});
}
