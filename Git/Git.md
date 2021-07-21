# Use Of Git

<!-- TOC -->

- [Use Of Git](#use-of-git)
    - [Git 配置](#git-%E9%85%8D%E7%BD%AE)
        - [配置git用户名和邮箱](#%E9%85%8D%E7%BD%AEgit%E7%94%A8%E6%88%B7%E5%90%8D%E5%92%8C%E9%82%AE%E7%AE%B1)
    - [初始化仓库](#%E5%88%9D%E5%A7%8B%E5%8C%96%E4%BB%93%E5%BA%93)
    - [添加文件、目录](#%E6%B7%BB%E5%8A%A0%E6%96%87%E4%BB%B6%E7%9B%AE%E5%BD%95)
    - [提交版本](#%E6%8F%90%E4%BA%A4%E7%89%88%E6%9C%AC)
    - [撤销 commit](#%E6%92%A4%E9%94%80-commit)
    - [撤销 add](#%E6%92%A4%E9%94%80-add)
    - [连接远程主机](#%E8%BF%9E%E6%8E%A5%E8%BF%9C%E7%A8%8B%E4%B8%BB%E6%9C%BA)
    - [推送至远程仓库](#%E6%8E%A8%E9%80%81%E8%87%B3%E8%BF%9C%E7%A8%8B%E4%BB%93%E5%BA%93)
    - [改动查询](#%E6%94%B9%E5%8A%A8%E6%9F%A5%E8%AF%A2)
    - [查看历史提交](#%E6%9F%A5%E7%9C%8B%E5%8E%86%E5%8F%B2%E6%8F%90%E4%BA%A4)
    - [分支相关命令如下：](#%E5%88%86%E6%94%AF%E7%9B%B8%E5%85%B3%E5%91%BD%E4%BB%A4%E5%A6%82%E4%B8%8B)
- [推送](#%E6%8E%A8%E9%80%81)
    - [新建仓库](#%E6%96%B0%E5%BB%BA%E4%BB%93%E5%BA%93)
    - [更新文件](#%E6%9B%B4%E6%96%B0%E6%96%87%E4%BB%B6)
- [常见问题解决方法](#%E5%B8%B8%E8%A7%81%E9%97%AE%E9%A2%98%E8%A7%A3%E5%86%B3%E6%96%B9%E6%B3%95)
    - [拒绝合并无关的历史](#%E6%8B%92%E7%BB%9D%E5%90%88%E5%B9%B6%E6%97%A0%E5%85%B3%E7%9A%84%E5%8E%86%E5%8F%B2)
    - [git clone、git pull、git fetch の区别？](#git-clonegit-pullgit-fetch-%E3%81%AE%E5%8C%BA%E5%88%AB)

<!-- /TOC -->

## Git 配置

优先级：`--local > --global > --system`

> 用了`--global`这个参数，表示你这台机器上所有的Git仓库都会使用这个配置

### 1.配置git用户名和邮箱

```bash
git config --global user.name        # 查看
git config --global user.name 用户名  # 修改
git config --global user.email       # 查看
git config --global user.email 邮箱   # 修改
```

## 初始化仓库
```bash
git init 仓库名  #创建一个git仓库
git init        #将一个项目转化为使用git管理（创建.git目录）
```

## 添加文件、目录
将修改添加到暂存区：
```bash
git add 文件/目录
```

## 提交版本
使用commit提交修改，实际上就是把暂存区的所有内容提交到当前分支：
```bash
git commit -m '信息'
```

## 撤销 commit
```bash
git reset --soft HEAD^
```
--soft
不删除工作空间的改动代码 ，撤销 commit，不撤销 git add file

## 撤销 add
```bash
git reset --hard HEAD^
```
--hard
删除工作空间的改动代码，撤销 commit 且撤销 add

## 连接远程主机
```bash
git remote add origin 远程仓库地址
```

## 推送至远程仓库
```bash
git push origin 欲推送的分支
```

## 改动查询
```bash
git diff [选项]           # 查看工作区中的修改
git diff [选项] --staged   # 查看已添加到暂存区的修改
git diff [选项] HEAD       # 查看当前所有未提交的修改

选项：
    --color-words： 颜色
    --stat：        不显示具体修改，只显示修改了的文件
```

## 查看历史提交
```bash
git log [选项]

选项：
    --online：只显示提交提示信息
    --stat：添加每次提交包含的文件信息
    --path：查看每次提交改变的内容
    --graph
```

## 分支相关命令如下：

* (创建分支并)切换到新分支：`git checkout -b 新分支`
* 创建分支：`git branch 新分支`
* 切换分支：`git checkout 欲切换到的分支`
* 查看当前分支：`git branch`
* 合并某分支到当前分支：`git merge 欲合并到当前分支的分支`
* 查看历史分支情况：`git log --graph --pretty=oneline --abbrev-commit`
* 删除未合并的分支：`git branch -D 分支`

<br><br>

# 推送
## 新建仓库
1. 首先在 GitHub 上创建新的仓库，添加进去必要的 LICENSE 和 .gitignore 文件；
2. 然后将这个仓库 clone 到本地；
3. 然后将你新文件写在里边，之后就可以 add 等一套了；

## 更新文件
1. 如果是本地比远程仓库更新，则直接 add 一套；
2. 如果远程仓库比本地仓库新，则向 fetch 更新本地仓库，然后 add 一套新文件；

<br><br>

# 常见问题解决方法
## 拒绝合并无关的历史

* [`git pull "fatal: 拒绝合并无关的历史"`](https://www.cnblogs.com/xidianzxm/p/12965841.html)
```bash
git init
git add .
git commit "提交说明"
# 连接远程主机：
git remote add  origin  远程仓库地址
git  push origin master
```
**报错：**
```bash
 ! [rejected]        master -> master (non-fast-forward)
error: 推送一些引用到 'git@codehub.devcloud:Openxt00001/open.git' 失败
提示：更新被拒绝，因为您当前分支的最新提交落后于其对应的远程分支。
提示：再次推送前，先与远程变更合并（如 'git pull ...'）。详见
提示：'git push --help' 中的 'Note about fast-forwards' 小节。
```
提示先拉取：
```bash
MacBook-Pro:~/go/src/demo/open$ git pull origin master
来自 codehub.devcloud.enxt00001/open
 * branch            master     -> FETCH_HEAD
fatal: 拒绝合并无关的历史
```
解决办法：
```bash
git pull origin 分支 --allow-unrelated-histories 
```
原因：可能是远程仓库与本地仓库没有相关的文件，git合并命令拒绝合并没有共同祖先的历史。

## `git clone、git pull、git fetch の区别？`
  - https://blog.csdn.net/zhou_xiaomiao/article/details/53185712
  - https://www.cnblogs.com/lalalagq/p/9968949.html

`git clone:`克隆远程仓库到本地，也就是从无到有的状态；也就不再需要 `git init`，直接使用`clone`的仓库管理；

`git pull:`拉取远程分支更新到本地仓库的操作。`git pull`是相当于从远程仓库获取最新版本，然后再与本地分支merge（合并），`git pull = git fetch + git merge`；

- `git pull  远程主机名  远程分支名:本地分支名`

- 举例：将远程主机origin的master分支拉取过来，与本地的branchtest分支合并。

- `git pull origin master:branchtest`

- 如果将冒号和后面的branchtest去掉，则表示将远程origin仓库的master分支拉取下来与本地当前分支合并。

`git fetch:`更新远程代码到本地仓库；更安全也更符合实际要求；

```bash
$ git fetch origin master:temp           #从远程的origin仓库的master分支下载到本地并新建一个分支temp
$ git diff temp                          #比较master分支和temp分支的不同
$ git merge temp                         #合并temp分支到master分支
$ git branch -d temp                     #删除temp
```
