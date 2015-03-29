var
  a:array[1..100] of longint;
  f:array[1..100,1..100] of longint;
  n,i,j:longint;
function dp(i,j:longint):longint;
var
  k,temp:longint;
begin
  if i+1=j then exit(0);
  if f[i,j]<>-1 then exit(f[i,j]);
  for k:=i+1 to j-1 do
    begin
      temp:=dp(i,k)+dp(k,j)+a[i]*a[k]*a[j];
      if (temp<f[i,j])or(f[i,j]=-1) then f[i,j]:=temp;
    end;
  exit(f[i,j]);
end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  fillchar(f,sizeof(f),255);
  writeln(dp(1,n));
end.