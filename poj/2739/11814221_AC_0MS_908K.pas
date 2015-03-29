var
  b,f:array[1..10000] of longint;
  a:array[1..10000] of boolean;
  n,i,j,k:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(a,sizeof(a),true);
  a[1]:=false;
  i:=2;
  while i<=100 do
    begin
      while not a[i] do inc(i);
      for j:=2 to 10000 div i do a[i*j]:=false;
      inc(i);
    end;
  j:=0;
  for i:=1 to 10000 do
    if a[i] then
      begin
        inc(j);
        b[j]:=i;
      end;
  k:=j;
  for i:=2 to k do b[i]:=b[i-1]+b[i];
  for i:=1 to k do
    for j:=0 to i-1 do
      if b[i]-b[j]<=10000 then inc(f[b[i]-b[j]]);
  while true do
    begin
      readln(n);
      if n=0 then break;
      writeln(f[n]);
    end;
end.