var
  a,sum:array[0..1000] of longint;
  f:array[0..1000,0..1000] of longint;
  n,i,j,k:longint;
function min(a,b:longint):longint;
begin
  min:=a;if b<a then min:=b;
end;
begin
  read(n);
  fillchar(a,sizeof(a),0);fillchar(sum,sizeof(sum),0);fillchar(f,sizeof(f),0);
  for i:=1 to n do begin read(a[i]);sum[i]:=sum[i-1]+a[i];end;
  for i:=1 to n do f[i,i]:=a[i];
  for i:=1 to n-1 do
    for j:=1 to n-i do
      begin
        f[j,i+j]:=maxlongint;
        for k:=j to i+j-1 do
          f[j,i+j]:=min(f[j,i+j],f[j,k]+f[k+1,i+j]);
        f[j,i+j]:=f[j,i+j]+sum[i+j]-sum[j-1];
      end;
  writeln(f[1,n]-sum[n]);
end.
