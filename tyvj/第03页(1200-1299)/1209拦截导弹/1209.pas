var
  s:ansistring;
  n,i,j:longint;
  a,f:array[0..100] of longint;
begin
  readln(s);
  j:=0;
  n:=0;
  for i:=1 to length(s) do
    if s[i] in ['0'..'9']
      then j:=j*10+ord(s[i])-48
      else
        begin
          inc(n);
          a[n]:=j;
          j:=0;
        end;
  inc(n);
  a[n]:=j;
  for i:=1 to n do f[i]:=1;
  for i:=2 to n do
    for j:=1 to i-1 do
      if (a[i]<=a[j])and(f[i]<f[j]+1) then f[i]:=f[j]+1;
  j:=0;
  for i:=1 to n do
    if j<f[i] then j:=f[i];
  write(j,',');
  for i:=1 to n do f[i]:=1;
  for i:=2 to n do
    for j:=1 to i-1 do
      if (a[i]>a[j])and(f[i]<f[j]+1) then f[i]:=f[j]+1;
  j:=0;
  for i:=1 to n do
    if j<f[i] then j:=f[i];
  write(j-1);
  writeln;
end.