var
  a,sum:array[0..100] of longint;
  f:array[0..100,0..100] of longint;
  n,i,j,ans,k,p:longint;
function max(a,b:longint):longint;
begin
  max:=a;if a<b then max:=b;
end;
begin
  read(n,k);
  for i:=1 to n do read(a[i]);
  if k=n-1 then begin ans:=1;for i:=1 to n do ans:=ans*a[i];writeln(ans);halt;end;
  fillchar(sum,sizeof(sum),0);
  for i:=1 to n do sum[i]:=sum[i-1]+a[i];
  if k=0 then begin writeln(sum[n]);halt;end;
  for i:=1 to n do
    for j:=0 to k do if j<i then
      begin
        if j=0 then begin f[i,j]:=sum[i];continue;end;
        f[i,j]:=0;
        for p:=j to i-1 do
          f[i,j]:=max(f[i,j],f[p,j-1]*(sum[i]-sum[p]));
      end;
  writeln(f[n,k]);
end.
