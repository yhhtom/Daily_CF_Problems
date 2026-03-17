
git add -A

git commit -m "Auto-save before sync"


git checkout main

git pull upstream


git checkout practice

git merge main

git checkout practice


git add -A

git commit -m "Daily submission: merged upstream updates"

git push origin practice

pause