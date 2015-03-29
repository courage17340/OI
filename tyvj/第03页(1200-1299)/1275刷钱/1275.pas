var
  w,v:array[1..100] of longint;
  f:array[0..100,0..20] of longint;
  k,n,i,j,m,t:longint;
begin
  read(n,m,k);
  if m=0 then begin writeln(0);halt;end;
  for i:=1 to n do
    begin
      read(t);
      j:=t div m;
      if t mod m>0 then inc(j);
      w[i]:=j;
    end;
  for i:=1 to n do read(v[i]);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=0 to k do
      begin
        f[i,j]:=f[i-1,j];
        if j>=w[i] then if f[i,j]<f[i-1,j-w[i]]+v[i] then f[i,j]:=f[i-1,j-w[i]]+v[i];
      end;
  writeln(f[n,k]);
end.
