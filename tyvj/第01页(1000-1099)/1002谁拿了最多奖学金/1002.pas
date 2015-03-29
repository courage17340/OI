type
  arr=
    record
      name:string;
      qimo,ban,lun,money:longint;
      monitor,west:char;
      end;
var
  a:array[0..100] of arr;
  n,i,k,total:longint;
  ch:char;
  st:string;
begin
  readln(n);
  for i:=1 to n do
    begin
      st:='';
      repeat
        read(ch);
        if ch<>' ' then st:=st+ch;
        until ch=' ';
      a[i].name:=st;
      read(a[i].qimo,a[i].ban);
      repeat read(ch);if ch<>' ' then begin a[i].monitor:=ch;break;end;until false;
      repeat read(ch);if ch<>' ' then begin a[i].west:=ch;break;end;until false;
      readln(a[i].lun);
    end;
  k:=0;
  total:=0;
  for i:=1 to n do
    begin
      a[i].money:=0;
      if (a[i].qimo>80)and(a[i].lun>0) then a[i].money:=a[i].money+8000;
      if (a[i].qimo>85)and(a[i].ban>80) then a[i].money:=a[i].money+4000;
      if a[i].qimo>90 then a[i].money:=a[i].money+2000;
      if (a[i].west='Y')and(a[i].qimo>85) then a[i].money:=a[i].money+1000;
      if (a[i].monitor='Y')and(a[i].ban>80) then a[i].money:=a[i].money+850;
      if a[i].money>k then begin k:=a[i].money;st:=a[i].name; end;
      total:=total+a[i].money;
    end;
  writeln(st);
  writeln(k);
  writeln(total);
end.