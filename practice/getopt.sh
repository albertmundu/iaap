


optstring=abc:


while getopts ab: name
do
    case $name in
    a) echo $OPTARG
    break;;
    esac
done


