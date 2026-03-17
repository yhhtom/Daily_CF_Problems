@echo off
echo === 开始同步 ===

:: 1. 【关键】无论当前状态如何，先暂存并提交本地修改，防止切换分支丢失文件
:: 如果没有任何修改，git commit 会失败，我们用 || echo 忽略这个错误继续执行
git add -A
git commit -m "Auto-save before sync" || echo [提示] 没有需要保存的本地修改，跳过此步。

:: 2. 切换到 main 并拉取 upstream 最新代码
git checkout main
git pull upstream main

:: 3. 切回 practice 并合并 main
git checkout practice
git merge main --no-edit

:: 4. 提交合并结果并推送到 origin
git add -A
git commit -m "Daily submission: merged upstream updates" || echo [提示] 没有新变化，跳过提交。
git push origin practice

echo === 同步完成 ===
pause