git clone https://github.com/iam2soup/RAGcloth.git
# Source - https://stackoverflow.com/a/42876846
# Posted by Socowi, modified by community. See post 'Timeline' for change history
# Retrieved 2026-05-08, License - CC BY-SA 4.0

if [[ "$EUID" = 0 ]]; then
    #echo "(1) already root"
else
    sudo -k # make sure to ask for password on next sudo ✱
    if sudo true; then
        #echo "(2) correct password"
    else
        #echo "(3) wrong password"
        exit 1
    fi
fi
# Do your sudo stuff here. Password will not be asked again due to caching.
sudo bash lin2build.sh
#test wip v1
