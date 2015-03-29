var
  a,b,c:array[0..100] of longint;
  f:array[0..100,1..2] of longint;{1©Й2ив}
  i,n,j:longint;
begin
  fillchar(f,sizeof(f),0);
  read(n);
  for i:=1 to n do read(a[i],b[i],c[i]);
  f[1,1]:=b[1];
  f[1,2]:=a[1]+c[1];
  for i:=2 to n do
    begin
      f[i,1]:=f[i-1,1];if f[i,1]>f[i-1,2]+c[i] then f[i,1]:=f[i-1,2]+c[i];inc(f[i,1],b[i]);
      f[i,2]:=f[i-1,2];if f[i,2]>f[i-1,1]+c[i] then f[i,2]:=f[i-1,1]+c[i];inc(f[i,2],a[i]);
    end;
  if f[n,1]>f[n,2] then writeln(f[n,2]) else writeln(f[n,1]);
end.
