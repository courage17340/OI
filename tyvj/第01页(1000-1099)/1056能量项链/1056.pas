var
  a:array[0..300] of longint;
  f:array[0..300,0..300] of longint;
  n,ans,i,j,k,L:longint;
function max(a,b:longint):longint;
begin max:=a;if a<b then max:=b;end;
begin
  readln(n);
  for i:=1 to n do
    begin
      read(a[i]);
      a[n+i]:=a[i];
    end;
  fillchar(f,sizeof(f),0);
  for L:=2 to n do
    for i:=1 to n*2-L+1 do
      begin
        j:=i+L;
        for k:=i+1 to j-1 do
          f[i,j]:=max(f[i,j],f[i,k]+f[k,j]+a[i]*a[j]*a[k]);
      end;
  ans:=0;
  for i:=1 to n do
    ans:=max(ans,f[i,i+n]);
  writeln(ans);
end.