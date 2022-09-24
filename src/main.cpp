#include "bsc/main_app.h"
#include "bsc/app_bar.h"
#include "bsc/scaffold.h"
#include "bsc/container.h"
#include "bsc/column.h"
#include "bsc/text.h"

#include<vector>

int main()
{

    std::vector<MenuItem> fileItems{
        MenuItem{
            "New",
            "Ctrl+N",
            nullptr
        },
        MenuItem{
            "Open",
            "Ctrl+O",
            nullptr
        },
        MenuItem{
            "Save",
            "Ctrl+S",
            nullptr
        },
        MenuItem{
            "Prefences",
            "Ctrl+P",
            nullptr
        },
        MenuItem{
            "Quit",
            "Ctrl+Q",
            nullptr
        }
    };

    std::vector<MenuItem> editItems{
        MenuItem{
            "Undo",
            "Ctrl+Z",
            nullptr
        },
        MenuItem{
            "Redo",
            "Ctrl+Y",
            nullptr
        },
    };
    
    std::vector<MenuButton> menu{ 
        MenuButton{
            "File",
            nullptr,
            &fileItems
        },
        MenuButton{
            "Edit",
            nullptr,
            &editItems
        },
        MenuButton {
            "About",
            [](){
                std::cout<<"Hello About"<<std::endl;
            }
        }
    };

    MainApp * app = new MainApp(
        "My App Title", 
        new Scaffold(
            new NavBar(
                "Brand",
                &menu
            ),
            new Container(
                "first",
                new Text("Hello My Friends")
            )
        )
    );
    app->run();

    delete app;
    return 0;
}