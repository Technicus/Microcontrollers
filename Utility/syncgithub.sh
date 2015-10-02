#!/bin/bash

push(){
  cd ..
  git add .
  # echo "git commit -m $@"     # test commit message
  git commit -m '$@'
  git push origin master
  echo
  exit 1
}

checkParameters(){
  if [[ "$1" < "1" ]]
  then
    echo "      Usage:"
    echo "              Be sure to include a commit message!"
    echo
    exit 1
  else
    push "${@:2}"
  fi
}

showopts () {
  while getopts ":pq:" optname
    do
      case "$optname" in
        "p")
          echo "Option $optname is specified"
          ;;
        "q")
          echo "Option $optname has value $OPTARG"
          ;;
        "?")
          echo "Unknown option $OPTARG"
          ;;
        ":")
          echo "No argument value for option $OPTARG"
          ;;
        *)
        # Should not occur
          echo "Unknown error while processing options"
          ;;
      esac
    done
  return $OPTIND
}

showargs () {
  for p in "$@"
    do
      echo "[$p]"
    done
}

argumentDescription(){
  optinfo=$(showopts "$@")
  argstart=$?
  arginfo=$(showargs "${@:$argstart}")
  echo "Arguments are:"
  echo "$arginfo"
  echo "Options are:"
  echo "$optinfo"
}

echo
checkParameters $# $@
# argumentDescription
# echo exit test