var
  a,b:array[0..100,0..100] of longint;
  n,i,j,k,p,ans:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  read(n);
  for i:=1 to n do
    for j:=1 to n do
      read(a[i,j]);
  ans:=a[1,1];
  fillchar(b,sizeof(b),0);
  for i:=1 to n do
    for j:=1 to n do
      b[i,j]:=b[i-1,j]+a[i,j];
  for i:=1 to n do
    for j:=i to n do
      begin
        p:=b[j,1]-b[i-1,1];
        ans:=max(ans,p);
        for k:=2 to n do
          begin
            p:=max(p+b[j,k]-b[i-1,k],b[j,k]-b[i-1,k]);
            ans:=max(ans,p);
          end;
      end;
  writeln(ans);
end.