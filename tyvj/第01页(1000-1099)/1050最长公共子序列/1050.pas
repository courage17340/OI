var
  st1,st2:ansistring;
  ch:char;
  L1,L2,i,j:longint;
  f:array[0..2000,0..2000] of longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
begin
  st1:='';
  repeat
    read(ch);
    if ch<>' ' then st1:=st1+ch;
    until ch=' ';
  readln(st2);
  L1:=length(st1);
  L2:=length(st2);
  fillchar(f,sizeof(f),0);
  for i:=1 to L1 do
    for j:=1 to L2 do
      if st1[i]=st2[j]
        then f[i,j]:=f[i-1,j-1]+1
        else f[i,j]:=max(f[i-1,j],f[i,j-1]);
  writeln(f[L1,L2]);
end.