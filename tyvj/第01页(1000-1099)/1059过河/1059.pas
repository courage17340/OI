var
  a:array[1..100] of longint;
  n,i,j,k,s,t,m,ans,L:longint;
  b:array[0..253000] of boolean;
  f:array[0..253000] of longint;
function min(a,b:longint):longint;
begin
  min:=a;
  if min>b then min:=b;
end;
begin
  readln(L);
  readln(s,t,m);
  for i:=1 to m do read(a[i]);
  for i:=1 to m-1 do
    for j:=i+1 to m do
      if a[i]>a[j] then
        begin
          k:=a[i];a[i]:=a[j];a[j]:=k;
        end;
  if s=t then
    begin
      ans:=0;
      for i:=1 to m do if a[i] mod s=0 then inc(ans);
      writeln(ans);
      halt;
    end;
  if a[1]>2521 then
    begin
      k:=a[1]-2521;
      for i:=1 to m do a[i]:=a[i]-k;
      L:=L-k;
    end;
  for i:=1 to m-1 do
    if a[i+1]-a[i]>2521 then
      begin
        k:=a[i+1]-a[i]-2521;
        for j:=i+1 to m do a[j]:=a[j]-k;
        L:=L-k;
      end;
  if L-a[m]>2521 then L:=a[m]+2521;
  fillchar(b,sizeof(b),true);
  fillchar(f,sizeof(f),1);
  f[0]:=0;
  for i:=1 to m do b[a[i]]:=false;
  for i:=1 to L+t-1 do
    for j:=i-t to min(i-s,L-1) do
      if j>=0 then
        f[i]:=min(f[i],f[j]+1-ord(b[i]));
  ans:=f[L];
  for i:=L+1 to L+t-1 do ans:=min(f[i],ans);
  writeln(ans);
end.