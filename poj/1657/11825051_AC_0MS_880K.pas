var
  n,i,j,x,y,p,q,t,k:longint;
  ch:char;
begin
  readln(n);
  for k:=1 to n do
    begin
      read(ch);
      x:=ord(ch)-96;
      read(y);
      read(ch);
      while ch=' ' do read(ch);
      p:=ord(ch)-96;
      readln(q);
      if (p=x)and(q=y) then
        begin
          writeln('0 0 0 0');
          continue;
        end;
      i:=abs(p-x);
      j:=abs(q-y);
      if i>j then write(i,' ') else write(j,' ');
      if (i*j=0)or(abs(i)=abs(j)) then write('1 ') else write('2 ');
      if i*j=0 then write('1 ') else write('2 ');
      if abs(i)=abs(j) then writeln(1)
        else
          if odd(i-j) then writeln('Inf')
            else writeln(2);
    end;
end.