var
  f:array[0..1000,0..4000] of longint;
  a:array[1..1000,1..2] of longint;
  i,j,n,ans:longint;
function min(a,b:longint):longint;
begin min:=a;if a>b then min:=b;end;
function max(a,b:longint):longint;
begin max:=a;if a<b then max:=b;end;
begin
  read(n);
  for i:=1 to n do read(a[i,1]);
  for i:=1 to n do read(a[i,2]);
  fillchar(f,sizeof(f),127);
  for i:=0 to 4000 do begin f[1,i]:=a[1,2];if i>=a[1,1] then f[1,i]:=0;end;
  for i:=2 to n do
    for j:=0 to 4000 do
      begin
        if j>=a[i,1] then f[i,j]:=f[i-1,j-a[i,1]];{A}
        f[i,j]:=min(f[i,j],f[i-1,j]+a[i,2]);{B}
      end;
  ans:=maxlongint;
  for j:=0 to 4000 do if ans>max(j,f[n,j]) then ans:=max(j,f[n,j]);
  writeln(ans);
end.