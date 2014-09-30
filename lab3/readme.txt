说明：
    menu.h中新添加了接口GetCmdNode()，并且在menu.c中添加了测试桩。
    测试系统主要分为两部分：
        一部分用于测试menu.h中各单元接口，直接运行./test既可。
        一部分用于模拟用户输入测试menu的功能，直接运行./test-shell.sh既可（若不能运行，请运行sudo chmod +x test-shell
修改权限）

ps:如果不能执行，请尝试运行make生成test 和 demo 
