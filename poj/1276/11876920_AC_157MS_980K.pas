var
  f:array[0..100000] of boolean;
  a,b,s:array[1..10] of longint;
  n,m,i,j,k,x:longint;
function min(a,b:longint):longint;
begin
  min:=a;
  if a>b then min:=b;
end;
begin
  while not eof do
    begin
      read(m,n);
      for i:=1 to n do read(b[i],a[i]);
      readln;
      s[1]:=a[1]*b[1];
      for i:=2 to n do s[i]:=a[i]*b[i]+s[i-1];
      fillchar(f,sizeof(f),0);
      f[0]:=true;
      for i:=1 to n do
        begin
          x:=1;
          dec(b[i],x);
          while b[i]>=0 do
            begin
              for j:=min(m,s[i]) downto x*a[i] do
              f[j]:=f[j] or f[j-x*a[i]];
              x:=x*2;
              if (b[i]<x)and(b[i]>0) then x:=b[i];
              dec(b[i],x);
            end;
        end;
      j:=m;
      while not f[j] do dec(j);
      writeln(j);
    end;
end.