var
  a,f:array[1..351,1..351] of longint;
  n,i,j:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to i do read(a[i,j]);
      readln;
    end;
  fillchar(f,sizeof(f),0);
  for i:=n downto 1 do
    for j:=1 to i do
      f[i,j]:=max(f[i+1,j],f[i+1,j+1])+a[i,j];
  writeln(f[1,1]);
end.