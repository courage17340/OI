var
  a,f:array[0..101,0..101] of longint;
  n,i,j:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
begin
  readln(n);
  for i:=1 to n do
    for j:=1 to i do
      read(a[i,j]);
  fillchar(f,sizeof(f),0);
  for i:=n downto 1 do
    for j:=1 to i do
      f[i,j]:=a[i,j]+max(f[i+1,j],f[i+1,j+1]);
  writeln(f[1,1]);
end.