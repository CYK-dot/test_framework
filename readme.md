# 测试框架
一个简单的，快速上手的测试框架，集成gtest/gmock，并且支持代码覆盖率收集。

# 环境准备
- minGW64，并且配置好环境变量，能检索到make、gcc等命令
- cmake
- python3，安装gcovr
- https://app.codecov.io/gh 注册账号且关联github账号，并关闭上传覆盖率所需的token

# 使用方式
1. 确保工作目录如下所示
```
YourProject/
├── .vscode/     vscode相关的配置文件
├── .github/     github相关的配置文件
├    ├─workflows/ CI流水线配置
├── projectCode/ 需要被测试的代码
├── test/        测试项目所在的目录
├    ├─script/   测试框架相关的脚本
├    ├─lib/      编译生成的gtest/gmock库
├    ├─vscode_cfg/ vscode相关的配置文件
├    ├─build/     编译生成的文件
├    ├─testcase/  测试用例代码
```

2. 将vscode_cfg文件夹中的内容拷贝到工作区中的.vscode目录下
3. ctrl+shift+b，即可找到三个任务，分别为
    - setup
    - build
    - run
4. 将ci文件夹下的build-and-test.yml文件拷贝到.github/workflows目录下，并重命名为ci.yml
