var
  a:array[1..100] of longint;
  f:array[0..100,0..50] of longint;
  i,j,k,n,t:longint;
function min(a,b:longint):longint;
begin
  min:=a;if a>b then min:=b;
end;
begin
  for i:=0 to 100 do for j:=0 to 50 do
    if j=0 then f[i,j]:=0 else f[i,j]:=maxlongint;
  read(n,k);
  k:=k+3;
  if k+k>n then begin writeln(-1);halt;end;
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do if a[i]>a[j] then begin t:=a[i];a[i]:=a[j];a[j]:=t;end;
  for i:=1 to n do
    for j:=1 to min(k+3,i shr 1) do
      f[i,j]:=min(f[i-1,j],f[i-2,j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
  writeln(f[n,k]);
end.
