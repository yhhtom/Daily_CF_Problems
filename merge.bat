@echo off
chcp 65001 > nul

:: 1. 先把本地没保存的改动存起来（防止 rebase 冲突）
call git add -A
call git commit -m "Auto-save: %date% %time%"

:: 2. 核心操作：拉取上游代码并把你的 practice 分支“接”上去
:: 这行直接代替了切换到 main、pull、再切回、再 merge 的所有步骤
call git pull --rebase upstream main

:: 3. 推送
:: 注意：如果你之前已经 push 过，rebase 后可能需要 -f（强推），因为你改写了历史
call git push origin practice -f

echo 同步完成！
pause