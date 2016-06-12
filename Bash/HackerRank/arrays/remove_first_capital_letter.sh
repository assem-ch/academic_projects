#!/usr/bin/env bash

LOOP=1
for((i = 0; $LOOP; i++));
do
    read k || LOOP=0;

    a[$i]=`echo $k | sed s/./\./1`;
done;
echo ${a[@]} #!/usr/bin/env bash