var
  a:array[1..9,1..9] of longint;
  f:array[0..20,0..11,0..11] of longint;
  n,i,j,k,ans,x,y:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
function min(a,b:longint):longint;
begin
  min:=a;
  if a>b then min:=b;
end;
begin
  fillchar(a,sizeof(a),0);
  readln(n);
  while true do
    begin
      readln(x,y,j);
      if x+y+j=0 then break;
      a[x,y]:=j;
    end;
  ans:=a[1,1]+a[n,n];
  a[1,1]:=0;a[n,n]:=0;
  fillchar(f,sizeof(f),0);
  for i:=1 to n*2-3 do
    for j:=1 to min(i+1,n) do
      for k:=j+1 to min(i+1,n) do
        begin
          f[i,j,k]:=max(f[i-1,j,k],f[i-1,j-1,k-1]);
          f[i,j,k]:=max(f[i,j,k],f[i-1,j,k-1]);
          f[i,j,k]:=max(f[i,j,k],f[i-1,j-1,k]);
          f[i,j,k]:=f[i,j,k]+a[i+2-j,j]+a[i+2-k,k];
        end;
  ans:=ans+f[n*2-3,n-1,n];
  writeln(ans);
end.
