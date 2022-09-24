#include "bsc/main_app.h"
#include "bsc/app_bar.h"
#include "bsc/scaffold.h"
#include "bsc/container.h"
#include "bsc/column.h"
#include "bsc/row.h"
#include "bsc/text.h"
#include<vector>

#include "./custom_widget.h"

int count = 0;

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

    StatefullWidget * myWgt = new StatefullWidget();
    myWgt->build(
        new Button(
            "Inc Count: " + std::to_string(count),
            [](){
                count++;   
                std::cout<<count<<std::endl;
            }
        )
    );
    

    std::vector<Widget*> row1{
        new Text("This is a column 1"),
        new Text("This is a row 1"),
        new Text("This is a row 2"),
        myWgt
    };

    std::vector<Widget*> row2{
        new Text("This is a column 4"),
        new Button(
            "Dec Count: " + std::to_string(count),
            [](){
                count--;
                std::cout<<count<<std::endl;
            }
        )
    };

    std::vector<Widget*> cols{
        new Row(row1),
        new Text("This is a column 2"),
        new Text("This is a column 3"),
        new Row(row2)
    };

    MainApp * app = new MainApp(
        "My App Title", 
        new Scaffold(
            new NavBar(
                "Apple",
                &menu
            ),
            new Container(
                "cont-1",
                new Column(
                    cols
                )
            )
        )
    );
    app->run();

    return 0;
}