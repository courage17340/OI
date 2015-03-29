var
  a:array[0..100] of longint;
  f:array[0..100,0..9999] of boolean;
  i,j,n,p,m,k:longint;
  s:int64;
begin
  read(n,p,m);
  fillchar(f,sizeof(f),false);
  for i:=1 to n do begin read(s);a[i]:=s mod m;end;
  f[1,0]:=true;f[0,0]:=true;
  for i:=2 to n do
    for j:=1 to p do
      if i>j then
        for k:=0 to m-1 do
          if k>=j*a[i] then f[i,k]:=f[i,k] or f[i-j,(k-j*a[i]) mod m]
                       else f[i,k]:=f[i,k] or f[i-j,(k+m-j*a[i]) mod m];
  k:=m-1;
  while not f[n,k] do dec(k);
  writeln(k);
end.
