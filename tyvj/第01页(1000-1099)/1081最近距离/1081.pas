var
  a:array[0..2010,1..2] of longint;
  f:array[0..2010,0..2010] of int64;
  i,j,n,p,q:longint;
  x:int64;
begin
  readln(n);
  for i:=1 to n do readln(a[i,1],a[i,2]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      f[i,j]:=int64(int64((a[i,1]-a[j,1])*int64(a[i,1]-a[j,1]))+int64(a[i,2]-a[j,2])*int64(a[i,2]-a[j,2]));
  x:=f[1,2];
  p:=1;
  q:=2;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if x>f[i,j] then
        begin
          x:=f[i,j];p:=i;q:=j;
        end;
  if n=1 then writeln(1,' ',1) else writeln(p,' ',q);
end.