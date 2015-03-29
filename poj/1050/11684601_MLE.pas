var
  a:array[0..110,0..110] of longint;
  f:array[1..100,1..100,-1..100,-1..100] of longint;
  n,i,j,p,q,ans:longint;
begin
  read(n);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  ans:=a[1,1];
  for i:=1 to n do
    for j:=1 to n do
      for p:=0 to n-i do
        for q:=0 to n-j do
          begin
            f[i,j,p,q]:=f[i,j,p,q-1]+f[i,j,p-1,q]-f[i,j,p-1,q-1]+a[i+p,j+q];
            if ans<f[i,j,p,q] then ans:=f[i,j,p,q];
          end;
  writeln(ans);
end.