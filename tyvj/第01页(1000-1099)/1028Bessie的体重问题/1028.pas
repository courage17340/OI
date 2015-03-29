var
  f:array[0..45000] of 0..1;
  a:array[0..500] of longint;
  i,j,n,h:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
begin
  fillchar(f,sizeof(f),0);
  read(h,n);
  for i:=1 to n do read(a[i]);
  readln;
  f[0]:=1;
  for i:=1 to n do
    for j:=h downto 0 do
      if (f[j]=1)and(j+a[i]<=h) then f[j+a[i]]:=1;
  j:=h;
  while f[j]=0 do dec(j);
  writeln(j);
end.