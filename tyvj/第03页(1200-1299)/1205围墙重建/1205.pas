const
  max=400;
var
  a,b,c:packed array[0..max] of longint;
  i,j,n,k,jw:longint;
procedure fei;
var
  i,x:longint;
begin
  jw:=0;
  for i:=max downto k do
    begin
      x:=a[i]+b[i]+jw;
      jw:=x div 1000000;
      c[i]:=x mod 1000000;
    end;
  if jw<>0 then
    begin
      k:=k-1;
      c[k]:=jw;
    end;
  a:=b;
  b:=c;
  fillchar(c,sizeof(c),0);
end;
procedure init;
begin
  read(n);n:=n+2;
end;
procedure work;
begin
  if n=1 then write(0)
    else if n=2 then write(1)
      else
        begin
          fillchar(a,sizeof(a),0);
          fillchar(b,sizeof(b),0);
          fillchar(c,sizeof(c),0);
          a[max]:=0;
          k:=max;
          b[max]:=1;
          for i:=3 to n do fei;
          write(b[k]);
          for j:=k+1 to max do
            begin
              if b[j] div 100000=0 then write(0);
              if b[j] div 10000=0 then write(0);
              if b[j] div 1000=0 then write(0);
              if b[j] div 100=0 then write(0);
              if b[j] div 10=0 then write(0);
              write(b[j]);
            end;
          writeln;
        end;
end;
begin
  init;
  work;
end.